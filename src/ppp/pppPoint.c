#include "ppp.h"

typedef struct {
    pppCDT cdt;
    pppFVECTOR pos;
} PPoint;

typedef struct {
    pppFVECTOR pos;
} VPoint;

void pppPoint(pppPObject * pobj, PPoint * p, pppCtrlTable * ctbl) {
    VPoint *v;

    if (ppvUserStopPartF) {
        return;
    }

    if (ppvMng->unkB9 || ppvMng->unkBC) {
        return;
    }

    if (p->cdt.time != pobj->time) {
        return;
    }
    
    v = (VPoint*)&pobj->val[ctbl->useVal[0]];
    v->pos.x += p->pos.x;
    v->pos.y += p->pos.y;
    v->pos.z += p->pos.z;
}

void pppPointCon(pppPObject * pobj, pppCtrlTable * ctbl) {
    float val = 0.0f;
    VPoint *v = (VPoint*)&pobj->val[ctbl->useVal[0]];
    
    v->pos.x = v->pos.y = v->pos.z = val;
}
