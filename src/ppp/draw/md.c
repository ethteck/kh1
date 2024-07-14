#include "common.h"
#include "ppp/draw.h"
#include "libgraph.h"

s32 D_0036F4C0;
s32 D_0036F4F0;

void set_ztest_off(void) {
    sceGsSyncPath(0, 0);
    sceDmaSend(oa_dmagif, &D_0036F4C0);
}

void set_invisible(void) {
    sceGsSyncPath(0, 0);
    sceDmaSend(oa_dmagif, &D_0036F4F0);
}

INCLUDE_ASM(const s32, "ppp/draw/md", unset_test);

INCLUDE_ASM(const s32, "ppp/draw/md", op1_md_draw);
