#include "ppp/pppKeLns.h"

INCLUDE_ASM(const s32, "ppp/pppKeLnsArnd", pppKeLnsArndDraw);

void pppKeLnsArndCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeLnsArnd* arnd = (KeLnsArnd*)&pobj->val[ctbl->useVal[0]];
    
    KeLnsArnd_Init(arnd);
}

INCLUDE_ASM(const s32, "ppp/pppKeLnsArnd", func_00193BC8);
