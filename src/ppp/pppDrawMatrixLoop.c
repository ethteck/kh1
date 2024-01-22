#include "ppp.h"

void pppDrawMatrixLoopCalc() {
    sceVu0MulMatrix(ppvPObj.next->dmat, ppvSWMatrix, ppvPObj.next->cmat);
}
