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

KingdomFile* func_0011FFD8(char* filename);

#endif /* IO_H */
