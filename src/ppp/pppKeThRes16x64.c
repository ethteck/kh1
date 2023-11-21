#include "ppp.h"

void pppKeThRes16x64Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    func_001AA960(&pobj->val[ctbl->useVal[0]], 64, 16);
}
