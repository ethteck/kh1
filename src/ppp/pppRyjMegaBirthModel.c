#include "ppp.h"

typedef struct {
    /* 0x00 */ pppFVECTOR vecForce;
    /* 0x10 */ char unk_10[0x4];
    /* 0x14 */ void* pvParticleData;
    /* 0x18 */ void* pvParticleWmat;
    /* 0x1C */ void* pvParticleColor;
    /* 0x20 */ u32 nParticle;
    /* 0x24 */ u16 ushTimingCt;
    /* 0x26 */ u16 ushIct;
} VRyjMegaBirthModel;

INCLUDE_ASM(const s32, "ppp/pppRyjMegaBirthModel", pppRyjMegaBirthModelCalc);

INCLUDE_ASM(const s32, "ppp/pppRyjMegaBirthModel", func_001A26D0);

INCLUDE_ASM(const s32, "ppp/pppRyjMegaBirthModel", func_001A2798);

INCLUDE_ASM(const s32, "ppp/pppRyjMegaBirthModel", pppRyjMegaBirthModelDraw);

INCLUDE_ASM(const s32, "ppp/pppRyjMegaBirthModel", pppRyjMegaBirthModelCon);

void pppRyjMegaBirthModelDes(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjMegaBirthModel* v = (VRyjMegaBirthModel*)&pobj->val[ctbl->useVal[2]];
    
    if (v->pvParticleData != NULL) {
        pppFree(ppvEnv, v->pvParticleData);
        v->pvParticleData = NULL;
    }
    if (v->pvParticleWmat != NULL) {
        pppFree(ppvEnv, v->pvParticleWmat);
        v->pvParticleWmat = NULL;
    }
    if (v->pvParticleColor != NULL) {
        pppFree(ppvEnv, v->pvParticleColor);
        v->pvParticleColor = NULL;
    }
}

INCLUDE_ASM(const s32, "ppp/pppRyjMegaBirthModel", func_001A2F20);
