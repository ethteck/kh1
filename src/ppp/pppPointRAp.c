#include "ppp.h"

typedef struct {
    /* 0x0 */ u8 faps;
    /* 0x1 */ u8 aptct;
} VPointRAp;

void pppPointRApCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    ((VPointRAp*)&pobj->val[ctbl->useVal[1]])->aptct = 0;
}

INCLUDE_ASM(const s32, "ppp/pppPointRAp", pppPointRApCalc);
