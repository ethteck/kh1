#include "ppp/pppUtil.h"

void pppGetRotMatrixYZX(sceVu0FMATRIX mp, pppIVECTOR* angle) {
    sceVu0FMATRIX m0, m1, m2, m3;

    pppGetRotMatrixX(m0, angle->x);
    pppGetRotMatrixZ(m1, angle->z);
    sceVu0MulMatrix(m2, m0, m1);
    pppGetRotMatrixY(m3, angle->y);
    sceVu0MulMatrix(mp, m2, m3);
}
