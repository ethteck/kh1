#!/usr/bin/env python3

import fileinput
from typing import List

NOP = "        nop # inserted by masps2.py\n"

float_reg_map = {
    "$f0": "$f1",
    "$f1": "$f0",
    "$f2": "$f3",
    "$f3": "$f2",
    "$f4": "$f5",
    "$f5": "$f4",
    "$f6": "$f7",
    "$f7": "$f6",
    "$f8": "$f9",
    "$f9": "$f8",
    "$f10": "$f11",
    "$f11": "$f10",
    "$f12": "$f13",
    "$f13": "$f12",
    "$f14": "$f15",
    "$f15": "$f14",
    "$f16": "$f17",
    "$f17": "$f16",
    "$f18": "$f19",
    "$f19": "$f18",
    "$f20": "$f21",
    "$f21": "$f20",
    "$f22": "$f23",
    "$f23": "$f22",
    "$f24": "$f25",
    "$f25": "$f24",
    "$f26": "$f27",
    "$f27": "$f26",
    "$f28": "$f29",
    "$f29": "$f28",
    "$f30": "$f31",
    "$f31": "$f30",
}


def get_next_op(lines: List[str], commented_nop=True) -> bool:
    for line in lines:
        line = line.strip()
        if not line:
            continue
        if line.startswith("."):
            continue
        if line.endswith(":"):
            continue
        if not commented_nop and line == "#nop":
            continue
        return line
    return ""


def is_next_op_floaty(lines: List[str]) -> bool:
    next_op = get_next_op(lines, commented_nop=False)
    if not next_op:
        return False
    return ".s" in next_op


def shares_float_regs(reg1: str, reg2: str) -> bool:
    if reg1 == reg2:
        return True
    if reg1 in float_reg_map and float_reg_map[reg1] == reg2:
        return True
    if reg2 in float_reg_map and float_reg_map[reg2] == reg1:
        return True
    return False


def get_op_inputs(op: str) -> List[str]:
    op, args = op.split()[:2]
    args = args.split(",")

    if op in ("mtc1", "s.s"):
        return [args[0]]
    return args[1:]


def process(in_lines: List[str]) -> List[str]:
    out_lines = []
    for i, line in enumerate(in_lines):
        out_lines.append(line)

        if "c.le.s" in line:
            out_lines.append(NOP)

        if "c.lt.s" in line:
            out_lines.append(NOP)

        if "li.s" in line:
            if get_next_op(in_lines[i + 1 :]) == "#nop":
                out_lines.append(NOP)
            else:
                next_op = get_next_op(in_lines[i + 1 :], commented_nop=False)
                this_dest = line.split()[1].split(",")[0]
                next_inputs = get_op_inputs(next_op)
                if any(shares_float_regs(this_dest, reg) for reg in next_inputs):
                    out_lines.append(NOP)

        if "mfc1" in line:
            out_lines.append(NOP)

        if "mtc1" in line:
            if is_next_op_floaty(in_lines[i + 1 :]):
                out_lines.append(NOP)
    return out_lines


in_lines = [line for line in fileinput.input()]
out_lines = process(in_lines)
for line in out_lines:
    print(line, end="")
