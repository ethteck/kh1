# Kingdom Hearts Decompilation

We're currently just targeting the main game executable, which is an elf file `SLPS_251.05` with sha1 `9dabbf867a7ec2a030df99ba1ed969f2deef0488`. 

### Dependencies
We require some python deps (`pip install -U -r requirements.txt`) and wibo for running the assembler, for which we only have a Windows executable.

### Setup

1. Extract `SLPS_251.05` from an ISO of the Kingdom Hearts (JP) and place it in the root of the repo.
2. `./configure.py`
3. `ninja`
