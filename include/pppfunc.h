#ifndef PPPFUNC_H
#define PPPFUNC_H

#include "common.h"

typedef f32 FMATRIX[4][4]; // size = 0x40

typedef struct {
    s32 time;
} pppCDT;

typedef struct {
    s16 x, y, z;
} pppSVECTOR; // size = 0x6

typedef struct {
    f32 x, y, z;
} pppFVECTOR; // size = 0xC

typedef struct {
    s32 x, y, z;
} pppIVECTOR; // size = 0xC

typedef struct {
    s16 r, g, b, a;
} pppHCVECTOR; // size = 0x8

typedef struct {
    u8 r, g, b, a;
} pppCVECTOR; // size = 0x4

typedef struct {
    /* 0x00 */ const char* progName;
    /* 0x04 */ void* calcFunc;
    /* 0x08 */ void* dektFunc;
    /* 0x0C */ void* drawFunc;
    /* 0x10 */ void* iniFunc;
    /* 0x14 */ void* staFunc;
    /* 0x18 */ void* endFunc;
    /* 0x1C */ void* conFunc;
    /* 0x20 */ void* con2Func;
    /* 0x24 */ void* desFunc;
} pppProg; // size = 0x28

typedef struct {
    /* 0x00 */ s32 time;
    /* 0x04 */ char dt[0];
} pppCtrlData; // size = 4 + ?

typedef struct {
    /* 0x00 */ struct pppProg* prog;
    /* 0x04 */ u16 dtbytes;
    /* 0x06 */ u16 ctrldtn;
    /* 0x08 */ pppCtrlData* ctrldt;
    /* 0x0C */ s32* useVal;
} pppCtrlTable; // size = 0x10

typedef struct _pppPData {
    /* 0x00 */ struct _pppPData* next;
    /* 0x04 */ u64* cvoff;
    /* 0x0C */ u32 flag;
    /* 0x10 */ u32 status;
    /* 0x14 */ s32 startFrameInit;
    /* 0x18 */ s32 totalFrame;
    /* 0x1C */ s32 loopFrame0;
    /* 0x20 */ s32 loopFrame1;
    /* 0x24 */ s32 valbytes;
    /* 0x28 */ s16 prio;
    /* 0x2A */ s16 ctrlTablen;
    /* 0x2C */ pppCtrlTable ctrlTable[0];
} pppPData; // size = 0x30 + ?

typedef struct {
    /* 0x00 */ pppPData* pdt;
    /* 0x04 */ struct _pppPObject* pobj;
    /* 0x08 */ s32 startFrame;
    /* 0x0C */ u16 pobjn;
    /* 0x0E */ u8 pdtno;
    /* 0x0F */ u8 cdummy[1];
} pppPDataVal;

typedef struct _pppPObject {
    /* 0x00 */ struct _pppPObject* next;
    /* 0x04 */ struct _pppPObject* ppobj;
    /* 0x08 */ pppPDataVal* pdtval;
    /* 0x0C */ s32 time;
    /* 0x10 */ FMATRIX cmat;
    /* 0x50 */ FMATRIX dmat;
    /* 0x90 */ pppSVECTOR* lpvert;
    /* 0x94 */ pppSVECTOR* lpnorm;
    /* 0x98 */ pppCtrlData** lpcdt;
    /* 0x9C */ u8 appearf;
    /* 0x9D */ u8 loop_in;
    /* 0x9E */ u8 loop_start0;
    /* 0x9F */ u8 dummy[1];
    /* 0xA0 */ char val[0];
} pppPObject; // size = 0xA0

typedef struct {
    /* 0x0 */ s32 pdtn;
    /* 0x4 */ s32 valoff;
} pppParamPObj; // size = 0x8

#endif
