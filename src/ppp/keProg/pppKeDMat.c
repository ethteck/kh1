#include "ppp.h"

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ FMATRIX Mat;
} PKeDMat;

typedef struct {
    /* 0x0 */ FMATRIX Mat;
} VKeDMat;

void pppKeDMatCalc(pppPObject* pobj, PKeDMat* p, pppCtrlTable* ctbl) {
    VKeDMat* v = (VKeDMat*)&pobj->val[ctbl->useVal[1]];

    sceVu0MulMatrix(ppvPObj.next->dmat, ppvWorldMatrix, ppvPObj.next->cmat);
    sceVu0CopyMatrix(v->Mat, ppvPObj.next->dmat);
    sceVu0MulMatrix(ppvPObj.next->dmat, ppvScreenMatrix, ppvPObj.next->dmat);
}
