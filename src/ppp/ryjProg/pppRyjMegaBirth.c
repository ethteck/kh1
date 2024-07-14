#include "ppp.h"

typedef struct {
    /* 0x00 */ FMATRIX matPar;
    /* 0x40 */ sceVu0FVECTOR vecForce;
    /* 0x50 */ void* pvParticleData;
    /* 0x54 */ void* pvParticleWmat;
    /* 0x58 */ void* pvParticleColor;
    /* 0x5C */ u32 nParticle;
    /* 0x60 */ u16 ushTimingCt;
    /* 0x62 */ u16 ushIct;
} VRyjMegaBirth;

INCLUDE_ASM(const s32, "ppp/ryjProg/pppRyjMegaBirth", pppRyjMegaBirthCalc);

INCLUDE_ASM(const s32, "ppp/ryjProg/pppRyjMegaBirth", func_0019ECE8);

INCLUDE_ASM(const s32, "ppp/ryjProg/pppRyjMegaBirth", func_0019ED48);

INCLUDE_ASM(const s32, "ppp/ryjProg/pppRyjMegaBirth", pppRyjMegaBirthDraw);

void pppRyjMegaBirthCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjMegaBirth* v = (VRyjMegaBirth*)&pobj->val[ctbl->useVal[2]];

    sceVu0UnitMatrix(v->matPar);
    *(u_long128*)v->vecForce = 0;
    v->pvParticleData = 0;
    v->pvParticleWmat = 0;
    v->pvParticleColor = 0;
    v->nParticle = 0;
    v->ushTimingCt = 0;
    v->ushIct = 0;
    sceVu0UnitMatrix(g_matUnit);
}

void pppRyjMegaBirthDes(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjMegaBirth* data = (VRyjMegaBirth*)&pobj->val[ctbl->useVal[2]];

    if (data->pvParticleData != NULL) {
        pppFree(ppvEnv, data->pvParticleData);
        data->pvParticleData = NULL;
    }
    if (data->pvParticleWmat != NULL) {
        pppFree(ppvEnv, data->pvParticleWmat);
        data->pvParticleWmat = NULL;
    }
    if (data->pvParticleColor != NULL) {
        pppFree(ppvEnv, data->pvParticleColor);
        data->pvParticleColor = NULL;
    }
}
