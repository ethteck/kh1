#include "disk.h"
#include "io.h"
#include "sifdev.h"
#include "sdk/libcdvd.h"
#include "eekernel.h"

s32 func_0024A010(void);
char* disk_GetImgName(void);
s32 disk_Mount(void);
s32 disk_Unmount(void);
s32 func_0024A4A8(void);
s32 disk_GetStatus(void);
s32 func_0024A630(s32);
s32 disk_Seek(char*, char*);
s32 disk_SetBlock(s32*);

extern volatile u8 D_002C1EB8;

s32 diskBlockSize; // file length
extern s32 D_004642EC;
extern s32 D_004642F0;
extern s32 D_004642F4;
extern s32 D_004642F8;
extern char D_00464300[];
extern char D_00464308[];
extern char D_00464320[];
extern char D_00464330[];
extern char D_00464340[];
extern s32 D_00464354;
extern s32 D_00464358;
extern s32 D_0046435C;
DiskManager diskMgr;
extern s32 D_00464384;
extern s32 D_0048DB00; // gp0 value

extern char D_00663A90[0x1000];

s32 func_0024A010() {
    return D_004642EC;
}

INCLUDE_ASM(const s32, "disk", func_0024A020);

void func_0024A140(s32 arg0) {
    if (0 < arg0) {
        do {
            D_004642F8++;
            arg0--;
        } while (arg0 != 0);
    }
}

s32 func_0024A178() {
    return D_004642F8;
}

void func_0024A188(s32 arg0) {
    int iVar1;
    int stat[4];

    do {
        WaitSema(arg0);
        D_002C1EB8 = D_002C1EB8 & 0xE7 | 0x10;
        iVar1 = func_0024A010();
        if (iVar1 != 0) {
            sceDevctl("pfs:", PDIOC_CLOSEALL, NULL, 0, NULL, 0);
        }
        while (sceDevctl("hdd:", HDIOC_DEV9OFF, NULL, 0, NULL, 0) < 0) {
            func_0024A140(100000);
        }
        while (sceCdPowerOff(stat) == 0) {
            func_0024A140(100000);
        }
        D_002C1EB8 |= 0x10 | 0x8;
        D_004642F0++;
    } while (TRUE);
}

void func_0024A278(s32 arg0) {
    D_002C1EB8 = D_002C1EB8 & ~(0x10 | 0x8) | 0x8;
    if (func_0024A010() != 0) {
        iSignalSema(arg0);
    }
}

s32* disk_StartThread() {
    struct ThreadParam threadParam;
    void* sema;
    struct SemaParam semaParam;
    int thread;

    semaParam.maxCount = 1;
    semaParam.initCount = 0;
    semaParam.option = 0;
    sema = CreateSema(&semaParam);
    threadParam.initPriority = 1;
    threadParam.stackSize = sizeof(D_00663A90);
    threadParam.gpReg = &D_0048DB00;
    threadParam.entry = func_0024A188;
    threadParam.stack = D_00663A90;
    thread = CreateThread(&threadParam);
    StartThread(thread, sema);
    return sceCdPOffCallback(func_0024A278, sema);
}

char* func_0024A368() {
    // return "128M";
    return D_00464300;
}

char* disk_GetGamecode(void) {
    // return "PP.SLPS-25105.0.KINGDOM";
    return D_00464308;
}

char* func_0024A388(void) {
    // return "haneman0";
    return D_00464320;
}

char* func_0024A398(void) {
    // return "mangan01";
    return D_00464330;
}

char* disk_GetImgName() {
    // return "pfs0:kingdom.img";
    return D_00464340;
}

s32 disk_Mount() {
    char* pcVar1;
    char* pcVar2;
    char blkdevname[128];

    if (diskMgr.bIsMounted == FALSE) {
        pcVar1 = diskMgr.unk_04();
        pcVar2 = diskMgr.unk_08();
        sprintf(blkdevname, "hdd0:%s,%s", pcVar1, pcVar2);
        if (sceMount("pfs0:", blkdevname, SCE_MT_RDWR, NULL, 0) < 0) {
            return TRUE;
        }
        diskMgr.bIsMounted = TRUE;
    }
    return FALSE;
}

s32 disk_Unmount() {
    if (diskMgr.bIsMounted != FALSE) {
        if (sceUmount("pfs0:") == 0) {
            diskMgr.bIsMounted = FALSE;
            return FALSE;
        }
    }
    return TRUE;
}

s32 func_0024A4A8() {
    char* filename;
    s32 fd;
    u64 offset;
    s32 ret;

    D_004642F4 = 90;
    filename = disk_GetImgName();
    fd = sceOpen(filename, SCE_RDONLY);
    D_004642F4 = 100;
    ret = TRUE;
    if (fd >= 0) {
        offset = sceLseek64(fd, 0, 2);
        D_004642F4 = 110;
        sceClose(fd);
        D_004642F4 = 120;
        ret = diskBlockSize; // seems fake?
        ret = TRUE;
        if ((u32)diskBlockSize == offset) {
            ret = FALSE;
        }
    }
    return ret;
}

s32 disk_GetStatus(void) {
    return sceDevctl("hdd0:", HDIOC_STATUS, NULL, 0, NULL, 0);
}

s32 func_0024A588(char* devname, s32 arg1) {
    s32 bufp;

    sceDevctl(devname, HDIOC_TOTALSECTOR, NULL, 0, NULL, 0);
    D_004642F4 = 60;
    bufp = NULL;

    if (sceDevctl(devname, HDIOC_FREESECTOR, NULL, 0, &bufp, 4) != 0) {
        return FALSE;
    }

    D_004642F4 = 70;
    if ((s32)((u32)bufp >> 0x12) < arg1) {
        return FALSE;
    }
    return TRUE;
}

s32 func_0024A620(void) {
    return D_00464354;
}

s32 func_0024A630(s32 arg0) {
    char filename[0x40];
    s32 fd;
    int val;

    s32 temp = 0;
    s32 mounted = diskMgr.bIsMounted;

    D_00464354 = 0;
    if (mounted != FALSE) {
        disk_Unmount();
    }
    D_004642F4 = 40;
    sprintf(filename, "hdd0:%s,,%s", diskMgr.unk_04(), &D_00464330);
    fd = sceOpen(filename, SCE_RDONLY);
    if (fd >= 0) {
        temp = sceIoctl2(fd, HIOCNSUB, NULL, 0, NULL, 0);
        if (temp < 0) {
            temp = 0;
        }
        temp++;
        sceDclose(fd);
    }
    D_004642F4 = 50;
    val = (((((u32)(arg0 + 0xFFFFF)) >> 20) + 0x7F) >> 7) + 1;
    if (func_0024A588("hdd0:", val - temp) == 0) {
        D_00464354 = -1;
    }
    if (mounted != FALSE) {
        disk_Mount();
    }
    D_004642F4 = 80;
    return D_00464354;
}

s32 disk_Seek(char* dirname, char* query) {
    struct sce_dirent sp;
    s32 fd;
    s32 buflen;
    s32 bFoundQuery = FALSE;

    fd = sceDopen(dirname);
    if (fd < 0) {
        return FALSE;
    }

    buflen = 0;
    while (sceDread(fd, &sp) > 0) {
        buflen += 1;
    }
    sceDclose(fd);

    if (buflen == 0) {
        return FALSE;
    }

    fd = sceDopen(dirname);
    if (fd < 0) {
        return FALSE;
    }

    while (sceDread(fd, &sp) > 0) {
        if (strcmp(sp.d_name, query) == 0) {
            bFoundQuery = TRUE;
        }
    }
    sceDclose(fd);
    return bFoundQuery;
}

s32 disk_SetBlock(s32* isoBlock) {
    s32 length = 0;
    KingdomFile* kingdomFile;

    if (isoBlock != NULL) {
        *isoBlock = 0;
    }

    kingdomFile = func_0011FFD8("kingdom.img");
    if (kingdomFile != NULL) {
        length = kingdomFile->length;
        if (isoBlock != NULL) {
            *isoBlock = kingdomFile->isoBlock;
        }
    }
    return length;
}

s32 func_0024A8B0(void) {
    s32 cond;
    s32 diskStatus;

    D_004642F4 = 0;
    D_00464358 = D_0046435C = 0;

    if (func_0024A010() == 0) {
        return D_00464358;
    }

    D_004642F4 = 10;
    disk_Unmount();
    if (disk_Seek("hdd0:", D_00464308) != 0) {
        cond = TRUE;
        D_00464384 = 1;
    } else {
        cond = FALSE;
        D_00464384 = 0;
    }
    diskBlockSize = disk_SetBlock(NULL);
    D_004642F4 = 20;
    diskStatus = disk_GetStatus();
    D_004642F4 = 30;
    switch (abs(diskStatus) & 0xF) {
        case 0:
            func_0024A630(diskBlockSize);
            if (disk_Mount() != 0) {
                D_00464358 = 1;
                if (cond) {
                    D_00464358 = 3;
                    D_0046435C = 2;
                }
            } else if (func_0024A4A8() != 0) {
                D_00464358 = 3;
                disk_Unmount();
                D_0046435C = 2;
            } else {
                D_00464358 = 2;
            }
            break;
        case 1:
            D_00464358 = 1;
            D_0046435C = 1;
            break;
        case 2:
            D_00464358 = 1;
            D_0046435C = 4;
            break;
        case 3:
            D_00464358 = 1;
            D_0046435C = 3;
            break;
    }
    D_004642F4 = 130;
    return D_00464358;
}

s32 func_0024AA88() {
    return D_00464358;
}

void func_0024AA98(s32 arg0) {
    D_00464358 = arg0;
}

// blocked by subsequent 4-byte aligned function breaking split

// s32 func_0024AAA8() {
//     return D_0046435C;
// }
