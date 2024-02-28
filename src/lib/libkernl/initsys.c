#include "common.h"
#include "eekernel.h"

#define KSEG0 0x80000000
#define SYSCALL(id) __asm__ volatile("li $3,"#id"\n syscall")

typedef struct {
    int num;
    void *func;
} _sysEntry;
static s32 *kFindAddress(s32 value);
static void setup(s32 n, void (*f)());

_sysEntry SysEntry = {.num = 0x83, .func = &kFindAddress};
int _pad = 0;
int __sce_sema_id = 0;
int __sce_eh_sema_id = 0;
s32 *_SyscallEntry = 0;

void supplement_crt0(void) {
    struct SemaParam libc_sema;
    struct SemaParam eh_sema;
    
    libc_sema.maxCount = 0x1;
    libc_sema.initCount = 0x1;
    eh_sema.maxCount = 0x1;
    eh_sema.initCount = 0x1;
    __sce_sema_id = CreateSema(&libc_sema);
    __sce_eh_sema_id = CreateSema(&eh_sema);
    return;
}

static s32 *kFindAddress(s32 value) {
    s32 *addr;
    
    addr = (s32*)KSEG0;
    while (*addr != value) {
        addr++;
    }
    return addr;
}

static u32 FindAddress(void *value) {
    SYSCALL(0x83);
}

int GetSystemCallTableEntry() {
    u32 addr;
    
    setup(SysEntry.num, SysEntry.func);
    addr = FindAddress(&kFindAddress);
    return addr - 0x20C;
}

static void setup(s32 n, void (*f)()) {
    SYSCALL(0x74);
}

static s32 *_setup(s32 n) {
    SYSCALL(0x74);
    return _SyscallEntry + n;
}

void _InitSys() {
    supplement_crt0();
    GetSystemCallTableEntry();
    InitAlarm();
    InitThread();
    InitExecPS2();
    InitTLBFunctions();
    return;
}
