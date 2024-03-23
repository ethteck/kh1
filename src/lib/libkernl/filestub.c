#include "common.h"
#include "eekernel.h"
#include <sifdev.h>
#include <sifrpc.h>
#include <sifcmd.h>
#include <stdarg.h>
#include <errno.h>
#include "lib/libkernl/filestub.h"

#define MAX_IOB_COUNT 32
#define MAX_ARG_SIZE 1024
#define UNCACHED(p) (((u32)p | 0x20000000))

s32 _sceFs_q[MAX_IOB_COUNT] = {
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
};
s32 _fs_init = 0;
s32 _fs_semid = -1;
s32 _fs_iob_semid = -1;
s32 _fs_fsq_semid = -1;

// BSS
u32 rcv_adr; // likely static
u32 ip0; // likely static
_sceFsData _send_data __attribute__((aligned (64)));
s32 _rcv_data_rpc __attribute__((aligned (64))); // unverified
_sceFsIntrData _rcv_data_cmd __attribute__((aligned (64)));
_sceFsIob _iob[MAX_IOB_COUNT];
sceSifClientData _cd;
char _fsversion[4];
_sceFsPoffData _sif_FsRcv_Data __attribute__((aligned (64)));
_sceFsPoffData _sif_FsPoff_Data __attribute__((aligned (64)));

static void _sceFsIobSemaMK(void) {
    struct SemaParam param;

    if (_fs_iob_semid == -1) {
        param.option = 0;
        param.initCount = 1;
        param.maxCount = 1;

        _fs_iob_semid = CreateSema(&param);
        _fs_fsq_semid = CreateSema(&param);
    }
}

static _sceFsIob* new_iob(void) {
    _sceFsIob* io;
    s32 i;
    
    _sceFsIobSemaMK();
    WaitSema(_fs_iob_semid);
    
    for (io = &_iob[0]; io < &_iob[MAX_IOB_COUNT]; io++) {
        if (io->i_flag == 0){
            io->i_flag = 0x10000000;
            SignalSema(_fs_iob_semid);
            return io;
        }
    }
    
    SignalSema(_fs_iob_semid);
    return NULL;
}

static _sceFsIob* get_iob(s32 fd) {
    _sceFsIob* ret;
    
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

static void _sceFs_Rcv_Intr(void*, void*); // TODO match this one
INCLUDE_ASM(const s32, "lib/libkernl/filestub", _sceFs_Rcv_Intr);

static void _sceFsSemInit(void) {
    struct SemaParam param;
    if (_fs_semid == -1) {
        param.option = 0;
        param.initCount = 1;
        param.maxCount = 1;
        _fs_semid = CreateSema(&param);
    }
}

static s32 _sceFsWaitS(s32 unused) {
    _sceFsSemInit();
    WaitSema(_fs_semid);
    return 0;
}

static void _sceFsSigSema(void) {
    SignalSema(_fs_semid);
}

int* scePowerOffHandler(void (*func)(void*), void* addr) {
    int* ret;
    _sceFsPoffData* pd;

    pd = &_sif_FsPoff_Data;
    _sceFsWaitS(0x1b);
    if (_fs_init == 0x0) {
        sceFsInit();
    }
    DIntr();
    ret = (int*)_sif_FsPoff_Data.sceFsPoffCbfunc;
    pd->sceFsPoffCbdata = addr;
    pd->sceFsPoffCbfunc = func;
    EIntr();
    _sceFsSigSema();
    return ret;
}

static void _sceFs_Poff_Intr(void* pkt, void* data) {
    _sceFsPoffData* p;
    p = (_sceFsPoffData*)data;
    if (p->sceFsPoffCbfunc != NULL) {
        p->sceFsPoffCbfunc(p->sceFsPoffCbdata);
    }
    ExitHandler();
}

int sceFsInit(void) {
    s32 i;
    s32 istat;
    s32 bufmode;
    _sceFsIob* io;
    _sceFsPoffData* pd;

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
    
    for (io = &_iob[0]; io < &_iob[MAX_IOB_COUNT]; io++) {
        io->i_flag = 0;
    }
    
    SignalSema(_fs_iob_semid);
    rcv_adr = (u32)&_rcv_data_cmd;
    istat = sceSifCallRpc(&_cd, 0xff, 0x0, &rcv_adr, sizeof(rcv_adr), &_rcv_data_rpc, sizeof(_rcv_data_rpc), NULL, NULL);
    if (istat < 0x0) {
        return -SCE_ECALLMISS;
    }
    else {
        memcpy(&_fsversion, (void*)UNCACHED(&_rcv_data_rpc), sizeof(_fsversion));
        _fs_init = 0x1;
        return 0; // SCE_OK doesn't seem to exist in this SDK version
    }
}

char* _fswildcard = "....";

// TODO these two vars aren't from this file
s32 D_00465374 = -1;
char* D_00465378 = "....\0";

// extern char __ps2_klibinfo_[16];
extern char D_00464B18; // TODO use the proper symbol for this


static s32 _fs_version(void) {
    s32 ret = FALSE;
    char* libver;

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
s32 sceFsReset(void) {
    _fs_init = 0;
    memset(_fsversion, 0, sizeof(_fsversion));
    return 0;
}

int sceOpen(const char* filename, int flag, ...) {
    u32 mode;
    s32 nsize;
    s32 ret;
    s32 retfd;
    _sceFsOpenData* od;
    _sceFsIob* io;
    struct SemaParam sparam;
    s32 i;
    va_list arg;
    s32 semaId;

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
    
    for (i = 0; i < MAX_ARG_SIZE && (od->name[i] = filename[i]) != 0; i++) { }
    if (i == MAX_ARG_SIZE) {
        od->name[MAX_ARG_SIZE-1] = 0x0;
    }

    nsize = io - _iob;
    od->flag = flag & ~0x90000000;
    od->ee_fds = nsize;
    od->mode = mode;
    sparam.maxCount = 0x1;
    sparam.initCount = 0x0;
    sparam.option = 0x0;
    semaId = CreateSema(&sparam);
    od->ee_semid = semaId;
    od->ee_retadr = (u32)&retfd;
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

int sceClose(int fd) {
    _sceFsCloseData* cd;
    _sceFsIob* io;
    s32 ret;
    s32 nsize;
    s32 ret_close;
    struct SemaParam sparam;
    s32 semaid;

    cd = &_send_data.closeData;
    
    io = get_iob(fd);
    _sceFsWaitS(0x1);
    if (_fs_init == 0x0) {
        _sceFsSigSema();
        return -0x1; // errno.h says this would be "Not super-user" but that doesn't make sense
    }
    
    if ((io == NULL) || (io->i_flag == 0x0)) {
        _sceFsSigSema();
        return -EBADF;
    }
    
    nsize = io - _iob;
    cd->fd = io->i_fd;
    cd->ee_fds = nsize;
    sparam.maxCount = 0x1;
    sparam.initCount = 0x0;
    sparam.option = 0x0;
    semaid = CreateSema(&sparam);
    cd->ee_semid = semaid;
    cd->ee_retadr = (u32)&ret_close;
    cd->ee_retsiz = sizeof(ret_close);
    ret = sceSifCallRpc(&_cd, 0x1, 0x0, &_send_data, sizeof(_sceFsCloseData), &_rcv_data_rpc, sizeof(_rcv_data_rpc), NULL, NULL);
    if (ret < 0x0) {
        DeleteSema(semaid);
        _sceFsSigSema();
        return -EAGAIN;
    }
   
    io->i_flag = 0x0;
    ret = *(u32*)UNCACHED(&_rcv_data_rpc);
    _sceFsSigSema();
    if (ret == 0x0) {
        DeleteSema(semaid);
        return -EAGAIN;
    }
        
    WaitSema(semaid);
    DeleteSema(semaid);
    if (ret_close < 0) {
        return ret_close;
    }
    
    return 0; // SCE_OK
}

INCLUDE_ASM(const s32, "lib/libkernl/filestub", sceLseek);

INCLUDE_ASM(const s32, "lib/libkernl/filestub", sceRead);

INCLUDE_ASM(const s32, "lib/libkernl/filestub", sceWrite);

INCLUDE_ASM(const s32, "lib/libkernl/filestub", sceIoctl);

int sceIoctl2(int fd, int cmd, const void* arg, unsigned int arglen, void* bufp,  unsigned int buflen) {
    _sceFsIoctlData* id;
    _sceFsIob* io;
    s32 ret;
    s32 ret_ioctl;
    struct SemaParam sparam;
    s32 semaid;
    
    id = &_send_data.ioctlData;

    io = get_iob(fd);
    _sceFsWaitS(0x1A);
    if (_fs_init == 0x0) {
        sceFsInit();
    }

    if ((io == NULL) || (io->i_flag == 0x0)) {
        _sceFsSigSema();
        return -EBADF;
    }
    
    if ((arglen > MAX_ARG_SIZE) || (buflen > MAX_ARG_SIZE)) {
        _sceFsSigSema();
        return -EINVAL;
    }
    
    if (arg == NULL) {
        id->arglen = 0;
    } else {
        memcpy(&id->arg, arg, arglen);
    }
    
    id->fd = io->i_fd;
    id->cmd = cmd;
    id->arglen = arglen;
    sparam.maxCount = 0x1;
    sparam.initCount = 0x0;
    sparam.option = 0x0;
    semaid = CreateSema(&sparam);
    id->ee_semid = semaid;
    id->ee_retadr = (u32)&ret_ioctl;
    id->ee_retsiz = sizeof(ret_ioctl);
    id->ret_argadr = bufp;
    id->ret_argsiz = buflen;
    
    sceSifWriteBackDCache(&_send_data, sizeof(_sceFsIoctlData));
    ret = sceSifCallRpc(&_cd, 0x1a, 0x0, &_send_data, sizeof(_sceFsIoctlData), &_rcv_data_rpc, sizeof(_rcv_data_rpc), NULL, NULL);
    
    if (ret < 0x0) {
        DeleteSema(semaid);
        _sceFsSigSema();
        return -EAGAIN;
    }
   
    ret = *(u32*)UNCACHED(&_rcv_data_rpc);
    _sceFsSigSema();
    if (ret == 0x0) {
        DeleteSema(semaid);
        return -EAGAIN;
    }
    
    WaitSema(semaid);
    DeleteSema(semaid);
    return ret_ioctl;
}

static s32 _sceCallCode(const char* name, u32 callcode) {
    _sceFsNameData* cc;
    s32 nsize;
    s32 ret;
    s32 ret_code;
    struct SemaParam sparam;
    s32 semaid;

    cc = &_send_data.nameData;
    
    _sceFsWaitS(callcode);
    if (_fs_init == 0x0) {
        sceFsInit();
    }
    
    for (nsize = 0; nsize < MAX_ARG_SIZE && (cc->name[nsize] = name[nsize]) != 0; nsize++) { }
    if (nsize == MAX_ARG_SIZE) {
        cc->name[MAX_ARG_SIZE-1] = 0x0;
        nsize = MAX_ARG_SIZE-1;
    }
    
    sparam.maxCount = 0x1;
    sparam.initCount = 0x0;
    sparam.option = 0x0;
    semaid = CreateSema(&sparam);
    cc->ee_semid = semaid;
    cc->ee_retadr = (u32)&ret_code;
    cc->ee_retsiz = sizeof(ret_code);
    
    ret = sceSifCallRpc(&_cd, callcode, 0x0, &_send_data, nsize + 0xC + 1, &_rcv_data_rpc, sizeof(_rcv_data_rpc), NULL, NULL);
    
    if (ret < 0x0) {
        DeleteSema(semaid);
        _sceFsSigSema();
        return -EAGAIN;
    }
   
    ret = *(u32*)UNCACHED(&_rcv_data_rpc);
    _sceFsSigSema();
    if (ret == 0x0) {
        DeleteSema(semaid);
        return -EAGAIN;
    }
    
    WaitSema(semaid);
    DeleteSema(semaid);
    return ret_code;
}

/**
 * @brief Delete file
 * @param filename File pathname (includes device name and ':')
 * @return 0 on success, -1 * error code on failure 
 */
s32 sceRemove(const char* filename) {
    return _sceCallCode(filename, 6);
}

int sceMkdir(const char* name, int flag) {
    _sceFsMkdirData* mkd;
    s32 nsize;
    s32 ret;
    s32 ret_mkdir;
    struct SemaParam sparam;
    s32 semaid;

    mkd = &_send_data.mkdirData;
    
    _sceFsWaitS(0x7);
    if (_fs_init == 0x0) {
        sceFsInit();
    }

    for (nsize = 0; nsize < MAX_ARG_SIZE && (mkd->name[nsize] = name[nsize]) != 0; nsize++) { }
    if (nsize == MAX_ARG_SIZE) {
        mkd->name[MAX_ARG_SIZE-1] = 0x0;
        nsize = MAX_ARG_SIZE-1;
    }
    
    mkd->flag = flag;
    sparam.maxCount = 0x1;
    sparam.initCount = 0x0;
    sparam.option = 0x0;
    semaid = CreateSema(&sparam);
    mkd->ee_semid = semaid;
    mkd->ee_retadr = (u32)&ret_mkdir;
    mkd->ee_retsiz = sizeof(ret_mkdir);
    
    ret = sceSifCallRpc(&_cd, 0x7, 0x0, &_send_data, nsize + 0x10 + 1, &_rcv_data_rpc, sizeof(_rcv_data_rpc), NULL, NULL);
    if (ret < 0x0) {
        DeleteSema(semaid);
        _sceFsSigSema();
        return -EAGAIN;
    }
   
    ret = *(u32*)UNCACHED(&_rcv_data_rpc);
    _sceFsSigSema();
    if (ret == 0x0) {
        DeleteSema(semaid);
        return -EAGAIN;
    }
    
    WaitSema(semaid);
    DeleteSema(semaid);
    return ret_mkdir;
}

/**
 * @brief Delete directory
 * @param dirname Directory pathname (includes device name and ':')
 * @return 0 on success, -1 * error code on failure
 */
s32 sceRmdir(const char* dirname) {
    return _sceCallCode(dirname, 8);
}

int sceFormat(const char* path, const char* blkdevname, void* arg, int arglen) {
    _sceFsFormatData* fd;
    s32 nsize;
    s32 ret;
    s32 ret_format;
    struct SemaParam sparam;
    s32 semaid;

    fd = &_send_data.formatData;
    
    _sceFsWaitS(0xE);
    if (_fs_init == 0x0) {
        sceFsInit();
    }

    for (nsize = 0; nsize < MAX_ARG_SIZE && (fd->path[nsize] = path[nsize]) != 0; nsize++) { }
    if (nsize == MAX_ARG_SIZE) {
        fd->path[MAX_ARG_SIZE-1] = 0x0;
    }

    if (blkdevname == NULL) {
        fd->blkdevname[0] = 0x0;
    } else {   
        for (nsize = 0; nsize < MAX_ARG_SIZE && (fd->blkdevname[nsize] = blkdevname[nsize]) != 0; nsize++) { }
        if (nsize == MAX_ARG_SIZE) {
            fd->blkdevname[MAX_ARG_SIZE-1] = 0x0;
        }
    }

    if (arglen > MAX_ARG_SIZE) {
        _sceFsSigSema();
        return -E2BIG;
    }

    for (nsize = 0; nsize < arglen; nsize++) {
        fd->arg[nsize] = ((char*)arg)[nsize];
    }

    fd->arglen = arglen;
    sparam.maxCount = 0x1;
    sparam.initCount = 0x0;
    sparam.option = 0x0;
    semaid = CreateSema(&sparam);
    fd->ee_semid = semaid;
    fd->ee_retadr = (u32)&ret_format;
    fd->ee_retsiz = sizeof(ret_format);

    sceSifWriteBackDCache(&_send_data, sizeof(_sceFsFormatData));
    ret = sceSifCallRpc(&_cd, 0xE, 0x0, &_send_data, sizeof(_sceFsFormatData), &_rcv_data_rpc, sizeof(_rcv_data_rpc), NULL, NULL);
    if (ret < 0x0) {
        DeleteSema(semaid);
        _sceFsSigSema();
        return -EAGAIN;
    }
   
    ret = *(u32*)UNCACHED(&_rcv_data_rpc);
    _sceFsSigSema();
    if (ret == 0x0) {
        DeleteSema(semaid);
        return -EAGAIN;
    }
    
    WaitSema(semaid);
    DeleteSema(semaid);
    return ret_format;
}

int sceAddDrv(void* addr) {
    _sceFsAddrData* id;
    s32 nsize;
    s32 ret;
    s32 ret_adddrv;
    struct SemaParam sparam;
    s32 semaid;

    id = &_send_data.addrData;
    
    _sceFsWaitS(0xF);
    if (_fs_init == 0x0) {
        sceFsInit();
    }

    id->addr = addr;
    sparam.maxCount = 0x1;
    sparam.initCount = 0x0;
    sparam.option = 0x0;
    semaid = CreateSema(&sparam);
    id->ee_semid = semaid;
    id->ee_retadr = (u32)&ret_adddrv;
    id->ee_retsiz = sizeof(ret_adddrv);

    ret = sceSifCallRpc(&_cd, 0xF, 0x0, &_send_data, sizeof(_sceFsAddrData), &_rcv_data_rpc, sizeof(_rcv_data_rpc), NULL, NULL);
    if (ret < 0x0) {
        DeleteSema(semaid);
        _sceFsSigSema();
        return -1;
    }
   
    ret = *(u32*)UNCACHED(&_rcv_data_rpc);
    _sceFsSigSema();
    if (ret == 0x0) {
        DeleteSema(semaid);
        return -1;
    }
    
    WaitSema(semaid);
    DeleteSema(semaid);
    return ret_adddrv;
}

s32 sceDelDrv(const char* name) {
    return _sceCallCode(name, 16);
}

int sceDopen(const char* name) {
    _sceFsIob* io;
    s32 ret;
    
    _sceFsWaitS(0x9);
    if (_fs_init == 0x0) {
        sceFsInit();
    }
    
    _sceFsSigSema();
    io = new_iob();
    if (io == NULL) {
        return -ENODEV;
    }
    
    ret = _sceCallCode(name, 0x9);
    if (ret < 0x0) {
        WaitSema(_fs_iob_semid);
        io->i_flag = 0x0;
        SignalSema(_fs_iob_semid);
        return ret;
    }
        
    WaitSema(_fs_iob_semid);
    io->i_fd = ret;
    ret = io - _iob;
    SignalSema(_fs_iob_semid);
    
    return ret;
}

int sceDclose(int fd) {
    _sceFsCloseData* cd;
    _sceFsIob* io;
    s32 ret;
    s32 ret_dclose;
    struct SemaParam sparam;
    s32 semaid;
    s32 temp;

    io = get_iob(fd);
    cd = &_send_data.closeData;
    
    _sceFsWaitS(0xA);
    if (_fs_init == 0x0) {
        _sceFsSigSema();
        return -1;
    }

    if ((io == NULL) || (io->i_flag == 0x0)) {
        _sceFsSigSema();
        return -EBADF;
    }

    cd->fd = io->i_fd;
    sparam.maxCount = 0x1;
    sparam.initCount = 0x0;
    sparam.option = 0x0;
    semaid = CreateSema(&sparam);
    cd->ee_semid = semaid;
    cd->ee_retadr = (u32)&ret_dclose;
    cd->ee_retsiz = sizeof(ret_dclose);

    ret = sceSifCallRpc(&_cd, 0xA, 0x0, &_send_data, sizeof(_sceFsCloseData), &_rcv_data_rpc, sizeof(_rcv_data_rpc), NULL, NULL);
    if (ret < 0x0) {
        DeleteSema(semaid);
        _sceFsSigSema();
        return -EAGAIN;
    }
   
    io->i_flag = 0;
    ret = *(u32*)UNCACHED(&_rcv_data_rpc);
    _sceFsSigSema();
    if (ret == 0x0) {
        DeleteSema(semaid);
        return -EAGAIN;
    }

    WaitSema(semaid);
    DeleteSema(semaid);
    temp = -1;
    if (temp < ret_dclose) {
        return 0;
    }
    return ret_dclose;
}

int sceDread(int fd, struct sce_dirent* dp) {
    _sceFsReadData* rd;
    _sceFsIob* io;
    s32 ret;
    s32 ret_dread;
    struct SemaParam sparam;
    s32 semaid;

    io = get_iob(fd);
    rd = &_send_data.readData;
    
    _sceFsWaitS(0xB);
    if (_fs_init == 0x0) {
        _sceFsSigSema();
        return -1;
    }

    if ((io == NULL) || (io->i_flag == 0x0)) {
        _sceFsSigSema();
        return -EBADF;
    }

    rd->fd = io->i_fd;
    rd->addr = (u32)dp;
    sparam.maxCount = 0x1;
    sparam.initCount = 0x0;
    sparam.option = 0x0;
    semaid = CreateSema(&sparam);
    rd->ee_semid = semaid;
    rd->ee_retadr = (u32)&ret_dread;
    rd->ee_retsiz = sizeof(ret_dread);

    ret = sceSifCallRpc(&_cd, 0xB, 0x0, &_send_data, sizeof(_sceFsReadData), &_rcv_data_rpc, sizeof(_rcv_data_rpc), NULL, NULL);
    if (ret < 0x0) {
        WaitSema(semaid);
        _sceFsSigSema();
        return -EAGAIN;
    }
   
    ret = *(u32*)UNCACHED(&_rcv_data_rpc);
    _sceFsSigSema();
    if (ret == 0x0) {
        DeleteSema(semaid);
        return -EAGAIN;
    }

    WaitSema(semaid);
    DeleteSema(semaid);
    return ret_dread;
}

int sceGetstat(const char* name, struct sce_stat* dp) {
    _sceFsGStatData* sd;
    s32 ret;
    s32 nsize;
    s32 ret_getstat;
    struct SemaParam sparam;
    s32 semaid;

    sd = &_send_data.gStatData;
    
    _sceFsWaitS(0xC);
    if (_fs_init == 0x0) {
        sceFsInit();
    }

    for (nsize = 0; nsize < MAX_ARG_SIZE && (sd->name[nsize] = name[nsize]) != 0; nsize++) { }
    if (nsize == MAX_ARG_SIZE) {
        sd->name[MAX_ARG_SIZE-1] = 0x0;
        nsize = MAX_ARG_SIZE-1;
    }

    sd->addr = dp;
    sparam.maxCount = 0x1;
    sparam.initCount = 0x0;
    sparam.option = 0x0;
    semaid = CreateSema(&sparam);
    sd->ee_semid = semaid;
    sd->ee_retadr = (u32)&ret_getstat;
    sd->ee_retsiz = sizeof(ret_getstat);

    ret = sceSifCallRpc(&_cd, 0xC, 0x0, &_send_data, nsize + 0x10 + 1, &_rcv_data_rpc, sizeof(_rcv_data_rpc), NULL, NULL);
    if (ret < 0x0) {
        DeleteSema(semaid);
        _sceFsSigSema();
        return -EAGAIN;
    }
   
    ret = *(u32*)UNCACHED(&_rcv_data_rpc);
    _sceFsSigSema();
    if (ret == 0x0) {
        DeleteSema(semaid);
        return -EAGAIN;
    }

    WaitSema(semaid);
    DeleteSema(semaid);
    return ret_getstat;
}

int sceChstat(const char* name, struct sce_stat* buf, unsigned int cbit) {
    _sceFsCStatData* cd;
    s32 ret;
    s32 nsize;
    s32 ret_chstat;
    struct SemaParam sparam;
    s32 semaid;

    cd = &_send_data.cStatData;
    
    _sceFsWaitS(0xD);
    if (_fs_init == 0x0) {
        sceFsInit();
    }

    for (nsize = 0; nsize < MAX_ARG_SIZE && (cd->name[nsize] = name[nsize]) != 0; nsize++) { }
    if (nsize == MAX_ARG_SIZE) {
        cd->name[MAX_ARG_SIZE-1] = 0x0;
        nsize = MAX_ARG_SIZE-1;
    }

    cd->stat = *buf;
    cd->cbit = cbit;
    sparam.maxCount = 0x1;
    sparam.initCount = 0x0;
    sparam.option = 0x0;
    semaid = CreateSema(&sparam);
    cd->ee_semid = semaid;
    cd->ee_retadr = (u32)&ret_chstat;
    cd->ee_retsiz = sizeof(ret_chstat);
    
    sceSifWriteBackDCache(&_send_data, sizeof(_sceFsCStatData));
    ret = sceSifCallRpc(&_cd, 0xD, 0x0, &_send_data, nsize + 0x50 + 1, &_rcv_data_rpc, sizeof(_rcv_data_rpc), NULL, NULL);
    if (ret < 0x0) {
        DeleteSema(semaid);
        _sceFsSigSema();
        return -EAGAIN;
    }
   
    ret = *(u32*)UNCACHED(&_rcv_data_rpc);
    _sceFsSigSema();
    if (ret == 0x0) {
        DeleteSema(semaid);
        return -EAGAIN;
    }

    WaitSema(semaid);
    DeleteSema(semaid);
    return ret_chstat;
}

int sceRename(const char* oldname, const char* newname) {
    _sceFsRenameData* rd;
    s32 ret;
    s32 nsize;
    s32 ret_chstat;
    struct SemaParam sparam;
    s32 semaid;

    rd = &_send_data.renameData;
    
    _sceFsWaitS(0x11);
    if (_fs_init == 0x0) {
        sceFsInit();
    }

    for (nsize = 0; nsize < MAX_ARG_SIZE && (rd->oldpath[nsize] = oldname[nsize]) != 0; nsize++) { }
    if (nsize == MAX_ARG_SIZE) {
        rd->oldpath[MAX_ARG_SIZE-1] = 0x0;
    }
    
    for (nsize = 0; nsize < MAX_ARG_SIZE && (rd->newpath[nsize] = newname[nsize]) != 0; nsize++) { }
    if (nsize == MAX_ARG_SIZE) {
        rd->newpath[MAX_ARG_SIZE-1] = 0x0;
    }

    sparam.maxCount = 0x1;
    sparam.initCount = 0x0;
    sparam.option = 0x0;
    semaid = CreateSema(&sparam);
    rd->ee_semid = semaid;
    rd->ee_retadr = (u32)&ret_chstat;
    rd->ee_retsiz = sizeof(ret_chstat);
    
    sceSifWriteBackDCache(&_send_data, sizeof(_sceFsRenameData));
    ret = sceSifCallRpc(&_cd, 0x11, 0x0, &_send_data, sizeof(_sceFsRenameData), &_rcv_data_rpc, sizeof(_rcv_data_rpc), NULL, NULL);
    if (ret < 0x0) {
        DeleteSema(semaid);
        _sceFsSigSema();
        return -EAGAIN;
    }
   
    ret = *(u32*)UNCACHED(&_rcv_data_rpc);
    _sceFsSigSema();
    if (ret == 0x0) {
        DeleteSema(semaid);
        return -EAGAIN;
    }

    WaitSema(semaid);
    DeleteSema(semaid);
    return ret_chstat;
}

/**
 * @brief Change current directory
 * @param name filepath name
 * @return 0 on success, -1 * error code on failure
 */
s32 sceChdir(const char* name) {
    return _sceCallCode(name, 18);
}

int sceSync(const char* path, int flag) {
    _sceFsSyncData* sd;
    s32 nsize;
    s32 ret;
    s32 ret_sync;
    struct SemaParam sparam;
    s32 i;
    s32 semaid;

    sd = &_send_data.syncData;
    
    _sceFsWaitS(0x13);
    if (_fs_init == 0x0) {
        sceFsInit();
    }
    
    for (i = 0; i < MAX_ARG_SIZE && (sd->path[i] = path[i]) != 0; i++) { }
    if (i == MAX_ARG_SIZE) {
        sd->path[MAX_ARG_SIZE-1] = 0x0;
    }
    
    sd->flag = flag;
    sparam.maxCount = 0x1;
    sparam.initCount = 0x0;
    sparam.option = 0x0;
    semaid = CreateSema(&sparam);
    sd->ee_semid = semaid;
    sd->ee_retadr = (u32)&ret_sync;
    sd->ee_retsiz = sizeof(ret_sync);
    
    ret = sceSifCallRpc(&_cd, 0x13, 0x0, &_send_data, sizeof(_sceFsSyncData), &_rcv_data_rpc, sizeof(_rcv_data_rpc), NULL, NULL);
    
    if (ret < 0x0) {
        DeleteSema(semaid);
        _sceFsSigSema();
        return -EAGAIN;
    }
   
    ret = *(u32*)UNCACHED(&_rcv_data_rpc);
    _sceFsSigSema();
    if (ret == 0x0) {
        DeleteSema(semaid);
        return -EAGAIN;
    }
    
    WaitSema(semaid);
    DeleteSema(semaid);
    return ret_sync;
}

int sceMount(const char* fsdevname, const char* blkdevname, int flag, void* arg, int arglen) {
    _sceFsMountData* md;
    s32 nsize;
    s32 ret;
    s32 ret_sync;
    struct SemaParam sparam;
    s32 semaid;

    md = &_send_data.mountData;
    
    _sceFsWaitS(0x14);
    if (_fs_init == 0x0) {
        sceFsInit();
    }
    
    for (nsize = 0; nsize < MAX_ARG_SIZE && (md->fsdevname[nsize] = fsdevname[nsize]) != 0; nsize++) { }
    if (nsize == MAX_ARG_SIZE) {
        md->fsdevname[MAX_ARG_SIZE-1] = 0x0;
    }
    for (nsize = 0; nsize < MAX_ARG_SIZE && (md->blkdevname[nsize] = blkdevname[nsize]) != 0; nsize++) { }
    if (nsize == MAX_ARG_SIZE) {
        md->blkdevname[MAX_ARG_SIZE-1] = 0x0;
    }

    if (arglen > MAX_ARG_SIZE) {
        _sceFsSigSema();
        return -E2BIG;
    }

    for (nsize = 0; nsize < arglen; nsize++) {
        md->arg[nsize] = ((char*)arg)[nsize];
    }
    
    md->flag = flag;
    md->arglen = arglen;
    sparam.maxCount = 0x1;
    sparam.initCount = 0x0;
    sparam.option = 0x0;
    semaid = CreateSema(&sparam);
    md->ee_semid = semaid;
    md->ee_retadr = (u32)&ret_sync;
    md->ee_retsiz = sizeof(ret_sync);
    
    sceSifWriteBackDCache(&_send_data, sizeof(_sceFsMountData));
    ret = sceSifCallRpc(&_cd, 0x14, 0x0, &_send_data, sizeof(_sceFsMountData), &_rcv_data_rpc, sizeof(_rcv_data_rpc), NULL, NULL);
    
    if (ret < 0x0) {
        DeleteSema(semaid);
        _sceFsSigSema();
        return -EAGAIN;
    }
   
    ret = *(u32*)UNCACHED(&_rcv_data_rpc);
    _sceFsSigSema();
    if (ret == 0x0) {
        DeleteSema(semaid);
        return -EAGAIN;
    }
    
    WaitSema(semaid);
    DeleteSema(semaid);
    return ret_sync;
}

/**
 * @brief Unmount filesystem
 * @param name string specifying mounted filesystem device name and unit number
 * @return 0 on success, -1 * error code on failure
 */
s32 sceUmount(const char* name) {
    return _sceCallCode(name, 21);
}

INCLUDE_ASM(const s32, "lib/libkernl/filestub", sceLseek64);

int sceDevctl(const char* devname, int cmd, const void* arg, unsigned int arglen, void* bufp, unsigned int buflen) {
    _sceFsDevctlData* dd;
    s32 nsize;
    s32 ret;
    s32 ret_devctl;
    struct SemaParam sparam;
    s32 semaid;

    dd = &_send_data.devctlData;
    
    _sceFsWaitS(0x17);
    if (_fs_init == 0x0) {
        sceFsInit();
    }

    for (nsize = 0; nsize < MAX_ARG_SIZE && (dd->path[nsize] = devname[nsize]) != 0; nsize++) { }
    if (nsize == MAX_ARG_SIZE) {
        dd->path[MAX_ARG_SIZE-1] = 0x0;
    }

    if ((arglen > MAX_ARG_SIZE) || (buflen > MAX_ARG_SIZE)) {
        _sceFsSigSema();
        return -EINVAL;
    }

    for (nsize = 0; nsize < arglen; nsize++) {
        dd->arg_buf[nsize] = ((char*)arg)[nsize];
    }
    
    dd->cmd = cmd;
    dd->arglen = arglen;
    sparam.maxCount = 0x1;
    sparam.initCount = 0x0;
    sparam.option = 0x0;
    semaid = CreateSema(&sparam);
    dd->ee_semid = semaid;
    dd->ee_retadr = (u32)&ret_devctl;
    dd->ee_retsiz = sizeof(ret_devctl);
    dd->ret_argadr = bufp;
    dd->ret_arglen = buflen;
    
    sceSifWriteBackDCache(&_send_data, sizeof(_sceFsDevctlData));
    ret = sceSifCallRpc(&_cd, 0x17, 0x0, &_send_data, sizeof(_sceFsDevctlData), &_rcv_data_rpc, sizeof(_rcv_data_rpc), NULL, NULL);
    
    if (ret < 0x0) {
        DeleteSema(semaid);
        _sceFsSigSema();
        return -EAGAIN;
    }
   
    ret = *(u32*)UNCACHED(&_rcv_data_rpc);
    _sceFsSigSema();
    if (ret == 0x0) {
        DeleteSema(semaid);
        return -EAGAIN;
    }
    
    WaitSema(semaid);
    DeleteSema(semaid);
    return ret_devctl;
}

int sceSymlink(const char* existing, const char* new) {
    _sceFsSymlinkData* rd;
    s32 nsize;
    s32 ret;
    s32 ret_link;
    struct SemaParam sparam;
    s32 semaid;

    rd = &_send_data.symlinkData;
    
    _sceFsWaitS(0x11);
    if (_fs_init == 0x0) {
        sceFsInit();
    }

    for (nsize = 0; nsize < MAX_ARG_SIZE && (rd->existing[nsize] = existing[nsize]) != 0; nsize++) { }
    if (nsize == MAX_ARG_SIZE) {
        rd->existing[MAX_ARG_SIZE-1] = 0x0;
    }
    
    for (nsize = 0; nsize < MAX_ARG_SIZE && (rd->new[nsize] = new[nsize]) != 0; nsize++) { }
    if (nsize == MAX_ARG_SIZE) {
        rd->new[MAX_ARG_SIZE-1] = 0x0;
    }

    sparam.maxCount = 0x1;
    sparam.initCount = 0x0;
    sparam.option = 0x0;
    semaid = CreateSema(&sparam);
    rd->ee_semid = semaid;
    rd->ee_retadr = (u32)&ret_link;
    rd->ee_retsiz = sizeof(ret_link);
    
    ret = sceSifCallRpc(&_cd, 0x18, 0x0, &_send_data, sizeof(_sceFsSymlinkData), &_rcv_data_rpc, sizeof(_rcv_data_rpc), NULL, NULL);
    if (ret < 0x0) {
        DeleteSema(semaid);
        _sceFsSigSema();
        return -EAGAIN;
    }
   
    ret = *(u32*)UNCACHED(&_rcv_data_rpc);
    _sceFsSigSema();
    if (ret == 0x0) {
        DeleteSema(semaid);
        return -EAGAIN;
    }
    
    WaitSema(semaid);
    DeleteSema(semaid);
    return ret_link;
}

int sceReadlink(const char* path, char* buf, unsigned int bufsize) {
    _sceFsReadlinkData* rd;
    s32 nsize;
    s32 ret;
    s32 ret_link;
    struct SemaParam sparam;
    s32 semaid;

    rd = &_send_data.readLinkData;
    
    _sceFsWaitS(0x11);
    if (_fs_init == 0x0) {
        sceFsInit();
    }

    for (nsize = 0; nsize < MAX_ARG_SIZE && (rd->path[nsize] = path[nsize]) != 0; nsize++) { }
    
    if (nsize == MAX_ARG_SIZE) {
        rd->path[MAX_ARG_SIZE-1] = 0x0;
    }

    if (bufsize >= MAX_ARG_SIZE) {
        bufsize = MAX_ARG_SIZE-1;
    }

    rd->bufsize = bufsize;
    rd->bufaddr = (u32)buf;
    sceSifWriteBackDCache(buf, bufsize);
    sparam.maxCount = 0x1;
    sparam.initCount = 0x0;
    sparam.option = 0x0;
    semaid = CreateSema(&sparam);
    rd->ee_semid = semaid;
    rd->ee_retadr = (u32)&ret_link;
    rd->ee_retsiz = sizeof(ret_link);
    
    ret = sceSifCallRpc(&_cd, 0x19, 0x0, &_send_data, sizeof(_sceFsSymlinkData), &_rcv_data_rpc, sizeof(_rcv_data_rpc), NULL, NULL);
    if (ret < 0x0) {
        DeleteSema(semaid);
        _sceFsSigSema();
        return -EAGAIN;
    }
   
    ret = *(u32*)UNCACHED(&_rcv_data_rpc);
    _sceFsSigSema();
    if (ret == 0x0) {
        DeleteSema(semaid);
        return -EAGAIN;
    }
    
    WaitSema(semaid);
    DeleteSema(semaid);
    return ret_link;
}
