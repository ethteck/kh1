#include "common.h"
#include "eekernel.h"
#include "sifrpc.h"
#include "libmc.h"

typedef struct {
    /* 0x00 */ s32 fd;
    /* 0x04 */ s32 port;
    /* 0x08 */ s32 slot;
    /* 0x0C */ s32 size;
    /* 0x10 */ s32 offset;
    /* 0x14 */ s32 mode;
    /* 0x18 */ void* buffer;
    /* 0x1C */ s32* unk_1C;
    /* 0x20 */ char unk_20[0x10];
} SifParams; // size = 0x30

typedef struct {
    /* 0x000 */ s32 port;
    /* 0x004 */ s32 slot;
    /* 0x008 */ s32 mode;
    /* 0x00C */ s32 maxent;
    /* 0x010 */ sceMcTblGetDir* table;
    /* 0x014 */ char name[0x3FF];
    /* 0x413 */ s8 unk_413;
} McStatus; // size = 0x414

// todo: data split, blocked by lib version string
s32 semaidRegFunc;
s32 mcRunCmdNo;

// todo: rodata split, blocked by libc constants (0x38DB60 to rodata end)
char D_0048DA58[24]; // "bind error libmc \n";
char D_0048DA70[40]; // "libmc: too old release of mcserv.irx\n";
char D_0048DA98[40]; // "libmc: too old release of mcman.irx\n";
char D_0048DAC0[32]; // "sceMcUdCheckNewCard RPC faild\n";

sceSifClientData mcClientID;
SifParams mcSifParams;
McStatus mcStatus;
s32 mcRetVal[4]; // Buffer for data received from RPC

sceMcTblGetDir mcFileTable;
s32 D_0066DB00;
sceMcTblGetDir mcCachedTables[16];

/**
 * @brief Initialize internal variables used in the Memory Card library
 *
 * @return `sceMcIni` macro value
 */
s32 sceMcInit(void) {
    struct SemaParam sParam;
    s32 sifServerStat;
    s32 i;

    if (semaidRegFunc < 0) {
        sParam.option = 0;
        sParam.initCount = 1;
        sParam.maxCount = 1;
        semaidRegFunc = CreateSema(&sParam);
    }
    sceMcSync(0, NULL, NULL);
    WaitSema(semaidRegFunc);
    sceSifInitRpc(0);

    while (TRUE) {
        if (sceSifBindRpc(&mcClientID, 0x80000400, 0) < 0) {
            printf(D_0048DA58);
            do {
                /* infinite loop */
            } while (TRUE);
        }
        if (mcClientID.serve != NULL) {
            break;
        }

        i = 0x100000;
        do {
            i--;
        } while (i != 0);
    }

    sifServerStat = sceSifCallRpc(&mcClientID, 0xFE, 0, &mcSifParams, sizeof(mcSifParams), &mcRetVal, 12, NULL, NULL);
    SignalSema(semaidRegFunc);
    if (sifServerStat < 0) {
        mcClientID.serve = NULL;
        return sifServerStat - 100;
    } else if (mcRetVal[1] < 0x20A) {
        printf(D_0048DA70);
        mcClientID.serve = NULL;
        return sceMcIniOldMcserv;
    } else {
        if (mcRetVal[2] < 0x20E) {
            printf(D_0048DA98);
            mcClientID.serve = NULL;
            return sceMcIniOldMcman;
        }
        return mcRetVal[0];
    }
}

/**
 * Release resources used by the memory card library
 */
s32 sceMcEnd(void) {
    if (semaidRegFunc >= 0) {
        DeleteSema(semaidRegFunc);
        semaidRegFunc = -1;
    }
    return 1;
}

INCLUDE_ASM(const s32, "lib/libmc", _lmcGetClientPtr);

/**
 * @brief Change `mcserv.irx` IOP module thread priority
 *
 * @param level Thread priority level
 * @return `sceMsResNo` macro value
 */
s32 sceMcChangeThreadPriority(s32 level) {
    s32 sifServerStat;

    if (PollSema(semaidRegFunc) < 0) {
        return sceMcErrSemapho;
    } else if (mcClientID.serve == NULL) {
        SignalSema(semaidRegFunc);
        return sceMcErrUnbind;
    } else {
        mcSifParams.mode = level;
        sifServerStat = sceSifCallRpc(
            &mcClientID, sceMcFuncChgPrior, 1, &mcSifParams, sizeof(mcSifParams), &mcRetVal, 4, NULL, NULL
        );
        if (sifServerStat == 0) {
            mcRunCmdNo = sceMcFuncChgPrior;
        } else {
            SignalSema(semaidRegFunc);
        }
        return sifServerStat;
    }
}

/**
 * @brief Get number of slots in the specified port
 *
 * @param port Port number
 * @return 1 to 4 on success, `sceMsResNo` macro value on error
 */
s32 sceMcGetSlotMax(s32 port) {
    s32 sifServerStat;

    if (PollSema(semaidRegFunc) < 0) {
        return sceMcErrSemapho;
    } else if (mcClientID.serve == NULL) {
        SignalSema(semaidRegFunc);
        return sceMcErrUnbind;
    } else {
        mcSifParams.port = port;
        sifServerStat = sceSifCallRpc(
            &mcClientID, sceMcFuncSlotMax, 0, &mcSifParams, sizeof(mcSifParams), &mcRetVal, 4, NULL, NULL
        );
        if (sifServerStat != 0) {
            SignalSema(semaidRegFunc);
            return sifServerStat;
        } else {
            SignalSema(semaidRegFunc);
            return mcRetVal[0];
        }
    }
}

/**
 * @brief Open a file and return the file descriptor. Up to three files can be open at the same time for all ports.
 *
 * @param port Port number
 * @param slot Slot number
 * @param name File name, up to 30 characters unless a path is specified
 * @param mode Readable: 1, Writable: 2, Newly created: 0x200, can be logical ORed together
 * @return File descriptor on success, `sceMsResNo` macro value on error
 */
s32 sceMcOpen(s32 port, s32 slot, const char* name, s32 mode) {
    s32 sifServerStat;

    if (PollSema(semaidRegFunc) < 0) {
        return sceMcErrSemapho;
    } else if (mcClientID.serve == NULL) {
        SignalSema(semaidRegFunc);
        return sceMcErrUnbind;
    } else if ((name == NULL) || (*name == '\0')) {
        SignalSema(semaidRegFunc);
        return sceMcErrNullStr;
    } else {
        strncpy(mcStatus.name, name, sizeof(mcStatus.name));
        mcStatus.unk_413 = '\0';
        mcStatus.port = port;
        mcStatus.mode = mode;
        mcStatus.slot = slot;
        sifServerStat = sceSifCallRpc(&mcClientID, sceMcFuncNoOpen, 1, &mcStatus, sizeof(mcStatus), &mcRetVal, 4, NULL, NULL);
        if (sifServerStat == 0) {
            mcRunCmdNo = sceMcFuncNoOpen;
        } else {
            SignalSema(semaidRegFunc);
        }
        return sifServerStat;
    }
}

/**
 * Create subdirectory specified by either a relative or absolute path.
 * If an absolute path is specified, each subdirectory above that directory must already exist.
 *
 * @param port port number
 * @param slot slot number
 * @param name name of subdirectory to be newly created
 * @return `sceMsRes` macro value
 */
s32 sceMcMkdir(s32 port, s32 slot, const char* name) {
    s32 iVar1 = sceMcOpen(port, slot, name, 0x40);

    if (iVar1 == 0) {
        mcRunCmdNo = sceMcFuncNoMkdir;
    }
    return iVar1;
}

/**
 * @brief Closes a file. If data to be written is not updated and remains in the file cache
 * (without `sceMcFlush` being executed), this function writes it to the Memory Card.
 *
 * @param fd File handler number of file to be closed
 * @return `sceMsRes` macro value
 */
s32 sceMcClose(s32 fd) {
    s32 sifServerStat;

    if (PollSema(semaidRegFunc) < 0) {
        return sceMcErrSemapho;
    } else if (mcClientID.serve == NULL) {
        SignalSema(semaidRegFunc);
        return sceMcErrUnbind;
    } else {
        mcSifParams.fd = fd;
        sifServerStat = sceSifCallRpc(
            &mcClientID, sceMcFuncNoClose, 1, &mcSifParams, sizeof(mcSifParams), &mcRetVal, 4, NULL, NULL
        );
        if (sifServerStat == 0) {
            mcRunCmdNo = sceMcFuncNoClose;
        } else {
            SignalSema(semaidRegFunc);
        }
        return sifServerStat;
    }
}

/**
 * @brief Moves the file pointer of a file that is open
 *
 * @param fd File handler number
 * @param offset Offset value from starting point indicated by mode
 * @param mode 0: Beginning of file, 1: Current file pointer, 2: End of file + 1 (file size)
 * @return s32
 */
s32 sceMcSeek(s32 fd, s32 offset, s32 mode) {
    s32 sifServerStat;

    if (PollSema(semaidRegFunc) < 0) {
        return sceMcErrSemapho;
    } else if (mcClientID.serve == NULL) {
        SignalSema(semaidRegFunc);
        return sceMcErrUnbind;
    } else {
        mcSifParams.fd = fd;
        mcSifParams.offset = offset;
        mcSifParams.mode = mode;
        sifServerStat =
            sceSifCallRpc(&mcClientID, sceMcFuncNoSeek, 1, &mcSifParams, sizeof(mcSifParams), &mcRetVal, 4, NULL, NULL);
        if (sifServerStat == 0) {
            mcRunCmdNo = sceMcFuncNoSeek;
        } else {
            SignalSema(semaidRegFunc);
        }
        return sifServerStat;
    }
}

INCLUDE_ASM(const s32, "lib/libmc", mceIntrReadFixAlign);
void mceIntrReadFixAlign();

/**
 * @brief Reads data from a file on the Memory Card
 *
 * @param fd File handler number
 * @param buff Pointer to buffer for writing data that was read
 * @param size Size to be read in bytes
 * @return Number of bytes read on success, `sceMsRes` macro value on error
 */
s32 sceMcRead(s32 fd, void* buff, s32 size) {
    s32 sifServerStat;

    if (PollSema(semaidRegFunc) < 0) {
        return sceMcErrSemapho;
    } else if (mcClientID.serve == NULL) {
        SignalSema(semaidRegFunc);
        return sceMcErrUnbind;
    } else {
        mcSifParams.fd = fd;
        mcSifParams.buffer = buff;
        mcSifParams.size = size;
        mcSifParams.unk_1C = &D_0066DB00;
        sceSifWriteBackDCache(buff, size);
        sceSifWriteBackDCache(&D_0066DB00, 0xC0);
        sifServerStat = sceSifCallRpc(
            &mcClientID, sceMcFuncNoRead, 1, &mcSifParams, sizeof(mcSifParams), &mcRetVal, 4, mceIntrReadFixAlign,
            &D_0066DB00
        );
        if (sifServerStat == 0) {
            mcRunCmdNo = sceMcFuncNoRead;
        } else {
            SignalSema(semaidRegFunc);
        }
        return sifServerStat;
    }
}

INCLUDE_ASM(const s32, "lib/libmc", sceMcWrite);

void mcHearAlarm(s32 arg0, u16 arg1, void* thread) {
    iWakeupThread((s32)thread);
    ExitHandler();
}

void mcDelayThread(u16 arg0) {
    SetAlarm(arg0, mcHearAlarm, (void*)GetThreadId());
    SleepThread();
}

INCLUDE_ASM(const s32, "lib/libmc", sceMcSync);

INCLUDE_ASM(const s32, "lib/libmc", mceGetInfoApdx);
void mceGetInfoApdx();

INCLUDE_ASM(const s32, "lib/libmc", sceMcGetInfo);

s32 sceMcUdCheckNewCard(void) {
    if (sceSifCallRpc(&mcClientID, 0x35, 0, &mcSifParams, sizeof(mcSifParams), &mcRetVal, 4, NULL, NULL) != 0) {
        printf(D_0048DAC0);
        return -1;
    }
    return mcRetVal[0];
}

/**
 * @brief Get a list of files on the Memory Card
 *
 * @param port Port number
 * @param slot Slot number
 * @param name Absolute or relative pathname from the current directory. Accepts a `*` wildcard.
 * @param mode 0: Check a port or slot that has changed since the last time sceMcGetDir() was executed.
 *             Non-0: Request file list following the portion that was obtained by the first call
 * @param maxent Max number of entries written to table by one call.
 * @param table Buffer where the file list that was obtained is written
 * @return s32
 */
s32 sceMcGetDir(s32 port, s32 slot, const char* name, u32 mode, s32 maxent, sceMcTblGetDir* table) {
    s32 sifServerStat;

    if (PollSema(semaidRegFunc) < 0) {
        return sceMcErrSemapho;
    } else if (mcClientID.serve == NULL) {
        SignalSema(semaidRegFunc);
        return sceMcErrUnbind;
    } else if (name == NULL || *name == '\0') {
        SignalSema(semaidRegFunc);
        return sceMcErrNullStr;
    } else {
        mcStatus.port = port;
        mcStatus.slot = slot;
        mcStatus.mode = mode;
        mcStatus.maxent = maxent;
        mcStatus.table = table;
        strncpy(mcStatus.name, name, sizeof(mcStatus.name));
        mcStatus.unk_413 = 0;
        if (-1 < maxent) {
            sceSifWriteBackDCache(table, maxent << 6);
        }
        sifServerStat = sceSifCallRpc(&mcClientID, sceMcFuncNoGetDir, 1, &mcStatus, sizeof(mcStatus), &mcRetVal, 4, NULL, NULL);
        if (sifServerStat == 0) {
            mcRunCmdNo = sceMcFuncNoGetDir;
        } else {
            SignalSema(semaidRegFunc);
        }
    }
    return sifServerStat;
}

INCLUDE_ASM(const s32, "lib/libmc", mceStorePwd);
void mceStorePwd();

/**
 * @brief Change current directory
 *
 * @param port Port number
 * @param slot Slot number
 * @param path Absolute or relative pathname from the current directory
 * @param pwd Pointer to buffer for storing current directory, 0 if not needed
 * @return `sceMsRes` macro value
 */
s32 sceMcChdir(s32 port, s32 slot, const char* path, char* pwd) {
    s32 sifServerStat;

    if (PollSema(semaidRegFunc) < 0) {
        return sceMcErrSemapho;
    } else if (mcClientID.serve == NULL) {
        SignalSema(semaidRegFunc);
        return sceMcErrUnbind;
    } else if (path == NULL || *path == '\0') {
        SignalSema(semaidRegFunc);
        return sceMcErrNullStr;
    } else {
        mcStatus.table = mcCachedTables;
        mcStatus.port = port;
        mcStatus.slot = slot;
        strncpy(mcStatus.name, path, sizeof(mcStatus.name));
        mcStatus.unk_413 = 0;
        sceSifWriteBackDCache(&mcCachedTables, sizeof(mcCachedTables));
        sifServerStat = sceSifCallRpc(
            &mcClientID, sceMcFuncNoChDir, 1, &mcStatus, sizeof(mcStatus), &mcRetVal, 4, mceStorePwd, pwd
        );
        if (sifServerStat == 0) {
            mcRunCmdNo = sceMcFuncNoChDir;
        } else {
            SignalSema(semaidRegFunc);
        }
    }
    return sifServerStat;
}

/**
 * @brief Logically formats a Memory Card, which must be formatted to perform file access operations.
 *
 * @param port Port number
 * @param slot Slot number
 * @return `sceMsRes` macro value
 */
s32 sceMcFormat(s32 port, s32 slot) {
    s32 sifServerStat;

    if (PollSema(semaidRegFunc) < 0) {
        return sceMcErrSemapho;
    } else if (mcClientID.serve == NULL) {
        SignalSema(semaidRegFunc);
        return sceMcErrUnbind;
    } else {
        mcSifParams.port = port;
        mcSifParams.slot = slot;
        sifServerStat = sceSifCallRpc(
            &mcClientID, sceMcFuncNoFormat, 1, &mcSifParams, sizeof(mcSifParams), &mcRetVal, 4, NULL, NULL
        );
        if (sifServerStat == 0) {
            mcRunCmdNo = sceMcFuncNoFormat;
        } else {
            SignalSema(semaidRegFunc);
        }
        return sifServerStat;
    }
}

/**
 * @brief Deletes a file on the Memory Card
 *
 * @param port Port number
 * @param slot Slot number
 * @param name Either an absolute or relative pathname of file to be deleted
 * @return `sceMsRes` macro value
 */
s32 sceMcDelete(s32 port, s32 slot, const char* name) {
    s32 sifServerStat;

    if (PollSema(semaidRegFunc) < 0) {
        return sceMcErrSemapho;
    } else if (mcClientID.serve == NULL) {
        SignalSema(semaidRegFunc);
        return sceMcErrUnbind;
    } else if (name == NULL || *name == '\0') {
        SignalSema(semaidRegFunc);
        return sceMcErrNullStr;
    } else {
        strncpy(mcStatus.name, name, sizeof(mcStatus.name));
        mcStatus.unk_413 = 0;
        mcStatus.port = port;
        mcStatus.slot = slot;
        mcStatus.mode = 0;
        sifServerStat = sceSifCallRpc(&mcClientID, sceMcFuncNoDelete, 1, &mcStatus, sizeof(mcStatus), &mcRetVal, 4, NULL, NULL);
        if (sifServerStat == 0) {
            mcRunCmdNo = sceMcFuncNoDelete;
        } else {
            SignalSema(semaidRegFunc);
        }
        return sifServerStat;
    }
}

/**
 * @brief Writes onto the Memory Card the data that remains in the file cache after a file is written
 *
 * @param fd File handler number of file for which file cache is to be written
 * @return `sceMsRes` macro value
 */
s32 sceMcFlush(s32 fd) {
    s32 sifServerStat;

    if (PollSema(semaidRegFunc) < 0) {
        return sceMcErrSemapho;
    } else if (mcClientID.serve == NULL) {
        SignalSema(semaidRegFunc);
        return sceMcErrUnbind;
    } else {
        mcSifParams.fd = fd;
        sifServerStat = sceSifCallRpc(
            &mcClientID, sceMcFuncNoFlush, 1, &mcSifParams, sizeof(mcSifParams), &mcRetVal, 4, NULL, NULL
        );
        if (sifServerStat == 0) {
            mcRunCmdNo = sceMcFuncNoFlush;
        } else {
            SignalSema(semaidRegFunc);
        }
        return sifServerStat;
    }
}

INCLUDE_ASM(const s32, "lib/libmc", sceMcSetFileInfo);

/**
 * @brief Change the file or directory name
 *
 * @param port Port number
 * @param slot Slot number
 * @param org File or directory to be renamed
 * @param new New name
 * @return `sceMsRes` macro value
 */
s32 sceMcRename(s32 port, s32 slot, const char* org, const char* new) {
    s32 sifServerStat;

    if (PollSema(semaidRegFunc) < 0) {
        return sceMcErrSemapho;
    } else if (mcClientID.serve == NULL) {
        SignalSema(semaidRegFunc);
        return sceMcErrUnbind;
    } else if ((org == NULL || *org == '\0') || new == NULL) {
        SignalSema(semaidRegFunc);
        return sceMcErrNullStr;
    } else {
        mcStatus.port = port;
        mcStatus.slot = slot;
        mcStatus.mode = 0x10;
        strncpy(mcStatus.name, org, sizeof(mcStatus.name));
        mcStatus.unk_413 = '\0';
        strncpy(mcFileTable.EntryName, new, 0x20);
        mcFileTable.EntryName[31] = '\0';
        mcStatus.table = &mcFileTable;
        FlushCache(0);
        sifServerStat =
            sceSifCallRpc(&mcClientID, sceMcFuncNoFileInfo, 1, &mcStatus, sizeof(mcStatus), &mcRetVal, 4, NULL, NULL);
        if (sifServerStat == 0) {
            mcRunCmdNo = sceMcFuncNoRename;
        } else {
            SignalSema(semaidRegFunc);
        }
        return sifServerStat;
    }
}

/**
 * @brief Unformats a Memory Card. This function is primarily used for debugging.
 *
 * @param port Port number
 * @param slot Slot number
 * @return `sceMsRes` macro value
 */
s32 sceMcUnformat(s32 port, s32 slot) {
    s32 sifServerStat;

    if (PollSema(semaidRegFunc) < 0) {
        return sceMcErrSemapho;
    } else if (mcClientID.serve == NULL) {
        SignalSema(semaidRegFunc);
        return sceMcErrUnbind;
    } else {
        mcSifParams.port = port;
        mcSifParams.slot = slot;
        sifServerStat = sceSifCallRpc(
            &mcClientID, sceMcFuncNoUnformat, 1, &mcSifParams, sizeof(mcSifParams), &mcRetVal, 4, NULL, NULL
        );
        if (sifServerStat == 0) {
            mcRunCmdNo = sceMcFuncNoUnformat;
        } else {
            SignalSema(semaidRegFunc);
        }
        return sifServerStat;
    }
}

/**
 * @brief Check free space in entry information storage area
 *
 * @param port Port number
 * @param slot Slot number
 * @param path Path name to be checked
 * @return Number of free entries on success, `sceMsRes` macro value on error
 */
s32 sceMcGetEntSpace(s32 port, s32 slot, const char* path) {
    s32 sifServerStat;

    if (PollSema(semaidRegFunc) < 0) {
        return sceMcErrSemapho;
    } else if (mcClientID.serve == NULL) {
        SignalSema(semaidRegFunc);
        return sceMcErrUnbind;
    } else if (path == NULL || *path == '\0') {
        SignalSema(semaidRegFunc);
        return sceMcErrNullStr;
    } else {
        mcStatus.port = port;
        mcStatus.slot = slot;
        strncpy(mcStatus.name, path, sizeof(mcStatus.name));
        mcStatus.unk_413 = '\0';
        sifServerStat =
            sceSifCallRpc(&mcClientID, sceMcFuncNoEntSpace, 1, &mcStatus, sizeof(mcStatus), &mcRetVal, 4, NULL, NULL);
        if (sifServerStat == 0) {
            mcRunCmdNo = sceMcFuncNoEntSpace;
        } else {
            SignalSema(semaidRegFunc);
        }
        return sifServerStat;
    }
}
