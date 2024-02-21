#include "common.h"
#include "eekernel.h"
#include <sifdev.h>
#include <sifrpc.h>
#include <sifcmd.h>
#include <stdarg.h>
#include <errno.h>
#include "lib/libkernl/filestub.h"

#define MAX_IOB_COUNT 32
#define UNCACHED(p) (((unsigned int)p | 0x20000000))

s32 _sceFs_q[32] = {
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
};
s32 _fs_init = 0;
s32 _fs_semid = -1;
s32 _fs_iob_semid = -1;
s32 _fs_fsq_semid = -1;

// BSS
unsigned int rcv_adr; // likely static
unsigned int ip0; // likely static
_sceFsData _send_data __attribute__((aligned (64)));
s32 _rcv_data_rpc __attribute__((aligned (64))); // unverified
_sceFsIntrData _rcv_data_cmd __attribute__((aligned (64)));
_sceFsIob _iob[32];
sceSifClientData _cd;
char _fsversion[4];
_sceFsPoffData _sif_FsRcv_Data __attribute__((aligned (64)));
_sceFsPoffData _sif_FsPoff_Data __attribute__((aligned (64)));

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

_sceFsIob *new_iob(void) {
    _sceFsIob *io;
    s32 i;
    
    _sceFsIobSemaMK();
    WaitSema(_fs_iob_semid);
    
    for (io = &_iob; io < &_iob[MAX_IOB_COUNT]; io++) {
        if (io->i_flag == 0){
            io->i_flag = 0x10000000;
            SignalSema(_fs_iob_semid);
            return io;
        }
    }
    
    SignalSema(_fs_iob_semid);
    return NULL;
}

_sceFsIob * get_iob(int fd) {
    _sceFsIob *ret;
    
    _sceFsIobSemaMK();
    WaitSema(_fs_iob_semid);
    
    if (ARRAY_COUNTU(_iob) <= fd) {
        SignalSema(_fs_iob_semid);
        return 0;
    }
    
    ret = &_iob[fd];
    SignalSema(_fs_iob_semid);
    return ret;
}

void _sceFs_Rcv_Intr(void); // TODO match this one
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

int* scePowerOffHandler(void (*func)(void *), void* addr) {
    int *ret;
    _sceFsPoffData *pd;

    pd = &_sif_FsPoff_Data;
    _sceFsWaitS(0x1b);
    if (_fs_init == 0x0) {
        sceFsInit();
    }
    DIntr();
    ret = _sif_FsPoff_Data.sceFsPoffCbfunc;
    pd->sceFsPoffCbdata = addr;
    pd->sceFsPoffCbfunc = func;
    EIntr();
    _sceFsSigSema();
    return ret;
}

void _sceFs_Poff_Intr(void *pkt, _sceFsPoffData *data) {
    if (data->sceFsPoffCbfunc != NULL) {
        data->sceFsPoffCbfunc(data->sceFsPoffCbdata);
    }
    ExitHandler();
}

int sceFsInit(void) {
    int i;
	int istat;
	int bufmode;
	_sceFsIob *io;
    _sceFsPoffData *pd;

    pd = &_sif_FsPoff_Data;
    sceSifInitRpc(0x0);
    pd->sceFsPoffCbfunc = NULL;
    pd->sceFsPoffCbdata = NULL;
    DIntr();
    sceSifAddCmdHandler(SIF_CMDI_SYSTEM | 0x11, &_sceFs_Rcv_Intr, &_sif_FsRcv_Data);
    sceSifAddCmdHandler(SIF_CMDI_SYSTEM | 0x13, &_sceFs_Poff_Intr, &_sif_FsPoff_Data);
    EIntr();

    while( 1 ) {
        istat = sceSifBindRpc(&_cd, 0x80000001, 0x0);
        if (istat < 0x0) {
            return -1;
        }
        
        if (_cd.serve != NULL){
            break;
        }

        for (i = 0x100000; i != -1; i--) {}
    }

    _sceFsIobSemaMK();
    WaitSema(_fs_iob_semid);
    
    for (io = &_iob; io < &_iob[MAX_IOB_COUNT]; io++) {
        io->i_flag = 0;
    }
    
    SignalSema(_fs_iob_semid);
    rcv_adr = &_rcv_data_cmd;
    istat = sceSifCallRpc(&_cd, 0xff, 0x0, &rcv_adr, 0x4, &_rcv_data_rpc, 0x4, NULL, NULL);
    if (istat < 0x0) {
        return -SCE_ECALLMISS;
    }
    else {
        memcpy(&_fsversion, UNCACHED(&_rcv_data_rpc), 4);
        _fs_init = 0x1;
        return 0; // SCE_OK doesn't seem to exist in this SDK version
    }
}

char* _fswildcard = "....";

// TODO these two vars aren't from this file
s32 D_00465374 = -1;
char* D_00465378 = "....\0";

// extern char __ps2_klibinfo_[16];
extern char* D_00464B18; // TODO use the proper symbol for this


s32 _fs_version(void) {
    s32 ret = FALSE;
    char *libver;

    libver = &D_00464B18; // TODO use the proper symbol for this
    // libver = &__ps2_klibinfo_[12];

    if (memcmp(&_fsversion, libver, 4) != 0 && memcmp(&_fsversion, _fswildcard, 4) != 0) {
        ret = memcmp(libver, _fswildcard, 4) != 0;
    }
    return ret;
}

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

int sceOpen(const char *filename, int flag, ...) {
    unsigned int mode;
    int nsize;
    int ret;
    int retfd;
    _sceFsOpenData *od;
    _sceFsIob *io;
    struct SemaParam sparam;
    int i;
    va_list arg;
    int semaId;


    od = &_send_data.openData;
    
    _sceFsWaitS(0x0);
    if (_fs_init == 0x0) {
        sceFsInit();
    }

    
    if (_fs_version() != 0x0) {
        _sceFsSigSema();
        return -SCE_EVERSIONMISS;
    } 
        
    io = new_iob();
    if (io == NULL) {
        _sceFsSigSema();
        return -ENODEV;
    }

    va_start (arg, flag);
    mode = va_arg (arg, int);
    va_end (arg);
    
    for (i = 0; i < 0x400 && (od->name[i] = filename[i]) != 0; i++) { }
    
    if (i == 0x400) {
        od->name[0x400-1] = 0x0;
    }
    

    nsize = (int)((u32)io - (u32)&_iob) >> 0x4;
    od->flag = flag & ~0x90000000;
    od->ee_fds = nsize;
    od->mode = mode;
    sparam.maxCount = 0x1;
    sparam.initCount = 0x0;
    sparam.option = 0x0;
    semaId = CreateSema(&sparam);
    od->ee_semid = semaId;
    od->ee_retadr = &retfd;
    od->ee_retsiz = sizeof(retfd);

    ret = sceSifCallRpc(&_cd, 0x0, 0x0, &_send_data, sizeof(_sceFsOpenData), &_rcv_data_rpc, sizeof(_rcv_data_rpc), 0x0, 0x0);
    if (ret < 0x0) {
        DeleteSema(semaId);
        _sceFsSigSema();
        return -EAGAIN;
    }
    
    ret = *(u32*)UNCACHED(&_rcv_data_rpc);
    _sceFsSigSema();
    if (ret == 0x0) {
        DeleteSema(semaId);
        return -EAGAIN;
    }
        
    WaitSema(semaId);
    DeleteSema(semaId);
    if (retfd < 0x0) {
        WaitSema(_fs_iob_semid);
        io->i_flag = 0x0;
        SignalSema(_fs_iob_semid);
        return retfd;
    }
    
    ret = nsize;
    WaitSema(_fs_iob_semid);
    io->i_fd = retfd;
    io->i_flag |= flag;
    SignalSema(_fs_iob_semid);

    return ret;
}

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
