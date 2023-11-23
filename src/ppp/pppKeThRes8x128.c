#include "ppp.h"

void pppKeThRes8x128Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    func_001AA960(&pobj->val[ctbl->useVal[0]], 128, 8);
}
