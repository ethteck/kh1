#include "ppp.h"

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ pppFVECTOR Drct;
} PKeDrct;

typedef struct {
    /* 0x0 */ pppFVECTOR Drct;
} VKeDrct;

void pppKeDrctCalc(pppPObject* pobj, PKeDrct* p, pppCtrlTable* ctbl) {
    VKeDrct* v;

    if (pobj->time == p->cdt.time) {
        v = (VKeDrct*)&pobj->val[ctbl->useVal[0]];
        v->Drct.x = p->Drct.x;
        v->Drct.y = p->Drct.y;
        v->Drct.z = p->Drct.z;
    } 
}

void pppKeDrctCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    ((PKeDrct*)&pobj->val[ctbl->useVal[0]])->Drct.z = 1.0f;
}
