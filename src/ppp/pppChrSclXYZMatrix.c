#include "ppp.h"

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ f32 sclr;
    /* 0x8 */ f32 maxscl;
} PChrSclXYZMatrix;

void pppChrSclXYZMatrixCalc(pppPObject* pobj, PChrSclXYZMatrix* p) {
    sceVu0FMATRIX m;

    sceVu0UnitMatrix(m);

    m[0][0] = ppvMng->unk_40 + (ppvMng->unk_40 * p->sclr);
    if (m[0][0] > p->maxscl) {
        m[0][0] = p->maxscl;
    }

    m[2][2] = m[0][0];

    m[1][1] = ppvMng->unk_44 + (ppvMng->unk_44 * p->sclr);
    if (m[1][1] > p->maxscl) {
        m[1][1] = p->maxscl;
    }

    sceVu0MulMatrix(ppvPObj.next->cmat, m, ppvPObj.next->cmat);
}
