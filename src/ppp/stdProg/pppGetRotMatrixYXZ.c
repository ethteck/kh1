#include "ppp/pppUtil.h"

void pppGetRotMatrixYXZ(sceVu0FMATRIX mp, pppIVECTOR* angle) {
    sceVu0FMATRIX m0, m1, m2, m3;

    pppGetRotMatrixZ(m0, angle->z);
    pppGetRotMatrixX(m1, angle->x);
    sceVu0MulMatrix(m2, m0, m1);
    pppGetRotMatrixY(m3, angle->y);
    sceVu0MulMatrix(mp, m2, m3);
}
