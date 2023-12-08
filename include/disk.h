#ifndef DISK_H
#define DISK_H

#include "common.h"

typedef char* (*XWhat)(void);
typedef s32 (*XHuh)(s32);
typedef void (*XWho)(s32);

typedef struct DiskManager {
    /* 0x00 */ XWhat unk_00;
    /* 0x04 */ XWhat getGamecode;
    /* 0x08 */ XWhat unk_08;
    /* 0x0C */ XWhat unk_0C;
    /* 0x10 */ b32 isMounted;
    /* 0x14 */ XWhat getImgName;
    /* 0x18 */ XHuh unk_18;
    /* 0x1C */ XWhat unk_1C;
    /* 0x20 */ XWho unk_20;
} DiskManager; // size = 0x24

extern DiskManager disk_Mgr;

char* func_0024A368(void);
char* disk_GetGamecode(void);
char* func_0024A388(void);
char* func_0024A398(void);
char* disk_GetImgName(void);
s32 func_0024A8B0(s32);
s32 func_0024AA88();
void func_0024AA98(s32);

#endif // DISK_H
