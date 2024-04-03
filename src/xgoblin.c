#include "common.h"

#include "io.h"

#include "libpc.h"
#include "libpad2.h"
#include "libvu0.h"

void func_0011F938();
void func_00121AE8();
void func_00122110();
void func_00122410();
void func_0012FB18();
void func_00147870();

extern f32 D_002B8340[];
extern sceVu0FMATRIX D_002C1E60;
extern s32 D_002C1EA0;
extern s32 D_002C1EBC;
extern f32 D_002C1EC0;
extern u32 D_002C1EE0[30][2];
extern scePad2SocketParam D_002C1FD8;

extern UNK_TYPE D_004DD188;
extern UNK_TYPE D_004DD198[];
extern u_long128 D_004DDA00;
extern s32 D_004DDC00;

// Loads several modules
INCLUDE_ASM(const s32, "xgoblin", func_0011EAF8);

s32 func_0011EBC8(void) {
    func_00122250();
    return 0;
}

void func_0011EBE8(void) {
    s32 i, j;

    sceVu0UnitMatrix(D_002C1E20);

    for (i = 0; i < ARRAY_COUNT(D_002C1E60); i++) {
        for (j = 0; j < ARRAY_COUNT(D_002C1E60[0]); j++) {
            D_002C1E60[i][j] = 0;
        }
    }
    D_002C1EA0 = 0;
    D_002C1EA8 = 0;
    D_002C1EBC = 0;
    func_0011EDD0(&D_004DD188, D_004DD198, 0x10, 0x80);
    func_00122110();
    func_00121AE8();
    func_00122410();
    func_001208B8();
    func_00147870();
    func_0011F938();
    func_0012FB18();
    ((XGoblin*)func_0011ED30(150000, func_0011EBC8))->unk_02 = -1;
}

void func_0011ECD0(void) {
    D_002C1EC0 = 1.0f / D_002B8340[1];
    func_0011EF58(&D_004DD188, D_002C1EBC);
    D_002C1EA0 ^= 1;
}

INCLUDE_ASM(const s32, "xgoblin", func_0011ED30);

void func_0011ED60(s32 arg0) {
    func_0011F108(&D_004DD188, arg0);
}

s32 func_0011ED80(s32 arg0) {
    s32 val = func_0011F108(&D_004DD188, arg0);
    if (val != 0) {
        return func_0011F148(&D_004DD188, val);
    }
}

INCLUDE_ASM(const s32, "xgoblin", func_0011EDD0);

INCLUDE_ASM(const s32, "xgoblin", func_0011EE10);

XGoblin* func_0011EE80(XGoblin* arg0, XGoblin* arg1) {
    XGoblin* pXVar;
    XGoblin* pXVar2 = NULL;

    for (pXVar = arg0->unk_08; pXVar != NULL && pXVar != arg1; pXVar = pXVar->unk_08) {
        pXVar2 = pXVar;
    }

    return pXVar2;
}

INCLUDE_ASM(const s32, "xgoblin", func_0011EEB8);

s32 func_0011EF58(XGoblin* arg0, s32 arg1) {
    u32 uVar3;

    s32 sVar5 = 0;
    XGoblin* pXVar2 = NULL;
    XGoblin* next = arg0->unk_08;

    while (next != 0) {
        if ((next->unk_02 & arg1) == arg1) {
            uVar3 = next->unk_0C(next);
            next->unk_00 &= 0xFFEF;

            if (uVar3 & 4) {
                if (pXVar2 != 0) {
                    if (pXVar2->unk_08 != next) {
                        pXVar2 = func_0011EE80(arg0, next);
                    }
                    pXVar2->unk_08 = next->unk_08;
                } else {
                    arg0->unk_08 = next->unk_08;
                }
                next->unk_00 = 0;
            } else {
                pXVar2 = next;
            }

            sVar5++;

            if (uVar3 & 8) {
                pXVar2 = next;
                break;
            }
        }
        next = next->unk_08;
    }

    arg0->unk_0C = NULL;
    return sVar5;
}

s32 func_0011F050(XGoblin* arg0, u16 (*arg1)(XGoblin*)) {
    XGoblin* next;
    XGoblin* gob;

    s32 iVar1 = 0;

    for (next = arg0->unk_08; next != NULL; next = next->unk_08) {
        if (((next->unk_00 | arg1(next)) & 4) != 0) {
            gob = func_0011EE80(arg0, next);
            if (gob != NULL) {
                gob->unk_08 = next->unk_08;
            } else {
                arg0->unk_08 = next->unk_08;
            }
            next->unk_00 = 0;
        }
        iVar1++;
    }

    return iVar1;
}

b32 func_0011F0F8(XOtherCrown* arg0) {
    return arg0->unk_00 & 1;
}

INCLUDE_ASM(const s32, "xgoblin", func_0011F108);

INCLUDE_ASM(const s32, "xgoblin", func_0011F148);

INCLUDE_ASM(const s32, "xgoblin", func_0011F1A0);

INCLUDE_ASM(const s32, "xgoblin", func_0011F388);

u32 func_0011F478(u32 arg0) {
    u32 i;
    u32 uVar3 = 0;

    for (i = 0; i < ARRAY_COUNT(D_002C1EE0); i++) {
        if ((arg0 & D_002C1EE0[i][0]) == D_002C1EE0[i][0]) {
            uVar3 |= D_002C1EE0[i][1];
        }
    }

    return uVar3;
}

INCLUDE_ASM(const s32, "xgoblin", func_0011F4B8);

INCLUDE_ASM(const s32, "xgoblin", func_0011F7C0);

INCLUDE_ASM(const s32, "xgoblin", func_0011F8C0);
// void func_0011F8C0(void) {
//     sceDbcInit();
//     scePad2Init(0);
//     D_004DDC00 = scePad2CreateSocket(&D_002C1FD8, &D_004DDA00);
// }

s32 func_0011F908(void) {
    scePcStart(0x8000F8DE, 0, 0); // TODO: libpc bitfield macro combination
    return 0;
}

void func_0011F938(void) {
    func_0011F908();
    ((XGoblin*)func_0011ED30(10000, func_0011F908))->unk_02 = -1;
}

INCLUDE_ASM(const s32, "xgoblin", func_0011F970);

INCLUDE_ASM(const s32, "xgoblin", func_0011F980);

INCLUDE_ASM(const s32, "xgoblin", func_0011F9B0);

INCLUDE_ASM(const s32, "xgoblin", func_0011F9E8);
