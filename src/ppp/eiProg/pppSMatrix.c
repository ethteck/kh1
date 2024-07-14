#include "ppp.h"

typedef struct {
    /* 0x0 */ void* m;
} PSMatrix;

PSMatrix* ppvlpCMatrix;

void pppSMatrixCalc(pppPObject* pobj, PSMatrix* p, pppCtrlTable* ctbl) {
    ppvlpCMatrix = (PSMatrix*)&pobj->val[ctbl->useVal[0]];
}
