#include "ppp.h"

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ pppIVECTOR m_dang;
} PAngMove;

typedef struct {
    /* 0x4 */ pppIVECTOR m_dang;
} VAngMove;

void pppAngMoveCalc(pppPObject* pobj, PAngMove* p, pppCtrlTable* ctbl) {
    VAngMove* ac0 = (VAngMove*)&pobj->val[ctbl->useVal[0]];
    VAngMove* ac1 = (VAngMove*)&pobj->val[ctbl->useVal[1]];

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }

    if (p->cdt.time == pobj->time) {
        ac1->m_dang.x += p->m_dang.x;
        ac1->m_dang.y += p->m_dang.y;
        ac1->m_dang.z += p->m_dang.z;
    }

    ac0->m_dang.x += ac1->m_dang.x;
    ac0->m_dang.y += ac1->m_dang.y;
    ac0->m_dang.z += ac1->m_dang.z;
}

void pppAngMoveCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VAngMove* ac = (VAngMove*)&pobj->val[ctbl->useVal[1]];
    ac->m_dang.x = ac->m_dang.y = ac->m_dang.z = 0;
}
