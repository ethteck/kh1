#include "common.h"
#include "stdio.h"
#include "string.h"

const char* D_002B9178[22];
//  = {
// "dh", "di", "dc", "tw", "aw", "tz", "po", "xx", "al", "lm", "nm",
// "he", "pi", "pp", "xx", "pc", "ew", "xx", "xx", "xx", "zz", "",
// };

char* func_00111F40(int idx, char* src) {
    return strcpy(src, D_002B9178[idx]);
}

INCLUDE_ASM(const s32, "xspinach", func_00111F68);

INCLUDE_ASM(const s32, "xspinach", func_00111FF0);

INCLUDE_ASM(const s32, "xspinach", func_001120D0);
