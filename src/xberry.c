#include "common.h"

#include "ppp/pppUtil.h"
#include "ppp/pppKeLns.h"

#include "libvu0.h"

extern f32 D_0036F790[0x1000]; // sine table

void pppGetRotMatrixX(sceVu0FMATRIX mp, u32 angle) {
    f32 sin = D_0036F790[(angle / 16) % 0x1000];
    f32 cos = D_0036F790[((angle + 0x4000) / 16) % 0x1000];

    mp[0][0] = 1.0f;
    mp[1][0] = 0.0f;
    mp[2][0] = 0.0f;
    mp[3][0] = 0.0f;
    mp[0][1] = 0.0f;
    mp[1][1] = cos;
    mp[2][1] = -sin;
    mp[3][1] = 0.0f;
    mp[0][2] = 0.0f;
    mp[1][2] = sin;
    mp[2][2] = cos;
    mp[3][2] = 0.0f;
    mp[0][3] = 0.0f;
    mp[1][3] = 0.0f;
    mp[2][3] = 0.0f;
    mp[3][3] = 1.0f;
}

void pppGetRotMatrixY(sceVu0FMATRIX mp, u32 angle) {
    f32 sin = D_0036F790[(angle / 16) % 0x1000];
    f32 cos = D_0036F790[((angle + 0x4000) / 16) % 0x1000];

    mp[0][0] = cos;
    mp[1][0] = 0.0f;
    mp[2][0] = sin;
    mp[3][0] = 0.0f;
    mp[0][1] = 0.0f;
    mp[1][1] = 1.0f;
    mp[2][1] = 0.0f;
    mp[3][1] = 0.0f;
    mp[0][2] = -sin;
    mp[1][2] = 0.0f;
    mp[2][2] = cos;
    mp[3][2] = 0.0f;
    mp[0][3] = 0.0f;
    mp[1][3] = 0.0f;
    mp[2][3] = 0.0f;
    mp[3][3] = 1.0f;
}

void pppGetRotMatrixZ(sceVu0FMATRIX mp, u32 angle) {
    f32 sin = D_0036F790[(angle / 16) % 0x1000];
    f32 cos = D_0036F790[((angle + 0x4000) / 16) % 0x1000];

    mp[0][0] = cos;
    mp[1][0] = -sin;
    mp[2][0] = 0.0f;
    mp[3][0] = 0.0f;
    mp[0][1] = sin;
    mp[1][1] = cos;
    mp[2][1] = 0.0f;
    mp[3][1] = 0.0f;
    mp[0][2] = 0.0f;
    mp[1][2] = 0.0f;
    mp[2][2] = 1.0f;
    mp[3][2] = 0.0f;
    mp[0][3] = 0.0f;
    mp[1][3] = 0.0f;
    mp[2][3] = 0.0f;
    mp[3][3] = 1.0f;
}

void pppGetRotMatrixXZY(sceVu0FMATRIX mp, pppIVECTOR* angle) {
    sceVu0FMATRIX m0, m1, m2, m3;

    pppGetRotMatrixY(m0, angle->y);
    pppGetRotMatrixZ(m1, angle->z);
    sceVu0MulMatrix(m2, m0, m1);
    pppGetRotMatrixX(m3, angle->x);
    sceVu0MulMatrix(mp, m2, m3);
}

void pppGetRotMatrixYZX(sceVu0FMATRIX mp, pppIVECTOR* angle) {
    sceVu0FMATRIX m0, m1, m2, m3;

    pppGetRotMatrixX(m0, angle->x);
    pppGetRotMatrixZ(m1, angle->z);
    sceVu0MulMatrix(m2, m0, m1);
    pppGetRotMatrixY(m3, angle->y);
    sceVu0MulMatrix(mp, m2, m3);
}

void pppGetRotMatrixYXZ(sceVu0FMATRIX mp, pppIVECTOR* angle) {
    sceVu0FMATRIX m0, m1, m2, m3;

    pppGetRotMatrixZ(m0, angle->z);
    pppGetRotMatrixX(m1, angle->x);
    sceVu0MulMatrix(m2, m0, m1);
    pppGetRotMatrixY(m3, angle->y);
    sceVu0MulMatrix(mp, m2, m3);
}

void pppGetRotMatrixZXY(sceVu0FMATRIX mp, pppIVECTOR* angle) {
    sceVu0FMATRIX m0, m1, m2, m3;

    pppGetRotMatrixY(m0, angle->y);
    pppGetRotMatrixX(m1, angle->x);
    sceVu0MulMatrix(m2, m0, m1);
    pppGetRotMatrixZ(m3, angle->z);
    sceVu0MulMatrix(mp, m2, m3);
}

void pppGetRotMatrixZYX(sceVu0FMATRIX arg0, pppIVECTOR* angle) {
    sceVu0FMATRIX m0, m1, m2, m3;

    pppGetRotMatrixX(m0, angle->x);
    pppGetRotMatrixY(m1, angle->y);
    sceVu0MulMatrix(m2, m0, m1);
    pppGetRotMatrixZ(m3, angle->z);
    sceVu0MulMatrix(arg0, m2, m3);
}

INCLUDE_ASM(const s32, "xberry", KeBornRnd2);

INCLUDE_ASM(const s32, "xberry", func_001A75B0);

INCLUDE_ASM(const s32, "xberry", func_001A75C8);

INCLUDE_ASM(const s32, "xberry", func_001A7668);

INCLUDE_ASM(const s32, "xberry", func_001A76E8);

void KeLnsLp_Init(KeLnsLp* lp) {
    ppvMng->drawPriority = 2;
    sceVu0UnitMatrix(lp->zMat);
    lp->preHidePow = 1.0f;
}

INCLUDE_ASM(const s32, "xberry", func_001A7C40);

INCLUDE_ASM(const s32, "xberry", func_001A7F48);

void KeLnsClm_Init(KeLnsClm* p) {
    p->flag = 0;
    p->lp = &ppvDbgTemp;
    p->shp = NULL;
}

INCLUDE_ASM(const s32, "xberry", func_001A8060);

void KeLnsArnd_Init(KeLnsArnd* p) {
    p->shp = NULL;
    p->lp = &ppvDbgTemp;
}

INCLUDE_ASM(const s32, "xberry", func_001A8248);

INCLUDE_ASM(const s32, "xberry", func_001A84B8);

void KeLnsCrn_Init(KeLnsCrn* p) {
    p->shp = NULL;
    p->lp = &ppvDbgTemp;
}

INCLUDE_ASM(const s32, "xberry", KeLnsFls_Draw);

void KeLnsFls_Init(KeLnsFls* p) {
    p->shp = NULL;
    p->lp = &ppvDbgTemp;
}

INCLUDE_ASM(const s32, "xberry", func_001A8770);
