#include "common.h"
#include "common_funcs.h"
#include "common_data.h"

#include "worldfile.h"
#include "xblade.h"
#include "xarcade.h"
#include "xnoodle.h"
#include "xtailor.h"
#include "disk.h"

typedef struct XPointy {
    /* 0x00 */ char unk_00[2];
    /* 0x02 */ s16 unk_02;
} XPointy;

extern s32 D_002979E0;
extern s32 D_002979E4;
extern u32 D_002A0508;
extern s32 D_002A0510;
extern s32 D_002A0520[];
extern u32 D_002B29C4;
extern s32 D_002B2CC4;
extern s32 D_002B8354;
extern s32 D_002B8364;
extern u32 D_002B85F8;
extern s32 D_002B8678;
extern s32 D_002B8680;
extern s32 D_002B8684;
extern s32 D_002B8698[];
extern s32 D_002B91E0;
extern s32 D_002B92F8;
extern s32 D_002B930C;
extern s32 D_002B9310;
extern s32 D_002B9314;
extern s32 D_002B9318[];
extern s32 D_002B9328;
extern s32 D_002B932C;
extern u32 D_002B9330;
extern u32 D_002B9334;
extern u32 D_002B933C;
extern s32 D_002B9340;
extern s32 D_002B9668;
extern s32 D_002B966C;
extern s32 D_002BD8D8;
extern s32 D_002C1EBC;

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

extern void func_001009A8();
extern s32 func_001016E8();
extern u16 func_00105660();
extern void func_00111198();
extern void func_001116C8();
void func_00114420();
extern void func_00117588();
extern void* func_00122588(s32, void*);
extern void func_00132450();
extern void func_00157B90();
extern void func_00177470();
extern void func_00180CE0();
extern void func_001C38C0();
extern void func_001C4FF0();
extern void* func_001EE280(s32);
extern void func_001ED878();

INCLUDE_ASM(const s32, "xblade", func_00112168);

void func_00112190(void) {
    D_002B85F8 |= 0x20;
}

void func_001121A8(void) {
    D_002B85F8 &= ~0x20;
}

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

INCLUDE_ASM(const s32, "xblade", func_00112690);
s32 func_00112690();

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

INCLUDE_ASM(const s32, "xblade", func_001132F0);
s32 func_001132F0();

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

INCLUDE_ASM(const s32, "xblade", func_00113410);

void func_00113618(void) {
    D_004D2A8C = 205;
    D_004D2A90 = 135;
    D_004D2A94 = 50;
    D_004D2A98 = 128;
    D_004D2A9C = 76;
    D_004D2AA0 = 128;
}

INCLUDE_ASM(const s32, "xblade", func_00113660);

INCLUDE_ASM(const s32, "xblade", func_001136C8);

INCLUDE_ASM(const s32, "xblade", func_00113710);

void func_001139F8(void) {
    D_004D2A68 = 0;
    D_004D2A6C = 0;
}

void* func_00113A10(s32 arg0) {
    void* p0 = func_001EE280(arg0);
    D_004D2A6C = arg0;
    return p0;
}

INCLUDE_ASM(const s32, "xblade", func_00113A40);

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

INCLUDE_ASM(const s32, "xblade", func_00113BC0);
s32 func_00113BC0();

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

INCLUDE_ASM(const s32, "xblade", func_00113E98);

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
