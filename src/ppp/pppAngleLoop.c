#include "ppp.h"

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ pppIVECTOR m_ang;
} PAngleLoop;

typedef struct {
    /* 0x0 */ pppIVECTOR m_ang;
    /* 0x4 */ void* m_pp;
} VAngleLoop;

void func_0018C558(PAngleLoop* p, VAngleLoop* ac) {
    ac->m_pp = p;
    ac->m_ang.z = ac->m_ang.x = ac->m_ang.y = 0;
}

void pppAngleLoopCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VAngleLoop* ac = (VAngleLoop*)&pobj->val[ctbl->useVal[0]];
    ac->m_pp = NULL;
}

void pppAngleLoopCon2(pppPObject* pobj, pppCtrlTable* ctbl) {
    VAngleLoop* vac = (VAngleLoop*)&pobj->val[ctbl->useVal[0]];
    PAngleLoop* pac = ((VAngleLoop*)&pobj->val[ctbl->useVal[0]])->m_pp;
    
    vac->m_ang.x -= pac->m_ang.x;
    vac->m_ang.y -= pac->m_ang.y;
    vac->m_ang.z -= pac->m_ang.z;
}

void pppAngleLoopCalc(pppPObject* pobj, PAngleLoop* p, pppCtrlTable* ctbl) {
    VAngleLoop* ac = (VAngleLoop*)&pobj->val[ctbl->useVal[0]];

    if (ppvUserStopPartF != 0 || ppvMng->unk_B1 != 0 || ppvMng->unk_B4 != 0) {
        return;
    }

    if (ac->m_pp == NULL) {
        func_0018C558(p, ac);
    }

    if (p->cdt.time == pobj->time) {
        ac->m_ang.x += p->m_ang.x;
        ac->m_ang.y += p->m_ang.y;
        ac->m_ang.z += p->m_ang.z;
    }
}
