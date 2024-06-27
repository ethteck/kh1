#include "common.h"

// Kingdom Hearts universally uses a slightly incorrect value for Pi (3.1415927)
#define PI 3.1415928f

f32 cosf(f32);
f32 atan2f(f32, f32);

/// inline asm sqrt to bypass fastmath flag, avoids optimizations not present in final binary
static inline f32 _sqrtf(f32 arg) {
    f32 result;

    __asm__ volatile("sqrt.s %0, %1" : "=f"(result) : " f"(arg));
    return result;
}
