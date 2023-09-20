import argparse


def apply(config, args):
    config["arch"] = "mipsee"
    config["baseimg"] = f"SLPS_251.05"
    config["myimg"] = f"build/SLPS_251.05"
    config["mapfile"] = f"build/SLPS_251.05.map"
    config["source_directories"] = [
        "src",
        "asm",
        "include",
        "assets",
    ]
    config["make_command"] = ["ninja"]
    config["objdump_flags"] = ["-Mfpr-names=32"]
    config["expected_dir"] = f"expected/"
