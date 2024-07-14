#include "ppp.h"

typedef struct {
    /* 0x0 */ u32 unFrameCt;
    /* 0x4 */ u8 bSmp;
    /* 0x5 */ u8 bStandby;
    /* 0x6 */ char dummy0[2];
    /* 0x8 */ pppFVECTOR* pvecSmp;
} VRyjDrawShipoly;

INCLUDE_ASM(const s32, "ppp/ryjProg/pppRyjDrawShipoly", pppRyjDrawShipolyCalc);

INCLUDE_ASM(const s32, "ppp/ryjProg/pppRyjDrawShipoly", pppRyjDrawShipolyDraw);

void pppRyjDrawShipolyCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjDrawShipoly* p = (VRyjDrawShipoly*)&pobj->val[ctbl->useVal[2]];
    p->pvecSmp = NULL;
    p->unFrameCt = 0;
    p->bSmp = FALSE;
    p->bStandby = TRUE;
}

void pppRyjDrawShipolyDes(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjDrawShipoly* p = (VRyjDrawShipoly*)&pobj->val[ctbl->useVal[2]];

    if (p->pvecSmp != NULL) {
        pppFree(ppvEnv, p->pvecSmp);
        p->pvecSmp = NULL;
    }
}

INCLUDE_ASM(const s32, "ppp/ryjProg/pppRyjDrawShipoly", func_0019C460);

INCLUDE_ASM(const s32, "ppp/ryjProg/pppRyjDrawShipoly", func_0019C618);

INCLUDE_ASM(const s32, "ppp/ryjProg/pppRyjDrawShipoly", func_0019C698);

INCLUDE_ASM(const s32, "ppp/ryjProg/pppRyjDrawShipoly", func_0019C770);
