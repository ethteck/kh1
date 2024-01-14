#include "ppp.h"

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ pppIVECTOR m_dang;
} PAngMoveLoop;

typedef struct {
    /* 0x4 */ pppIVECTOR m_dang;
} VAngMoveLoop;

void pppAngMoveLoopCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VAngMoveLoop* ac = (VAngMoveLoop*)&pobj->val[ctbl->useVal[1]];
    ac->m_dang.x = ac->m_dang.y = ac->m_dang.z = 0;
}

void pppAngMoveLoopCon2(pppPObject* pobj, pppCtrlTable* ctbl) {
    pppAngMoveLoopCon(pobj, ctbl);
}

void pppAngMoveLoopCalc(pppPObject* pobj, PAngMoveLoop* p, pppCtrlTable* ctbl) {
    VAngMoveLoop* ac0 = (VAngMoveLoop*)&pobj->val[ctbl->useVal[0]];
    VAngMoveLoop* ac1 = (VAngMoveLoop*)&pobj->val[ctbl->useVal[1]];

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }

    if (p->cdt.time == pobj->time) {
        ac1->m_dang.x += p->m_dang.x;
        ac1->m_dang.y += p->m_dang.y;
        ac1->m_dang.z += p->m_dang.z;
    }

    if (!ppvEmptyLoop) {
        ac0->m_dang.x += ac1->m_dang.x;
        ac0->m_dang.y += ac1->m_dang.y;
        ac0->m_dang.z += ac1->m_dang.z;
    }
}
