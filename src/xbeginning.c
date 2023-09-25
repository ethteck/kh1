#include "common.h"

#include "eekernel.h"
#include "libdma.h"
#include "libgraph.h"

typedef struct XInchWorm {
    /* 0x00 */ char unk_00[0x44];
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ char unk_48[0x38];
} XInchWorm;

extern UNK_TYPE D_00297740;
extern XInchWorm D_00297850;
extern s32 D_002A0514;
extern s32 D_002A2740;
extern f32 D_002A274C;
extern sceDmaChan* D_002A30D4;
extern s32 D_002B29C4;
extern s32 D_002B2CC0;
extern s32 D_002B80F0;
extern u32 D_002B85F8;
extern s32* D_002B8690;
extern s32* D_002B8694;
extern sceGsLoadImage D_002B8700;
extern s32 D_002B8C84;
extern s32 D_002B8C88;
extern s32 D_002B8C90;
extern s32 D_002B8C94;
extern s32 D_002B9040;
extern s32 D_002B92F8;
extern s32 D_002B9310;
extern s32 D_002B9314;
extern s32 D_002B9328;
extern s32 D_002B932C;
extern s32 D_002BD854;

extern s32 D_00375BC0;

extern UNK_TYPE D_0048DC50;
extern UNK_TYPE D_0048DC90;
extern UNK_TYPE D_0048DCD0;
extern UNK_TYPE D_0048DD10;
extern UNK_TYPE D_0048DD50;
extern XInchWorm D_0048DDA0[];

s32 func_00100328(void);
void func_00100460(s32, UNK_TYPE*); // in-file, maybe handwritten
void func_001004F0(void);
void func_001006C8(void);
void func_001006F8(void);
void func_001007E0(void);
void func_00100880(void);

void func_00101560(void);
void func_00101E18(void);
void func_00102950(void);
void func_00103130(void);
void func_001036F0(void);
void func_00104110(void);
void func_001043A0(s32, XInchWorm*);
void func_001043E0(XInchWorm*);
void func_00106718(void);
void func_00106728(void);
void func_00106A08(UNK_TYPE*, s32);
void func_00106AA8(void);
void func_00107CF8(XInchWorm*);
void func_00108D68(s32, s32, XInchWorm*);
void func_0010BE10(void);
void func_0010E700(void);
void func_001116A8(void);
int func_00111910(void);
void func_001139F8(void);
void func_00113CA8(void);
void func_00114440(void);
void func_00114800(void);
void func_00114A50(void);
s32 func_0011C6C8(s32);
void func_0011E350(void);
void func_0011E360(void);
s32 func_0011E418(void);
s32 func_0011ED30(s32, UNK_FUN_PTR(arg1));
void func_00177708(void);
void func_00177748(void);
void func_00177768(void);
void func_001777A8(void);

s32 func_001000E8(void) {
    sceGsSyncPath(0, 0);
    func_00106AA8();
    return 0;
}

INCLUDE_ASM(const s32, "xbeginning", func_00100118);
void func_00100118(void);

void func_00100168(void) {
    s32 new_var;

    D_002A30D4 = sceDmaGetChan(SCE_DMA_GIF);
    D_002B2CC0 = 0;
    func_00106718();
    func_00106728();
    D_002B29C4 = 0;
    D_00375BC0 &= ~1;
    D_002B92F8 = 0;
    D_002A0514 = 0;
    D_002B8C90 = 0;

    new_var = 0;
    do {
        D_002B8C94 = 0;
    } while (new_var); // TODO improve

    func_00113CA8();
    func_001139F8();
    func_00114440();
    func_00111910();
    D_002B932C = 0;
    D_002B9328 = 0;
    func_00101560();
    D_002B85F8 &= ~0x2;
    D_002B8690 = &D_002B9040;
    D_002B8694 = &D_002B9040;
}

#ifdef NON_MATCHING
extern s32 func_00103928;
extern s32 func_00112690;
extern s32 func_00119E18;

void func_00100240(void) {
    D_002BD854 = 0;
    func_0011C6C8(0);
    func_001116A8();
    D_002B80F0 = 0;
    func_0011ED30(10499, &func_00119E18);
    func_0011ED30(164003, &func_00103928);
    func_00100118();
    func_0011E350();
    D_002B9314 = 0;
    D_002B85F8 &= ~2;
    func_0011E418();
    D_002B9310 = 0;
    func_0010E700();
    func_0010BE10();
    func_0011ED30(50000, &func_00112690);
    func_001004F0();
    func_00114A50();
    func_0011ED30(120000, &func_00100328);
    D_002A274C = 0.050000001f;
}
#else
INCLUDE_ASM(const s32, "xbeginning", func_00100240);
#endif

s32 func_00100328(void) {
    s32 temp_16;
    s32 temp_3;

    D_002B8C94 = D_002B8C90;
    D_002B8C90 = D_00375BC0 & 1;
    func_00114800();
    temp_16 = (D_002B85F8 >> 1) & 1;
    if (temp_16 == 1) {
        func_001006C8();
        temp_3 = D_002B85F8 & 1;
        if (temp_3 == temp_16) {
            if (((D_002B85F8 >> 3) & 1) == temp_3) {
                func_001006F8();
                func_001007E0();
            }
            func_00100880();
            func_00101E18();
            func_00102950();
        }
    }
    if (D_002A2740 != 0) {
        func_00103130();
    }
    if (D_002B8C84 != 0) {
        func_001036F0();
    }
    if (D_002B8C88 != 0) {
        func_00104110();
    }
    func_0011E360();
    return 0;
}

INCLUDE_ASM(const s32, "xbeginning", main);

void func_001004F0() {
    func_00100460(0, &D_0048DC50);
    func_00100460(1, &D_0048DC90);
    func_00100460(3, &D_0048DCD0);
    func_00100460(6, &D_0048DD10);
    func_00100460(7, &D_0048DD50);
}

INCLUDE_ASM(const s32, "xbeginning", func_00100550);

void func_00100648(void) {
    func_001043A0(-1, &D_00297850);
    func_001043A0(-1, &D_0048DDA0[0]);
    D_0048DDA0[0].unk_44 = 0.0f;
}

void func_00100690(void) {
    func_001043A0(-1, &D_0048DDA0[1]);
    D_0048DDA0[1].unk_44 = 0.0f;
}

void func_001006C8(void) {
    func_001043E0(&D_00297850);
    func_00107CF8(&D_00297850);
}

void func_001006F8(void);
INCLUDE_ASM(const s32, "xbeginning", func_001006F8);

void func_001007D0(f32 arg0) {
    D_0048DDA0[1].unk_44 = arg0;
}

void func_001007E0(void) {
    func_00106A08(&D_00297740, 10010);
    func_001043E0(&D_0048DDA0[0]);
    func_00108D68(0, 10010, &D_0048DDA0[0]);
    if (((D_002B85F8 >> 5) % 2) == 1) {
        func_001043E0(&D_0048DDA0[1]);
        func_00108D68(1, 10010, &D_0048DDA0[1]);
    }
}

void func_00100880(void);
INCLUDE_ASM(const s32, "xbeginning", func_00100880);

void func_001009A8(void) {
    D_002B85F8 |= 1;
    D_002B85F8 |= 2;
    func_00177768();
    func_001777A8();
}

void func_001009D8(void) {
    D_002B85F8 &= ~1;
    D_002B85F8 &= ~2;
    func_00177708();
    func_00177748();
}

INCLUDE_ASM(const s32, "xbeginning", func_00100A10);

INCLUDE_ASM(const s32, "xbeginning", func_00100B30);

void func_00100C18(u_long128* srcaddr, s16 dbp) {
    sceGsSetDefLoadImage(&D_002B8700, dbp, 1, 0, 0, 0, 8, 2);
    FlushCache(WRITEBACK_DCACHE);
    sceGsExecLoadImage(&D_002B8700, srcaddr);
    sceGsSyncPath(0, 0);
}

void func_00100C90(u_long128* srcaddr, s16 dbp) {
    sceGsSetDefLoadImage(&D_002B8700, dbp, 1, 0, 0, 0, 16, 16);
    FlushCache(WRITEBACK_DCACHE);
    sceGsExecLoadImage(&D_002B8700, srcaddr);
    sceGsSyncPath(0, 0);
}

void func_00100D08(u_long128* srcaddr, s16 dbp) {
    sceGsSetDefLoadImage(&D_002B8700, dbp, 8, 20, 0, 0, 512, 256);
    FlushCache(WRITEBACK_DCACHE);
    sceGsExecLoadImage(&D_002B8700, srcaddr);
    sceGsSyncPath(0, 0);
}

void func_00100D80(u_long128* srcaddr, s16 dbp) {
    sceGsSetDefLoadImage(&D_002B8700, dbp, 4, 19, 0, 0, 256, 256);
    FlushCache(WRITEBACK_DCACHE);
    sceGsExecLoadImage(&D_002B8700, srcaddr);
    sceGsSyncPath(0, 0);
}

void func_00100DF8(u_long128* srcaddr, s16 dbp) {
    sceGsSetDefLoadImage(&D_002B8700, dbp, 4, 27, 0, 0, 256, 1024);
    FlushCache(WRITEBACK_DCACHE);
    sceGsExecLoadImage(&D_002B8700, srcaddr);
    sceGsSyncPath(0, 0);
}

INCLUDE_ASM(const s32, "xbeginning", func_00100E70);

INCLUDE_ASM(const s32, "xbeginning", func_00100F48);
extern void func_00100F48();

void func_001011B8(void) {
    func_0011ED30(190000, &func_00100F48);
}
