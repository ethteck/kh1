#include "common.h"

typedef struct {
    /* 0x00 */ char unk_00[0x10];
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
} XFlapjack;

s32 D_002B29CC;
s32 D_002B29D0;

s32 D_002B85C0[4];
s32 D_002B860C;

extern f32 D_002B8340[];
extern u16 D_002B8C70;

f32 D_0048E508;

s32 func_001061D8() {
    if (((D_002B85C0[0] == 0) || (D_002B860C == 128)) & 0xFFFFu) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM(const s32, "xpancake", func_00106208);

INCLUDE_ASM(const s32, "xpancake", func_00106230);

INCLUDE_ASM(const s32, "xpancake", func_00106380);

INCLUDE_ASM(const s32, "xpancake", func_00106428);

void func_001064E8() {
    D_0048E508 = 0;
}

s32 func_001064F8(XFlapjack* arg0) {
    arg0->unk_10 += D_002B8340[1];
    if (arg0->unk_18 <= arg0->unk_10) {
        D_002B85C0[3] = 128;
        D_002B85C0[2] = 128;
        D_002B85C0[1] = 128;
        D_002B85C0[0] = 128;
        return 4;
    }
    D_002B85C0[3] = arg0->unk_14 * arg0->unk_10;
    D_002B85C0[2] = arg0->unk_14 * arg0->unk_10;
    D_002B85C0[1] = arg0->unk_14 * arg0->unk_10;
    D_002B85C0[0] = arg0->unk_14 * arg0->unk_10;
    return 0;
}

void func_00106578(s32 arg0) {
    XFlapjack* p0;
    s32 val;

    func_00106718();
    func_00106728();
    p0 = func_0011EEB8(&D_002B8C70, 0, func_001064F8);
    val = arg0 << 1;
    if (arg0 == 0) {
        arg0 = 1;
    }
    if (p0 != NULL) {
        p0->unk_10 = 0.0f;
        p0->unk_18 = val;
        p0->unk_14 = 128.0f / (arg0 << 1);
    }
}

s32 func_00106610(XFlapjack* arg0) {
    arg0->unk_10 -= D_002B8340[1];
    if (arg0->unk_10 <= 0) {
        D_002B85C0[3] = 0;
        D_002B85C0[2] = 0;
        D_002B85C0[1] = 0;
        D_002B85C0[0] = 0;
        return 4;
    }
    D_002B85C0[3] = arg0->unk_14 * arg0->unk_10;
    D_002B85C0[2] = arg0->unk_14 * arg0->unk_10;
    D_002B85C0[1] = arg0->unk_14 * arg0->unk_10;
    D_002B85C0[0] = arg0->unk_14 * arg0->unk_10;
    return 0;
}

void func_00106690(s32 arg0) {
    XFlapjack* p0 = func_0011EEB8(&D_002B8C70, 0, func_00106610);
    s32 val = arg0 << 1;
    if (arg0 == 0) {
        arg0 = 1;
    }
    if (p0 != NULL) {
        p0->unk_10 = val;
        p0->unk_14 = 128.0f / (arg0 << 1);
    }
}

void func_00106718() {
    D_002B29CC = 0;
}

void func_00106728() {
    D_002B29D0 = 0;
}

s32 func_00106738(XFlapjack* arg0) {
    arg0->unk_10 += D_002B8340[1];
    if (arg0->unk_18 <= arg0->unk_10) {
        D_002B860C = 128;
        return 4;
    }
    D_002B860C = arg0->unk_14 * arg0->unk_10;
    return 0;
}

void func_00106790(s32 arg0) {
    XFlapjack* p0;
    s32 val;

    func_00106718();
    func_00106728();
    p0 = func_0011EEB8(&D_002B8C70, 0, func_00106738);
    val = arg0 << 1;
    if (arg0 == 0) {
        arg0 = 1;
    }
    if (p0 != NULL) {
        p0->unk_10 = 0.0f;
        p0->unk_18 = val;
        p0->unk_14 = 128.0f / (arg0 << 1);
    }
}

s32 func_00106828(XFlapjack* arg0) {
    f32 new_var = 0.0f;

    arg0->unk_10 -= D_002B8340[1];
    if (new_var >= arg0->unk_10) {
        if (((arg0->unk_14 == 0) && (!(new_var = arg0->unk_14))) && (new_var == 0)) {
        }
        D_002B860C = 0;
        return 4;
    }
    D_002B860C = arg0->unk_14 * arg0->unk_10;
    return 0;
}

void func_00106880(s32 arg0) {
    XFlapjack* p0;
    f32 f0;
    s32 val;

    if ((D_002B29CC == 1) || (D_002B29D0 == 1)) {
        func_00106578(arg0);
        func_00106718();
        func_00106728();
        return;
    }

    p0 = func_0011EEB8(&D_002B8C70, 0, func_00106828);
    val = arg0 << 1;
    f0 = 128.0f;
    if (arg0 == 0) {
        arg0 = 1;
    }
    if (p0 != 0) {
        p0->unk_10 = val;
        p0->unk_14 = f0 / ((f32)(arg0 << 1));
    }
}
