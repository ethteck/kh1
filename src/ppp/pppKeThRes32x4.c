#include "ppp.h"

void pppKeThRes32x4Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeThResHd_Init(&pobj->val[ctbl->useVal[0]], 4, 32);
}
