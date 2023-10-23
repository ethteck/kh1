#include "common.h"

typedef struct XTrumpet {
    /* 0x000 */ u8 unk_00[16];
    /* 0x010 */ int unk_10;
    /* 0x014 */ int unk_14;
    /* 0x018 */ int unk_18;
    /* 0x01C */ int unk_1c;
    /* 0x020 */ int unk_20;
    /* 0x024 */ int unk_24;
    /* 0x028 */ int unk_28;
    /* 0x02C */ int unk_2c;
    /* 0x030 */ int unk_30;
    /* 0x034 */ int unk_34;
    /* 0x038 */ int unk_38;
    /* 0x03C */ int unk_3c;
    /* 0x040 */ int unk_40;
    /* 0x044 */ int unk_44;
    /* 0x048 */ int unk_48;
    /* 0x04C */ int unk_4c;
    /* 0x050 */ u8 unk_50[28];
    /* 0x06C */ u8 unk_6c[234];
    /* 0x156 */ // u16 unk_156; possibly unused space, unnecessary for match
    /* 0x158 */ int unk_158;
    /* 0x15C */ void* unk_15c;
} XTrumpet;

extern int D_002B8364;
extern int D_002B8678;

XTrumpet* D_002B90B0;

extern int D_002B916C;
extern int D_002B9170;
extern int D_002B9174;

extern int D_004D29D0;
extern int D_004D2998;
extern int D_004D29AC;
extern int D_004D29C4;

void func_001110A0() {
    D_002B90B0 = func_0022F768(3);
}

void func_001110D0() {
    int i;

    func_001110A0();
    for (i = 0; i < 234; i++) {
        D_002B90B0->unk_6c[i] = 0;
    }
    D_002B90B0->unk_40 = 0;
    D_002B90B0->unk_44 = 0;
    D_002B90B0->unk_10 = 0;
    D_002B90B0->unk_14 = 0;
    D_002B90B0->unk_18 = 0;
    D_002B90B0->unk_1c = 0;
    D_002B90B0->unk_20 = 0;
    D_002B90B0->unk_24 = 0;
    D_002B90B0->unk_28 = 0;
    D_002B90B0->unk_2c = 0;
    D_002B90B0->unk_30 = 0;
    D_002B90B0->unk_34 = 0;
    D_002B90B0->unk_38 = 0;
    D_002B90B0->unk_3c = 0;
    D_002B90B0->unk_158 = 0;
}

INCLUDE_ASM(const s32, "xtrumpet", func_00111158);

INCLUDE_ASM(const s32, "xtrumpet", func_00111198);

INCLUDE_ASM(const s32, "xtrumpet", func_00111210);

INCLUDE_ASM(const s32, "xtrumpet", func_00111298);

INCLUDE_ASM(const s32, "xtrumpet", func_00111328);

INCLUDE_ASM(const s32, "xtrumpet", func_001113A8);

void func_001113E8() {
    func_001809C8(&D_002B90B0->unk_4c);
}

INCLUDE_ASM(const s32, "xtrumpet", func_00111408);

INCLUDE_ASM(const s32, "xtrumpet", func_00111468);

INCLUDE_ASM(const s32, "xtrumpet", func_001114B8);

void func_00111580(int param1) {
    func_001114B8(D_002B8678, param1);
}

void* func_001115A0() {
    if (D_002B90B0) {
        return D_002B90B0->unk_15c;
    }
    return NULL;
}

void func_001115C0() {
    if (D_002B90B0) {
        D_002B90B0->unk_15c++;
    }
}

void func_001115E8() {
    D_002B8364 = 0;
    func_0022F578(-1);
    func_001EF840();
    func_001601A8();
    func_0013CB18();
    func_001EBEB0();
    func_001BC048();
    func_001110D0();
}

INCLUDE_ASM(const s32, "xtrumpet", func_00111638);

void func_001116A8() {
    D_004D2998 = 0;
}

void func_001116B8() {
    D_004D2998 = 1;
}

void func_001116C8() {
    if (D_004D2998 == 0) {
        func_0022F808();
    }
}

void func_001116F8() {
    int iVar1 = func_0013C2A8(3);
    if (iVar1 != -1) {
        D_002B90B0->unk_158 |= 8;
    }
    iVar1 = func_0013C2A8(5);
    if (iVar1 != -1) {
        D_002B90B0->unk_158 |= 0x20;
    }
    iVar1 = func_0013C2A8(6);
    if (iVar1 != -1) {
        D_002B90B0->unk_158 |= 0x40;
    }
    iVar1 = func_0013C2A8(7);
    if (iVar1 != -1) {
        D_002B90B0->unk_158 |= 0x80;
    }
    iVar1 = func_0013C2A8(8);
    if (iVar1 != -1) {
        D_002B90B0->unk_158 |= 0x100;
    }
    iVar1 = func_0013C2A8(9);
    if (iVar1 != -1) {
        D_002B90B0->unk_158 |= 0x200;
    }
}

// Injecting .rodata calls, unsure how to handle this
INCLUDE_ASM(const s32, "xtrumpet", func_001117D8);
// void func_001117D8() {
//   switch (D_002B8678) {
//   case 5:
//     if (D_002B90B0->unk158 & 8) {
//       func_0013C768(3);
//     }
//     break;
//   case 8:
//     if (D_002B90B0->unk158 & 0x20) {
//       func_0013C768(5);
//     }
//     break;
//   case 9:
//     if (D_002B90B0->unk158 & 0x40) {
//       func_0013C768(6);
//     }
//     break;
//   case 10:
//     if (D_002B90B0->unk158 & 0x80) {
//       func_0013C768(7);
//     }
//     break;
//   case 0xd:
//     if (D_002B90B0->unk158 & 0x100) {
//       func_0013C768(8);
//     }
//     break;
//   case 0xf:
//     if (D_002B90B0->unk158 & 0x200) {
//       func_0013C768(9);
//     }
//   }
// }

void func_00111910() {
    D_002B9174 = 0;
}

INCLUDE_ASM(const s32, "xtrumpet", func_00111920);
void func_00111920();

INCLUDE_ASM(const s32, "xtrumpet", func_00111A00);

INCLUDE_ASM(const s32, "xtrumpet", func_00111A70);

INCLUDE_ASM(const s32, "xtrumpet", func_00111B70);

void func_00111BD8() {
    D_004D29AC = 1;
    D_002B9174 = 1;
}

void func_00111BF0() {
    D_004D29AC = 0;
    D_002B9174 = 0;
}

int func_00111C08() {
    D_004D29AC = 2;
    return D_002B916C;
}

void func_00111C20(int param1) {
    D_002B916C = param1 * 60;
}

void func_00111C38(int param1) {
    D_004D29C4 = param1;
    D_002B9170 = 0;
}

void func_00111C50(int param1) {
    D_002B9170 = param1;
}

int func_00111C60(int param1) {
    int result;

    D_002B9170 += param1;
    if ((D_004D29C4 == 0) || (result = 1, D_002B9170 < D_004D29C4)) {
        result = 0;
    }
    return result;
}

INCLUDE_ASM(const s32, "xtrumpet", func_00111C98);

INCLUDE_ASM(const s32, "xtrumpet", func_00111D98);

INCLUDE_ASM(const s32, "xtrumpet", func_00111E20);

void func_00111F00() {
    D_004D29D0 = 1;
    func_00245130();
    func_00245140();
}

// The following unused functions might be part of xspinach?

void func_00111F28(void) {
}

void func_00111F30(void) {
}

void func_00111F38(void) {
}
