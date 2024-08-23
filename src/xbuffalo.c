#include "common.h"

s32 D_003759C4;
s32 D_003759C8;
s32 D_003759DC;

s32 D_00623B38;
s32 D_00623B48;

INCLUDE_ASM("asm/nonmatchings/xbuffalo", func_001C1680);

s32 func_001C1838(void) {
    return D_003759DC;
}

void func_001C1848(s32 arg0) {
    D_003759C4 = arg0;
}

void func_001C1858(s32 arg0) {
    D_003759C8 = arg0;
}

INCLUDE_ASM("asm/nonmatchings/xbuffalo", func_001C1868);

INCLUDE_ASM("asm/nonmatchings/xbuffalo", func_001C1888);

INCLUDE_ASM("asm/nonmatchings/xbuffalo", func_001C1970);

s32 func_001C19E8(void) {
    return 0x16FA88; // possibly some macro value?
}

INCLUDE_ASM("asm/nonmatchings/xbuffalo", func_001C19F8);

INCLUDE_ASM("asm/nonmatchings/xbuffalo", func_001C1A90);

INCLUDE_ASM("asm/nonmatchings/xbuffalo", func_001C1AB8);

INCLUDE_ASM("asm/nonmatchings/xbuffalo", func_001C1AE0);

INCLUDE_ASM("asm/nonmatchings/xbuffalo", func_001C1B40);

INCLUDE_ASM("asm/nonmatchings/xbuffalo", func_001C1BE8);

INCLUDE_ASM("asm/nonmatchings/xbuffalo", func_001C1D38);

INCLUDE_ASM("asm/nonmatchings/xbuffalo", func_001C1E78);

INCLUDE_ASM("asm/nonmatchings/xbuffalo", func_001C2080);

INCLUDE_ASM("asm/nonmatchings/xbuffalo", func_001C20B8);

INCLUDE_ASM("asm/nonmatchings/xbuffalo", func_001C2110);

s32 func_001C2150(void) {
    func_0011EF58(&D_00623B38, 0);
    return 0;
}

void* func_001C2178(void) {
    func_0011EDD0(&D_00623B38, &D_00623B48, 0x1C, 8);
    return func_0011ED30(50002, func_001C2150);
}

