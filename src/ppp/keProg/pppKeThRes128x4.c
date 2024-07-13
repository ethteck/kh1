#include "ppp.h"

void pppKeThRes128x4Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeThResHd_Init(&pobj->val[ctbl->useVal[0]], 4, 128);
}
