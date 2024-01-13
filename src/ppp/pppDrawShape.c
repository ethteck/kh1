#include "ppp.h"

typedef struct {
    /* 0x0 */ u16 wait;
    /* 0x2 */ u16 seq;
    /* 0x4 */ u16 seq_now;
} VDrawShape;

void pppDrawShapeCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VDrawShape* vds = (VDrawShape*)&pobj->val[ctbl->useVal[0]];
    vds->seq_now = 0;
    vds->seq = 0;
    vds->wait = 0;
}

INCLUDE_ASM(const s32, "ppp/pppDrawShape", pppDrawShapeCalc);

INCLUDE_ASM(const s32, "ppp/pppDrawShape", pppDrawShapeDraw);
