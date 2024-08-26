#include "common.h"
#include "xpeanut.h"

#include "math.h"

extern s32 D_002C1EA0;

extern sceVu0FMATRIX D_002B8370;

// .data
sceVu0FVECTOR D_002DEC10 = {0.0f, 1.0f, 0.0f, 1.0f};
sceVu0FMATRIX D_002DEC20 = {};
sceVu0FMATRIX D_002DEC60 = {};
sceVu0FMATRIX D_002DECA0 = {};
sceVu0FVECTOR D_002DECE0 = {};
sceVu0FVECTOR D_002DECF0 = {};
f32 D_002DED00 = 0.0f;
f32 D_002DED04 = 0.0f;
u32 D_002DED08 = 0;
s32* D_002DED0C = NULL;

// .bss
extern f32 D_004FAE00;
extern sceVu0FMATRIX D_004FAE10[];
extern sceVu0FMATRIX D_004FAE90[];
extern sceVu0FMATRIX D_004FAF10[];
extern f32 D_004FAF90;
extern f32 D_004FAF94;

extern void func_00110848(f32);
extern f32 func_00120AC8(f32);
void func_00120B40(f32, sceVu0FVECTOR, sceVu0FMATRIX);

void func_00125010(f32 arg0) {
    D_002DED00 = arg0;
    D_004FAE00 = 256.0f / tanf(((arg0 * 0.5f) / 180.0f) * PI);
}

void func_00125088(f32 arg0) {
    D_004FAF94 = D_002DED00;
    func_00125010(arg0);
}

void func_001250B0(void) {
    func_00125010(D_004FAF94);
}

void func_001250D0(f32* arg0, f32* arg1) {
    atan2f(arg0[0] - arg1[0], arg0[2] - arg1[2]);
}

void func_00125100(f32 arg0, f32 arg1, f32* arg2, f32* arg3) {
    sceVu0FMATRIX m;

    sceVu0RotMatrixY(m, D_002C1E20, -func_00120AC8(D_002DED04));
    sceVu0ApplyMatrix(arg3, m, arg2);
    arg3[0] = -arg3[0];
    arg3[3] = arg1;
    sceVu0RotMatrixY(m, D_002C1E20, arg0);
    sceVu0ApplyMatrix(arg3, m, arg3);
}

INCLUDE_ASM("asm/nonmatchings/xpeanut", func_001251B0);

INCLUDE_ASM("asm/nonmatchings/xpeanut", func_001253B8);
s32 func_001253B8(void);
// s32 func_001253B8(void) {
//     sceVu0FVECTOR v0;
//     sceVu0FVECTOR v1;
//     sceVu0FMATRIX m;

//     func_00110848(D_004FAE00);
//     sceVu0SubVector(v0, D_002DECF0, D_002DECE0);
//     sceVu0Normalize(v0, v0);
//     func_00120B40(func_00120AC8(D_002DED04), v0, m);
//     sceVu0ApplyMatrix(v1, m, D_002DEC10);
//     sceVu0CameraMatrix(D_004FAE90[D_002C1EA0], D_002DECE0, v0, v1);
//     sceVu0CopyMatrix(D_002DEC60, D_004FAE90[D_002C1EA0]);
//     sceVu0CopyMatrix(D_004FAF10[D_002C1EA0], D_002B8370);
//     sceVu0CopyMatrix(D_002DECA0, D_004FAF10[D_002C1EA0]);
//     sceVu0MulMatrix(D_004FAE10[D_002C1EA0], D_002DECA0, D_002DEC60);
//     sceVu0CopyMatrix(D_002DEC20, D_004FAE10[D_002C1EA0]);
//     D_002DED0C = D_004FAE10[D_002C1EA0];
//     func_001109A8();
//     func_001250D0(D_002DECE0, D_002DECF0);
//     D_004FAF90 = 0;
//     return 0;
// }

s32 func_00125558(void) {
    sceVu0CopyMatrix(D_002DEC60, D_004FAE90[D_002C1EA0 ^ 1]);
    sceVu0CopyMatrix(D_002DEC20, D_004FAE10[D_002C1EA0 ^ 1]);
    sceVu0CopyMatrix(D_002DECA0, D_004FAF10[D_002C1EA0 ^ 1]);
    func_00110A30();
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/xpeanut", func_001255F8);
