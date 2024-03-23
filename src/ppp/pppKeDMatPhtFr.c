#include "ppp.h"

void pppKeDMatPhtFrCalc(void) {
    sceVu0ScaleVector(KeDMat[0], KeMatPht[0], ppvParScl[0]);
    sceVu0ScaleVector(KeDMat[1], KeMatPht[1], ppvParScl[1]);
    sceVu0ScaleVector(KeDMat[2], KeMatPht[2], ppvParScl[2]);
    sceVu0ApplyMatrix(KeDMat[3], ppvWorldMatrix, KeMatPht[3]);
    sceVu0ScaleVector(ppvPObj.next->dmat[0], ppvPObj.next->cmat[0], ppvParScl[0]);
    sceVu0ScaleVector(ppvPObj.next->dmat[1], ppvPObj.next->cmat[1], ppvParScl[1]);
    sceVu0ScaleVector(ppvPObj.next->dmat[2], ppvPObj.next->cmat[2], ppvParScl[2]);
    sceVu0ApplyMatrix(ppvPObj.next->dmat[3], ppvWorldMatrix, ppvPObj.next->cmat[3]);
    sceVu0MulMatrix(ppvPObj.next->dmat, ppvScreenMatrix, ppvPObj.next->dmat);
}
