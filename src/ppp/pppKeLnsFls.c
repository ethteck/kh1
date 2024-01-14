#include "ppp.h"

INCLUDE_ASM(const s32, "ppp/pppKeLnsFls", pppKeLnsFlsDraw);

void pppKeLnsFlsCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeLnsFls_Init(&pobj->val[ctbl->useVal[0]]);
}

INCLUDE_ASM(const s32, "ppp/pppKeLnsFls", func_00194350);
