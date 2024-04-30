#include "common.h"

typedef struct XLaserDot {
    u8 unk[16];
} XLaserDot;

typedef struct XKitten {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x04 */ s32 unk_08;
    /* 0x0C */ struct XKitten* prev;
    /* 0x10 */ struct XKitten* next;
    /* 0x14 */ struct XKitten* prev_kit;
    /* 0x18 */ struct XKitten* next_kit;
    /* 0x1C */ u8 unk_1C[28];
    /* 0x38 */ u64 unk_38;
    /* 0x40 */ u8 unk_40[28];
    /* 0x5C */ XLaserDot* unk_5C;
    /* 0x60 */ u8 unk_60[8];
    /* 0x68 */ s32 unk_68;
    /* 0x6C */ u8 unk_6C[12];
    /* 0x78 */ s32 unk_78;
    /* 0x7C */ s32 unk_7C;
    /* 0x80 */ s32 unk_80;
    /* 0x84 */ s32 unk_84;
    /* 0x88 */ char unk_88[0x60];
} XKitten;

XKitten* func_001F3A20(XKitten*, s32);
void func_001F3DA0(XKitten*, s32);
void func_001F3EC8(XKitten*);
void func_001F3F00(XKitten*);
void func_001F3F18(XKitten*, s32);
s32 func_001F3F38(XKitten*);
s32 func_001F3F88(XKitten*, s32);
s32 func_001F3FD8(XKitten*);
s32 func_001F4040(XKitten*, s32);
s32 func_001F40C0(XKitten*);
void func_001F45D8(XKitten*, s32);
void func_001F45F0(XKitten*);
void func_001F4640(XKitten*);
void func_001F4668(XKitten*, XKitten*);
void func_001F4690(XKitten*, XKitten*);
void func_001F46D8(XKitten*, XKitten*);
void func_001F4888(XKitten*, s32);
