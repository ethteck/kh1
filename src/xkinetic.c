#include "common.h"
#include "xflamingo.h"
#include "xhumungus.h"
#include "xcursed.h"

INCLUDE_ASM("asm/nonmatchings/xkinetic", func_001C21B8);

s32 func_001C2270(void) {
    return 2;
}

s32 func_001C2278(Script* arg0, s32 arg1) {
    arg0->unk_174[2] += arg1;
    if (arg1 < 0) {
        return 4;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/xkinetic", func_001C2298);

s32 func_001C22E8(void) {
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xkinetic", func_001C22F0);

INCLUDE_ASM("asm/nonmatchings/xkinetic", func_001C2328);

INCLUDE_ASM("asm/nonmatchings/xkinetic", func_001C2370);

INCLUDE_ASM("asm/nonmatchings/xkinetic", func_001C23C0);

INCLUDE_ASM("asm/nonmatchings/xkinetic", func_001C2410);

INCLUDE_ASM("asm/nonmatchings/xkinetic", func_001C2460);

s32 func_001C24B0(Script* arg0) {
    arg0->unk_2F0--;
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xkinetic", func_001C24C8);

s64 func_001C2578(s64 arg0, s32 arg1) {
    switch (arg1) {
        case 0:
        case 1:
            arg0 &= 1;
        case 2:
            if (arg0 < -0x80) {
                arg0 = -0x80;
            } else if (arg0 >= 0x7f) {
                arg0 = 0x7f;
            }
            break;
        case 3:
            if (arg0 < -0x8000) {
                arg0 = -0x8000;
            } else if (arg0 >= 0x7fff) {
                arg0 = 0x7fff;
            }
            break;
        case 4:
            if (arg0 < -0x800000) {
                arg0 = -0x800000;
            } else if (arg0 >= 0x7fffff) {
                arg0 = 0x7fffff;
            }
            break;
        case 5:
            if (arg0 < 0) {
                arg0 = 0;
            } else if (arg0 >= 0xff) {
                arg0 = 0xff;
            }
            break;
        case 6:
            if (arg0 < 0) {
                arg0 = 0;
            } else if (arg0 >= 0xffff) {
                arg0 = 0xffff;
            }
            break;
        case 7:
            if (arg0 < 0) {
                arg0 = 0;
            } else if (arg0 >= 0xffffff) {
                arg0 = 0xffffff;
            }
            break;
    }
    return arg0;
}

s32 func_001C26A8(Script* arg0, s64 arg1) {
    s32 val = func_001C2578(arg1, 4);

    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = val;
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xkinetic", func_001C26F8);

INCLUDE_ASM("asm/nonmatchings/xkinetic", func_001C2728);

s32 func_001C27D8(s32 arg0) {
    void* temp = func_0022F768(2); // todo: find proper struct for this argument
    return temp + arg0;
}

INCLUDE_ASM("asm/nonmatchings/xkinetic", func_001C2808);

INCLUDE_ASM("asm/nonmatchings/xkinetic", func_001C28B8);

INCLUDE_ASM("asm/nonmatchings/xkinetic", func_001C2AA0);

INCLUDE_ASM("asm/nonmatchings/xkinetic", func_001C2B60);

s32 func_001C2CA0(void) {
    return 2;
}

s32 func_001C2CA8(void) {
    return 2;
}

s32 func_001C2CB0(void) {
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xkinetic", func_001C2CB8);

INCLUDE_ASM("asm/nonmatchings/xkinetic", func_001C2D40);

INCLUDE_ASM("asm/nonmatchings/xkinetic", func_001C2D70);

INCLUDE_ASM("asm/nonmatchings/xkinetic", func_001C2FB0);

INCLUDE_ASM("asm/nonmatchings/xkinetic", func_001C30A0);

INCLUDE_ASM("asm/nonmatchings/xkinetic", func_001C3208);

INCLUDE_ASM("asm/nonmatchings/xkinetic", func_001C32E8);

INCLUDE_ASM("asm/nonmatchings/xkinetic", func_001C3308);

INCLUDE_ASM("asm/nonmatchings/xkinetic", func_001C3380);

INCLUDE_ASM("asm/nonmatchings/xkinetic", func_001C3430);

INCLUDE_ASM("asm/nonmatchings/xkinetic", func_001C34E0);

INCLUDE_ASM("asm/nonmatchings/xkinetic", func_001C3670);

INCLUDE_ASM("asm/nonmatchings/xkinetic", func_001C3680);
