#include "common.h"

//INCLUDE_ASM(const s32, "func_0013B368", func_0013B368);

s32 func_0011ED30(s32, s32*);
s32 func_00120590(void*, s32*, s32*, s32);
s32 func_00157B90(void);
s32 func_001EE090(s32);
s32 sprintf(void*, s32*, s32, s32);

extern s32 func_0013B138;
extern s32 func_0013B1D0;

// .data
extern s32 D_00301010[];
extern s32 D_00301050;
extern s32 D_00301054;

// .rodata
extern char* D_004879D0; // "%s%s"

// ?
extern s32 D_00532600;
extern s32 D_00532604;
extern s32 D_0053260C;

// ???
extern s32 func_F20000;

s32 func_0013B368(void) {
    char something[0x20];
    if ((D_00532604 != 2) || (func_001EE090(2) != 0)) {
        return 0;
    }
    func_00157B90();
    D_00532604 = 3;
    sprintf(something, &D_004879D0, D_00301010[D_00532600], D_00301050);
    func_00120590(something, D_0053260C, NULL, 0);
    sprintf(something, &D_004879D0, D_00301010[D_00532600], D_00301054);
    func_00120590(something, &func_F20000, &func_0013B138, 0);
    func_0011ED30(0xB798, &func_0013B1D0);
    return 1;
}
