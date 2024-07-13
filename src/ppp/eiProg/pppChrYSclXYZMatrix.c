#include "ppp.h"


typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ f32 sclr;
    /* 0x8 */ f32 maxscl;
} PChrYSclXYZMatrix;

void pppChrYSclXYZMatrixCalc(pppPObject* pobj, PChrYSclXYZMatrix* p) {
    sceVu0FMATRIX m;

    sceVu0UnitMatrix(m);

    m[1][1] = ppvMng->scaleY + (ppvMng->scaleY * p->sclr);
    if (m[1][1] > p->maxscl) {
        m[1][1] = p->maxscl;
    }

    /* Bug? */
    m[1][1] = m[2][2];
    m[0][0] = m[1][1];

    sceVu0MulMatrix(ppvPObj.next->cmat, m, ppvPObj.next->cmat);
}
