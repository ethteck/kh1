#ifndef PPPKELNS_H
#define PPPKELNS_H

#include "common.h"
#include "ppp.h"

// todo: relocate this once we have a better idea of what it is
typedef struct {
    /* 0x0 */ u_long128* shape;
    /* 0x4 */ s32 nPacketSize;
} pppShapeSt;

typedef struct {
    /* 0x00 */ FMATRIX mat;
    /* 0x40 */ f32 zMat[3][4];
    /* 0x70 */ f32 vec[2];
    /* 0x78 */ f32 pers;
    /* 0x7C */ f32 vPow;
    /* 0x80 */ f32 lcPos[3];
    /* 0x8C */ u8 idx;
    /* 0x8D */ u8 mbk;
    /* 0x8E */ u8 r;
    /* 0x8F */ u8 md;
    /* 0x90 */ sceVu0FVECTOR lVec;
    /* 0xA0 */ f32 _p2[1];
    /* 0xA4 */ f32 len2;
    /* 0xA8 */ f32 pow;
    /* 0xAC */ f32 preHidePow;
} KeLnsLp; // size = 0xB0

typedef struct {
    /* 0x0 */ s16 cnt;
    /* 0x2 */ u8 seqIdx;
    /* 0x3 */ char flag[1];
} KeLnsFlr; // size = 0x4

typedef struct {
    /* 0x0 */ KeLnsFlr* lp;
    /* 0x4 */ pppShapeSt* shp;
    /* 0x8 */ KeLnsFlr flr;
} KeLnsArnd; // size = 0xC

typedef struct {
    /* 0x0 */ KeLnsFlr* lp;
    /* 0x4 */ pppShapeSt* shp;
    /* 0x8 */ KeLnsFlr flr;
} KeLnsCrn; // size = 0xC

typedef struct {
    /* 0x0 */ KeLnsFlr* lp;
    /* 0x4 */ pppShapeSt* shp;
    /* 0x8 */ KeLnsFlr flr;
} KeLnsFls; // size = 0xC

typedef struct {
    /* 0x0 */ KeLnsFlr flr;
    /* 0x4 */ f32 rdPr;
} KeLnsClmFlr; // size = 0x8

typedef struct {
    /* 0x00 */ KeLnsLp* lp;
    /* 0x04 */ pppShapeSt* shp;
    /* 0x08 */ u8 num;
    /* 0x09 */ u8 flag;
    /* 0x0A */ s16 betw;
    /* 0x0C */ s16 stOfs;
    /* 0x0E */ u8 flagType;
    /* 0x0F */ char _p0[1];
    /* 0x10 */ KeLnsClmFlr flr[1];
} KeLnsClm; // size = 0x18

void KeLnsLp_Init(KeLnsLp*);
void KeLnsClm_Init(KeLnsClm*);
void KeLnsArnd_Init(KeLnsArnd*);
void KeLnsCrn_Init(KeLnsCrn*);
void KeLnsFls_Init(KeLnsFls*);

#endif // PPPKELNS_H
