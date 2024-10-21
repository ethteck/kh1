#include "common.h"
#include "libvu0.h"
#include "eeregs.h"

void sceVu0ApplyMatrix(sceVu0FVECTOR v0, sceVu0FMATRIX m0, sceVu0FVECTOR v1) {
    __asm__ __volatile__("          \n\
	lqc2            vf4, 0x0(%1)    \n\
	lqc2            vf5, 0x10(%1)   \n\
	lqc2            vf6, 0x20(%1)   \n\
	lqc2            vf7, 0x30(%1)   \n\
	lqc2            vf8, 0x0(%2)    \n\
	vmulax.xyzw	    ACC, vf4,vf8    \n\
	vmadday.xyzw	ACC, vf5,vf8    \n\
	vmaddaz.xyzw	ACC, vf6,vf8    \n\
	vmaddw.xyzw	    vf9, vf7,vf8    \n\
	sqc2            vf9,0x0(%0)     \n\
	" : : "r"(v0), "r"(m0), "r"(v1) : "memory");
}

INCLUDE_ASM("asm/nonmatchings/lib/libvu0", sceVu0MulMatrix);
// void sceVu0MulMatrix(sceVu0FMATRIX m0, sceVu0FMATRIX m1,sceVu0FMATRIX m2) {
//     __asm__ __volatile__("          \n\
// 	lqc2            vf4,0x0(%2)     \n\
// 	lqc2            vf5,0x10(%2)    \n\
// 	lqc2            vf6,0x20(%2)    \n\
// 	lqc2            vf7,0x30(%2)    \n\
// 	li              $7,4            \n\
// _loop:                              \n\
// 	lqc2            vf8,0x0(%1)     \n\
// 	vmulax.xyzw	    ACC,vf4,vf8     \n\
// 	vmadday.xyzw    ACC,vf5,vf8     \n\
// 	vmaddaz.xyzw	ACC,vf6,vf8     \n\
// 	vmaddw.xyzw	    vf9,vf7,vf8     \n\
// 	sqc2            vf9,0x0(%0)     \n\
// 	addi            $7,-1           \n\
// 	addi            %1,0x10         \n\
// 	addi            %0,0x10         \n\
// 	bne             $0,$7,_loop     \n\
// 	":: "r" (m0), "r" (m2), "r" (m1) : "$7", "memory");
// }

void sceVu0OuterProduct(sceVu0FVECTOR v0, sceVu0FVECTOR v1, sceVu0FVECTOR v2) {
    __asm__ __volatile__("      \n\
	lqc2    vf4,0x0(%1)         \n\
	lqc2    vf5,0x0(%2)         \n\
	vopmula.xyz	ACC,vf4,vf5     \n\
	vopmsub.xyz	vf6,vf5,vf4     \n\
	vsub.w vf6,vf6,vf6		    \n\
	sqc2    vf6,0x0(%0)         \n\
	": : "r" (v0) , "r" (v1) ,"r" (v2) : "memory");
}

f32 sceVu0InnerProduct(sceVu0FVECTOR v0, sceVu0FVECTOR v1) {
    register f32 product;

    __asm__ __volatile__("      \n\
	lqc2    vf4,0x0(%1)         \n\
	lqc2    vf5,0x0(%2)         \n\
	vmul.xyz vf5,vf4,vf5        \n\
	vaddy.x vf5,vf5,vf5         \n\
	vaddz.x vf5,vf5,vf5         \n\
	qmfc2   $2 ,vf5             \n\
	mtc1    $2,%0               \n\
	": "=f" (product) :"r" (v0) ,"r" (v1) :"$2", "memory" );
}

void sceVu0Normalize(sceVu0FVECTOR v0, sceVu0FVECTOR v1) {
    __asm__ __volatile__("      \n\
    lqc2        vf4,0x0(%1)     \n\
    vmul.xyz    vf5,vf4,vf4     \n\
    vaddy.x     vf5,vf5,vf5     \n\
    vaddz.x     vf5,vf5,vf5     \n\
    vsqrt       Q,vf5x          \n\
    vwaitq                      \n\
    vaddq.x     vf5x,vf0x,Q     \n\
    vnop                        \n\
    vnop                        \n\
    vdiv        Q,vf0w,vf5x     \n\
    vsub.xyzw   vf6,vf0,vf0     \n\
    vwaitq                      \n\
    vmulq.xyz   vf6,vf4,Q       \n\
    sqc2        vf6,0x0(%0)     \n\
    ": : "r" (v0) , "r" (v1) : "memory");
}

INCLUDE_ASM("asm/nonmatchings/lib/libvu0", sceVu0TransposeMatrix);
// void sceVu0TransposeMatrix(sceVu0FMATRIX m0, sceVu0FMATRIX m1) {
//     __asm__ __volatile__("      \n\
// 	lq $8,0x0000(%1)            \n\
// 	lq $9,0x0010(%1)            \n\
// 	lq $10,0x0020(%1)           \n\
// 	lq $11,0x0030(%1)           \n\
// 	pextlw     $12,$9,$8        \n\
// 	pextuw     $13,$9,$8        \n\
// 	pextlw     $14,$11,$10      \n\
// 	pextuw     $15,$11,$10      \n\
// 	pcpyld     $8,$14,$12       \n\
// 	pcpyud     $9,$12,$14       \n\
// 	pcpyld     $10,$15,$13      \n\
// 	pcpyud     $11,$13,$15      \n\
// 	sq $8,0x0000(%0)            \n\
// 	sq $9,0x0010(%0)            \n\
// 	sq $10,0x0020(%0)           \n\
// 	sq $11,0x0030(%0)           \n\
// 	": : "r" (m0) , "r" (m1) : "memory");
// }

void sceVu0InversMatrix(sceVu0FMATRIX m0, sceVu0FMATRIX m1) {
    __asm__ __volatile__("      \n\
	lq          $8,0x0000(%1)   \n\
	lq          $9,0x0010(%1)   \n\
	lq          $10,0x0020(%1)  \n\
	lqc2        vf4,0x0030(%1)  \n\
	vmove.xyzw  vf5,vf4         \n\
	vsub.xyz    vf4,vf4,vf4     \n\
	vmove.xyzw  vf9,vf4         \n\
	qmfc2       $11,vf4         \n\
	pextlw      $12,$9,$8       \n\
	pextuw      $13,$9,$8       \n\
	pextlw      $14,$11,$10     \n\
	pextuw      $15,$11,$10     \n\
	pcpyld      $8,$14,$12      \n\
	pcpyud      $9,$12,$14      \n\
	pcpyld      $10,$15,$13     \n\
	qmtc2       $8,vf6          \n\
	qmtc2       $9,vf7          \n\
	qmtc2       $10,vf8         \n\
	vmulax.xyz  ACC,vf6,vf5     \n\
	vmadday.xyz ACC,vf7,vf5     \n\
	vmaddz.xyz  vf4,vf8,vf5     \n\
	vsub.xyz    vf4,vf9,vf4     \n\
	sq 			$8,0x0000(%0)   \n\
	sq 			$9,0x0010(%0)   \n\
	sq 			$10,0x0020(%0)  \n\
	sqc2 		vf4,0x0030(%0)  \n\
	": : "r" (m0) , "r" (m1):"$8","$9","$10","$11","$12","$13","$14","$15", "memory");
}

void sceVu0DivVector(sceVu0FVECTOR v0, sceVu0FVECTOR v1, f32 q) {
    __asm__ __volatile__("		\n\
	lqc2 		vf4,0x0(%1)		\n\
	mfc1 		$8,%2			\n\
	qmtc2		$8,vf5			\n\
	vdiv 		Q,vf0w,vf5x		\n\
	vwaitq						\n\
	vmulq.xyzw	vf4,vf4,Q		\n\
	sqc2    	vf4,0x0(%0)		\n\
	": : "r" (v0) , "r" (v1), "f" (q):"$8", "memory");
}

void sceVu0DivVectorXYZ(sceVu0FVECTOR v0, sceVu0FVECTOR v1, f32 q) {
    __asm__ __volatile__("		\n\
	lqc2		vf4,0x0(%1)		\n\
	mfc1		$8,%2			\n\
	qmtc2		$8,vf5			\n\
	vdiv    	Q,vf0w,vf5x		\n\
	vwaitq						\n\
	vmulq.xyz	vf4,vf4,Q		\n\
	sqc2		vf4,0x0(%0)		\n\
	": : "r" (v0) , "r" (v1), "f" (q) : "$8", "memory");
}

void sceVu0InterVector(sceVu0FVECTOR v0, sceVu0FVECTOR v1, sceVu0FVECTOR v2, f32 t) {
    __asm__ __volatile__("		\n\
	lqc2		vf4,0x0(%1)		\n\
	lqc2		vf5,0x0(%2)		\n\
	mfc1		$8,%3			\n\
	qmtc2    	$8,vf6			\n\
    vaddw.x   	vf7,vf0,vf0		\n\
    vsub.x    	vf8,vf7,vf6		\n\
	vmulax.xyzw	ACC,vf4,vf6		\n\
	vmaddx.xyzw	vf9,vf5,vf8		\n\
	sqc2    	vf9,0x0(%0)		\n\
	": : "r" (v0) , "r" (v1), "r" (v2), "f" (t) : "$8", "memory");
}

void sceVu0AddVector(sceVu0FVECTOR v0, sceVu0FVECTOR v1, sceVu0FVECTOR v2) {
    __asm__ __volatile__("		\n\
	lqc2		vf4,0x0(%1)		\n\
	lqc2		vf5,0x0(%2)		\n\
	vadd.xyzw	vf6,vf4,vf5		\n\
	sqc2    	vf6,0x0(%0)		\n\
	": : "r" (v0) , "r" (v1), "r" (v2) : "memory");
}

void sceVu0SubVector(sceVu0FVECTOR v0, sceVu0FVECTOR v1, sceVu0FVECTOR v2) {
    __asm__ __volatile__("		\n\
	lqc2    	vf4,0x0(%1)		\n\
	lqc2    	vf5,0x0(%2)		\n\
	vsub.xyzw	vf6,vf4,vf5		\n\
	sqc2		vf6,0x0(%0)		\n\
	": : "r" (v0) , "r" (v1), "r" (v2) : "memory");
}

void sceVu0MulVector(sceVu0FVECTOR v0, sceVu0FVECTOR v1, sceVu0FVECTOR v2) {
    __asm__ __volatile__("		\n\
	lqc2		vf4,0x0(%1)		\n\
	lqc2		vf5,0x0(%2)		\n\
	vmul.xyzw	vf6,vf4,vf5		\n\
	sqc2		vf6,0x0(%0)		\n\
	": : "r" (v0) , "r" (v1), "r" (v2) : "memory");
}

void sceVu0ScaleVector(sceVu0FVECTOR v0, sceVu0FVECTOR v1, f32 t) {
    __asm__ __volatile__("		\n\
	lqc2		vf4,0x0(%1)		\n\
	mfc1    	$8,%2			\n\
	qmtc2    	$8,vf5			\n\
	vmulx.xyzw	vf6,vf4,vf5		\n\
	sqc2    	vf6,0x0(%0)		\n\
	": : "r" (v0) , "r" (v1), "f" (t):"$8", "memory");
}

void sceVu0TransMatrix(sceVu0FMATRIX m0, sceVu0FMATRIX m1, sceVu0FVECTOR tv) {
    __asm__ __volatile__("		\n\
	lqc2		vf4,0x0(%2)		\n\
	lqc2    	vf5,0x30(%1)	\n\
	lq    		$7,0x0(%1)		\n\
	lq    		$8,0x10(%1)		\n\
	lq    		$9,0x20(%1)		\n\
	vadd.xyz	vf5,vf5,vf4		\n\
	sq    		$7,0x0(%0)		\n\
	sq    		$8,0x10(%0)		\n\
	sq    		$9,0x20(%0)		\n\
	sqc2    	vf5,0x30(%0)	\n\
	": : "r" (m0) , "r" (m1), "r" (tv):"$7","$8","$9","memory");
}

INCLUDE_ASM("asm/nonmatchings/lib/libvu0", sceVu0CopyVector);
// void sceVu0CopyVector(sceVu0FVECTOR v0, sceVu0FVECTOR v1) {
//     __asm__ __volatile__("	\n\
// 	lq	$6,0x0(%1)			\n\
// 	sq	$6,0x0(%0)			\n\
// 	": : "r" (v0) , "r" (v1):"$6", "memory");
// }

INCLUDE_ASM("asm/nonmatchings/lib/libvu0", sceVu0CopyMatrix);
// void sceVu0CopyMatrix(sceVu0FMATRIX m0, sceVu0FMATRIX m1) {
//     __asm__ __volatile__("	\n\
// 	lq    $6,0x0(%1)		\n\
// 	lq    $7,0x10(%1)		\n\
// 	lq    $8,0x20(%1)		\n\
// 	lq    $9,0x30(%1)		\n\
// 	sq    $6,0x0(%0)		\n\
// 	sq    $7,0x10(%0)		\n\
// 	sq    $8,0x20(%0)		\n\
// 	sq    $9,0x30(%0)		\n\
// 	": : "r" (m0) , "r" (m1):"$6","$7","$8","$9","memory");
// }

void sceVu0FTOI4Vector(sceVu0IVECTOR v0, sceVu0FVECTOR v1) {
    __asm__ __volatile__("		\n\
	lqc2    	vf4,0x0(%1)		\n\
	vftoi4.xyzw	vf5,vf4			\n\
	sqc2    	vf5,0x0(%0)		\n\
	": : "r" (v0) , "r" (v1) : "memory");
}

void sceVu0FTOI0Vector(sceVu0IVECTOR v0, sceVu0FVECTOR v1) {
    __asm__ __volatile__("		\n\
	lqc2    	vf4,0x0(%1)		\n\
	vftoi0.xyzw	vf5,vf4			\n\
	sqc2    	vf5,0x0(%0)		\n\
	": : "r" (v0) , "r" (v1) : "memory");
}

void sceVu0ITOF4Vector(sceVu0FVECTOR v0, sceVu0IVECTOR v1) {
    __asm__ __volatile__("		\n\
	lqc2    	vf4,0x0(%1)		\n\
	vitof4.xyzw	vf5,vf4			\n\
	sqc2    	vf5,0x0(%0)		\n\
	": : "r" (v0) , "r" (v1) : "memory");
}

void sceVu0ITOF0Vector(sceVu0FVECTOR v0, sceVu0IVECTOR v1) {
    __asm__ __volatile__("		\n\
	lqc2    	vf4,0x0(%1)		\n\
	vitof0.xyzw	vf5,vf4			\n\
	sqc2    	vf5,0x0(%0)		\n\
	": : "r" (v0) , "r" (v1) : "memory");
}

void sceVu0UnitMatrix(sceVu0FMATRIX m0) {
    __asm__ __volatile__("		\n\
	vsub.xyzw	vf4,vf0,vf0		\n\
	vadd.w		vf4,vf4,vf0		\n\
	vmr32.xyzw	vf5,vf4			\n\
	vmr32.xyzw	vf6,vf5			\n\
	vmr32.xyzw	vf7,vf6			\n\
	sqc2   		vf4,0x30(%0)	\n\
	sqc2   		vf5,0x20(%0)	\n\
	sqc2   		vf6,0x10(%0)	\n\
	sqc2   		vf7,0x0(%0)		\n\
	": : "r" (m0) : "memory");
}

// Coefficients for sceVu0ecossin
__asm__ ("				\n\
	.data				\n\
	.align 4			\n\
	S5432:				\n\
	.word 0x362E9C14,	\
		  0xB94FB21F,	\
		  0x3C08873E, 	\
		  0xBE2AAAA4	\n\
	.text				\n\
");

static void _sceVu0ecossin(f32 t) {
    __asm__ __volatile__("          \n\
	la          $8,S5432       		\n\
	lqc2        vf05,0x0($8)        \n\
	vmr32.w     vf06,vf06           \n\
	vaddx.x     vf04,vf00,vf06      \n\
	vmul.x      vf06,vf06,vf06      \n\
	vmulx.yzw   vf04,vf04,vf00      \n\
	vmulw.xyzw  vf08,vf05,vf06      \n\
	vsub.xyzw   vf05,vf00,vf00      \n\
	vmulx.xyzw  vf08,vf08,vf06      \n\
	vmulx.xyz   vf08,vf08,vf06      \n\
	vaddw.x     vf04,vf04,vf08      \n\
	vmulx.xy    vf08,vf08,vf06      \n\
	vaddz.x     vf04,vf04,vf08      \n\
	vmulx.x     vf08,vf08,vf06      \n\
	vaddy.x     vf04,vf04,vf08      \n\
	vaddx.x     vf04,vf04,vf08      \n\
	vaddx.xy    vf04,vf05,vf04      \n\
	vmul.x      vf07,vf04,vf04      \n\
	vsubx.w     vf07,vf00,vf07      \n\
	vsqrt       Q,vf07w             \n\
	vwaitq                          \n\
	vaddq.x     vf07,vf00,Q         \n\
	bne	        $7,$0,_ecossin_01   \n\
	vaddx.x     vf04,vf05,vf07      \n\
	b	        _ecossin_02         \n\
_ecossin_01:                        \n\
	vsubx.x     vf04,vf05,vf07      \n\
_ecossin_02:                        \n\
	": : :"$7","$8");
}

INCLUDE_ASM("asm/nonmatchings/lib/libvu0", sceVu0RotMatrixZ);
// void sceVu0RotMatrixZ(sceVu0FMATRIX m0, sceVu0FMATRIX m1, f32 rz) {
//     __asm__ __volatile__("					\n\
// 	mtc1			$0,$f0					\n\
// 	c.olt.s 		%2,$f0					\n\
// 	li.s    $f0,1.57079637050628662109e0	\n\
// 	bc1f    		_RotMatrixZ_01			\n\
// 	add.s   		%2,$f0,%2				\n\
// 	li 				$7,1					\n\
// 	j				_RotMatrixZ_02			\n\
// _RotMatrixZ_01:								\n\
// 	sub.s   		%2,$f0,%2				\n\
// 	move			$7,$0					\n\
// _RotMatrixZ_02:								\n\
// 	mfc1    		$8,%2					\n\
// 	qmtc2    		$8,vf6					\n\
// 	move			$6,$31					\n\
// 	jal	_sceVu0ecossin						\n\
// 	move			$31,$6					\n\
// 	vmove.xyzw 		vf06,vf05				\n\
// 	vmove.xyzw 		vf07,vf05				\n\
// 	vmove.xyzw 		vf09,vf00				\n\
// 	vsub.xyz 		vf09,vf09,vf09 			\n\
// 	vmr32.xyzw 		vf08,vf09				\n\
// 	vsub.zw 		vf04,vf04,vf04 			\n\
// 	vaddx.y 		vf06,vf05,vf04			\n\
// 	vaddy.x 		vf06,vf05,vf04			\n\
// 	vsubx.x 		vf07,vf05,vf04			\n\
// 	vaddy.y 		vf07,vf05,vf04			\n\
// 	li    			$7,4					\n\
// _loopRotMatrixZ:							\n\
// 	lqc2    		vf4,0x0(%1)				\n\
// 	vmulax.xyzw		ACC,vf6,vf4				\n\
// 	vmadday.xyzw	ACC,vf7,vf4				\n\
// 	vmaddaz.xyzw	ACC,vf8,vf4				\n\
// 	vmaddw.xyzw		vf5,vf9,vf4				\n\
// 	sqc2    		vf5,0x0(%0)				\n\
// 	addi    		$7,-1					\n\
// 	addi    		%1,0x10					\n\
// 	addi    		%0,0x10					\n\
// 	bne				$0,$7,_loopRotMatrixZ	\n\
// 	": : "r" (m0) , "r" (m1), "f" (rz):"$6","$7","$8","$f0", "memory");
// }

INCLUDE_ASM("asm/nonmatchings/lib/libvu0", sceVu0RotMatrixX);
// void sceVu0RotMatrixX(sceVu0FMATRIX m0, sceVu0FMATRIX m1, f32 rx) {
//     __asm__ __volatile__("					\n\
// 	mtc1			$0,$f0					\n\
// 	c.olt.s 		%2,$f0					\n\
// 	li.s    $f0,1.57079637050628662109e0	\n\
// 	bc1f    		_RotMatrixX_01			\n\
// 	add.s   		%2,$f0,%2				\n\
// 	li 				$7,1					\n\
// 	j				_RotMatrixX_02			\n\
// _RotMatrixX_01:								\n\
// 	sub.s   		%2,$f0,%2				\n\
// 	move			$7,$0					\n\
// _RotMatrixX_02:								\n\
// 	mfc1    		$8,%2					\n\
// 	qmtc2    		$8,$vf6					\n\
// 	move			$6,$31					\n\
// 	jal				_sceVu0ecossin			\n\
// 	move			$31,$6					\n\
// 	vmove.xyzw 		vf06,vf05				\n\
// 	vmove.xyzw 		vf07,vf05				\n\
// 	vmove.xyzw 		vf08,vf05				\n\
// 	vmove.xyzw 		vf09,vf05				\n\
// 	vaddw.x 		vf06,vf05,vf00			\n\
// 	vaddw.w 		vf09,vf05,vf00			\n\
// 	vsub.zw 		vf04,vf04,vf04			\n\
// 	vaddx.z 		vf07,vf05,vf04			\n\
// 	vaddy.y 		vf07,vf05,vf04			\n\
// 	vsubx.y 		vf08,vf05,vf04			\n\
// 	vaddy.z 		vf08,vf05,vf04			\n\
// 	li    			$7,4					\n\
// _loopRotMatrixX:							\n\
// 	lqc2    		vf4,0x0(%1)				\n\
// 	vmulax.xyzw		ACC,vf6,vf4				\n\
// 	vmadday.xyzw	ACC,vf7,vf4				\n\
// 	vmaddaz.xyzw	ACC,vf8,vf4				\n\
// 	vmaddw.xyzw		vf5,vf9,vf4				\n\
// 	sqc2			vf5,0x0(%0)				\n\
// 	addi    		$7,-1					\n\
// 	addi    		%1,0x10					\n\
// 	addi    		%0,0x10					\n\
// 	bne				$0,$7,_loopRotMatrixX	\n\
// 	": : "r" (m0) , "r" (m1), "f" (rx):"$6","$7","$8","$f0","memory");
// }

INCLUDE_ASM("asm/nonmatchings/lib/libvu0", sceVu0RotMatrixY);
// void sceVu0RotMatrixY(sceVu0FMATRIX m0, sceVu0FMATRIX m1, f32 ry) {
//     __asm__ __volatile__("					\n\
// 	mtc1			$0,$f0					\n\
// 	c.olt.s 		%2,$f0					\n\
// 	li.s	$f0,1.57079637050628662109e0	\n\
// 	bc1f    		_RotMatrixY_01			\n\
// 	add.s   		%2,$f0,%2				\n\
// 	li 				$7,1					\n\
// 	j				_RotMatrixY_02			\n\
// _RotMatrixY_01:								\n\
// 	sub.s   		%2,$f0,%2				\n\
// 	move			$7,$0					\n\
// _RotMatrixY_02:								\n\
// 	mfc1    		$8,%2					\n\
// 	qmtc2    		$8,vf6					\n\
// 	move			$6,$31					\n\
// 	jal				_sceVu0ecossin			\n\
// 	move			$31,$6					\n\
// 	vmove.xyzw 		vf06,vf05				\n\
// 	vmove.xyzw 		vf07,vf05				\n\
// 	vmove.xyzw 		vf08,vf05				\n\
// 	vmove.xyzw 		vf09,vf05				\n\
// 	vaddw.y			vf07,vf05,vf00 			\n\
// 	vaddw.w			vf09,vf05,vf00 			\n\
// 	vsub.zw			vf04,vf04,vf04 			\n\
// 	vsubx.z			vf06,vf05,vf04 			\n\
// 	vaddy.x			vf06,vf05,vf04 			\n\
// 	vaddx.x			vf08,vf05,vf04 			\n\
// 	vaddy.z			vf08,vf05,vf04 			\n\
// 	li    			$7,4					\n\
// _loopRotMatrixY:							\n\
// 	lqc2    		vf4,0x0(%1)				\n\
// 	vmulax.xyzw		ACC,vf6,vf4				\n\
// 	vmadday.xyzw	ACC,vf7,vf4				\n\
// 	vmaddaz.xyzw	ACC,vf8,vf4				\n\
// 	vmaddw.xyzw		vf5,vf9,vf4				\n\
// 	sqc2    		vf5,0x0(%0)				\n\
// 	addi    $7,-1							\n\
// 	addi    %1,0x10							\n\
// 	addi    %0,0x10							\n\
// 	bne		$0,$7,_loopRotMatrixY			\n\
// 	": : "r" (m0) , "r" (m1), "f" (ry):"$6","$7","$8","$f0","memory");
// }

void sceVu0RotMatrix(sceVu0FMATRIX m0, sceVu0FMATRIX m1, sceVu0FVECTOR rot) {
	sceVu0RotMatrixZ(m0, m1, rot[2]);
	sceVu0RotMatrixY(m0, m0, rot[1]);
	sceVu0RotMatrixX(m0, m0, rot[0]);
}

void sceVu0ClampVector(sceVu0FVECTOR v0, sceVu0FVECTOR v1, f32 min, f32 max) {
    __asm__ __volatile__("			\n\
	mfc1		$8,%2				\n\
	mfc1		$9,%3				\n\
	lqc2		vf6,0x0(%1)			\n\
	qmtc2		$8,vf4				\n\
	qmtc2		$9,vf5				\n\
	vmaxx.xyzw 	$vf06,$vf06,$vf04	\n\
	vminix.xyzw $vf06,$vf06,$vf05	\n\
	sqc2    	vf6,0x0(%0)			\n\
	": : "r" (v0) , "r" (v1), "f" (min), "f" (max):"$8","$9","memory");
}

void sceVu0CameraMatrix(sceVu0FMATRIX m, sceVu0FVECTOR p, sceVu0FVECTOR zd, sceVu0FVECTOR yd) {
    sceVu0FMATRIX m0;
    sceVu0FVECTOR xd;

    sceVu0UnitMatrix(m0);
    sceVu0OuterProduct(xd, yd, zd);
    sceVu0Normalize(m0[0], xd);
    sceVu0Normalize(m0[2], zd);
    sceVu0OuterProduct(m0[1], m0[2], m0[0]);
    sceVu0TransMatrix(m0, m0, p);
    sceVu0InversMatrix(m, m0);
}

void sceVu0NormalLightMatrix(sceVu0FMATRIX m, sceVu0FVECTOR l0, sceVu0FVECTOR l1, sceVu0FVECTOR l2) {
    sceVu0FVECTOR t;

    sceVu0ScaleVector(t, l0, -1);
	sceVu0Normalize(m[0], t);

    sceVu0ScaleVector(t, l1, -1);
	sceVu0Normalize(m[1], t);

    sceVu0ScaleVector(t, l2, -1);
	sceVu0Normalize(m[2], t);

	m[3][0] = m[3][1] = m[3][2] = 0.0f;
	m[3][3] = 1.0f;

	sceVu0TransposeMatrix(m, m);
}

void sceVu0LightColorMatrix(sceVu0FMATRIX m, sceVu0FVECTOR c0, sceVu0FVECTOR c1, sceVu0FVECTOR c2, sceVu0FVECTOR a) {
    sceVu0CopyVector(m[0], c0);
    sceVu0CopyVector(m[1], c1);
    sceVu0CopyVector(m[2], c2);
    sceVu0CopyVector(m[3], a);
}

INCLUDE_ASM("asm/nonmatchings/lib/libvu0", sceVu0ViewScreenMatrix);
// void sceVu0ViewScreenMatrix(sceVu0FMATRIX m, f32 scrz, f32 ax, f32 ay, 
// 	f32 cx, f32 cy, f32 zmin, f32 zmax, f32 nearz, f32 farz) 
// {
// 	sceVu0FMATRIX mt;

// 	f32 cz = (-zmax * nearz + zmin * farz) / (-nearz + farz);
// 	f32 az  = farz * nearz * (-zmin + zmax) / (-nearz + farz);

// 	sceVu0UnitMatrix(m);
// 	m[0][0] = scrz;
// 	m[1][1] = scrz;
// 	m[2][2] = 0.0f;
// 	m[3][3] = 0.0f;
// 	m[3][2] = 1.0f;
// 	m[2][3] = 1.0f;

// 	sceVu0UnitMatrix(mt);
// 	mt[0][0] = ax;
// 	mt[1][1] = ay;
// 	mt[2][2] = az;
// 	mt[3][0] = cx;
// 	mt[3][1] = cy;
// 	mt[3][2] = cz;

// 	sceVu0MulMatrix(m, mt, m);
// }

INCLUDE_ASM("asm/nonmatchings/lib/libvu0", sceVu0DropShadowMatrix);
// void sceVu0DropShadowMatrix(sceVu0FMATRIX m, sceVu0FVECTOR lp, f32 a, f32 b, f32 c, s32 mode) {
//     if (mode) {	// spot light
// 		f32 x = lp[0], y = lp[1], z = lp[2];
// 		f32 d = 1.0f - (a*x + b*y + c*z);

// 		m[0][0] = a*x+d, m[1][0] = b*x,   m[2][0] = c*x,   m[3][0] = -x;
// 		m[0][1] = a*y,   m[1][1] = b*y+d, m[2][1] = c*y,   m[3][1] = -y;
// 		m[0][2] = a*z,   m[1][2] = b*z,   m[2][2] = c*z+d, m[3][2] = -z;
// 		m[0][3] = a,     m[1][3] = b,     m[2][3] = c,     m[3][3] = d-1;
//     } else {	// parallel light
// 		f32 p  = lp[0], q = lp[1], r = lp[2];
// 		f32 n  = a*p + b*q + c*r;
// 		f32 nr = -1.0f / n;

// 		m[0][0] = nr*(a*p-n), m[1][0] = nr*(b*p),   m[2][0] = nr*(c*p),   m[3][0] = nr*(-p);
// 		m[0][1] = nr*(a*q),   m[1][1] = nr*(b*q-n), m[2][1] = nr*(c*q),   m[3][1] = nr*(-q);
// 		m[0][2] = nr*(a*r),   m[1][2] = nr*(b*r),   m[2][2] = nr*(c*r-n), m[3][2] = nr*(-r);
// 		m[0][3] = 0.0f,       m[1][3] = 0.0f,       m[2][3] = 0.0f,       m[3][3] = nr*(-n);
//     }
// }

INCLUDE_ASM("asm/nonmatchings/lib/libvu0", sceVu0RotTransPersN);
// void sceVu0RotTransPersN(sceVu0IVECTOR* v0, sceVu0FMATRIX m0, sceVu0FVECTOR* v1, s32 n, s32 mode) {
//     __asm__ __volatile__("			\n\
// 	lqc2			vf4,0x0(%1)		\n\
// 	lqc2			vf5,0x10(%1)	\n\
// 	lqc2			vf6,0x20(%1)	\n\
// 	lqc2			vf7,0x30(%1)	\n\
// _rotTPN_loop:						\n\
// 	lqc2			vf8,0x0(%2)		\n\
// 	vmulax.xyzw     ACC, vf4,vf8	\n\
// 	vmadday.xyzw    ACC, vf5,vf8	\n\
// 	vmaddaz.xyzw	ACC, vf6,vf8	\n\
// 	vmaddw.xyzw		vf9,vf7,vf8		\n\
// 	vdiv    		Q,vf0w,vf9w		\n\
// 	vwaitq							\n\
// 	vmulq.xyz		vf9,vf9,Q		\n\
// 	vftoi4.xyzw		vf10,vf9		\n\
// 	beqz			%4,_rotTPN		\n\
// 	vftoi0.zw		vf10,vf9		\n\
// _rotTPN:							\n\
// 	sqc2			vf10,0x0(%0)	\n\
// 	addi			%3,-1			\n\
// 	addi			%2,0x10			\n\
// 	addi			%0,0x10			\n\
// 	bne		$0,%3,_rotTPN_loop		\n\
// 	": : "r" (v0) , "r" (m0) ,"r" (v1), "r" (n) ,"r" (mode):"memory");
// }

void sceVu0RotTransPers(sceVu0IVECTOR v0, sceVu0FMATRIX m0, sceVu0FVECTOR v1, s32 mode) {
    __asm__ __volatile__("			\n\
	lqc2			vf4,0x0(%1)		\n\
	lqc2			vf5,0x10(%1)	\n\
	lqc2			vf6,0x20(%1)	\n\
	lqc2			vf7,0x30(%1)	\n\
	lqc2			vf8,0x0(%2)		\n\
	vmulax.xyzw		ACC, vf4,vf8	\n\
	vmadday.xyzw    ACC, vf5,vf8	\n\
	vmaddaz.xyzw    ACC, vf6,vf8	\n\
	vmaddw.xyzw		vf9,vf7,vf8		\n\
	vdiv    		Q,vf0w,vf9w		\n\
	vwaitq							\n\
	vmulq.xyz		vf9,vf9,Q		\n\
	vftoi4.xyzw		vf10,vf9		\n\
	beqz			%3,_rotTP		\n\
	vftoi0.zw		vf10,vf9		\n\
_rotTP:								\n\
	sqc2	vf10,0x0(%0)			\n\
	": : "r" (v0) , "r" (m0) ,"r" (v1), "r" (mode):"memory");
}

void sceVu0CopyVectorXYZ(sceVu0FVECTOR v0, sceVu0FVECTOR v1) {
    v0[0] = v1[0];
    v0[1] = v1[1];
    v0[2] = v1[2];
}

void sceVu0InterVectorXYZ(sceVu0FVECTOR v0, sceVu0FVECTOR v1, sceVu0FVECTOR v2, f32 r) {
    __asm__ __volatile__("			\n\
	lqc2		vf4,0x0(%1)			\n\
	lqc2		vf5,0x0(%2)			\n\
	mfc1		$8,%3				\n\
	qmtc2		$8,vf6				\n\
	vmove.w		vf9,vf4				\n\
	vaddw.x		vf7,vf0,vf0			\n\
	vsub.x		vf8,vf7,vf6			\n\
	vmulax.xyz	ACC,vf4,vf6			\n\
	vmaddx.xyz	vf9,vf5,vf8			\n\
	sqc2    	vf9,0x0(%0)			\n\
	": : "r" (v0) , "r" (v1), "r" (v2), "f" (r) : "$8","memory");
}

void sceVu0ScaleVectorXYZ(sceVu0FVECTOR v0, sceVu0FVECTOR v1, f32 s) {
    __asm__ __volatile__("		\n\
	lqc2		vf4,0x0(%1)		\n\
	mfc1		$8,%2			\n\
	qmtc2		$8,vf5			\n\
	vmulx.xyz	vf4,vf4,vf5		\n\
	sqc2		vf4,0x0(%0)		\n\
	": : "r" (v0) , "r" (v1), "f" (s):"$8","memory");
}

INCLUDE_ASM("asm/nonmatchings/lib/libvu0", sceVu0ClipScreen);
// s32 sceVu0ClipScreen(sceVu0FVECTOR v0) {
//     register s32 ret;

//     __asm__ __volatile__("\n\
// 	vsub.xyzw	vf04,vf00,vf00			\n\
// 	li     		%0,0x4580000045800000	\n\
// 	lqc2    	vf07,0x0(%1)			\n\
// 	qmtc2  		%0,vf06					\n\
// 	ctc2    	$0,$vi16				\n\
// 	vsub.xyw	vf05,vf07,vf04			\n\
// 	vsub.xy		vf05,vf06,vf07			\n\
// 	vnop			    				\n\
// 	vnop								\n\
// 	vnop								\n\
// 	vnop								\n\
// 	vnop								\n\
//     cfc2    %0,$vi16					\n\
// 	andi	%0,%0,0xc0					\n\
// 	":"=&r"(ret): "r" (v0));

//     return ret;
// }

INCLUDE_ASM("asm/nonmatchings/lib/libvu0", sceVu0ClipScreen3);
// s32 sceVu0ClipScreen3(sceVu0FVECTOR v0, sceVu0FVECTOR v1, sceVu0FVECTOR v2) {
//     register s32 ret;

//     __asm__ __volatile__("				\n\
// 	vsub.xyzw	vf04,vf00,vf00			\n\
// 	li			%0,0x4580000045800000	\n\
// 	lqc2    	vf06,0x0(%1)			\n\
// 	lqc2    	vf08,0x0(%2)			\n\
// 	lqc2    	vf09,0x0(%3)			\n\
// 	qmtc2		%0,vf07					\n\
// 	ctc2		$0,$vi16				\n\
// 	vsub.xyw	vf05,vf06,vf04			\n\
// 	vsub.xy 	vf05,vf07,vf06 			\n\
// 	vsub.xyw	vf05,vf08,vf04			\n\
// 	vsub.xy 	vf05,vf07,vf08			\n\
// 	vsub.xyw	vf05,vf09,vf04			\n\
// 	vsub.xy 	vf05,vf07,vf09			\n\
// 	vnop								\n\
// 	vnop								\n\
// 	vnop								\n\
// 	vnop								\n\
// 	vnop								\n\
// 	cfc2    	%0,$vi16				\n\
// 	andi		%0,%0,0xc0				\n\
// 	":"=&r"(ret): "r" (v0), "r" (v1), "r" (v2) );

//     return ret;
// }

INCLUDE_ASM("asm/nonmatchings/lib/libvu0", sceVu0ClipAll);
// s32 sceVu0ClipAll(sceVu0FVECTOR minv, sceVu0FVECTOR maxv, sceVu0FMATRIX ms, sceVu0FVECTOR *vm, s32 n) {
//     register s32 ret;
//     __asm__ __volatile__("			\n\
// 	lqc2		vf8,0x0(%4)			\n\
// 	lqc2		vf4,0x0(%3)			\n\
// 	lqc2		vf5,0x10(%3)		\n\
// 	lqc2		vf6,0x20(%3)		\n\
// 	lqc2		vf7,0x30(%3)		\n\
// 	lqc2		vf9,0x0(%1)			\n\
// 	lqc2		vf10,0x0(%2)		\n\
// 	lqc2		vf11,0x0(%1)		\n\
// 	lqc2		vf12,0x0(%2)		\n\
// loop_clip_all:						\n\
// 	vmulax.xyzw		ACC,vf4,vf8		\n\
// 	vmadday.xyzw	ACC,vf5,vf8		\n\
// 	vmaddaz.xyzw	ACC,vf6,vf8		\n\
// 	vmaddw.xyzw		vf8,vf7,vf8		\n\
// 	vmulw.xyz		vf11,vf9,vf8	\n\
// 	vmulw.xyz		vf12,vf10,vf8	\n\
// 	vnop							\n\
// 	vnop							\n\
// 	ctc2    	$0,$vi16            \n\
// 	vsub.xyw	vf11,vf8,vf11  		\n\
// 	vsub.xyw	vf12,vf12,vf8  		\n\
// 	vmove.w		vf11,vf9			\n\
// 	vmove.w		vf12,vf10			\n\
// 	vnop							\n\
// 	addi		%4,0x10				\n\
// 	lqc2    	vf8,0x0(%4)			\n\
// 	addi		%5,-1				\n\
// 	cfc2    	%0,$vi16			\n\
// 	andi		%0,%0,0xc0			\n\
// 	beqz		%0,end_clip_all		\n\
// 	bne			$0,%5,loop_clip_all	\n\
// 	addi		%0,$0,1				\n\
// end_clip_all:						\n\
// 	":"=&r"(ret): "r" (minv),"r" (maxv),"r" (ms),"r" (vm),"r" (n));
//     return ret;
// }

static u32 init_vif_regs[8] __attribute__((aligned (16))) = {
	0x01000404, // STCYCL
	0x20000000, // STMASK
	0x00000000, // DATA
	0x05000000, // STMOD
	0x04000000, // ITOP
	0x00000000, // NOP
	0x00000000, // NOP
	0x00000000, // NOP
};

INCLUDE_ASM("asm/nonmatchings/lib/libvu0", sceVpu0Reset);
// void sceVpu0Reset(void) {
//     static u32 init_vif_regs[8] __attribute__((aligned (16))) = {
// 	0x01000404, // STCYCL
// 	0x20000000, // STMASK
// 	0x00000000, // DATA
// 	0x05000000, // STMOD
// 	0x04000000, // ITOP
// 	0x00000000, // NOP
// 	0x00000000, // NOP
// 	0x00000000, // NOP
//     };
// 	DPUT_VIF0_MARK(0);
// 	DPUT_VIF0_ERR(0);
// 	DPUT_VIF0_FBRST(1); // VIF1 reset
// 	__asm__ __volatile__("	\n\
// 	cfc2 	$8, $vi28		\n\
// 	ori  	$8, $8, 0x0002	\n\
// 	ctc2 	$8, $vi28		\n\
// 	sync.p					\n\
// 	":::"$8"); /* VU1 reset */
// 	DPUT_VIF0_FIFO(*(u_long128*)&(init_vif_regs[0]));
// 	DPUT_VIF0_FIFO(*(u_long128*)&(init_vif_regs[4]));
// }
