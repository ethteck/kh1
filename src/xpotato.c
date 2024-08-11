#include "xtango.h"
#include "xpotato.h"

extern u32 D_003DE6A0;
extern s32 D_003E3088;
extern s32 D_003ED728;
extern s32 D_003ED72C;
extern u32 D_003ED730;
extern s32 D_003EE8B0;

extern void* D_0063CF00;
extern s32 D_0063CF04;
extern u32 D_0063CF18;
extern u32 D_0063CF38;
extern u32 D_0063CF3C;
extern u32 D_0063CF40;
extern u32 D_0063CF44;
extern u32 D_0063CF48;
extern u32 D_0063CF4C;
extern u32 D_0063CF50;
extern u32 D_0063CF88;
extern u32 D_0063CFA0;
extern u32 D_0063D050;

extern void* func_001F3A20(void*, s32);
extern void func_001F9B50(s32);

void func_00215A88(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_003ED718->unk_20); i++) {
        D_003ED718->unk_20[i] = 4;
        func_00215AF0(i, 4);
    }
}

INCLUDE_ASM("asm/nonmatchings/xpotato", func_00215AF0);

INCLUDE_ASM("asm/nonmatchings/xpotato", func_00215B88);

s32 func_00215C48(s32 arg0) {
    s32 val;

    func_001F9B50(23);
    val = 239;
    if (D_0063CF44 != D_0063CF38 - 1) {
        val = func_00132EF0(D_0063CF44);
        val = (&D_0063CF18)[D_0063CF44] * 3 + val + 217;
    }
    return func_001F9F78(arg0, 0, 174, 12, val, 17, 0x80c87850);
}

INCLUDE_ASM("asm/nonmatchings/xpotato", func_00215CE8);

INCLUDE_ASM("asm/nonmatchings/xpotato", func_00215EE8);

INCLUDE_ASM("asm/nonmatchings/xpotato", func_00215F48);

INCLUDE_ASM("asm/nonmatchings/xpotato", func_00216198);

s32 func_00216758(XWhiskey* arg0) {
    func_001F9B50(23);
    return func_001F9F78(arg0, 0, 174, 12, arg0->munny, 17, 0x80c87850);
}

INCLUDE_ASM("asm/nonmatchings/xpotato", func_002167A0);

INCLUDE_ASM("asm/nonmatchings/xpotato", func_002168F8);

INCLUDE_ASM("asm/nonmatchings/xpotato", func_00216D88);

s32 func_00217038(s32 arg0) {
    s32 val = 213;
    if (D_0063CF3C != 0) {
        val = 214;
        D_003E3088 = func_001EF960(D_0063CF3C);
    }
    func_001F9B50(23);
    return func_001F9F78(arg0, 0, 174, 12, val, 17, 0x80c87850);
}

INCLUDE_ASM("asm/nonmatchings/xpotato", func_002170B0);

INCLUDE_ASM("asm/nonmatchings/xpotato", func_00217420);

s32 func_00217810(s32 arg0) {
    return func_00207728(arg0, 4, 2, 0, 0, 122, 117);
}

void func_00217840(void* arg0) {
    void* p0 = func_001F3A20(&D_003EE8B0, 0);

    if (p0 != NULL) {
        func_001F4690(p0, arg0);
    }
    D_0063CF00 = arg0;
    D_0063CF04 = NULL;
}

void func_00217898(void) {
    if (D_0063CF3C > D_003DE6A0 - 1) {
        D_0063CF3C = D_003DE6A0 - 1;
    }
    func_00215B88();
}

void func_002178D0(void) {
    D_0063CF3C = 0;
    D_0063CF40 = 0;
    D_0063CF44 = 0;
    D_0063CF48 = 0;
    D_0063CF4C = 0;
    D_0063CF50 = 0;
}

INCLUDE_ASM("asm/nonmatchings/xpotato", func_00217908);

INCLUDE_ASM("asm/nonmatchings/xpotato", func_00217B00);

s32 func_00218648(s32 arg0) {
    s32 val = 277;

    func_001F9B50(23);
    if (D_0063CF88 != 0) {
        D_003E3088 = func_001EF960(D_0063CF88);
        val = 278;
    }
    return func_001F9F78(arg0, 0, 174, 12, val, 17, 0x80c87850);
}

INCLUDE_ASM("asm/nonmatchings/xpotato", func_002186B8);

s32 func_00218840(s32 arg0) {
    return func_00207728(arg0, 4, 2, 0, 0, 122, 118);
}

INCLUDE_ASM("asm/nonmatchings/xpotato", func_00218870);

void func_002189D0(void) {
    if (D_0063CF88 > D_003DE6A0 - 1) {
        D_0063CF88 = D_003DE6A0 - 1;
    }
}

void func_00218A00(void) {
    D_0063CF88 = 0;
}

void func_00218A10(void) {
    D_003ED718->unk_00 = 0;
    D_003ED718->unk_08 = 0;
    D_003ED718->unk_04 = 0;
    D_003ED718->unk_0C = 0;
    D_003ED718->unk_10 = 0;
    D_003ED718->unk_14 = 0;
    D_003ED718->unk_18 = 0;
}

INCLUDE_ASM("asm/nonmatchings/xpotato", func_00218A38);

INCLUDE_ASM("asm/nonmatchings/xpotato", func_00218AC0);

u32 func_00218B48(void) {
    return D_003ED718->unk_00;
}

u32 func_00218B58(void) {
    return func_00218B48();
}

void func_00218B70(s32 arg0) {
    D_003ED718->unk_00 = arg0;
}

u32 func_00218B80(void) {
    return D_003ED718->unk_04;
}

u32 func_00218B90(void) {
    return func_00218B80();
}

u32 func_00218BA8(u32 arg0) {
    D_003ED718->unk_04 = arg0;
}

s32 func_00218BB8(void) {
    return D_003ED718->unk_08;
}

u32 func_00218BC8(void) {
    return func_00218BB8();
}

void func_00218BE0(s32 arg0) {
    D_003ED718->unk_08 = arg0;
}

u32 func_00218BF0(void) {
    return 0;
}

u32 func_00218BF8(void) {
    return 0;
}

void func_00218C00(void) {
}

u32 func_00218C08(void) {
    return D_003ED718->unk_10;
}

s32 func_00218C18(void) {
    return func_00218C08();
}

void func_00218C30(s32 arg0) {
    D_003ED718->unk_10 = arg0;
}

u32 func_00218C40(void) {
    return D_003ED718->unk_14;
}

s32 func_00218C50(void) {
    return func_00218C40();
}

void func_00218C68(s32 arg0) {
    D_003ED718->unk_14 = arg0;
}

u32 func_00218C78(void) {
    return D_003ED718->unk_18;
}

s32 func_00218C88(void) {
    return func_00218C78();
}

void func_00218CA0(s32 arg0) {
    D_003ED718->unk_18 = arg0;
}

INCLUDE_ASM("asm/nonmatchings/xpotato", func_00218CB0);

void func_00218D08(void) {
    D_003ED72C++;
    D_003ED728--;
}

void func_00218D38(void) {
    func_0011F9E8(0x3600, 4, 19, 0, 0, 138, 0x58, 759, D_003ED730, &D_0063CFA0);
    func_0011F9E8(0x3680, 1, 0, 0, 0, 16, 16, 64, D_003ED730 + 0x2F70, &D_0063D050);
}

INCLUDE_ASM("asm/nonmatchings/xpotato", func_00218DD0);

INCLUDE_ASM("asm/nonmatchings/xpotato", func_002190C0);

INCLUDE_ASM("asm/nonmatchings/xpotato", func_002192D8);

INCLUDE_ASM("asm/nonmatchings/xpotato", func_00219468);

INCLUDE_ASM("asm/nonmatchings/xpotato", func_002195F8);

INCLUDE_ASM("asm/nonmatchings/xpotato", func_00219788);
