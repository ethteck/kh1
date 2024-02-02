#include "common.h"
#include "sdk/ee/libvu0.h"

typedef struct Unk150000 {
    /* 0x00 */ char unk_00[0x2];
    /* 0x02 */ s16 unk_02;
} Unk150000; // size = ?

typedef struct Unk3010F8 {
    /* 0x000 */ char unk_000[0x36];
    /* 0x036 */ u8 unk_036;
    /* 0x037 */ char unk_037[0x457];
    /* 0x48E */ u8 unk_48E[3];
    /* 0x491 */ u8 unk_491;
    /* 0x492 */ u8 unk_492[3];
} Unk3010F8; // size = ?

extern _VX D_002C1EB8;

extern sceVu0FMATRIX D_002C1E20;
extern u32 D_002C1EA8;

// Todo: Used in many unsplit sections
extern Unk3010F8* D_003010F8;
