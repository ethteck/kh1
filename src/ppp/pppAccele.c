#include "ppp.h"

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ pppFVECTOR vec;
} PAccele;

typedef struct {
    /* 0x0 */ pppFVECTOR vec;
} VAccele;

void pppAcceleCalc(pppPObject* pobj, PAccele* p, pppCtrlTable* ctbl) {
    VAccele* ac0 = (VAccele*)&pobj->val[ctbl->useVal[0]];
    VAccele* ac1 = (VAccele*)&pobj->val[ctbl->useVal[1]];

    if (ppvUserStopPartF != 0 || ppvMng->unk_B1 != 0 || ppvMng->unk_B4 != 0) {
        return;
    }

    if (p->cdt.time == pobj->time) {
        ac1->vec.x += p->vec.x;
        ac1->vec.y += p->vec.y;
        ac1->vec.z += p->vec.z;
    }
    ac0->vec.x += ac1->vec.x;
    ac0->vec.y += ac1->vec.y;
    ac0->vec.z += ac1->vec.z;
}

void pppAcceleCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VAccele* ac = (VAccele*)&pobj->val[ctbl->useVal[1]];
    ac->vec.x = ac->vec.y = ac->vec.z = 0.0f;
}
