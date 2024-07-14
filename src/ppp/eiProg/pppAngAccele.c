#include "ppp.h"

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ pppIVECTOR ddang;
} PAngAccele;

typedef struct {
    /* 0x0 */ pppIVECTOR ddang;
} VAngAccele;

void pppAngAcceleCalc(pppPObject* pobj, PAngAccele* p, pppCtrlTable* ctbl) {
    VAngAccele* ac0 = (VAngAccele*)&pobj->val[ctbl->useVal[0]];
    VAngAccele* ac1 = (VAngAccele*)&pobj->val[ctbl->useVal[1]];

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }

    if (p->cdt.time == pobj->time) {
        ac1->ddang.x += p->ddang.x;
        ac1->ddang.y += p->ddang.y;
        ac1->ddang.z += p->ddang.z;
    }
    ac0->ddang.x += ac1->ddang.x;
    ac0->ddang.y += ac1->ddang.y;
    ac0->ddang.z += ac1->ddang.z;
}

void pppAngAcceleCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VAngAccele* ac = (VAngAccele*)&pobj->val[ctbl->useVal[1]];
    ac->ddang.x = ac->ddang.y = ac->ddang.z = 0;
}
