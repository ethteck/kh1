#include "ppp.h"

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ f32 sclr;
    /* 0x8 */ f32 maxscl;
} PChrXSclXYZMatrix;

void pppChrXSclXYZMatrixCalc(pppPObject* pobj, PChrXSclXYZMatrix* p) {
    sceVu0FMATRIX m;

    sceVu0UnitMatrix(m);

    m[0][0] = ppvMng->scaleX + (ppvMng->scaleX * p->sclr);
    if (m[0][0] > p->maxscl) {
        m[0][0] = p->maxscl;
    }

    m[2][2] = m[0][0];
    m[1][1] = m[0][0];

    sceVu0MulMatrix(ppvPObj.next->cmat, m, ppvPObj.next->cmat);
}
