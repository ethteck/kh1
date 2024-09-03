#!/usr/bin/env python3

import argparse
import os
import struct
import sys
from io import BytesIO
from pathlib import Path
from typing import List, Optional, Tuple

import tqdm

from common import KingdomFile, hash_filename

import rich.pretty

SCRIPT_DIR = Path(os.path.dirname(os.path.realpath(__file__)))
ROOT_DIR = SCRIPT_DIR.parent.parent
FILENAMES_PATH = SCRIPT_DIR / "kingdom_filenames.txt"

BLOCK_LENGTH = 0x800


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
                        dst_data[dst_index] = dst_data[dst_index + copy_index]
                    else:
                        dst_data[dst_index] = 0
                    dst_index -= 1
                    if dst_index < 0:
                        break
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
        if int.from_bytes(something, 'big') != 1:
            continue

        string_length = int.from_bytes(data.read(1), 'big')
        if string_length != len(filename_bytes):
            continue

        cur_pos = data.tell()
        read_filename = data.read(string_length)
        if read_filename == filename_bytes:
            data.seek(cur_pos - 0x1B)

            pos = int.from_bytes(data.read(4), 'big')
            return pos

        data.seek(cur_pos + 1)
    return 0


def get_file_pos(iso_bytes: BytesIO, filename: str):
    pos = get_file_offset(iso_bytes, filename)
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


def get_kingdom_files(
    iso_bytes: BytesIO, filenames: dict[int, str]
) -> Tuple[int, List[KingdomFile]]:
    kingdom_files: List[KingdomFile] = []

    start = get_file_pos(iso_bytes, "KINGDOM.IDX;1")

    iso_bytes.seek(start)
    num_unknown = 0
    while True:
        (hash, is_compressed, iso_block, length) = struct.unpack(
            "<IIII", iso_bytes.read(0x10)
        )
        if hash == 0:
            break
        file = KingdomFile(hash, is_compressed, iso_block, length)
        if hash in filenames:
            file.filename = filenames[hash]
        else:
            print(f"0x{hash:X}")
            num_unknown += 1
        kingdom_files.append(file)
    return num_unknown, kingdom_files


if __name__ == "__main__":
    parser = argparse.ArgumentParser()

    parser.add_argument("iso_path", help="Path to ISO file", type=Path)
    args = parser.parse_args()

    kingdom_files: List[KingdomFile] = []
    filenames = get_filenames()
    out_dir: str = "kingdom"

    print("Reading ISO...\r", end="")
    with open(args.iso_path, "rb") as f:
        iso_bytes = BytesIO(f.read())

    num_unknown, kingdom_files = get_kingdom_files(iso_bytes, filenames)
    out_msg = f"Reading ISO... Found {len(kingdom_files)} files"
    if num_unknown > 0:
        out_msg += f" ({num_unknown} filenames unknown)"
    print(out_msg)

    kingdom_files.sort(key=lambda x: x.iso_block)
    for file in kingdom_files:
        rich.pretty.pprint(file)

    cnf_start = get_file_pos(iso_bytes, "SYSTEM.CNF;1")

    with tqdm.tqdm(total=len(kingdom_files), unit=" file") as pbar:
        for entry in kingdom_files:
            if entry.filename is None:
                entry.filename = f"unknown/{entry.hash:08X}.bin"
            path: Path = out_dir / Path(entry.filename)
            pbar.set_description("Extracting " + path.name.ljust(14))
            iso_bytes.seek(cnf_start + entry.iso_block * BLOCK_LENGTH)
            contents = iso_bytes.read(entry.length)

            if entry.is_compressed:
                contents = decompress(contents)

            path.parent.mkdir(parents=True, exist_ok=True)
            with open(path, "wb") as out:
                out.write(contents)
            pbar.update(1)
