#include "ppp.h"

typedef struct {
    /* 0x0 */ u16 wait;
    /* 0x2 */ u16 seq;
    /* 0x4 */ u16 seq_now;
} VDrawShapeX;

void pppDrawShapeXCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VDrawShapeX* vds = (VDrawShapeX*)&pobj->val[ctbl->useVal[0]];
    vds->seq_now = 0;
    vds->seq = 0;
    vds->wait = 0;
}

INCLUDE_ASM(const s32, "ppp/keProg/pppDrawShapeX", pppDrawShapeXCalc);

INCLUDE_ASM(const s32, "ppp/keProg/pppDrawShapeX", pppDrawShapeXDraw);
