#include "common.h"
#include "ppp.h"
#include "ppp/draw.h"

extern sceVu0FMATRIX D_002B84F0;

s32 D_0035FE00;

pppModelSt RendModel[128]; // = {};
pppShapeSt RendShape[128]; // = {};
pppVsfSt RendVsf[128];     // = {};
ppvmng D_00360600[0x100];  // = {};

s16 D_0036C5C6[];
s32 D_0036C600;

u8 D_00590580[];

s32 ppvCurPrimpLen;
u_long128* ppvPrimp;
s32 ppvPrimpLen;

u_long128 D_00570580;
pppSVECTOR* ppvVertex;

void pppSetPrimPacket(u_long128* primPacketArea, s32 len) {
    if (primPacketArea != NULL) {
        ppvPrimp = primPacketArea;
        ppvPrimpLen = len;
    } else {
        ppvPrimp = &D_00570580;
        ppvPrimpLen = 0x20000;
    }
}

void drawStart(void) {
    ppvVertex = NULL;
}

s32 pppDbgAlloc(s32 arg0, s32 arg1) {
    return pppAlloc(arg0, arg1);
}

void drawEnd(void) {
    if (ppvCurPrimpLen != 0) {
        op_ot_draw();
        op_otz_init();
    }
}

void initGraphicSystem(void) {
    op_init_draw();
    op_gs2_init();
    op_otz_init();
    op_init_fog_work();
}

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00181040);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_001810D0);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00181110);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00181150);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_001811A8);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00181200);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_001812B0);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00181340);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_001813F0);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_001814C8);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_001815A0);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00181600);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00181640);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_001817E8);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", pppSetUp);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", dpd_h_skip_version);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", dpd_h_skip_datainfo);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00181A58);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00181B38);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00181BA8);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00181C20);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00181D30);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", dpd_set_object_tex);
// void dpd_set_object_tex(ppvmng* pMng) {
//     int* piVar1;
//     short clutpStart;
//     short texpStart;

//     texpStart = pMng->texpStart;
//     clutpStart = pMng->clutpStart;
//     if ((texpStart == 0) && (clutpStart == 0)) {
//         return;
//     }
//     piVar1 = dpd_h_skip_version(pMng->pchDpd);
//     piVar1 = dpd_h_skip_datainfo(piVar1, 2);
//     piVar1 = func_00181C20(piVar1, pMng->pEtc->abUseShape, texpStart, clutpStart);
//     func_00181D30(piVar1, pMng->pEtc->abUseRsd, texpStart, clutpStart);
// }

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", dpd_set_shape_data);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", dpd_set_rsd_data);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", dpd_set_vsf_data);

s32 dpd_set_object_data(ppvmng* pMng) {
    s32* piVar1;
    s16** ppsVar2;

    piVar1 = dpd_h_skip_version(pMng->pchDpd);
    piVar1 = dpd_h_skip_datainfo(piVar1, 2);
    ppsVar2 = dpd_set_shape_data(piVar1, pMng->pEtc->abUseShape);
    ppsVar2 = dpd_set_rsd_data(ppsVar2, pMng->pEtc->abUseRsd);
    return dpd_set_vsf_data(ppsVar2, pMng->pEtc->abUseVsf);
}

void func_00182110(s32 arg0) {
    D_0036C600 = arg0;
}

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00182120);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_001821A8);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00182288);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00182348);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_001823B8);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00182478);

void vramcache_clear(_VRAMCACHE* cache) {
    cache->dpd = NULL;
    cache->dpdId = 0;
    cache->blockStart = -1;
    cache->blockNum = 0;
    cache->boolUse = FALSE;
}

void vramcachemng_clear(_VRAMCACHE_MNG* cacheMng) {
    s32 i;

    for (i = 0; i < 10; i++) {
        vramcache_clear(&cacheMng->vramCacheTex[i]);
    }

    for (i = 0; i < 6; i++) {
        vramcache_clear(&cacheMng->vramCacheClut[i]);
    }
}

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00182580);

void vramcache_texture(_VRAMCACHE_MNG* cacheMng, ppvmng* pMng) {
    s32 lVar1 = func_00182580(cacheMng, 10, pMng, pMng->unk_91);

    if (lVar1 < 0) {
        pMng->texpStart = 0;
    } else {
        pMng->texpStart = (lVar1 << 7) + 0x3800;
    }
}

void vramcache_clut(_VRAMCACHE_MNG* cacheMng, ppvmng* pMng) {
    s32 lVar1 = func_00182580(cacheMng->vramCacheClut, 6, pMng, pMng->unk_92);

    if (lVar1 < 0) {
        pMng->clutpStart = 0;
    } else {
        pMng->clutpStart = (lVar1 << 5) + 0x3D40;
    }
}

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00182938);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00182980);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_001829D0);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00182A78);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00182B18);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00182C78);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00182D90);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_001831A0);

void init_part_mng(ppvmng* pMng) {
    memset(pMng, 0, 0xC0);
    pMng->unk_00 = 0;
    pMng->usef = 9;
    pMng->unk_04 = 0.0f;
    pMng->unk_08 = 0.0f;
    pMng->unk_0C = 1.0f;
    pMng->unk_20 = 1.0f;
    pMng->unk_24 = 1.0f;
    pMng->unk_28 = 1.0f;
    pMng->unk_2C = 1.0f;
    pMng->unk_10 = 0.0f;
    pMng->unk_14 = 0.0f;
    pMng->unk_18 = 0.0f;
    pMng->unk_1C = 0.0f;
    pMng->colorR = 1.0f;
    pMng->colorG = 1.0f;
    pMng->colorB = 1.0f;
    pMng->colorA = 1.0f;
    pMng->scaleX = 1.0f;
    pMng->scaleY = 1.0f;
    pMng->unk_48 = 1.0f;
    pMng->unk_4C = 1.0f;
}

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00183658);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", pppInitPartRender);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", pppSetPartMatrix);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_001838E8);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00183980);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_001839F0);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00183A60);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00183AD0);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00183B70);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00183C10);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", pppDeletePObject);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", pppAllFreePObject);
// void pppAllFreePObject(ppvmng* pMng) {
//     pppPObject* pObj = pMng->unk_74;

//     while (pObj != NULL) {
//         pppDeletePObject(pObj);
//         pObj = pObj->next;
//     }

//     pMng->unk_74 = NULL;

//     if (pMng->unk_80 != 0) {
//         pppFree(ppvEnv, pMng->unk_80);
//         pMng->unk_80 = 0;
//     }
// }

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00183E78);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00183EC8);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00183EF8);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00184298);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_001843E0);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00184500);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00184548);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00184728);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00184DB0);

void func_00184E48(ppvmng* pMng) {
    ppvMng = pMng;
    func_001839F0(pMng);
    func_00184DB0(pMng);
    func_00184548(pMng);
}

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00184E80);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00184F60);

void func_00185000(void) {
}

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00185008);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", pppAlloc);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", pppFree);
