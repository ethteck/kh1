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
s32 D_0041F920[2][4] = {};
s32 D_0041F940[2][4] = {};
s32 D_0041F960[2][4] = {};
s32 D_0041F980[2][4] = {};

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
// Commands are executed in a loop, altering behavior based on the current step
s32 memcardLoopStep;
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
void* memcardFileBuffer;
s32 memcardFileSize;
s32 memcardFileHandle;
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
    s32 iVar1 = D_0041F940[port][slot];
    D_0041F940[port][slot] = 0;
    return iVar1;
}

void func_002309C8(s32 port, s32 slot) {
    D_0041F940[port][slot] = 0;
}

s32 func_002309E8(s32 port, s32 slot) {
    s32 iVar1 = D_0041F960[port][slot];
    D_0041F960[port][slot] = 0;
    return iVar1;
}

void func_00230A10(s32 port, s32 slot) {
    D_0041F960[port][slot] = 0;
}

s32 func_00230A30(s32 port, s32 slot) {
    s32 iVar1 = D_0041F980[port][slot];
    D_0041F980[port][slot] = 0;
    return iVar1;
}

void func_00230A58(s32 port, s32 slot) {
    D_0041F980[port][slot] = 0;
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
    switch (memcardLoopStep) {
        case 0: // Examine the memory card status
            sceMcGetInfo(memcardPort, memcardSlot, &memcardType, &memcardFree, &memcardFormat);
            memcardLoopStep++;
            break;

        case 1: // Wait for sceMcGetInfo to finish
            if (sceMcSync(1, NULL, &memcardResult) != sceMcExecRun) {
                memcardLoopStep++;
            }
            break;

        case 2: // Check the result of the memory card status
            if (memcardType == sceMcTypePDA) {
                D_0041F920[memcardPort][memcardSlot] = 3;
            } else {
                switch (memcardResult) {
                    case sceMcResSucceed: // Same card has been used continuously
                        D_00641FF8[1] = 0;
                        D_0041F920[memcardPort][memcardSlot] = 0;
                        break;

                    case sceMcResChangedCard: // Card has since been changed to a formatted card
                        D_00641FF8[1] = 0;
                        D_0041F920[memcardPort][memcardSlot] = 1;
                        D_0041F940[memcardPort][memcardSlot] = 1;
                        D_0041F960[memcardPort][memcardSlot] = 1;
                        break;

                    case sceMcResNoFormat: // Card has since been changed to an unformatted card
                        D_00641FF8[1] = 0;
                        D_0041F920[memcardPort][memcardSlot] = 2;
                        D_0041F940[memcardPort][memcardSlot] = 1;
                        D_0041F960[memcardPort][memcardSlot] = 1;
                        break;

                    default: // Card could not be accessed or detected
                        D_0041F920[memcardPort][memcardSlot] = 3;
                        if (D_00641FF8[1] == 0) {
                            D_0041F940[memcardPort][memcardSlot] = 1;
                            D_0041F980[memcardPort][memcardSlot] = 1;
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
    switch (memcardLoopStep) {
        case 0: // Get all files on the memory card
            sceMcGetDir(memcardPort, memcardSlot, "*", 0, memcardEntries, memcardFileBuf);
            memcardLoopStep++;
            break;

        case 1: // Wait for sceMcGetDir to finish
            if (sceMcSync(1, NULL, &memcardResult) != sceMcExecRun) {
                memcardLoopStep++;
            }
            break;

        case 2: // Result contains number of entries obtained, negative if it won't write to table
            if (memcardResult >= 0) {
                memcardEntries = memcardResult;
                memcardGetAllStatus = 0;
            } else {
                if (memcardResult == sceMcResNoFormat) {
                    memcardEntries = -1;
                    memcardGetAllStatus = 1;
                } else if (memcardResult == sceMcResNoEntry) {
                    memcardEntries = -1;
                    memcardGetAllStatus = 2;
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
    switch (memcardLoopStep) {
        case 0: // Get files in the specified directory
            sceMcGetDir(memcardPort, memcardSlot, memcardFileName, 0, memcardEntries, memcardFileBuf);
            memcardLoopStep++;
            break;

        case 1: // Wait for sceMcGetDir to finish
            if (sceMcSync(1, NULL, &memcardResult) != sceMcExecRun) {
                memcardLoopStep++;
            }
            break;

        case 2: // Result contains number of entries obtained, negative if it won't write to table
            if (memcardResult >= 0) {
                memcardEntries = memcardResult;
                memcardGetDirStatus = 0;
            } else {
                if (memcardResult == sceMcResNoFormat) {
                    memcardEntries = -1;
                    memcardGetDirStatus = 2;
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

void memcard_Format(void) {
    switch (memcardLoopStep) {
        case 0: // Format the memory card
            sceMcFormat(memcardPort, memcardSlot);
            memcardLoopStep++;
            break;

        case 1: // Wait for sceMcFormat to finish
            if (sceMcSync(1, NULL, &memcardResult) != sceMcExecRun) {
                memcardLoopStep++;
            }
            break;

        case 2: // Check the result of the format
            if (memcardResult != sceMcResSucceed) {
                if (D_00641FDC != 0) {
                    D_00641FDC--;
                    D_00641FE0 = 60;
                    memcardLoopStep = 3;
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
            memcardLoopStep = 0;
    }
}

void memcard_Unformat(void) {
    switch (memcardLoopStep) {
        case 0: // Erase memory card formatting
            sceMcUnformat(memcardPort, memcardSlot);
            memcardLoopStep++;
            break;

        case 1: // Wait for sceMcUnformat to finish
            if (sceMcSync(1, NULL, &memcardResult) != sceMcExecRun) {
                memcardLoopStep++;
            }
            break;

        case 2: // Check the result of the unformat
            if (memcardResult != sceMcResSucceed) {
                if (D_00641FDC != 0) {
                    D_00641FDC--;
                    D_00641FE0 = 60;
                    memcardLoopStep = 3;
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
            memcardLoopStep = 0;
    }
}

void memcard_Chdir(void) {
    switch (memcardLoopStep) {
        case 0: // Change the current working directory
            sceMcChdir(memcardPort, memcardSlot, memcardFileName, memcardDirStore);
            memcardLoopStep++;
            break;

        case 1: // Wait for sceMcChdir to finish
            if (sceMcSync(1, NULL, &memcardResult) != sceMcExecRun) {
                memcardLoopStep++;
            }
            break;

        case 2: // Check the result of the chdir
            switch (memcardResult) {
                case sceMcResSucceed: // Directory was changed successfully
                    memcardChdirStatus = 0;
                    break;
                case sceMcResNoFormat: // Memory card was unformatted
                    memcardChdirStatus = 1;
                    break;
                case sceMcResNoEntry: // Specified directory does not exist
                    memcardChdirStatus = 2;
                    break;
                default: // Memory card could not be accessed or detected
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
    switch (memcardLoopStep) {
        case 0: // Create a new directory
            sceMcMkdir(memcardPort, memcardSlot, memcardFileName);
            memcardLoopStep++;
            break;

        case 1: // Wait for sceMcMkdir to finish
            if (sceMcSync(1, NULL, &memcardResult) != sceMcExecRun) {
                memcardLoopStep++;
            }
            break;

        case 2: // Check the result of the mkdir
            switch (memcardResult) {
                case sceMcResSucceed: // Directory was created successfully
                    memcardMkdirStatus = 0;
                    break;
                case sceMcResNoFormat: // Memory card was unformatted
                    memcardMkdirStatus = 1;
                    break;
                case sceMcResFullDevice: // Memory card is too full
                    memcardMkdirStatus = 2;
                    break;
                case sceMcResNoEntry: // Specified directory already exists
                    memcardMkdirStatus = 3;
                    break;
                default: // Memory card could not be accessed or detected
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

    switch (memcardLoopStep) {
        case 0: // Open the file
            sceMcOpen(memcardPort, memcardSlot, memcardFileName, SCE_CREAT | SCE_RDWR);
            memcardLoopStep++;
            break;

        case 1: // Wait for sceMcOpen to finish
            if (sceMcSync(1, NULL, &memcardResult) != sceMcExecRun) {
                memcardLoopStep++;
            }
            break;

        case 2: // Store the file handle
            if (memcardResult > -1) {
                memcardLoopStep++;
                memcardFileHandle = memcardResult;
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

        case 3: // Write to the file
            sceMcWrite(memcardFileHandle, memcardFileBuffer, memcardFileSize);
            memcardLoopStep++;
            break;

        case 4: // Wait for sceMcWrite to finish
            if (sceMcSync(1, NULL, &memcardResult) != sceMcExecRun) {
                memcardLoopStep++;
            }
            break;

        case 5: // Check the result of the write
            if (memcardResult >= 0) {
                if (memcardResult == memcardFileSize) {
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
            memcardLoopStep++;
            return;

        case 6: // Close the file
            sceMcClose(memcardFileHandle);
            memcardLoopStep++;
            break;

        case 7: // Block until sceMcClose is finished
            if (sceMcSync(1, NULL, &memcardResult) == sceMcExecRun) {
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
    switch (memcardLoopStep) {
        case 0: // Delete the file or directory
            sceMcDelete(memcardPort, memcardSlot, memcardFileName);
            memcardLoopStep++;
            break;

        case 1: // Wait for sceMcDelete to finish
            if (sceMcSync(1, NULL, &memcardResult) != sceMcExecRun) {
                memcardLoopStep++;
            }
            break;

        case 2: // Check the result of the delete
            switch (memcardResult) {
                case sceMcResSucceed: // File or directory was deleted successfully
                    memcardDeleteStatus = 0;
                    break;
                case sceMcResNoFormat: // Memory card was unformatted
                    memcardDeleteStatus = 1;
                    break;
                case sceMcResNoEntry: // Specified file or directory does not exist
                    memcardDeleteStatus = 2;
                    break;
                case sceMcResDeniedPermit: // File or directory could not be deleted
                    memcardDeleteStatus = 3;
                    break;
                case sceMcResNotEmpty: // Directory is not empty
                    memcardDeleteStatus = 4;
                    break;
                default: // Memory card could not be accessed or detected
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
    switch (memcardLoopStep) {
        case 0: // Open the file
            sceMcOpen(memcardPort, memcardSlot, memcardFileName, SCE_RDONLY);
            memcardLoopStep++;
            return;

        case 1: // Wait for sceMcOpen to finish
            if (sceMcSync(1, NULL, &memcardResult) != sceMcExecRun) {
                memcardLoopStep++;
            }
            return;

        case 2: // Store the file handle
            if (memcardResult > -1) {
                memcardLoopStep++;
                memcardFileHandle = memcardResult;
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

        case 3: // Read from the file
            sceMcRead(memcardFileHandle, memcardFileBuffer, memcardFileSize);
            memcardLoopStep++;
            return;

        case 4: // Wait for sceMcRead to finish
            if (sceMcSync(1, NULL, &memcardResult) != sceMcExecRun) {
                memcardLoopStep++;
            }
            return;

        case 5: // Check the result of the read
            if (memcardResult >= sceMcResSucceed) {
                if (memcardResult == memcardFileSize) {
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
            memcardLoopStep++;
            return;

        case 6: // Close the file
            sceMcClose(memcardFileHandle);
            memcardLoopStep++;
            return;

        case 7: // Block until sceMcClose is finished
            if (sceMcSync(1, NULL, &memcardResult) == sceMcExecRun) {
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
    switch (memcardLoopStep) {
        case 0: // Open the file
            sceMcOpen(memcardPort, memcardSlot, memcardFileName, 2);
            memcardLoopStep++;
            return;

        case 1: // Wait for sceMcOpen to finish
            if (sceMcSync(1, NULL, &memcardResult) != sceMcExecRun) {
                memcardLoopStep++;
            }
            return;

        case 2: // Store the file handle
            if (memcardResult > -1) {
                memcardLoopStep++;
                memcardFileHandle = memcardResult;
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

        case 3: // Write to the file
            sceMcWrite(memcardFileHandle, memcardFileBuffer, memcardFileSize);
            memcardLoopStep++;
            return;

        case 4: // Wait for sceMcWrite to finish
            if (sceMcSync(1, NULL, &memcardResult) != sceMcExecRun) {
                memcardLoopStep++;
            }
            return;

        case 5: // Check the result of the write
            if (memcardResult >= 0) {
                if (memcardResult == memcardFileSize) {
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
            memcardLoopStep++;
            return;

        case 6: // Close the file
            sceMcClose(memcardFileHandle);
            memcardLoopStep++;
            return;

        case 7: // Block until sceMcClose is finished
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
    switch (memcardLoopStep) {
        case 0: // Rename the file
            sceMcRename(memcardPort, memcardSlot, memcardFileName, memcardNewFileName);
            memcardLoopStep++;
            break;

        case 1: // Wait for sceMcRename to finish
            if (sceMcSync(1, NULL, &memcardResult) != sceMcExecRun) {
                memcardLoopStep++;
            }
            break;

        case 2: // Check the result of the rename
            if (memcardResult == sceMcResSucceed) {
                memcardRenameStatus = 0;
            } else if (memcardResult == sceMcResNoFormat) {
                memcardRenameStatus = 1;
            } else if (memcardResult == sceMcResNoEntry) {
                memcardRenameStatus = 2;
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
