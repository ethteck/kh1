#ifndef IO_H
#define IO_H

#include "common.h"

#define SECTOR_SIZE (2048)

typedef struct KingdomFile {
    /* 0x00 */ s32 hash;
    /* 0x04 */ s32 isCompressed;
    /* 0x08 */ s32 isoBlock;
    /* 0x0C */ s32 length;
} KingdomFile; // size = 0x10

typedef struct IOReadTask {
    /* 0x00 */ u32 flags;
    /* 0x04 */ char unk_04[0x20];
    /* 0x24 */ s32 nSector;   // kingdom file iso block
    /* 0x28 */ s32 length;    // kingdom file length in bytes
    /* 0x2C */ void* dst;     // data buffer
    /* 0x30 */ s32 bytesRead; // num read bytes
    /* 0x34 */ s32 unk_34;
} IOReadTask; // size = 0x38

typedef struct XOtherCrown {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ char unk_02[0xE];
    /* 0x10 */ char unk_10[0x28];
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ char unk_48[0x4];
} XOtherCrown; // size = 0x4C

KingdomFile* cdvd_FindFile(char* filename);

#endif /* IO_H */
