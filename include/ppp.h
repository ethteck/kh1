#ifndef PPP_H
#define PPP

#include "common.h"

typedef struct {
    /* 0x00 */ const char* progName;
    /* 0x04 */ void* calcFunc;
    /* 0x08 */ void* dektFunc;
    /* 0x0C */ void* drawFunc;
    /* 0x10 */ void* iniFunc;
    /* 0x14 */ void* staFunc;
    /* 0x18 */ void* endFunc;
    /* 0x1C */ void* conFunc;
    /* 0x20 */ void* con2Func;
    /* 0x24 */ void* desFunc;
} pppProg; // size = 0x28

#endif /* PPP_H */
