#include "common.h"

void memcard_Initialize(void);

s32 memcard_GetAllStatus(void);
s32 memcard_GetDirStatus(void);
s32 memcard_GetFormatStatus(void);
s32 memcard_GetUnformatStatus(void);
s32 memcard_GetChdirStatus(void);
s32 memcard_GetMkdirStatus(void);
s32 memcard_GetCreateStatus(void);
s32 memcard_GetDeleteStatus(void);
s32 memcard_GetReadStatus(void);
s32 memcard_GetWriteStatus(void);
s32 memcard_GetRenameStatus(void);

void func_00231370(void);
void memcard_GetInfo(void);
void memcard_GetAllFiles(void);
void memcard_GetDirFiles(void);
void memcard_Format(void);
void memcard_Unformat(void);
void memcard_Chdir(void);
void memcard_Mkdir(void);
void memcard_Create(void);
void memcard_Delete(void);
void memcard_Read(void);
void memcard_Write(void);
void memcard_Rename(void);
void func_00232FF8(void);
