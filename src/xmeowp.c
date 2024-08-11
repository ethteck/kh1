#include "common.h"
#include "xmeowp.h"

extern XKitten D_003E3890;
extern void* D_003E3898;
extern s32 D_003EBCC0;
extern s32 D_003EBCC4;

const u8 D_0048A670[16] = {};

extern XKitten D_00639A90[24];
extern XKitten* D_0063B050;

extern s32 func_00233138(s32, s32);

// Nonmatch: Assignment instructions out of order
INCLUDE_ASM("asm/nonmatchings/xmeowp", func_001F3990);
// void func_001F3990(void) {
//     XKitten* pXVar1;
//     int iVar2;

//     iVar2 = 24;
//     pXVar1 = D_00639A90;
//     do {
//         iVar2 += -1;
//         pXVar1->unk_84 = 0;
//         pXVar1 = pXVar1 + 1;
//     } while (0 < iVar2);

//     D_0063B050 = NULL;
//     D_003EBCC0 = 0x80E6E6E6;
//     D_003EBCC4 = 320;

//     func_001F0E58(8);
//     func_001F0E58(0);
//     func_001FDAC8();
// }

XKitten* func_001F3A08(void* arg0) {
    return func_001F3A20(arg0, 6);
}

INCLUDE_ASM("asm/nonmatchings/xmeowp", func_001F3A20);

XKitten* func_001F3D50(XKitten* arg0) {
    return func_001F3A20(arg0, func_00233138(4, 54) + 1);
}

void func_001F3D88(void* arg0) {
    func_001F3DA0(arg0, 6);
}

INCLUDE_ASM("asm/nonmatchings/xmeowp", func_001F3DA0);

void func_001F3DF0(void* arg0) {
    func_001F3DA0(arg0, func_00233138(4, 54) + 1);
}

XKitten* func_001F3E28(s32 arg0, s32 arg1) {
    D_003E3890.unk_00 = arg1;
    D_003E3890.unk_08 = arg0;
    return func_001F3A20(&D_003E3890, 6);
}

XKitten* func_001F3E58(s32 arg0, s32 arg1, s32 arg2) {
    D_003E3890.unk_00 = arg1;
    D_003E3890.unk_08 = arg0;
    return func_001F3A20(&D_003E3890, arg2);
}

XKitten* func_001F3E88(s32 arg0, s32 arg1) {
    D_003E3890.unk_00 = arg1;
    D_003E3890.unk_08 = arg0;
    return func_001F3A20(&D_003E3890, func_00233138(4, 54) + 1);
}

void func_001F3EC8(XKitten* arg0) {
    arg0->unk_84 = 4;
    if (arg0->prev) {
        arg0->prev->next = arg0->next;
    }
    if (arg0->next) {
        arg0->next->prev = arg0->prev;
    }
}

void func_001F3F00(XKitten* arg0) {
    arg0->unk_38 |= 0x100000000;
}

void func_001F3F18(XKitten* arg0, s32 arg1) {
    arg0->unk_7C = arg1;
    arg0->unk_38 |= 0x100000000;
}

INCLUDE_ASM("asm/nonmatchings/xmeowp", func_001F3F38);

INCLUDE_ASM("asm/nonmatchings/xmeowp", func_001F3F88);

INCLUDE_ASM("asm/nonmatchings/xmeowp", func_001F3FD8);

INCLUDE_ASM("asm/nonmatchings/xmeowp", func_001F4040);

INCLUDE_ASM("asm/nonmatchings/xmeowp", func_001F40C0);

INCLUDE_ASM("asm/nonmatchings/xmeowp", func_001F4150);

INCLUDE_ASM("asm/nonmatchings/xmeowp", func_001F41F8);

INCLUDE_ASM("asm/nonmatchings/xmeowp", func_001F42B0);

INCLUDE_ASM("asm/nonmatchings/xmeowp", func_001F4380);

INCLUDE_ASM("asm/nonmatchings/xmeowp", func_001F4408);

INCLUDE_ASM("asm/nonmatchings/xmeowp", func_001F44A0);

INCLUDE_ASM("asm/nonmatchings/xmeowp", func_001F4510);

INCLUDE_ASM("asm/nonmatchings/xmeowp", func_001F4590);

void func_001F45D8(XKitten* arg0, s32 arg1) {
    arg0->unk_7C = arg1;
}

void func_001F45E0(XKitten* arg0) {
    arg0->unk_7C = arg0->unk_78;
}

void func_001F45F0(XKitten* arg0) {
    if (arg0->prev_kit) {
        arg0->prev_kit->next_kit = arg0->next_kit;
        if (arg0->next_kit == NULL) {
            arg0->prev_kit = NULL;
        } else {
            arg0->next_kit->prev_kit = arg0->prev_kit;
            arg0->prev_kit = NULL;
        }
        arg0->next_kit = D_0063B050;
        D_0063B050->prev_kit = arg0;
        D_0063B050 = arg0;
    }
}

void func_001F4640(XKitten* arg0) {
    if (arg0) {
        arg0->unk_38 |= 0x200000000;
    }
}

void func_001F4668(XKitten* arg0, XKitten* prev) {
    arg0->prev = prev;
}

void func_001F4670(XKitten* arg0) {
    if (arg0->prev) {
        arg0->prev->next = NULL;
        arg0->prev = NULL;
    }
}

void func_001F4690(XKitten* arg0, XKitten* arg1) {
    XKitten* kit;

    if (arg0->prev != NULL) {
        arg0->prev->next = arg0->next;
    }

    if (arg0->next != NULL) {
        arg0->next->prev = arg0->prev;
    }

    kit = arg1->next;

    arg1->next = arg0;
    arg0->prev = arg1;
    arg0->next = kit;
    if (kit != NULL) {
        kit->prev = arg0;
    }
}

void func_001F46D8(XKitten* arg0, XKitten* next) {
    arg0->next = next;
}

void func_001F46E0(XKitten* arg0) {
    if (arg0->next) {
        arg0->next->prev = NULL;
        arg0->next = NULL;
    }
}

void func_001F4700(XKitten* arg0, XKitten* arg1) {
    XKitten* pXVar1;

    if (arg0->prev != NULL) {
        arg0->prev->next = arg0->next;
    }

    if (arg0->next != NULL) {
        arg0->next->prev = arg0->prev;
    }

    pXVar1 = arg1->prev;

    arg1->prev = arg0;
    arg0->next = arg1;
    arg0->prev = pXVar1;

    if (pXVar1 != NULL) {
        pXVar1->next = arg0;
    }
}

INCLUDE_ASM("asm/nonmatchings/xmeowp", func_001F4748);

INCLUDE_ASM("asm/nonmatchings/xmeowp", func_001F4790);

void func_001F47F0(XKitten* arg0) {
    XKitten* prev = arg0->prev;
    XKitten* next = arg0->next;

    if (prev != NULL) {
        prev->next = next;
    }
    if (next != NULL) {
        next->prev = prev;
    }
}

void func_001F4810(XKitten* arg0, XKitten* arg1) {
    XKitten* kit1_next = arg0->next;
    XKitten* kit1_prev = arg0->prev;
    XKitten* kit2_prev = arg1->prev;
    XKitten* kit2_next = arg1->next;

    if (kit1_prev != NULL) {
        kit1_prev->next = arg1;
    }
    if (kit1_next != NULL) {
        kit1_next->prev = arg1;
    }
    if (kit2_prev != NULL) {
        kit2_prev->next = arg0;
    }
    if (kit2_next != NULL) {
        kit2_next->prev = arg0;
    }
    arg0->prev = kit2_prev;
    arg0->next = kit2_next;
    arg1->prev = kit1_prev;
    arg1->next = kit1_next;
}

u8* func_001F4858(XKitten* arg0) {
    if (arg0->unk_5C == NULL) {
        return &D_0048A670;
    }
    return arg0->unk_5C;
}

void func_001F4878(XKitten* arg0, u8* arg1) {
    arg0->unk_5C = arg1;
}

s32 func_001F4880(XKitten* arg0) {
    return arg0->unk_68;
}

void func_001F4888(XKitten* arg0, s32 arg1) {
    arg0->unk_68 = arg1;
}
