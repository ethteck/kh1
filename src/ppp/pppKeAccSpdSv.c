#include "ppp.h"

void pppKeAccSpdSvCalc(void) {
}

void pppKeAccSpdSvCon(void) {
}

void func_001851E8(sceVu0FMATRIX arg0, u32* arg1) {
    sceVu0FMATRIX m0, m1, m2, m3;

    func_001A70F8(m0, arg1[2]);
    func_001A7078(m1, arg1[1]);
    sceVu0MulMatrix(m2, m0, m1);
    func_001A6FF8(m3, arg1[0]);
    sceVu0MulMatrix(arg0, m2, m3);
}
