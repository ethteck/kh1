#include "common.h"

typedef struct {
  /* 0x00 */ int unk00;
  /* 0x04 */ int unk04;
  /* 0x00 */ u8 unk08[8];
  /* 0x10 */ int unk10;
  /* 0x14 */ int unk14;
  /* 0x18 */ int unk18;
  /* 0x1C */ int unk1c;
  /* 0x20 */ int unk20;
  /* 0x24 */ int unk24;
  /* 0x28 */ int unk28;
  /* 0x2C */ int unk2c;
  /* 0x30 */ int unk30;
  /* 0x34 */ int unk34;
  /* 0x38 */ int unk38;
  /* 0x3C */ int unk3c;
  /* 0x40 */ int unk40;
  /* 0x44 */ int unk44;
  /* 0x48 */ int unk48;
  /* 0x4C */ int unk4c;
  /* 0x50 */ u8 unk50[28];
  /* 0x6C */ u8 unk6c[234];
  /* 0x156 */ u16 unk156;
  /* 0x158 */ int unk158;
  /* 0x15C */ void *unk15c;
} XTrumpet;

extern int D_002B8364;
extern int D_002B8678;

XTrumpet *D_002B90B0;

extern int D_002B916C;
extern int D_002B9170;
extern int D_002B9174;

// Might be part of xspinach

extern int D_004D29D0;
extern int D_004D2998;
extern int D_004D29AC;
extern int D_004D29C4;

void func_001110A0() { D_002B90B0 = func_0022F768(3); }

void func_001110D0() {
  int i;

  func_001110A0();
  for (i = 0; i < 234; i++) {
    D_002B90B0->unk6c[i] = 0;
  }
  D_002B90B0->unk40 = 0;
  D_002B90B0->unk44 = 0;
  D_002B90B0->unk10 = 0;
  D_002B90B0->unk14 = 0;
  D_002B90B0->unk18 = 0;
  D_002B90B0->unk1c = 0;
  D_002B90B0->unk20 = 0;
  D_002B90B0->unk24 = 0;
  D_002B90B0->unk28 = 0;
  D_002B90B0->unk2c = 0;
  D_002B90B0->unk30 = 0;
  D_002B90B0->unk34 = 0;
  D_002B90B0->unk38 = 0;
  D_002B90B0->unk3c = 0;
  D_002B90B0->unk158 = 0;
}

INCLUDE_ASM(const s32, "xtrumpet", func_00111158);

INCLUDE_ASM(const s32, "xtrumpet", func_00111198);

INCLUDE_ASM(const s32, "xtrumpet", func_00111210);

INCLUDE_ASM(const s32, "xtrumpet", func_00111298);

INCLUDE_ASM(const s32, "xtrumpet", func_00111328);

INCLUDE_ASM(const s32, "xtrumpet", func_001113A8);

void func_001113E8() { func_001809C8(&D_002B90B0->unk4c); }

INCLUDE_ASM(const s32, "xtrumpet", func_00111408);

INCLUDE_ASM(const s32, "xtrumpet", func_00111468);

INCLUDE_ASM(const s32, "xtrumpet", func_001114B8);

void func_00111580(int param1) { func_001114B8(D_002B8678, param1); }

void *func_001115A0() {
  if (D_002B90B0) {
    return D_002B90B0->unk15c;
  }
  return NULL;
}

void func_001115C0() {
  if (D_002B90B0) {
    D_002B90B0->unk15c++;
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

void func_001116A8() { D_004D2998 = 0; }

void func_001116B8() { D_004D2998 = 1; }

void func_001116C8() {
  if (D_004D2998 == 0) {
    func_0022F808();
  }
}

void func_001116F8() {
  int iVar1 = func_0013C2A8(3);
  if (iVar1 != -1) {
    D_002B90B0->unk158 |= 8;
  }
  iVar1 = func_0013C2A8(5);
  if (iVar1 != -1) {
    D_002B90B0->unk158 |= 0x20;
  }
  iVar1 = func_0013C2A8(6);
  if (iVar1 != -1) {
    D_002B90B0->unk158 |= 0x40;
  }
  iVar1 = func_0013C2A8(7);
  if (iVar1 != -1) {
    D_002B90B0->unk158 |= 0x80;
  }
  iVar1 = func_0013C2A8(8);
  if (iVar1 != -1) {
    D_002B90B0->unk158 |= 0x100;
  }
  iVar1 = func_0013C2A8(9);
  if (iVar1 != -1) {
    D_002B90B0->unk158 |= 0x200;
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

void func_00111910() { D_002B9174 = 0; }

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

void func_00111C20(int param1) { D_002B916C = param1 * 60; }

void func_00111C38(int param1) {
  D_004D29C4 = param1;
  D_002B9170 = 0;
}

void func_00111C50(int param1) { D_002B9170 = param1; }

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

void func_00111F28(void) {}

void func_00111F30(void) {}

void func_00111F38(void) {}
