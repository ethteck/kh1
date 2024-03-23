#include "ppp.h"

void pppDrawMatrixLoopCalc(void) {
    sceVu0MulMatrix(ppvPObj.next->dmat, ppvSWMatrix, ppvPObj.next->cmat);
}
