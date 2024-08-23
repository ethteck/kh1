#include "common.h"
#include "common_funcs.h"
#include "xquack.h"
#include "xturtle.h"

typedef struct XTurtle {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ u8 unk_14;
    /* 0x15 */ u8 unk_15;
    /* 0x16 */ u8 unk_16;
    /* 0x17 */ char unk_17;
} XTurtle;

typedef struct XScale {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
} XScale; // size = 0x8

typedef struct XShell {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
} XShell; // size = 0xC

extern s32 D_002A0514;
extern s32 D_002BD8B4;
extern s32 D_002BD8B8[2];
extern s32 D_002BD8C8;
extern s32 D_002BD8CC;
extern s32 D_002BD8E0;
extern s32 D_002BD8E4;

const char D_00486E40[] = "%3d";
const char D_00486E48[] = "amusic/music";
const char D_00486E58[] = ".dat";
const char D_00486E60[] = "amusic/se";

void (*D_004DCB70)(void);
extern s32 D_004DCB8C;
extern XTurtle* D_004DCB90;
extern XShell* D_004DCB94;
extern XTurtle* D_004DCB98;
extern XTurtle* D_004DCF58;
extern XScale* D_004DD138;
extern s32 D_004DD180;

XTurtle* func_0011CDD8(s32, s32, s32, s32, s32);

void func_0011C5D8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    func_001EE570(arg0, arg1, arg2, arg3, arg4, arg5);
}

s32 func_0011C5F0(s32 arg0, s32 arg1, s32 arg2) {
    return func_001EE618(arg0, arg1, arg2);
}

void* func_0011C608(s32 arg0) {
    return func_001EE5D8(arg0);
}

void* func_0011C620(void* arg0) {
    return func_001EE660(arg0);
}

void* func_0011C638(void* arg0) {
    return func_001EE6B8(arg0);
}

s32 func_0011C650(void) {
    return func_001EE090();
}

void* func_0011C668(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return func_001EE330(arg0, arg1, arg2, arg3, arg4);
}

s32 func_0011C680(s32 arg0, s32 arg1, s32 arg2) {
    return func_001EE390(arg0, arg1, arg2);
}

void* func_0011C698(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return func_001EE428(arg0, arg1, arg2, arg3, arg4);
}

void* func_0011C6B0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return func_001EE478(arg0, arg1, arg2, arg3, arg4);
}

void func_0011C6C8(s32 arg0) {
    XScale* var_2;
    XTurtle* var_3;
    XShell* var_4;
    s32 i;

    if (arg0 == 0) {
        D_004DCB90 = &D_004DCB98;
        D_004DCB94 = &D_004DCF58;
        D_004DCB8C = 0x28;
    } else {
        D_004DCB90 = func_00155ED8(0x10, 1);
        D_004DCB94 = func_00155ED8(0x11, 1);
        D_004DCB8C = 0x80;
    }

    var_3 = D_004DCB90;
    var_4 = D_004DCB94;
    for (i = 0; i < D_004DCB8C; i++) {
        var_3->unk_14 = 0;
        var_4->unk_00 = 0;
        var_4->unk_04 = 0;
        var_4->unk_08 = 0;
        var_3++;
        var_4++;
    }

    var_2 = &D_004DD138;
    for (i = 0; i < 4; i++) {
        var_2->unk_00 = 0;
        var_2->unk_04 = 0;
        var_2++;
    }
}

void func_0011C7D0(void) {
    D_004DD180 = 0;
}

void func_0011C7E0(void) {
    D_004DD180 = 1;
}

void func_0011C7F0(void) {
    func_0011C7D0();
    func_0011C6C8(0);
    func_001EE5D8(0);
    func_001EE5D8(1);
    func_001EE390(-100, -1, -1);
    func_001EE1E0(0, 0);
    func_001EE1E0(0, 1);
    func_001EE1E0(1, 0);
    func_001EE1E0(1, 1);
    func_001EE1E0(0, -8);
    func_001EE1E0(3, -8);
    func_001EE228(10);
    func_00113A10(0);
    func_001EEC58();
    func_00101528();
}

INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011C898);

INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011C938);

s32 func_0011C9B0(void* arg0) {
    return func_00120438("amusic/se000.dat", arg0); // in xkingdom.c
}

s32 func_0011C9D0(void) {
    if (func_001EE090()) {
        return 0;
    }

    if (D_004DCB70 != NULL) {
        D_004DCB70();
    }

    return 4;
}

INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011CA10);

INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011CB50);

INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011CC20);

void func_0011CDB8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, XTurtle* arg5, s32 arg6) {
    arg5->unk_0C = arg6;
    arg5->unk_00 = arg0;
    arg5->unk_10 = arg1;
    arg5->unk_04 = arg2;
    arg5->unk_08 = arg3;
    arg5->unk_16 = arg4;
    arg5->unk_15 = 0;
}

XTurtle* func_0011CDD8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    XTurtle* it = D_004DCB90;
    s32 i;

    for (i = 0; i < D_004DCB8C; i++, it++) {
        s32 val = (arg0 < 1000) ? 2 : -1;

        if (it->unk_14 == 0) {
            func_0011CDB8(arg0, arg1, arg2, arg3, arg4, it, val);
            return it;
        }
    }

    return NULL;
}


INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011CE58);

void func_0011CEB0(s32 arg0, s32 arg1) {
    s32 val = arg0 < 1000 ? 2 : -8;

    func_0011C668(val, arg0, arg1, 0x3FFF, 0x3FFF);
    func_0011CE58(arg0, arg1);
}

s32 func_0011CF08(s32 arg0, s32 arg1) {
    s32 val = arg0 < 1000 ? 2 : -8;

    return func_0011C680(val, arg0, arg1);
}

void* func_0011CF38(s32 arg0, s32 arg1, s32 arg2) {
    s32 val = arg0 < 1000 ? 2 : -8;

    return func_0011C698(val, arg0, arg1, -1, arg2);
}

void* func_0011CF70(s32 arg0, s32 arg1) {
    s32 val = arg0 < 1000 ? 2 : -1;

    return func_0011C668(val, arg0, arg1, 0x3FFF, 0x3FFF);
}

s32 func_0011CFA8(s32 arg0, s32 arg1) {
    s32 val = arg0 < 1000 ? 2 : -1;

    return func_0011C680(val, arg0, arg1);
}

void* func_0011CFD8(s32 arg0, s32 arg1, s32 arg2) {
    s32 val = arg0 < 1000 ? 2 : -1;

    return func_0011C698(val, arg0, arg1, -1, arg2);
}

void func_0011D010(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    XTurtle* bleb = func_0011CDD8(arg0, arg1, arg2, arg3, 0);

    if (bleb != NULL) {
        bleb->unk_14 = 1;
    }
}

void func_0011D040(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    XTurtle* bleb = func_0011CDD8(arg0, arg1, arg2, arg3, 1);

    if (bleb != NULL) {
        bleb->unk_14 = 2;
    }
}

void func_0011D070(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    XTurtle* bleb = func_0011CDD8(arg0, arg1, arg2, arg3, 2);

    if (bleb != NULL) {
        bleb->unk_14 = 1;
    }
}

void func_0011D0A0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    XTurtle* bleb = func_0011CDD8(arg0, arg1, arg2, arg3, 3);

    if (bleb != NULL) {
        bleb->unk_14 = 2;
    }
}

void func_0011D0D0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    XTurtle* bleb = func_0011CDD8(arg0, arg1, arg2, arg3, 4);

    if (bleb != NULL) {
        bleb->unk_14 = 2;
    }
}

INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011D100);

INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011D180);

INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011D1F8);

INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011D278);

INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011D310);

INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011D3B8);

INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011D420);

INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011D4B8);

INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011D520);

void* func_0011D598(s32 arg0) {
    return func_0011C668(2, arg0, 0, 0x3FFF, 0x3FFF);
}

void* func_0011D5C0(s32 arg0, s32 arg1) {
    s32 val = 0x3FFF;
    if (arg1 != 0) {
        val = 0x1FFF;
    }

    return func_0011C6B0(2, arg0, 0, val, val);
}

s32 func_0011D5F0(s32 arg0) {
    return func_0011C680(2, arg0, 0);
}

INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011D610);

void func_0011D978(s32* arg0, s32* arg1) {
    s32 val;

    if (*arg0 < 0) {
        *arg0 = 0;
    }
    if (*arg1 < 0) {
        *arg1 = 0;
    }
    if (*arg0 < 0x4000) {
        val = *arg1;
    } else {
        *arg0 = 0x3FFF;
        val = *arg1;
    }
    if (val > 0x3FFF) {
        *arg1 = 0x3FFF;
    }
}

void func_0011D9C8(s32* arg0, s32* arg1, s32 arg2, s32 arg3) {
    if ((arg3 == 2) && (D_002A0514 != 0)) {
        *arg0 = 0;
        *arg1 = 0;
    } else if (arg2 == 0x3FFF) {
        *arg0 = 0x3FFF;
        *arg1 = 0x3FFF;
    } else {
        *arg0 = *arg0 + arg2;
        *arg1 = *arg1 + arg2;
        func_0011D978(arg0, arg1);
    }
}

INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011DA50);

INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011DAC0);

INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011DB18);

INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011DBF8);

INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011DCB8);

INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011DFF0);

void func_0011E048(s32 arg0) {
    func_001EDD20(arg0);
    func_0011DFF0(arg0);
}

INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011E070);

s32 func_0011E168(s32 arg0) {
    D_002BD8E4 = func_0011E070(arg0);
    return D_002BD8E4;
}

INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011E190);

void func_0011E2A8(void) {
    func_0011C5F0(0, 0, 960);
    func_0011C5D8(1, 0, 0x3000, 240, 0, 240);
    D_002BD8B4 = 1;
}

void func_0011E2F8(void) {
    func_0011C5F0(1, 0, 720);
    func_0011C5D8(0, 0, 0x3000, 480, 1, 240);
    D_002BD8B4 = 0;
}

void func_0011E340(void) {
    D_002BD8E0 = 1;
}

void func_0011E350(void) {
    D_002BD8E0 = 0;
}

INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011E360);

void func_0011E418(void) {
    func_00101528();
}

INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011E430);

INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011E520);
void func_0011E520();

INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011E578);

s32 func_0011E5E8(UNK_TYPE arg0, UNK_TYPE arg1, s32 arg2) {
    return func_0011CA10(0, arg2, D_002BD8C8, func_0011E520);
}

INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011E618);
void func_0011E618();

s32 func_0011E6C0(UNK_TYPE arg0, UNK_TYPE arg1, s32 arg2) {
    return func_0011CA10(1, arg2, D_002BD8CC, func_0011E618);
}

INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011E6F0);

void func_0011E7C8(s32 arg0, void* arg1) {
    func_0011E6F0(0, 0x3000, 0, arg0, 0, arg1);
}

void func_0011E7F8(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    func_0011E6F0(1, arg0, arg1, arg2, 0, arg3);
}

void func_0011E830(s32 arg0, void* arg1) {
    func_0011E6F0(0, 0x3000, 0, arg0, 1, arg1);
}

INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011E860);

INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011E900);

void* func_0011E9A8(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    D_002BD8B8[arg0] = -1;
    D_004DCB70 = arg3;
    func_001EE1E0(1, arg0);
    func_001EE518(arg0, arg1, arg2);
    return func_0011ED30(10000, func_0011C9D0);
}

INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011EA28);
