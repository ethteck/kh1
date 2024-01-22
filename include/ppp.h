#ifndef PPP_H
#define PPP

#include "common.h"
#include "pppfunc.h"

#include "sdk/ee/libvu0.h"

typedef struct {
    /* 0x00 */ char unk_00[0x30];
    /* 0x30 */ f32 colorR;
    /* 0x34 */ f32 colorG;
    /* 0x38 */ f32 colorB;
    /* 0x3C */ f32 colorA;
    /* 0x40 */ f32 scaleX;
    /* 0x44 */ f32 scaleY;
    /* 0x48 */ char unk_48[0x68];
    /* 0xB0 */ u8 drawPriority;
    /* 0xB1 */ u8 stop;
    /* 0xB2 */ u8 followCam;
    /* 0xB3 */ u8 unk_B3;
    /* 0xB4 */ u8 unk_B4;
    /* 0xB5 */ u8 unk_B5;
    /* 0xB6 */ u8 unk_B6;
    /* 0xB7 */ u8 unk_B7;
    /* 0xB8 */ u64 unk_B8;
} ppvmng; // size=?

extern sceVu0FVECTOR ppvParScl;

extern ppvmng* ppvMng;
extern void* ppvEnv;
extern pppPObject ppvPObj;
extern sceVu0FVECTOR ppvEye;
extern sceVu0FVECTOR ppvAt;
extern sceVu0FMATRIX ppvWorldMatrix;
extern sceVu0FMATRIX ppvWorldMatrixWood;
extern sceVu0FMATRIX ppvScreenMatrix;
extern sceVu0FMATRIX ppvSWMatrix;
extern s32 ppvUserStopPartF;
extern s32 ppvEmptyLoop;
extern sceVu0FMATRIX g_matUnit;
extern sceVu0FMATRIX KeDMat;
extern sceVu0FMATRIX KeMatPht;


#endif /* PPP_H */
