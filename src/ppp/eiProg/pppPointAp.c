#include "ppp.h"

typedef struct {
    /* 0x0 */ u8 faps;
    /* 0x1 */ u8 aptct;
} VPointAp;

void pppPointApCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    ((VPointAp*)&pobj->val[ctbl->useVal[1]])->aptct = 0;
}

INCLUDE_ASM("asm/nonmatchings/ppp/eiProg/pppPointAp", pppPointApCalc);
