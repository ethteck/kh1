#include "ppp.h"

void pppKeDMatPhtCalc(void) {
    sceVu0MulMatrix(KeDMat, ppvWorldMatrix, KeMatPht);
    sceVu0ScaleVector(ppvPObj.next->dmat[0], ppvPObj.next->cmat[0], ppvParScl[0]);
    sceVu0ScaleVector(ppvPObj.next->dmat[1], ppvPObj.next->cmat[1], ppvParScl[1]);
    sceVu0ScaleVector(ppvPObj.next->dmat[2], ppvPObj.next->cmat[2], ppvParScl[2]);
    sceVu0ApplyMatrix(ppvPObj.next->dmat[3], ppvWorldMatrix, ppvPObj.next->cmat[3]);
    sceVu0MulMatrix(ppvPObj.next->dmat, ppvScreenMatrix, ppvPObj.next->dmat);
}
