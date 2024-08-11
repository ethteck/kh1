#include "common.h"
#include "fastmath.h"

f32 func_001215A8(sceVu0FVECTOR, sceVu0FVECTOR);

extern f32 D_002B8340[];
extern f32 D_002B8344[];

f32 func_00120A38(sceVu0FVECTOR arg0) {
    f32 prod = sceVu0InnerProduct(arg0, arg0);
    return _sqrtf(prod);
}

f32 func_00120A58(sceVu0FVECTOR arg0) {
    return _sqrtf(arg0[0] * arg0[0] + arg0[2] * arg0[2]);
}

s32 func_00120A78(sceVu0FMATRIX arg0, sceVu0FMATRIX arg1, sceVu0FVECTOR arg2) {
    sceVu0RotMatrixZ(arg0, arg1, arg2[2]);
    sceVu0RotMatrixX(arg0, arg0, arg2[0]);
    sceVu0RotMatrixY(arg0, arg0, arg2[1]);
}

INCLUDE_ASM("asm/nonmatchings/xball", func_00120AC8);
f32 func_00120AC8(f32);

INCLUDE_ASM("asm/nonmatchings/xball", func_00120B40);

INCLUDE_ASM("asm/nonmatchings/xball", func_00120D38);

INCLUDE_ASM("asm/nonmatchings/xball", func_00120DB8);

// nonmatch: extra nops
INCLUDE_ASM("asm/nonmatchings/xball", func_00120E48);
// s32 func_00120E48(sceVu0FMATRIX arg0, sceVu0FVECTOR* arg1) {
//     sceVu0FVECTOR local_40;
//     s32 i;

//     for (i = 0; i < 8; i++) {
//         sceVu0ApplyMatrix(local_40, arg0, arg1[i]);
//         if (local_40[3] < 1.0f) {
//             return 0;
//         }
//         local_40[0] /= local_40[3];
//         local_40[1] /= local_40[3];
//         if (local_40[0] < 0.0f || local_40[0] > 4095.0f) {
//             return 0;
//         }
//         if (local_40[1] < 0.0f || local_40[1] > 4095.0f) {
//             return 0;
//         }
//     }
//     return 1;
// }

void func_00120F48(f32 arg0, sceVu0FVECTOR arg1, sceVu0FVECTOR arg2) {
    arg1[0] = arg2[0] * arg0;
    arg1[1] = arg2[1];
    arg1[2] = arg2[2] * arg0;
    arg1[3] = arg2[3];
}

s32 func_00120F78(sceVu0FMATRIX arg0) {
    return (arg0[0][2] < 0.0f || sceVu0ClipScreen(*arg0) != 0) ? TRUE : FALSE;
}

s32 func_00120FC8(f32 arg0, sceVu0FMATRIX arg1, sceVu0FMATRIX arg2, sceVu0FMATRIX arg3) {
    sceVu0FVECTOR v0;
    sceVu0FVECTOR v1;
    sceVu0FVECTOR v2;
    sceVu0FVECTOR v3;
    sceVu0FVECTOR v4;

    sceVu0SubVector(v1, arg2[1], arg2[0]);
    sceVu0SubVector(v2, arg3[1], arg3[0]);
    sceVu0ScaleVector(
        v3, v1, ((arg3[0][1] - arg2[0][1]) + v2[1] * (arg3[0][0] - arg2[0][0])) / (v2[0] * v1[1] - v2[1] * v1[0])
    );
    sceVu0AddVector(v3, v3, arg2[0]);

    sceVu0SubVector(v1, arg2[0], v3);
    func_001223B0(v1, v1);

    sceVu0SubVector(v2, arg3[0], v3);
    func_001223B0(v2, v2);

    sceVu0InterVector(v0, v2, v1, arg0);
    sceVu0Normalize(v0, v0);
    sceVu0ScaleVector(v4, v0, v1[3] + (v2[3] - v1[3]) * arg0);
    sceVu0AddVector(arg1[0], v3, v4);
    arg1[0][3] = 1.0f;

    sceVu0SubVector(v1, arg2[1], v3);
    func_001223B0(v1, v1);

    sceVu0SubVector(v2, arg3[1], v3);
    func_001223B0(v2, v2);

    sceVu0InterVector(v0, v2, v1, arg0);
    sceVu0Normalize(v0, v0);
    sceVu0ScaleVector(v4, v0, v1[3] + (v2[3] - v1[3]) * arg0);
    sceVu0AddVector(arg1[1], v3, v4);
    arg1[1][3] = 1.0f;

    return 1;
}

INCLUDE_ASM("asm/nonmatchings/xball", func_00121200);

INCLUDE_ASM("asm/nonmatchings/xball", func_00121340);

INCLUDE_ASM("asm/nonmatchings/xball", func_001213B0);

void func_00121480(f32 arg0, f32 arg1, f32 arg2, f32 arg3, sceVu0FMATRIX arg4, sceVu0FVECTOR arg5) {
    sceVu0DropShadowMatrix(arg4, arg5, arg0, arg1, arg2, 0);
    sceVu0ScaleVectorXYZ(arg4[3], arg4[3], arg3);
}

void func_001214C8(sceVu0FMATRIX arg0, sceVu0FMATRIX arg1) {
    arg0[0][0] = arg1[0][0];
    arg0[0][1] = arg1[1][0];
    arg0[0][2] = arg1[2][0];
    arg0[0][3] = 0.0f;
    arg0[1][0] = arg1[0][1];
    arg0[1][1] = arg1[1][1];
    arg0[1][2] = arg1[2][1];
    arg0[1][3] = 0.0f;
    arg0[2][0] = arg1[0][2];
    arg0[2][1] = arg1[1][2];
    arg0[2][2] = arg1[2][2];
    arg0[2][3] = 0.0f;
    arg0[3][0] = 0.0f;
    arg0[3][1] = 0.0f;
    arg0[3][2] = 0.0f;
    arg0[3][3] = 1.0f;
}

INCLUDE_ASM("asm/nonmatchings/xball", func_00121538);

INCLUDE_ASM("asm/nonmatchings/xball", func_001215A8);

f32 func_001216A8(sceVu0FVECTOR arg0, sceVu0FVECTOR arg1) {
    return acosf(func_001215A8(arg0, arg1));
}

INCLUDE_ASM("asm/nonmatchings/xball", func_001216C8);

INCLUDE_ASM("asm/nonmatchings/xball", func_001217C0);

INCLUDE_ASM("asm/nonmatchings/xball", func_00121830);

void func_00121878(sceVu0FVECTOR arg0, sceVu0FVECTOR arg1, sceVu0FVECTOR arg2) {
    arg1[0] = atan2f(-arg0[1], func_00120A58(arg0));
    arg1[1] = atan2f(arg0[0], arg0[2]);
    arg1[2] = 0.0f;
    arg1[3] = 1.0f;
}

INCLUDE_ASM("asm/nonmatchings/xball", func_001218E0);

f32 func_00121970(f32 arg0) {
    if (arg0 > 0.0f) {
        arg0 -= D_002B8340[1];
        if (arg0 < 0.0f) {
            arg0 = 0.0f;
        }
    }
    return arg0;
}

void func_001219A8(sceVu0FVECTOR arg0, sceVu0FVECTOR arg1) {
    sceVu0FVECTOR stack0;
    sceVu0FVECTOR stack1;

    sceVu0CopyVector(stack0, arg0);
    sceVu0CopyVector(stack1, arg1);
    stack0[1] = 0.0f;
    stack1[1] = 0.0f;
    func_001215A8(stack0, stack1);
}
