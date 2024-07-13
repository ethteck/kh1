#ifndef PPPUTIL_H
#define PPPUTIL_H

#include "common.h"
#include "ppp/pppKeLns.h"

extern f32 D_0036F790[0x1000]; // sine table

void pppGetRotMatrixX(sceVu0FMATRIX mp, u32 angle);
void pppGetRotMatrixY(sceVu0FMATRIX mp, u32 angle);
void pppGetRotMatrixZ(sceVu0FMATRIX mp, u32 angle);
void pppGetRotMatrixXYZ(sceVu0FMATRIX mp, pppIVECTOR* angle);
void pppGetRotMatrixXZY(sceVu0FMATRIX mp, pppIVECTOR* angle);
void pppGetRotMatrixYZX(sceVu0FMATRIX mp, pppIVECTOR* angle);
void pppGetRotMatrixYXZ(sceVu0FMATRIX mp, pppIVECTOR* angle);
void pppGetRotMatrixZXY(sceVu0FMATRIX mp, pppIVECTOR* angle);
void pppGetRotMatrixZYX(sceVu0FMATRIX arg0, pppIVECTOR* angle);

#endif // PPPUTIL_H
