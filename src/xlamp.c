#include "common.h"
#include "libpc.h"
#include "eekernel.h"
#include "libgraph.h"

extern void* D_002C219C;

extern s32 D_0034DF90; // also used in 4A098 split

// .bss
s32 D_004F0508;
s32 D_004F050C;
s32 D_004F8530;
s32 D_004FA560;
s32 D_004FA668;

extern void* func_0011EEB8(); //  todo: conflicting signatures already used, figure out correct one

void* func_00121DE0(s32 arg0, s32 arg1) {
    return func_0011EEB8(D_004FA560, arg0, arg1);
}

INCLUDE_ASM("asm/nonmatchings/xlamp", func_00121E08);

INCLUDE_ASM("asm/nonmatchings/xlamp", func_00121EC8);

s32 func_00121FB8(s32 unused) {
    iDisableDmac(DMAC_VIF1);
    iDisableDmac(DMAC_GIF);
    D_002C219C = iFlushCache;

    if (func_00121EC8() != 0) {
        iEnableDmac(DMAC_VIF1);
        iEnableDmac(DMAC_GIF);
    }

    D_002C219C = FlushCache;
    ExitHandler();
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/xlamp", func_00122030);

INCLUDE_ASM("asm/nonmatchings/xlamp", func_00122110);

void* func_00122228(s32 arg0, s32 arg1) {
    return func_0011EEB8(D_004F8530, arg0, arg1);
}

INCLUDE_ASM("asm/nonmatchings/xlamp", func_00122250);

void func_001222B0(void) {
    DisableDmac(DMAC_VIF1);
    DisableDmac(DMAC_GIF);
    D_004F0508 = AddDmacHandler(DMAC_VIF1, func_00121FB8, 0);
    D_004F050C = AddDmacHandler(DMAC_GIF, func_00121FB8, 0);
}

void func_00122318(void) {
    DisableDmac(DMAC_VIF1);
    DisableDmac(DMAC_GIF);
    RemoveDmacHandler(DMAC_VIF1, D_004F0508);
    RemoveDmacHandler(DMAC_GIF, D_004F050C);
}

INCLUDE_ASM("asm/nonmatchings/xlamp", func_00122358);

INCLUDE_ASM("asm/nonmatchings/xlamp", func_001223B0);

INCLUDE_ASM("asm/nonmatchings/xlamp", func_00122410);

INCLUDE_ASM("asm/nonmatchings/xlamp", func_00122430);

void func_001224A0(void) {
    D_004FA668 -= 8;
}

void func_001224B8(void) {
    scePcStop();
}

void func_001224D0(void) {
    func_00148FD0();
    func_00147B28();
    func_0013F248();
    func_00127310();
    func_0014FAC0();
    func_00151F20();
    func_00132D48();
}

void func_00122518(void) {
    D_002C1EA8 = 0;
    func_0013CE18();
    func_001255F8();
    func_00124F38();
    func_00128B68();
    func_001334A8();
    func_00149078();
    func_00142260();
    func_00142578();
    func_001582E8();
    func_001566E0();
    func_0014A248();
    func_0012FE80();
}

INCLUDE_ASM("asm/nonmatchings/xlamp", func_00122588);

void func_00122720(void) {
    func_00235EE0();
    func_00178140(0);
    func_0013BCA8(); // in xapple
    func_0014C498();
    func_00124CD8();
    func_0012FB18();
    func_00180358();
    func_0017F2B0();
    func_001421D8();
    func_001333A0();
    func_001467A8();
    func_00151B88();
    func_001777E0();
    func_001697B8();
    D_0034DF90 = 6;
    func_00157A18();
}

void func_001227B0(void) {
    func_00178140(0);
    func_0013BCA8(); // in xapple
    func_0015A5D0();
    func_00124DD0();
    func_001333A0();
    func_00146830();
    func_00149008();
    func_0012B5D8();
    func_00123020();
    func_0014C450();
    func_001355B8();
    func_0012FB50();
    func_00170A28();
}
