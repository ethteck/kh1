#include "ppp.h"

typedef struct {
    pppCDT cdt;
    pppFVECTOR scale;
} PScale;

typedef struct {
    pppFVECTOR scale;
} VScale;

void pppScaleCalc(pppPObject* pobj, PScale* p, pppCtrlTable* ctbl) {
    VScale* v;

    if (ppvUserStopPartF != 0) {
        return;
    }

    if (ppvMng->unk_B1 != 0 || ppvMng->unk_B4 != 0) {
        return;
    }

    if (p->cdt.time != pobj->time) {
        return;
    }

    v = (VScale*)&pobj->val[ctbl->useVal[0]];
    v->scale.x += p->scale.x;
    v->scale.y += p->scale.y;
    v->scale.z += p->scale.z;
}

void pppScaleCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    f32 val = 0.0f;
    VScale* v = (VScale*)&pobj->val[ctbl->useVal[0]];

    v->scale.x = v->scale.y = v->scale.z = val;
}
