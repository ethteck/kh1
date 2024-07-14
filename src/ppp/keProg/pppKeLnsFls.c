#include "ppp/pppKeLns.h"

INCLUDE_ASM(const s32, "ppp/keProg/pppKeLnsFls", pppKeLnsFlsDraw);

void pppKeLnsFlsCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeLnsFls* fls = (KeLnsFls*)&pobj->val[ctbl->useVal[0]];
    
    KeLnsFls_Init(fls);
}

INCLUDE_ASM(const s32, "ppp/keProg/pppKeLnsFls", func_00194350);
