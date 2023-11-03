#include "common.h"
#include "sifrpc.h"

s32 D_003DE5B8;
sceSifClientData D_003DE5C0;

char D_0048A578[]; // "sound:cue buff over\n";

s32 D_00639880;
void* D_0062D980;
void* D_0062D984;
void* D_0062D988;
void* D_0062D98C;

INCLUDE_ASM(const s32, "xquack", func_001EE0B8);

void* func_001EE188(void* arg0) {
    D_0062D980 = arg0;
    sceSifCallRpc(&D_003DE5C0, 1, 0, &D_0062D980, 0x2000, &D_0062D980, 0x2000, NULL, NULL);
    return D_0062D980;
}

void* func_001EE1E0(void* arg0, void* arg1) {
    func_001EE0B8(38, arg0, arg1, 0, 0, 0, 0, 0);
    return D_0062D980;
}

INCLUDE_ASM(const s32, "xquack", func_001EE228);

INCLUDE_ASM(const s32, "xquack", func_001EE280);

void* func_001EE2D8(void* arg0, void* arg1, void* arg2) {
    D_00639880 += 1;
    func_001EE0B8(4, arg0, arg1, arg2, 0, 0, 0, 0);
    return D_0062D980;
}

INCLUDE_ASM(const s32, "xquack", func_001EE330);

INCLUDE_ASM(const s32, "xquack", func_001EE390);

INCLUDE_ASM(const s32, "xquack", func_001EE3D8);

void* func_001EE428(void* arg0, void* arg1, void* arg2, s32 arg3, s32 arg4) {
    func_001EE0B8(7, arg0, arg1, arg2, arg3, arg4, 0, 0);
    return D_0062D980;
}

void* func_001EE478(void* arg0, void* arg1, void* arg2, s32 arg3, s32 arg4) {
    func_001EE0B8(8, arg0, arg1, arg2, arg3, arg4, 0, 0);
    return D_0062D980;
}

INCLUDE_ASM(const s32, "xquack", func_001EE4C8);

void* func_001EE518(void* arg0, void* arg1, void* arg2) {
    D_00639880 += 1;
    func_001EE0B8(11, arg0, arg1, arg2, 0, 0, 0, 0);
    return D_0062D980;
}

INCLUDE_ASM(const s32, "xquack", func_001EE570);

void* func_001EE5D8(void* arg0) {
    func_001EE0B8(13, arg0, 0, 0, 0, 0, 0, 0);
    return D_0062D980;
}

INCLUDE_ASM(const s32, "xquack", func_001EE618);

void* func_001EE660(void* arg0) {
    D_0062D980 = arg0;
    sceSifCallRpc(&D_003DE5C0, 47, 0, &D_0062D980, 0x2000, &D_0062D980, 0x2000, NULL, NULL);
    return D_0062D980;
}

void* func_001EE6B8(void* arg0) {
    D_0062D980 = arg0;
    sceSifCallRpc(&D_003DE5C0, 48, 0, &D_0062D980, 0x2000, &D_0062D980, 0x2000, NULL, NULL);
    return D_0062D980;
}

void* func_001EE710(void* arg0, void* arg1, void* arg2) {
    D_00639880 += 1;
    func_001EE0B8(3, arg0, arg1, arg2, 0, 0, 0, 0);
    return D_0062D980;
}

void* func_001EE768(void* arg0) {
    func_001EE0B8(19, arg0, 0, 0, 0, 0, 0, 0);
    return D_0062D980;
}

INCLUDE_ASM(const s32, "xquack", func_001EE7A8);

INCLUDE_ASM(const s32, "xquack", func_001EE7F0);

void* func_001EE838(void* arg0, void* arg1, void* arg2) {
    D_00639880 += 1;
    func_001EE0B8(40, arg0, arg1, arg2, 0, 0, 0, 0);
    return D_0062D980;
}

INCLUDE_ASM(const s32, "xquack", func_001EE890);

void* func_001EE8E0(void* arg0, void* arg1) {
    func_001EE0B8(43, arg0, arg1, 0, 0, 0, 0, 0);
    return D_0062D980;
}

void* func_001EE928() {
    sceSifCallRpc(&D_003DE5C0, 22, 0, &D_0062D980, 0x2000, &D_0062D980, 0x2000, NULL, NULL);
    return D_0062D980;
}

void* func_001EE980(void* arg0) {
    D_0062D980 = arg0;
    sceSifCallRpc(&D_003DE5C0, 23, 0, &D_0062D980, 0x2000, &D_0062D980, 0x2000, NULL, NULL);
    return D_0062D980;
}

void* func_001EE9D8() {
    sceSifCallRpc(&D_003DE5C0, 24, 0, &D_0062D980, 0x2000, &D_0062D980, 0x2000, NULL, NULL);
    return D_0062D980;
}

INCLUDE_ASM(const s32, "xquack", func_001EEA30);

void* func_001EEA98() {
    sceSifCallRpc(&D_003DE5C0, 27, 0, &D_0062D980, 0x2000, &D_0062D980, 0x2000, NULL, NULL);
    return D_0062D980;
}

void* func_001EEAF0(void* arg0) {
    D_0062D980 = arg0;
    sceSifCallRpc(&D_003DE5C0, 29, 0, &D_0062D980, 0x2000, &D_0062D980, 0x2000, NULL, NULL);
    return D_0062D980;
}

INCLUDE_ASM(const s32, "xquack", func_001EEB48);

void* func_001EEBA8(void* arg0) {
    D_0062D980 = arg0;
    sceSifCallRpc(&D_003DE5C0, 35, 0, &D_0062D980, 0x2000, &D_0062D980, 0x2000, NULL, NULL);
    return D_0062D980;
}

void* func_001EEC00(void* arg0) {
    D_0062D980 = arg0;
    sceSifCallRpc(&D_003DE5C0, 36, 0, &D_0062D980, 0x2000, &D_0062D980, 0x2000, NULL, NULL);
    return D_0062D980;
}

INCLUDE_ASM(const s32, "xquack", func_001EEC58);
