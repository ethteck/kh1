#include "common.h"

s32 D_0046421C;
s32 D_0046423C;
s32 D_004642B8;

s32 D_00663A48;
s32 D_00663A4C;
s32 D_00663A50;
s32 D_00663A6C;
s32 D_00663A8C;

char* D_00463D48[4] = {"opn.dat", "end.dat", "end2.dat", "demo.dat"};

char* func_00248548(s32 idx) {
    return D_00463D48[idx];
}

s32 func_00248560(void) {
    return D_00663A48;
}

s32 func_00248570(void) {
    return D_00663A4C;
}

void func_00248580(s32 arg0) {
    D_00663A48 = arg0;
}

void func_00248590(s32 arg0) {
    D_00663A4C = arg0;
}

void func_002485A0(s32 arg0) {
    D_00663A48 = arg0;
    D_00663A4C = sceCdGetError();
}

INCLUDE_ASM("asm/nonmatchings/xjockey", func_002485C8);

void func_00248728(s32* arg0, char* arg1, f32* arg2) {
    f32 local_20[4];

    if (func_002485C8(arg0, arg1, 0, local_20) < 0) {
        asm("break");
    }

    arg2[0] = local_20[0];
}

void func_00248768(s32* arg0, char* arg1, s32* arg2) {
    s32 local_20[4];

    if (func_002485C8(arg0, arg1, 0, local_20) < 0) {
        asm("break");
    }

    arg2[0] = local_20[0];
}

void func_002487A8(s32* arg0, s32* arg1) {
    while (*arg1 != NULL) {
        if (func_002485C8(arg0, arg1[1], 0, *arg1) < 0) {
            asm("break");
        }
        arg1 += 2;
    }
}

INCLUDE_ASM("asm/nonmatchings/xjockey", func_00248808);

INCLUDE_ASM("asm/nonmatchings/xjockey", func_00248888);

INCLUDE_ASM("asm/nonmatchings/xjockey", func_002489F8);

INCLUDE_ASM("asm/nonmatchings/xjockey", func_00248A10);

INCLUDE_ASM("asm/nonmatchings/xjockey", func_00248A28);

INCLUDE_ASM("asm/nonmatchings/xjockey", func_00249000);

INCLUDE_ASM("asm/nonmatchings/xjockey", func_00249458);

INCLUDE_ASM("asm/nonmatchings/xjockey", func_002494F0);

INCLUDE_ASM("asm/nonmatchings/xjockey", func_00249958);

INCLUDE_ASM("asm/nonmatchings/xjockey", func_002499F0);

INCLUDE_ASM("asm/nonmatchings/xjockey", func_00249A70);

s32 func_00249AF0(void) {
    return D_004642B8;
}

s32 func_00249B00(void) {
    return D_00663A8C;
}

INCLUDE_ASM("asm/nonmatchings/xjockey", func_00249B10);

INCLUDE_ASM("asm/nonmatchings/xjockey", func_00249CA8);

INCLUDE_ASM("asm/nonmatchings/xjockey", func_00249D38);

s32 func_00249F78(void) {
    return D_0046423C;
}

INCLUDE_ASM("asm/nonmatchings/xjockey", func_00249F88);

s32 func_0024A000(void) {
    return D_0046421C;
}

INCLUDE_RODATA("asm/nonmatchings/xjockey", D_0048B458);

INCLUDE_RODATA("asm/nonmatchings/xjockey", D_0048B460);

INCLUDE_RODATA("asm/nonmatchings/xjockey", D_0048B478);

INCLUDE_RODATA("asm/nonmatchings/xjockey", D_0048B488);
