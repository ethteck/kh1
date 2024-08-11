#include "ppp.h"

typedef struct {
    /* 0x00 */ void* pvParticleData;
    /* 0x04 */ void* pvParticleColor;
    /* 0x08 */ u32 nParticle;
    /* 0x0C */ f32 fAlphaScale;
    /* 0x10 */ u16 ushTimingCt;
    /* 0x12 */ u8 bActive;
} VRyjMegaBirthModelFilter; // size = 0x14

sceVu0FVECTOR g_vecCamDirM;

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaBirthModelFilter", pppRyjMegaBirthModelFilterCalc);

void func_001A69A8(void) {
}

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaBirthModelFilter", func_001A69B0);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaBirthModelFilter", pppRyjMegaBirthModelFilterDraw);

void pppRyjMegaBirthModelFilterSta(void) {
    sceVu0SubVector(g_vecCamDirM, ppvAt, ppvEye);
    sceVu0Normalize(g_vecCamDirM, g_vecCamDirM);
    g_vecCamDirM[3] = 1.0f;
}

void pppRyjMegaBirthModelFilterCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjMegaBirthModelFilter* v = (VRyjMegaBirthModelFilter*)&pobj->val[ctbl->useVal[2]];

    v->pvParticleData = NULL;
    v->pvParticleColor = NULL;
    v->nParticle = 0;
    v->fAlphaScale = 1.0f;
    v->ushTimingCt = 0;
    v->bActive = 1;
    
    ppvMng->unk_B3 = 1;
}

void pppRyjMegaBirthModelFilterDes(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjMegaBirthModelFilter* v = (VRyjMegaBirthModelFilter*)&pobj->val[ctbl->useVal[2]];

    if (v->pvParticleData != NULL) {
        pppFree(ppvEnv, v->pvParticleData);
        v->pvParticleData = NULL;
    }
    if (v->pvParticleColor != NULL) {
        pppFree(ppvEnv, v->pvParticleColor);
        v->pvParticleColor = NULL;
    }
}
