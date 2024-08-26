#include "common.h"
#include "libdma.h"

extern s32 D_0051C6C4;

typedef struct {
    /* 0x00 */ char unk_00[0x10];
    /* 0x10 */ void* unk_10;
} XCream;

s32 func_001274C0(XCream* arg0) {
    sceDmaSend(sceDmaGetChan(SCE_DMA_GIF), arg0->unk_10);
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xcream", func_001274F8);

INCLUDE_ASM("asm/nonmatchings/xcream", func_00127560);

INCLUDE_ASM("asm/nonmatchings/xcream", func_00127960);

INCLUDE_ASM("asm/nonmatchings/xcream", func_00127B18);

INCLUDE_ASM("asm/nonmatchings/xcream", func_00127B98);

INCLUDE_ASM("asm/nonmatchings/xcream", func_00127C20);

INCLUDE_ASM("asm/nonmatchings/xcream", func_00128250);

INCLUDE_ASM("asm/nonmatchings/xcream", func_00128488);

INCLUDE_ASM("asm/nonmatchings/xcream", func_001284E8);

INCLUDE_ASM("asm/nonmatchings/xcream", func_00128780);

INCLUDE_ASM("asm/nonmatchings/xcream", func_00128B68);

INCLUDE_ASM("asm/nonmatchings/xcream", func_00128CA8);

INCLUDE_ASM("asm/nonmatchings/xcream", func_00128D10);

void func_00128D40(s32* arg0) {
    func_0012B850(*arg0);
}

INCLUDE_ASM("asm/nonmatchings/xcream", func_00128D58);

void func_00128DA0(void) {
    func_0012B850(D_0051C6C4);
}

INCLUDE_ASM("asm/nonmatchings/xcream", func_00128DC0);

INCLUDE_ASM("asm/nonmatchings/xcream", func_00128DF8);

void func_00128E18(void) {
}

void func_00128E20(void) {
}
