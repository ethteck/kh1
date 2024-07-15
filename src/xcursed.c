#include "common.h"

s32 D_003F2080;
s32 D_003F2C80;
s32 D_003F3C80;
s32 D_003F4080;
s32 D_003F4480;
s32 D_00408480;
s32 D_00408880;

s32 func_0022F578(s32 arg0) {
    s32* puVar1;
    int i;

    switch (arg0) {
        case -1:
            for (i = 0x16C0, puVar1 = &D_003F2080; i > 0; i--) {
                *(u_long128*)puVar1 = 0;
                puVar1 += 4;
            }
            return 0;

        case 0:
            for (i = 0xC0, puVar1 = &D_003F2080; i > 0; i--) {
                *(u_long128*)puVar1 = 0;
                puVar1 += 4;
            }
            return 0;

        case 1:
            for (i = 0x100, puVar1 = &D_003F2C80; i > 0; i--) {
                *(u_long128*)puVar1 = 0;
                puVar1 += 4;
            }
            return 0;

        case 2:
            for (i = 0x40, puVar1 = &D_003F3C80; i > 0; i--) {
                *(u_long128*)puVar1 = 0;
                puVar1 += 4;
            }
            return 0;

        case 3:
            for (i = 0x40, puVar1 = &D_003F4080; i > 0; i--) {
                *(u_long128*)puVar1 = 0;
                puVar1 += 4;
            }
            return 0;

        case 4:
            for (i = 0x1400, puVar1 = &D_003F4480; i > 0; i--) {
                *(u_long128*)puVar1 = 0;
                puVar1 += 4;
            }
            return 0;

        case 5:
            for (i = 0x40, puVar1 = &D_00408480; i > 0; i--) {
                *(u_long128*)puVar1 = 0;
                puVar1 += 4;
            }
            return 0;

        case 6:
            for (i = 0x40, puVar1 = &D_00408880; i > 0; i--) {
                *(u_long128*)puVar1 = 0;
                puVar1 += 4;
            }
            return 0;

        default:
            return -1;
    }
}

void* func_0022F768(s32 arg0) {
    switch (arg0) {
        case 0:
            return &D_003F2080;
        case 1:
            return &D_003F2C80;
        case 2:
            return &D_003F3C80;
        case 3:
            return &D_003F4080;
        case 4:
            return &D_003F4480;
        case 5:
            return &D_00408480;
        case 6:
            return &D_00408880;
        default:
            return NULL;
    }
}
