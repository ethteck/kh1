#include "ppp.h"

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ s32 param;
} PDrawHook;

typedef struct {
    /* 0x0 */ s32 param;
} VDrawHook;

void pppDrawHookDraw(pppPObject* pobj, PDrawHook* p, pppCtrlTable* ctbl) {
    pppDrawFunc func;
    
    ((VDrawHook*)&pobj->val[ctbl->useVal[0]])->param = p->param;

    if (ppvHookFuncTbl != NULL) {
        func = ppvHookFuncTbl[pobj->pdtval->pdtno];
        if (func != NULL) {
            func(pobj, p->param);
        }
    }
}
