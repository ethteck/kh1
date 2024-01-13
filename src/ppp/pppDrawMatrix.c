#include "ppp.h"
#include "libvu0.h"

FMATRIX ppvSWMatrix;

void pppDrawMatrixCalc() {
    sceVu0MulMatrix(ppvPObj.next->dmat, ppvSWMatrix, ppvPObj.next->cmat);
}
