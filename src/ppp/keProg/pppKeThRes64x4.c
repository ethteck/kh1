#include "ppp.h"

void pppKeThRes64x4Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeThResHd_Init(&pobj->val[ctbl->useVal[0]], 4, 64);
}
