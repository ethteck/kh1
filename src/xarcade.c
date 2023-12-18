#include "disk.h"
#include "io.h"
#include "libgraph.h"

typedef struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04;
} XArcade;

extern char D_002B29B0[]; // "host:./kingdom.cnf"
extern char* D_002B29C8;
extern s32 D_002B2CB0;
extern s32 D_002B2CC0;
extern s32 D_002B2CC4;
extern u_long128* D_002B2CC8;
extern u_long128* D_002B2CCC;
extern s32** D_002B8690;
extern s32** D_002B8694;
extern s32 D_002B85C0[4];
extern sceGsLoadImage D_002B8700;
extern s32 D_002B8870;
extern s32 D_002B8C70;
extern s32 D_002B8C8C;
extern s32* D_002DEC60;
extern s32* D_002DECA0;

extern s32 D_00358BE0;

extern char D_004869E0[]; // "host:./kingdom.log"
extern char D_004869F8[]; // "kingdom.img"
extern s32 D_0048EBE0;
extern f32 D_0048EBE4;
extern f32 D_0048EBFC;
extern XArcade D_0048EC00;
extern s32 D_0048EC08;

extern void func_F20000(s32, s32);
extern void func_00100240(); // in xbeginning
extern void func_00110230(s32);
extern void func_0011EDD0(s32*, s32*, s32, s32);
extern u_long128* func_00121C98(s32, u_long128**);
extern void func_00122518();
extern s32* func_00155ED8(s32, s32);
extern void func_001600B8();
extern void func_001C20B8();
extern void func_00233968();
extern void func_00248530();

void func_001090D8() {
    KingdomFile* file;

    func_0010FEC0();
    func_001102A0();
    func_0010C010();
    func_001EF810();
    func_0022F578(-1);
    func_0011EAF8(D_002B29B0, D_004869E0);

    file = cdvd_FindFile(D_004869F8);
    if (file != NULL) {
        disk_Mgr.unk_18(file->length);
    } else {
        disk_Mgr.unk_18(0);
    }
    D_002B29C8 = disk_Mgr.unk_1C();
    func_00110230(0);
    D_002B8C8C = 0;
    func_001ED888(NULL);
    func_0011F7C0();
}

s32 func_001091B0() {
    func_0011EF58(&D_002B8C70, 0);
    return 0;
}

INCLUDE_ASM(const s32, "xarcade", func_001091D8);

s32 func_00109340() {
    func_00110190();
    func_00176E30();
    func_00176E98();
    D_00358BE0 = 1;
    func_0011EDD0(&D_002B8C70, &D_002B8870, 0x20, 0x20);
    return func_0011ED30(0x2E662, func_001091B0);
}

INCLUDE_ASM(const s32, "xarcade", func_001093A8);

void func_001093D8() {
    func_00122518();
    func_001600B8();
    func_00100240();
    func_001C20B8();
    func_00233968();
    func_00248530();
    D_002B8690 = &D_002DEC60;
    D_002B8694 = &D_002DECA0;
}

void func_00109440() {
    FlushCache(INVALIDATE_ICACHE);
    func_F20000(0, 0);
}

INCLUDE_ASM(const s32, "xarcade", func_00109468);

INCLUDE_ASM(const s32, "xarcade", func_00109580);

INCLUDE_ASM(const s32, "xarcade", func_001099D8);

s32 func_00109AA0() {
    sceGsStoreImage img;

    sceGsSetDefStoreImage(&img, 0x1A00, 8, 1, 0, 0, 0x200, 0x180);
    FlushCache(WRITEBACK_DCACHE);
    sceGsSyncPath(0, 0);
    sceGsExecStoreImage(&img, func_F20000);
    return 4;
}

s32 func_00109B00() {
    return func_0011ED30(190000, func_00109AA0);
}

INCLUDE_ASM(const s32, "xarcade", func_00109B28);
void func_00109B28();

s32 func_00109C50(s32 arg0) {
    D_0048EC00.unk_04 = arg0 << 1;
    D_0048EC08 = 0;
    return func_0011ED30(190000, func_00109B28);
}

INCLUDE_ASM(const s32, "xarcade", func_00109C98);

s32 func_00109D68() {
    sceGsStoreImage img;

    sceGsSetDefStoreImage(&img, 0x1A00, 8, 1, 0, 0, 0x200, 0x180);
    FlushCache(WRITEBACK_DCACHE);
    sceGsSyncPath(0, 0);
    D_002B2CCC = func_00155ED8(62, 2);
    sceGsExecStoreImage(&img, D_002B2CCC);
    return 4;
}

s32 func_00109DE8() {
    D_002B2CC4 = 1;
    if (D_002B85C0[0] != 0x80) {
        func_001037C8(1);
    }
    return func_0011ED30(190000, func_00109D68);
}

INCLUDE_ASM(const s32, "xarcade", func_00109E30);
void func_00109E30();

INCLUDE_ASM(const s32, "xarcade", func_00109F60);
s32 func_00109F60();

s32 func_0010A040() {
    D_0048EC00.unk_00 = 0;
    if (D_002B2CC0 != 0) {
        return func_0011ED30(190000, func_00109F60);
    }
    return func_0011ED30(190000, func_00109E30);
}

INCLUDE_ASM(const s32, "xarcade", func_0010A098);
void func_0010A098();

s32 func_0010A0E0() {
    return func_0011ED30(190000, func_0010A098);
}

void func_0010A108() {
    sceGsStoreImage img;

    func_00106948(&D_002B2CB0);
    sceGsSetDefStoreImage(&img, 0x3600, 4, 1, 0, 0, 0x100, 0xC0);
    FlushCache(WRITEBACK_DCACHE);
    sceGsSyncPath(0, 0);
    D_002B2CC8 = func_00121C98(0x24000, &D_002B2CC8);
    sceGsExecStoreImage(&img, D_002B2CC8);
}

void func_0010A190() {
    sceGsSetDefLoadImage(&D_002B8700, 0x3600, 4, 1, 0, 0, 0x100, 0xC0);
    FlushCache(WRITEBACK_DCACHE);
    sceGsSyncPath(0, 0);
    sceGsExecLoadImage(&D_002B8700, D_002B2CC8);
}
