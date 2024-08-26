#include "common.h"

typedef struct {
    /* 0x00*/ char unk_04[0x44];
    /* 0x44*/ f32 unk_44;
} XToast;

typedef struct {
    /* 0x000 */ char unk_000[0x130];
    /* 0x130 */ XToast* unk_130;
} XToaster;

INCLUDE_RODATA("asm/nonmatchings/xtoaster", D_00487018);

INCLUDE_RODATA("asm/nonmatchings/xtoaster", D_00487020);

INCLUDE_RODATA("asm/nonmatchings/xtoaster", D_00487028);

INCLUDE_RODATA("asm/nonmatchings/xtoaster", D_00487030);

INCLUDE_RODATA("asm/nonmatchings/xtoaster", D_00487038);

INCLUDE_RODATA("asm/nonmatchings/xtoaster", D_00487040);

INCLUDE_RODATA("asm/nonmatchings/xtoaster", D_00487048);

INCLUDE_RODATA("asm/nonmatchings/xtoaster", D_00487050);

INCLUDE_RODATA("asm/nonmatchings/xtoaster", D_00487058);

INCLUDE_RODATA("asm/nonmatchings/xtoaster", D_00487060);

INCLUDE_RODATA("asm/nonmatchings/xtoaster", D_00487068);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_001231E0);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123318);

void func_00123340(f32 arg0, XToaster* arg1) {
    arg1->unk_130->unk_44 = arg0;
}

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123350);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_001233D0);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_001233F8);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123430);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_001234A0);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123518);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123558);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_001235B8);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123620);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123698);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_001236F0);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123730);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123768);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_001237E8);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123830);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123858);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123880);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_001239D8);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123A08);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123A40);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123A80);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123AB8);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123B20);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123B50);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123BD0);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123C80);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123C90);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123E48);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123E78);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123ED0);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123F00);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00124108);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_001242E8);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00124420);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_001245F0);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00124BC8);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00124CA0);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00124CD8);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00124DD0);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00124F38);
