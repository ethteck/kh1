#include "ppp.h"

void pppKeThRes16x64Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeThResHd_Init(&pobj->val[ctbl->useVal[0]], 64, 16);
}
