#include "common.h"

#include "memcard.h"
#include "xtango.h"
#include "xpotato.h"
#include "xcursed.h"

typedef struct {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ u16 unk_06;
    /* 0x08 */ u16 unk_08;
    /* 0x0A */ u16 unk_0A;
    /* 0x0C */ u32 unk_0C;
    /* 0x10 */ u32 unk_10;
} XScotch;

typedef struct {
    /* 0x0 */ u8 unk_00;
    /* 0x2 */ u16 unk_02;
    /* 0x4 */ u32 unk_04;
    /* 0x8 */ u32 unk_08;
} XBravo;

u16 D_003DE5F0[12];
u32 D_003DE630[10];
s32 D_003DE690[3];
s32 D_003DE6A0;

extern XBravo* func_00147AE8(s32);
void func_001F0C28(void);
extern void func_0021D2B0();
extern void func_0022F888();

INCLUDE_ASM("asm/nonmatchings/xtango", func_001EF210);
u32 func_001EF210(); // temporary for following functions, changes signature to unsigned

u32 func_001EF298(void) {
    return func_001EF210() / 216000;
}

u32 func_001EF2D0(void) {
    return func_001EF210() / 3600;
}

u32 func_001EF300(void) {
    return func_001EF210() / 60;
}

INCLUDE_ASM("asm/nonmatchings/xtango", func_001EF330);

u32 func_001EF3D0(void) {
    return func_001EF210() / 216000;
}

u32 func_001EF408(void) {
    return (func_001EF210() / 3600) % 60;
}

u32 func_001EF448(void) {
    return (func_001EF210() / 60) % 60;
}

INCLUDE_ASM("asm/nonmatchings/xtango", func_001EF488);

INCLUDE_ASM("asm/nonmatchings/xtango", func_001EF530);

INCLUDE_ASM("asm/nonmatchings/xtango", func_001EF5C8);

INCLUDE_ASM("asm/nonmatchings/xtango", func_001EF668);

INCLUDE_ASM("asm/nonmatchings/xtango", func_001EF708);

void func_001EF810(void) {
    D_003ED718 = func_0022F768(5);
}

void func_001EF840(void) {
    func_0022F888();
    func_00218A10();
    D_003ED718->munny = 0;
    func_00215A88();
    func_0021D2B0();
}

void func_001EF878(void) {
    func_00230068();
    memcard_Initialize();
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

INCLUDE_ASM("asm/nonmatchings/xtango", func_001EF900);

s32 func_001EF938(s32 arg0) {
    return func_001F0EF0(D_003DE5F0[arg0]);
}

s32 func_001EF960(s32 arg0) {
    return func_001F0EF0(D_003DE5F0[D_003010F8->unk_48E[arg0]]);
}

INCLUDE_ASM("asm/nonmatchings/xtango", func_001EF998);

XScotch* func_001EF9C8(s32 arg0) {
    return (XScotch*)func_00147A88(arg0);
}

u32 func_001EF9E0(s32 arg0) {
    if (arg0 != 0) {
        XScotch* obj = (XScotch*)func_00147A88(arg0);
        return func_00147A50(obj->unk_00);
    }
    return func_001F0EF0(160);
}

u32 func_001EFA18(s32 arg0) {
    if (arg0 != 0) {
        XScotch* obj = (XScotch*)func_00147A88(arg0);
        return obj->unk_0C;
    }
    return 0;
}

u16 func_001EFA48(s32 arg0) {
    XScotch* obj = (XScotch*)func_00147A88(arg0);
    return obj->unk_08;
}

u16 func_001EFA68(s32 arg0) {
    XScotch* obj = (XScotch*)func_00147A88(arg0);
    return obj->unk_0A;
}

s16 func_001EFA88(s32 arg0) {
    XScotch* obj = (XScotch*)func_00147A88(arg0);
    return obj->unk_06;
}

u8 func_001EFAA8(s32 arg0) {
    XScotch* obj = (XScotch*)func_00147A88(arg0);
    return obj->unk_02;
}

u8 func_001EFAC8(s32 arg0) {
    XScotch* obj = (XScotch*)func_00147A88(arg0);
    return obj->unk_03;
}

u16 func_001EFAE8(s32 arg0) {
    XScotch* obj = (XScotch*)func_00147A88(arg0);
    return obj->unk_10;
}

u16 func_001EFB08(s32 arg0) {
    XScotch* obj = (XScotch*)func_00147A88(arg0);
    return obj->unk_04 & 1;
}

INCLUDE_ASM("asm/nonmatchings/xtango", func_001EFB30);

s8 func_001EFBB0(s32 arg0, s32 arg1) {
    s8 bVar1;
    int iVar3;

    if (func_001EFB08(arg0) != 0) {
        arg1 = 0;
        iVar3 = D_003DE6A0;
    } else {
        iVar3 = 1;
    }

    do {
        if (func_001495C8(arg0, (u32)D_003010F8->unk_48E[arg1]) != 0) {
            return 1;
        }
        iVar3--;
        arg1++;
    } while (iVar3 != 0);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/xtango", func_001EFC40);

s32 func_001EFC98(s32 arg0) {
    return func_001EFAA8(arg0) != 13;
}

s32 func_001EFCC0(s32 arg0) {
    return func_001EFAA8(arg0) == 0;
}

INCLUDE_ASM("asm/nonmatchings/xtango", func_001EFCE0);

INCLUDE_ASM("asm/nonmatchings/xtango", func_001EFD40);

s32 func_001EFDA0(s32 arg0) {
    XScotch* obj;

    if (arg0 != 0) {
        obj = (XScotch*)func_00147A88(arg0);
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

s32 func_001EFE00(void) {
    s32 sVar1 = func_001BC578();
    s32 iVar2 = 0;
    s32 iVar3 = 0;
    s32 iVar4 = 0;
    s32 iVar5;

    if (0 < sVar1) {
        do {
            iVar5 = iVar2 + 1;
            iVar2 = func_001BC590(iVar2);
            iVar4 += iVar2;
            iVar2 = iVar5;
            iVar3 = iVar4;
        } while (iVar5 < sVar1);
    }
    return iVar4;
}

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

INCLUDE_ASM("asm/nonmatchings/xtango", func_001EFF08);

INCLUDE_ASM("asm/nonmatchings/xtango", func_001EFF28);

INCLUDE_ASM("asm/nonmatchings/xtango", func_001EFF90);

INCLUDE_ASM("asm/nonmatchings/xtango", func_001EFFF8);

INCLUDE_ASM("asm/nonmatchings/xtango", func_001F0060);

INCLUDE_ASM("asm/nonmatchings/xtango", func_001F00C8);

INCLUDE_ASM("asm/nonmatchings/xtango", func_001F0130);

INCLUDE_ASM("asm/nonmatchings/xtango", func_001F0198);

INCLUDE_ASM("asm/nonmatchings/xtango", func_001F0218);

INCLUDE_ASM("asm/nonmatchings/xtango", func_001F02B8);

INCLUDE_ASM("asm/nonmatchings/xtango", func_001F0330);

INCLUDE_ASM("asm/nonmatchings/xtango", func_001F03A0);

INCLUDE_ASM("asm/nonmatchings/xtango", func_001F0420);

s32 func_001F0530(s32 arg0) {
    return func_001EFAA8(arg0) - 2;
}

s32 func_001F0550(s32 arg0, s32 idx) {
    if (arg0 != 0) {
        return func_001EFAA8(arg0) == D_003DE630[idx];
    }
    return FALSE;
}

INCLUDE_ASM("asm/nonmatchings/xtango", func_001F05A0);

s32 func_001F0600(void) {
    s32 i;

    for (i = 3; i >= 0; i--) {
        if (D_003010F8->unk_036 == D_003DE690[i]) {
            return 0;
        }
    }
    return 1;
}

s32 func_001F0650(s32 arg0) {
    if (arg0 != 0) {
        return func_001EFAA8(arg0) == 1;
    }
    return FALSE;
}

INCLUDE_ASM("asm/nonmatchings/xtango", func_001F0680);

INCLUDE_ASM("asm/nonmatchings/xtango", func_001F06E8);

INCLUDE_ASM("asm/nonmatchings/xtango", func_001F0730);

INCLUDE_ASM("asm/nonmatchings/xtango", func_001F07A0);

XBravo* func_001F0808(s32 arg0) {
    return func_00147AE8(arg0);
}

u32 func_001F0820(s32 arg0) {
    if (arg0 != 0) {
        return func_00147AE8(arg0 & ~0x80)->unk_04;
    }
    return func_001F0EF0(189);
}

u32 func_001F0860(s32 arg0) {
    if (arg0 != 0) {
        return func_00147AE8(arg0 & ~0x80)->unk_08;
    }
    return func_001F0EF0(189);
}

u8 func_001F08A0(s32 arg0) {
    if (arg0 != 0) {
        return func_00147AE8(arg0 & ~0x80)->unk_00;
    }
    return 0;
}

u16 func_001F08D8(s32 arg0) {
    if (arg0 != 0) {
        return func_00147AE8(arg0 & ~0x80)->unk_02;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/xtango", func_001F0910);

INCLUDE_ASM("asm/nonmatchings/xtango", func_001F0938);

INCLUDE_ASM("asm/nonmatchings/xtango", func_001F0960);

INCLUDE_ASM("asm/nonmatchings/xtango", func_001F0A00);

void func_001F0A58(u32 arg0) {
    D_003ED718->munny = arg0 <= 99999 ? arg0 : 99999;
}

s32 func_001F0A80(void) {
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

INCLUDE_ASM("asm/nonmatchings/xtango", func_001F0B10);

s32 func_001F0BD8(s32 arg0) {
    s32 val = func_0013DA88(D_003010F8->unk_48E[arg0]);
    if (val == 0 || func_001233F8(val) == 0) {
        return 0;
    }
    return val;
}

void func_001F0C28(void) {
}
