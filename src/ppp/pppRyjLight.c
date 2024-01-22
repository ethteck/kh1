#include "ppp.h"

/// This file's functions are empty in the 2.5 prototype

typedef struct {
    void* unk_00;
} VRyjLight;

INCLUDE_ASM(const s32, "ppp/pppRyjLight", pppRyjLightCalc);

void pppRyjLightCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    ((VRyjLight*)&pobj->val[ctbl->useVal[2]])->unk_00 = NULL;
}

void pppRyjLightDes(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjLight* ryjLight = (VRyjLight*)&pobj->val[ctbl->useVal[2]];

    if (ryjLight->unk_00 != NULL) {
        func_00122B70(ryjLight->unk_00);
        ryjLight->unk_00 = NULL;
    }
}
