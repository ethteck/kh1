#ifndef PPP_H
#define PPP

#include "common.h"
#include "pppfunc.h"

typedef struct {
    /* 0x00 */ u8 unk_00[0xB0];
    /* 0xB8 */ u8 unk_B8;
    /* 0xB9 */ u8 unk_B9;
    /* 0xBA */ u8 unk_BA;
    /* 0xBB */ u8 unk_BB;
    /* 0xBC */ u8 unk_BC;
    /* 0xBD */ u8 unk_BD;
    /* 0xBE */ u8 unk_BE;
    /* 0xBF */ u8 unk_BF;
    /* 0xC0 */ u64 unk_C0;
} ppvmng; // size=?

extern s32 ppvUserStopPartF;
extern ppvmng* ppvMng;

#endif /* PPP_H */
