#include "common.h"
#include "memcard.h"

#include "libmc.h"

// .data

void (*memcardCommands[14])(void) = {
    func_00231370,    memcard_GetInfo, memcard_GetAllFiles, memcard_GetDirFiles, memcard_Format,
    memcard_Unformat, memcard_Chdir,   memcard_Mkdir,       memcard_Create,      memcard_Delete,
    memcard_Read,     memcard_Write,   memcard_Rename,      func_00232FF8,
};
s32 D_0041F900[2] = {};
s32 memcardPort = 0;
s32 memcardSlot = 0;
// Type of memory card detected
s32 memcardType = sceMcTypeNoCard;

// Number of free clusters on memory card, if available
s32 memcardFree = 0;

// Boolean indicating if the memory card is formatted
s32 memcardFormat = 0;
s32 D_0041F920[8] = {};
s32 D_0041F940[8] = {};
s32 D_0041F960[8] = {};
s32 D_0041F980[8] = {};

// Buffer for storing the obtained file list
sceMcTblGetDir* memcardFileBuf = NULL;

// Number of entries to be written to table
// If negative, skips writing and `sceMcSync` only returns number of entries matching `name`
s32 memcardEntries = 0;

// Buffer for storing the current directory
char memcardDirStore[32] = {};
s32 D_0041F9C8[2] = {};

// .bss

s32 D_006417B8;
s32 memcardCurCmdIdx;
s32 D_00641FC4;
s32 D_00641FC8;
s32 D_00641FCC;
s32 D_00641FD0;
s32 D_00641FD4;

// Stores result of sceMcSync. Negative values indicate an error, positive carries contextual values
s32 memcardResult;

s32 D_00641FDC;
s32 D_00641FE0;
s32 D_00641FE4;
s32 D_00641FE8;
s32 D_00641FEC;
s32 D_00641FF0;
s32 D_00641FF8[2];

// The following appear to be status flags for each command
s32 memcardGetAllStatus;
s32 memcardGetDirStatus;
s32 memcardFormatStatus;
s32 memcardUnformatStatus;
s32 memcardChdirStatus;
s32 memcardMkdirStatus;
s32 memcardCreateStatus;
s32 memcardDeleteStatus;
s32 memcardReadStatus;
s32 memcardWriteStatus;
s32 memcardRenameStatus;
s32 D_0064202C;

char* memcardFileName;
char* memcardNewFileName;
void* D_00642038;
s32 D_0064203C;
s32 D_00642040;
s32 (*D_00642044)(s32);

INCLUDE_ASM(const s32, "memcard", func_002304D8);

INCLUDE_ASM(const s32, "memcard", func_00230520);

INCLUDE_ASM(const s32, "memcard", func_00230760);

INCLUDE_ASM(const s32, "memcard", func_00230810);

s32 func_00230948(void) {
    return D_006417B8;
}

void func_00230958(s32 arg0) {
    D_006417B8 = 1;
    D_00641FE4 = arg0;
    D_00641FE8 = 0;
}

void func_00230978(void) {
    D_006417B8 = 0;
}

void func_00230988(s32 arg0, s32 arg1) {
    D_00641FEC = arg0;
    D_00641FF0 = arg1;
}

s32 func_002309A0(s32 port, s32 slot) {
    s32 iVar1 = D_0041F940[port * 4 + slot];
    D_0041F940[port * 4 + slot] = 0;
    return iVar1;
}

void func_002309C8(s32 port, s32 slot) {
    D_0041F940[port * 4 + slot] = 0;
}

s32 func_002309E8(s32 port, s32 slot) {
    s32 iVar1 = D_0041F960[port * 4 + slot];
    D_0041F960[port * 4 + slot] = 0;
    return iVar1;
}

void func_00230A10(s32 port, s32 slot) {
    D_0041F960[port * 4 + slot] = 0;
}

s32 func_00230A30(s32 port, s32 slot) {
    s32 iVar1 = D_0041F980[port * 4 + slot];
    D_0041F980[port * 4 + slot] = 0;
    return iVar1;
}

void func_00230A58(s32 port, s32 slot) {
    D_0041F980[port * 4 + slot] = 0;
}

INCLUDE_ASM(const s32, "memcard", func_00230A78);

INCLUDE_ASM(const s32, "memcard", func_00230AF8);

INCLUDE_ASM(const s32, "memcard", func_00230BA8);

INCLUDE_ASM(const s32, "memcard", func_00230C70);

INCLUDE_ASM(const s32, "memcard", func_00230CF0);

INCLUDE_ASM(const s32, "memcard", func_00230D70);

INCLUDE_ASM(const s32, "memcard", func_00230E08);

INCLUDE_ASM(const s32, "memcard", func_00230EA0);

INCLUDE_ASM(const s32, "memcard", func_00230F68);

INCLUDE_ASM(const s32, "memcard", func_00231000);

INCLUDE_ASM(const s32, "memcard", func_002310C8);

INCLUDE_ASM(const s32, "memcard", func_00231190);

INCLUDE_ASM(const s32, "memcard", func_00231240);

s32 func_002312A0(void) {
    return D_00641FF8[1];
}

s32 memcard_GetAllStatus(void) {
    return memcardGetAllStatus;
}

s32 memcard_GetDirStatus(void) {
    return memcardGetDirStatus;
}

s32 memcard_GetFormatStatus(void) {
    return memcardFormatStatus;
}

s32 memcard_GetUnformatStatus(void) {
    return memcardUnformatStatus;
}

s32 memcard_GetChdirStatus(void) {
    return memcardChdirStatus;
}

s32 memcard_GetMkdirStatus(void) {
    return memcardMkdirStatus;
}

s32 memcard_GetCreateStatus(void) {
    return memcardCreateStatus;
}

s32 memcard_GetDeleteStatus(void) {
    return memcardDeleteStatus;
}

s32 memcard_GetReadStatus(void) {
    return memcardReadStatus;
}

s32 memcard_GetWriteStatus(void) {
    return memcardWriteStatus;
}

s32 memcard_GetRenameStatus(void) {
    return memcardRenameStatus;
}

s32 func_00231360(void) {
    return D_0064202C;
}

INCLUDE_ASM(const s32, "memcard", func_00231370);

void memcard_GetInfo(void) {
    switch (D_00641FC4) {
        case 0:
            sceMcGetInfo(memcardPort, memcardSlot, &memcardType, &memcardFree, &memcardFormat);
            D_00641FC4++;
            break;

        case 1:
            if (sceMcSync(1, NULL, &memcardResult) != 0) {
                D_00641FC4++;
            }
            break;

        case 2:
            if (memcardType == sceMcTypePDA) {
                D_0041F920[memcardPort * 4 + memcardSlot] = 3;
            } else {
                switch (memcardResult) {
                    case sceMcResSucceed: // Same card has been used continuously
                        D_00641FF8[1] = 0;
                        D_0041F920[memcardPort * 4 + memcardSlot] = 0;
                        break;

                    case sceMcResChangedCard: // Card has since been changed to a formatted card
                        D_00641FF8[1] = 0;
                        D_0041F920[memcardPort * 4 + memcardSlot] = 1;
                        D_0041F940[memcardPort * 4 + memcardSlot] = 1;
                        D_0041F960[memcardPort * 4 + memcardSlot] = 1;
                        break;

                    case sceMcResNoFormat: // Card has since been changed to an unformatted card
                        D_00641FF8[1] = 0;
                        D_0041F920[memcardPort * 4 + memcardSlot] = 2;
                        D_0041F940[memcardPort * 4 + memcardSlot] = 1;
                        D_0041F960[memcardPort * 4 + memcardSlot] = 1;
                        break;

                    default:
                        D_0041F920[memcardPort * 4 + memcardSlot] = 3;
                        if (D_00641FF8[1] == 0) {
                            D_0041F940[memcardPort * 4 + memcardSlot] = 1;
                            D_0041F980[memcardPort * 4 + memcardSlot] = 1;
                        }
                        D_00641FF8[1] = 1;
                        break;
                }
            }

            memcardCurCmdIdx = 0;
            D_00641FE8 = D_00641FE4;
            if (D_00642044 != NULL) {
                D_00642044(D_00641FD4);
            }
            break;
    }
}

void memcard_GetAllFiles(void) {
    switch (D_00641FC4) {
        case 0:
            sceMcGetDir(memcardPort, memcardSlot, "*", 0, memcardEntries, memcardFileBuf);
            D_00641FC4++;
            break;

        case 1:
            if (sceMcSync(1, NULL, &memcardResult) != 0) {
                D_00641FC4++;
            }
            break;

        case 2:
            // Result contains number of entries obtained
            if (memcardResult >= 0) {
                memcardEntries = memcardResult;
                memcardGetAllStatus = 0;
            } else {
                if (memcardResult == sceMcResNoFormat) {
                    memcardEntries = -1;
                    memcardGetAllStatus = 1;
                } else if (memcardResult == sceMcResNoEntry) {
                    memcardEntries = -1;
                    memcardGetAllStatus = D_00641FC4;
                } else {
                    memcardEntries = -1;
                    memcardGetAllStatus = 3;
                }
            }
            memcardCurCmdIdx = 0;
            D_00641FE8 = D_00641FE4;
            if (D_00642044 != NULL) {
                D_00642044(D_00641FD4);
            }
    }
}

void memcard_GetDirFiles(void) {
    switch (D_00641FC4) {
        case 0:
            sceMcGetDir(memcardPort, memcardSlot, memcardFileName, 0, memcardEntries, memcardFileBuf);
            D_00641FC4++;
            break;

        case 1:
            if (sceMcSync(1, NULL, &memcardResult) != 0) {
                D_00641FC4++;
            }
            break;

        case 2:
            if (D_00641FC4 == 2) {
                if (memcardResult >= 0) {
                    memcardEntries = memcardResult;
                    memcardGetDirStatus = 0;
                } else {
                    if (memcardResult == sceMcResNoFormat) {
                        memcardEntries = -1;
                        memcardGetDirStatus = D_00641FC4;
                    } else if (memcardResult == sceMcResNoEntry) {
                        memcardEntries = -1;
                        memcardGetDirStatus = 3;
                    } else {
                        memcardEntries = -1;
                        memcardGetDirStatus = 4;
                    }
                }
                memcardCurCmdIdx = 0;
                D_00641FE8 = D_00641FE4;
                if (D_00642044 != NULL) {
                    D_00642044(D_00641FD4);
                }
            }
    }
}

void memcard_Format(void) {
    switch (D_00641FC4) {
        case 0:
            sceMcFormat(memcardPort, memcardSlot);
            D_00641FC4++;
            break;

        case 1:
            if (sceMcSync(1, NULL, &memcardResult) != 0) {
                D_00641FC4++;
            }
            break;

        case 2:
            if (memcardResult != sceMcResSucceed) {
                if (D_00641FDC != 0) {
                    D_00641FDC--;
                    D_00641FE0 = 60;
                    D_00641FC4 = 3;
                    break;
                }
                memcardFormatStatus = TRUE;
            } else {
                memcardFormatStatus = FALSE;
            }
            memcardCurCmdIdx = 0;
            D_00641FE8 = D_00641FE4;
            if (D_00642044 != NULL) {
                D_00642044(D_00641FD4);
            }
            break;

        case 3:
            if (D_00641FE0 != 0) {
                D_00641FE0--;
                break;
            }
            D_00641FC4 = 0;
    }
}

void memcard_Unformat(void) {
    switch (D_00641FC4) {
        case 0:
            sceMcUnformat(memcardPort, memcardSlot);
            D_00641FC4++;
            break;

        case 1:
            if (sceMcSync(1, NULL, &memcardResult) != 0) {
                D_00641FC4++;
            }
            break;

        case 2:
            if (memcardResult != sceMcResSucceed) {
                if (D_00641FDC != 0) {
                    D_00641FDC--;
                    D_00641FE0 = 60;
                    D_00641FC4 = 3;
                    break;
                }
                memcardUnformatStatus = 1;
            } else {
                memcardUnformatStatus = 0;
            }
            memcardCurCmdIdx = 0;
            D_00641FE8 = D_00641FE4;
            if (D_00642044 != NULL) {
                D_00642044(D_00641FD4);
            }
            break;

        case 3:
            if (D_00641FE0 != 0) {
                D_00641FE0--;
                break;
            }
            D_00641FC4 = 0;
    }
}

void memcard_Chdir(void) {
    switch (D_00641FC4) {
        case 0:
            sceMcChdir(memcardPort, memcardSlot, memcardFileName, memcardDirStore);
            D_00641FC4++;
            break;

        case 1:
            if (sceMcSync(1, NULL, &memcardResult) != 0) {
                D_00641FC4++;
            }
            break;

        case 2:
            switch (memcardResult) {
                case sceMcResSucceed:
                    memcardChdirStatus = 0;
                    break;
                case sceMcResNoFormat: // Memory card was unformatted
                    memcardChdirStatus = 1;
                    break;
                case sceMcResNoEntry: // Specified directory does not exist
                    memcardChdirStatus = D_00641FC4;
                    break;
                default:
                    memcardChdirStatus = 3;
                    break;
            }
            memcardCurCmdIdx = 0;
            D_00641FE8 = D_00641FE4;
            if (D_00642044 != NULL) {
                D_00642044(D_00641FD4);
            }
    }
}

void memcard_Mkdir(void) {
    switch (D_00641FC4) {
        case 0:
            sceMcMkdir(memcardPort, memcardSlot, memcardFileName);
            D_00641FC4++;
            break;

        case 1:
            if (sceMcSync(1, NULL, &memcardResult) != 0) {
                D_00641FC4++;
            }
            break;

        case 2:
            switch (memcardResult) {
                case sceMcResSucceed:
                    memcardMkdirStatus = 0;
                    break;
                case sceMcResNoFormat: // Memory card was unformatted
                    memcardMkdirStatus = 1;
                    break;
                case sceMcResFullDevice: // Memory card is too full
                    memcardMkdirStatus = D_00641FC4;
                    break;
                case sceMcResNoEntry: // Specified directory already exists
                    memcardMkdirStatus = 3;
                    break;
                default:
                    memcardMkdirStatus = 4;
                    break;
            }
            memcardCurCmdIdx = 0;
            D_00641FE8 = D_00641FE4;
            if (D_00642044 != NULL) {
                D_00642044(D_00641FD4);
            }
    }
}

// todo: match without goto
void memcard_Create(void) {
    int iVar1;
    s32 sVar2;

    switch (D_00641FC4) {
        case 0:
            sceMcOpen(memcardPort, memcardSlot, memcardFileName, SCE_CREAT | SCE_RDWR);
            D_00641FC4++;
            break;

        case 1:
            if (sceMcSync(1, NULL, &memcardResult) != 0) {
                D_00641FC4++;
            }
            break;

        case 2:
            if (memcardResult > -1) {
                D_00641FC4 = D_00641FC4 + 1;
                D_00642040 = memcardResult;
                return;
            }
            if (memcardResult == sceMcResNoFormat) {
                memcardCreateStatus = 1;
            } else if (memcardResult == sceMcResFullDevice) {
                memcardCreateStatus = 2;
            } else if (memcardResult == sceMcResNoEntry) {
                memcardCreateStatus = 3;
            } else if (memcardResult == sceMcResDeniedPermit) {
                memcardCreateStatus = 4;
            } else if (memcardResult == sceMcResUpLimitHandle) {
                memcardCreateStatus = 5;
            } else {
                memcardCreateStatus = 7;
            }
            goto LAB_0023278c;

        case 3:
            sceMcWrite(D_00642040, D_00642038, D_0064203C);
            D_00641FC4++;
            break;

        case 4:
            if (sceMcSync(1, NULL, &memcardResult) != 0) {
                D_00641FC4++;
            }
            break;

        case 5:
            if (memcardResult >= 0) {
                if (memcardResult == D_0064203C) {
                    memcardCreateStatus = 0;
                } else {
                    memcardCreateStatus = 6;
                }
            } else {
                if (memcardResult == sceMcResNoFormat) {
                    memcardCreateStatus = 1;
                } else if (memcardResult == sceMcResFullDevice) {
                    memcardCreateStatus = 2;
                } else if (memcardResult == sceMcResNoEntry) {
                    memcardCreateStatus = 5;
                } else if (memcardResult == sceMcResDeniedPermit) {
                    memcardCreateStatus = 4;
                } else if (memcardResult == sceMcResFailReplace) {
                    memcardCreateStatus = 6;
                } else {
                    memcardCreateStatus = 7;
                }
            }
            D_00641FC4++;
            return;

        case 6:
            sceMcClose(D_00642040);
            D_00641FC4++;
            break;

        case 7:
            if (sceMcSync(1, NULL, &memcardResult) == 0) {
                return;
            }
        LAB_0023278c:
            memcardCurCmdIdx = 0;
            D_00641FE8 = D_00641FE4;
            if (D_00642044 != NULL) {
                D_00642044(D_00641FD4);
            }
    }
}

void memcard_Delete(void) {
    switch (D_00641FC4) {
        case 0:
            sceMcDelete(memcardPort, memcardSlot, memcardFileName);
            D_00641FC4++;
            break;

        case 1:
            if (sceMcSync(1, NULL, &memcardResult) != 0) {
                D_00641FC4++;
            }
            break;

        case 2:
            switch (memcardResult) {
                case sceMcResSucceed:
                    memcardDeleteStatus = 0;
                    break;
                case sceMcResNoFormat:
                    memcardDeleteStatus = 1;
                    break;
                case sceMcResNoEntry:
                    memcardDeleteStatus = 2;
                    break;
                case sceMcResDeniedPermit:
                    memcardDeleteStatus = 3;
                    break;
                case sceMcResNotEmpty:
                    memcardDeleteStatus = 4;
                    break;
                default:
                    memcardDeleteStatus = 5;
                    break;
            }
            memcardCurCmdIdx = 0;
            D_00641FE8 = D_00641FE4;
            if (D_00642044 != NULL) {
                D_00642044(D_00641FD4);
            }
    }
}

// todo: match without goto
void memcard_Read(void) {
    switch (D_00641FC4) {
        case 0:
            sceMcOpen(memcardPort, memcardSlot, memcardFileName, SCE_RDONLY);
            D_00641FC4++;
            return;

        case 1:
            if (sceMcSync(1, NULL, &memcardResult) != 0) {
                D_00641FC4++;
            }
            return;

        case 2:
            if (memcardResult > -1) {
                D_00641FC4++;
                D_00642040 = memcardResult;
                return;
            }
            if (memcardResult == sceMcResNoFormat) {
                memcardReadStatus = 1;
            } else if (memcardResult == sceMcResFullDevice) {
                memcardReadStatus = 2;
            } else if (memcardResult == sceMcResNoEntry) {
                memcardReadStatus = 3;
            } else if (memcardResult == sceMcResDeniedPermit) {
                memcardReadStatus = 4;
            } else if (memcardResult == sceMcResUpLimitHandle) {
                memcardReadStatus = 5;
            } else {
                memcardReadStatus = 7;
            }
            goto LAB_00232bac;

        case 3:
            sceMcRead(D_00642040, D_00642038, D_0064203C);
            D_00641FC4++;
            return;

        case 4:
            if (sceMcSync(1, NULL, &memcardResult) != 0) {
                D_00641FC4++;
            }
            return;

        case 5:
            if (memcardResult >= sceMcResSucceed) {
                if (memcardResult == D_0064203C) {
                    memcardReadStatus = 0;
                } else {
                    memcardReadStatus = 6;
                }
            } else {
                if (memcardResult == sceMcResNoFormat) {
                    memcardReadStatus = 1;
                } else if (memcardResult == sceMcResFullDevice) {
                    memcardReadStatus = 6;
                } else if (memcardResult == sceMcResNoEntry) {
                    memcardReadStatus = 5;
                } else if (memcardResult == sceMcResDeniedPermit) {
                    memcardReadStatus = 4;
                } else {
                    memcardReadStatus = 7;
                }
            }
            D_00641FC4++;
            return;

        case 6:
            sceMcClose(D_00642040);
            D_00641FC4++;
            return;

        case 7:
            if (sceMcSync(1, NULL, &memcardResult) == 0) {
                return;
            }
        LAB_00232bac:
            memcardCurCmdIdx = 0;
            D_00641FE8 = D_00641FE4;
            if (D_00642044 != NULL) {
                D_00642044(D_00641FD4);
            }
    }
}

// todo: match without goto
void memcard_Write(void) {
    switch (D_00641FC4) {
        case 0:
            sceMcOpen(memcardPort, memcardSlot, memcardFileName, 2);
            D_00641FC4++;
            return;

        case 1:
            if (sceMcSync(1, NULL, &memcardResult) != 0) {
                D_00641FC4++;
            }
            return;

        case 2:
            if (memcardResult > -1) {
                D_00641FC4++;
                D_00642040 = memcardResult;
                return;
            }
            if (memcardResult == sceMcResNoFormat) {
                memcardWriteStatus = 1;
            } else if (memcardResult == sceMcResFullDevice) {
                memcardWriteStatus = 2;
            } else if (memcardResult == sceMcResNoEntry) {
                memcardWriteStatus = 3;
            } else if (memcardResult == sceMcResDeniedPermit) {
                memcardWriteStatus = 4;
            } else if (memcardResult == sceMcResUpLimitHandle) {
                memcardWriteStatus = 5;
            } else {
                memcardWriteStatus = 7;
            }
            goto LAB_00232bac;

        case 3:
            sceMcWrite(D_00642040, D_00642038, D_0064203C);
            D_00641FC4++;
            return;

        case 4:
            if (sceMcSync(1, NULL, &memcardResult) != 0) {
                D_00641FC4++;
            }
            return;

        case 5:
            if (memcardResult >= 0) {
                if (memcardResult == D_0064203C) {
                    memcardWriteStatus = 0;
                } else {
                    memcardWriteStatus = 6;
                }
            } else {
                if (memcardResult == sceMcResNoFormat) {
                    memcardWriteStatus = 1;
                } else if (memcardResult == sceMcResFullDevice) {
                    memcardWriteStatus = 2;
                } else if (memcardResult == sceMcResNoEntry) {
                    memcardWriteStatus = 5;
                } else if (memcardResult == sceMcResDeniedPermit) {
                    memcardWriteStatus = 4;
                } else if (memcardResult == sceMcResFailReplace) {
                    memcardWriteStatus = 6;
                } else {
                    memcardWriteStatus = 7;
                }
            }
            D_00641FC4++;
            return;

        case 6:
            sceMcClose(D_00642040);
            D_00641FC4++;
            return;

        case 7:
            if (sceMcSync(1, NULL, &memcardResult) == 0) {
                return;
            }
        LAB_00232bac:
            memcardCurCmdIdx = 0;
            D_00641FE8 = D_00641FE4;
            if (D_00642044 != NULL) {
                D_00642044(D_00641FD4);
            }
    }
}

void memcard_Rename(void) {
    switch (D_00641FC4) {
        case 0:
            sceMcRename(memcardPort, memcardSlot, memcardFileName, memcardNewFileName);
            D_00641FC4++;
            break;

        case 1:
            if (sceMcSync(1, NULL, &memcardResult) != 0) {
                D_00641FC4++;
            }
            break;

        case 2:
            if (memcardResult == sceMcResSucceed) {
                memcardRenameStatus = 0;
            } else if (memcardResult == sceMcResNoFormat) {
                memcardRenameStatus = 1;
            } else if (memcardResult == sceMcResNoEntry) {
                memcardRenameStatus = D_00641FC4;
            } else {
                memcardRenameStatus = 3;
            }
            memcardCurCmdIdx = 0;
            D_00641FE8 = D_00641FE4;
            if (D_00642044 != NULL) {
                D_00642044(D_00641FD4);
            }
    }
}

void func_00232FF8(void) {
    memcardCurCmdIdx = 0;
    D_00641FE8 = D_00641FE4;
    D_0064202C = D_00642044(D_00641FD4);
}

void memcard_RunCommand(void) {
    memcardCommands[memcardCurCmdIdx]();
}
