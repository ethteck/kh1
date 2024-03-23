#include "ppp.h"

typedef struct {
    /* 0x00 */ void* pvParticleData;
    /* 0x04 */ void* pvParticleColor;
    /* 0x08 */ u32 nParticle;
    /* 0x0C */ f32 fAlphaScale;
    /* 0x10 */ u16 ushTimingCt;
    /* 0x12 */ u8 bActive;
} VRyjMegaBirthFilter;

sceVu0FVECTOR g_vecCamDir;

INCLUDE_ASM(const s32, "ppp/pppRyjMegaBirthFilter", pppRyjMegaBirthFilterCalc);

void func_001A4F70(void) {
}

INCLUDE_ASM(const s32, "ppp/pppRyjMegaBirthFilter", func_001A4F78);

INCLUDE_ASM(const s32, "ppp/pppRyjMegaBirthFilter", pppRyjMegaBirthFilterDraw);

// INCLUDE_ASM(const s32, "ppp/pppRyjMegaBirthFilter", pppRyjMegaBirthFilterSta);
void pppRyjMegaBirthFilterSta(void) {
    sceVu0SubVector(g_vecCamDir, ppvAt, ppvEye);
    sceVu0Normalize(g_vecCamDir, g_vecCamDir);
    g_vecCamDir[3] = 1.0f;
}

void pppRyjMegaBirthFilterCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjMegaBirthFilter* v = (VRyjMegaBirthFilter*)&pobj->val[ctbl->useVal[2]];
    
    v->pvParticleData = NULL;
    v->pvParticleColor = NULL;
    v->nParticle = 0;
    v->fAlphaScale = 1.0f;
    v->ushTimingCt = 0;
    v->bActive = TRUE;
    ppvMng->unk_B3 = 1;
}

void pppRyjMegaBirthFilterDes(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjMegaBirthFilter* v = (VRyjMegaBirthFilter*)&pobj->val[ctbl->useVal[2]];
    
    if (v->pvParticleData != NULL) {
        pppFree(ppvEnv, v->pvParticleData);
        v->pvParticleData = NULL;
    }
    if (v->pvParticleColor != NULL) {
        pppFree(ppvEnv, v->pvParticleColor);
        v->pvParticleColor = NULL;
    }
}

INCLUDE_ASM(const s32, "ppp/pppRyjMegaBirthFilter", func_001A5500);

INCLUDE_ASM(const s32, "ppp/pppRyjMegaBirthFilter", func_001A5548);

INCLUDE_ASM(const s32, "ppp/pppRyjMegaBirthFilter", func_001A55A8);

INCLUDE_ASM(const s32, "ppp/pppRyjMegaBirthFilter", func_001A55D8);

INCLUDE_ASM(const s32, "ppp/pppRyjMegaBirthFilter", func_001A5EF8);

INCLUDE_ASM(const s32, "ppp/pppRyjMegaBirthFilter", func_001A6040);

INCLUDE_ASM(const s32, "ppp/pppRyjMegaBirthFilter", func_001A66B0);
