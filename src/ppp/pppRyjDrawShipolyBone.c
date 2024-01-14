#include "ppp.h"

s32 D_006105A4;

typedef struct {
    /* 0x00 */ u32 unFrameCt;
    /* 0x04 */ u8 bSmp;
    /* 0x05 */ u8 bStandby;
    /* 0x06 */ char dummy0[2];
    /* 0x08 */ sceVu0FVECTOR* pvecSmp;
    /* 0x0C */ char dummy1[4];
    /* 0x10 */ f32 avecBonePos[2][4];
} VRyjDrawShipolyBone;

void pppRyjDrawShipolyBoneCalc(void) {
}

INCLUDE_ASM(const s32, "ppp/pppRyjDrawShipolyBone", func_0019D100);

INCLUDE_ASM(const s32, "ppp/pppRyjDrawShipolyBone", pppRyjDrawShipolyBoneDraw);

void pppRyjDrawShipolyBoneCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjDrawShipolyBone* p = (VRyjDrawShipolyBone*)&pobj->val[ctbl->useVal[1]];

    p->unFrameCt = 0;
    p->bSmp = 0;
    p->bStandby = 1;
    p->pvecSmp = NULL;
    ppvMng->unk_B3 = 1;
}

void pppRyjDrawShipolyBoneDes(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjDrawShipolyBone* p = (VRyjDrawShipolyBone*)&pobj->val[ctbl->useVal[1]];

    if (p->pvecSmp != NULL) {
        pppFree(ppvEnv, p->pvecSmp);
        p->pvecSmp = NULL;
    }
}

INCLUDE_ASM(const s32, "ppp/pppRyjDrawShipolyBone", func_0019D798);

INCLUDE_ASM(const s32, "ppp/pppRyjDrawShipolyBone", func_0019D7E0);

INCLUDE_ASM(const s32, "ppp/pppRyjDrawShipolyBone", func_0019D840);

INCLUDE_ASM(const s32, "ppp/pppRyjDrawShipolyBone", func_0019D898);

INCLUDE_ASM(const s32, "ppp/pppRyjDrawShipolyBone", func_0019E520);

INCLUDE_ASM(const s32, "ppp/pppRyjDrawShipolyBone", func_0019E8B0);
