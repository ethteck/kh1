#! /usr/bin/env python3

import argparse
import os
import shutil
import subprocess
import sys
from pathlib import Path
from typing import Dict, List, Set, Union

import ninja_syntax
import splat
import splat.scripts.split as split
from splat.segtypes.linker_entry import LinkerEntry

ROOT = Path(__file__).parent.resolve()
TOOLS_DIR = ROOT / "tools"

VERSIONS = {
    "jp": ("SLPS_251.05", "Original Japanese"),
    "fm": ("SLPS_251.98", "Final Mix"),
}

CROSS = "mips-linux-gnu-"

COMMON_INCLUDES = "-Iinclude -isystem include/sdk/ee -isystem include/gcc"

GAME_CC_DIR = f"{TOOLS_DIR}/cc/ee-gcc2.96"
LIB_CC_DIR = f"{TOOLS_DIR}/cc/ee-gcc2.9-991111/bin"
COMMON_COMPILE_FLAGS = "-O2 -G0 $g"

GAME_GCC_CMD = f"{GAME_CC_DIR}/bin/ee-gcc -c -B {GAME_CC_DIR}/bin/ee- {COMMON_INCLUDES} {COMMON_COMPILE_FLAGS} $in"

GAME_AS_CMD = f"{GAME_CC_DIR}/ee/bin/as {COMMON_COMPILE_FLAGS} -EL -mabi=eabi"
GAME_COMPILE_CMD = f"{GAME_GCC_CMD} -S -o - | {TOOLS_DIR}/masps2.py > $out.s && {GAME_AS_CMD} $out.s"

PERMUTER_COMPILE_CMD = f"{GAME_GCC_CMD} -S -o - | {TOOLS_DIR}/masps2.py | {GAME_AS_CMD}"

LIB_COMPILE_CMD = f"{LIB_CC_DIR}/ee-gcc -c -isystem include/gcc-991111 {COMMON_INCLUDES} {COMMON_COMPILE_FLAGS}"

NO_G_FILES = [
    "xblade.c",
    "gumi.c",
]


class Paths:
    def __init__(self, version: str):
        basename, _ = VERSIONS[version]

        self.version = version
        self.basename = basename
        self.target_elf = basename
        self.target_rom = f"{basename}.rom"
        self.yaml = f"config/kh.{version}.yaml"
        self.ld_script = f"{basename}.ld"
        self.config_dir = f"config/{version}"
        self.build_dir = f"build/{version}"
        self.elf = f"{self.build_dir}/{basename}.elf"
        self.map = f"{self.build_dir}/{basename}.map"
        self.rom = f"{self.build_dir}/{basename}.rom"
        self.checksum = f"{self.config_dir}/checksum.sha1"


def clean(paths: Paths):
    if os.path.exists(".splache"):
        os.remove(".splache")
    for generated in (paths.ld_script, f"{paths.basename}.d"):
        if os.path.exists(generated):
            os.remove(generated)
    shutil.rmtree("asm", ignore_errors=True)
    shutil.rmtree("assets", ignore_errors=True)
    shutil.rmtree("build", ignore_errors=True)


def extract_rom(paths: Paths):
    elf = ROOT / paths.target_elf
    rom = ROOT / paths.target_rom

    if not elf.is_file():
        sys.exit(
            f"Could not find {paths.target_elf}. Place the {VERSIONS[paths.version][1]} "
            "executable, ripped from the disc, in the root of the repository."
        )

    subprocess.run(
        [
            f"{CROSS}objcopy",
            "-O",
            "binary",
            "--gap-fill=0x00",
            "-R",
            ".reginfo",
            str(elf),
            str(rom),
        ],
        check=True,
    )


def write_permuter_settings():
    with open("permuter_settings.toml", "w") as f:
        f.write(
            f"""compiler_command = "{PERMUTER_COMPILE_CMD} -D__GNUC__"
assembler_command = "mips-linux-gnu-as -march=r5900 -mabi=eabi -Iinclude"
compiler_type = "gcc"

[preserve_macros]

[decompme.compilers]
"tools/build/cc/gcc/gcc" = "ee-gcc2.96"
"""
        )


def asm_dependencies(paths: Paths, src_path: Path) -> List[str]:
    dep_file = Path(paths.build_dir) / src_path.with_suffix(".asmproc.d")
    if not dep_file.is_file():
        return []

    rule = dep_file.read_text().replace("\\\n", " ").split("\n")[0]
    _, _, deps = rule.partition(":")
    return deps.split()


def build_stuff(paths: Paths, linker_entries: List[LinkerEntry]):
    built_objects: Set[Path] = set()

    def build(
        object_paths: Union[Path, List[Path]],
        src_paths: List[Path],
        task: str,
        variables: Dict[str, str] = {},
        implicit: List[str] = [],
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
                implicit=implicit,
                implicit_outputs=implicit_outputs,
            )

    ninja = ninja_syntax.Writer(open(str(ROOT / "build.ninja"), "w"), width=9999)

    # Rules
    ld_args = " ".join(
        [
            "-EL",
            f"-T {paths.config_dir}/undefined_syms.txt",
            f"-T {paths.config_dir}/undefined_syms_auto.txt",
            f"-T {paths.config_dir}/undefined_funcs_auto.txt",
            "-T linker_script_extra.ld",
            "-Map $mapfile",
            "-T $in",
            "-o $out",
        ]
    )

    ninja.rule(
        "as",
        description="as $in",
        command=(
            "sed -e 's/\\x24ACC/ACC/g' -e 's/\\x24Q/Q/g' -e 's/\\x24R/R/g' "
            "-e 's/^jlabel func_/glabel func_/' $in | "
            f"{GAME_AS_CMD} -Iinclude/ee-as -Iinclude -o $out && "
            f"{CROSS}strip $out -N dummy-symbol-name"
        ),
    )

    ninja.rule(
        "hasm",
        description="as $in",
        command=(
            f"{CROSS}as -no-pad-sections -EL -march=5900 -mabi=eabi "
            f"-Iinclude/cross-as -Iinclude -o $out $in"
        ),
    )

    ninja.rule(
        "cc",
        description="cc $in",
        command=f"{GAME_COMPILE_CMD} -o $out && {CROSS}strip $out -N dummy-symbol-name",
    )

    ninja.rule(
        "libcc",
        description="cc $in",
        command=f"{LIB_COMPILE_CMD} $in -o $out && {CROSS}strip $out -N dummy-symbol-name",
    )

    ninja.rule(
        "ld",
        description="link $out",
        command=f"{CROSS}ld {ld_args}",
    )

    ninja.rule(
        "sha1sum",
        description="sha1sum $in",
        command="sha1sum -c $in && touch $out",
    )

    ninja.rule(
        "rom",
        description="rom $out",
        command=f"{CROSS}objcopy $in $out -O binary --gap-fill=0x00",
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
            if str(entry.src_paths[0]).startswith("src/"):
                rule = "hasm"
                implicit = ["include/cross-as/macro.inc", "include/macro.inc"]
            else:
                rule = "as"
                implicit = ["include/ee-as/macro.inc", "include/labels.inc"]
            build(entry.object_path, entry.src_paths, rule, implicit=implicit)
        elif isinstance(seg, splat.segtypes.common.c.CommonSegC):
            implicit = asm_dependencies(paths, entry.src_paths[0])
            if any(
                str(src_path).startswith("src/lib/") for src_path in entry.src_paths
            ):
                build(entry.object_path, entry.src_paths, "libcc", implicit=implicit)
            else:
                if entry.src_paths[0].name in NO_G_FILES:
                    g = ""
                else:
                    g = "-g"
                build(
                    entry.object_path,
                    entry.src_paths,
                    "cc",
                    variables={"g": g},
                    implicit=implicit,
                )
        elif isinstance(seg, splat.segtypes.common.databin.CommonSegDatabin):
            build(entry.object_path, entry.src_paths, "as")
        else:
            print(f"ERROR: Unsupported build segment type {seg.type}")
            sys.exit(1)

    ninja.build(
        paths.elf,
        "ld",
        paths.ld_script,
        implicit=[str(obj) for obj in built_objects],
        variables={"mapfile": paths.map},
    )

    ninja.build(
        paths.rom,
        "rom",
        paths.elf,
    )

    ninja.build(
        paths.rom + ".ok",
        "sha1sum",
        paths.checksum,
        implicit=[paths.rom],
    )

    ninja.default(paths.rom + ".ok")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Configure the project")
    parser.add_argument(
        "-v",
        "--version",
        help="Game version to configure for",
        choices=list(VERSIONS),
        default="jp",
    )
    parser.add_argument(
        "-c",
        "--clean",
        help="Clean extraction and build artifacts",
        action="store_true",
    )
    args = parser.parse_args()

    paths = Paths(args.version)

    if args.clean:
        clean(paths)

    print(
        f"Kingdom Hearts De:Compiled ~ Generating build configuration for "
        f"{VERSIONS[args.version][1]} edition ({paths.basename})"
    )

    extract_rom(paths)

    split.main([Path(paths.yaml)], modes="all", verbose=False)

    build_stuff(paths, split.linker_writer.entries)

    write_permuter_settings()
