#include "ppp.h"

void pppKeThRes255x4Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeThResHd_Init(&pobj->val[ctbl->useVal[0]], 4, 255);
}
