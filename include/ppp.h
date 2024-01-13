#ifndef PPP_H
#define PPP

#include "common.h"
#include "pppfunc.h"

#include "sdk/ee/libvu0.h"

typedef struct {
    /* 0x00 */ u8 unk_00[0x40];
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ u8 unk_48[104];
    /* 0xB0 */ u8 unk_B0;
    /* 0xB1 */ u8 unk_B1;
    /* 0xB2 */ u8 unk_B2;
    /* 0xB3 */ u8 unk_B3;
    /* 0xB4 */ u8 unk_B4;
    /* 0xB5 */ u8 unk_B5;
    /* 0xB6 */ u8 unk_B6;
    /* 0xB7 */ u8 unk_B7;
    /* 0xB8 */ u64 unk_B8;
} ppvmng; // size=?

extern sceVu0FVECTOR ppvParScl;

extern ppvmng* ppvMng;
extern pppPObject ppvPObj;
extern sceVu0FMATRIX ppvWorldMatrix;
extern sceVu0FMATRIX ppvWorldMatrixWood;
extern sceVu0FMATRIX ppvScreenMatrix;
extern sceVu0FMATRIX ppvSWMatrix;
extern s32 ppvUserStopPartF;
extern s32 ppvEmptyLoop;
extern sceVu0FMATRIX KeDMat;
extern sceVu0FMATRIX KeMatPht;


#endif /* PPP_H */
