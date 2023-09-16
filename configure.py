#! /usr/bin/env python3

import argparse
import os
import shutil
import sys
from pathlib import Path
from typing import Dict, List, Set, Union

import ninja_syntax

ROOT = Path(__file__).parent.resolve()
TOOLS_DIR = ROOT / "tools"
SPLAT_DIR = TOOLS_DIR / "splat"

sys.path.append(str(SPLAT_DIR))

import segtypes.common.asm
import segtypes.common.bin
import segtypes.common.databin
import segtypes.common.bss
import segtypes.common.data
from segtypes.linker_entry import LinkerEntry
import split

YAML_FILE = "kh.jp.yaml"
ELF_PATH = "build/SLPS_251.05"
LD_PATH = "SLPS_251.05.ld"
MAP_PATH = "build/SLPS_251.05.map"


def clean():
    os.remove(".splache")
    shutil.rmtree("asm", ignore_errors=True)
    shutil.rmtree("assets", ignore_errors=True)
    shutil.rmtree("build", ignore_errors=True)


def build_stuff(linker_entries: List[LinkerEntry]):
    built_objects: Set[Path] = set()

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
            if object_path.suffix == ".o":
                built_objects.add(object_path)
            ninja.build(
                outputs=object_strs,
                rule=task,
                inputs=[str(s) for s in src_paths],
                variables=variables,
                implicit_outputs=implicit_outputs,
            )

    ninja = ninja_syntax.Writer(open(str(ROOT / "build.ninja"), "w"), width=9999)

    COMMON_INCLUDES = "-Iinclude"

    # Rules
    cross = "mips-linux-gnu-"

    ld_args = f"-EL -T undefined_syms.txt -T undefined_syms_auto.txt -T undefined_funcs_auto.txt -Map $mapfile -T $in -o $out"

    ninja.rule(
        "as",
        description="as $in",
        command=f"cpp {COMMON_INCLUDES} $in -o  - | {cross}as -EL -march=5900 -mabi=eabi -Iinclude -o $out",
    )

    ninja.rule(
        "ld",
        description="link $out",
        command=f"{cross}ld {ld_args}",
    )

    ninja.rule(
        "sha1sum",
        description="sha1sum $in",
        command="sha1sum -c $in && touch $out",
    )

    for entry in linker_entries:
        seg = entry.segment

        if entry.object_path is None:
            continue

        if (
            isinstance(seg, segtypes.common.asm.CommonSegAsm)
            or isinstance(seg, segtypes.common.data.CommonSegData)
            and not seg.type[0] == "."
        ):
            build(entry.object_path, entry.src_paths, "as")
        elif isinstance(seg, segtypes.common.databin.CommonSegDatabin):
            build(entry.object_path, entry.src_paths, "as")
        elif isinstance(seg, segtypes.common.bss.CommonSegBss):
            pass
        else:
            print(f"ERROR: Unsupported segment type {seg.type}")
            sys.exit(1)

    ninja.build(
        ELF_PATH,
        "ld",
        LD_PATH,
        implicit=[str(obj) for obj in built_objects],
        variables={"mapfile": MAP_PATH},
    )

    ROM_OK_PATH = ELF_PATH + ".ok"

    ninja.build(
        ROM_OK_PATH,
        "sha1sum",
        "checksum.sha1",
        implicit=[ELF_PATH],
    )


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
        clean()

    split.main([YAML_FILE], modes="all", verbose=False)

    linker_entries = split.linker_writer.entries

    build_stuff(linker_entries)
