#include "ppp.h"

void pppKeThResCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeThResHd_Init(&pobj->val[ctbl->useVal[0]], 1, 3);
}
