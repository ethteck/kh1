#include "xhumungus.h"
#include "xflamingo.h"

typedef void (*XHumungusFunc)(UNK_TYPE);

extern u32 D_002A2740;
extern s32 D_002A2744;
extern s32 D_002A2748;
extern u32 D_002B29C4;
extern u32 D_002B8000;
extern u32 D_002B8004;
extern u32 D_002B8008;
extern u32 D_002B8014;
extern f32 D_002B8348;
extern u32 D_002B834C;
extern s32 D_002B8678;
extern s32 D_002B8680;
extern s32 D_002B8684;
extern u32 D_002B916C;
extern u32 D_002B9170;
extern u32 D_002B9338;
extern u32 D_002B9660;
extern s32 D_002C2104;
extern s32 D_002C2108;
extern s32 D_002C2024;
extern u32 D_002C1EA8;
extern u16 D_002C1EAA;
extern u32 D_002DED08;
extern u32 D_00375BC0;
extern u32 D_00388860;
extern u32 D_003889B0;
extern GiantMountain D_003854E0;

// Sora/Riku score on Destiny Island
extern s32 D_003C10B8[];

extern XHumungusFunc D_003C10D8[];
extern XHumungusFunc D_003D4A20[];
extern s32* D_003D55DC;

extern u32 D_003F0DD4;
extern s32 D_0041F8BC;

extern char D_0048A3A0[];

extern void* D_00624550;
extern void* D_00624554;
extern void* D_00624658;
extern void* D_00624958;
extern void* D_00624960;
extern void* D_00624970;

extern void func_F20000();

INCLUDE_ASM(const s32, "xhumungus", func_001C8470);

INCLUDE_ASM(const s32, "xhumungus", func_001C8950);

INCLUDE_ASM(const s32, "xhumungus", func_001C8E68);

INCLUDE_ASM(const s32, "xhumungus", func_001C9380);

INCLUDE_ASM(const s32, "xhumungus", func_001C98D0);

INCLUDE_ASM(const s32, "xhumungus", func_001C99C8);

INCLUDE_ASM(const s32, "xhumungus", func_001C9A70);

INCLUDE_ASM(const s32, "xhumungus", func_001C9B30);

INCLUDE_ASM(const s32, "xhumungus", func_001C9B88);

INCLUDE_ASM(const s32, "xhumungus", func_001C9BE0);

INCLUDE_ASM(const s32, "xhumungus", func_001C9C30);

INCLUDE_ASM(const s32, "xhumungus", func_001C9C80);

INCLUDE_ASM(const s32, "xhumungus", func_001C9CD0);

INCLUDE_ASM(const s32, "xhumungus", func_001C9D40);

INCLUDE_ASM(const s32, "xhumungus", func_001C9DB0);

INCLUDE_ASM(const s32, "xhumungus", func_001C9E20);

INCLUDE_ASM(const s32, "xhumungus", func_001C9E70);

INCLUDE_ASM(const s32, "xhumungus", func_001C9EC0);

INCLUDE_ASM(const s32, "xhumungus", func_001C9FE0);

INCLUDE_ASM(const s32, "xhumungus", func_001CA090);

INCLUDE_ASM(const s32, "xhumungus", func_001CA418);

INCLUDE_ASM(const s32, "xhumungus", func_001CA638);

INCLUDE_ASM(const s32, "xhumungus", func_001CA720);

INCLUDE_ASM(const s32, "xhumungus", func_001CA7A0);

INCLUDE_ASM(const s32, "xhumungus", func_001CA888);

INCLUDE_ASM(const s32, "xhumungus", func_001CA908);

INCLUDE_ASM(const s32, "xhumungus", func_001CACC0);

INCLUDE_ASM(const s32, "xhumungus", func_001CADC0);

INCLUDE_ASM(const s32, "xhumungus", func_001CADE0);

INCLUDE_ASM(const s32, "xhumungus", func_001CB0E0);

INCLUDE_ASM(const s32, "xhumungus", func_001CB1A8);

INCLUDE_ASM(const s32, "xhumungus", func_001CB4A0);

INCLUDE_ASM(const s32, "xhumungus", func_001CB5C0);

INCLUDE_ASM(const s32, "xhumungus", func_001CB7B8);

INCLUDE_ASM(const s32, "xhumungus", func_001CB850);

INCLUDE_ASM(const s32, "xhumungus", func_001CB8C8);

INCLUDE_ASM(const s32, "xhumungus", func_001CB938);

INCLUDE_ASM(const s32, "xhumungus", func_001CB998);

INCLUDE_ASM(const s32, "xhumungus", func_001CBB90);

INCLUDE_ASM(const s32, "xhumungus", func_001CBC20);

INCLUDE_ASM(const s32, "xhumungus", func_001CBE90);

INCLUDE_ASM(const s32, "xhumungus", func_001CC130);

INCLUDE_ASM(const s32, "xhumungus", func_001CC1B8);

INCLUDE_ASM(const s32, "xhumungus", func_001CC240);

s32 func_001CC2C8() {
    if ((D_002C1EA8 >> 1 & 1) == 0) {
        func_00180038();
    }
    return 2;
}

s32 func_001CC300() {
    if ((D_002C1EA8 >> 1 & 1) == 0) {
        func_00180080();
    }
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001CC338);

void func_001CC520() {
    D_003854E0.unk_0 = 0;
}

INCLUDE_ASM(const s32, "xhumungus", func_001CC530);

INCLUDE_ASM(const s32, "xhumungus", func_001CC558);

INCLUDE_ASM(const s32, "xhumungus", func_001CC588);

INCLUDE_ASM(const s32, "xhumungus", func_001CC618);

INCLUDE_ASM(const s32, "xhumungus", func_001CC680);

void func_001CC798(s32 arg0) {
    D_003854E0.unk_3070 &= ~0x100000000;
    D_003854E0.unk_3140 = arg0;
    *D_003854E0.unk_3144 = arg0;
}

INCLUDE_ASM(const s32, "xhumungus", func_001CC7D0);

INCLUDE_ASM(const s32, "xhumungus", func_001CC930);

INCLUDE_ASM(const s32, "xhumungus", func_001CC950);

INCLUDE_ASM(const s32, "xhumungus", func_001CC9A8);

INCLUDE_ASM(const s32, "xhumungus", func_001CCA88);

INCLUDE_ASM(const s32, "xhumungus", func_001CCB18);

INCLUDE_ASM(const s32, "xhumungus", func_001CCC48);

INCLUDE_ASM(const s32, "xhumungus", func_001CCEF8);

INCLUDE_ASM(const s32, "xhumungus", func_001CCF78);

INCLUDE_ASM(const s32, "xhumungus", func_001CD2A8);

INCLUDE_ASM(const s32, "xhumungus", func_001CD340);

INCLUDE_ASM(const s32, "xhumungus", func_001CD4D0);

INCLUDE_ASM(const s32, "xhumungus", func_001CD620);

INCLUDE_ASM(const s32, "xhumungus", func_001CD738);

INCLUDE_ASM(const s32, "xhumungus", func_001CD8E8);

INCLUDE_ASM(const s32, "xhumungus", func_001CDA00);

INCLUDE_ASM(const s32, "xhumungus", func_001CDB18);

INCLUDE_ASM(const s32, "xhumungus", func_001CDCC8);

INCLUDE_ASM(const s32, "xhumungus", func_001CDD18);

INCLUDE_ASM(const s32, "xhumungus", func_001CDD68);

INCLUDE_ASM(const s32, "xhumungus", func_001CDDB8);

INCLUDE_ASM(const s32, "xhumungus", func_001CDE20);

INCLUDE_ASM(const s32, "xhumungus", func_001CDE88);

INCLUDE_ASM(const s32, "xhumungus", func_001CDED8);

INCLUDE_ASM(const s32, "xhumungus", func_001CDF28);

INCLUDE_ASM(const s32, "xhumungus", func_001CDF78);

INCLUDE_ASM(const s32, "xhumungus", func_001CDFC8);

INCLUDE_ASM(const s32, "xhumungus", func_001CE060);

INCLUDE_ASM(const s32, "xhumungus", func_001CE0A0);

s32 func_001CE188(xBigBoii* arg0) {
    arg0->unk_174[3] -= 1;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001CE1A0);

s32 func_001CE738() {
    func_0017FED8();
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001CE758);

// Handle score against Riku on Destiny Island
s32 func_001CE858(xBigBoii* arg0) {
    s32 start = arg0->unk_174[3];

    D_003C10B8[arg0->unk_174[start + 3]] = arg0->unk_174[start + 4];
    arg0->unk_174[3] -= 2;
    return 2;
}

void func_001CE898(xBigBoii* arg0) {
    arg0->unk_174[3] -= 1;
    arg0->unk_174[arg0->unk_174[3] + 4] += arg0->unk_174[arg0->unk_174[3] + 5];
}

void func_001CE8D0(xBigBoii* arg0) {
    arg0->unk_174[3] -= 1;
    arg0->unk_174[arg0->unk_174[3] + 4] -= arg0->unk_174[arg0->unk_174[3] + 5];
}

void func_001CE908(xBigBoii* arg0) {
    arg0->unk_174[arg0->unk_174[3] + 4] = -arg0->unk_174[arg0->unk_174[3] + 4];
}

void func_001CE928(xBigBoii* arg0) {
    arg0->unk_174[3] -= 1;
    arg0->unk_174[arg0->unk_174[3] + 4] *= arg0->unk_174[arg0->unk_174[3] + 5];
}

INCLUDE_ASM(const s32, "xhumungus", func_001CE960);

INCLUDE_ASM(const s32, "xhumungus", func_001CE9A0);

void func_001CE9E0(xBigBoii* arg0) {
    arg0->unk_174[3] -= 1;
    arg0->unk_174[arg0->unk_174[3] + 4] = arg0->unk_174[arg0->unk_174[3] + 4] == arg0->unk_174[arg0->unk_174[3] + 5];
}

void func_001CEA18(xBigBoii* arg0) {
    arg0->unk_174[3] -= 1;
    arg0->unk_174[arg0->unk_174[3] + 4] = arg0->unk_174[arg0->unk_174[3] + 5] < arg0->unk_174[arg0->unk_174[3] + 4];
}

void func_001CEA50(xBigBoii* arg0) {
    arg0->unk_174[3] -= 1;
    arg0->unk_174[arg0->unk_174[3] + 4] = arg0->unk_174[arg0->unk_174[3] + 4] < arg0->unk_174[arg0->unk_174[3] + 5] ^ 1;
}

void func_001CEA88(xBigBoii* arg0) {
    arg0->unk_174[3] -= 1;
    arg0->unk_174[arg0->unk_174[3] + 4] = arg0->unk_174[arg0->unk_174[3] + 4] < arg0->unk_174[arg0->unk_174[3] + 5];
}

void func_001CEAC0(xBigBoii* arg0) {
    arg0->unk_174[3] -= 1;
    arg0->unk_174[arg0->unk_174[3] + 4] = arg0->unk_174[arg0->unk_174[3] + 5] < arg0->unk_174[arg0->unk_174[3] + 4] ^ 1;
}

void func_001CEAF8(xBigBoii* arg0) {
    arg0->unk_174[3] -= 1;
    arg0->unk_174[arg0->unk_174[3] + 4] = arg0->unk_174[arg0->unk_174[3] + 4] != arg0->unk_174[arg0->unk_174[3] + 5];
}

void func_001CEB30(xBigBoii* arg0) {
    arg0->unk_174[3] -= 1;
    arg0->unk_174[arg0->unk_174[3] + 4] &= arg0->unk_174[arg0->unk_174[3] + 5];
}

void func_001CEB68(xBigBoii* arg0) {
    arg0->unk_174[3] -= 1;
    arg0->unk_174[arg0->unk_174[3] + 4] |= arg0->unk_174[arg0->unk_174[3] + 5];
}

void func_001CEBA0(xBigBoii* arg0) {
    arg0->unk_174[3] -= 1;
    arg0->unk_174[arg0->unk_174[3] + 4] ^= arg0->unk_174[arg0->unk_174[3] + 5];
}

void func_001CEBD8(xBigBoii* arg0) {
    arg0->unk_174[arg0->unk_174[3] + 4] = ~arg0->unk_174[arg0->unk_174[3] + 4];
}

INCLUDE_ASM(const s32, "xhumungus", func_001CEBF8);

INCLUDE_ASM(const s32, "xhumungus", func_001CEC30);

s32 func_001CEC68(UNK_TYPE arg0, s32 arg1) {
    D_003C10D8[arg1](arg0);
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001CEC98);

INCLUDE_ASM(const s32, "xhumungus", func_001CECE0);

s32 func_001CED20(xBigBoii* arg0) {
    arg0->unk_174[3] -= 1;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001CED38);

INCLUDE_ASM(const s32, "xhumungus", func_001CF070);

INCLUDE_ASM(const s32, "xhumungus", func_001CF128);

s32 func_001CF1B0() {
    return 2;
}

s32 func_001CF1B8() {
    D_00375BC0 |= 2;
    func_00133538();
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001CF1E8);

s32 func_001CF250() {
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001CF258);

INCLUDE_ASM(const s32, "xhumungus", func_001CF2A0);

INCLUDE_ASM(const s32, "xhumungus", func_001CF320);

INCLUDE_ASM(const s32, "xhumungus", func_001CF350);

INCLUDE_ASM(const s32, "xhumungus", func_001CF380);

INCLUDE_ASM(const s32, "xhumungus", func_001CF3B0);

INCLUDE_ASM(const s32, "xhumungus", func_001CF458);

INCLUDE_ASM(const s32, "xhumungus", func_001CF488);

INCLUDE_ASM(const s32, "xhumungus", func_001CF4D0);

INCLUDE_ASM(const s32, "xhumungus", func_001CF518);

INCLUDE_ASM(const s32, "xhumungus", func_001CF560);

INCLUDE_ASM(const s32, "xhumungus", func_001CF5A8);

INCLUDE_ASM(const s32, "xhumungus", func_001CF5F0);

INCLUDE_ASM(const s32, "xhumungus", func_001CF638);

INCLUDE_ASM(const s32, "xhumungus", func_001CF6C8);

INCLUDE_ASM(const s32, "xhumungus", func_001CF728);

INCLUDE_ASM(const s32, "xhumungus", func_001CF788);

INCLUDE_ASM(const s32, "xhumungus", func_001CF7D0);

INCLUDE_ASM(const s32, "xhumungus", func_001CF818);

INCLUDE_ASM(const s32, "xhumungus", func_001CF860);

INCLUDE_ASM(const s32, "xhumungus", func_001CF8A8);

s32 func_001CF918() {
    if (D_002B834C == 1) {
        D_002B834C = 4;
    }
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001CF940);

INCLUDE_ASM(const s32, "xhumungus", func_001CF970);

INCLUDE_ASM(const s32, "xhumungus", func_001CFA08);

INCLUDE_ASM(const s32, "xhumungus", func_001CFA90);

INCLUDE_ASM(const s32, "xhumungus", func_001CFB28);

INCLUDE_ASM(const s32, "xhumungus", func_001CFBC0);

INCLUDE_ASM(const s32, "xhumungus", func_001CFC18);

INCLUDE_ASM(const s32, "xhumungus", func_001CFCB0);

INCLUDE_ASM(const s32, "xhumungus", func_001CFD08);

INCLUDE_ASM(const s32, "xhumungus", func_001CFD58);

INCLUDE_ASM(const s32, "xhumungus", func_001CFD90);

INCLUDE_ASM(const s32, "xhumungus", func_001CFDC8);

INCLUDE_ASM(const s32, "xhumungus", func_001CFE00);

INCLUDE_ASM(const s32, "xhumungus", func_001CFE30);

INCLUDE_ASM(const s32, "xhumungus", func_001CFE70);

INCLUDE_ASM(const s32, "xhumungus", func_001CFEB0);

INCLUDE_ASM(const s32, "xhumungus", func_001CFF30);

INCLUDE_ASM(const s32, "xhumungus", func_001D0078);

INCLUDE_ASM(const s32, "xhumungus", func_001D01D8);

INCLUDE_ASM(const s32, "xhumungus", func_001D0308);

INCLUDE_ASM(const s32, "xhumungus", func_001D0438);

INCLUDE_ASM(const s32, "xhumungus", func_001D04C0);

INCLUDE_ASM(const s32, "xhumungus", func_001D0548);

INCLUDE_ASM(const s32, "xhumungus", func_001D0590);

INCLUDE_ASM(const s32, "xhumungus", func_001D0600);

INCLUDE_ASM(const s32, "xhumungus", func_001D0670);

INCLUDE_ASM(const s32, "xhumungus", func_001D06F0);

INCLUDE_ASM(const s32, "xhumungus", func_001D0828);

INCLUDE_ASM(const s32, "xhumungus", func_001D0870);

INCLUDE_ASM(const s32, "xhumungus", func_001D0918);

s32 func_001D0970() {
    func_00104200(16);
    D_003854E0.unk_3078 |= 1;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D09A8);

s32 func_001D0A08() {
    func_00104310(16);
    D_003854E0.unk_3078 &= ~1;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D0A40);

INCLUDE_ASM(const s32, "xhumungus", func_001D0AA0);

INCLUDE_ASM(const s32, "xhumungus", func_001D0B50);

INCLUDE_ASM(const s32, "xhumungus", func_001D0B98);

INCLUDE_ASM(const s32, "xhumungus", func_001D0C98);

INCLUDE_ASM(const s32, "xhumungus", func_001D0D98);

INCLUDE_ASM(const s32, "xhumungus", func_001D0DE0);

INCLUDE_ASM(const s32, "xhumungus", func_001D0E78);

INCLUDE_ASM(const s32, "xhumungus", func_001D0F10);

INCLUDE_ASM(const s32, "xhumungus", func_001D1068);

INCLUDE_ASM(const s32, "xhumungus", func_001D11C0);

INCLUDE_ASM(const s32, "xhumungus", func_001D1238);

INCLUDE_ASM(const s32, "xhumungus", func_001D12D0);

INCLUDE_ASM(const s32, "xhumungus", func_001D1328);

INCLUDE_ASM(const s32, "xhumungus", func_001D1380);

INCLUDE_ASM(const s32, "xhumungus", func_001D13D8);

INCLUDE_ASM(const s32, "xhumungus", func_001D13F8);

s32 func_001D14F0() {
    func_00109B00();
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D1510);

INCLUDE_ASM(const s32, "xhumungus", func_001D1568);

INCLUDE_ASM(const s32, "xhumungus", func_001D1598);

INCLUDE_ASM(const s32, "xhumungus", func_001D15E0);

INCLUDE_ASM(const s32, "xhumungus", func_001D1628);

INCLUDE_ASM(const s32, "xhumungus", func_001D16C0);

INCLUDE_ASM(const s32, "xhumungus", func_001D17D0);

INCLUDE_ASM(const s32, "xhumungus", func_001D1878);

s32 func_001D1938() {
    D_002C1EA8 &= ~8;
    return 2;
}

s32 func_001D1958() {
    D_002C1EA8 |= 8;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D1978);

s32 func_001D19A8() {
    D_002C1EA8 |= 4;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D19C8);

INCLUDE_ASM(const s32, "xhumungus", func_001D1A20);

INCLUDE_ASM(const s32, "xhumungus", func_001D1A98);

INCLUDE_ASM(const s32, "xhumungus", func_001D1B10);

INCLUDE_ASM(const s32, "xhumungus", func_001D1BD8);

INCLUDE_ASM(const s32, "xhumungus", func_001D1C10);

INCLUDE_ASM(const s32, "xhumungus", func_001D1C48);

INCLUDE_ASM(const s32, "xhumungus", func_001D1C68);

INCLUDE_ASM(const s32, "xhumungus", func_001D1C88);

INCLUDE_ASM(const s32, "xhumungus", func_001D1D70);

INCLUDE_ASM(const s32, "xhumungus", func_001D1E20);

s32 func_001D1EE0(xBigBoii* arg0) {
    s32 val = D_002B8678;
    arg0->unk_174[3] += 1;
    arg0->unk_174[arg0->unk_174[3] + 4] = val;
    return 2;
}

s32 func_001D1F08(xBigBoii* arg0) {
    s32 val = D_002B8680;
    arg0->unk_174[3] += 1;
    arg0->unk_174[arg0->unk_174[3] + 4] = val;
    return 2;
}

s32 func_001D1F30(xBigBoii* arg0) {
    s32 val = D_002B8684;
    arg0->unk_174[3] += 1;
    arg0->unk_174[arg0->unk_174[3] + 4] = val;
    return 2;
}

s32 func_001D1F58(xBigBoii* arg0) {
    func_001055B8((long)arg0->unk_174[arg0->unk_174[3] + 4], 0);
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001D1FA0(xBigBoii* arg0) {
    func_001055B8((long)arg0->unk_174[arg0->unk_174[3] + 4], 1);
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001D1FE8(xBigBoii* arg0) {
    func_00111408(
        arg0->unk_174[arg0->unk_174[3] + 2], arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]
    );
    arg0->unk_174[3] -= 3;
    return 2;
}

s32 func_001D2040(xBigBoii* arg0) {
    func_00106380(
        arg0->unk_174[arg0->unk_174[3] + 1], arg0->unk_174[arg0->unk_174[3] + 2], arg0->unk_174[arg0->unk_174[3] + 3],
        arg0->unk_174[arg0->unk_174[3] + 4]
    );
    arg0->unk_174[3] -= 4;
    return 2;
}

s32 func_001D20A0(xBigBoii* arg0) {
    func_00106428(
        arg0->unk_174[arg0->unk_174[3] + 1], arg0->unk_174[arg0->unk_174[3] + 2], arg0->unk_174[arg0->unk_174[3] + 3],
        arg0->unk_174[arg0->unk_174[3] + 4]
    );
    arg0->unk_174[3] -= 4;
    return 2;
}

s32 func_001D2100() {
    func_001064E8();
    return 2;
}

s32 func_001D2120(xBigBoii* arg0) {
    func_0022F768(1);
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001D2158(xBigBoii* arg0) {
    func_0022F768(1);
    arg0->unk_174[3] -= 1;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D2190);

s32 func_001D2248() {
    func_00104200(1);
    D_003854E0.unk_3078 |= 1;
    return 2;
}

s32 func_001D2280() {
    func_00104310(1);
    D_003854E0.unk_3078 &= ~1;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D22B8);

INCLUDE_ASM(const s32, "xhumungus", func_001D2308);

INCLUDE_ASM(const s32, "xhumungus", func_001D23A8);

INCLUDE_ASM(const s32, "xhumungus", func_001D23D8);

void func_001D2440() {
    func_F20000(0, 0);
}

s32 func_001D2460() {
    func_00120590(D_0048A3A0, func_F20000, func_001D2440, NULL);
    return 2;
}

s32 func_001D2498() {
    D_0041F8BC = 0;
    return 2;
}

s32 func_001D24A8(xBigBoii* arg0) {
    arg0->unk_174[3] += 1;
    arg0->unk_174[arg0->unk_174[3] + 4] = func_00125BB8(1);
    return 2;
}

s32 func_001D24F0(xBigBoii* arg0) {
    arg0->unk_174[3] += 1;
    arg0->unk_174[arg0->unk_174[3] + 4] = func_00125BB8(2);
    return 2;
}

s32 func_001D2538(xBigBoii* arg0) {
    arg0->unk_174[3] += 1;
    arg0->unk_174[arg0->unk_174[3] + 4] = func_00125BB8(4);
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D2580);

s32 func_001D25D8() {
    D_003854E0.unk_3070 |= 0x10000000000;
    return 8;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D2600);

INCLUDE_ASM(const s32, "xhumungus", func_001D2840);

INCLUDE_ASM(const s32, "xhumungus", func_001D2A80);

INCLUDE_ASM(const s32, "xhumungus", func_001D2AF0);

INCLUDE_ASM(const s32, "xhumungus", func_001D2CA0);

INCLUDE_ASM(const s32, "xhumungus", func_001D2D28);

s32 func_001D2DB8(xBigBoii* arg0) {
    D_003854E0.unk_3148 |= arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001D2DF0(xBigBoii* arg0) {
    D_003854E0.unk_3148 &= ~arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001D2E30() {
    D_002C1EA8 |= 0x10;
    return 2;
}

s32 func_001D2E50() {
    D_002C1EA8 &= ~0x10;
    return 2;
}

s32 func_001D2E70() {
    D_002A2740 = 1;
    return 2;
}

s32 func_001D2E88() {
    D_002A2740 = 0;
    return 2;
}

s32 func_001D2E98(xBigBoii* arg0) {
    D_002A2744 = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001D2EC0(xBigBoii* arg0) {
    D_002A2748 = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3] -= 1;
    return 2;
}

// INCLUDE_ASM(const s32, "xhumungus", func_001D2EE8);
s32 func_001D2EE8(xBigBoii* arg0) {
    arg0->unk_174[3] += 1;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_002C2104;
    return 2;
}

s32 func_001D2F10(xBigBoii* arg0) {
    arg0->unk_174[3] += 1;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_002C2024;
    return 2;
}

s32 func_001D2F38(xBigBoii* arg0) {
    arg0->unk_174[3] += 1;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_002C2108;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D2F60);

void func_001D3080() {
    D_003854E0.unk_3070 &= ~0x200000000000;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D30B0);

INCLUDE_ASM(const s32, "xhumungus", func_001D3118);

INCLUDE_ASM(const s32, "xhumungus", func_001D3138);

INCLUDE_ASM(const s32, "xhumungus", func_001D3198);

INCLUDE_ASM(const s32, "xhumungus", func_001D3200);

INCLUDE_ASM(const s32, "xhumungus", func_001D3240);

INCLUDE_ASM(const s32, "xhumungus", func_001D3300);

INCLUDE_ASM(const s32, "xhumungus", func_001D33B8);

INCLUDE_ASM(const s32, "xhumungus", func_001D3498);

INCLUDE_ASM(const s32, "xhumungus", func_001D3570);

INCLUDE_ASM(const s32, "xhumungus", func_001D3668);

INCLUDE_ASM(const s32, "xhumungus", func_001D3750);

INCLUDE_ASM(const s32, "xhumungus", func_001D3860);

INCLUDE_ASM(const s32, "xhumungus", func_001D3960);

INCLUDE_ASM(const s32, "xhumungus", func_001D39B8);

INCLUDE_ASM(const s32, "xhumungus", func_001D3A20);

INCLUDE_ASM(const s32, "xhumungus", func_001D3A88);

s32 func_001D3AF0() {
    return 2;
}

s32 func_001D3AF8() {
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D3B00);

INCLUDE_ASM(const s32, "xhumungus", func_001D3CF0);

s32 func_001D3EF0(xBigBoii* arg0) {
    func_001E1F78(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001D3F38(xBigBoii* arg0) {
    func_001E22B0(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001D3F80(xBigBoii* arg0) {
    func_001E22F0(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001D3FC8(xBigBoii* arg0) {
    func_001E2628(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 1;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D4010);

INCLUDE_ASM(const s32, "xhumungus", func_001D4060);

INCLUDE_ASM(const s32, "xhumungus", func_001D40B0);

INCLUDE_ASM(const s32, "xhumungus", func_001D40F0);

s32 func_001D4190(xBigBoii* arg0) {
    arg0->unk_174[3] -= 1;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D41A8);

INCLUDE_ASM(const s32, "xhumungus", func_001D41F0);

INCLUDE_ASM(const s32, "xhumungus", func_001D42E8);

INCLUDE_ASM(const s32, "xhumungus", func_001D43E0);

INCLUDE_ASM(const s32, "xhumungus", func_001D4540);

INCLUDE_ASM(const s32, "xhumungus", func_001D45E0);

INCLUDE_ASM(const s32, "xhumungus", func_001D4690);

INCLUDE_ASM(const s32, "xhumungus", func_001D46F0);

INCLUDE_ASM(const s32, "xhumungus", func_001D4A30);

s32 func_001D4A98() {
    D_003854E0.unk_3070 &= ~0x800000000000;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D4AD0);

s32 func_001D4B38() {
    D_003854E0.unk_3070 &= ~0x1000000000000;
    return 2;
}

s32 func_001D4B70(xBigBoii* arg0) {
    func_00111A00((long)arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 1;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D4BB8);
void func_001D4BB8(); // temp for next function

s32 func_001D4C30(xBigBoii* arg0) {
    func_00111B70(arg0->unk_174[arg0->unk_174[3] + 4], func_001D4BB8);
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001D4C80() {
    func_00111BD8();
    return 2;
}

s32 func_001D4CA0() {
    func_00111BF0();
    return 2;
}

s32 func_001D4CC0(xBigBoii* arg0) {
    s32 val = func_00111C08();
    arg0->unk_174[3] += 1;
    arg0->unk_174[arg0->unk_174[3] + 4] = val;
    return 2;
}

s32 func_001D4D00(xBigBoii* arg0) {
    func_00111C20(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001D4D48(xBigBoii* arg0) {
    func_00111C38(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001D4D90(xBigBoii* arg0) {
    func_00111C60(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001D4DD8(xBigBoii* arg0) {
    func_00111C50(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 1;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D4E20);

s32 func_001D4E88() {
    D_003854E0.unk_3070 &= ~0x2000000000000;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D4EC0);

s32 func_001D4EE8() {
    D_00375BC0 &= ~8;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D4F08);

s32 func_001D4FB0(xBigBoii* arg0) {
    func_001E86A0(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001D4FF8(xBigBoii* arg0) {
    s32 val = func_00123880(arg0->unk_174[arg0->unk_174[3] + 3]);
    func_00137230(val, 0, arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D5068);

INCLUDE_ASM(const s32, "xhumungus", func_001D5128);

INCLUDE_ASM(const s32, "xhumungus", func_001D5158);

INCLUDE_ASM(const s32, "xhumungus", func_001D51D0);

INCLUDE_ASM(const s32, "xhumungus", func_001D5248);

INCLUDE_ASM(const s32, "xhumungus", func_001D52B0);

s32 func_001D5328() {
    func_00178140(0);
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D5348);

INCLUDE_ASM(const s32, "xhumungus", func_001D5378);

INCLUDE_ASM(const s32, "xhumungus", func_001D53A8);

INCLUDE_ASM(const s32, "xhumungus", func_001D5420);

INCLUDE_ASM(const s32, "xhumungus", func_001D5480);

INCLUDE_ASM(const s32, "xhumungus", func_001D54B0);

INCLUDE_ASM(const s32, "xhumungus", func_001D54E8);

s32 func_001D5528(xBigBoii* arg0) {
    func_0013C768(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001D5570(xBigBoii* arg0) {
    func_0013C7D0(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 1;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D55B8);

INCLUDE_ASM(const s32, "xhumungus", func_001D5608);

INCLUDE_ASM(const s32, "xhumungus", func_001D5658);

s32 func_001D56A8() {
    func_00112A50();
    D_003854E0.unk_3070 |= 0x10000000000;
    return 8;
}

s32 func_001D56E8() {
    func_0011C540();
    return 2;
}

s32 func_001D5708() {
    func_00111198();
    func_0022F808();
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D5730);

INCLUDE_ASM(const s32, "xhumungus", func_001D58F8);

INCLUDE_ASM(const s32, "xhumungus", func_001D59B8);

INCLUDE_ASM(const s32, "xhumungus", func_001D59F8);

INCLUDE_ASM(const s32, "xhumungus", func_001D5A70);

INCLUDE_ASM(const s32, "xhumungus", func_001D5AE8);

INCLUDE_ASM(const s32, "xhumungus", func_001D5B60);

INCLUDE_ASM(const s32, "xhumungus", func_001D5C00);

INCLUDE_ASM(const s32, "xhumungus", func_001D5C68);

INCLUDE_ASM(const s32, "xhumungus", func_001D5CE8);

INCLUDE_ASM(const s32, "xhumungus", func_001D5D58);

INCLUDE_ASM(const s32, "xhumungus", func_001D5DC8);

INCLUDE_ASM(const s32, "xhumungus", func_001D5E08);

INCLUDE_ASM(const s32, "xhumungus", func_001D5E48);

INCLUDE_ASM(const s32, "xhumungus", func_001D5E88);

INCLUDE_ASM(const s32, "xhumungus", func_001D5F20);

INCLUDE_ASM(const s32, "xhumungus", func_001D5FA0);

INCLUDE_ASM(const s32, "xhumungus", func_001D6020);

INCLUDE_ASM(const s32, "xhumungus", func_001D60A8);

INCLUDE_ASM(const s32, "xhumungus", func_001D63E0);

s32 func_001D6450(xBigBoii* arg0) {
    arg0->unk_174[3] += 1;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_003854E0.unk_3150;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D6478);

INCLUDE_ASM(const s32, "xhumungus", func_001D6520);

INCLUDE_ASM(const s32, "xhumungus", func_001D65D0);

INCLUDE_ASM(const s32, "xhumungus", func_001D6680);

s32 func_001D66F8(xBigBoii* arg0) {
    s32 val = D_002C1EA8 & 1;
    arg0->unk_174[3] += 1;
    arg0->unk_174[arg0->unk_174[3] + 4] = val;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D6728);

INCLUDE_ASM(const s32, "xhumungus", func_001D6750);

INCLUDE_ASM(const s32, "xhumungus", func_001D6778);

INCLUDE_ASM(const s32, "xhumungus", func_001D6828);

s32 func_001D68D8(xBigBoii* arg0) {
    func_001038B0(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001D6920(xBigBoii* arg0) {
    func_001037C8(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 1;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D6968);

INCLUDE_ASM(const s32, "xhumungus", func_001D6A78);

INCLUDE_ASM(const s32, "xhumungus", func_001D6AC0);

INCLUDE_ASM(const s32, "xhumungus", func_001D6B08);

INCLUDE_ASM(const s32, "xhumungus", func_001D6B30);

INCLUDE_ASM(const s32, "xhumungus", func_001D6B50);

INCLUDE_ASM(const s32, "xhumungus", func_001D6B88);

INCLUDE_ASM(const s32, "xhumungus", func_001D6C08);

INCLUDE_ASM(const s32, "xhumungus", func_001D6C58);

INCLUDE_ASM(const s32, "xhumungus", func_001D6CA8);

s32 func_001D6CD8() {
    func_0012C990(0, 0);
    return 2;
}

s32 func_001D6D00() {
    func_0012C990(0, 1);
    return 2;
}

s32 func_001D6D28() {
    func_0012C990(1, 0);
    return 2;
}

s32 func_001D6D50() {
    func_0012C990(1, 1);
    return 2;
}

s32 func_001D6D78() {
    func_0012C990(2, 0);
    return 2;
}

s32 func_001D6DA0() {
    func_0012C990(2, 1);
    return 2;
}

s32 func_001D6DC8() {
    func_0012C990(6, 0);
    return 2;
}

s32 func_001D6DF0() {
    func_0012C990(6, 1);
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D6E18);

s32 func_001D6EA8(xBigBoii* arg0) {
    s32 val = D_002DED08;
    arg0->unk_174[3] = arg0->unk_174[3] + 1;
    if (val == 2) {
        arg0->unk_174[arg0->unk_174[3] + 4] = 1;
    } else {
        arg0->unk_174[arg0->unk_174[3] + 4] = 0;
    }
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D6EF0);

INCLUDE_ASM(const s32, "xhumungus", func_001D6F38);

INCLUDE_ASM(const s32, "xhumungus", func_001D6F80);

INCLUDE_ASM(const s32, "xhumungus", func_001D6FD0);

s32 func_001D7028(xBigBoii* arg0) {
    arg0->unk_174[3] += 1;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_003854E0.unk_315C;
    return 2;
}

s32 func_001D7050(xBigBoii* arg0) {
    arg0->unk_174[3] += 1;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_003854E0.unk_3160;
    return 2;
}

s32 func_001D7078(xBigBoii* arg0) {
    arg0->unk_174[3] += 1;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_003854E0.unk_3164;
    return 2;
}

s32 func_001D70A0(xBigBoii* arg0) {
    arg0->unk_174[3] += 1;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_003854E0.unk_3168;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D70C8);

INCLUDE_ASM(const s32, "xhumungus", func_001D7178);

INCLUDE_ASM(const s32, "xhumungus", func_001D71A0);

INCLUDE_ASM(const s32, "xhumungus", func_001D7250);

INCLUDE_ASM(const s32, "xhumungus", func_001D7300);

INCLUDE_ASM(const s32, "xhumungus", func_001D7358);

INCLUDE_ASM(const s32, "xhumungus", func_001D76F0);

INCLUDE_ASM(const s32, "xhumungus", func_001D7730);

s32 func_001D7770(xBigBoii* arg0) {
    arg0->unk_174[3] += 1;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_003854E0.unk_3170;
    return 2;
}

s32 func_001D7798(xBigBoii* arg0) {
    arg0->unk_174[3] += 1;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_003854E0.unk_3174;
    return 2;
}

s32 func_001D77C0(xBigBoii* arg0) {
    D_003854E0.unk_3170 = arg0->unk_174[arg0->unk_174[3] + 3];
    D_003854E0.unk_3174 = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_001D7808(xBigBoii* arg0) {
    func_0014EE50(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001D7850(xBigBoii* arg0) {
    func_0014EE78(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001D7898() {
    int i = 1;
    int j;

    while (i < 0x20) {
        j = i + 1;
        func_0014EE50(i);
        i = j;
    }
    return 2;
}

s32 func_001D78D8() {
    int i = 1;
    int j;

    while (i < 0x20) {
        j = i + 1;
        func_0014EE78(i);
        i = j;
    }
    return 2;
}

s32 func_001D7918(xBigBoii* arg0) {
    D_002B8000 = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3] -= 1;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D7940);

s32 func_001D7998(xBigBoii* arg0) {
    func_001452E0(0, arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001D79E0(xBigBoii* arg0) {
    func_001452E0(1, arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001D7A28() {
    func_00145398();
    return 2;
}

s32 func_001D7A48() {
    func_00112B60();
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D7A68);

INCLUDE_ASM(const s32, "xhumungus", func_001D7B60);

INCLUDE_ASM(const s32, "xhumungus", func_001D7C00);

INCLUDE_ASM(const s32, "xhumungus", func_001D7D10);

INCLUDE_ASM(const s32, "xhumungus", func_001D7D70);

s32 func_001D7DD0(xBigBoii* arg0) {
    func_00111580(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001D7E18() {
    func_00249F88();
    return 2;
}

s32 func_001D7E38() {
    if (func_0024A000() == 0) {
        return 4;
    }
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D7E68);

s32 func_001D7EC8() {
    func_00104178();
    return 2;
}

s32 func_001D7EE8() {
    func_001009A8();
    return 2;
}

s32 func_001D7F08() {
    func_001009D8();
    return 2;
}

s32 func_001D7F28(xBigBoii* arg0) {
    func_001807B0(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001D7F70() {
    func_00180848();
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D7F90);

INCLUDE_ASM(const s32, "xhumungus", func_001D7FD8);

s32 func_001D8020(xBigBoii* arg0) {
    func_0023E0B0(arg0->unk_174[arg0->unk_174[3] + 4], 1);
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001D8068(xBigBoii* arg0) {
    func_0023E0B0(arg0->unk_174[arg0->unk_174[3] + 4], 3);
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001D80B0(xBigBoii* arg0) {
    func_0023E0B0(arg0->unk_174[arg0->unk_174[3] + 4], 1);
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001D80F8(xBigBoii* arg0) {
    func_0023E0B0(arg0->unk_174[arg0->unk_174[3] + 4], 0);
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001D8140() {
    D_002C1EA8 &= ~0x8000000;
    return 2;
}

s32 func_001D8168() {
    D_002C1EA8 |= 0x8000000;
    return 2;
}

s32 func_001D8188(xBigBoii* arg0) {
    arg0->unk_174[arg0->unk_174[3] + 4] = func_00105AE0((long)arg0->unk_174[arg0->unk_174[3] + 4]);
    return 2;
}

s32 func_001D81E0(xBigBoii* arg0) {
    func_00105B38(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_001D8230() {
    func_001116A8();
    return 2;
}

s32 func_001D8250() {
    func_001116B8();
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D8270);

INCLUDE_ASM(const s32, "xhumungus", func_001D8380);

s32 func_001D8408() {
    D_002B9660 = 0;
    return 2;
}

s32 func_001D8418() {
    D_002B9660 = 1;
    return 2;
}

s32 func_001D8430() {
    D_003854E0.unk_3070 |= 0x800000000000000;
    return 2;
}

s32 func_001D8458() {
    D_003854E0.unk_3070 &= ~0x800000000000000;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D8490);

INCLUDE_ASM(const s32, "xhumungus", func_001D8500);

INCLUDE_ASM(const s32, "xhumungus", func_001D8570);

s32 func_001D85C0() {
    D_002C1EA8 &= ~0x800;
    return 2;
}

s32 func_001D85E0() {
    D_002C1EA8 |= 0x800;
    return 2;
}

s32 func_001D8600() {
    D_002C1EA8 &= ~0x200;
    return 2;
}

s32 func_001D8620() {
    D_002C1EA8 |= 0x200;
    return 2;
}

s32 func_001D8640() {
    D_002C1EA8 &= ~0x400;
    return 2;
}

s32 func_001D8660() {
    D_002C1EA8 |= 0x400;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D8680);

s32 func_001D8700(xBigBoii* arg0) {
    arg0->unk_174[3] = arg0->unk_174[3] + 1;
    arg0->unk_174[arg0->unk_174[3] + 4] = func_00125B90(1);
    return 2;
}

s32 func_001D8748(xBigBoii* arg0) {
    arg0->unk_174[3] += 1;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_003854E0.unk_3380;
    return 2;
}

s32 func_001D8770() {
    D_00388860 = 0;
    return 2;
}

s32 func_001D8780() {
    D_002C1EA8 |= 0x1000;
    return 2;
}

s32 func_001D87A0() {
    D_002C1EA8 &= ~0x1000;
    return 2;
}

s32 func_001D87C0(xBigBoii* arg0) {
    func_001F0A90(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001D8808(xBigBoii* arg0) {
    func_001128F0(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 1;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D8850);

INCLUDE_ASM(const s32, "xhumungus", func_001D8928);

INCLUDE_ASM(const s32, "xhumungus", func_001D8A00);

s32 func_001D8A30(xBigBoii* arg0) {
    arg0->unk_174[3] -= 1;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D8A48);

INCLUDE_ASM(const s32, "xhumungus", func_001D8A68);

INCLUDE_ASM(const s32, "xhumungus", func_001D8AF0);

INCLUDE_ASM(const s32, "xhumungus", func_001D8B30);

INCLUDE_ASM(const s32, "xhumungus", func_001D8C50);

INCLUDE_ASM(const s32, "xhumungus", func_001D8CD0);

INCLUDE_ASM(const s32, "xhumungus", func_001D8D38);

INCLUDE_ASM(const s32, "xhumungus", func_001D8D60);

void func_001D8DB8() {
    D_003854E0.unk_3070 &= ~0x2000000000000000;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D8DE8);

INCLUDE_ASM(const s32, "xhumungus", func_001D8E90);

INCLUDE_ASM(const s32, "xhumungus", func_001D8EE0);

INCLUDE_ASM(const s32, "xhumungus", func_001D8F00);

void func_001D8F80() {
    D_003854E0.unk_3070 &= ~0x4000000000000000;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D8FB0);

INCLUDE_ASM(const s32, "xhumungus", func_001D9038);

INCLUDE_ASM(const s32, "xhumungus", func_001D9058);

INCLUDE_ASM(const s32, "xhumungus", func_001D90B0);

INCLUDE_ASM(const s32, "xhumungus", func_001D93B8);

INCLUDE_ASM(const s32, "xhumungus", func_001D9720);

INCLUDE_ASM(const s32, "xhumungus", func_001D9C28);

s32 func_001D9DD0(xBigBoii* arg0) {
    func_00156BA0(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001D9E18(xBigBoii* arg0) {
    func_00156B70(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001D9E60() {
    D_002C1EA8 &= ~0x8000;
    return 2;
}

s32 func_001D9E88() {
    D_002C1EA8 |= 0x8000;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001D9EA8);

INCLUDE_ASM(const s32, "xhumungus", func_001D9F08);

INCLUDE_ASM(const s32, "xhumungus", func_001D9F60);

s32 func_001D9F88(xBigBoii* arg0) {
    arg0->unk_174[arg0->unk_174[3] + 4] = func_00158C30(arg0->unk_174[arg0->unk_174[3] + 4]);
    return 2;
}

s32 func_001D9FE0() {
    D_003854E0.unk_3078 |= 1;
    return 2;
}

s32 func_001DA000() {
    D_003854E0.unk_3078 &= ~1;
    D_00375BC0 &= ~1;
    D_002B8348 = 1.0;
    D_002C1EA8 &= ~0x400;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001DA060);

s32 func_001DA0F0(xBigBoii* arg0) {
    func_0013C1E0(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001DA138(xBigBoii* arg0) {
    func_0013C1F0(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001DA180(xBigBoii* arg0) {
    func_0013C148(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001DA1C8(xBigBoii* arg0) {
    if (arg0->unk_174[arg0->unk_174[3] + 4] != 0) {
        func_0012C990(3, 1);
    } else {
        func_0012C990(3, 0);
    }
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001DA228(xBigBoii* arg0) {
    if (arg0->unk_174[arg0->unk_174[3] + 4] != 0) {
        func_0012C990(4, 1);
    } else {
        func_0012C990(4, 0);
    }
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001DA288(xBigBoii* arg0) {
    if (arg0->unk_174[arg0->unk_174[3] + 4] != 0) {
        func_0012C990(5, 1);
    } else {
        func_0012C990(5, 0);
    }
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001DA2E8(xBigBoii* arg0) {
    func_0014A070(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001DA330() {
    func_00114400();
    return 2;
}

s32 func_001DA350() {
    func_00114410();
    return 2;
}

s32 func_001DA370() {
    func_00112AD8();
    return 2;
}

s32 func_001DA390() {
    if (func_00110EA8() == 2) {
        return 2;
    }
    return 4;
}

s32 func_001DA3C0(xBigBoii* arg0) {
    func_00110E38(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001DA408() {
    func_00110E78();
    return 2;
}

s32 func_001DA428() {
    if (func_00110EA8() != 4) {
        return 4;
    }
    return 2;
}

s32 func_001DA458(xBigBoii* arg0) {
    func_001114B8(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_001DA4A8(xBigBoii* arg0) {
    func_001424E8(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001DA4F0(xBigBoii* arg0) {
    func_0013C230(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_001DA540(xBigBoii* arg0) {
    arg0->unk_174[arg0->unk_174[3] + 4] = func_0013C280(arg0->unk_174[arg0->unk_174[3] + 4]);
    return 2;
}

s32 func_001DA598(xBigBoii* arg0) {
    func_00157158(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 1;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001DA5E0);

s32 func_001DA638(xBigBoii* arg0) {
    func_00105510(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_001DA688(xBigBoii* arg0) {
    func_00105560(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_001DA6D8(xBigBoii* arg0) {
    arg0->unk_174[3] += 1;
    arg0->unk_174[arg0->unk_174[3] + 4] = func_001EF300();
    return 2;
}

s32 func_001DA720() {
    func_00112190();
    return 2;
}

s32 func_001DA740() {
    func_001121A8();
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001DA760);

INCLUDE_ASM(const s32, "xhumungus", func_001DA940);

INCLUDE_ASM(const s32, "xhumungus", func_001DAAA8);

INCLUDE_ASM(const s32, "xhumungus", func_001DAB88);

INCLUDE_ASM(const s32, "xhumungus", func_001DACC8);

INCLUDE_ASM(const s32, "xhumungus", func_001DAD58);

INCLUDE_ASM(const s32, "xhumungus", func_001DAE38);

s32 func_001DAF70() {
    func_001116F8();
    func_0011C5B8();
    return 6;
}

INCLUDE_ASM(const s32, "xhumungus", func_001DAF98);

INCLUDE_ASM(const s32, "xhumungus", func_001DAFC8);

s32 func_001DB078() {
    func_00103730();
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001DB098);

s32 func_001DB0C8(xBigBoii* arg0) {
    func_00108488(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_001DB118(xBigBoii* arg0) {
    func_001084F0(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

void func_001DB168() {
    D_003854E0.unk_3070 &= ~0x200000000000;
}

INCLUDE_ASM(const s32, "xhumungus", func_001DB198);

INCLUDE_ASM(const s32, "xhumungus", func_001DB218);

void func_001DB238(void) {
}

INCLUDE_ASM(const s32, "xhumungus", func_001DB240);

INCLUDE_ASM(const s32, "xhumungus", func_001DB298);

INCLUDE_ASM(const s32, "xhumungus", func_001DB2E8);

INCLUDE_ASM(const s32, "xhumungus", func_001DB340);

INCLUDE_ASM(const s32, "xhumungus", func_001DB3A0);

INCLUDE_ASM(const s32, "xhumungus", func_001DB3F8);

INCLUDE_ASM(const s32, "xhumungus", func_001DB450);

INCLUDE_ASM(const s32, "xhumungus", func_001DB4A8);

INCLUDE_ASM(const s32, "xhumungus", func_001DB4F8);

INCLUDE_ASM(const s32, "xhumungus", func_001DB578);

INCLUDE_ASM(const s32, "xhumungus", func_001DB5D0);
void func_001DB5D0(); // temp for next function

s32 func_001DB618() {
    func_0011ED30(0xc352, func_001DB5D0);
    D_003854E0.unk_3078 |= 4;
    return 2;
}

s32 func_001DB658() {
    D_003854E0.unk_3078 &= ~4;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001DB678);

s32 func_001DB6C8(xBigBoii* arg0) {
    func_0013C858(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_001DB718(xBigBoii* arg0) {
    D_002B8004 = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001DB740(xBigBoii* arg0) {
    D_002B8008 = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3] -= 1;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001DB768);

INCLUDE_ASM(const s32, "xhumungus", func_001DB7A8);

s32 func_001DB810(xBigBoii* arg0) {
    D_002B8014 = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001DB838(xBigBoii* arg0) {
    func_0013C338(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001DB880() {
    D_00375BC0 &= ~4;
    D_003854E0.unk_3070 &= ~0x2000000000;
    return 2;
}

s32 func_001DB8C8(xBigBoii* arg0) {
    func_001BC480(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 1;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001DB910);

s32 func_001DB970() {
    if ((D_002C1EAA & 1) != 0) {
        return 4;
    }
    return 2;
}

s32 func_001DB990() {
    if ((D_002C1EA8 & 0x6000) != 0) {
        return 4;
    }
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001DB9B0);

s32 func_001DBA00() {
    if (func_00235F50() != 0) {
        return 4;
    }
    return 2;
}

s32 func_001DBA30(xBigBoii* arg0) {
    s32 val = D_003F0DD4;
    arg0->unk_174[3] += 1;
    arg0->unk_174[arg0->unk_174[3] + 4] = val;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001DBA58);

INCLUDE_ASM(const s32, "xhumungus", func_001DBAE8);

INCLUDE_ASM(const s32, "xhumungus", func_001DBB50);

INCLUDE_ASM(const s32, "xhumungus", func_001DBC40);

INCLUDE_ASM(const s32, "xhumungus", func_001DBC88);

INCLUDE_ASM(const s32, "xhumungus", func_001DBD18);

INCLUDE_ASM(const s32, "xhumungus", func_001DBDA8);

INCLUDE_ASM(const s32, "xhumungus", func_001DBE38);

INCLUDE_ASM(const s32, "xhumungus", func_001DBEB0);

INCLUDE_ASM(const s32, "xhumungus", func_001DBF58);

INCLUDE_ASM(const s32, "xhumungus", func_001DBFC8);

s32 func_001DC040(xBigBoii* arg0) {
    func_00131B90(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001DC090);

INCLUDE_ASM(const s32, "xhumungus", func_001DC0E8);

INCLUDE_ASM(const s32, "xhumungus", func_001DC140);

INCLUDE_ASM(const s32, "xhumungus", func_001DC198);

INCLUDE_ASM(const s32, "xhumungus", func_001DC1F0);

s32 func_001DC278() {
    D_002B9338 = 0;
    return 2;
}

s32 func_001DC288() {
    D_002B9338 = 1;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001DC2A0);

s32 func_001DC368(xBigBoii* arg0) {
    arg0->unk_174[3] += 1;
    arg0->unk_174[arg0->unk_174[3] + 4] = func_001F0A80();
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001DC3B0);

INCLUDE_ASM(const s32, "xhumungus", func_001DC3D8);

s32 func_001DC428(xBigBoii* arg0) {
    s32 val = D_002B9170;
    arg0->unk_174[3] += 1;
    arg0->unk_174[arg0->unk_174[3] + 4] = val;
    return 2;
}

s32 func_001DC450(xBigBoii* arg0) {
    s32 val = D_002B916C;
    arg0->unk_174[3] += 1;
    arg0->unk_174[arg0->unk_174[3] + 4] = val;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001DC478);

INCLUDE_ASM(const s32, "xhumungus", func_001DC4D0);

void func_001DC538() {
    D_003854E0.unk_3078 &= ~0x20;
}

s32 func_001DC558(xBigBoii* arg0) {
    if (func_00149E38(arg0->unk_174[arg0->unk_174[3] + 4], func_001DC538)) {
        D_003854E0.unk_3078 |= 0x20;
    }
    arg0->unk_174[3] -= 1;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001DC5C0);

INCLUDE_ASM(const s32, "xhumungus", func_001DC5E8);

s32 func_001DC8A8(xBigBoii* arg0) {
    func_001ED6F0(arg0->unk_174[arg0->unk_174[3] + 4], 1);
    arg0->unk_174[3] -= 1;
    return 2;
}

s32 func_001DC8F0() {
    func_00111F00();
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001DC910);

INCLUDE_ASM(const s32, "xhumungus", func_001DC960);

INCLUDE_ASM(const s32, "xhumungus", func_001DC9D0);

INCLUDE_ASM(const s32, "xhumungus", func_001DCA28);

INCLUDE_ASM(const s32, "xhumungus", func_001DCA98);

INCLUDE_ASM(const s32, "xhumungus", func_001DCB08);

INCLUDE_ASM(const s32, "xhumungus", func_001DCB70);

INCLUDE_ASM(const s32, "xhumungus", func_001DCBD8);

INCLUDE_ASM(const s32, "xhumungus", func_001DCC48);

INCLUDE_ASM(const s32, "xhumungus", func_001DCC98);

INCLUDE_ASM(const s32, "xhumungus", func_001DCCE8);

INCLUDE_ASM(const s32, "xhumungus", func_001DCD38);

INCLUDE_ASM(const s32, "xhumungus", func_001DCD90);

INCLUDE_ASM(const s32, "xhumungus", func_001DCDE0);

s32 func_001DCE30() {
    D_00375BC0 |= 0x10;
    return 2;
}

s32 func_001DCE50() {
    D_00375BC0 &= ~0x10;
    return 2;
}

s32 func_001DCE70() {
    func_001ED878(0);
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001DCE90);

INCLUDE_ASM(const s32, "xhumungus", func_001DCEE8);

INCLUDE_ASM(const s32, "xhumungus", func_001DCFA8);

INCLUDE_ASM(const s32, "xhumungus", func_001DD118);

INCLUDE_ASM(const s32, "xhumungus", func_001DD170);

INCLUDE_ASM(const s32, "xhumungus", func_001DD1E0);

INCLUDE_ASM(const s32, "xhumungus", func_001DD250);

INCLUDE_ASM(const s32, "xhumungus", func_001DD288);

INCLUDE_ASM(const s32, "xhumungus", func_001DD2C0);

INCLUDE_ASM(const s32, "xhumungus", func_001DD318);

s32 func_001DD370() {
    D_002C1EA8 |= 0x20;
    return 2;
}

s32 func_001DD390() {
    D_002C1EA8 &= ~0x20;
    return 2;
}

s32 func_001DD3B0() {
    D_003854E0.unk_3078 &= ~0x80;
    return 2;
}

s32 func_001DD3D0() {
    D_003854E0.unk_3078 |= 0x80;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001DD3F0);

INCLUDE_ASM(const s32, "xhumungus", func_001DD430);

s32 func_001DD480() {
    D_002C1EA8 |= 0x200000;
    return 2;
}

s32 func_001DD4A0() {
    D_002C1EA8 &= ~0x200000;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001DD4C8);

s32 func_001DD520(xBigBoii* arg0) {
    arg0->unk_174[3] += 1;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_003889B0;
    return 2;
}

void func_001DD548() {
    D_003854E0.unk_3078 &= ~0x100;
}

s32 func_001DD568() {
    D_003854E0.unk_3078 |= 0x100;
    func_0011E830(func_001DD548, func_F20000);
    return 2;
}

s32 func_001DD5B0() {
    D_003854E0.unk_3078 |= 0x100;
    func_0011E830(func_001DD548, &D_003D55DC);
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001DD5F8);

// Nonmatch: Regswap
INCLUDE_ASM(const s32, "xhumungus", func_001DD620);
// void func_001DD620(UNK_TYPE arg0, UNK_TYPE arg1, s32 arg2) {
//     func_00177908(arg2);
//     D_003854E0.unk_3078 &= ~0x200;
// }

INCLUDE_ASM(const s32, "xhumungus", func_001DD658);

INCLUDE_ASM(const s32, "xhumungus", func_001DD6E0);

INCLUDE_ASM(const s32, "xhumungus", func_001DD708);

INCLUDE_ASM(const s32, "xhumungus", func_001DD750);

INCLUDE_ASM(const s32, "xhumungus", func_001DD7B0);

INCLUDE_ASM(const s32, "xhumungus", func_001DD7F8);

s32 func_001DD848(xBigBoii* arg0) {
    func_0013BF20(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 1;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001DD890);

s32 func_001DD990() {
    func_00125B40(1);
    return 2;
}

s32 func_001DD9B0() {
    func_00125B40(0);
    return 2;
}

s32 func_001DD9D0() {
    s32 i, j = 0;

    do {
        i = j + 1;
        func_001BC4F8(j, 99);
        j = i;
    } while (i < 0x47);
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001DDA18);

s32 func_001DDA78(xBigBoii* arg0) {
    s32 sVar2 = D_002B29C4;
    arg0->unk_174[3] += 1;
    arg0->unk_174[arg0->unk_174[3] + 4] = sVar2;
    return 2;
}

INCLUDE_ASM(const s32, "xhumungus", func_001DDAA0);

INCLUDE_ASM(const s32, "xhumungus", func_001DDAF0);

INCLUDE_ASM(const s32, "xhumungus", func_001DDB58);

INCLUDE_ASM(const s32, "xhumungus", func_001DDC08);

void func_001DDCB8(UNK_TYPE arg0, s32 idx) {
    D_003D4A20[idx](arg0);
}

INCLUDE_ASM(const s32, "xhumungus", func_001DDCE8);

INCLUDE_ASM(const s32, "xhumungus", func_001DDFA0);

void func_001DE098() {
    D_003854E0.unk_3380 += 1;
}

INCLUDE_ASM(const s32, "xhumungus", func_001DE0B0);

INCLUDE_ASM(const s32, "xhumungus", func_001DE1B8);

s32 func_001DE338() {
    func_0011EF58(&D_00624960, 0);
    return 0;
}

s32 func_001DE360() {
    s32 result;

    D_00624550 = func_00155ED8(0x32, 2);
    D_00624554 = D_00624550 + 0x7D000;
    func_0011EDD0(&D_00624960, &D_00624970, 0x50, 0x100);
    result = func_0011ED30(49999, func_001DE338);
    D_00624958 = NULL;
    return result;
}

void func_001DE3E0(void* arg0, void* arg1) {
    D_00624550 = arg0;
    D_00624554 = arg1;
}

INCLUDE_ASM(const s32, "xhumungus", func_001DE3F8);

INCLUDE_ASM(const s32, "xhumungus", func_001DE518);

INCLUDE_ASM(const s32, "xhumungus", func_001DE5F0);

INCLUDE_ASM(const s32, "xhumungus", func_001DE680);

INCLUDE_ASM(const s32, "xhumungus", func_001DE750);

INCLUDE_ASM(const s32, "xhumungus", func_001DE7C0);

void func_001DEDF8() {
    func_00177908(D_00624550);
    D_003854E0.unk_3070 &= ~0x100000000000;
}

s32 func_001DEE48() {
    return func_00120590(&D_00624658, D_00624550, func_001DEDF8, NULL);
}
