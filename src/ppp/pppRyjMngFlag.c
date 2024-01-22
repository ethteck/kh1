#include "ppp.h"

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ u8 bFollowCam;
    /* 0x5 */ u8 bStop;
    /* 0x6 */ u8 bDrawPriority;
} PRyjMngFlag;

void pppRyjMngFlagCalc(pppPObject* pobj, PRyjMngFlag* p, pppCtrlTable* ctbl) {
    if (p->cdt.time == pobj->time) {
        ppvMng->followCam = p->bFollowCam;
        ppvMng->stop = p->bStop;
        ppvMng->drawPriority = p->bDrawPriority;
    }
}

INCLUDE_ASM(const s32, "ppp/pppRyjMngFlag", func_0019F698);

INCLUDE_ASM(const s32, "ppp/pppRyjMngFlag", func_0019F810);
