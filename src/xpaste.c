#include "common.h"
#include "common_funcs.h"

#include "xarcade.h"
#include "xblade.h"
#include "xturtle.h"

extern s32 D_002B29D0; // also in xpancake
extern s32 D_002B8354; // also in xarcade, xblade, xtailor
extern s32 D_002BD854; // also in xbeginning and unsplit code
extern s32 D_002BD858; // also in xblade
extern s32 D_002BD85C; // also in xblade
extern s32 D_003ED704; // also in xarcade, xturtle, and unsplit code
extern s32 D_003F117C; // also in unsplit code
extern s32 D_003F1514; // also in unsplit code
extern s32 D_003F1518; // also in unsplit code

void func_0011C540();

extern void func_00180CE0();
extern void func_0022BA18(u16);

s32 func_0011C440() {
    if (D_003ED704 == 0) {
        if (D_003F117C == 1) {
            func_001093A8(2);
            func_00111638();
            D_002B29D0 = 1;
        } else {
            func_0011C540();
        }
        return 4;
    }
    return 0;
}

s32 func_0011C4B0() {
    if (D_003F1514 == 0) {
        switch (D_003F1518) {
            case FALSE:
                func_001093A8(10);
                func_0022F848();
                func_00158C00(15);
                func_00111638();
                return 4;
            case TRUE:
                func_00229D60(0xffff);
                func_0011ED30(30000, func_0011C440);
                return 4;
        }
    }
    return 0;
}

void func_0011C540() {
    D_002BD854 = 1;
    D_002B8354 = 0;
    func_00114420();
    func_00180CE0();
    func_0022BA18(-1);
    func_0011E340();
    func_0011ED30(30000, func_0011C4B0);
    func_0011D4B8(120);
}

void func_0011C598(s32 arg0) {
    D_002BD858 = arg0;
}

void func_0011C5A8() {
    D_002BD858 = 0;
}

void func_0011C5B8() {
    D_002BD85C = 1;
}

void func_0011C5C8() {
    D_002BD85C = 0;
}
