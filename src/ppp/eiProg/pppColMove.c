#include "ppp.h"

typedef struct {
    /* 0x0 */ pppHCVECTOR col;
} VColMove;

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ pppHCVECTOR col;
} PColMove;

void pppColMoveCalc(pppPObject* pobj, PColMove* p, pppCtrlTable* ctbl) {
    VColMove* col = (VColMove*)&pobj->val[ctbl->useVal[0]];
    VColMove* ac = (VColMove*)&pobj->val[ctbl->useVal[1]];

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }

    if (p->cdt.time == pobj->time) {
        ac->col.r += p->col.r;
        ac->col.g += p->col.g;
        ac->col.b += p->col.b;
        ac->col.a += p->col.a;
    }

    col->col.r += ac->col.r;
    col->col.g += ac->col.g;
    col->col.b += ac->col.b;
    col->col.a += ac->col.a;
}

void pppColMoveCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VColMove* col = (VColMove*)&pobj->val[ctbl->useVal[1]];
    col->col.r = col->col.g = col->col.b = col->col.a = 0;
}
