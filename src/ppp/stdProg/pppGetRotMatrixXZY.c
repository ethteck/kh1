#include "ppp/pppUtil.h"

void pppGetRotMatrixXZY(sceVu0FMATRIX mp, pppIVECTOR* angle) {
    sceVu0FMATRIX m0, m1, m2, m3;

    pppGetRotMatrixY(m0, angle->y);
    pppGetRotMatrixZ(m1, angle->z);
    sceVu0MulMatrix(m2, m0, m1);
    pppGetRotMatrixX(m3, angle->x);
    sceVu0MulMatrix(mp, m2, m3);
}
