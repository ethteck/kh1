#include "common.h"
#include "sifdev.h"
#include "ppp/draw.h"

void opc(void) {
}

void opc2(void) {
}

void opc3(void) {
}

void op_init_global(void) {
}

void ops_init_spr(void) {
    spr_a[0] = 0x70000000;
    spr_rev_a[0] = 0x70004000;
    spr_index = 0;
    spr_rev_index = 0;
}

void op_num_info(void) {
}

INCLUDE_ASM("asm/nonmatchings/ppp/draw/global", op_spr_alloc);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/global", op_spr_rev_alloc);

// todo: next two are being compiled as unsigned despite data entries being signed
INCLUDE_ASM("asm/nonmatchings/ppp/draw/global", op_spr_free);
// void op_spr_free(void) {
//     spr_index--;
// }

INCLUDE_ASM("asm/nonmatchings/ppp/draw/global", op_spr_rev_free);
// void op_spr_rev_free(void) {
//     spr_rev_index--;
// }

s32 op_spr_rev_check(s32 arg0) {
    if ((s32)spr_a + arg0 <= spr_rev_a[spr_rev_index + 1]) {
        return 0;
    }
    return -1;
}

s32 op_spr_check(s32 arg0) {
    if (spr_a[spr_index + 1] <= (s32)spr_rev_a - arg0) {
        return 0;
    }
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/ppp/draw/global", op_file_read);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/global", op_file_size);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/global", op_oef2_set);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/global", op_oef2_set2);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/global", op_oef2_set2_16);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/global", op_oef2_a_get);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/global", op_random);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/global", op_random_p);
