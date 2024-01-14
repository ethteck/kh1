#include "ppp.h"

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ pppFVECTOR m_scl;
} PPointLoop;

typedef struct {
    /* 0x0 */ pppFVECTOR m_scl;
    /* 0xC */ void* m_pp;
} VPointLoop;

void func_0018C410(PPointLoop* p, VPointLoop* ac) {
    ac->m_pp = p;
    ac->m_scl.x = ac->m_scl.y = ac->m_scl.z = 0.0f;
}

void pppPointLoopCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VPointLoop* ac = (VPointLoop*)&pobj->val[ctbl->useVal[0]];
    ac->m_pp = NULL;
}

void pppPointLoopCon2(pppPObject* pobj, pppCtrlTable* ctbl) {
    VPointLoop* vac = (VPointLoop*)&pobj->val[ctbl->useVal[0]];
    PPointLoop* pac = ((VPointLoop*)&pobj->val[ctbl->useVal[0]])->m_pp;

    vac->m_scl.x -= pac->m_scl.x;
    vac->m_scl.y -= pac->m_scl.y;
    vac->m_scl.z -= pac->m_scl.z;
}

void pppPointLoopCalc(pppPObject* pobj, PPointLoop* p, pppCtrlTable* ctbl) {
    VPointLoop* ac = (VPointLoop*)&pobj->val[ctbl->useVal[0]];

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }

    if (ac->m_pp == NULL) {
        func_0018C410(p, ac);
    }

    if (p->cdt.time == pobj->time) {
        ac->m_scl.x += p->m_scl.x;
        ac->m_scl.y += p->m_scl.y;
        ac->m_scl.z += p->m_scl.z;
    }
}
