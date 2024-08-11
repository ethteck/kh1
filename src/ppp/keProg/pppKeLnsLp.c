#include "ppp/pppKeLns.h"

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ f32 lWid;
    /* 0x8 */ f32 pow;
    /* 0xC */ u8 r;
    /* 0xD */ u8 md;
} PKeLnsLp;

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeLnsLp", pppKeLnsLpDraw);

void pppKeLnsLpCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeLnsLp* lp = (KeLnsLp*)&pobj->val[ctbl->useVal[0]];

    KeLnsLp_Init(lp);
    lp->lVec[3] = 0;
    lp->pow = 0;
}

void pppKeLnsLpCon2(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeLnsLp* lp = (KeLnsLp*)&pobj->val[ctbl->useVal[0]];

    lp->lVec[3] = 0;
    lp->pow = 0;
}

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeLnsLp", func_00193978);
