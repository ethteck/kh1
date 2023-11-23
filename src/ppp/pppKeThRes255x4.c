#include "ppp.h"

void pppKeThRes255x4Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    func_001AA960(&pobj->val[ctbl->useVal[0]], 4, 255);
}
