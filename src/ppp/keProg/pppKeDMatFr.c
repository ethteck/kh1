#include "ppp.h"

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ FMATRIX MatFr;
} PKeDMatFr;

typedef struct {
    /* 0x0 */ FMATRIX MatFr;
} VKeDMatFr;

void pppKeDMatFrCalc(pppPObject* pobj, PKeDMatFr* p, pppCtrlTable* ctbl) {
    VKeDMatFr* v = (VKeDMatFr*)&pobj->val[ctbl->useVal[1]];

    sceVu0ScaleVector(ppvPObj.next->dmat[0], ppvPObj.next->cmat[0], ppvParScl[0]);
    sceVu0ScaleVector(ppvPObj.next->dmat[1], ppvPObj.next->cmat[1], ppvParScl[1]);
    sceVu0ScaleVector(ppvPObj.next->dmat[2], ppvPObj.next->cmat[2], ppvParScl[2]);
    sceVu0ApplyMatrix(ppvPObj.next->dmat[3], ppvWorldMatrix, ppvPObj.next->cmat[3]);
    sceVu0CopyMatrix(v->MatFr, ppvPObj.next->dmat);
    sceVu0MulMatrix(ppvPObj.next->dmat, ppvScreenMatrix, ppvPObj.next->dmat);
}
