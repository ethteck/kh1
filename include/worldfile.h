#ifndef WORLDFILE_H
#define WORLDFILE_H

#include "common.h"

// Load the world abbreviation selected by index into a destination buffer
const char* worldfile_getAbbr(int idx, char* dest);

// Get the name of a world/room file without setting any global variables
char* worldfile_getNameNoSet(s32 idx, s32, s32, char* dest);

// Set world and room file names in global variables and return the raw name
char* worldfile_getNames(void);

// Get the name of binary/image data files for a world/room
char* worldfile_getBinImgName(s32);

// World data file name (eg: `al.wdt`)
char worldDataFile[0x40];

// World binary/image file name without extension (eg: `al00_01`)
char worldBinImgFile[0x40];

// Room archive file name (eg: `al01.ard`)
char roomArchiveFile[0x40];

#endif // WORLDFILE_H
