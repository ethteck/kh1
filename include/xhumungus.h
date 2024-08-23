#include "common.h"
#include "libvu0.h"

// Needs more investigation, current implementation seems weird
typedef struct {
    /* 0x000 */ u8 unk_00[0x70];
    /* 0x070 */ s32 unk_70;
    /* 0x074 */ char unk_74[0x8];
    /* 0x07C */ s32 unk_7C[1]; // length unknown
    /* 0x080 */ char unk_80[0xF4];
    /* 0x174 */ s32 unk_174[95]; // probably not this length, needs investigation
    /* 0x2F0 */ s32 unk_2F0;
} Script;
