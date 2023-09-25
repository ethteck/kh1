from ctypes import c_uint32
from dataclasses import dataclass
from typing import Optional


@dataclass
class KingdomFile:
    hash: int
    is_compressed: bool
    iso_block: int
    length: int
    filename: Optional[str] = None

    def __rich_repr__(self):
        yield f"{self.hash:X}"
        yield "filename", self.filename
        yield "iso_block", self.iso_block
        yield "length", f"{self.length:X}"
        yield "is_compressed", self.is_compressed


def hash_filename(filename: str) -> int:
    hash = c_uint32(0)
    for c in filename:
        hash = c_uint32(
            c_uint32(hash.value * 2).value
            ^ c_uint32(c_uint32(c_uint32(ord(c)).value << 0x10).value % 69665).value
        )
    return hash.value
