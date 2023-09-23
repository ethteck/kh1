#include "common.h"

#include "gcc/stdio.h"

#include "sdk/ee/libvu0.h"

typedef struct XAppleStemTip {
    /* 0x00 */ char unk_00[0x48];
    /* 0x48 */ s32 unk_48;
} XAppleStemTip;

typedef struct XAppleStem {
    /* 0x00 */ s32 unk_00[0x6C / 4];
    /* 0x6C */ XAppleStemTip *unk_6C;
} XAppleStem;

typedef struct XApple4 {
    /* 0x00 */ s32 unk_00[4];
} XApple4;

typedef union X32 {
    s32 s32;
    u8 u8[4];
} X32;

typedef struct XAppleBlemish {
    /* 0x000 */ s32 unk_00;
    /* 0x004 */ X32 unk_04;
    /* 0x008 */ char unk_08[0x8];
    /* 0x010 */ f32 unk_10;
    /* 0x014 */ char unk_14[0x28];
    /* 0x03C */ f32 unk_3C;
    /* 0x040 */ char unk_40[0x90];
    /* 0x0D0 */ sceVu0FMATRIX unk_D0;
    /* 0x110 */ char unk_110[0x10];
    /* 0x120 */ sceVu0FVECTOR unk_120;
    /* 0x134 */ char unk_130[0x240];
    /* 0x370 */ u64 unk_370;
    /* 0x374 */ char unk_378[0xCC];
    /* 0x444 */ s32 unk_444;
} XAppleBlemish;

// funcs
s32 func_0011ED30(s32, s32 (*func)(void));
s32 func_0011EF58(s32*, s32);
s32 func_00120590(char*, void*, void*, void*);
f32 func_00120A38(sceVu0FVECTOR);
f32 func_00120A58(f32*);
f32 func_00120AC8(f32);
void func_001223B0(f32*, f32*);
XAppleBlemish* func_001234A0(XAppleBlemish*);
void func_00123830(XAppleBlemish*, s32);
void func_00123E48(s32, sceVu0FVECTOR);
void func_00124BC8(XAppleBlemish*);
void func_00130248(XAppleBlemish*, f32, UNK_PTR);
void func_001313A8(XAppleBlemish*, UNK_PTR);
void func_00131410(XAppleBlemish*);
s32 func_00132160(s32, s32, s32);
void func_001372F8(f32, XAppleBlemish*);
void func_00137348(XAppleBlemish*);
void func_0013A790(void);
s32 func_0013B1D0(void);
void func_0013B578(void);
s32 func_0013BD88(s32*, s32*, s32);
s32 func_0013BDA0(s32*);
s32 func_00157B90(void);
void func_00163638(sceVu0FMATRIX, sceVu0FMATRIX);
void func_00177828(s32);
void func_001778A0(s32);
void func_001778B8(s32);
f32 func_00177D68(void);
void func_001C64E0(UNK_PTR, UNK_PTR, UNK_PTR);
s32 func_001EE090(void);

// ???
extern s32 func_F20000(s32, s32);

// .data
extern f32 D_002B8340[];
extern s32 D_002C1E00;
extern sceVu0FMATRIX D_002C1E20;
extern u32 D_002C1EA8;
extern u32 D_002C1EC8;
extern XAppleStem* D_002DEC00;
extern sceVu0FVECTOR D_002DECE0;
extern sceVu0FVECTOR D_002DECF0;
extern u32 D_002DED20;
extern sceVu0FVECTOR D_00301030;
extern sceVu0FVECTOR D_00301040;
extern s32 D_00301088;
extern s32 D_00301010[];
extern s32 D_00301050;
extern s32 D_00301054;
extern s32 D_00301058;
extern u32 D_00375BC0;

// .rodata
extern char D_004879D0[]; // "%s%s"

// .bss ?
extern f32 D_005324B4;
extern f32 D_005324B8;
extern f32 D_005324BC;
extern sceVu0FVECTOR D_005324C0;
extern sceVu0FVECTOR D_005324D0;
extern sceVu0FVECTOR D_005324E0;
extern sceVu0FVECTOR D_005324F0;
extern f32 D_00532500;
extern s32 D_00532508;
extern s32 D_00532518;
extern XAppleBlemish* D_005325E8;
extern XAppleBlemish* D_005325EC;
extern sceVu0FVECTOR D_005325F0;
extern s32 D_00532600;
extern s32 D_00532604;
extern XApple4* D_00532608;
extern s32* D_0053260C;
extern s32 D_00532610;

s32 func_0013AB68(u16* arg0) {
    sceVu0FVECTOR sp0;
    sceVu0FVECTOR sp10;
    sceVu0FMATRIX sp20;
    sceVu0FMATRIX sp60;

    f32 var_f21;
    f32 ry;
    f32 s;
    f32 fVar1;
    f32 fVar2;

    if (((D_002C1EA8 >> 20) & 1) == 0) {
        return 4;
    }

    if (*arg0 & 0x10) {
        func_00163638(D_005325E8->unk_D0, sp60);
        D_002DECF0[3] = 1.0f;
        D_002DECE0[3] = 1.0f;
        sceVu0ApplyMatrix(D_005324D0, sp60, D_002DECE0);
        sceVu0ApplyMatrix(D_005324E0, sp60, D_002DECF0);
        sceVu0SubVector(D_005324C0, D_00301040, D_005324D0);
        D_005324B8 = func_00120A38(D_005324C0);
        sceVu0SubVector(D_005324C0, D_005324E0, D_005324D0);
        sceVu0Normalize(D_005324C0, D_005324C0);
        sceVu0ScaleVector(D_005324C0, D_005324C0, D_005324B8);
        sceVu0AddVector(D_005324E0, D_005324C0, D_005324D0);
        sceVu0SubVector(D_005324F0, D_005324D0, D_005324E0);
        D_005324F0[1] = 0.0f;
        func_001223B0(D_005324F0, D_005324F0);
        D_005324B8 = D_005324F0[3];
        D_005324F0[3] = 1.0f;
        sceVu0SubVector(D_005324C0, D_00301030, D_00301040);
        D_005324BC = func_00120A58(D_005324C0) - D_005324B8;

        fVar1 = atan2f(D_005324D0[0] - D_005324E0[0], D_005324D0[2] - D_005324E0[2]);
        fVar2 = atan2f(D_00301030[0] - D_00301040[0], D_00301030[2] - D_00301040[2]);
        D_005324B4 = func_00120AC8(fVar2 - fVar1);

        if (func_00177D68() < 0.5f) {
            if (D_005324B4 < 0.0f) {
                D_005324B4 += 6.2831855f;
            } else {
                D_005324B4 -= 6.2831855f;
            }
        }
        if (func_00177D68() < 0.5f) {
            D_005324B4 += 0.5235988f;
        } else {
            D_005324B4 -= 0.5235988f;
        }
        D_00532500 = 40.0f;
    }

    D_00532500 -= D_002B8340[1];
    var_f21 = D_00532500 / 40.0f;
    if (var_f21 < 0.0f) {
        var_f21 = 0.0f;
    }

    var_f21 = (cosf(var_f21 * 3.1415928f) + 1.0f) * 0.5f;
    sceVu0InterVector(sp10, D_00301040, D_005324E0, var_f21);
    ry = func_00120AC8(D_005324B4 * var_f21);
    sceVu0RotMatrixY(sp20, D_002C1E20, ry);
    sceVu0ApplyMatrix(D_005324C0, sp20, D_005324F0);
    s = D_005324B8 + D_005324BC * var_f21;
    sceVu0ScaleVector(D_005324C0, D_005324C0, s);
    sceVu0AddVector(sp0, sp10, D_005324C0);
    sp0[3] = 1.0f;
    sp10[3] = 1.0f;
    sp0[1] = (D_00301030[1] * var_f21) + (D_005324D0[1] * (1.0f - var_f21));
    sceVu0ApplyMatrix(D_002DECE0, D_005325E8->unk_D0, sp0);
    sceVu0ApplyMatrix(D_002DECF0, D_005325E8->unk_D0, sp10);
    return 0;
}

INCLUDE_ASM(const s32, "unnamed_apple", func_0013AFE8);

void func_0013B138(void) {
    if (D_0053260C[2] - D_0053260C[1] > 0) {
        func_001560C8((s32)D_0053260C + D_0053260C[1]);
    }
    if (D_0053260C[3] - D_0053260C[2] > 0) {
        func_001560C8((s32)D_0053260C + D_0053260C[2]);
    }
    if (D_0053260C[4] - D_0053260C[3] > 0) {
        func_00177908((s32)D_0053260C + D_0053260C[3]);
    }
    FlushCache(2);
    D_00532604 = 4;
}

INCLUDE_ASM(const s32, "unnamed_apple", func_0013B1D0);

// s32 func_0013B1D0(void) {
//     XAppleBlemish* var_17;
//     s32 var_16;

//     var_17 = NULL;
//     do {
//         var_17 = func_001234A0(var_17);
//         if (var_17 == NULL) {
//             break;
//         }

//         if (var_17 == D_005325E8) {
//             var_16 = var_17->unk_00 | 0x30;
//             var_16 &= ~0x2;
//             func_001372F8(0.0f, var_17);
//             var_17->unk_370 |= 0x10000000000000;
//         } else {
//             var_16 = var_17->unk_00 & ~0x8000;
//             func_00137348(var_17);
//             sceVu0CopyVector(var_17->unk_120, D_002C1E00 + 0x1E00);
//         }
//         func_00123830(var_17, var_16);

//     } while (TRUE);

//     sceVu0CopyVector(D_005325F0, &D_005325E8->unk_10);
//     D_005325F0[3] = D_005325E8->unk_3C;
//     func_00123E48(D_005325E8->unk_04.s32, D_002C1E00);
//     func_00177828(D_00532610);
//     func_001778B8(0);
//     func_001778A0(1);
//     D_002C1EA8 &= ~0x100000;
//     D_002C1EA8 |= 0x4000;
//     if (((s32)((D_002C1EC8 >> 8) % 4) < 2) && (D_00532608[1].unk_00[1] != D_00532608[1].unk_00[0])) {
//         func_001313A8(D_005325E8, (s32)D_00532608 + D_00532608->unk_00[3]);
//         func_001C64E0((s32)D_00532608 + D_00532608[1].unk_00[0], (s32)D_00532608 + D_00532608[1].unk_00[1], (s32)D_00532608 + D_00532608[1].unk_00[2]);
//     }
//     return 4;
// }

s32 func_0013B368(void) {
    char something[0x20];

    if (D_00532604 != 2 || (func_001EE090() != 0)) {
        return 0;
    }
    func_00157B90();
    D_00532604 = 3;
    sprintf(something, D_004879D0, D_00301010[D_00532600], D_00301050);
    func_00120590(something, D_0053260C, NULL, 0);
    sprintf(something, D_004879D0, D_00301010[D_00532600], D_00301054);
    func_00120590(something, &func_F20000, &func_0013B138, 0);
    func_0011ED30(47000, &func_0013B1D0);
    return 1;
}

INCLUDE_ASM(const s32, "unnamed_apple", func_0013B480);

// typedef struct LargeApple {
//     /* 0x00 */ char unk_00[0x30];
//     /* 0x30 */ f32 unk_30[3];
//     /* 0x3C */ f32 unk_3C;
// } LargeApple;

// typedef struct OtherApple {
//     /* 0x00 */ u16 unk_00;
//     /* 0x02 */ char unk_02[0xE];
//     /* 0x10 */ f32 unk_10;
// } OtherApple;

// s32 func_001009A8();
// void* func_00122AF8(s32, s32, s32);
// s32 func_00122B70(void*);
// extern f32 D_002B8340[];
// extern LargeApple* D_00532504;

// s32 func_0013B480(OtherApple* arg0) {
//     f32 temp_f2;

//     if (arg0->unk_00 & 0x10) {
//         LargeApple* a;

//         D_00532504 = func_00122AF8(1, 9, 0);
//         D_00532504->unk_30[0] = D_00532504->unk_30[1] = D_00532504->unk_30[2] = 0.0f;
//         D_00532504->unk_3C = 1.0f;
//         func_001009A8();
//         arg0->unk_10 = 60.0f;
//     }
//     arg0->unk_10 -= D_002B8340[1];

//     temp_f2 = arg0->unk_10 / 60.0f;
//     if (arg0->unk_10 / 60.0f <= 0.0f) {
//         func_00122B70(D_00532504);
//         return 4;
//     }
//     D_00532504->unk_30[0] = D_00532504->unk_30[1] = D_00532504->unk_30[2] = 1.0f - temp_f2;
//     return 0;
// }

INCLUDE_ASM(const s32, "unnamed_apple", func_0013B578);
// int func_0011EEB8(int*, int, int*);
// int func_00123858(void*);
// void func_001250B0(void);
// void func_00133588(void);
// void func_001452E0(int, int);
// void func_0014F8B0(XAppleBlemish*, int);
// void func_0023E0B0(int, int);

// extern int func_0013B480;

// void func_0013B578(void) {
//     XAppleBlemish* var_16;

//     func_00133588();
//     func_001250B0();
//     func_0023E0B0(0, 1);
//     var_16 = func_001234A0(NULL);
//     if (var_16 != NULL) {
//         do {
//             if (!((var_16->unk_370 >> 0x21) & 1) && (var_16 != D_002DEC00->unk_00[1]) && (var_16 != D_002DEC00->unk_00[2])) {
//                 func_00123858(var_16);
//             }
//             var_16 = func_001234A0(var_16);
//         } while (var_16 != NULL);
//     }
//     func_0014F8B0(D_005325E8, 0);
//     func_00123E48(D_005325E8->unk_04.s32, D_005325F0);
//     func_00131410(D_005325E8);
//     func_00130248(D_005325E8, 0.0f, 0x40000000);
//     D_005325E8->unk_370 &= ~0x10000000000000;
//     D_005325E8->unk_00 &= ~0x200000;
//     D_005325E8->unk_444 = 0;
//     func_001778A0(0);
//     D_002C1EA8 &= ~0x4000;
//     func_001452E0(0, 4);
//     func_0011EEB8(&D_00532518, 0, &func_0013B480);
// }

INCLUDE_ASM(const s32, "unnamed_apple", func_0013B6E0);

// s32 func_0013B6E0(void) {
//     XAppleBlemish* var_4;

//     if (((D_00375BC0 >> 2) & 1) != 0 || D_00532604 != 4 || func_001EE090() != 0) {
//         return 0;
//     }

//     func_0013B578();
//     D_005325EC = NULL;
//     var_4 = NULL;

//     do {
//         var_4 = func_001234A0(var_4);
//         if (var_4 == NULL) {
//             break;
//         }
//         if (var_4->unk_04.u8[2] == 7) {
//             D_005325EC = var_4;
//             break;
//         }
//     } while (TRUE);

//     if (D_005325EC != NULL) {
//         if ((D_0053260C[2] - D_0053260C[1]) > 0) {
//             func_001313A8(D_005325EC, (s32)D_0053260C + D_0053260C[1]);
//             func_00130248(D_005325EC, 0.0f, 0);
//             D_005325EC->unk_00 &= ~0x30;
//         }
//         D_005325EC->unk_444 = 0;
//     }
//     if ((((u32) D_002C1EC8 >> 8) % 4) != 1) {
//         if (D_0053260C[3] - D_0053260C[2] > 0) {
//             func_001313A8(D_005325E8, (s32)D_0053260C + D_0053260C[2]);
//             func_00130248(D_005325E8, 0.0f, 0);
//         }
//         func_F20000(0, ((D_0053260C[4] - D_0053260C[3]) <= 0) ? NULL : ((s32)D_0053260C + D_0053260C[3]));
//     } else {
//         func_00124BC8(D_005325EC);
//         func_00131410(D_005325E8);
//         func_00130248(D_005325E8, 0.0f, 0x40000000);
//     }
//     return 1;
// }

s32 func_0013B890(void) {
    if ((((D_002C1EC8 >> 8) % 4) == 1) || (func_F20000(1, 0) == 0)) {
        func_0013A790();
        D_002C1EA8 &= ~0x2000;
        D_00301088 = 0;
        return 1;
    }
    return 0;
}

s32 func_0013B8F8(u16* arg0) {
    if (*arg0 & 0x10) {
        func_0013BD88(&D_00532508, &D_00301058, 4);
    }
    func_0011EF58(&D_00532518, 0);
    return (func_0013BDA0(&D_00532508) != 0) ? 0 : 4;
}

void func_0013B968(s32 arg0) {
    func_00132160(
        arg0,
        (s32)D_00532608->unk_00 + D_00532608->unk_00[1],
        ((D_00532608->unk_00[3] - D_00532608->unk_00[2]) <= 0) ? 0 : ((s32)D_00532608->unk_00 + D_00532608->unk_00[2])
    );
}
void func_0013B9A8(void) {
    D_00532604 = 2;
}

INCLUDE_ASM(const s32, "unnamed_apple", func_0013B9B8);

f32 func_0013BAC0(void) {
    return (D_002DEC00->unk_6C->unk_48 + ((s32)(D_002DED20 >> 0xA) & 7)) * 3000;
}

// s32 func_0011EDD0(s32*, s32*, s32, s32);
// s32 func_00141668(XAppleBlemish*, s32);
// XApple4* func_00155ED8(s32, s32);
// void func_00157AD8(s32);

// typedef struct AppleWormInner {
//     /* 0x00 */ u8 unk_00;
//     /* 0x01 */ char unk_01[0x7];
// } AppleWormInner;

// typedef struct AppleWorm {
//     /* 0x00 */ char unk_00[0x98];
//     /* 0x98 */ AppleWormInner unk_98[2];
// } AppleWorm;

// extern s32 D_00301078;
// extern s32 D_00301080;
// extern f32 D_0030108C;
// extern f32 D_00301090;
// extern s32 D_00301094;
// extern AppleWorm* D_003051EC;

// extern s32 D_00532528;

// extern s32 func_0013B9B8;

// void func_0013BB00(s32 arg0, s32 arg1) {
//     char something[0x30];

//     D_002C1EA8 |= 0x102000;
//     D_00301080 = &D_003051EC.unk_98[arg1].unk_00;
//     D_00301088 = (D_00301088 & ~7) | (arg1 & 7) | 8;
//     D_00301094 |= 1 << arg1;
//     D_0030108C = func_0013BAC0();
//     D_00301090 = D_0030108C;
//     func_00141668(arg0, -D_003051EC.unk_98[arg1].unk_00);
//     D_005325E8 = arg0;
//     D_00532600 = arg1;
//     func_00157AD8(1);
//     func_00157AD8(2);
//     func_00157AD8(3);
//     D_00532604 = 0;
//     D_00532608 = func_00155ED8(0x34, 0xC);
//     sprintf(something, &D_004879D0, D_00301010[arg1], D_00301078);
//     func_00120590(something, D_00532608, &func_0013B9B8, 0);
//     func_0011EDD0(&D_00532518, &D_00532528, 0x18, 8);
//     func_0011ED30(52000, &func_0013B8F8);
// }

INCLUDE_ASM(const s32, "unnamed_apple", func_0013BB00);
