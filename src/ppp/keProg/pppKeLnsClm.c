#include "ppp/pppKeLns.h"

INCLUDE_ASM(const s32, "ppp/keProg/pppKeLnsClm", pppKeLnsClmDraw);

void pppKeLnsClmCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeLnsClm* clm = (KeLnsClm*)&pobj->val[ctbl->useVal[0]];
    
    KeLnsClm_Init(clm);
    clm->num = 4;
}

INCLUDE_ASM(const s32, "ppp/keProg/pppKeLnsClm", func_00193E80);
