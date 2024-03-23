#include "ppp.h"
#include "libvu0.h"

FMATRIX ppvSWMatrix;

void pppDrawMatrixCalc(void) {
    sceVu0MulMatrix(ppvPObj.next->dmat, ppvSWMatrix, ppvPObj.next->cmat);
}
