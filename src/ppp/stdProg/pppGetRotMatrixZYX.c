#include "ppp/pppUtil.h"

void pppGetRotMatrixZYX(sceVu0FMATRIX arg0, pppIVECTOR* angle) {
    sceVu0FMATRIX m0, m1, m2, m3;

    pppGetRotMatrixX(m0, angle->x);
    pppGetRotMatrixY(m1, angle->y);
    sceVu0MulMatrix(m2, m0, m1);
    pppGetRotMatrixZ(m3, angle->z);
    sceVu0MulMatrix(arg0, m2, m3);
}
