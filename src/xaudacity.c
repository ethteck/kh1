#include "common.h"
#include "math.h"

extern s32 D_002979E8;
extern f32 D_002B8344[];
extern f32 D_002B8348;

extern s32 D_002DF430;
extern s32 D_002DF43C;

extern f32 func_00120AC8(f32);
extern f32 func_00177D68(void);
extern s32 func_00147A10(s32);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00128E28);
// void func_00128E28(f32* arg0) {
//     f32 x = func_00120AC8((*arg0 / 180.0f) * PI);
//     *arg0 = sinf(x);
// }

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00128E80);
// void func_00128E80(f32* arg0) {
//     f32 x = func_00120AC8((*arg0 / 180.0f) * PI);
//     *arg0 = cosf(x);
// }

void func_00128ED8(f32* arg0) {
    *arg0 = func_00177D68();
}

void func_00128F00(f32* arg0) {
    *arg0 = D_002B8344[0];
}

void func_00128F10(s32* arg0) {
    *arg0 = func_00147A10(*arg0);
}

void func_00128F40(void) {
}

void func_00128F48(void) {
}

void func_00128F50(void) {
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00128F58);
// void func_00128F58(f32* arg0) {
//     *arg0 = func_00120AC8((*arg0 / 180.0f) * PI);
// }

void func_00128FA8(f32* arg0) {
    D_002B8348 = *arg0;
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00128FB8);

void func_00128FE8(f32** arg0) {
    sceVu0AddVector(arg0[0], arg0[0], arg0[1]);
}

void func_00129010(f32** arg0) {
    sceVu0SubVector(arg0[0], arg0[0], arg0[1]);
}

void func_00129038(f32** arg0) {
    func_001223B0(arg0[0], arg0[0]);
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129058);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_001290C8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129138);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129188);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_001291D8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129200);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129230);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129260);

void func_00129320(void) {
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129328);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129358);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129398);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_001293C0);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_001293F8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129430);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129458);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129490);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_001294C0);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_001294E0);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129500);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129540);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129570);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_001295A8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_001295D8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129608);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129638);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129660);

void func_001296A8(void) {
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_001296B0);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_001296D0);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129700);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129718);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129748);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129780);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_001297A8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_001297C0);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_001297F0);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129820);

void func_00129840(void) {
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129848);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129868);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129878);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_001298A8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_001298D8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129910);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129938);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129960);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_001299B8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_001299F0);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129A18);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129A48);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129A80);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129AB0);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129AC8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129AE8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129B28);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129B40);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129B88);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129BC0);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129C08);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129C30);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129C58);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129C88);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129CA8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129CC0);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129CF8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129D18);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129D38);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129D58);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129D70);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129D98);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129DD8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129DF8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129E18);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129E78);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129EA8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129F20);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129F40);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129F60);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129F88);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129FB8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129FD0);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A000);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A018);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A038);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A078);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A098);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A0C8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A0E0);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A0F8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A128);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A140);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A168);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A1B8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A1C8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A1F8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A210);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A270);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A280);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A308);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A328);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A360);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A3D0);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A418);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A450);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A470);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A488);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A4C8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A4E8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A528);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A548);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A5F0);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A628);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A648);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A680);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A6B8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A6D8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A700);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A720);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A738);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A760);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A7A0);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A7D0);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A7F0);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A818);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A838);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A888);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A8A0);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A8E8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A900);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A968);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A9B8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012AA08);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012AA28);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012AA60);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012AA80);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012AAB0);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012AAE0);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012AB10);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012AB60);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012AB90);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012ABC8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012AC08);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012AC40);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012AC58);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012AC78);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012ACA8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012ACE0);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012ACF8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012AD20);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012AD50);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012AD68);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012AD88);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012ADB8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012ADE0);

void func_0012AE00(void) {
    func_0011D598(65);
    func_001ED878(14);
    func_0023F758();
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012AE28);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012AE78);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012AEB8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012AFF0);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012B030);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012B068);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012B088);

void func_0012B0A8(s32* arg0) {
    *arg0 = func_0012CBC0(*arg0);
}

void func_0012B0D8(s32* arg0) {
    *arg0 = &D_002DF430;
}

void func_0012B0E8(s32* arg0) {
    *arg0 = &D_002DF43C;
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012B0F8);

void func_0012B120(s32* arg0) {
    *arg0 = func_00146740(*arg0);
}

void func_0012B150(s32* arg0) {
    func_00146610(arg0[0], arg0[1], 1);
}

void func_0012B170(s32* arg0) {
    *arg0 = func_001C6530(arg0[0], arg0[1]);
}

void func_0012B1A0(s32* arg0) {
    *arg0 = D_002979E8;
}
