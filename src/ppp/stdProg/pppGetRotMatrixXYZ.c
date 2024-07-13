#include "ppp/pppUtil.h"

void pppGetRotMatrixXYZ(sceVu0FMATRIX mp, pppIVECTOR* angle) {
    sceVu0FMATRIX m0, m1, m2, m3;

    pppGetRotMatrixZ(m0, angle->z);
    pppGetRotMatrixY(m1, angle->y);
    sceVu0MulMatrix(m2, m0, m1);
    pppGetRotMatrixX(m3, angle->x);
    sceVu0MulMatrix(mp, m2, m3);
}
