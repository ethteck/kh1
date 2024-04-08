#include "common.h"
#include "worldfile.h"

// .data
extern s32 D_002A050C;
extern s32 D_002A0520[2];
extern s32 D_002B8688;
extern s32 D_002B868C;
extern s32 D_002B9040;
extern s32 D_002B930C;
extern s32 D_002B9338;
extern s32 D_002BD8B8[2];
extern s32 D_002BD8DC;

// todo: .rodata also used in func_001011E0
const char D_00486970[] = ".img";

// .bss
extern s32 D_0048DE90[2];

extern s32 func_001011B8();
extern void func_0011C6C8(s32);

INCLUDE_ASM(const s32, "xporcupine", func_001011E0);

s32 func_001014A8() {
    char stack[64];

    strcpy(stack, worldBinImgFile);
    strcat(stack, D_00486970);
    // strcat(stack, ".img");
    D_002A050C = func_00155ED8(0x34, 8);
    D_002A050C = func_001133E0(D_002A050C, 0x80);
    return func_00120590(stack, D_002A050C, func_001011B8, 0);
}

void func_00101528() {
    D_0048DE90[0] = -1;
    D_002BD8B8[0] = 0;
    D_0048DE90[1] = -1;
    D_002BD8B8[1] = 0;
    D_002BD8DC = 0;
    D_002B9338 = 0;
}

void func_00101560() {
    D_002B8688 = -1;
    D_002B868C = -1;
    D_002B930C = 0;
}

void func_00101580() {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_0048DE90); i++) {
        if (D_0048DE90[i] != D_002A0520[i]) {
            if (D_002A0520[i] != 0) {
                func_0011D070(D_002A0520[i], i, &D_002B9040, 0x3FFF);
            }
            D_0048DE90[i] = D_002A0520[i];
        }
    }
}

void func_00101628(s32 arg0) {
    s32 i;
    
    for (i = 0; i < ARRAY_COUNT(D_0048DE90); i++) {
        if ((D_0048DE90[i] != D_002A0520[i]) || (D_0048DE90[i] == 0)) {
            func_0011D1F8(D_0048DE90[i], i, arg0);
        }
    }
}

// nonmatch: regswap?
INCLUDE_ASM(const s32, "xporcupine", func_001016B8);
// void func_001016B8() {
//     func_0011C6C8(0);
//     D_0048DE90[0] = -1;
//     D_0048DE90[1] = -1;
//     func_00101580();
// }

INCLUDE_ASM(const s32, "xporcupine", func_001016E8);
