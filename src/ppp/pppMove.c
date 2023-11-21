#include "ppp.h"

typedef struct {
    pppCDT cdt;
    pppFVECTOR vec;
} PMove;

typedef struct {
    pppFVECTOR vec;
} VMove;

void pppMove(pppPObject* pobj, PMove* p, pppCtrlTable* ctbl) {
    VMove* v;
    pppFVECTOR* move;

    v = (VMove*)&pobj->val[ctbl->useVal[0]];
    move = (pppFVECTOR*)&pobj->val[ctbl->useVal[1]];
    if (ppvUserStopPartF != 0) {
        return;
    }

    if (ppvMng->unk_B9 != 0 || ppvMng->unk_BC != 0) {
        return;
    }

    if (p->cdt.time == pobj->time) {
        move->x = move->x + p->vec.x;
        move->y = move->y + p->vec.y;
        move->z = move->z + p->vec.z;
    }
    v->vec.x = v->vec.x + move->x;
    v->vec.y = v->vec.y + move->y;
    v->vec.z = v->vec.z + move->z;
}

void pppMoveCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    f32 val = 0.0f;
    VMove* v = (VMove*)&pobj->val[ctbl->useVal[1]];

    v->vec.x = v->vec.y = v->vec.z = val;
}
