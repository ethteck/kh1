# Kingdom Hearts De:Compiled

A decompilation of the Playstation 2 releases of Kingdom Hearts.

## Supported Versions

| Game Version             | ELF           | Sha1                                     |
|--------------------------|---------------|------------------------------------------|
| Original Japanese        | `SLPS_251.05` |`9dabbf867a7ec2a030df99ba1ed969f2deef0488`|
| Final Mix (JP Exclusive) | `SLPS_251.98` |`e70bda789916142aafb53d85cef2e806b35ad8d8`|

---

### Dependencies

Some python dependencies are required, which you can obtain by running `pip install -U -r requirements.txt`.

---

### Setup

1. Extract the ELF file from an ISO of the game version you're targeting and place it in the root of the repo.
2. Run `./configure.py` to generate the build files.
   - Optionally, specify the game version you're targeting with the `--version`/`-v` flag. Defaults to the original Japanese version if not specified.
   - You can clear existing configurations with the `--clean`/`-c` flag
   - eg: `./configure.py -c -v fm` will clear the existing build configuration and generate a new one for the Final Mix version.

3. Run `ninja` to build the project. Final output will be stored by version in the `build` directory.

---

### Notes

No game assets are published in this repository. This includes any files required to run the game, such as the game's executable, ISO, or any files extracted from it.

This repository targets the game's main executable, an elf file named uniquely by the game's serial number. A copy of the elf file is required to build the project, and must be provided by the user by extracting it from a legal copy of the game.

 >[!WARNING]
 > Additional asset extraction is currently only supported by the JP version of the game.

Additional assets that are not used in this project may optionally be extracted by running `./tools/iso/extract.py` on the game's ISO. The extracted files are in the `kingdom` directory.
