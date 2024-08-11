#include "ppp.h"

typedef struct {
    /* 0x0 */ f32 inp;
    /* 0x4 */ f32 dinp;
    /* 0x8 */ f32 ddinp;
    /* 0xC */ pppFVECTOR* lpvt;
} VVtMime;

INCLUDE_ASM("asm/nonmatchings/ppp/eiProg/pppVtMime", pppVtMimeCalc);

INCLUDE_ASM("asm/nonmatchings/ppp/eiProg/pppVtMime", pppVtMimeDraw);

void pppVtMimeCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VVtMime* v = (VVtMime*)&pobj->val[ctbl->useVal[0]];

    v->lpvt = NULL;
    v->inp = v->dinp = v->ddinp = 0;
}

void pppVtMimeCon2(pppPObject* pobj, pppCtrlTable* ctbl) {
    VVtMime* v = (VVtMime*)&pobj->val[ctbl->useVal[0]];

    v->inp = v->dinp = v->ddinp = 0;
}

void pppVtMimeDes(pppPObject* pobj, pppCtrlTable* ctbl) {
    VVtMime* v = (VVtMime*)&pobj->val[ctbl->useVal[0]];

    if (v->lpvt != NULL) {
        pppFree(ppvEnv, v->lpvt);
        v->lpvt = NULL;
    }
}
