#include "common.h"

typedef char* (*XWhat)(void);
typedef s32 (*XHuh)(s32);

typedef struct DiskManager {
    /* 0x00 */ XWhat unk_00;
    /* 0x04 */ XWhat unk_04;
    /* 0x04 */ XWhat unk_08;
    /* 0x04 */ XWhat unk_0C;
    /* 0x10 */ b32 isMounted;
    /* 0x14 */ XWhat unk_14;
    /* 0x18 */ XHuh unk_18;
    /* 0x1C */ XWhat unk_1C;
    /* 0x20 */ XWhat unk_20;
} DiskManager;

DiskManager disk_Mgr;
