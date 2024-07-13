#include "ppp.h"

typedef struct {
    /* 0x00 */ u32 unShapeNum;
    /* 0x04 */ u32 unModelNum;
    /* 0x08 */ u32 unLampNum;
    /* 0x0C */ void* pvShape;
    /* 0x10 */ void* pvModel;
    /* 0x14 */ void* pvLamp;
} VRyjMegaPlace;

INCLUDE_ASM(const s32, "ppp/ryjProg/pppRyjMegaPlace", pppRyjMegaPlaceCalc);

INCLUDE_ASM(const s32, "ppp/ryjProg/pppRyjMegaPlace", func_001A0140);

INCLUDE_ASM(const s32, "ppp/ryjProg/pppRyjMegaPlace", func_001A0460);

INCLUDE_ASM(const s32, "ppp/ryjProg/pppRyjMegaPlace", func_001A07A8);

INCLUDE_ASM(const s32, "ppp/ryjProg/pppRyjMegaPlace", pppRyjMegaPlaceDraw);

INCLUDE_ASM(const s32, "ppp/ryjProg/pppRyjMegaPlace", pppRyjMegaPlaceCon);

void pppRyjMegaPlaceDes(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjMegaPlace* v = (VRyjMegaPlace*)&pobj->val[ctbl->useVal[0]];

    if (v->pvShape != NULL) {
        pppFree(ppvEnv, v->pvShape);
        v->pvShape = NULL;
    }
    if (v->pvModel != NULL) {
        pppFree(ppvEnv, v->pvModel);
        v->pvModel = NULL;
    }
    if (v->pvLamp != NULL) {
        pppFree(ppvEnv, v->pvLamp);
        v->pvLamp = NULL;
    }
}
