#include "ppp/pppUtil.h"

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
