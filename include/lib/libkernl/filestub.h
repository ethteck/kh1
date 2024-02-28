#ifndef __filestub__
#define __filestub__

#include <sifdev.h>
#include "common.h"

typedef struct _sceFsIob {
    s32 i_fd;
    u32 i_flag;
    s32 i_errno;
    void *i_private;
}_sceFsIob;

typedef struct {
    s32 ee_semid;
    u32 ee_retadr;
    u32 ee_retsiz;
    s32 flag;
    u32 mode;
    char name[1024];
    s32 ee_fds;
} _sceFsOpenData;

typedef struct {
    s32 ee_semid;
    u32 ee_retadr;
    u32 ee_retsiz;
    s32 fd;
    s32 ee_fds;
} _sceFsCloseData;

typedef struct {
    s32 ee_semid;
    u32 ee_retadr;
    u32 ee_retsiz;
    s32 fd;
    s32 offset;
    s32 how;
    s32 ee_fds;
} _sceFsLseekData;

typedef struct {
    s32 ee_semid;
    u32 ee_retadr;
    u32 ee_retsiz;
    s32 fd;
    u32 addr;
    s32 size;
    u32 s32r_addr;
    s32 ee_fds;
} _sceFsReadData;

typedef struct {
    s32 ee_semid;
    u32 ee_retadr;
    u32 ee_retsiz;
    s32 fd;
    u32 addr;
    s32 size;
    s32 psize;
    u8 pdata[16];
    s32 ee_fds;
} _sceFsWriteData;

typedef struct {
    s32 ee_semid;
    u32 ee_retadr;
    u32 ee_retsiz;
    s32 fd;
    s32 cmd;
    u8 arg[1024];
    void *ret_argadr;
    s32 ret_argsiz;
    s32 arglen;
} _sceFsIoctlData;

typedef struct {
    s32 ee_semid;
    u32 ee_retadr;
    u32 ee_retsiz;
    char name[1024];
} _sceFsNameData;

typedef struct {
    s32 ee_semid;
    u32 ee_retadr;
    u32 ee_retsiz;
    void *addr;
} _sceFsAddrData;

typedef struct {
    s32 ee_semid;
    u32 ee_retadr;
    u32 ee_retsiz;
    void *addr;
    u8 name[1024];
} _sceFsGStatData;

typedef struct {
    s32 ee_semid;
    u32 ee_retadr;
    u32 ee_retsiz;
    u32 cbit;
    struct sce_stat stat;
    u8 name[1024];
} _sceFsCStatData;

typedef struct {
    s32 ee_semid;
    u32 ee_retadr;
    u32 ee_retsiz;
    char path[1024];
    char blkdevname[1024];
    u8 arg[1024];
    s32 arglen;
} _sceFsFormatData;

typedef struct {
    s32 ee_semid;
    u32 ee_retadr;
    u32 ee_retsiz;
    char oldpath[1024];
    char newpath[1024];
} _sceFsRenameData;

typedef struct {
    s32 ee_semid;
    u32 ee_retadr;
    u32 ee_retsiz;
    s32 fd;
    s32 flag;
    char path[1024];
} _sceFsSyncData;

typedef struct {
    s32 ee_semid;
    u32 ee_retadr;
    u32 ee_retsiz;
    s32 flag;
    char name[1024];
} _sceFsMkdirData;

typedef struct {
    s32 ee_semid;
    u32 ee_retadr;
    u32 ee_retsiz;
    char fsdevname[1024];
    char blkdevname[1024];
    u8 arg[1024];
    s32 flag;
    s32 arglen;
} _sceFsMountData;

typedef struct {
    s32 ee_semid;
    u32 ee_retadr;
    u32 ee_retsiz;
    s32 fd;
    s64 offset;
    s32 how;
    s32 ee_fds;
} _sceFsLseek64Data;

typedef struct {
    s32 ee_semid;
    u32 ee_retadr;
    u32 ee_retsiz;
    char path[1024];
    u8 arg_buf[1024];
    s32 cmd;
    s32 arglen;
    void *ret_argadr;
    s32 ret_arglen;
} _sceFsDevctlData;

typedef struct {
    s32 ee_semid;
    u32 ee_retadr;
    u32 ee_retsiz;
    char existing[1024];
    char new[1024];
} _sceFsSymlinkData;

typedef struct {
    s32 ee_semid;
    u32 ee_retadr;
    u32 ee_retsiz;
    u32 bufsize;
    u32 bufaddr;
    char path[1024];
} _sceFsReadlinkData;

typedef struct {
    s32 psize;
    s32 ssize;
    u32 paddr;
    u32 saddr;
    u8 pdata[64];
    u8 sdata[64];
} _sceFsReadIntrData;

typedef struct {
    s32 ee_semid;
    u32 ee_retmod;
    u32 ee_retadr;
    u32 ee_retsiz;
    s32 data_top[4];
} _sceFsIntrRcvData;

typedef struct {
    s32 ee_semid;
    u32 ee_retmod;
    u32 ee_retadr;
    u32 ee_retsiz;
    s32 ee_ret;
    u32 ee_dentadr;
    struct sce_dirent dent;
} _sceFsIntrRcvDirData;

typedef struct {
    s32 ee_semid;
    u32 ee_retmod;
    u32 ee_retadr;
    u32 ee_retsiz;
    s32 ee_ret;
    u32 ee_readladr;
    u32 ee_readlsiz;
    char linkname[1024];
} _sceFsIntrRcvReadLData;

typedef struct {
    s32 ee_semid;
    u32 ee_retmod;
    u32 ee_retadr;
    u32 ee_retsiz;
    s32 ee_ret;
    u32 ret_argadr;
    u32 ret_argsiz;
    u8 arg[1024];
} _sceFsIntrRcvIoctlData;

typedef struct {
    s32 ee_semid;
    u32 ee_retmod;
    u32 ee_retadr;
    u32 ee_retsiz;
    s32 ee_ret;
    u32 ret_argadr;
    u32 ret_argsiz;
    u8 arg[1024];
} _sceFsIntrRcvDevctlData;

typedef struct {
    void (*sceFsPoffCbfunc)(void *);
    void *sceFsPoffCbdata;
} _sceFsPoffData;

// inferred
typedef union {
    _sceFsOpenData openData;
    _sceFsCloseData closeData;
    _sceFsLseekData lSeekData;
    _sceFsReadData readData;
    _sceFsWriteData writeData;
    _sceFsIoctlData ioctlData;
    _sceFsNameData nameData;
    _sceFsAddrData addrData;
    _sceFsGStatData gStatData;
    _sceFsCStatData cStatData;
    _sceFsFormatData formatData;
    _sceFsRenameData renameData;
    _sceFsSyncData syncData;
    _sceFsMkdirData mkdirData;
    _sceFsMountData mountData;
    _sceFsLseek64Data lseek64Data;
    _sceFsDevctlData devctlData;
    _sceFsSymlinkData symlinkData;
    _sceFsReadlinkData readLinkData;
    _sceFsReadIntrData readIntrData;
} _sceFsData;

// inferred
typedef union {
    _sceFsReadIntrData readIntrData;
    _sceFsIntrRcvData rcvData;
    _sceFsIntrRcvDirData rcvDirData;
    _sceFsIntrRcvReadLData rcvReadLdata;
    _sceFsIntrRcvIoctlData rcvIoctlData;
    _sceFsIntrRcvDevctlData rcvDevctlData;
} _sceFsIntrData;

#endif /* __filestub__ */
