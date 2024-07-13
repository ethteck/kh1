#include "common.h"

#include "ppp/pppUtil.h"
#include "ppp/pppKeLns.h"

#include "libvu0.h"

INCLUDE_ASM(const s32, "ppp/xberry", KeBornRnd2);

INCLUDE_ASM(const s32, "ppp/xberry", func_001A75B0);

INCLUDE_ASM(const s32, "ppp/xberry", func_001A75C8);

INCLUDE_ASM(const s32, "ppp/xberry", func_001A7668);

INCLUDE_ASM(const s32, "ppp/xberry", func_001A76E8);

void KeLnsLp_Init(KeLnsLp* lp) {
    ppvMng->drawPriority = 2;
    sceVu0UnitMatrix(lp->zMat);
    lp->preHidePow = 1.0f;
}

INCLUDE_ASM(const s32, "ppp/xberry", func_001A7C40);

INCLUDE_ASM(const s32, "ppp/xberry", func_001A7F48);

void KeLnsClm_Init(KeLnsClm* p) {
    p->flag = 0;
    p->lp = &ppvDbgTemp;
    p->shp = NULL;
}

INCLUDE_ASM(const s32, "ppp/xberry", func_001A8060);

void KeLnsArnd_Init(KeLnsArnd* p) {
    p->shp = NULL;
    p->lp = &ppvDbgTemp;
}

INCLUDE_ASM(const s32, "ppp/xberry", func_001A8248);

INCLUDE_ASM(const s32, "ppp/xberry", func_001A84B8);

void KeLnsCrn_Init(KeLnsCrn* p) {
    p->shp = NULL;
    p->lp = &ppvDbgTemp;
}

INCLUDE_ASM(const s32, "ppp/xberry", KeLnsFls_Draw);

void KeLnsFls_Init(KeLnsFls* p) {
    p->shp = NULL;
    p->lp = &ppvDbgTemp;
}

INCLUDE_ASM(const s32, "ppp/xberry", func_001A8770);
