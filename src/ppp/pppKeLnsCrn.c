#include "ppp/pppKeLns.h"

INCLUDE_ASM(const s32, "ppp/pppKeLnsCrn", pppKeLnsCrnDraw);

void pppKeLnsCrnCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeLnsCrn* crn = (KeLnsCrn*)&pobj->val[ctbl->useVal[0]];

    KeLnsCrn_Init(crn);
}

INCLUDE_ASM(const s32, "ppp/pppKeLnsCrn", func_001940F0);
