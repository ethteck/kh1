#ifndef GUMI_H
#define GUMI_H

#include "common.h"

typedef struct XGumiBlock {
    /* 0x00 */ char unk_00[0x31];
    /* 0x31 */ s8 unk_31;
    /* 0x32 */ char unk_32[0x12];
    /* 0x44 */ s8 unk_44;
    /* 0x45 */ char unk_45[0x2];
    /* 0x47 */ s8 unk_47;
} XGumiBlock; // size: 0x48

typedef struct XGumiThing {
    /* 0x000 */ u64 unk_000;
    /* 0x008 */ u64 unk_008;
    /* 0x010 */ u64 unk_010;
    /* 0x018 */ u64 unk_018;
    /* 0x020 */ struct XGumiThing* unk_020;
    /* 0x024 */ char unk_024[4];
    /* 0x028 */ s32 unk_028;
    /* 0x02C */ char unk_02C[0x40];
} XGumiThing; // size: 0x70
typedef struct XGumi {
    /* 0x0000 */ char unk_0000[4];
    /* 0x0004 */ s32 unk_0004;
    /* 0x0008 */ s32 unk_0008;
    /* 0x000C */ char unk_000C[0x9A6C];
    /* 0x9A78 */ XGumiBlock unk_9A78;
    /* 0x9AC0 */ char unk_9AC0[0x38];
    /* 0x9AF8 */ s32 unk_9AF8;
    /* 0x9AFC */ s32 unk_9AFC;
    /* 0x9B00 */ s32 unk_9B00;
    /* 0x9B04 */ s32 unk_9B04;
    /* 0x9B08 */ s32 unk_9B08;
    /* 0x9B0C */ s32 unk_9B0C;
    /* 0x9B10 */ s32 unk_9B10;
    /* 0x9B14 */ s32 unk_9B14;
    /* 0x9B18 */ s32 unk_9B18;
    /* 0x9B1C */ s32 unk_9B1C;
    /* 0x9B20 */ s32 unk_9B20;
    /* 0x9B24 */ s32 unk_9B24;
    /* 0x9B28 */ char unk_9B28[0x98];
    /* 0x9BC0 */ u8 unk_9BC0[0x20];
} XGumi; // size: 0x9BE0

void func_001BCAA0(void*);
XGumiBlock* func_001BCB58(void);

// u8 func_001BC590(s32); // todo: used in a few other splits, but breaks match in defining TU if even declared beforehand

#endif // GUMI_H
