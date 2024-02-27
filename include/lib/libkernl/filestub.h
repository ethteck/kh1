#ifndef __filestub__
#define __filestub__

#include <sifdev.h>
#include "common.h"

typedef struct _sceFsIob {
    int i_fd;
    u32 i_flag;
    int i_errno;
    void *i_private;
}_sceFsIob;

typedef struct {
	int ee_semid;
	unsigned int ee_retadr;
	unsigned int ee_retsiz;
	int flag;
	unsigned int mode;
	char name[1024];
	int ee_fds;
} _sceFsOpenData;

typedef struct {
	int ee_semid;
	unsigned int ee_retadr;
	unsigned int ee_retsiz;
	int fd;
	int ee_fds;
} _sceFsCloseData;

typedef struct {
	int ee_semid;
	unsigned int ee_retadr;
	unsigned int ee_retsiz;
	int fd;
	int offset;
	int how;
	int ee_fds;
} _sceFsLseekData;

typedef struct {
	int ee_semid;
	unsigned int ee_retadr;
	unsigned int ee_retsiz;
	int fd;
	unsigned int addr;
	int size;
	unsigned int intr_addr;
	int ee_fds;
} _sceFsReadData;

typedef struct {
	int ee_semid;
	unsigned int ee_retadr;
	unsigned int ee_retsiz;
	int fd;
	unsigned int addr;
	int size;
	int psize;
	unsigned char pdata[16];
	int ee_fds;
} _sceFsWriteData;

typedef struct {
	int ee_semid;
	unsigned int ee_retadr;
	unsigned int ee_retsiz;
	int fd;
	int cmd;
	unsigned char arg[1024];
	void *ret_argadr;
	int ret_argsiz;
	int arglen;
} _sceFsIoctlData;

typedef struct {
	int ee_semid;
	unsigned int ee_retadr;
	unsigned int ee_retsiz;
	char name[1024];
} _sceFsNameData;

typedef struct {
	int ee_semid;
	unsigned int ee_retadr;
	unsigned int ee_retsiz;
	void *addr;
} _sceFsAddrData;

typedef struct {
	int ee_semid;
	unsigned int ee_retadr;
	unsigned int ee_retsiz;
	void *addr;
	unsigned char name[1024];
} _sceFsGStatData;

typedef struct {
	int ee_semid;
	unsigned int ee_retadr;
	unsigned int ee_retsiz;
	unsigned int cbit;
	struct sce_stat stat;
	unsigned char name[1024];
} _sceFsCStatData;

typedef struct {
	int ee_semid;
	unsigned int ee_retadr;
	unsigned int ee_retsiz;
	char path[1024];
	char blkdevname[1024];
	unsigned char arg[1024];
	int arglen;
} _sceFsFormatData;

typedef struct {
	int ee_semid;
	unsigned int ee_retadr;
	unsigned int ee_retsiz;
	char oldpath[1024];
	char newpath[1024];
} _sceFsRenameData;

typedef struct {
	int ee_semid;
	unsigned int ee_retadr;
	unsigned int ee_retsiz;
	int fd;
	int flag;
	char path[1024];
} _sceFsSyncData;

typedef struct {
	int ee_semid;
	unsigned int ee_retadr;
	unsigned int ee_retsiz;
	int flag;
	char name[1024];
} _sceFsMkdirData;

typedef struct {
	int ee_semid;
	unsigned int ee_retadr;
	unsigned int ee_retsiz;
	char fsdevname[1024];
	char blkdevname[1024];
	unsigned char arg[1024];
	int flag;
	int arglen;
} _sceFsMountData;

typedef struct {
	int ee_semid;
	unsigned int ee_retadr;
	unsigned int ee_retsiz;
	int fd;
	long int offset;
	int how;
	int ee_fds;
} _sceFsLseek64Data;

typedef struct {
	int ee_semid;
	unsigned int ee_retadr;
	unsigned int ee_retsiz;
	char path[1024];
	unsigned char arg_buf[1024];
	int cmd;
	int arglen;
	void *ret_argadr;
	int ret_arglen;
} _sceFsDevctlData;

typedef struct {
	int ee_semid;
	unsigned int ee_retadr;
	unsigned int ee_retsiz;
	char existing[1024];
	char new[1024];
} _sceFsSymlinkData;

typedef struct {
	int ee_semid;
	unsigned int ee_retadr;
	unsigned int ee_retsiz;
	unsigned int bufsize;
	unsigned int bufaddr;
	char path[1024];
} _sceFsReadlinkData;

typedef struct {
	int psize;
	int ssize;
	unsigned int paddr;
	unsigned int saddr;
	unsigned char pdata[64];
	unsigned char sdata[64];
} _sceFsReadIntrData;

typedef struct {
	int ee_semid;
	unsigned int ee_retmod;
	unsigned int ee_retadr;
	unsigned int ee_retsiz;
	int data_top[4];
} _sceFsIntrRcvData;

typedef struct {
	int ee_semid;
	unsigned int ee_retmod;
	unsigned int ee_retadr;
	unsigned int ee_retsiz;
	int ee_ret;
	unsigned int ee_dentadr;
	struct sce_dirent dent;
} _sceFsIntrRcvDirData;

typedef struct {
	int ee_semid;
	unsigned int ee_retmod;
	unsigned int ee_retadr;
	unsigned int ee_retsiz;
	int ee_ret;
	unsigned int ee_readladr;
	unsigned int ee_readlsiz;
	char linkname[1024];
} _sceFsIntrRcvReadLData;

typedef struct {
	int ee_semid;
	unsigned int ee_retmod;
	unsigned int ee_retadr;
	unsigned int ee_retsiz;
	int ee_ret;
	unsigned int ret_argadr;
	unsigned int ret_argsiz;
	unsigned char arg[1024];
} _sceFsIntrRcvIoctlData;

typedef struct {
	int ee_semid;
	unsigned int ee_retmod;
	unsigned int ee_retadr;
	unsigned int ee_retsiz;
	int ee_ret;
	unsigned int ret_argadr;
	unsigned int ret_argsiz;
	unsigned char arg[1024];
} _sceFsIntrRcvDevctlData;

typedef struct {
	void (*sceFsPoffCbfunc)(/* parameters unknown */);
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
