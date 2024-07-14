#include "ppp.h"

void pppKeThRes64x16Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeThResHd_Init(&pobj->val[ctbl->useVal[0]], 16, 64);
}
