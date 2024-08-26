#include "common.h"

typedef struct {
    /* 0x00 */ char unk_0x00[0x10];
    /* 0x10 */ sceVu0FVECTOR* unk_10;
    /* 0x20 */ sceVu0FVECTOR unk_20;
    /* 0x30 */ sceVu0FVECTOR unk_30;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ void (*unk_48)(sceVu0FVECTOR*);
} XHoot;

extern f32 D_002B8340[];

s32 D_004FA670;
s32 D_004FA680;

s32 func_00122828(XHoot* arg0) {
    s32 uVar1;
    f32 fVar2;
    f32 r;

    uVar1 = 0;
    fVar2 = arg0->unk_44 - D_002B8340[1];

    r = fVar2 / arg0->unk_40;
    arg0->unk_44 = fVar2;
    if (r < 0.0f) {
        r = 0.0f;
        if (arg0->unk_48 != NULL) {
            arg0->unk_48(arg0->unk_10);
        }
        uVar1 = 4;
    }
    sceVu0InterVector(arg0->unk_10[3], &arg0->unk_20, &arg0->unk_30, r);
    return uVar1;
}

// Nonmatch: Preprocessor is adding nops unintentionally
INCLUDE_ASM("asm/nonmatchings/xowl", func_001228C8);
// void func_001228C8(f32 arg0, sceVu0FVECTOR* arg1, f32* arg2, void (*arg3)()) {
//     XHoot* pvVar1;

//     if (0.0f >= arg0) {
//         sceVu0CopyVector(arg1[3], arg2);
//     } else {
//         pvVar1 = func_0011EEB8(&D_004FA670, 0, func_00122828);
//         pvVar1->unk_10 = arg1;
//         pvVar1->unk_44 = arg0;
//         pvVar1->unk_40 = arg0;
//         pvVar1->unk_48 = arg3;
//         sceVu0CopyVector(pvVar1->unk_20, arg1[3]);
//         sceVu0CopyVector(pvVar1->unk_30, arg2);
//     }
// }

INCLUDE_ASM("asm/nonmatchings/xowl", func_00122988);

INCLUDE_ASM("asm/nonmatchings/xowl", func_00122AF8);

void func_00122B70(s32* arg0) {
    *arg0 = 0;
}

INCLUDE_ASM("asm/nonmatchings/xowl", func_00122B78);

INCLUDE_ASM("asm/nonmatchings/xowl", func_00122DD8);

INCLUDE_ASM("asm/nonmatchings/xowl", func_00122EC8);

void func_00122FF0(void) {
    func_0011EDD0(&D_004FA670, &D_004FA680, 0x50, 8);
}

INCLUDE_ASM("asm/nonmatchings/xowl", func_00123020);

INCLUDE_ASM("asm/nonmatchings/xowl", func_00123088);

INCLUDE_ASM("asm/nonmatchings/xowl", func_001230D0);

INCLUDE_ASM("asm/nonmatchings/xowl", func_00123108);
