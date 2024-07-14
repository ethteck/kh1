#include "common.h"
#include "pppfunc.h"

typedef struct {
    /* 0x00 */ s32 flag;
    /* 0x04 */ s32 pa;
    /* 0x08 */ s32 va;
    /* 0x0C */ s32 na;
    /* 0x10 */ u16 pc;
    /* 0x12 */ u16 vc;
    /* 0x14 */ u16 nc;
    /* 0x16 */ u8 alpha;
    /* 0x17 */ u8 alphaFix;
    /* 0x18 */ u16 res[2];
    /* 0x1C */ s32 vna;
} OMD_H;

typedef struct _pppEMCB {
    /* 0x00 */ struct _pppEMCB* next;
    /* 0x04 */ struct _pppEMCB* prev;
    /* 0x08 */ s32 owner;
    /* 0x0C */ s32 wdummy;
} pppEMCB;

typedef struct {
    /* 0x00 */ pppEMCB* lastFreeHeap;
    /* 0x04 */ pppEMCB* effectHeapTop;
    /* 0x08 */ pppEMCB* effectHeapBottom;
    /* 0x0C */ s32 allocSize;
} pppMemMng;

typedef struct {
    /* 0x00 */ s32 nvert;
    /* 0x04 */ s32 nnorm;
    /* 0x08 */ s32 npoly;
    /* 0x0C */ s32 tex0l;
    /* 0x10 */ s32 tex0h;
    /* 0x14 */ pppSVECTOR* vert;
    /* 0x18 */ pppSVECTOR* norm;
    /* 0x1C */ OMD_H* omd;
    /* 0x20 */ s32 nPacketSize;
} pppModelSt;

typedef struct {
    /* 0x0 */ u_long128* shape;
    /* 0x4 */ s32 nPacketSize;
} pppShapeSt;

typedef struct {
    /* 0x0 */ u16 modelNo;
    /* 0x2 */ u16 indexN;
    /* 0x4 */ s16* index;
} pppVsfSt;

typedef struct {
    /* 0x00 */ pppMemMng heapMng;
    /* 0x10 */ pppModelSt* lpModel;
    /* 0x14 */ pppShapeSt* lpShape;
    /* 0x18 */ pppVsfSt* lpVsf;
} pppEnvSt;

extern pppEnvSt g_Env;
extern pppEnvSt* ppvEnv;
