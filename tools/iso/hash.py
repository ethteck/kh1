#!/usr/bin/env python3

import argparse
import os
from pathlib import Path
from typing import List

from common import hash_filename

SCRIPT_DIR = Path(os.path.dirname(os.path.realpath(__file__)))

if __name__ == "__main__":
    parser = argparse.ArgumentParser()

    parser.add_argument("filename", help="Filename to hash")
    args = parser.parse_args()

    missing_hashes: List[int] = []
    with open(SCRIPT_DIR / "missing_hashes.txt") as f:
        for line in f.readlines():
            line = line.strip()
            missing_hashes.append(int(line, 16))

    hash = hash_filename(args.filename)
    if hash in missing_hashes:
        print(f"Missing hash found! 0x{hash:X}")
    else:
        print(f"0x{hash:X}")
