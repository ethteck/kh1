#include "ppp/pppKeLns.h"

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeLnsFls", pppKeLnsFlsDraw);

void pppKeLnsFlsCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeLnsFls* fls = (KeLnsFls*)&pobj->val[ctbl->useVal[0]];
    
    KeLnsFls_Init(fls);
}

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeLnsFls", func_00194350);
