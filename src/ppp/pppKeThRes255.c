#include "ppp.h"

void pppKeThRes255Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    func_001AA960(&pobj->val[ctbl->useVal[0]], 1, 255);
}
