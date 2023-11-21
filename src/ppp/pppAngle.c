#include "ppp.h"

typedef struct {
    pppCDT cdt;
    pppIVECTOR angle;
} PAngle;

typedef struct {
    pppIVECTOR angle;
} VAngle;

void pppAngleCalc(pppPObject* pobj, PAngle* p, pppCtrlTable* ctbl) {
    VAngle* v;

    if (ppvUserStopPartF) {
        return;
    }

    if (ppvMng->unk_B9 || ppvMng->unk_BC) {
        return;
    }

    if (p->cdt.time != pobj->time) {
        return;
    }

    v = (VAngle*)&pobj->val[ctbl->useVal[0]];
    v->angle.x += p->angle.x;
    v->angle.y += p->angle.y;
    v->angle.z += p->angle.z;
}

void pppAngleCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    s32 val = 0;
    VAngle* v = (VAngle*)&pobj->val[ctbl->useVal[0]];

    v->angle.x = v->angle.y = v->angle.z = val;
}
