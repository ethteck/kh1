#include "ppp.h"

void pppKeThRes128x8Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    func_001AA960(&pobj->val[ctbl->useVal[0]], 8, 128);
}
