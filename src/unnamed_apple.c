#include "common.h"

typedef struct AppleStemTip {
    /* 0x00 */ char unk_00[0x48];
    /* 0x48 */ s32 unk_48;
} AppleStemTip;

typedef struct AppleStem {
    /* 0x00 */ s32 unk_00[0x6C / 4];
    /* 0x6C */ AppleStemTip *unk_6C;
} AppleStem;

typedef struct Apple4 {
    /* 0x00 */ s32 unk_00[4];
} Apple4;

typedef struct AppleBlemish {
    /* 0x000 */ s32 unk_00;
    /* 0x004 */ s32 unk_04;
    /* 0x008 */ char unk_08[0x368];
    /* 0x370 */ u64 unk_370;
    /* 0x374 */ char unk_378[0xC8];
    /* 0x444 */ s32 unk_444;
} AppleBlemish;

extern s32 func_0013B1D0;

// .data
extern s32 D_002C1EA8;
extern u32 D_002C1EC8;
extern s32 D_00301088;
extern AppleStem *D_002DEC00;
extern u32 D_002DED20;
extern s32 D_00301010[];
extern s32 D_00301050;
extern s32 D_00301054;
extern s32 D_00301058;

// .rodata
extern char *D_004879D0; // "%s%s"

// .bss ?
extern s32 D_00532508;
extern s32 D_00532518;
extern s32 D_00532600;
extern s32 D_00532604;
extern Apple4* D_00532608;
extern s32* D_0053260C;

// ???
extern s32 func_F20000(s32, s32);

s32 func_0011ED30(s32, s32*);
s32 func_0011EF58(s32*, s32);
s32 func_00120590(void*, s32*, s32*, s32);
s32 func_00132160(s32, s32, s32);
s32 func_0013A790();
s32 func_0013BD88(s32*, s32*, s32);
s32 func_0013BDA0(s32*);
s32 func_00157B90(void);
s32 func_001EE090(void);
s32 sprintf(void*, s32*, s32, s32);

INCLUDE_ASM(const s32, "unnamed_apple", func_0013AB68);

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

s32 func_0013B368(void) {
    char something[0x20];

    if (D_00532604 != 2 || (func_001EE090() != 0)) {
        return 0;
    }
    func_00157B90();
    D_00532604 = 3;
    sprintf(something, &D_004879D0, D_00301010[D_00532600], D_00301050);
    func_00120590(something, D_0053260C, NULL, 0);
    sprintf(something, &D_004879D0, D_00301010[D_00532600], D_00301054);
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
// void* func_001234A0(void*);
// int func_00123858(void*);
// int func_00123E48(s32, int*);
// int func_001250B0();
// int func_00130248(void*, f32, int);
// int func_00131410(void*);
// int func_00133588();
// int func_001452E0(int, int);
// int func_0014F8B0(void*, int);
// int func_001778A0();
// int func_0023E0B0(int, int);

// extern AppleBlemish* D_005325E8;
// extern int D_005325F0;
// extern int func_0013B480;

// void func_0013B578(void) {
//     AppleBlemish* var_16;

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
//     func_00123E48(D_005325E8->unk_04, &D_005325F0);
//     func_00131410(D_005325E8);
//     func_00130248(D_005325E8, 0, 0x40000000);
//     D_005325E8->unk_370 &= ~0x10000000000000;
//     D_005325E8->unk_00 &= 0xFFDFFFFF;
//     D_005325E8->unk_444 = 0;
//     func_001778A0();
//     D_002C1EA8 &= ~0x4000;
//     func_001452E0(0, 4);
//     func_0011EEB8(&D_00532518, 0, &func_0013B480);
// }

INCLUDE_ASM(const s32, "unnamed_apple", func_0013B6E0);

// s32* func_001234A0(s32*);
// s32 func_00124BC8(s32*);
// s32 func_00130248(s32*, f32, s32);
// s32 func_001313A8(s32*, void*);
// s32 func_00131410(s32*);
// s32 func_0013B578();
// s32 func_001EE090();

// extern u32 D_002C1EC8;
// extern u32 D_00375BC0;
// extern s32* D_005325E8;
// extern AppleBlemish* D_005325EC;
// extern s32 D_00532604;

// s32 func_0013B6E0(void) {
//     AppleBlemish **new_var;
//     AppleBlemish* var_4;

//     if (((D_00375BC0 >> 2) & 1) || (D_00532604 != 4) || (func_001EE090() != 0)) {
//         return 0;
//     } else {
//         func_0013B578();
//         D_005325EC = NULL;
//         var_4 = NULL;

//         do {
//             var_4 = func_001234A0(var_4);
//             if (var_4 == NULL) {
//                 break;
//             }
//             if (var_4->unk_06 == 7) {
//                 D_005325EC = var_4;
//                 break;
//             }
//         } while (1);

//         if (D_005325EC != NULL) {
//             if ((D_0053260C[2] - D_0053260C[1]) > 0) {
//                 func_001313A8(D_005325EC, (s32)D_0053260C + D_0053260C[1]);
//                 func_00130248(D_005325EC, 0.0f, 0);
//                 D_005325EC->unk_00 &= ~0x30;
//             }
//             D_005325EC->unk_444 = 0;
//         }
//         if (((D_002C1EC8 >> 8) % 4) != 1) {
//             if (D_0053260C[3] - D_0053260C[2] > 0) {
//                 func_001313A8(D_005325E8, (s32)D_0053260C + D_0053260C[2]);
//                 func_00130248(D_005325E8, 0.0f, 0);
//             }
//             func_F20000(0, ((D_0053260C[4] - D_0053260C[3]) <= 0) ? NULL : ((s32)D_0053260C + D_0053260C[3]));
//         } else {
//             func_00124BC8(D_005325EC);
//             func_00131410(D_005325E8);
//             func_00130248(D_005325E8, 0.0f, 0x40000000);
//         }
//         return 1;
//     }
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
// f32 func_0013BAC0(void);
// s32 func_00141668(s32, s32);
// s32 func_00155ED8(s32, s32);
// s32 func_00157AD8(s32);

// typedef struct AppleWormInner {
//     /* 0x00 */ u8 unk_00;
//     /* 0x01 */ char unk_01[0x7];
// } AppleWormInner;

// typedef struct AppleWorm {
//     /* 0x00 */ char unk_00[0x98];
//     /* 0x98 */ AppleWormInner unk_98[2];
// } AppleWorm;

// extern s32 D_002C1EA8;
// extern s32 D_00301078;
// extern s32 D_00301080;
// extern s32 D_00301088;
// extern f32 D_0030108C;
// extern f32 D_00301090;
// extern s32 D_00301094;
// extern AppleWorm D_003051EC;

// extern s32 D_00532518;
// extern s32 D_00532528;
// extern s32 D_005325E8;
// extern s32 D_00532600;
// extern s32 D_00532604;

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
