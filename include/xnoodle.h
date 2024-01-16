#include "common.h"
#include "io.h"
#include "sdk/ee/libvu0.h"

typedef struct XNoodle {
    /* 0x00 */ char unk_00[0x14];
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ char unk_24[0xC];
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ char unk_40[0x18];
    /* 0x58 */ f32 unk_58;
    /* 0x5C */ f32 unk_5C;
    /* 0x60 */ sceVu0FVECTOR unk_60;
    /* 0x70 */ char unk_70[0x10];
    /* 0x80 */ s32 unk_80;
} XNoodle;

void func_0010AD58(u32);
void func_0010BB10(XNoodle*, s32);
void func_0010BB50();
void* func_0010BE10();
void func_0010BF08(void (*)(IOReadTask*), IOReadTask*);
void func_0010BF50(void (*)(IOReadTask*));
void func_0010BF98();
void func_0010BFD8();
void func_0010C010();
void func_0010C0E0();
void func_0010C110();
void func_0010C158();
