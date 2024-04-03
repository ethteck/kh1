#include "common.h"

#include "sdk/ee/libgraph.h"
#include "sdk/ee/libvu0.h"

#include "worldfile.h"
#include "xblade.h"
#include "xarcade.h"
#include "xnoodle.h"
#include "xtailor.h"
#include "disk.h"

#include "string.h"

typedef struct XPointy {
    /* 0x00 */ char unk_00[2];
    /* 0x02 */ s16 unk_02;
} XPointy;

typedef struct XBlobule {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ char unk_04[0x2C];
    /* 0x30 */ sceVu0FVECTOR unk_30;
} XBlobule; // size = 0x40

extern sceVu0FMATRIX D_00297850;
extern s32 D_002979E0;
extern s32 D_002979E4;
extern u32 D_002A0508;
extern s32 D_002A0510;
extern s32 D_002A0520[];
extern u32 D_002B29C4;
extern s32 D_002B2CC4;
extern s32 D_002B2CC8;
extern s32 D_002B8354;
extern s32 D_002B8364;
extern sceVu0FMATRIX D_002B84F0;
extern u32 D_002B85F8;
extern s32 D_002B8678;
extern s32 D_002B8680;
extern s32 D_002B8684;
extern s32 D_002B8688;
extern s32 D_002B8698[];
extern s32 D_002B91E0;
//extern XBlobule D_002B92F0[];
extern s32 D_002B92F8;
extern s32 D_002B9304;
extern s32 D_002B9308;
extern s32 D_002B930C;
extern s32 D_002B9310;
extern s32 D_002B9314;
extern s32 D_002B9318[];
extern s32 D_002B9328;
extern s32 D_002B932C;
extern u32 D_002B9330;
extern u32 D_002B9334;
extern s32 D_002B9338;
extern u32 D_002B933C;
extern s32 D_002B9340;
extern volatile s32 D_002B9664; // TODO not sure if volatile but needed to match func_00113BC0
extern s32 D_002B9668;
extern s32 D_002B966C;
extern s32 D_002BD8D8;
extern s32 D_002C1EBC;

extern s32 D_003F0DD8;

extern s32 D_004D2A2C;
extern s32 D_004D2A60;
extern s32 D_004D2A68;
extern s32 D_004D2A6C;
extern s32 D_004D2A70;
extern s32 D_004D2A74;
extern s32 D_004D2A8C;
extern s32 D_004D2A90;
extern s32 D_004D2A94;
extern s32 D_004D2A98;
extern s32 D_004D2A9C;
extern s32 D_004D2AA0;
extern s32 D_004D2AAC;
extern s32 D_004D2AB0;

extern s32 D_9A0000;

void func_001009A8();
s32 func_001016E8();
u16 func_00105660();
void func_00111198();
void func_001116C8();
void func_00114420();
void func_00117588();
void func_00177688(void);
void func_001776C8(void);
void* func_00122588(s32, void*);
void func_00132450();
void func_00157B90();
void func_00177470();
void func_001778A0(s32);
void func_00180CE0();
void func_001C38C0();
void func_001C4FF0();
void* func_001EE280(s32);
void func_001ED878();

INCLUDE_ASM(const s32, "xblade", func_00112168);

void func_00112190(void) {
    D_002B85F8 |= 0x20;
}

void func_001121A8(void) {
    D_002B85F8 &= ~0x20;
}

void func_001121C8(void);
INCLUDE_ASM(const s32, "xblade", func_001121C8);

void* func_001124E8(void) {
    return func_0011ED30(50000, func_001016E8);
}

s32 func_00112508(UNK_TYPE arg0, UNK_TYPE arg1, s32* arg2) {
    func_001ED888(2);
    func_001EE1E0(3, -9);
    func_00101528();
    func_001EE1E0(0, -1);
    func_001EE1E0(3, -1);
    func_001EE1E0(0, 0);
    func_001EE1E0(0, 1);
    func_001EE1E0(1, 0);
    func_001EE1E0(1, 1);
    func_0014A248();
    func_00146BC8(-3);
    func_00146BC8(-4);
    func_00146BC8(-5);
    func_00146BC8(-6);
    func_00146BC8(-7);
    func_001EE1E0(0, -8);
    func_001EE1E0(3, -8);
    func_001EE1E0(3, -10);
    return func_0011CC20(-1, arg2, func_001124E8);
}

s32 func_001125F0(void) {
    char stack[64];
    void* p0;

    func_0011C938(stack);
    p0 = func_00155ED8(0x34, 4);

    return func_00120590(stack, p0, func_00112508, 0);
}

s32 func_00112630(void) {
    func_001121C8();
    func_0010E580();
    func_0010AD58(D_002B9330);
    D_002A0508 = D_002B9330;
    D_002A0508 = func_001133E0(D_002B9330, 0x40);
    return func_001125F0();
}

s32 func_00112690(void) {
    if (D_002B930C == 1 && D_002B9310 == 0) {
        return 0;
    }

    worldfile_getNames();
    D_002B9304 = 0;
    D_002B9308 = 0;
    D_002B9314 = 1;
    D_004D2A2C = &D_9A0000;
    func_00177688();
    func_001776C8();

    if (D_002B8688 == D_002B8678) {
        D_002B9304 = 1;
    }
    
    if (D_002B9304 == 1) {
        func_001121C8();
        if (D_002B9328 != 0) {
            func_001125F0();
        } else {
            func_001124E8();
        }
    } else {
        func_00120590(worldDataFile, D_004D2A2C, func_00112630, 0);
    }
    return 4;
}

s32 func_001127A0(void) {
    func_001C38C0();
    D_002B29C4 = 0;
    func_00122720();
    func_0011ED30(189999, func_00112690);
    return 4;
}

void* func_001127E0(void) {
    func_001009D8();
    return func_0011ED30(190000, func_001127A0);
}

INCLUDE_ASM(const s32, "xblade", func_00112810);

void* func_00112848(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    D_002B92F8 = arg3;
    D_002B8678 = arg0;
    D_002B8680 = arg1;
    D_002B8684 = arg2;
    return func_001127E0();
}

INCLUDE_ASM(const s32, "xblade", func_00112880);

void func_001128D8(s32 arg0) {
    D_002A0510 = arg0;
    D_002B9310 = 1;
}

INCLUDE_ASM(const s32, "xblade", func_001128F0);
// extern s32 D_002A050C;
// extern s32 D_002B868C;
// extern s32 D_002B92FC;

// typedef struct Something {
//     /* 0x00 */ s32 unk_00;
//     /* 0x04 */ char unk_04[0x3C];
// } Something;

// extern s32* D_002B92F0;

// void func_001128F0(s32 arg0) {
//     char str[0x40];
//     s32* temp;
//     s32 temp2;
//     s32 new_var2 = 1;
    
//     if (((D_002C1EA8 >> 0xD) & 1) != new_var2) {
//         temp = (D_002B92F0[arg0 << 4] << 6) + D_002B92FC;
//         temp2 = *temp;
//         if (D_002B868C != temp2) {
//             D_002B930C = 1;
//             worldfile_getBinImgName(temp2);
//             strcpy(str, worldBinImgFile);
//             strcat(str, ".img");
//             D_002A050C = func_00155ED8(0x34, 8);
//             D_002A050C = func_001133E0(D_002A050C, 0x80);
//             func_00120590(str, D_002A050C, func_001128D8, 0);
//         }
//     }
// }

s32 func_001129C8(void) {
    func_0011C6C8(0);
    D_002B29C4 = 0;
    func_00122720();
    return 4;
}

void func_001129F8(void) {
    func_00157B90();
    D_002A0520[1] = 0;
    D_002A0520[0] = 0;
    func_0011C5F0(0, 0, 360);
    func_0011C5F0(1, 0, 360);
    func_0011D310(360);
    func_00101628(360);
}

void func_00112A50(void) {
    func_0012C990(2, 0);
    func_0012C990(6, 0);
    D_002C1EA8 |= 0x80000;
    func_001129F8();
    func_001C38C0();
    func_0011ED30(190000, func_001129C8);
    D_002B8698[0] = D_002B8678;
    D_002B8698[1] = D_002B8680;
    func_001093A8(4);
}

void func_00112AD8(void) {
    D_002C1EA8 |= 0x80000;
    func_001129F8();
    func_001C38C0();
    func_00112CF0();
    func_0011ED30(190000, func_001129C8);
    D_002B9318[0] = D_002B8678;
    D_002B9318[1] = D_002B8680;
    D_002B9318[2] = D_002B92F8;
    func_001093A8(6);
}

void func_00112B60(void) {
    // empty function
}

void func_00112B68(void) {
    func_001ED888(2);
    func_001EE1E0(3, -9);
    func_001EE1E0(0, -1);
    func_001EE1E0(3, -1);
    func_001EE1E0(0, 0);
    func_001EE1E0(0, 1);
    func_001EE1E0(1, 0);
    func_001EE1E0(1, 1);
    func_001EE1E0(0, -8);
    func_001EE1E0(3, -8);
    func_001EE1E0(0, -3);
    func_001EE1E0(3, -3);
    func_001EE1E0(0, -4);
    func_001EE1E0(3, -4);
    func_001EE1E0(0, -5);
    func_001EE1E0(3, -5);
    func_001EE1E0(0, -6);
    func_001EE1E0(3, -6);
    func_001EE1E0(0, -7);
    func_001EE1E0(3, -7);
    func_001EE1E0(3, -10);
}

void* func_00112C70(void) {
    func_00114420();
    return func_001093A8(9);
}

void* func_00112C90(void) {
    func_00114420();
    return func_001093A8(8);
}

void* func_00112CB0(void) {
    return func_00155ED8(61, 3);
}

void* func_00112CD0(void) {
    return func_00155ED8(0, 64);
}

INCLUDE_ASM(const s32, "xblade", func_00112CF0);

INCLUDE_ASM(const s32, "xblade", func_00112D48);

INCLUDE_ASM(const s32, "xblade", func_00112D88);

INCLUDE_ASM(const s32, "xblade", func_00112DE0);

INCLUDE_ASM(const s32, "xblade", func_00112EE8);

INCLUDE_ASM(const s32, "xblade", func_00112FE8);
extern s32 D_002B92F4;

// void func_00104DC8(s32, sceVu0FVECTOR);
// void func_001113A8(s32, sceVu0FVECTOR);
// void func_00112D48(s32, sceVu0FVECTOR);
// s32 func_00112D88(void);

// void func_00112FE8(sceVu0FVECTOR arg0) {
//     sceVu0FMATRIX* mtx;

//     if (D_002B92F8 == -1) {
//         D_002B92F8 = func_00112D88();
//     }
//     if (D_002B92F8 < D_002B92F4) {
//         mtx = &D_002B92F0[D_002B92F8];
//         arg0[0] = (*mtx)[3][0];
//         arg0[1] = (*mtx)[3][1];
//         arg0[2] = (*mtx)[3][2];
//         arg0[3] = (*mtx)[3][3];
//         if (D_002B9328 != 0) {
//             if (D_002B932C == 1) {
//                 func_00112D48(2, arg0);
//             }
//         }
//         if (D_002B8364 == 1) {
//             func_001113A8(2, arg0);
//         }
//     } else {
//         func_00104DC8(0, arg0);
//     }
// }

s32 func_001130F0(s32 arg0) {
    D_002B9334 = arg0;
    if (arg0 != 0) {
        D_002B933C = 0;
        return func_001C4740(arg0, 0);
    }
    return func_00110150();
}

void func_00113130(void) {
    if (D_002B9328 != 0 && D_002B932C == 0) {
        func_0013C008();
    }
}

INCLUDE_ASM(const s32, "xblade", func_00113170);
s32 func_00113170();
// s32 func_00113170(void) {
//     if (D_002B2CC4 != 0) {
//         return 0;
//     }
//     D_002B8354 = 1;
//     func_00105660();
//     func_00180CE0();
//     func_00132450();
//     D_002B933C = 1;

//     if (D_002979E0 != 0 && D_002979E4 != 0) {
//         func_00177470(D_002979E0, D_002979E4, D_002B8680 + 1, 100000);
//     }

//     func_001009A8();
//     D_002C1EA8 &= ~0x4;
//     D_002C1EA8 &= ~0x8000000;
//     func_001C4FF0(D_002B91E0, 0);
//     D_002B930C = 0;
//     D_002B9310 = 0;
//     D_002B9328 = 0;
//     func_00114430();
//     D_002BD8D8 = 0;

//     if (D_002B8364 == 1 || D_002B29C4 == 1) {
//         func_001113E8();
//     }

//     D_002B8364 = 0;
//     func_00111198();
//     func_001116C8();
//     func_001ED878(0);
//     D_002B9314 = 0;
//     return 4;
// }

void* func_001132A0(void) {
    return func_0011ED30(49900, func_00113170);
}

void* func_001132C0(void) {
    func_00113130();
    return func_00122588(D_002B9340, func_001132A0);
}

void* func_001132F0(void) {
    if (D_002B29C4 == 1) {
        func_0013C668();
    }
    func_001144C8();
    if (D_002B9338 == 0) {
        D_002BD8D8 = 1;
        return func_0011E7C8(func_001132C0, func_00155ED8(0x34, 4));
    }
    return func_001132C0();
}

s32 func_00113380(void) {
    func_00112168();
    func_00101580();
    D_002B9340 = func_001133E0(D_002B9340, 0x80);
    func_00120590(roomArchiveFile, D_002B9340, func_001132F0, 0);
    return 4;
}

s32 func_001133E0(s32 arg0, s32 arg1) {
    if ((arg0 % arg1) != 0) {
        arg0 = ((arg0 / arg1) * arg1) + arg1;
    }
    return arg0;
}

#ifndef NON_MATCHING
INCLUDE_ASM(const s32, "xblade", func_00113410);
#else

typedef struct Big300 {
    /* 0x00 */ s64 unk_00[0x300 / 8];
} Big300; // size = 0x300;

extern Big300 D_002B9350;
extern s32 D_002B9650;

s32 func_001F0EF0(s32);

void func_00113410(void) {
    s32 temp_16;
    s32 temp_7;
    u64 temp_3;
    u64 temp_5;
    u64 new_var2;
    s32 new_var4;
    s32 *new_var6;

    new_var6 = &D_004D2A98;
    new_var4 = (*new_var6) << 0x18;
    temp_7 = D_004D2A94 << 0x10;
    new_var2 = (u64) D_004D2A9C << 0x18;
    temp_7 = temp_7 | D_004D2A90 << 8;

    temp_3 = ((u64) D_004D2AA0 << 0x18) | 0x100D17A88;

    D_002B9350.unk_00[0x140 / 8] = temp_3;
    D_002B9350.unk_00[0x160 / 8] = temp_3;
    D_002B9350.unk_00[0x180 / 8] = temp_3;
    D_002B9350.unk_00[0x190 / 8] = temp_3;
    D_002B9350.unk_00[0x1A0 / 8] = temp_3;
    D_002B9350.unk_00[0x1B0 / 8] = temp_3;
    D_002B9350.unk_00[0x1D0 / 8] = temp_3;
    D_002B9350.unk_00[0x1F0 / 8] = temp_3;
    D_002B9350.unk_00[0x230 / 8] = temp_3;
    D_002B9350.unk_00[0x250 / 8] = temp_3;
    D_002B9350.unk_00[0x270 / 8] = temp_3;
    D_002B9350.unk_00[0x280 / 8] = temp_3;
    D_002B9350.unk_00[0x290 / 8] = temp_3;
    D_002B9350.unk_00[0x2A0 / 8] = temp_3;
    D_002B9350.unk_00[0x2C0 / 8] = temp_3;
    D_002B9350.unk_00[0x2E0 / 8] = temp_3;
    
    temp_5 = new_var2 | 0x100000000;
    
    D_002B9350.unk_00[0x50 / 8] = temp_5;
    D_002B9350.unk_00[0x70 / 8] = temp_5;
    D_002B9350.unk_00[0x90 / 8] = temp_5;
    D_002B9350.unk_00[0xA0 / 8] = temp_5;
    D_002B9350.unk_00[0xB0 / 8] = temp_5;
    D_002B9350.unk_00[0xC0 / 8] = temp_5;
    D_002B9350.unk_00[0xE0 / 8] = temp_5;
    D_002B9350.unk_00[0x100 / 8] = temp_5;

    temp_16 = D_004D2A8C | new_var4 | temp_7;
    
    func_001102C0();
    func_0010F3D0();
    func_00106948(&D_002B9650);
    func_001F2EF8(temp_16, 0xB6, 0x36, func_001F0EF0(5), 18);
    func_001F2EF8(temp_16, 0xD6, 0x36, func_001F0EF0(6), 18);
    func_001F2EF8(temp_16, 0xF6, 0x36, func_001F0EF0(7), 18);
    func_001F2EF8(temp_16, 0x116, 0x36, func_001F0EF0(8), 18);
    func_001F2EF8(temp_16, 0x136, 0x36, func_001F0EF0(9), 18);
    func_0010F420();
    sceGsSyncPath(0, 0);

    DPUT_GS_PMODE(0xFF03);
    DPUT_GS_DISPFB1(0x11B0);
    DPUT_GS_DISPLAY1(0x7F9FF020D227C);
}
#endif

void func_00113618(void) {
    D_004D2A8C = 205;
    D_004D2A90 = 135;
    D_004D2A94 = 50;
    D_004D2A98 = 128;
    D_004D2A9C = 76;
    D_004D2AA0 = 128;
}

INCLUDE_ASM(const s32, "xblade", func_00113660);

void func_001136C8(s32);
INCLUDE_ASM(const s32, "xblade", func_001136C8);

extern s32 D_004D2A80;
extern s32 D_004D2A84;
extern s32 D_004D2A88;
extern s32 D_004D2AA4;

INCLUDE_ASM(const s32, "xblade", func_00113710);
// void func_00113710(void) {
//     switch (D_004D2A80) {
//         default:
//         case 0:
//             return;
//         case 1:
//             switch (D_004D2A84) {
//                 case 0:
//                     if (D_004D2A88 < 2) {
//                         D_004D2A98 += 50;
//                         D_004D2A9C += 15;
//                         D_004D2AA0 += 25;
//                         break;
//                     }
//                     D_004D2A84 = 1;
//                 case 1:
//                     if (D_004D2A88 < 5) {
//                         D_004D2A8C += 25;
//                         D_004D2A90 += 2;
//                         D_004D2A94 -= 68;
//                         D_004D2A98 += 9;
//                         D_004D2A9C += 15;
//                         D_004D2AA0 += 25;
//                         break;
//                     }
//                     D_004D2A84 = 2;
//                 case 2:
//                     D_004D2AA4 = 0;
//                     func_00113618();
//                     break;
//             }
//             break;
//         case 2:
//             switch (D_004D2A84) {
//                 case 0:
//                     if (D_004D2A88 < 2) {
//                         D_004D2A98 -= 14;
//                         D_004D2A9C -= 15;
//                         D_004D2AA0 -= 25;
//                         break;
//                     }
//                     D_004D2A84 = 1;
//                 case 1:
//                     if (D_004D2A88 < 5) {
//                         D_004D2A8C -= 25;
//                         D_004D2A90 -= 2;
//                         D_004D2A94 += 68;
//                         D_004D2A98 -= 33;
//                         D_004D2A9C -= 15;
//                         D_004D2AA0 -= 25;
//                         break;
//                     }
//                     D_004D2A84 = 2;
//                 case 2:
//                     func_001136C8(0);

//                     if (D_002B9668 == 2) {
//                         func_00113A10(0);
//                     } else {
//                         func_00113A40(0);
//                     }
//                     D_004D2A80 = 0;
//                     return;
//             }
//             break;
//     }
//     func_00113410();
//     D_004D2A88++;
// }

void func_001139F8(void) {
    D_004D2A68 = 0;
    D_004D2A6C = 0;
}

void* func_00113A10(s32 arg0) {
    void* p0 = func_001EE280(arg0);
    D_004D2A6C = arg0;
    return p0;
}

void func_00113A40(s32 arg0) {
    if (arg0 == 0) {
        D_004D2A68--;
        if (D_004D2A68 == 0) {
            if (D_004D2A6C == 1) {
                func_00113A10(arg0);
                func_001EEC58();
                func_001102C0();
                func_00113A10(1);
            } else {
                func_00113A10(arg0);
            }
        }
    } else {
        func_001EE280(2);
        D_004D2A68++;
        if (D_004D2A68 == 0) {
            D_004D2A68++;
            printf("ERROR:sound pause\n");
        }
    }
}

s32 func_00113AF8(void) {
    func_00102970(0x80, 0x20);

    if (D_004D2A70 == 4) {
        return 0;
    }
    return 4;
}

s32 func_00113B30(void) {
    XPointy* p0 = func_0011ED30(10499, func_00113AF8);
    p0->unk_02 = 1;
    func_00102970(0x80, 0x10);
    D_004D2A70 = 3;
    return 4;
}

s32 func_00113B78(void) {
    XPointy* p0 = func_0011ED30(190019, func_00113B30);
    p0->unk_02 = 1;
    func_0010A108();
    func_00102970(0x80, 0x10);
    return 4;
}

s32 func_00113BC0(void) {
    func_00102970(0x80, 0);
    if (D_003F0DD8 != 0) {
        D_003F0DD8 = 0;
        func_00112A50();
    }
    D_004D2A70 = 0;
    D_002B9664 = 0;
    sceGsSyncPath(0, 0);
    func_00121D50(D_002B2CC8);
    func_001778A0(0);
    D_004D2A60 = 0;
    return 4;
}

s32 func_00113C40(void) {
    XPointy* p0;

    func_00102970(0x80, 0x10);
    p0 = func_0011ED30(190019, func_00113BC0);
    p0->unk_02 = -1;
    return 4;
}

s32 func_00113C80(void) {
    func_00102970(0x80, 0x20);
    return 4;
}

void func_00113CA8(void) {
    D_002B9668 = 1;
}

INCLUDE_ASM(const s32, "xblade", func_00113CB8);

void func_00113E18(void) {
    D_002C1EBC = 1;
}

void func_00113E28(void) {
    D_002C1EBC = 0;
}

void func_00113E38(void) {
    func_001778A0(1);
    D_004D2A70 = 1;
    D_004D2A60 = 1;
}

INCLUDE_ASM(const s32, "xblade", func_00113E68);

static const char padding[] = "\0\0"; // TODO likely file split

INCLUDE_ASM(const s32, "xblade", func_00113E98);
// s32 func_00113E98(void) {
//     s32 init1;
//     f32 temp_f20;
//     s32 init2;
//     s32 ret;

//     if (((D_002B8330 == 3) || (ret = 1, (D_002B8330 == 5))) && (ret = 1, (D_002B2CC4 == 0))) {
//         if (D_004D2A74 == 0) {
//             switch (D_002B9668) {
//                 case 1:
//                 case 2:
//                     D_004D2A7C = 1;
//                     D_004D2A78 = 0;
//                     D_004D2A80 = 0;
//                     D_004D2AA4 = 0;
//                     temp_f20 = D_002B8340[1];
//                     init1 = D_002B8354;
   
//                     do {
//                         init2 = D_004D2A80;
//                         if (D_004D2AA4 == 0) {
//                             if (D_002C2020[2] & 8) {
//                                 D_002B8354 = 0;
//                                 D_004D2A78 ^= 1;
//                                 D_004D2AA4 = 1;

//                                 do {
//                                     D_004D2A88 = 0;
//                                     D_004D2A84 = 0;
//                                 } while (0);

//                                 switch (init2) {
//                                     case 0:
//                                         if (D_002B9668 == 2) {
//                                             func_00113A10(1);
//                                         } else {
//                                             func_00113A40(1);
//                                         }
//                                         D_004D2A8C = 0x80;
//                                         D_004D2A90 = 0x80;
//                                         D_004D2A94 = 0xFF;
//                                         D_004D2A80 = 1;
//                                         D_004D2A98 = 0;
//                                         D_004D2A9C = 0;
//                                         D_004D2AA0 = 0;
//                                         break;
//                                     case 1:
//                                         D_004D2A80 = 2;
//                                         func_00113618();
//                                         break;
//                                 }
//                                 D_002B9664 ^= 1;
//                             }
//                         }

//                         if (init2 != 0) {
//                             func_00113710(D_004D2A78);
//                             D_002B9664 = 1;
//                             func_001224B8();
//                             func_0010FB90();
//                             if (func_00109468() == 0) {
//                                 break; 
//                             } 
//                             if (func_0010F768() != 0) {
//                                 func_001136C8(D_004D2A78);
//                             }
//                             func_001102C0();
//                         } else {
//                             D_004D2A7C = 0;
//                             D_002B9664 = 0;
//                             D_002B8354 = init1;
//                             D_002B8340[1] = temp_f20;
//                         }
//                     } while (D_004D2A7C != 0);

//                     break;
//                 case 4:
//                     if (D_002BD858 != 0) {
//                         func_00113E38();
//                         D_004D2A64 = D_002BD858;
//                         func_0011C5A8();
//                     }
//                     break;
//                 case 5:
//                     if (D_002BD85C != 0) {
//                         func_00113E38();
//                         func_0011C5C8();
//                     }
//                     break;
//                 case 3:
//                     if (D_004D2A70 == 0) {
//                         if (D_002C2028 & 8) {
//                             func_00113E38();
//                         }
//                     }
//                     break;
//             }
//         }

//         switch (D_004D2A70) {
//             case 0:
//                 D_002C1EBC = 0;
//                 break;
//             case 1:
//                 func_00113E18();
//                 ((XGoblin*)func_0011ED30(190020, &func_00113B78))->unk_02 = 1;
//                 D_004D2A70 = 2;
//                 break;
//             case 2:
//                 func_00113E18();
//                 break;
//             case 3:
//                 func_00113E18();
//                 func_00113A10(1);
//                 switch (D_002B9668) {
//                     case 0:
//                         func_00113E68();
//                         D_002B29C8 = disk_Mgr.unk_1C();
//                         func_00157B90();
//                         func_0020D4C0(1);
//                     case 1:
//                     case 2:
//                         break;
//                     case 3:
//                         func_00113E68();
//                         func_0022B248(1);
//                         break;
//                     case 4:
//                         func_00113E68();
//                         func_00111328();
//                         func_00157B90();
//                         func_002277D8(1, D_004D2A64);
//                         break;
//                     case 5:
//                         func_00113E68();
//                         func_00157B90();
//                         func_002279D8(1);
//                         break;
//                 }
//                 D_004D2A70 = 4;
//                 break;
//             case 4:
//                 func_00113E18();
//                 if (D_003ED704 == 0) {
//                     if (D_003F0DD8 != 0) {
//                         D_002B9660 = 1;
//                     }
//                     if (D_002B9668 == 3) {
//                         func_001DDFA0(D_003F1454);
//                     }
//                     func_00113A10(0);
//                     D_004D2A70 = 5;
//                 }
//                 break;
//             case 5:
//                 D_002B8354 = 1;
//                 ((XGoblin*)func_0011ED30(190021, &func_00113C40))->unk_02 = -1;
//                 func_00113E28();
//                 D_004D2A70 = 6;
//                 break;
//             case 6:
//                 func_00113E28();
//                 break;
//             default:
//                 func_00113E28();
//                 break;
//         }
//         ret = D_002B8350;
//     }
//     return ret;
// }

void func_00114400(void) {
    D_002B966C = 1;
}

void func_00114410(void) {
    D_002B966C = 0;
}

void func_00114420(void) {
    D_004D2A74 = 1;
}

void func_00114430(void) {
    D_004D2A74 = 0;
}

INCLUDE_ASM(const s32, "xblade", func_00114440);

INCLUDE_ASM(const s32, "xblade", func_00114480);

INCLUDE_ASM(const s32, "xblade", func_001144C8);

INCLUDE_ASM(const s32, "xblade", func_001145B0);

INCLUDE_ASM(const s32, "xblade", func_001145E8);

INCLUDE_ASM(const s32, "xblade", func_00114638);
// s32 func_00114638(sceVu0FMATRIX arg0, f32 arg1, s32 arg2, s32 arg3) {
//     f32* temp_16;
//     sceVu0FVECTOR* temp_2;
//     s32 temp_4;
//     s32 ret;
//     f32* temp_3;

//     temp_2 = func_00122430(0x110, 0x80);
//     temp_3 = arg1 + 0x18;
//     temp_2[0][1] = *temp_3;
//     temp_16 = arg1 + *temp_3;
//     temp_2[0][0] = temp_16;
//     D_004D2AA8 = temp_2;
//     ret = 0;
//     sceVu0ApplyMatrix(D_004D2AA8 + 0x80 / 4, arg0, *D_004D2AA8 + 0x00 / 4);
//     sceVu0ApplyMatrix(D_004D2AA8 + 0x90 / 4, arg0, *D_004D2AA8 + 0x10 / 4);
//     sceVu0ApplyMatrix(D_004D2AA8 + 0xA0 / 4, arg0, *D_004D2AA8 + 0x20 / 4);
//     sceVu0ApplyMatrix(D_004D2AA8 + 0xB0 / 4, arg0, *D_004D2AA8 + 0x30 / 4);
//     sceVu0ApplyMatrix(D_004D2AA8 + 0xC0 / 4, arg0, *D_004D2AA8 + 0x40 / 4);
//     sceVu0ApplyMatrix(D_004D2AA8 + 0xD0 / 4, arg0, *D_004D2AA8 + 0x50 / 4);
//     sceVu0ApplyMatrix(D_004D2AA8 + 0xE0 / 4, arg0, *D_004D2AA8 + 0x60 / 4);
//     sceVu0ApplyMatrix(D_004D2AA8 + 0xF0 / 4, arg0, *D_004D2AA8 + 0x70 / 4);
//     sceVu0MulMatrix(D_004D2AA8 + 0x10 / 4, D_002B84F0, D_00297850);
//     if (func_0024B800(D_004D2AA8 + 0x10 / 4, D_004D2AA8 + 0x80 / 4) == 0) {
//         if (arg2 == 40000) {
//             func_00106A08(&D_002B9690, 40000);
//         }
//         temp_4 = D_004D2AAC;
//         D_004D2AAC++;
//         func_00108C48(temp_4, arg2, arg0, D_004D2AA8, arg3);
//         ret = 1;
//     }
//     func_001224A0(D_004D2AA8);
//     return ret;
// }

void func_00114800(void) {
    D_004D2AAC = 0;
    D_004D2AB0 = 0;
}

INCLUDE_ASM(const s32, "xblade", func_00114818);

INCLUDE_ASM(const s32, "xblade", func_001149B0);

INCLUDE_ASM(const s32, "xblade", func_00114A50);

void func_00114B18(f32* arg0, s32 arg1) {
    if (arg1 == -1) {
        func_00117588(arg0);
        return;
    }
    func_0011AED0(arg1, arg0);
}

INCLUDE_ASM(const s32, "xblade", func_00114B50);

s32 func_00114C18(s32 arg0, s32 arg1, s32 arg2) {
    if (arg0 == -1) {
        return func_00104AA8(arg1, arg2);
    }
    return func_0011A648(arg0, arg1, arg2);
}

s32 func_00114C58(s32 arg0, s32 arg1, s32 arg2) {
    if (arg0 == -1) {
        return func_00104AA8(arg1, arg2);
    }
    return func_0011A7F8(arg0, arg1, arg2);
}

void func_00114C98(s32 arg0, s32 arg1, s32 arg2) {
    if (arg0 == -1) {
        func_00104CF8(arg1, arg2);
        return;
    }
    func_0011A758(arg0, arg1, arg2);
}
