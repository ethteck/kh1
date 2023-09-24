#!/usr/bin/env python3

import os
import struct
import sys
from ctypes import c_uint32
from dataclasses import dataclass
from io import BytesIO
from pathlib import Path
from typing import List, Optional

SCRIPT_DIR = Path(os.path.dirname(os.path.realpath(__file__)))
ROOT_DIR = SCRIPT_DIR.parent.parent
FILENAMES_PATH = SCRIPT_DIR / "kingdom_filenames.txt"
ISO_PATH = ROOT_DIR / "kh_jp.iso"

BLOCK_LENGTH = 0x800


@dataclass
class KingdomFile:
    hash: int
    is_compressed: bool
    iso_block: int
    length: bool
    filename: Optional[str] = None


def decompress(src_data):
    src_index = len(src_data) - 1

    if src_index == 0:
        return bytearray()

    key = src_data[src_index]
    src_index -= 1
    dec_size = (
        src_data[src_index]
        | (src_data[src_index - 1] << 8)
        | (src_data[src_index - 2] << 16)
    )
    src_index -= 3

    dst_index = dec_size - 1
    dst_data = bytearray(dec_size)
    while dst_index >= 0 and src_index >= 0:
        data = src_data[src_index]
        src_index -= 1
        if data == key and src_index >= 0:
            copy_index = src_data[src_index]
            src_index -= 1
            if copy_index > 0 and src_index >= 0:
                copy_length = src_data[src_index]
                src_index -= 1
                for i in range(copy_length + 3):
                    if dst_index + copy_index + 1 < len(dst_data):
                        dst_data[dst_index] = dst_data[dst_index + copy_index + 1]
                    else:
                        dst_data[dst_index] = 0
                    dst_index -= 1
            else:
                dst_data[dst_index] = data
                dst_index -= 1
        else:
            dst_data[dst_index] = data
            dst_index -= 1

    return dst_data


def get_file_offset(data: BytesIO, filename: str) -> Optional[int]:
    base_pos = 0x105 * BLOCK_LENGTH

    filename_bytes = filename.encode("UTF-8")

    data.seek(base_pos)

    for i in range(0x500):
        something = data.read(1)
        if int.from_bytes(something) != 1:
            continue

        string_length = int.from_bytes(data.read(1))
        if string_length != len(filename_bytes):
            continue

        cur_pos = data.tell()
        read_filename = data.read(string_length)
        if read_filename == filename_bytes:
            data.seek(cur_pos - 0x1B)

            pos = int.from_bytes(data.read(4))
            return pos

        data.seek(cur_pos + 1)
    return 0


def find_file_pos(filename: str):
    with open(ISO_PATH, "rb") as f:
        iso_bytes = f.read()

    pos = get_file_offset(BytesIO(iso_bytes), filename)
    if not pos:
        print("File not found")
        sys.exit(1)
    return pos * 0x800


def get_filenames() -> dict[int, str]:
    ret: dict[int, str] = {}

    with open(FILENAMES_PATH) as f:
        lines = f.readlines()
    for line in lines:
        filename = line.strip()
        ret[hash_filename(filename)] = filename
    return ret


def hash_filename(filename: str) -> int:
    hash = c_uint32(0)
    for c in filename:
        hash = c_uint32(
            c_uint32(hash.value * 2).value
            ^ c_uint32(c_uint32(c_uint32(ord(c)).value << 0x10).value % 69665).value
        )
    return hash.value


kingdom_files: List[KingdomFile] = []
filenames = get_filenames()
start = find_file_pos("KINGDOM.IDX;1")
cnf_start = find_file_pos("SYSTEM.CNF;1")
end = 0x4CA5A0  # todo don't hard-code
num = (end - start) // 0x10
with open(ISO_PATH, "rb") as f:
    f.seek(start)
    not_found = 0
    for i in range(num):
        (hash, is_compressed, iso_block, length) = struct.unpack("<IIII", f.read(0x10))
        file = KingdomFile(hash, is_compressed, iso_block, length)
        if hash in filenames:
            file.filename = filenames[hash]
        else:
            print(f"0x{hash:X}")
            not_found += 1
        kingdom_files.append(file)
    print(f"{not_found} filenames unknown")

    for entry in kingdom_files:
        f.seek(cnf_start + entry.iso_block * BLOCK_LENGTH)
        contents = f.read(entry.length)

        if entry.is_compressed:
            contents = decompress(contents)

        if entry.filename is None:
            entry.filename = f"unknown/{entry.hash:08x}.bin"

        path = ROOT_DIR / "kingdom" / entry.filename
        path.parent.mkdir(parents=True, exist_ok=True)
        with open(path, "wb") as out:
            out.write(contents)
