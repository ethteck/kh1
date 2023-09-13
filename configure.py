#! /usr/bin/env python3

import argparse
import os
from pathlib import Path
import shutil
import sys

ROOT = Path(__file__).parent.resolve()
TOOLS_DIR = ROOT / "tools"
SPLAT_DIR = TOOLS_DIR / "splat"

sys.path.append(str(SPLAT_DIR))

import split

YAML_FILE = "kh.jp.yaml"

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Configure the project")
    parser.add_argument(
        "-c",
        "--clean",
        help="Clean extraction and build artifacts",
        action="store_true",
    )
    args = parser.parse_args()

    if args.clean:
        os.remove(".splache")
        shutil.rmtree("asm", ignore_errors=True)
        shutil.rmtree("assets", ignore_errors=True)
        shutil.rmtree("build", ignore_errors=True)

    split.main([YAML_FILE], modes="all", verbose=False)
