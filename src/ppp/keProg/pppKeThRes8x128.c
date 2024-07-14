#include "ppp.h"

void pppKeThRes8x128Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeThResHd_Init(&pobj->val[ctbl->useVal[0]], 128, 8);
}
