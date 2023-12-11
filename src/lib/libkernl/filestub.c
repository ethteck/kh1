#include "common.h"
#include "eekernel.h"
#include <sifdev.h>

s32 _fs_init;
s32 _fs_semid;
s32 _fs_iob_semid;
s32 _fs_fsq_semid;

char _fsversion[24];

void _sceFsIobSemaMK() {
    struct SemaParam param;

    if (_fs_iob_semid == -1) {
        param.option = 0;
        param.initCount = 1;
        param.maxCount = 1;

        _fs_iob_semid = CreateSema(&param);
        _fs_fsq_semid = CreateSema(&param);
    }
}

INCLUDE_ASM(const s32, "lib/libkernl/filestub", new_iob);

INCLUDE_ASM(const s32, "lib/libkernl/filestub", get_iob);

INCLUDE_ASM(const s32, "lib/libkernl/filestub", _sceFs_Rcv_Intr);

void _sceFsSemInit() {
    struct SemaParam param;
    if (_fs_semid == -1) {
        param.option = 0;
        param.initCount = 1;
        param.maxCount = 1;
        _fs_semid = CreateSema(&param);
    }
}

s32 _sceFsWaitS() {
    _sceFsSemInit();
    WaitSema(_fs_semid);
    return 0;
}

void _sceFsSigSema() {
    SignalSema(_fs_semid);
}

INCLUDE_ASM(const s32, "lib/libkernl/filestub", scePowerOffHandler);

INCLUDE_ASM(const s32, "lib/libkernl/filestub", _sceFs_Poff_Intr);

INCLUDE_ASM(const s32, "lib/libkernl/filestub", sceFsInit);

INCLUDE_ASM(const s32, "lib/libkernl/filestub", _fs_version);

/**
 * @brief Invalidate file service bind information. 
 * This function should always be called after the IOP is reset,
 * since the file service RPC BIND information will be invalid.
 * @return Always returns 0
 */
s32 sceFsReset() {
    _fs_init = 0;
    memset(_fsversion, 0, 4);
    return 0;
}

INCLUDE_ASM(const s32, "lib/libkernl/filestub", sceOpen);

INCLUDE_ASM(const s32, "lib/libkernl/filestub", sceClose);

INCLUDE_ASM(const s32, "lib/libkernl/filestub", sceLseek);

INCLUDE_ASM(const s32, "lib/libkernl/filestub", sceRead);

INCLUDE_ASM(const s32, "lib/libkernl/filestub", sceWrite);

INCLUDE_ASM(const s32, "lib/libkernl/filestub", sceIoctl);

INCLUDE_ASM(const s32, "lib/libkernl/filestub", sceIoctl2);

INCLUDE_ASM(const s32, "lib/libkernl/filestub", _sceCallCode);

/**
 * @brief Delete file
 * @param filename File pathname (includes device name and ':')
 * @return 0 on success, -1 * error code on failure 
 */
s32 sceRemove(const char* filename) {
    return _sceCallCode(filename, 6);
}

INCLUDE_ASM(const s32, "lib/libkernl/filestub", sceMkdir);

/**
 * @brief Delete directory
 * @param dirname Directory pathname (includes device name and ':')
 * @return 0 on success, -1 * error code on failure
 */
s32 sceRmdir(const char* dirname) {
    return _sceCallCode(dirname, 8);
}

INCLUDE_ASM(const s32, "lib/libkernl/filestub", sceFormat);

INCLUDE_ASM(const s32, "lib/libkernl/filestub", sceAddDrv);

s32 sceDelDrv(const char* name) {
    return _sceCallCode(name, 16);
}

INCLUDE_ASM(const s32, "lib/libkernl/filestub", sceDopen);

INCLUDE_ASM(const s32, "lib/libkernl/filestub", sceDclose);

INCLUDE_ASM(const s32, "lib/libkernl/filestub", sceDread);

INCLUDE_ASM(const s32, "lib/libkernl/filestub", sceGetstat);

INCLUDE_ASM(const s32, "lib/libkernl/filestub", sceChstat);

INCLUDE_ASM(const s32, "lib/libkernl/filestub", sceRename);

/**
 * @brief Change current directory
 * @param name filepath name
 * @return 0 on success, -1 * error code on failure
 */
s32 sceChdir(const char* name) {
    return _sceCallCode(name, 18);
}

INCLUDE_ASM(const s32, "lib/libkernl/filestub", sceSync);

INCLUDE_ASM(const s32, "lib/libkernl/filestub", sceMount);

/**
 * @brief Unmount filesystem
 * @param name string specifying mounted filesystem device name and unit number
 * @return 0 on success, -1 * error code on failure
 */
s32 sceUmount(const char* name) {
    return _sceCallCode(name, 21);
}

INCLUDE_ASM(const s32, "lib/libkernl/filestub", sceLseek64);

INCLUDE_ASM(const s32, "lib/libkernl/filestub", sceDevctl);

INCLUDE_ASM(const s32, "lib/libkernl/filestub", sceSymlink);

INCLUDE_ASM(const s32, "lib/libkernl/filestub", sceReadlink);
