#ifndef PPP_H
#define PPP

#include "common.h"
#include "ppp/pppEnv.h"
#include "pppfunc.h"

typedef struct {
    /* 0x00 */ char* dpd;
    /* 0x04 */ u32 dpdId;
    /* 0x08 */ s8 blockStart;
    /* 0x11 */ s8 blockNum;
    /* 0x0A */ s8 boolUse;
    /* 0x13 */ s8 res;
} _VRAMCACHE;

typedef struct {
    /* 0x000 */ _VRAMCACHE vramCacheTex[10];
    /* 0x0F0 */ _VRAMCACHE vramCacheClut[6];
} _VRAMCACHE_MNG;

typedef struct _pppPEtcData {
    /* 0x000 */ f32 afBbox[32];
    /* 0x080 */ f32 vecOffset[4];
    /* 0x090 */ s32 ivecAngle[4];
    /* 0x0A0 */ f32 vecScale[4];
    /* 0x0B0 */ u8 abUseTexture[16];
    /* 0x0C0 */ u8 abUseShape[16];
    /* 0x0D0 */ u8 abUseRsd[16];
    /* 0x0E0 */ u8 abUseVsf[16];
    /* 0x0F0 */ s32 nWorkMemSize;
    /* 0x0F4 */ s32 nPacketMemSize;
    /* 0x0F8 */ u8 viewClipStop;
    /* 0x0F9 */ u8 chrScale;
    /* 0x0FA */ u8 bindPosOnly;
    /* 0x0FB */ u8 nonAmbient;
    /* 0x0FC */ s16 seNo;
    /* 0x0FE */ s16 seVolAdd;
    /* 0x100 */ f32 seWait;
    /* 0x104 */ s32 boneNo;
    /* 0x108 */ s32 wait;
    /* 0x10C */ s32 res;
} pppPEtcData;

typedef struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 colorR;
    /* 0x34 */ f32 colorG;
    /* 0x38 */ f32 colorB;
    /* 0x3C */ f32 colorA;
    /* 0x40 */ f32 scaleX;
    /* 0x44 */ f32 scaleY;
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ char unk_50[0x24];
    /* 0x74 */ pppPObject* unk_74;
    /* 0x78 */ char unk_78[0x8];
    /* 0x80 */ s32 unk_80;
    /* 0x84 */ char unk_84[0x2];
    /* 0x86 */ s16 usef;
    /* 0x88 */ char* pchDpd;
    /* 0x8C */ pppPEtcData* pEtc;
    /* 0x90 */ char unk_90;
    /* 0x91 */ u8 unk_91;
    /* 0x91 */ u8 unk_92;
    /* 0x92 */ char unk_93[0x5];
    /* 0x98 */ s32 unk_98;
    /* 0x9C */ void* unk_9C;
    /* 0xA0 */ char unk_A0[4];
    /* 0xA4 */ s16 texpStart;
    /* 0xA6 */ s16 clutpStart;
    /* 0xA8 */ char unk_A8[0x8];
    /* 0xB0 */ u8 drawPriority;
    /* 0xB1 */ u8 stop;
    /* 0xB2 */ u8 followCam;
    /* 0xB3 */ u8 unk_B3;
    /* 0xB4 */ u8 unk_B4;
    /* 0xB5 */ u8 unk_B5;
    /* 0xB6 */ u8 unk_B6;
    /* 0xB7 */ u8 unk_B7;
    /* 0xB8 */ u64 unk_B8;
} ppvmng; // size= 0xC0

extern sceVu0FVECTOR ppvParScl;

// todo: find what this is, maybe KeLnsLp, but used extensively for non-KeLns stuff
// symbol name is possibly a debug thing from 2.5 proto and will need renamed here
extern UNK_TYPE ppvDbgTemp; 

typedef void (*pppDrawFunc)(pppPObject* pobj, s32 param);

extern ppvmng* ppvMng;
extern pppPObject ppvPObj;
extern sceVu0FVECTOR ppvEye;
extern sceVu0FVECTOR ppvAt;
extern sceVu0FMATRIX ppvWorldMatrix;
extern sceVu0FMATRIX ppvWorldMatrixWood;
extern sceVu0FMATRIX ppvScreenMatrix;
extern sceVu0FMATRIX ppvSWMatrix;
extern sceVu0FMATRIX ppvSWMatrixWood;
extern sceVu0FMATRIX ppvUnitMatrix;
extern sceVu0FVECTOR ppvZeroVector;
extern s32 ppvUserStopPartF;
extern pppDrawFunc* ppvHookFuncTbl;
extern s32 ppvEmptyLoop;
extern sceVu0FMATRIX g_matUnit;
extern sceVu0FMATRIX KeDMat;
extern sceVu0FMATRIX KeMatPht;


#endif /* PPP_H */
