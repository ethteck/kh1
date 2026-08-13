import argparse


def apply(config, args):
    config["arch"] = "mipsee"
    config["baseimg"] = f"SLPS_251.05.rom"
    config["myimg"] = f"build/jp/SLPS_251.05.rom"
    config["mapfile"] = f"build/jp/SLPS_251.05.map"
    config["source_directories"] = [
        "src",
        "asm",
        "include",
        "assets",
    ]
    config["make_command"] = ["ninja"]
    config["objdump_flags"] = ["-Mreg-names=n32"]
    config["expected_dir"] = f"expected/"
