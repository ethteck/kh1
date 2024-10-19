#include "common.h"
#include "xnoodle.h"

typedef struct {
    /* 0x00 */ char unk_00[0x11];
    /* 0x11 */ s8 unk_11;
    /* 0x12 */ char unk_12[0x12];
    /* 0x24 */ s32 unk_24;
} XSauce;

u_long128* D_002B7B70;
u_long128* D_002B7BB0;
u_long128* D_002B7BF0;
u_long128* D_002B7C30;
u_long128* D_002B7C70;
u_long128* D_002B7CB0;
u_long128* D_002B7CF0;
u_long128* D_002B7D30;
u_long128* D_002B7D70;
u_long128* D_002B7DB0;
u_long128* D_002B7DF0;
u_long128* D_002B7E30;
u_long128* D_002B7E70;
u_long128* D_002B7EB0;
u_long128* D_002B7EF0;
u_long128* D_002B7F30;
s32 D_002B7FF0;

s32 D_004CF574;
s32 D_004CF57C;

extern u_long128* func_00121C98(s32 arg0, u_long128** arg1);

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010C2D8);

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010C360);

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010C4B8);

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010C918);

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010CA30);

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010CAE0);

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010CBA0);

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010CBF8);

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010CC80);

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010CCD8);

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010CCF0);

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010CE98);

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010CF18);

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010D010);

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010D130);

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010D168);

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010D218);

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010D250);

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010E230);

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010E270);

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010E330);

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010E450);

void func_0010E580(void) {
    u_long128* imageAddrs[8];

    imageAddrs[0] = func_00121C98(0x40, imageAddrs);
    imageAddrs[1] = func_00121C98(0x40, imageAddrs + 1);
    imageAddrs[2] = func_00121C98(0x40, imageAddrs + 2);
    imageAddrs[3] = func_00121C98(0x40, imageAddrs + 3);
    imageAddrs[4] = func_00121C98(0x40, imageAddrs + 4);
    imageAddrs[5] = func_00121C98(0x40, imageAddrs + 5);
    imageAddrs[6] = func_00121C98(0x40, imageAddrs + 6);
    imageAddrs[7] = func_00121C98(0x40, imageAddrs + 7);

    func_0010E450(imageAddrs[0], imageAddrs[1], 0);
    func_0010E450(imageAddrs[2], imageAddrs[3], 1);
    func_0010E450(imageAddrs[4], imageAddrs[5], 2);
    func_0010E450(imageAddrs[6], imageAddrs[7], 3);

    func_0010C1D0(16364, imageAddrs[0]);
    func_0010C1D0(16365, imageAddrs[1]);
    func_0010C1D0(16366, imageAddrs[2]);
    func_0010C1D0(16367, imageAddrs[3]);
    func_0010C1D0(16368, imageAddrs[4]);
    func_0010C1D0(16369, imageAddrs[5]);
    func_0010C1D0(16370, imageAddrs[6]);
    func_0010C1D0(16371, imageAddrs[7]);

    sceGsSyncPath(0, 0);

    func_00121D50(imageAddrs[0]);
    func_00121D50(imageAddrs[1]);
    func_00121D50(imageAddrs[2]);
    func_00121D50(imageAddrs[3]);
    func_00121D50(imageAddrs[4]);
    func_00121D50(imageAddrs[5]);
    func_00121D50(imageAddrs[6]);
    func_00121D50(imageAddrs[7]);
}

void func_0010E700(void) {
    *(u16*)(func_0011ED30(180150, func_0010C248) + 2) = -1;

    func_0010C1D0(16348, &D_002B7B70);
    func_0010C1D0(16349, &D_002B7BB0);
    func_0010C1D0(16350, &D_002B7BF0);
    func_0010C1D0(16351, &D_002B7C30);
    func_0010C1D0(16352, &D_002B7C70);
    func_0010C1D0(16353, &D_002B7CB0);
    func_0010C1D0(16354, &D_002B7CF0);
    func_0010C1D0(16355, &D_002B7D30);
    func_0010C1D0(16356, &D_002B7D70);
    func_0010C1D0(16357, &D_002B7DB0);
    func_0010C1D0(16358, &D_002B7DF0);
    func_0010C1D0(16359, &D_002B7E30);
    func_0010C1D0(16360, &D_002B7E70);
    func_0010C1D0(16361, &D_002B7EB0);
    func_0010C1D0(16362, &D_002B7EF0);
    func_0010C1D0(16363, &D_002B7F30);
}

void func_0010E830(XSauce* arg0) {
    func_00106948(&D_002B7FF0);
    arg0->unk_11 = 1;
    func_0010E330(arg0);
}

void func_0010E868(XSauce* arg0) {
    func_00106948(&D_002B7FF0);
    arg0->unk_24 = 0;
    arg0->unk_11 = 0;
    func_0010E330(arg0);
}

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010E8A0);

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010E9A8);

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010EA38);

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010EB50);

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010EBE0);

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010ED10);

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010EDA0);

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010EDC0);

s32 func_0010EEC8(s32 arg0) {
    s32 stack[4];

    return func_0010EDC0(arg0, stack) / 24 + 1;
}

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010EF00);

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010F0A0);

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010F1C8);

void func_0010F380(void) {
    if (D_004CF574 != 0) {
        func_00121D50(D_004CF574);
    }
}

void func_0010F3B8(s32 arg0, s32 arg1) {
    *(s32*)(arg1 + 0xA8) = arg0; // todo: figure out what struct this is
    D_004CF574 = 0;
    D_004CF57C = 0;
}
