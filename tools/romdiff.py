#! /usr/bin/env python3
"""Report where a built ROM differs from the target it should match.

A failing `sha1sum -c` only says the build didn't match. This says which
objects it didn't match in, which is usually enough to name the culprit.
Intended for CI triage; never fails, so it can be dropped in a post block.
"""

import argparse
import re
import sys
from pathlib import Path

import yaml

ROOT = Path(__file__).parent.parent.resolve()

VERSIONS = {
    "jp": "SLPS_251.05",
    "fm": "SLPS_251.98",
}

# Regions to print before giving up; a wholesale mismatch is not worth dumping.
MAX_REGIONS = 40

# Single-line map entry: " .text  0x00000000002304d8  0x2b9c  build/jp/foo.o".
# Long section names wrap onto their own line, leaving the rest indented.
MAP_ENTRY_RE = re.compile(r"^\s+(\.\S+)\s+0x([0-9a-f]+)\s+0x([0-9a-f]+)\s+(\S+)$")
MAP_WRAP_RE = re.compile(r"^\s+(\.\S+)$")
MAP_WRAPPED_ENTRY_RE = re.compile(r"^\s+0x([0-9a-f]+)\s+0x([0-9a-f]+)\s+(\S+)$")


def load_vram_base(version: str):
    """Return (rom_start, vram) of the first segment, to map offsets to vram."""
    yaml_path = ROOT / f"config/kh.{version}.yaml"
    if not yaml_path.is_file():
        return None

    with open(yaml_path) as f:
        config = yaml.load(f, Loader=yaml.SafeLoader)

    for segment in config.get("segments", []):
        if isinstance(segment, dict) and "vram" in segment:
            return segment.get("start", 0), segment["vram"]
    return None


def load_map(map_path: Path):
    """Return [(start_vram, end_vram, section, object)] sorted by address."""
    if not map_path.is_file():
        return []

    entries = []
    pending_section = None

    for line in map_path.read_text(errors="replace").split("\n"):
        match = MAP_ENTRY_RE.match(line)
        if match:
            pending_section = None
            section, addr, size, obj = match.groups()
        else:
            match = MAP_WRAPPED_ENTRY_RE.match(line)
            if match and pending_section:
                section = pending_section
                addr, size, obj = match.groups()
                pending_section = None
            else:
                wrap = MAP_WRAP_RE.match(line)
                pending_section = wrap.group(1) if wrap else None
                continue

        if not obj.endswith(".o"):
            continue

        start = int(addr, 16)
        length = int(size, 16)
        if length:
            entries.append((start, start + length, section, obj))

    entries.sort()
    return entries


def owner(entries, vram):
    for start, end, section, obj in entries:
        if start <= vram < end:
            return f"{obj} ({section}+{hex(vram - start)})"
    return "unknown"


def regions(target: bytes, built: bytes):
    """Group differing byte offsets into contiguous runs."""
    runs = []
    start = None

    for i in range(min(len(target), len(built))):
        if target[i] != built[i]:
            if start is None:
                start = i
        elif start is not None:
            runs.append((start, i))
            start = None

    if start is not None:
        runs.append((start, min(len(target), len(built))))

    return runs


def report(version: str) -> bool:
    """Print a diff report. Returns False if there was nothing to compare."""
    basename = VERSIONS[version]
    target_path = ROOT / f"{basename}.rom"
    built_path = ROOT / f"build/{version}/{basename}.rom"

    if not target_path.is_file() or not built_path.is_file():
        return False

    target = target_path.read_bytes()
    built = built_path.read_bytes()

    print(f"=== {version}: {built_path.relative_to(ROOT)} vs {target_path.name} ===")

    if target == built:
        print("    matches")
        return True

    if len(target) != len(built):
        print(f"    size differs: target {len(target)}, built {len(built)}")

    runs = regions(target, built)
    total = sum(end - start for start, end in runs)
    print(f"    {total} bytes differ in {len(runs)} region(s)")

    base = load_vram_base(version)
    entries = load_map(ROOT / f"build/{version}/{basename}.map")
    if not entries:
        print("    (no linker map; cannot attribute to objects)")

    objects = set()
    for i, (start, end) in enumerate(runs):
        vram = None
        if base is not None:
            rom_start, vram_base = base
            vram = start - rom_start + vram_base

        who = owner(entries, vram) if entries and vram is not None else "unknown"
        objects.add(who.split(" ")[0])

        if i >= MAX_REGIONS:
            continue

        where = f"    {hex(start)}"
        if vram is not None:
            where += f"  vram {hex(vram)}"
        print(f"{where}  {end - start} bytes  {who}")

        # Print the containing words, which is usually where the story is.
        word = start & ~3
        while word < end:
            chunk = slice(word, word + 4)
            print(
                f"        {hex(word)}  target {target[chunk].hex()}"
                f"  built {built[chunk].hex()}"
            )
            word += 4

    if len(runs) > MAX_REGIONS:
        print(f"    ... {len(runs) - MAX_REGIONS} more region(s) not shown")

    print("    affected objects:")
    for obj in sorted(objects):
        print(f"        {obj}")

    return True


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "-v",
        "--version",
        help="Game version to check (default: every version that was built)",
        choices=list(VERSIONS),
        action="append",
    )
    args = parser.parse_args()

    compared = False
    for version in args.version or list(VERSIONS):
        compared |= report(version)

    if not compared:
        print("romdiff: nothing built to compare", file=sys.stderr)

    # Purely diagnostic; the build already reported its own verdict.
    sys.exit(0)
