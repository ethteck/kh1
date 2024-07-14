#include "ppp.h"

typedef struct {
    /* 0x0 */ pppHCVECTOR ddcol;
} VColAccele;

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ pppHCVECTOR ddcol;
} PColAccele;

void pppColAcceleCalc(pppPObject* pobj, PColAccele* p, pppCtrlTable* ctbl) {
    VColAccele* col = (VColAccele*)&pobj->val[ctbl->useVal[0]];
    VColAccele* ac = (VColAccele*)&pobj->val[ctbl->useVal[1]];

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }

    if (p->cdt.time == pobj->time) {
        ac->ddcol.r += p->ddcol.r;
        ac->ddcol.g += p->ddcol.g;
        ac->ddcol.b += p->ddcol.b;
        ac->ddcol.a += p->ddcol.a;
    }

    col->ddcol.r += ac->ddcol.r;
    col->ddcol.g += ac->ddcol.g;
    col->ddcol.b += ac->ddcol.b;
    col->ddcol.a += ac->ddcol.a;
}

void pppColAcceleCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VColAccele* col = (VColAccele*)&pobj->val[ctbl->useVal[1]];
    col->ddcol.r = col->ddcol.g = col->ddcol.b = col->ddcol.a = 0;
}
