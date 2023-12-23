#include "common.h"
#include "common_funcs.h"
#include "common_data.h"

#include "io.h"

#include "libvu0.h"

extern UNK_TYPE D_004DD188;

s32 func_0011EBC8(void);
void func_0011F938();

void func_00121AE8();
void func_00122110();
void func_00122410();
void func_0012FB18();
void func_00147870();

extern sceVu0FMATRIX D_002C1E60;
extern s32 D_002C1EA0;
extern s32 D_002C1EBC;
extern s32 D_004DD198;

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
    func_0011EDD0(&D_004DD188, &D_004DD198, 0x10, 0x80);
    func_00122110();
    func_00121AE8();
    func_00122410();
    func_001208B8();
    func_00147870();
    func_0011F938();
    func_0012FB18();
    ((Unk150000*) func_0011ED30(150000, func_0011EBC8))->unk_02 = -1;
}

INCLUDE_ASM(const s32, "xgoblin", func_0011ECD0);

INCLUDE_ASM(const s32, "xgoblin", func_0011ED30);

void func_0011ED60(s32 arg0) {
    func_0011F108(&D_004DD188, arg0);
}

INCLUDE_ASM(const s32, "xgoblin", func_0011ED80);

INCLUDE_ASM(const s32, "xgoblin", func_0011EDD0);

INCLUDE_ASM(const s32, "xgoblin", func_0011EE10);

INCLUDE_ASM(const s32, "xgoblin", func_0011EE80);

INCLUDE_ASM(const s32, "xgoblin", func_0011EEB8);

INCLUDE_ASM(const s32, "xgoblin", func_0011EF58);

INCLUDE_ASM(const s32, "xgoblin", func_0011F050);

b32 func_0011F0F8(XOtherCrown* arg0) {
    return arg0->unk_00 & 1;
}

INCLUDE_ASM(const s32, "xgoblin", func_0011F108);

INCLUDE_ASM(const s32, "xgoblin", func_0011F148);

INCLUDE_ASM(const s32, "xgoblin", func_0011F1A0);

INCLUDE_ASM(const s32, "xgoblin", func_0011F388);

INCLUDE_ASM(const s32, "xgoblin", func_0011F478);

INCLUDE_ASM(const s32, "xgoblin", func_0011F4B8);

INCLUDE_ASM(const s32, "xgoblin", func_0011F7C0);

INCLUDE_ASM(const s32, "xgoblin", func_0011F8C0);

INCLUDE_ASM(const s32, "xgoblin", func_0011F908);

INCLUDE_ASM(const s32, "xgoblin", func_0011F938);

INCLUDE_ASM(const s32, "xgoblin", func_0011F970);

INCLUDE_ASM(const s32, "xgoblin", func_0011F980);

INCLUDE_ASM(const s32, "xgoblin", func_0011F9B0);

INCLUDE_ASM(const s32, "xgoblin", func_0011F9E8);
