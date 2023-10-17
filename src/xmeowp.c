#include "common.h"

typedef struct XLaserDot {
  u8 unk[16];
} XLaserDot;

typedef struct XKitten {
  /* 0x00 */ int unk00;
  /* 0x04 */ int unk04;
  /* 0x04 */ int unk08;
  /* 0x0C */ struct XKitten *prev;
  /* 0x10 */ struct XKitten *next;
  /* 0x14 */ struct XKitten *prev_kit;
  /* 0x18 */ struct XKitten *next_kit;
  /* 0x1C */ u8 unk1C[6];
  /* 0x22 */ s16 unk22;
  /* 0x24 */ s16 unk24;
  /* 0x26 */ s16 unk26;
  /* 0x28 */ s16 unk28;
  /* 0x2A */ u8 unk2a[14];
  /* 0x38 */ u64 unk38;
  /* 0x40 */ u8 unk40[28];
  /* 0x5C */ XLaserDot *unk5c;
  /* 0x60 */ u8 unk60[8];
  /* 0x68 */ int unk68;
  /* 0x6C */ u8 unk6c[12];
  /* 0x78 */ int unk78;
  /* 0x7C */ int unk7c;
  /* 0x80 */ int unk80;
  /* 0x84 */ int unk84;
} XKitten;

extern s32 func_00233138(int, int);

extern XKitten D_003E3890;
extern void *D_003E3898;
extern XLaserDot D_0048A670;
extern XKitten *D_0063B050;

INCLUDE_ASM(XKitten *, "xmeowp", func_001F3A20);

XKitten *func_001F3D50(void *param_1) {
  int lVar1 = func_00233138(4, 54);
  return (XKitten*)func_001F3A20(param_1, lVar1 + 1);
}

void func_001F3D88(void *param_1) { func_001F3DA0(param_1, 6); }

INCLUDE_ASM(const s32, "xmeowp", func_001F3DA0);

void func_001F3DF0(void *param_1) {
  int iVar1 = func_00233138(4, 54);
  func_001F3DA0(param_1, iVar1 + 1);
}

XKitten* func_001F3E28(int param_1, int param_2) {
  D_003E3890.unk00 = param_2;
  D_003E3890.unk08 = param_1;
  return (XKitten*)func_001F3A20(&D_003E3890, 6);
}

XKitten *func_001F3E58(int param1, int param2, int param3) {
  D_003E3890.unk00 = param2;
  D_003E3890.unk08 = param1;
  return (XKitten*)func_001F3A20(&D_003E3890, param3);
}

XKitten *func_001F3E88(int param1, int param2) {
  int lVar1;
  D_003E3890.unk00 = param2;
  D_003E3890.unk08 = param1;
  lVar1 = func_00233138(4, 0x36);
  return (XKitten*)func_001F3A20(&D_003E3890, lVar1 + 1);
}

void func_001F3EC8(XKitten *xkitten) {
  xkitten->unk84 = 4;
  if (xkitten->prev) {
    xkitten->prev->next = xkitten->next;
  }
  if (xkitten->next) {
    xkitten->next->prev = xkitten->prev;
  }
}

void func_001F3F00(XKitten *xkitten) { xkitten->unk38 |= 0x100000000; }

void func_001F3F18(XKitten *xkitten, int param2) {
  xkitten->unk7c = param2;
  xkitten->unk38 |= 0x100000000;
}

INCLUDE_ASM(const s32, "xmeowp", func_001F3F38);

INCLUDE_ASM(const s32, "xmeowp", func_001F3F88);

INCLUDE_ASM(const s32, "xmeowp", func_001F3FD8);

INCLUDE_ASM(const s32, "xmeowp", func_001F4040);

INCLUDE_ASM(const s32, "xmeowp", func_001F40C0);

INCLUDE_ASM(const s32, "xmeowp", func_001F4150);

INCLUDE_ASM(const s32, "xmeowp", func_001F41F8);

INCLUDE_ASM(const s32, "xmeowp", func_001F42B0);

INCLUDE_ASM(const s32, "xmeowp", func_001F4380);

INCLUDE_ASM(const s32, "xmeowp", func_001F4408);

INCLUDE_ASM(const s32, "xmeowp", func_001F44A0);

INCLUDE_ASM(const s32, "xmeowp", func_001F4510);

INCLUDE_ASM(const s32, "xmeowp", func_001F4590);

void func_001F45D8(XKitten *xkitten, int param2) { xkitten->unk7c = param2; }

void func_001F45E0(XKitten *xkitten) { xkitten->unk7c = xkitten->unk78; }

void func_001F45F0(XKitten *xkitten) {
  if (xkitten->prev_kit) {
    xkitten->prev_kit->next_kit = xkitten->next_kit;
    if (xkitten->next_kit == NULL) {
      xkitten->prev_kit = NULL;
    } else {
      xkitten->next_kit->prev_kit = xkitten->prev_kit;
      xkitten->prev_kit = NULL;
    }
    xkitten->next_kit = D_0063B050;
    D_0063B050->prev_kit = xkitten;
    D_0063B050 = xkitten;
  }
}

void func_001F4640(XKitten *xkitten) {
  if (xkitten) {
    xkitten->unk38 |= 0x200000000;
  }
}

void func_001F4668(XKitten *xkitten, XKitten *prev) { xkitten->prev = prev; }

void func_001F4670(XKitten *xkitten) {
  if (xkitten->prev) {
    xkitten->prev->next = NULL;
    xkitten->prev = NULL;
  }
}

void func_001F4690(XKitten *xkitten1, XKitten *xkitten2) {
  XKitten *kit1, *kit2;

  if (xkitten1->prev) {
    xkitten1->prev->next = xkitten1->next;
    kit1 = xkitten1->next;
  } else {
    kit1 = xkitten1->next;
  }

  if (kit1) {
    kit1->prev = xkitten1->prev;
    kit2 = xkitten2->next;
  } else {
    kit2 = xkitten2->next;
  }

  xkitten2->next = xkitten1;
  xkitten1->prev = xkitten2;
  xkitten1->next = kit2;
  if (kit2 != NULL) {
    kit2->prev = xkitten1;
  }
}

void func_001F46D8(XKitten *xkitten, XKitten *next) { xkitten->next = next; }

void func_001F46E0(XKitten *xkitten) {
  if (xkitten->next) {
    xkitten->next->prev = NULL;
    xkitten->next = NULL;
  }
}

INCLUDE_ASM(const s32, "xmeowp", func_001F4700);

INCLUDE_ASM(const s32, "xmeowp", func_001F4748);

INCLUDE_ASM(const s32, "xmeowp", func_001F4790);

void func_001F47F0(XKitten *xkitten) {
  XKitten *prev, *next;

  prev = xkitten->prev;
  next = xkitten->next;
  if (prev != NULL) {
    prev->next = next;
  }
  if (next != NULL) {
    next->prev = prev;
  }
}

void func_001F4810(XKitten *xkitten1, XKitten *xkitten2) {
  XKitten *kit1_next, *kit1_prev, *kit2_next, *kit2_prev;

  kit1_next = xkitten1->next;
  kit1_prev = xkitten1->prev;
  kit2_prev = xkitten2->prev;
  kit2_next = xkitten2->next;
  if (kit1_prev != NULL) {
    kit1_prev->next = xkitten2;
  }
  if (kit1_next != NULL) {
    kit1_next->prev = xkitten2;
  }
  if (kit2_prev != NULL) {
    kit2_prev->next = xkitten1;
  }
  if (kit2_next != NULL) {
    kit2_next->prev = xkitten1;
  }
  xkitten1->prev = kit2_prev;
  xkitten1->next = kit2_next;
  xkitten2->prev = kit1_prev;
  xkitten2->next = kit1_next;
}

XLaserDot *func_001F4858(XKitten *xkitten) {
  XLaserDot *dot = xkitten->unk5c;
  if (dot == NULL) {
    dot = &D_0048A670;
  }
  return dot;
}

void func_001F4878(XKitten *xkitten, XLaserDot *dot) { xkitten->unk5c = dot; }

int func_001F4880(XKitten *xkitten) { return xkitten->unk68; }

void func_001F4888(XKitten *xkitten, int param2) { xkitten->unk68 = param2; }
