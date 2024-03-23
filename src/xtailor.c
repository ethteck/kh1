#include "common.h"
#include "common_funcs.h"
#include "common_data.h"
#include "xtailor.h"
#include "xblade.h"

#include "libgraph.h"
#include "libvu0.h"
#include "sdk/libcdvd.h"

extern s32 D_002A30D0;
extern s32 D_002B8170;
extern s32 D_002B8240;
extern s32 D_002B8280;
extern sceVu0FMATRIX D_002B8370;
extern sceVu0FMATRIX D_002B83B0;
extern sceVu0FMATRIX D_002B83F0;
extern sceVu0FMATRIX D_002B8430;
extern sceVu0FMATRIX D_002B8470;
extern sceVu0FMATRIX D_002B84B0;
extern sceVu0FMATRIX D_002B84F0;
extern sceVu0FMATRIX D_002B8530;
extern sceVu0FMATRIX D_002B8570;
extern s32 D_002B85C0[4];
extern s32 D_002B8210;
extern s32 D_002B8678;
extern s32 D_002B8680;

extern s32 D_002B9030;
extern s32 D_002B9084;
extern f32 D_002B9090[4];
extern s32 D_002B90A0[3];

extern sceVu0FMATRIX D_002DEC60;

extern char D_00486C40[];
extern char D_00486C50[];
extern char D_00486C60[];

extern s32 D_004CF580;
extern s32 D_004CF588;
extern s32 D_004CF58C;
extern s32 D_004CF590;
extern s32 D_004D0590;
extern sceVu0FMATRIX D_004D2590;
extern sceVu0FMATRIX D_004D25D0;
extern sceGsDispEnv D_004D2610;
extern s32 D_004D284C;
extern sceVu0FMATRIX D_004D2850;
extern sceVu0FMATRIX D_004D2890;
extern sceVu0FMATRIX D_004D28D0;
extern sceVu0FMATRIX D_004D2910;
extern sceVu0FMATRIX D_004D2950;
extern s32 D_004D2990;
extern s32 D_004D2994;

extern s32 func_F20000();
void func_00110F88(s32);
s32 func_00120590(char*, void*, void*, void*);

void func_0010F3D0(void) {
    func_00106948(&D_002B8170);
    sceGsSyncPath(0, 0);
}

void func_0010F3F8(void) {
    func_00106948(&D_002B8240);
    sceGsSyncPath(0, 0);
}

void func_0010F420(void) {
    func_00106948(&D_002B8280);
    sceGsSyncPath(0, 0);
}

#define DISPWIDTH 640

void func_0010F448(void) {
    sceGsSyncPath(0, 0);
    DPUT_GS_PMODE(SCE_GS_SET_PMODE(1, 1, 0, 0, 0, 0, 0xFF));
    DPUT_GS_DISPFB1(SCE_GS_SET_DISPFB1(0xD8000 / 2048, 512 / 64, SCE_GS_PSMCT32, 0, 0));
    DPUT_GS_DISPLAY1(SCE_GS_SET_DISPLAY1(0, 160, 4, 0, (DISPWIDTH * 4) - 1, 128 - 1));
}

void func_0010F4A8(u32 arg0) {
    if ((D_002C1EB8.u8 >> 3 & 3) == 0) {
        if (arg0 == 0) {
            sceGsSyncPath(0, 0);
            func_001102C0();
            DPUT_GS_PMODE(0x22);
        } else {
            sceGsSyncPath(0, 0);
            func_001102C0();
            if (arg0 & 4) {
                func_0010F3D0();
                func_00106948(&D_002B8210);
                if (D_004CF58C == 0) {
                    func_001FD4C0(76, 11);
                    func_001F2EF8(0x64FFFFFF, 118, 16, func_001F0EF0(3), 15);
                    func_00207640(1, 351, 92, 90);
                } else {
                    func_001FD4C0(84, 30);
                    func_001F2EF8(0x64FFFFFF, 126, 39, func_001F0EF0(4), 15);
                    func_00207640(1, 351, 70, 90);
                }
                func_0010F3F8();
                func_00106948(&D_002B8210);
                func_0010F420();
                func_0010F448();
                return;
            }
            if (arg0 & 2) {
                func_0010F3D0();
                func_00106948(&D_002B8210);
                func_001FD4C0(104, 30);
                func_001F2EF8(0x64FFFFFF, 146, 39, func_001F0EF0(2), 15);
                func_0010F3F8();
                func_00106948(&D_002B8210);
                func_0010F420();
                func_0010F448();
                return;
            }
            if (arg0 & 1) {
                func_0010F3D0();
                func_00106948(&D_002B8210);
                func_001FD4C0(84, 30);
                func_001F2EF8(0x64FFFFFF, 126, 39, func_001F0EF0(1), 15);
                func_0010F3F8();
                func_00106948(&D_002B8210);
                func_0010F420();
                func_0010F448();
                return;
            }
        }
    }
}

void func_0010F6F0(void) {
    D_004CF580 = D_002C1EB8.s32;
}

void func_0010F708(void) {
    D_004CF588 = D_002C1EB8.s32;
}

void func_0010F720(u32 arg0) {
    func_0010F4A8(arg0);
    if (func_00110EA8() != 0) {
        func_00110F88(arg0);
    }
}

INCLUDE_ASM(const s32, "xtailor", func_0010F768);

INCLUDE_ASM(const s32, "xtailor", func_0010FA30);

void func_0010FA88(void) {
    void* src = func_00155ED8(0x34, 0xC);
    // s32 size = func_00120438("allset.set", src);
    s32 size = func_00120438(D_00486C40, src);
    memcpy(&D_004CF590, src, size);
    func_0010FA30(&D_004CF590);
}

void func_0010FAE8(void) {
    void* src = func_00155ED8(0x34, 0xC);
    // s32 size = func_00120438("allarea.nam", src);
    s32 size = func_00120438(D_00486C50, src);
    memcpy(&D_004D0590, src, size);
}

INCLUDE_ASM(const s32, "xtailor", func_0010FB38);
void* func_0010FB38(s32, s32);

void* func_0010FB68(void) {
    return func_0010FB38(D_002B8678, D_002B8680);
}

INCLUDE_ASM(const s32, "xtailor", func_0010FB90);

void func_0010FCD0(void) {
    D_004D2990 = 0;
}

void func_0010FCE0(void) {
    D_004D2990 = 1;
}

INCLUDE_ASM(const s32, "xtailor", func_0010FCF0);

void func_0010FD40(s16 w, s16 h) {
    D_004D284C = 0;
    sceGsSetDefDispEnv(&D_004D2610, 1, w, h, 0, 0);
    D_004D2610.dispfb.FBP &= 0xFFFFFE00;
    FlushCache(WRITEBACK_DCACHE);
    sceGsSyncPath(0, 0);
    sceGsPutDispEnv(&D_004D2610);
}

INCLUDE_ASM(const s32, "xtailor", func_0010FDB8);

void func_0010FE10(u32* x, u32* y) {
    *x = D_004D2610.display.DX;
    *y = D_004D2610.display.DY;
}

void func_0010FE38(void) {
    sceGsResetGraph(1, 1, 2, 0);
    DPUT_GS_EXTWRITE(0);
    sceGsPutDispEnv(&D_004D2610);
}

INCLUDE_ASM(const s32, "xtailor", func_0010FE78);

INCLUDE_ASM(const s32, "xtailor", func_0010FEC0);

INCLUDE_ASM(const s32, "xtailor", func_00110038);
s32 func_00110038(s32);

void func_00110150(void) {
    D_002B85C0[3] = 128;
    D_002B85C0[2] = 128;
    D_002B85C0[1] = 128;
    D_002B85C0[0] = 128;
}

void func_00110170(void) {
    D_002B85C0[3] = 0;
    D_002B85C0[2] = 0;
    D_002B85C0[1] = 0;
    D_002B85C0[0] = 0;
}

INCLUDE_ASM(const s32, "xtailor", func_00110190);

INCLUDE_ASM(const s32, "xtailor", func_00110230);

INCLUDE_ASM(const s32, "xtailor", func_00110240);

void func_001102A0(void) {
    sceGsSyncVCallback(func_00110038);
}

INCLUDE_ASM(const s32, "xtailor", func_001102C0);

INCLUDE_ASM(const s32, "xtailor", func_00110410);

INCLUDE_ASM(const s32, "xtailor", func_00110848);

void func_001109A8(void) {
    sceVu0CopyMatrix(D_004D2950, D_002B84F0);
    sceVu0MulMatrix(D_002B84F0, D_002B83B0, D_002DEC60);
    sceVu0MulMatrix(D_002B8530, D_002B8430, D_002DEC60);
    sceVu0MulMatrix(D_002B8570, D_002B8470, D_002DEC60);
}

void func_00110A30(void) {
    sceVu0CopyMatrix(D_002B8370, D_004D2590);
    sceVu0CopyMatrix(D_002B83B0, D_004D2850);
    sceVu0CopyMatrix(D_002B83F0, D_004D2890);
    sceVu0CopyMatrix(D_002B8430, D_004D28D0);
    sceVu0CopyMatrix(D_002B8470, D_004D2910);
    sceVu0CopyMatrix(D_002B84B0, D_004D25D0);
    sceVu0MulMatrix(D_002B84F0, D_002B83B0, D_002DEC60);
}

INCLUDE_ASM(const s32, "xtailor", func_00110AE0);

void func_00110C40(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    D_002B9090[0] = arg0;
    D_002B9090[1] = arg1;
    D_002B9090[2] = arg2;
    D_002B9090[3] = arg3;
    D_002B90A0[0] = 0;
    D_002B90A0[1] = 0;
    D_002B90A0[2] = 0;
}

INCLUDE_ASM(const s32, "xtailor", func_00110C70);

INCLUDE_ASM(const s32, "xtailor", func_00110DE0);
void func_00110DE0();

void func_00110E18(void) {
    D_002A30D0 = 0;
    D_002B9030 = 0;
    D_002B9084 = 0;
}

s32 func_00110E38(s32 arg0) {
    D_002B9030 = 0;
    D_004D2994 = arg0;
    return func_00120590(D_00486C60, &func_F20000, func_00110DE0, NULL);
}

INCLUDE_ASM(const s32, "xtailor", func_00110E78);

INCLUDE_ASM(const s32, "xtailor", func_00110EA8);

INCLUDE_ASM(const s32, "xtailor", func_00110ED8);

void func_00110EE8(void) {
    func_F20000(3, 0);
}

void func_00110F08(void) {
    func_F20000(8, 0);
}

void func_00110F28(void) {
    func_F20000(9, 0);
}

void func_00110F48(void) {
    func_F20000(4, 0);
}

void func_00110F68(void) {
    func_F20000(5, 0);
}

void func_00110F88(s32 arg0) {
    func_F20000(6, arg0);
}

void func_00110FA8(void) {
    func_F20000(7, 0);
}

INCLUDE_ASM(const s32, "xtailor", func_00110FC8);

void func_00111050(void) {
    sceCdRead(0, 0, NULL, NULL);
    func_00247CD8();
    sceCdStatus();
    sceCdBreak();
    sceCdGetError();
    sceIpuInit();
    sceIpuSync();
}
