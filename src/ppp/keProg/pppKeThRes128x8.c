#include "ppp.h"

void pppKeThRes128x8Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeThResHd_Init(&pobj->val[ctbl->useVal[0]], 8, 128);
}
