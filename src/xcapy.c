#include "common.h"

//#include "gcc/stdio.h"

typedef struct XCapy {
    /* 0x00 */ char unk_00[0x08];
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C; // some state
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
} XCapy;

typedef struct XCapy2 {
    /* 0x00 */ char unk_00[0x24];
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ char unk_30[0x14];
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ s32 unk_48;
    /* 0x4C */ s32 unk_4C;
    /* 0x50 */ s32 unk_50;
} XCapy2;

void func_00244048(s32, UNK_TYPE*, s32, s32, f32);
void func_00244130(s32, s32, char*, f32, char*, s32);
void func_00244200(void*);
void func_002465E8(s32*, s32);

extern UNK_TYPE D_0042BC20[];
extern s32 D_004610F8;

extern char D_0048B348[];
extern char D_0048B350[];
extern char D_0048B358[];
extern char D_0048B360[];
extern char D_0048B368[];
extern char D_0048B370[];
extern char D_0048B378[];

extern UNK_TYPE D_006632D0;
extern s32 D_006633A0[8];
extern s32 D_006633C0[8];
extern s32 D_006633E0[7];

#ifdef NON_MATCHING
void func_00244490(XCapy2* arg0) {
    char sp[3];
    char sp10[0x10];
    s32 unk_24;
    s32 x;
    s32 y;

    unk_24 = arg0->unk_24;

    if (arg0->unk_2C != 0) {
        x = unk_24 + 0x5D;
    } else {
        x = unk_24 + 0x67;
    }
    y = arg0->unk_28;

    sp[0] = 0xE5;
    sp[1] = 0x4E;
    sp[2] = 0x19;

    y += 0x2B;

    if (arg0->unk_2C != 0) {
        sprintf(sp10, D_0048B348, arg0->unk_50);
        func_00244130(x, y, sp, 0.8f, sp10, D_004610F8);
        x += 22;
        func_00244130(x, y, sp, 0.8f, D_0048B350, D_004610F8);
        x += 11;
    }
    sprintf(sp10, D_0048B348, arg0->unk_4C);
    func_00244130(x, y, sp, 0.8f, sp10, D_004610F8);
    x += 22;
    func_00244130(x, y, sp, 0.8f,D_0048B358, D_004610F8);
    x += 11;
    sprintf(sp10, D_0048B348, arg0->unk_48);
    func_00244130(x, y, sp, 0.8f, sp10, D_004610F8);
    x += 22;
    func_00244130(x, y, sp, 0.8f,D_0048B358, D_004610F8);
    x += 5;
    func_00244130(x, y, sp, 0.8f,D_0048B358, D_004610F8);
    x += 9;
    sprintf(sp10, D_0048B348, arg0->unk_44);
    func_00244130(x, y, sp, 0.8f, sp10, D_004610F8);
}
#else
void func_00244490(XCapy2*);
INCLUDE_ASM(const s32, "xcapy", func_00244490);
#endif

void func_002446B0(XCapy2* arg0) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_006633C0); i++) {
        func_00244048(D_006633C0[i], &D_006632D0, arg0->unk_24, arg0->unk_28, 1.0f);
    }
    func_00244200(arg0);
    func_00244490(arg0);
}

void func_00244730(XCapy2* arg0) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_006633A0); i++) {
        func_00244048(D_006633A0[i], &D_006632D0, arg0->unk_24, arg0->unk_28, 1.0f);
    }
    func_00244200(arg0);
    func_00244490(arg0);
}

void func_002447B0(XCapy2* arg0) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_006633E0); i++) {
        func_00244048(D_006633E0[i], &D_006632D0, arg0->unk_24, arg0->unk_28, 1.0f);
    }
    func_00244200(arg0);
}

void func_00244828(s32 arg0) {
    func_002465E8(&D_0042BC20[arg0 * 1500], 1);
}

void func_00244858(XCapy* arg0) {
    char str[0x10];
    u8 rgb[3]; // probably

    rgb[0] = 0xFF;
    rgb[1] = 0xFF;
    rgb[2] = 0xFF;

    switch (arg0->unk_0C) {
        case 1:
            sprintf(str, D_0048B360, arg0->unk_10);
            func_00244130(69, 22, rgb, 1.0f, str, D_004610F8);
            if (arg0->unk_08 != 0) {
                sprintf(str, D_0048B368);
                func_00244130(84, 22, rgb, 1.0f, str, D_004610F8);
                sprintf(str, D_0048B360, arg0->unk_14);
                func_00244130(97, 22, rgb, 1.0f, str, D_004610F8);
            }
            break;
        case 2:
            sprintf(str, D_0048B348, arg0->unk_10);
            func_00244130(69, 22, rgb, 1.0f, str, D_004610F8);
            if (arg0->unk_08 != 0) {
                sprintf(str, D_0048B368);
                func_00244130(97, 22, rgb, 1.0f, str, D_004610F8);
                sprintf(str, D_0048B348, arg0->unk_14);
                func_00244130(110, 22, rgb, 1.0f, str, D_004610F8);
            }
            break;
        case 3:
            sprintf(str, D_0048B370, arg0->unk_10);
            func_00244130(69, 22, rgb, 1.0f, str, D_004610F8);
            if (arg0->unk_08 != 0) {
                sprintf(str, D_0048B368);
                func_00244130(110, 22, rgb, 1.0f, str, D_004610F8);
                sprintf(str, D_0048B370, arg0->unk_14);
                func_00244130(123, 22, rgb, 1.0f, str, D_004610F8);
            }
            break;
        case 4:
            sprintf(str, D_0048B378, arg0->unk_10);
            func_00244130(69, 22, rgb, 1.0f, str, D_004610F8);
            if (arg0->unk_08 != 0) {
                sprintf(str, D_0048B368);
                func_00244130(123, 22, rgb, 1.0f, str, D_004610F8);
                sprintf(str, D_0048B378, arg0->unk_14);
                func_00244130(136, 22, rgb, 1.0f, str, D_004610F8);
            }
            break;
    }
}
