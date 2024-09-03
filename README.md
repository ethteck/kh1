# Kingdom Hearts De:Compiled

A decompilation of the Playstation 2 releases of Kingdom Hearts.

## Supported Versions

| Game Version      | ELF           | Sha1                                     |
|-------------------|---------------|------------------------------------------|
| Original Japanese | `SLPS_251.05` |`9dabbf867a7ec2a030df99ba1ed969f2deef0488`|
| Final Mix         | `SLPS_251.98` |`e70bda789916142aafb53d85cef2e806b35ad8d8`|

---

This repository currently only targets the main game executable, an elf file named uniquely by the game's serial number.

### Dependencies

Some python dependencies are required, which you can obtain by running `pip install -U -r requirements.txt`.

### Setup

1. Extract the ELF file from an ISO of the game version you're targeting and place it in the root of the repo.
2. Run `./configure.py` to generate the build files.
   - Optionally, specify the game version you're targeting with the `--region`/`-r` flag. Defaults to the original Japanese version if not specified.
   - You can clear existing configurations with the `--clean`/`-c` flag
   - eg: `./configure.py -c -r fm`

3. Run `ninja` to build the project. Final output will be stored by version in the `build` directory.
`

---

The game's assets are not included in this repository, and are not required to build the project. They may optionally be extracted by running `./tools/iso/extract.py` on the game's ISO (JP only for now). This will extract the game's assets to the `kingdom` directory.
