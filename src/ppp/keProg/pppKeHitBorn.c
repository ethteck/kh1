#include "ppp.h"

typedef u8 TKeHitBorn_Stt;

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ pppParamPObj bornPt;
    /* 0xC */ u8 cmdContinue;
} PKeHitBorn;

typedef struct {
    /* 0x0 */ TKeHitBorn_Stt stt;
} VKeHitBorn;

INCLUDE_ASM(const s32, "ppp/keProg/pppKeHitBorn", pppKeHitBornCalc);

void pppKeHitBornCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    ((VKeHitBorn*)&pobj->val[ctbl->useVal[2]])->stt = 0;
}
