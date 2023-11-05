#include "xtango.h"

extern u32 D_003DE6A0;
extern s32 D_003E3088;
extern s32 D_003ED728;
extern s32 D_003ED72C;

extern u32 D_0063CF88;

// Nonmatch: bnez should be bnezl
INCLUDE_ASM(const s32, "xpotato", func_00215A88);
// void func_00215A88() {
//     int i;

//     for (i = 0; i < 10; i++) {
//         D_003ED718->unk_20[i] = 4;
//         func_00215AF0(i, 4);
//     }
// }

INCLUDE_ASM(const s32, "xpotato", func_00215AF0);

INCLUDE_ASM(const s32, "xpotato", func_00215B88);

INCLUDE_ASM(const s32, "xpotato", func_00215C48);

INCLUDE_ASM(const s32, "xpotato", func_00215CE8);

INCLUDE_ASM(const s32, "xpotato", func_00215EE8);

INCLUDE_ASM(const s32, "xpotato", func_00215F48);

INCLUDE_ASM(const s32, "xpotato", func_00216198);

s32 func_00216758(XWhiskey* arg0) {
    func_001F9B50(23);
    return func_001F9F78(arg0, 0, 174, 12, arg0->munny, 17, 0x80c87850);
}

INCLUDE_ASM(const s32, "xpotato", func_002167A0);

INCLUDE_ASM(const s32, "xpotato", func_002168F8);

INCLUDE_ASM(const s32, "xpotato", func_00216D88);

INCLUDE_ASM(const s32, "xpotato", func_00217038);

INCLUDE_ASM(const s32, "xpotato", func_002170B0);

INCLUDE_ASM(const s32, "xpotato", func_00217420);

s32 func_00217810(s32 arg0) {
    return func_00207728(arg0, 4, 2, 0, 0, 122, 117);
}

INCLUDE_ASM(const s32, "xpotato", func_00217840);

INCLUDE_ASM(const s32, "xpotato", func_00217898);

INCLUDE_ASM(const s32, "xpotato", func_002178D0);

INCLUDE_ASM(const s32, "xpotato", func_00217908);

INCLUDE_ASM(const s32, "xpotato", func_00217B00);

INCLUDE_ASM(const s32, "xpotato", func_00218648);

INCLUDE_ASM(const s32, "xpotato", func_002186B8);

s32 func_00218840(s32 arg0) {
    return func_00207728(arg0, 4, 2, 0, 0, 122, 118);
}

INCLUDE_ASM(const s32, "xpotato", func_00218870);

INCLUDE_ASM(const s32, "xpotato", func_002189D0);
// void func_002189D0() {
//     if (D_003DE6A0 - 1 < D_0063CF88) {
//         D_0063CF88 = D_003DE6A0 - 1;
//     }
// }

void func_00218A00() {
    D_0063CF88 = 0;
}

void func_00218A10() {
    D_003ED718->unk_00 = 0;
    D_003ED718->unk_08 = 0;
    D_003ED718->unk_04 = 0;
    D_003ED718->unk_0C = 0;
    D_003ED718->unk_10 = 0;
    D_003ED718->unk_14 = 0;
    D_003ED718->unk_18 = 0;
}

INCLUDE_ASM(const s32, "xpotato", func_00218A38);

INCLUDE_ASM(const s32, "xpotato", func_00218AC0);

u32 func_00218B48() {
    return D_003ED718->unk_00;
}

u32 func_00218B58() {
    return func_00218B48();
}

void func_00218B70(s32 arg0) {
    D_003ED718->unk_00 = arg0;
}

u32 func_00218B80() {
    return D_003ED718->unk_04;
}

u32 func_00218B90() {
    return func_00218B80();
}

u32 func_00218BA8(u32 arg0) {
    D_003ED718->unk_04 = arg0;
}

s32 func_00218BB8() {
    return D_003ED718->unk_08;
}

u32 func_00218BC8() {
    return func_00218BB8();
}

void func_00218BE0(s32 arg0) {
    D_003ED718->unk_08 = arg0;
}

u32 func_00218BF0() {
    return 0;
}

u32 func_00218BF8() {
    return 0;
}

void func_00218C00(void) {
}

u32 func_00218C08() {
    return D_003ED718->unk_10;
}

s32 func_00218C18() {
    return func_00218C08();
}

void func_00218C30(s32 arg0) {
    D_003ED718->unk_10 = arg0;
}

u32 func_00218C40() {
    return D_003ED718->unk_14;
}

s32 func_00218C50() {
    return func_00218C40();
}

void func_00218C68(s32 arg0) {
    D_003ED718->unk_14 = arg0;
}

u32 func_00218C78() {
    return D_003ED718->unk_18;
}

s32 func_00218C88() {
    return func_00218C78();
}

void func_00218CA0(s32 arg0) {
    D_003ED718->unk_18 = arg0;
}

INCLUDE_ASM(const s32, "xpotato", func_00218CB0);

void func_00218D08() {
    D_003ED72C++;
    D_003ED728--;
}

INCLUDE_ASM(const s32, "xpotato", func_00218D38);

INCLUDE_ASM(const s32, "xpotato", func_00218DD0);

INCLUDE_ASM(const s32, "xpotato", func_002190C0);

INCLUDE_ASM(const s32, "xpotato", func_002192D8);

INCLUDE_ASM(const s32, "xpotato", func_00219468);

INCLUDE_ASM(const s32, "xpotato", func_002195F8);

INCLUDE_ASM(const s32, "xpotato", func_00219788);
