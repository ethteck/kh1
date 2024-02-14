#include "common.h"
#include "xspinach.h"

#include "stdio.h"
#include "string.h"

extern s32 D_002B8678;
extern s32 D_002B8680;

const char* D_002B9178[21] = {
    "dh", "di", "dc", "tw", "aw", "tz", "po", "xx", "al", "lm", "nm",
    "he", "pi", "pp", "xx", "pc", "ew", "xx", "xx", "xx", "zz",
};

char D_002B91D0[] = ".wdt";
char D_002B91D8[] = ".ard";
s32 D_002B91E0 = 0;
s32 D_002B91E4 = 0;
s32 D_002B91E8 = 0;
s32 D_002B91EC = 0;
char D_002B91F0[64] = {};
char D_002B9230[64] = {};
char D_002B9270[64] = {};
char D_002B92B0[64] = {};

char* func_00111F40(int idx, char* dest) {
    return strcpy(dest, D_002B9178[idx]);
}

char* func_00111F68(s32 idx, s32 arg1, s32 arg2, char* dest) {
    char str[0x10];
    char stack[0x40];

    func_00111F40(idx, stack);
    sprintf(str, "%2d", arg1 + 1);
    if (str[0] == ' ') {
        str[0] = '0';
    }
    strcpy(dest, stack);
    return strcat(dest, str);
}

char* func_00111FF0() {
    char str[16];
    char stack[64];

    func_00111F40(D_002B8678, stack);
    sprintf(str, "%2d", D_002B8680 + 1);
    if (str[0] == ' ') {
        str[0] = '0';
    }
    strcpy(D_002B91F0, stack);
    strcat(D_002B91F0, D_002B91D0);
    strcpy(D_002B92B0, stack);
    strcat(D_002B92B0, str);
    strcat(D_002B92B0, D_002B91D8);
    strcpy(D_002B9270, stack);
    return strcat(D_002B9270, str);
}

char* func_001120D0(s32 arg0) {
    char str[16];
    char stack[64];

    func_00111F40(D_002B8678, stack);
    sprintf(str, "%2d", arg0 + 1);
    if (str[0] == ' ') {
        str[0] = '0';
    }
    strcpy(D_002B9230, stack);
    strcat(D_002B9230, "00_");
    return strcat(D_002B9230, str);
}
