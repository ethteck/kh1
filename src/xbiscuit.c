#include "common.h"
#include "libdma.h"

extern s32 D_003DEF90;
extern s32 D_003E0810;
extern s32 D_003E2BE0;
extern s32 D_003E3080;
extern s32 D_003E3084;
extern s32* D_003E30A8;
extern s32 D_003E30AC;
extern s32 D_003E38C0;
extern s32 D_003EB8C0;

char D_0048A590[32]; // "menu/sysfont.bin"

extern s32 D_00639A80;
extern s32* D_00639A84;
extern s32* D_00639A88;
extern s32 D_00639A8C;
extern void* D_0063B050;

void func_001F0DF8(s32*, s32*);
void* func_001F1960(s32, s32, s32, s32, s32, s32, s32, s32);
void* func_001F19F0(s32, s32, s32, s32, s32, s32, s32, s32);
void* func_001F1FA8(s32, s32, s32, s32, s32, s32, s32, s32);

void func_001F0C30(void) {
    void* dst;
    u64 stack0[22];
    u64 stack1[22];

    dst = func_00155ED8(0x34, 12);

    func_00120438(D_0048A590, dst);

    func_0011F9E8(0x3FFC, 1, 0, 0, 0, 0x10, 0x10, 0x40, dst + 0x10000, stack1);
    FlushCache(0);
    sceDmaSend(sceDmaGetChan(SCE_DMA_GIF), stack1);
    sceGsSyncPath(0, 0);

    func_0011F9E8(0x1000, 4, 36, 0, 0, 0x100, 0x100, 0x800, dst, stack0);
    FlushCache(0);
    sceDmaSend(sceDmaGetChan(SCE_DMA_GIF), stack0);
    sceGsSyncPath(0, 0);

    func_0011F9E8(0x1000, 4, 44, 0, 0, 0x100, 0x100, 0x800, dst + 0x8000, stack0);
    FlushCache(0);
    sceDmaSend(sceDmaGetChan(SCE_DMA_GIF), stack0);
    sceGsSyncPath(0, 0);
}

// Nonmatch: Assignment instructions out of order
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F0D88);
// void func_001F0D88(void) {
//     D_003E30A8 = &D_003DEF90;
//     D_003E30AC = 0x310;
//     func_001F0E38(20);
//     func_001F0E58(8);
//     func_001F0E58(0);
//     func_001F0DD0();
// }

void func_001F0DD0(void) {
    func_001F0DF8(&D_003E0810, &D_003E2BE0);
}

void func_001F0DF8(s32* arg0, s32* arg1) {
    D_00639A84 = arg0;
    D_00639A88 = arg1;
}

INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F0E10);

void func_001F0E38(s32 arg0) {
    D_00639A80 = arg0 << 4;
}

s32 func_001F0E48(void) {
    return D_00639A80 >> 4;
}

INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F0E58);

s32 func_001F0E68(void) {
    return D_003E3080;
}

void func_001F0E78(s32 arg0) {
    D_003E3084 = arg0;
}

s32 func_001F0E88(void) {
    return D_003E3084;
}

INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F0E98);

s32 func_001F0EC0(s32 arg0, s32 arg1) {
    s32 val = func_001F0E98(arg0);
    return func_001F0FF8(val, arg1);
}

INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F0EF0);

s32 func_001F0F10(s32 arg0, s32 arg1) {
    s32 val = func_001F0EF0(arg0);
    return func_001F0FF8(val, arg1);
}

INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F0F40);

s32 func_001F0F58(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 val = func_001F0F40(arg0, arg1, arg2);
    return func_001F0FF8(val, arg3);
}

INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F0F88);

INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F0FB0);

INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F0FF8);

s32 func_001F1070(s32 arg0) {
    s32 val = func_001F0E98(arg0);
    return func_001F1090(val);
}

INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F1090);

s32 func_001F1140(s32 arg0) {
    return func_001F1070(arg0) + 1;
}

s32 func_001F1160(s32 arg0) {
    return func_001F1090(arg0) + 1;
}

s32 func_001F1180(s32 arg0) {
    s32 val = func_001F0E98(arg0);
    return func_001F11C0(val);
}

s32 func_001F11A0(s32 arg0, s32 arg1, s32 arg2) {
    s32 val = func_001F0F40(arg0, arg1, arg2);
    return func_001F11C0(val);
}

INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F11C0);

INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F1228);

s32 func_001F1278(s32 arg0) {
    return func_001F12C0(arg0, 18);
}

s32 func_001F1290(s32 arg0) {
    return func_001F12F0(arg0, 18);
}

s32 func_001F12A8(s32 arg0) {
    return func_001F14F0(arg0, 18);
}

s32 func_001F12C0(s32 arg0, s32 arg1) {
    s32 val = func_001F0E98(arg0);
    return func_001F12F0(val, arg1);
}

INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F12F0);

INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F14F0);

INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F15F0);

INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F1770);

INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F1788);

void* func_001F17C0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    return func_001F19F0(arg0, arg1, 0, arg2, arg3, arg4, arg5, 14);
}

void* func_001F17F8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    return func_001F1960(arg0, arg1, 0, arg2, arg3, arg4, arg5, 18);
}

void* func_001F1830(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    return func_001F19F0(arg0, arg1, 0, arg2, arg3, arg4, arg5, 18);
}

void* func_001F1868(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    return func_001F1FA8(arg0, arg1, 0, arg2, arg3, arg4, arg5, 18);
}

void* func_001F18A0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    return func_001F1960(arg0, arg1, 0, arg2, arg3, arg4, arg5, arg6);
}

void* func_001F18E0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    return func_001F19F0(arg0, arg1, 0, arg2, arg3, arg4, arg5, arg6);
}

void* func_001F1920(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    return func_001F1FA8(arg0, arg1, 0, arg2, arg3, arg4, arg5, arg6);
}

void* func_001F1960(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    s32 val = func_001F0E98(arg6);
    return func_001F19F0(arg0, arg1, arg2, arg3, arg4, arg5, val, arg7);
}

INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F19F0);

INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F1FA8);

INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F2378);

void* func_001F2670(s32, s32, s32, s32, s32, s32, s32);
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F2670);

void* func_001F2888(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 val = func_001F1228(arg5);
    return func_001F2670(arg0, arg1, arg2, arg3, arg4, val, arg6);
}

INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F2908);

s32 func_001F2DD8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_001F2F88(0, arg0, arg1, arg2, arg3, 14);
    return D_00639A8C;
}

s32 func_001F2E20(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_001F30A0(0, arg0, arg1, arg2, arg3, 14);
    return D_00639A8C;
}

s32 func_001F2E68(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_001F31B8(0, arg0, arg1, arg2, arg3, 14);
    return D_00639A8C;
}

s32 func_001F2EB0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_001F2F88(0, arg0, arg1, arg2, arg3, arg4);
    return D_00639A8C;
}

s32 func_001F2EF8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_001F30A0(0, arg0, arg1, arg2, arg3, arg4);
    return D_00639A8C;
}

s32 func_001F2F40(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_001F31B8(0, arg0, arg1, arg2, arg3, arg4);
    return D_00639A8C;
}

INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F2F88);

INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F30A0);

INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F31B8);

INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F32D0);

INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F33D8);

INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F34E0);

INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F35E8);

void func_001F3718(s32** arg0, s32** arg1) {
    *arg0 = &D_003E38C0;
    *arg1 = &D_003EB8C0;
}

INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F3738);
