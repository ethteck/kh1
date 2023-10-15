#include "common.h"
#include "io.h"

#include "sdk/libcdvd.h"
#include "sdk/ee/eekernel.h"
#include "sdk/ee/sifdev.h"

#include "gcc/string.h"

typedef struct XCrown {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ char unk_04[0x20];
    /* 0x24 */ s32 unk_24; // kingdom file iso block
    /* 0x28 */ s32 unk_28; // kingdom file length in bytes
    /* 0x2C */ void* unk_2C; // data buffer
    /* 0x30 */ s32 unk_30; // num read bytes
    /* 0x34 */ s32 unk_34;
} XCrown; // size = 0x38

void func_0010BEE8(void);
void func_0010BF08(void (*)(XCrown*), XCrown*);
void func_0010BF50(void (*)(XCrown*));
void func_0011FB78(void);
void func_0011FB98(s32 lsn, s32, char*);
s32 func_0011FE88(void*, s32);
s32 func_0011FF40(char* str);
s32 func_001EE068(void);
s32 func_00218C88(void);
void func_00218CA0(s32);
KingdomFile* bsearch(s32, s32*, s32, s32, void*);

extern volatile s8 D_002C1EB8;
extern s32 D_002C2094;
extern s32 D_002C2180;
extern sceCdRMode D_002C2188;
extern s32 D_002C218C;
extern s32 D_002C2190;
extern s32 D_002C2194;
extern s32 D_002C2198; // fp.size

extern char D_0034E340[];

extern void (*D_00464380)(s32);
extern s32 D_004DE140;
extern char D_004EC140[];
extern s32 D_004EC940;
extern s32 D_004EC948;
extern XCrown D_004EC970[16];

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
                func_0011FB98(D_004EC948, 1, D_0034E340);
                if (strncmp(D_0034E340, D_004EC140, 0x800) != 0) {
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
        if (!(temp->unk_00 & 1)) {
            temp->unk_00 |= 1;
            temp->unk_30 = -1;
            temp->unk_34 = D_002C2194++;
            return temp;
        }
    }
    return NULL;
}

void func_0011FE80(XCrown* arg0) {
    arg0->unk_00 = 0;
}

INCLUDE_ASM(const s32, "xkingdom", func_0011FE88);

// hash
s32 func_0011FF40(char* str) {
    s32 len = strlen(str);
    s32 hash = 0;
    s32 i;

    for (i = 0; i < len; i++) {
        hash = (hash * 2) ^ ((str[i] << 0x10) % 69665);
    }
    return hash;
}

// hash comparer for the binary search
int func_0011FFB8(const int *left, const int *right) {
    if (left < *right)
        return -1;
    return *right < left;
}

KingdomFile* func_0011FFD8(char* filename) {
    return bsearch(func_0011FF40(filename), &D_004DE140, D_002C2180, 0x10, func_0011FFB8);
}

void func_00120018(XCrown* arg0) {
    u32 numSectors = (u32) (arg0->unk_28 + 0x7FF) >> 11;
    s32 var_17;

    do {
        while (TRUE) {
            if (sceCdDiskReady(1) == SCECdComplete && sceCdRead(arg0->unk_24, numSectors, arg0->unk_2C, &D_002C2188) != 0) {
                break;
            }
            func_0010BEE8();
        }
        
        while (sceCdSync(1) != 0) {
            func_0010BEE8();
        }
    } while (sceCdGetError() != SCECdErNO);

    if ((arg0->unk_00 >> 1) & 1) {
        FlushCache(WRITEBACK_DCACHE);
        var_17 = func_0011FE88(arg0->unk_2C, arg0->unk_28);
    } else {
        var_17 = arg0->unk_28;
    }

    func_0010BF50(func_00120018);
    arg0->unk_30 = var_17;
}

void func_00120108(XCrown* arg0) {
    s32 cond;
    s32 fd;
    s32 nbyte;

    fd = sceOpen("pfs0:kingdom.img", 1);
    cond = FALSE;
    
    if (fd < 0 || D_002C2094 & 0x2000) {
        cond = TRUE;
    } else {
        s32 numReadBytes = 0;

        sceLseek(fd, arg0->unk_24 * 2048, SCE_SEEK_SET);

        for (nbyte = arg0->unk_28; nbyte > 0; nbyte -= numReadBytes) {
            numReadBytes = sceRead(fd, arg0->unk_2C, nbyte);
            if (numReadBytes < 0) { // error
                cond = TRUE;
                break;
            }
        }

        sceClose(fd);
        if (!cond) {
            if ((arg0->unk_00 >> 1) & 1) {
                FlushCache(WRITEBACK_DCACHE);
                numReadBytes = func_0011FE88(arg0->unk_2C, arg0->unk_28);
            }
            arg0->unk_30 = numReadBytes;
        }
    }
        
    if (cond) {
        D_00464380(4);
        D_002C1EB8 |= 4;
        do {
            func_0010BEE8();
        } while(((D_002C1EB8 & 0xFF) >> 2) & 1);
        func_00218CA0(0);
        arg0->unk_24 += D_004EC940;
        func_0010BF08(&func_00120018, arg0);
    }
    func_0010BF50(func_00120108);
}

void func_00120280(sceCdlFILE* fp, char* name) {
    while (sceCdDiskReady(1) != SCECdComplete || sceCdSearchFile(fp, name) == 0) {
        func_0011FB78();
    }
}

XCrown* func_001202E8(char* filename, void* arg1) {
    XCrown* temp_2;
    KingdomFile* kingdomFile;

    temp_2 = func_0011FE18();
    temp_2->unk_2C = arg1;
    temp_2->unk_30 = -1;
    
    kingdomFile = func_0011FFD8(filename);
    if (kingdomFile == NULL) {
        temp_2->unk_30 = 0;
    } else {
        temp_2->unk_28 = kingdomFile->length;
        temp_2->unk_00 = (temp_2->unk_00 & ~2) | ((kingdomFile->isCompressed & 1) * 2);
        temp_2->unk_24 = kingdomFile->isoBlock;
        if (func_00218C88() == 0) {
            func_0010BF08(func_00120018, temp_2);
        } else {
            temp_2->unk_24 -= D_004EC940;
            func_0010BF08(func_00120108, temp_2);
        }
    }
    return temp_2;
}

s32 func_001203C8(char* arg0, char* arg1) {
    sceCdlFILE fp;

    func_00120280(&fp, arg0);
    func_0011FB98(fp.lsn, (fp.size + 0x7FF) >> 11, arg1);
    D_002C2198 = fp.size;
    FlushCache(WRITEBACK_DCACHE);
    FlushCache(INVALIDATE_ICACHE);
    return D_002C2198;
}

INCLUDE_ASM(const s32, "xkingdom", func_00120438);
// s32 func_00120438(char* arg0, void* arg1) {
//     XCrown* temp_2 = func_001202E8(arg0, arg1);

//     while (temp_2->unk_30 < 0) {
//         func_0011FB78();
//     }
    
//     D_002C2198 = temp_2->unk_30;
//     func_0011FE80(temp_2);
//     FlushCache(WRITEBACK_DCACHE);
//     FlushCache(INVALIDATE_ICACHE);
//     return D_002C2198;
// }

INCLUDE_ASM(const s32, "xkingdom", func_001204C0);

INCLUDE_ASM(const s32, "xkingdom", func_00120590);

INCLUDE_ASM(const s32, "xkingdom", func_00120640);

void func_001206D0(char* filename) {
    if (sceCdDiskReady(1) == SCECdComplete) {
        KingdomFile* kingdomFile = func_0011FFD8(filename);

        if (kingdomFile != NULL) {
            sceCdSeek(kingdomFile->isoBlock);
        }
    }
}

INCLUDE_ASM(const s32, "xkingdom", func_00120728);

INCLUDE_ASM(const s32, "xkingdom", func_00120750);
