#! /usr/bin/env python3

import argparse
import os
import shutil
import sys
from pathlib import Path
from typing import Dict, List, Union

import ninja_syntax

ROOT = Path(__file__).parent.resolve()
TOOLS_DIR = ROOT / "tools"
SPLAT_DIR = TOOLS_DIR / "splat"

sys.path.append(str(SPLAT_DIR))

import segtypes.common.asm
import segtypes.common.data
from segtypes.linker_entry import LinkerEntry
import split

YAML_FILE = "kh.jp.yaml"


def build_stuff(linker_entries: List[LinkerEntry]):
    def build(
        object_paths: Union[Path, List[Path]],
        src_paths: List[Path],
        task: str,
        variables: Dict[str, str] = {},
        implicit_outputs: List[str] = [],
    ):
        if not isinstance(object_paths, list):
            object_paths = [object_paths]

        object_strs = [str(obj) for obj in object_paths]

        for object_path in object_paths:
            ninja.build(
                outputs=object_strs,
                rule=task,
                inputs=[str(s) for s in src_paths],
                # implicit=implicit,
                # order_only=order_only,
                variables=variables,
                implicit_outputs=implicit_outputs,
            )

    ninja = ninja_syntax.Writer(open(str(ROOT / "build.ninja"), "w"), width=9999)

    COMMON_INCLUDES = "-Iinclude"

    # Rules

    cross = "mips-linux-gnu-"

    ninja.rule(
        "as",
        description="as $in",
        command=f"cpp {COMMON_INCLUDES} $in -o  - | {cross}as -EB -march=5900 -Iinclude -o $out",
    )

    for entry in linker_entries:
        seg = entry.segment

        if (
            isinstance(seg, segtypes.common.asm.CommonSegAsm)
            or isinstance(seg, segtypes.common.data.CommonSegData)
            and not seg.type[0] == "."
        ):
            build(entry.object_path, entry.src_paths, "as")


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

    linker_entries = split.linker_writer.entries

    build_stuff(linker_entries)
