#include "ppp.h"

void pppKeThRes32x32Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeThResHd_Init(&pobj->val[ctbl->useVal[0]], 32, 32);
}
