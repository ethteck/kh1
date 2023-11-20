# A simple tool that reads the symbol_addrs.txt file produced by Splat
# and generates a .sym file for use with the PCSX2 emulator's debugger.

# NOTE: The generated .sym file MUST be in the EXACT same directory and have
# the EXACT same name as the .iso being used in PCSX2 for the emulator
# to detect it. For example, the sym file generated to accompany
# `Roms/KingdomHearts.iso` MUST be named/stored as `Roms/KingdomHearts.sym`

import os
import argparse


def generate_sym_file(input_file, output_file):
    with open(input_file, "r") as txt_file:
        lines = txt_file.readlines()

    with open(output_file, "w") as sym_file:
        for line in lines:
            # Write section titles into the output
            if line.startswith("//") and "=" not in line:
                sym_file.write("\n")  # Separate by section
                sym_file.write(line)
            else:
                # Split the line into segments, discarding unnecessary data
                parts = line.split("=")

                if len(parts) == 2:
                    # Extract symbol name and bit address
                    symbol_name = parts[0].strip()
                    rest = parts[1].split(";")
                    bit_address = rest[0].strip()[2:]  # Remove 0x prefix

                    # Write the converted data to the output .sym file
                    sym_file.write(f"{bit_address} {symbol_name}\n")


def main():
    parser = argparse.ArgumentParser(
        description="Convert Splat's symbol_addrs.txt file into a PCSX2-compatible symbol table"
    )
    parser.add_argument(
        "output_file",
        nargs="?",
        default="RENAME_TO_GAME_ISO.sym",
        help="Name of the game's ISO file. This must match or the emulator will not recognize it.",
    )
    args = parser.parse_args()

    # Read symbol_addrs.txt from the root directory
    symbol_addrs = os.path.join(
        os.path.dirname(os.path.realpath(__file__)), "../symbol_addrs.txt"
    )

    # Set the output file path, addending .sym if necessary
    output_file = args.output_file
    if not output_file.endswith(".sym"):
        output_file += ".sym"

    generate_sym_file(symbol_addrs, output_file)


if __name__ == "__main__":
    main()
