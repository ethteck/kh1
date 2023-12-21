#include "common.h"
#include "io.h"
#include "disk.h"
#include "sdk/libcdvd.h"
#include "sdk/ee/eekernel.h"
#include "sdk/ee/sifdev.h"

#include "gcc/stdlib.h"
#include "gcc/string.h"

typedef struct XCrown {
    /* 0x00 */ u32 flags;
    /* 0x04 */ char unk_04[0x20];
    /* 0x24 */ s32 nSector;   // kingdom file iso block
    /* 0x28 */ s32 length;    // kingdom file length in bytes
    /* 0x2C */ void* dst;     // data buffer
    /* 0x30 */ s32 bytesRead; // num read bytes
    /* 0x34 */ s32 unk_34;
} XCrown; // size = 0x38

typedef struct XOtherCrown {
    /* 0x00 */ char unk_00[0x10];
    /* 0x10 */ char unk_10[0x28];
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ char unk_48[0x4];
} XOtherCrown; // size = 0x4C

void func_0010BEE8(void);
void func_0010BF08(void (*)(XCrown*), XCrown*);
void func_0010BF50(void (*)(XCrown*));
XOtherCrown* func_0011EEB8(s32*, s32, s32);
void func_0011FB78(void);
s32 cdvd_Decompress(u8* data, s32 compressedLength);
s32 cdvd_Hash(char* str);
s32 func_001EE068(void);
s32 func_00218C88(void);
void func_00218CA0(s32);

extern vs8 D_002C1EB8;
extern s32 D_002C2094;
extern s32 D_002C2180;
extern sceCdRMode D_002C2188;
extern s32 D_002C218C;
extern s32 D_002C2190;
extern s32 D_002C2194;
extern s32 D_002C2198; // fp.size

extern char D_0034E340[0x800];
extern char D_0048B549[];

// .bss

s32 D_004DE128;
s32 D_004DE140;
char D_004EC140[0x800];
s32 D_004EC940;
sceCdlFILE cdvd_Descriptor;
extern XCrown D_004EC970[16];
extern s32 D_004ECCF0;
extern s32 D_004DDC60;
extern XOtherCrown D_004DDC68[16];

sceCdlFILE* cdvd_GetFileDescriptor() {
    return &cdvd_Descriptor;
}

void func_0011FB78() {
    func_001224B8();
    func_001102C0();
}

void func_0011FB98(u32 lbn, u32 sectors, char* buf) {
    do {
        while (sceCdDiskReady(1) != SCECdComplete || sceCdRead(lbn, sectors, buf, &D_002C2188) == SCECdErNO) {
            func_0011FB78();
        }
        // Command is not complete
        while (sceCdSync(1) != 0) {
            func_0011FB78();
        }
    } while (sceCdGetError() != 0);
}

INCLUDE_ASM(const s32, "xkingdom", func_0011FC58);

void func_0011FD08(void) {
    if (func_001EE068() == 1) {
        if (D_002C218C > 30) {
            D_002C1EB8 |= 2;
        } else {
            D_002C218C++;
        }
    } else {
        if (((D_002C1EB8 & 0xFF) >> 1) & 1) {
            if (D_002C2190 > 0) {
                D_002C2190 -= 1;
                return;
            } else {
                func_0011FB98(cdvd_Descriptor.lsn, 1, D_0034E340);
                if (strncmp(D_0034E340, D_004EC140, ARRAY_COUNT(D_0034E340)) != 0) {
                    D_002C2190 = 60;
                    return;
                }
            }
        }
        D_002C218C = 0;
        D_002C1EB8 &= ~0x2;
    }
}

XCrown* func_0011FE18(void) {
    s32 i = 0;
    XCrown* temp = D_004EC970;

    for (i = 0; i < ARRAY_COUNT(D_004EC970); i++, temp++) {
        if (!(temp->flags & 1)) {
            temp->flags |= 1;
            temp->bytesRead = -1;
            temp->unk_34 = D_002C2194++;
            return temp;
        }
    }
    return NULL;
}

void func_0011FE80(XCrown* arg0) {
    arg0->flags = 0;
}

// in-place decompression algorithm
s32 cdvd_Decompress(u8* data, s32 compressedLength) {
    s32 copyLength;
    s32 decompressedLength;
    s32 i;
    u8 key;
    u8* srcPtr;
    u8* dstPtr;
    u8 copyIndex;
    u8 ch;

    srcPtr = &data[compressedLength];
    key = *--srcPtr;
    decompressedLength = *--srcPtr | (*--srcPtr << 8) | (*--srcPtr << 0x10);
    dstPtr = &data[decompressedLength];
    while (data < srcPtr) {
        ch = *--srcPtr;
        if (ch == key) {
            copyIndex = *--srcPtr;
            if (copyIndex == 0) {
                *--dstPtr = ch;
            } else {
                copyLength = *--srcPtr + 3;
                for (i = 0; i < copyLength; i++) {
                    *--dstPtr = dstPtr[copyIndex];
                }
            }
        } else {
            *--dstPtr = ch;
        }
    }
    return decompressedLength;
}

// hash
s32 cdvd_Hash(char* str) {
    s32 len = strlen(str);
    s32 hash = 0;
    s32 i;

    for (i = 0; i < len; i++) {
        hash = (hash * 2) ^ ((str[i] << 0x10) % 69665);
    }
    return hash;
}

s32 cdvd_Compare(const u32 left, const u32* right) {
    if (left < *right) {
        return -1;
    }
    return *right < left;
}

KingdomFile* cdvd_FindFile(char* filename) {
    return bsearch(cdvd_Hash(filename), &D_004DE140, D_002C2180, 0x10, cdvd_Compare);
}

void func_00120018(XCrown* arg0) {
    u32 numSectors = (u32)(arg0->length + 0x7FF) >> 11;
    s32 length;

    do {
        while (TRUE) {
            if (sceCdDiskReady(1) == SCECdComplete && sceCdRead(arg0->nSector, numSectors, arg0->dst, &D_002C2188) != 0) {
                break;
            }
            func_0010BEE8();
        }

        while (sceCdSync(1) != 0) {
            func_0010BEE8();
        }
    } while (sceCdGetError() != SCECdErNO);

    if ((arg0->flags >> 1) & 1) {
        FlushCache(WRITEBACK_DCACHE);
        length = cdvd_Decompress(arg0->dst, arg0->length);
    } else {
        length = arg0->length;
    }

    func_0010BF50(func_00120018);
    arg0->bytesRead = length;
}

void func_00120108(XCrown* arg0) {
    s32 cond;
    s32 fd;
    s32 nbyte;

    fd = sceOpen("pfs0:kingdom.img\0\0\0\0", SCE_RDONLY);
    cond = FALSE;

    if (fd < 0 || D_002C2094 & 0x2000) {
        cond = TRUE;
    } else {
        s32 numReadBytes = 0;

        sceLseek(fd, arg0->nSector * SECTOR_SIZE, SCE_SEEK_SET);

        for (nbyte = arg0->length; nbyte > 0; nbyte -= numReadBytes) {
            numReadBytes = sceRead(fd, arg0->dst, nbyte);
            if (numReadBytes < 0) { // error
                cond = TRUE;
                break;
            }
        }

        sceClose(fd);
        if (!cond) {
            if ((arg0->flags >> 1) & 1) {
                FlushCache(WRITEBACK_DCACHE);
                numReadBytes = cdvd_Decompress(arg0->dst, arg0->length);
            }
            arg0->bytesRead = numReadBytes;
        }
    }

    if (cond) {
        disk_Mgr.unk_20(4);
        D_002C1EB8 |= 4;
        do {
            func_0010BEE8();
        } while (((D_002C1EB8 & 0xFF) >> 2) & 1);
        func_00218CA0(0);
        arg0->nSector += D_004EC940;
        func_0010BF08(&func_00120018, arg0);
    }
    func_0010BF50(func_00120108);
}

void cdvd_WaitForDisc(sceCdlFILE* fp, char* name) {
    // DVD-ROM is not ready or file was not found
    while (sceCdDiskReady(1) != SCECdComplete || sceCdSearchFile(fp, name) == 0) {
        func_0011FB78();
    }
}

XCrown* func_001202E8(char* filename, void* dst) {
    XCrown* task;
    KingdomFile* kingdomFile;

    task = func_0011FE18();
    task->dst = dst;
    task->bytesRead = -1;

    kingdomFile = cdvd_FindFile(filename);
    if (kingdomFile == NULL) {
        task->bytesRead = 0;
    } else {
        task->length = kingdomFile->length;
        task->flags = (task->flags & ~2) | ((kingdomFile->isCompressed & 1) * 2);
        task->nSector = kingdomFile->isoBlock;
        if (func_00218C88() == 0) {
            func_0010BF08(func_00120018, task);
        } else {
            task->nSector -= D_004EC940;
            func_0010BF08(func_00120108, task);
        }
    }
    return task;
}

s32 func_001203C8(char* name, char* buf) {
    sceCdlFILE fp;

    cdvd_WaitForDisc(&fp, name);
    func_0011FB98(fp.lsn, (fp.size + 0x7FF) >> 11, buf);
    D_002C2198 = fp.size;
    FlushCache(WRITEBACK_DCACHE);
    FlushCache(INVALIDATE_ICACHE);
    return D_002C2198;
}

s32 func_00120438(const char* fileName, void* dst);
INCLUDE_ASM(const s32, "xkingdom", func_00120438);
// s32 func_00120438(char* filename, void* arg1) {
//     XCrown* temp_2 = func_001202E8(filename, arg1);

//     while (temp_2->bytesRead < 0) {
//         func_0011FB78();
//     }

//     D_002C2198 = temp_2->bytesRead;
//     func_0011FE80(temp_2);
//     FlushCache(WRITEBACK_DCACHE);
//     FlushCache(INVALIDATE_ICACHE);
//     return D_002C2198;
// }

void func_001204C0(void);
INCLUDE_ASM(const s32, "xkingdom", func_001204C0);

s32 func_00120590(char* arg0, s32 arg1, s32 arg2, s32 arg3) {
    XOtherCrown* temp_2 = func_0011EEB8(&D_004DE128, 0, func_001204C0);
    s32* new_var2 = &D_004DDC60; // TODO fake match
    s32* new_var;
    
    temp_2->unk_44 = D_004DDC60++;
    temp_2->unk_40 = arg3;
    strcpy(temp_2->unk_10, arg0);
    temp_2->unk_38 = arg1;
    temp_2->unk_3C = arg2;
    D_004DDC60 = (u16) *new_var2;
    
    new_var = &temp_2->unk_44; // TODO fake match
    return *new_var;
}

s32 func_00120640(s32 arg0) {
    XOtherCrown* it = &D_004DDC68[0];
    s32 i;
    
    for (i = 0; i < 0x10; i++, it++) {
        if (func_0011F0F8(it) != 0 && (arg0 == -1 || arg0 == it->unk_44)) {
            return 1;
        }
    }
    return 0;
}

void cdvd_Seek(char* filename) {
    // Confirm disk status allows commands to be sent
    if (sceCdDiskReady(1) == SCECdComplete) {
        KingdomFile* kingdomFile = cdvd_FindFile(filename);
        if (kingdomFile != NULL) {
            // Seek DVD-ROM head to specified block then pause
            sceCdSeek(kingdomFile->isoBlock);
        }
    }
}

void func_00120728(s32 arg0) {
    func_0011EEB8(&D_004DE128, 0, arg0);
}

s32 func_00120750() {
    func_0011EF58(&D_004DE128, 0);
    return 0;
}

char* cdvd_GetFileName(char* arg0) {
    static char D_0048DB00[0x50140]; // TODO REMOVE THIS
    
    static char D_004DDC40[0x100];

    s32 len;
    s32 i;
    char* new_var5;
    s32 blah;
    
    strcpy(D_004DDC40, "cdrom0:\\");
    strcat(D_004DDC40, arg0);
    len = strlen(D_004DDC40);

    for (i = 8; i < len; i++) {
        blah = D_004DDC40[i];

        if ((new_var5 = D_0048B549)[blah] & 2) {
            blah -= 0x20;
        }

        D_004DDC40[i] = blah;
    }
    return D_004DDC40;
}

void func_00120820(char* file) {
    s32 val;

    char* filename = cdvd_GetFileName(file);
    do {
        val = sceSifLoadModule(filename, 0, NULL);
    } while (val < 0);
}

s32 func_00120868(char* file, s32 args, char* argp, s32* result) {
    char* filename = cdvd_GetFileName(file);
    return sceSifLoadStartModule(filename, args, argp, result);
}

void func_001208B8() {
    s32 val = func_0011ED30(185000, func_00120750);
    *(s16*)(val + 2) = -1;
}

void func_001208E8() {
    XCrown* crown;
    s32 i;

    func_0011EDD0(&D_004DE128, &D_004DDC68, 0x4C, 0x10);
    crown = D_004EC970;
    D_004DDC60 = 0;

    for (i = 0; i < ARRAY_COUNT(D_004EC970); i++) {
        func_0011FE80(crown);
        crown++;
    }
}

s32 func_00120958() {
    s32 val;

    sceSifInitRpc(0);
    sceFsReset();
    sceCdInit(0);
    sceCdMmode(2);

    do {
        val = sceSifRebootIop("cdrom0:\\IOPRP243.IMG");
    } while (val == 0);
    do {
        val = sceSifSyncIop();
    } while (val == 0);

    sceSifInitRpc(0);
    sceCdInit(0);
    sceCdMmode(2);
    return sceCdInitEeCB(0, &D_004ECCF0, 0x1000);
}

void func_001209E0() {
    sceCdDiskReady(0);
    cdvd_WaitForDisc(&cdvd_Descriptor, "\\SYSTEM.CNF;1");
    func_0011FB98(cdvd_Descriptor.lsn, 1, D_004EC140);
    sceCdSync(0);
    func_0011FC58();
}
