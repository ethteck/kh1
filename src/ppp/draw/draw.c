#include "common.h"
#include "ppp/draw.h"

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001A9280);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001A95B8);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001A9620);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001A96D0);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001A9C50);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AA7C0);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AA868);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AA940);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", KeThResHd_Init);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AA9C8);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AAA30);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AAB28);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AAC80);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AADB8);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AADC8);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AAF58);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AAF80);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AAFC0);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB0B0);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB0D8);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB0F0);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB108);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB120);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB138);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB150);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB168);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB180);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB198);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB208);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB270);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB2A0);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB320);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB348);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB380);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB3A8);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB3E0);

void func_001AB408(sceVu0FVECTOR arg0, sceVu0FVECTOR arg1) {
    sceVu0FVECTOR stack;

    sceVu0SubVector(stack, arg0, arg1);
    func_001AB3A8(stack);
}

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB438);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB470);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB4B8);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB828);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001ABA80);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001ABCC8);

void op_init_draw(void) {
    ops_init_draw_work();
    ops_init_spr();
}

void ops_init_draw_work(void) {
    oa_dmagif = sceDmaGetChan(SCE_DMA_GIF);
}

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", op_gs2_init);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", op_otz_init);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AC0A8);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AC120);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AC148);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AC180);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AC298);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AC430);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AC4C8);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AC4F0);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", op_ot_draw);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AC758);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AC7A8);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AC7F8);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AC848);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", op_init_fog_work);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AC978);

INCLUDE_RODATA("asm/nonmatchings/ppp/draw/draw", D_00489A60);
