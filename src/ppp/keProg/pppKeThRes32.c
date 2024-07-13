#include "ppp.h"

void pppKeThRes32Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeThResHd_Init(&pobj->val[ctbl->useVal[0]], 1, 32);
}
