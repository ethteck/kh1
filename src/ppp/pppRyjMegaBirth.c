#include "ppp.h"

typedef struct {
    /* 0x00 */ FMATRIX matPar;
    /* 0x40 */ pppFVECTOR vecForce;
    /* 0x50 */ void* pvParticleData;
    /* 0x54 */ void* pvParticleWmat;
    /* 0x58 */ void* pvParticleColor;
    /* 0x5C */ u32 nParticle;
    /* 0x60 */ u16 ushTimingCt;
    /* 0x62 */ u16 ushIct;
    /* 0x64 */ u8 unk_64;
    /* 0x65 */ u8 unk_65;
    /* 0x66 */ u8 unk_66;
    /* 0x67 */ u8 unk_67;
    /* 0x68 */ u8 unk_68;
    /* 0x69 */ u8 unk_69;
    /* 0x6A */ u8 unk_6A;
    /* 0x6B */ u8 unk_6B;
    /* 0x6C */ u8 unk_6C;
    /* 0x6D */ u8 unk_6D;
    /* 0x6E */ u8 unk_6E;
    /* 0x6F */ u8 unk_6F;
} VRyjMegaBirth;

INCLUDE_ASM(const s32, "ppp/pppRyjMegaBirth", pppRyjMegaBirthCalc);

INCLUDE_ASM(const s32, "ppp/pppRyjMegaBirth", func_0019ECE8);

INCLUDE_ASM(const s32, "ppp/pppRyjMegaBirth", func_0019ED48);

INCLUDE_ASM(const s32, "ppp/pppRyjMegaBirth", pppRyjMegaBirthDraw);

INCLUDE_ASM(const s32, "ppp/pppRyjMegaBirth", pppRyjMegaBirthCon);

INCLUDE_ASM(const s32, "ppp/pppRyjMegaBirth", pppRyjMegaBirthDes);
