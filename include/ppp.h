#ifndef PPP_H
#define PPP

#include "common.h"
#include "pppfunc.h"

typedef struct {
    /* 0x00 */ u8 unk[0xB0];
    /* 0xB8 */ u8 unkB8;
    /* 0xB9 */ u8 unkB9;
    /* 0xBA */ u8 unkBA;
    /* 0xBB */ u8 unkBB;
    /* 0xBC */ u8 unkBC;
    /* 0xBD */ u8 unkBD;
    /* 0xBE */ u8 unkBE;
    /* 0xBF */ u8 unkBF;
    /* 0xC0 */ long unkC0;
} ppvmng; // size=?

extern s32 ppvUserStopPartF;
extern ppvmng* ppvMng;

#endif /* PPP_H */
