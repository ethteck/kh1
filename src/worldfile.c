/**
 * Provider for handling file names and extensions for world and room data files
 */

#include "common.h"
#include "worldfile.h"

#include "stdio.h"
#include "string.h"

// Loaded world/room index?
extern s32 D_002B8678;

extern s32 D_002B8680;

/**
 * World abbreviations used for file names
 * al - Agrabah
 * aw - Wonderland
 * dc - Disney Castle
 * dh - Dive to the Heart
 * di - Destiny Islands
 * ew - End of the World
 * he - Olympus Coliseum
 * lm - Atlantica
 * nm - Halloween Town
 * pc - Hollow Bastion
 * pi - Monstro
 * po - 100 Acre Wood
 * pp - Neverland
 * tw - Traverse Town
 * tz - Deep Jungle
 * xx - Unknown/Unused
 * zz - Miscellanous
 */
const char* worldAbbrs[21] = {
    "dh", "di", "dc", "tw", "aw", "tz", "po", "xx", "al", "lm", "nm",
    "he", "pi", "pp", "xx", "pc", "ew", "xx", "xx", "xx", "zz",
};

char worldDataExt[] = ".wdt";
char roomArchiveExt[] = ".ard";

s32 D_002B91E0 = 0;
s32 D_002B91E4 = 0;
s32 D_002B91E8 = 0;
s32 D_002B91EC = 0;

char worldDataFile[0x40] = {};
char worldBinImgFile[0x40] = {};
char roomArchiveRaw[0x40] = {};
char roomArchiveFile[0x40] = {};

const char* worldfile_getAbbr(int idx, char* dest) {
    return strcpy(dest, worldAbbrs[idx]);
}

char* worldfile_getNameNoSet(s32 idx, s32 fileidx, UNK_TYPE arg2, char* dest) {
    char filenum[0x10];
    char abbr[0x40];

    worldfile_getAbbr(idx, abbr);
    sprintf(filenum, "%2d", fileidx + 1);
    if (filenum[0] == ' ') {
        filenum[0] = '0';
    }
    strcpy(dest, abbr);
    return strcat(dest, filenum);
}

char* worldfile_getNames() {
    char filenum[0x10];
    char abbr[0x40];

    worldfile_getAbbr(D_002B8678, abbr);
    sprintf(filenum, "%2d", D_002B8680 + 1);
    if (filenum[0] == ' ') {
        filenum[0] = '0';
    }
    strcpy(worldDataFile, abbr);
    strcat(worldDataFile, worldDataExt);
    strcpy(roomArchiveFile, abbr);
    strcat(roomArchiveFile, filenum);
    strcat(roomArchiveFile, roomArchiveExt);
    strcpy(roomArchiveRaw, abbr);
    return strcat(roomArchiveRaw, filenum);
}

char* worldfile_getBinImgName(s32 arg0) {
    char filenum[0x10];
    char abbr[0x40];

    worldfile_getAbbr(D_002B8678, abbr);
    sprintf(filenum, "%2d", arg0 + 1);
    if (filenum[0] == ' ') {
        filenum[0] = '0';
    }
    strcpy(worldBinImgFile, abbr);
    strcat(worldBinImgFile, "00_");
    return strcat(worldBinImgFile, filenum);
}
