#!/usr/bin/env python3

import os
import struct
import sys
from ctypes import c_uint32
from io import BytesIO
from pathlib import Path
from typing import Optional

SCRIPT_DIR = Path(os.path.dirname(os.path.realpath(__file__)))
ROOT_DIR = SCRIPT_DIR.parent.parent
FILENAMES_PATH = SCRIPT_DIR / "kingdom_filenames.txt"
ISO_PATH = ROOT_DIR / "kh_jp.iso"

BLOCK_LENGTH = 0x800


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


def find_kingdom_pos():
    with open(ISO_PATH, "rb") as f:
        iso_bytes = f.read()

    pos = get_file_offset(BytesIO(iso_bytes), "KINGDOM.IDX;1")
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


filenames = get_filenames()
start = find_kingdom_pos()
end = 0x4CA5A0  # todo don't hard-code
num = (end - start) // 0x10
with open(ISO_PATH, "rb") as f:
    f.seek(start)
    for i in range(num):
        (hash, is_compressed, iso_block, length) = struct.unpack("<IIII", f.read(0x10))
        if hash not in filenames:
            print(
                f"!NOT FOUND! {hash:X} {is_compressed} {iso_block:X} {length:X} UNKNOWN"
            )
        else:
            print(
                f"{filenames[hash]} {hash:X} {is_compressed} {iso_block:X} {length:X}"
            )
