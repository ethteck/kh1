#! /usr/bin/env python3

import argparse
import os
import shutil
import sys
from pathlib import Path
from typing import Dict, List, Set, Union

import ninja_syntax
import splat
import splat.scripts.split as split
from splat.segtypes.linker_entry import LinkerEntry

ROOT = Path(__file__).parent.resolve()
TOOLS_DIR = ROOT / "tools"

VERSION = "jp"
BASENAME = "SLPS_251.05"
YAML_FILE = f"config/kh.{VERSION}.yaml"

LD_PATH = f"{BASENAME}.ld"
ELF_PATH = f"build/{VERSION}/{BASENAME}"
MAP_PATH = f"build/{VERSION}/{BASENAME}.map"
PRE_ELF_PATH = f"build/{VERSION}/{BASENAME}.elf"

COMMON_INCLUDES = "-Iinclude -isystem include/sdk/ee -isystem include/gcc"

GAME_CC_DIR = f"{TOOLS_DIR}/cc/ee-gcc2.96"
LIB_CC_DIR = f"{TOOLS_DIR}/cc/ee-gcc2.9-991111/bin"
COMMON_COMPILE_FLAGS = "-O2 -G0 $g"

GAME_GCC_CMD = f"{GAME_CC_DIR}/bin/ee-gcc -c -B {GAME_CC_DIR}/bin/ee- {COMMON_INCLUDES} {COMMON_COMPILE_FLAGS} $in"

GAME_COMPILE_CMD = f"{GAME_GCC_CMD} -S -o - | {TOOLS_DIR}/masps2.py | {GAME_CC_DIR}/ee/bin/as {COMMON_COMPILE_FLAGS} -EL -mabi=eabi"

LIB_COMPILE_CMD = f"{LIB_CC_DIR}/ee-gcc -c -isystem include/gcc-991111 {COMMON_INCLUDES} {COMMON_COMPILE_FLAGS}"

NO_G_FILES = [
    "xblade.c",
    "gumi.c",
]


def clean():
    if os.path.exists(".splache"):
        os.remove(".splache")
    shutil.rmtree("asm", ignore_errors=True)
    shutil.rmtree("assets", ignore_errors=True)
    shutil.rmtree("build", ignore_errors=True)


def write_permuter_settings():
    with open("permuter_settings.toml", "w") as f:
        f.write(
            f"""compiler_command = "{GAME_COMPILE_CMD} -D__GNUC__"
assembler_command = "mips-linux-gnu-as -march=r5900 -mabi=eabi -Iinclude"
compiler_type = "gcc"

[preserve_macros]

[decompme.compilers]
"tools/build/cc/gcc/gcc" = "ee-gcc2.96"
"""
        )


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

    # Rules
    cross = "mips-linux-gnu-"

    config = f"config/{VERSION}"

    ld_args = f"-EL -T {config}/undefined_syms.txt -T {config}/undefined_syms_auto.txt -T {config}/undefined_funcs_auto.txt -Map $mapfile -T $in -o $out"

    ninja.rule(
        "as",
        description="as $in",
        command=f"cpp {COMMON_INCLUDES} $in -o  - | {cross}as -no-pad-sections -EL -march=5900 -mabi=eabi -Iinclude -o $out",
    )

    ninja.rule(
        "cc",
        description="cc $in",
        command=f"{GAME_COMPILE_CMD} -o $out && {cross}strip $out -N dummy-symbol-name",
    )

    ninja.rule(
        "libcc",
        description="cc $in",
        command=f"{LIB_COMPILE_CMD} $in -o $out && {cross}strip $out -N dummy-symbol-name",
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

    ninja.rule(
        "elf",
        description="elf $out",
        command=f"{cross}objcopy $in $out -O binary",
    )

    for entry in linker_entries:
        seg = entry.segment

        if seg.type[0] == ".":
            continue

        if entry.object_path is None:
            continue

        if isinstance(seg, splat.segtypes.common.asm.CommonSegAsm) or isinstance(
            seg, splat.segtypes.common.data.CommonSegData
        ):
            build(entry.object_path, entry.src_paths, "as")
        elif isinstance(seg, splat.segtypes.common.c.CommonSegC):
            if any(
                str(src_path).startswith("src/lib/") for src_path in entry.src_paths
            ):
                build(entry.object_path, entry.src_paths, "libcc")
            else:
                if entry.src_paths[0].name in NO_G_FILES:
                    g = ""
                else:
                    g = "-g"
                build(entry.object_path, entry.src_paths, "cc", variables={"g": g})
        elif isinstance(seg, splat.segtypes.common.databin.CommonSegDatabin):
            build(entry.object_path, entry.src_paths, "as")
        else:
            print(f"ERROR: Unsupported build segment type {seg.type}")
            sys.exit(1)

    ninja.build(
        PRE_ELF_PATH,
        "ld",
        LD_PATH,
        implicit=[str(obj) for obj in built_objects],
        variables={"mapfile": MAP_PATH},
    )

    ninja.build(
        ELF_PATH,
        "elf",
        PRE_ELF_PATH,
    )

    ninja.build(
        ELF_PATH + ".ok",
        "sha1sum",
        f"config/{VERSION}/checksum.sha1",
        implicit=[ELF_PATH],
    )


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Configure the project")
    parser.add_argument(
        "-v",
        "--version",
        help="Game version to configure for",
        choices=["jp", "fm"],
    )
    parser.add_argument(
        "-c",
        "--clean",
        help="Clean extraction and build artifacts",
        action="store_true",
    )
    args = parser.parse_args()

    if args.version:
        VERSION = args.version
    else:
        VERSION = "jp"

    BASENAME = {
        "jp": "SLPS_251.05",
        "fm": "SLPS_251.98",
    }[VERSION]

    LD_PATH = f"{BASENAME}.ld"
    ELF_PATH = f"build/{VERSION}/{BASENAME}"
    MAP_PATH = f"build/{VERSION}/{BASENAME}.map"
    PRE_ELF_PATH = f"build/{VERSION}/{BASENAME}.elf"

    if args.clean:
        clean()

    EXTENDEDNAME = {
        "jp": "Original Japanese",
        "fm": "Final Mix",
    }[VERSION]

    print(
        f"Kingdom Hearts De:Compiled ~ Generating build configuration for {EXTENDEDNAME} edition ({BASENAME})"
    )

    YAML_FILE = f"config/kh.{VERSION}.yaml"

    split.main([YAML_FILE], modes="all", verbose=False)

    linker_entries = split.linker_writer.entries

    build_stuff(linker_entries)

    write_permuter_settings()
