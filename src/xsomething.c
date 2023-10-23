#include "common.h"
#include "io.h"

#include "sifdev.h"
#include "gcc/stdio.h"
#include "gcc/string.h"

typedef struct XThingy {
    /* 0x00 */ char unk_00[0x4];
    /* 0x04 */ char* (*unk_04)(void);
    /* 0x08 */ char unk_08[0x8];
    /* 0x10 */ s32 unk_10;
} XThingy;

s32 func_0024A010(void);
s32 func_0024A3B8(void);
s32 func_0024A458(void);
s32 func_0024A4A8(void);
s32 func_0024A558(void);
void func_0024A630(s32);
s32 func_0024A780(char*, char*);
s32 func_0024A850(s32*);

extern s32 D_004642E8; // file length
extern s32 D_004642F4;
extern char D_00464308[];
extern s32 D_00464330;
extern s32 D_00464354;
extern s32 D_00464358;
extern s32 D_0046435C;
extern XThingy D_00464360;
extern s32 D_00464384;
extern char D_0048B4F0[]; // device name

s32 func_0024A558(void) {
    return sceDevctl(D_0048B4F0, 0x4807, 0, 0, 0, 0);
}

s32 func_0024A588(char* devname, s32 arg1) {
    s32 sp0;

    sceDevctl(devname, 0x4802, NULL, 0, 0, 0);
    D_004642F4 = 60;
    sp0 = 0;

    if (sceDevctl(devname, 0x480A, NULL, 0, &sp0, 4) != 0) {
        return FALSE;
    }

    D_004642F4 = 70;
    if ((s32)((u32) sp0 >> 0x12) < arg1) {
        return FALSE;
    }
    return TRUE;
}

s32 func_0024A620(void) {
    return D_00464354;
}

INCLUDE_ASM(const s32, "xsomething", func_0024A630);

// void func_0024A630(s32 arg0) {
//     char filename[0x40];
//     s32 temp_20;
//     s32 fd;
//     s32 temp_2_2;
//     s32 var_17;
//     s32 temp;

//     var_17 = 0;
//     temp_20 = D_00464360.unk_10;
//     D_00464354 = 0;
//     if (temp_20 != 0) {
//         func_0024A458();
//     }
//     D_004642F4 = 40;
//     sprintf(filename, "hdd0:%s,,%s", D_00464360.unk_04(), &D_00464330);
//     fd = sceOpen(filename, 1);
//     if (fd >= 0) {
//         temp_2_2 = sceIoctl2(fd, 0x6803, NULL, 0, 0, 0);
//         var_17 = ((temp_2_2 < 0) ? 0 : temp_2_2) + 1;
//         sceDclose(fd);
//     }
//     D_004642F4 = 50;
//     temp = func_0024A588(&D_0048B4F0, (((u32) (((u32) (arg0 + 0xFFFFF) >> 20) + 0x7F) >> 7) + 1) - var_17);
//     if (temp == 0) {
//         D_00464354 = -1;
//     }
//     if (temp_20 != 0) {
//         func_0024A3B8();
//     }
//     D_004642F4 = 80;
// }

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
    if (func_0024A780(D_0048B4F0, D_00464308) != 0) {
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
