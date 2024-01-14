#include "ppp.h"

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ pppFVECTOR m_scl;
} PScaleLoop;

typedef struct {
    /* 0x0 */ pppFVECTOR m_scl;
    /* 0xC */ void* m_pp;
} VScaleLoop;

void func_0018C6A0(PScaleLoop* p, VScaleLoop* ac) {
    ac->m_pp = p;
    ac->m_scl.x = ac->m_scl.y = ac->m_scl.z = 0.0f;
}

void pppScaleLoopCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VScaleLoop* ac = (VScaleLoop*)&pobj->val[ctbl->useVal[0]];
    ac->m_pp = NULL;
}

void pppScaleLoopCon2(pppPObject* pobj, pppCtrlTable* ctbl) {
    VScaleLoop* vac = (VScaleLoop*)&pobj->val[ctbl->useVal[0]];
    PScaleLoop* pac = ((VScaleLoop*)&pobj->val[ctbl->useVal[0]])->m_pp;

    vac->m_scl.x -= pac->m_scl.x;
    vac->m_scl.y -= pac->m_scl.y;
    vac->m_scl.z -= pac->m_scl.z;
}

void pppScaleLoopCalc(pppPObject* pobj, PScaleLoop* p, pppCtrlTable* ctbl) {
    VScaleLoop* ac = (VScaleLoop*)&pobj->val[ctbl->useVal[0]];

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }

    if (ac->m_pp == NULL) {
        func_0018C6A0(p, ac);
    }

    if (p->cdt.time == pobj->time) {
        ac->m_scl.x += p->m_scl.x;
        ac->m_scl.y += p->m_scl.y;
        ac->m_scl.z += p->m_scl.z;
    }
}
