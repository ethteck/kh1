#include "common.h"

typedef struct {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x06 */ u16 unk_08;
    /* 0x0A */ u16 unk_0A;
    /* 0x0C */ u32 unk_0C;
    /* 0x10 */ u16 unk_10;
    /* 0x12 */ char unk_12[10];
    /* 0x1C */ u32 munny;
} XWhiskey;

u16 D_003DE5F0[12];
u32 D_003DE630[10];
XWhiskey* D_003ED718;

INCLUDE_ASM(const s32, "xtango", func_001EF210);
u32 func_001EF210(); // temporary for following functions, changes signature to unsigned

u32 func_001EF298() {
    return func_001EF210() / 216000;
}

u32 func_001EF2D0() {
    return func_001EF210() / 3600;
}

u32 func_001EF300() {
    return func_001EF210() / 60;
}

INCLUDE_ASM(const s32, "xtango", func_001EF330);

u32 func_001EF3D0() {
    return func_001EF210() / 216000;
}

u32 func_001EF408() {
    return (func_001EF210() / 3600) % 60;
}

u32 func_001EF448() {
    return (func_001EF210() / 60) % 60;
}

INCLUDE_ASM(const s32, "xtango", func_001EF488);

INCLUDE_ASM(const s32, "xtango", func_001EF530);

INCLUDE_ASM(const s32, "xtango", func_001EF5C8);

INCLUDE_ASM(const s32, "xtango", func_001EF668);

INCLUDE_ASM(const s32, "xtango", func_001EF708);

void func_001EF810() {
    D_003ED718 = (XWhiskey*)func_0022F768(5);
}

// Nonmatch: Regswap
INCLUDE_ASM(const s32, "xtango", func_001EF840);
// void func_001EF840() {
//     func_0022F888();
//     func_00218A10();
//     D_003ED718->munny = 0;
//     func_00215A88();
//     func_0021D2B0();
// }

void func_001EF878() {
    func_00230068();
    func_002304D8();
    func_001F0D88(); // in xbiscuit
    func_001F3738(); // in xbiscuit
    func_001F0C28();
    func_0020D538();
    func_00229DC8();
    func_0022A8B0();
    func_0022AED0();
    func_0022B338();
    func_0022BB00();
    func_0022BB08();
    func_0022E530();
    func_0022F218();
    func_0022F570();
}

INCLUDE_ASM(const s32, "xtango", func_001EF900);

s32 func_001EF938(s32 arg0) {
    return func_001F0EF0(D_003DE5F0[arg0]);
}

INCLUDE_ASM(const s32, "xtango", func_001EF960);

INCLUDE_ASM(const s32, "xtango", func_001EF998);

XWhiskey* func_001EF9C8(s32 arg0) {
    return (XWhiskey*)func_00147A88(arg0);
}

u32 func_001EF9E0(s32 arg0) {
    if (arg0 != 0) {
        XWhiskey* obj = (XWhiskey*)func_00147A88(arg0);
        return func_00147A50(obj->unk_00);
    }
    return func_001F0EF0(160);
}

u32 func_001EFA18(s32 arg0) {
    if (arg0 != 0) {
        XWhiskey* obj = (XWhiskey*)func_00147A88(arg0);
        return obj->unk_0C;
    }
    return 0;
}

u16 func_001EFA48(s32 arg0) {
    XWhiskey* obj = (XWhiskey*)func_00147A88(arg0);
    return obj->unk_08;
}

u16 func_001EFA68(s32 arg0) {
    XWhiskey* obj = (XWhiskey*)func_00147A88(arg0);
    return obj->unk_0A;
}

s16 func_001EFA88(s32 arg0) {
    XWhiskey* obj = (XWhiskey*)func_00147A88(arg0);
    return obj->unk_06;
}

u8 func_001EFAA8(s32 arg0) {
    XWhiskey* obj = (XWhiskey*)func_00147A88(arg0);
    return obj->unk_02;
}

u8 func_001EFAC8(s32 arg0) {
    XWhiskey* obj = (XWhiskey*)func_00147A88(arg0);
    return obj->unk_03;
}

u16 func_001EFAE8(s32 arg0) {
    XWhiskey* obj = (XWhiskey*)func_00147A88(arg0);
    return obj->unk_10;
}

u16 func_001EFB08(s32 arg0) {
    XWhiskey* obj = (XWhiskey*)func_00147A88(arg0);
    return obj->unk_04 & 1;
}

INCLUDE_ASM(const s32, "xtango", func_001EFB30);

INCLUDE_ASM(const s32, "xtango", func_001EFBB0);

INCLUDE_ASM(const s32, "xtango", func_001EFC40);

s32 func_001EFC98(s32 arg0) {
    return func_001EFAA8(arg0) != 13;
}

s32 func_001EFCC0(s32 arg0) {
    return func_001EFAA8(arg0) == 0;
}

INCLUDE_ASM(const s32, "xtango", func_001EFCE0);

INCLUDE_ASM(const s32, "xtango", func_001EFD40);

s32 func_001EFDA0(s32 arg0) {
    XWhiskey* obj;

    if (arg0 != 0) {
        obj = (XWhiskey*)func_00147A88(arg0);
        if (obj->unk_02 == 0) {
            return TRUE;
        }
    }
    return FALSE;
}

s32 func_001EFDD0(s32 arg0) {
    return func_001BC390(arg0);
}

s32 func_001EFDE8(s32 arg0) {
    return func_001BC370(arg0);
}

INCLUDE_ASM(const s32, "xtango", func_001EFE00);

s32 func_001EFE68(s32 arg0) {
    if (arg0 != 0) {
        return func_001EF9E0(arg0);
    }
    return func_001F0EF0(176);
}

s32 func_001EFE90(s32 arg0) {
    if (arg0 != 0) {
        return func_001EF9E0(arg0);
    }
    return func_001F0EF0(176);
}

s32 func_001EFEB8(s32 arg0) {
    if (arg0 != 0) {
        return func_001EFA18(arg0);
    }
    return func_001F0EF0(177);
}

s32 func_001EFEE0(s32 arg0) {
    if (arg0 != 0) {
        return func_001EFA18(arg0);
    }
    return func_001F0EF0(177);
}

INCLUDE_ASM(const s32, "xtango", func_001EFF08);

INCLUDE_ASM(const s32, "xtango", func_001EFF28);

INCLUDE_ASM(const s32, "xtango", func_001EFF90);

INCLUDE_ASM(const s32, "xtango", func_001EFFF8);

INCLUDE_ASM(const s32, "xtango", func_001F0060);

INCLUDE_ASM(const s32, "xtango", func_001F00C8);

INCLUDE_ASM(const s32, "xtango", func_001F0130);

INCLUDE_ASM(const s32, "xtango", func_001F0198);

INCLUDE_ASM(const s32, "xtango", func_001F0218);

INCLUDE_ASM(const s32, "xtango", func_001F02B8);

INCLUDE_ASM(const s32, "xtango", func_001F0330);

INCLUDE_ASM(const s32, "xtango", func_001F03A0);

INCLUDE_ASM(const s32, "xtango", func_001F0420);

s32 func_001F0530(s32 arg0) {
    return func_001EFAA8(arg0) - 2;
}

s32 func_001F0550(s32 arg0, s32 idx) {
    if (arg0 != 0) {
        return func_001EFAA8(arg0) == D_003DE630[idx];
    }
    return FALSE;
}

INCLUDE_ASM(const s32, "xtango", func_001F05A0);

INCLUDE_ASM(const s32, "xtango", func_001F0600);

s32 func_001F0650(s32 arg0) {
    if (arg0 != 0) {
        return func_001EFAA8(arg0) == 1;
    }
    return FALSE;
}

INCLUDE_ASM(const s32, "xtango", func_001F0680);

INCLUDE_ASM(const s32, "xtango", func_001F06E8);

INCLUDE_ASM(const s32, "xtango", func_001F0730);

INCLUDE_ASM(const s32, "xtango", func_001F07A0);

void* func_001F0808(s32 arg0) {
    return func_00147AE8(arg0);
}

INCLUDE_ASM(const s32, "xtango", func_001F0820);

INCLUDE_ASM(const s32, "xtango", func_001F0860);

INCLUDE_ASM(const s32, "xtango", func_001F08A0);

INCLUDE_ASM(const s32, "xtango", func_001F08D8);

INCLUDE_ASM(const s32, "xtango", func_001F0910);

INCLUDE_ASM(const s32, "xtango", func_001F0938);

INCLUDE_ASM(const s32, "xtango", func_001F0960);

INCLUDE_ASM(const s32, "xtango", func_001F0A00);

void func_001F0A58(u32 arg0) {
    D_003ED718->munny = arg0 <= 99999 ? arg0 : 99999;
}

s32 func_001F0A80() {
    return D_003ED718->munny;
}

void func_001F0A90(s32 arg0) {
    s32 val = D_003ED718->munny + arg0;

    D_003ED718->munny = val;
    if (val < 0) {
        D_003ED718->munny = 0;
        return;
    }
    if (val > 99999u) {
        D_003ED718->munny = 99999;
    }
}

void func_001F0AD0(s32 arg0) {
    s32 val = D_003ED718->munny - arg0;

    D_003ED718->munny = val;
    if (val < 0) {
        D_003ED718->munny = 0;
        return;
    }
    if (val > 99999u) {
        D_003ED718->munny = 99999;
    }
}

INCLUDE_ASM(const s32, "xtango", func_001F0B10);

INCLUDE_ASM(const s32, "xtango", func_001F0BD8);

void func_001F0C28(void) {
}
