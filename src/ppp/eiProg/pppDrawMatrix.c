#include "ppp.h"

void pppDrawMatrixCalc(void) {
    sceVu0MulMatrix(ppvPObj.next->dmat, ppvSWMatrix, ppvPObj.next->cmat);
}
