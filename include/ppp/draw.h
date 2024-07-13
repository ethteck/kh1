#include "common.h"
#include "libdma.h"

s32 spr_a[32];
s32 spr_rev_a[32];
s8 spr_index;
s8 spr_rev_index;

sceDmaChan* oa_dmagif;

void op_ot_draw(void);
void op_init_draw(void);
void op_gs2_init(void);
void op_otz_init(void);
void op_init_fog_work(void);

