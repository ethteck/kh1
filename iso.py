from io import BytesIO
import sys
from typing import Optional


BLOCK_LENGTH = 0x800


def get_file_offset(data: BytesIO, filename: str) -> Optional[int]:
    base_pos = 0x105 * BLOCK_LENGTH

    filename_bytes = filename.encode("UTF-8")

    data.seek(base_pos)

    for i in range(0x500):
        something = data.read(1)
        if int.from_bytes(something) != 1:
            continue

        string_length = int.from_bytes(data.read(1))
        if string_length != len(filename_bytes):
            continue

        cur_pos = data.tell()
        read_filename = data.read(string_length)
        if read_filename == filename_bytes:
            data.seek(cur_pos - 0x1B)

            pos = int.from_bytes(data.read(4))
            return pos

        data.seek(cur_pos + 1)


with open("kh_jp.iso", "rb") as f:
    iso_bytes = f.read()

file_like = BytesIO(iso_bytes)
pos = get_file_offset(file_like, "KINGDOM.IDX;1")
if not pos:
    print("File not found")
    sys.exit(1)
print(f"{(pos * 0x800):X}")
