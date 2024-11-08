#include "ppp.h"

#include "gcc/math.h"

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ s32 m_model;
    /* 0x08 */ f32 m_tu;
    /* 0x0C */ f32 m_dtu;
    /* 0x10 */ f32 m_ddtu;
    /* 0x14 */ f32 m_tv;
    /* 0x18 */ f32 m_dtv;
    /* 0x1C */ f32 m_ddtv;
    /* 0x20 */ u8 m_acalc;
    /* 0x21 */ u8 m_afix;
    /* 0x22 */ u8 m_draw;
    /* 0x23 */ u8 m_fog;
    /* 0x24 */ u8 m_near;
    /* 0x25 */ u8 m_scis;
} PDrawMdlLoopZ;

typedef struct {
    /* 0x0 */ void* m_pp;
    /* 0x4 */ f32 m_tu;
    /* 0x8 */ f32 m_dtu;
    /* 0xC */ f32 m_ddtu;
    /* 0x10 */ f32 m_tv;
    /* 0x14 */ f32 m_dtv;
    /* 0x18 */ f32 m_ddtv;
    /* 0x1C */ f32 m_uv;
} VDrawMdlLoopZ;

INCLUDE_ASM("asm/nonmatchings/ppp/eiProg/pppDrawMdlLoopZ", func_0018CC58);

void pppDrawMdlLoopZCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    ((VDrawMdlLoopZ*)&pobj->val[ctbl->useVal[2]])->m_pp = NULL;
}

void pppDrawMdlLoopZCon2(pppPObject* pobj, pppCtrlTable* ctbl) {
    VDrawMdlLoopZ* vmdl = (VDrawMdlLoopZ*)&pobj->val[ctbl->useVal[2]];

    vmdl->m_dtu = vmdl->m_ddtu = vmdl->m_dtv = vmdl->m_ddtv = 0;
}

void pppDrawMdlLoopZDes(void) {
}

void pppDrawMdlLoopZCalc(pppPObject* pobj, PDrawMdlLoopZ* p, pppCtrlTable* ctbl) {
    VDrawMdlLoopZ* vmdl = (VDrawMdlLoopZ*)&pobj->val[ctbl->useVal[2]];
    PDrawMdlLoopZ* pmdl = (PDrawMdlLoopZ*)&pobj->val[ctbl->useVal[2]];

    if (vmdl->m_pp == NULL) {
        func_0018CC58(p, vmdl);
    }

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }

    if (p->cdt.time == pobj->time) {
        pmdl->m_tu += p->m_dtu;
        pmdl->m_dtu += p->m_ddtu;
        pmdl->m_tv += p->m_dtv;
        pmdl->m_dtv += p->m_ddtv;
    }

    if (!ppvEmptyLoop) {
        vmdl->m_dtu += vmdl->m_ddtu;
        vmdl->m_dtv += vmdl->m_ddtv;
        vmdl->m_tu += vmdl->m_dtu;
        vmdl->m_tv += vmdl->m_dtv;
        vmdl->m_tu = fmodf(vmdl->m_tu, 32768.0f);
        vmdl->m_tv = fmodf(vmdl->m_tv, 32768.0f);
    }
}

INCLUDE_ASM("asm/nonmatchings/ppp/eiProg/pppDrawMdlLoopZ", pppDrawMdlLoopZDraw);
