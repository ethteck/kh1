#include "ppp/pppUtil.h"

void pppGetRotMatrixZXY(sceVu0FMATRIX mp, pppIVECTOR* angle) {
    sceVu0FMATRIX m0, m1, m2, m3;

    pppGetRotMatrixY(m0, angle->y);
    pppGetRotMatrixX(m1, angle->x);
    sceVu0MulMatrix(m2, m0, m1);
    pppGetRotMatrixZ(m3, angle->z);
    sceVu0MulMatrix(mp, m2, m3);
}
