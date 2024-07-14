#include "ppp.h"

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ pppHCVECTOR col;
} PColor;

typedef struct {
    /* 0x0 */ pppHCVECTOR col;
    /* 0x8 */ pppCVECTOR release_col;
} VColor;

INCLUDE_ASM(const s32, "ppp/eiProg/pppColor", pppColorCalc);

void pppColorCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VColor* v = (VColor*)&pobj->val[ctbl->useVal[0]];
    
    v->col.r = v->col.g = v->col.b = v->col.a = 0;
}
