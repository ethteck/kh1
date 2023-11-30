#include "common.h"
#include "io.h"
#include "sifdev.h"
#include "sdk/libcdvd.h"
#include "eekernel.h"

typedef char* (*XWhat)(void);
typedef s32 (*XHuh)(s32);

typedef struct XThingy {
    /* 0x00 */ XWhat unk_00;
    /* 0x04 */ XWhat unk_04;
    /* 0x04 */ XWhat unk_08;
    /* 0x04 */ XWhat unk_0C;
    /* 0x10 */ s32 bIsMounted;
} XThingy;

s32 func_0024A010(void);
char* func_0024A3A8(void);
s32 func_0024A3B8(void);
s32 func_0024A458(void);
s32 func_0024A4A8(void);
s32 func_0024A558(void);
s32 func_0024A630(s32);
s32 func_0024A780(char*, char*);
s32 func_0024A850(s32*);

extern volatile u8 D_002C1EB8;

extern s32 D_004642E8; // file length
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
extern XThingy D_00464360;
extern s32 D_00464384;
extern s32 D_0048DB00; // gp0 value

extern char D_00663A90[0x1000];

s32 func_0024A010() {
    return D_004642EC;
}

INCLUDE_ASM(const s32, "xsomething", func_0024A020);

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

s32* func_0024A2D0() {
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

char* func_0024A378(void) {
    // return "PP.SLPS-25105.0.KINGDOM";
    return D_00464308;
}

char* func_0024A388(void) {
    // return "haneman0";
    return D_00464320;
}

char* func_0024A398(void) {
    //     return "mangan01";
    return D_00464330;
}

char* func_0024A3A8() {
    // return "pfs0:kingdom.img";
    return D_00464340;
}

s32 func_0024A3B8() {
    char* pcVar1;
    char* pcVar2;
    char blkdevname[128];

    if (D_00464360.bIsMounted == FALSE) {
        pcVar1 = D_00464360.unk_04();
        pcVar2 = D_00464360.unk_08();
        sprintf(blkdevname, "hdd0:%s,%s", pcVar1, pcVar2);
        if (sceMount("pfs0:", blkdevname, SCE_MT_RDWR, NULL, 0) < 0) {
            return TRUE;
        }
        D_00464360.bIsMounted = TRUE;
    }
    return FALSE;
}

s32 func_0024A458() {
    if (D_00464360.bIsMounted != FALSE) {
        if (sceUmount("pfs0:") == 0) {
            D_00464360.bIsMounted = FALSE;
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
    filename = func_0024A3A8();
    fd = sceOpen(filename, SCE_RDONLY);
    D_004642F4 = 100;
    ret = TRUE;
    if (fd >= 0) {
        offset = sceLseek64(fd, 0, 2);
        D_004642F4 = 110;
        sceClose(fd);
        D_004642F4 = 120;
        ret = D_004642E8; // seems fake?
        ret = TRUE;
        if ((u32)D_004642E8 == offset) {
            ret = FALSE;
        }
    }
    return ret;
}

s32 func_0024A558(void) {
    return sceDevctl("hdd0:", HDIOC_STATUS, NULL, 0, NULL, 0);
}

s32 func_0024A588(char* devname, s32 arg1) {
    s32 bufp;

    sceDevctl(devname, HDIOC_TOTALSECTOR, NULL, 0, 0, 0);
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
    s32 mounted = D_00464360.bIsMounted;

    D_00464354 = 0;
    if (mounted != FALSE) {
        func_0024A458();
    }
    D_004642F4 = 40;
    sprintf(filename, "hdd0:%s,,%s", D_00464360.unk_04(), &D_00464330);
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
        func_0024A3B8();
    }
    D_004642F4 = 80;
    return D_00464354;
}

s32 func_0024A780(char* dirname, char* arg1) {
    struct sce_dirent sp;
    s32 fd;
    s32 var_17;
    s32 var_18;

    var_18 = 0;

    fd = sceDopen(dirname);
    if (fd < 0) {
        return 0;
    }

    var_17 = 0;
    while (sceDread(fd, &sp) > 0) {
        var_17 += 1;
    }
    sceDclose(fd);

    if (var_17 == 0) {
        return 0;
    }

    fd = sceDopen(dirname);
    if (fd < 0) {
        return 0;
    }

    while (sceDread(fd, &sp) > 0) {
        var_18 = (strcmp(sp.d_name, arg1) == 0) ? 1 : var_18;
    }
    sceDclose(fd);
    return var_18;
}

s32 func_0024A850(s32* isoBlock) {
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
    s32 var_2;

    D_004642F4 = 0;
    D_00464358 = D_0046435C = 0;

    if (func_0024A010() == 0) {
        return D_00464358;
    }

    D_004642F4 = 10;
    func_0024A458();
    if (func_0024A780("hdd0:", D_00464308) != 0) {
        cond = TRUE;
        D_00464384 = 1;
    } else {
        cond = FALSE;
        D_00464384 = 0;
    }
    D_004642E8 = func_0024A850(NULL);
    D_004642F4 = 20;
    var_2 = func_0024A558();
    D_004642F4 = 30;
    switch (abs(var_2) & 0xF) {
        case 0:
            func_0024A630(D_004642E8);
            if (func_0024A3B8() != 0) {
                D_00464358 = 1;
                if (cond) {
                    D_00464358 = 3;
                    D_0046435C = 2;
                }
            } else if (func_0024A4A8() != 0) {
                D_00464358 = 3;
                func_0024A458();
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
