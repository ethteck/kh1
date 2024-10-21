/* SCE CONFIDENTIAL
 "PlayStation 2" Programmer Tool Runtime Library Release 2.5
 */
/* 
 *                      Emotion Engine Library
 *                          Version 0.10
 *                           Shift-JIS
 *
 *      Copyright (C) 1998-1999 Sony Computer Entertainment Inc.
 *                        All Rights Reserved.
 *
 *                        libvu0 - libvu0.h
 *                       Header File for VU0 Macro Code Library
 *
 *       Version        Date            Design      Log
 *  --------------------------------------------------------------------
 *       0.10           Mar,25,1999     shino 
 */

#ifndef _LIB_VU0_H_
#define _LIB_VU0_H_

#include "eetypes.h"

#ifdef __cplusplus
extern "C" {
#endif

// basic type
typedef int		qword[4] 	__attribute__ ((aligned(16)));
typedef int		sceVu0IVECTOR[4] __attribute__((aligned (16)));
typedef float		sceVu0FVECTOR[4] __attribute__((aligned (16)));
typedef float		sceVu0FMATRIX[4][4] __attribute__((aligned (16)));

// prototypes

/// @brief Copies vector v1 to v0
/// @param v0 Output vector
/// @param v1 Input vector
void sceVu0CopyVector(sceVu0FVECTOR v0, sceVu0FVECTOR v1);

/// @brief Copies X, Y, and Z elements of v1 to v0.
/// The W element of v0 is left unchanged.
/// @param v0 Output vector
/// @param v1 Input vector
void sceVu0CopyVectorXYZ(sceVu0FVECTOR v0, sceVu0FVECTOR v1);

/// @brief Convert each element of a floating-point vector to a fixed-point vector with 0-bit fractional part
/// @param v0 Output vector
/// @param v1 Input vector
void sceVu0FTOI0Vector(sceVu0IVECTOR v0, sceVu0FVECTOR v1);

/// @brief Convert each element of a floating-point vector to a fixed-point vector with 4-bit fractional part
/// @param v0 Output vector
/// @param v1 Input vector
void sceVu0FTOI4Vector(sceVu0IVECTOR v0, sceVu0FVECTOR v1);

/// @brief Convert each element of a fixed-point vector with 0-bit fractional part to a floating-point vector
/// @param v0 Output vector
/// @param v1 Input vector
void sceVu0ITOF0Vector(sceVu0FVECTOR v0, sceVu0IVECTOR v1);

/// @brief Convert each element of a fixed-point vector with 4-bit fractional part to a floating-point vector
/// @param v0 Output vector
/// @param v1 Input vector
void sceVu0ITOF4Vector(sceVu0FVECTOR v0, sceVu0IVECTOR v1);

/// @brief Multiply vector by scalar
/// @param v0 Output vector
/// @param v1 Input vector
/// @param s Input scalar
void sceVu0ScaleVector(sceVu0FVECTOR v0, sceVu0FVECTOR v1, float s);

/// @brief Multiply X, Y, and Z elements of an input vector by a scalar.
/// The W element of v1 is directly copied into v0 without modification.
/// @param v0 Output vector
/// @param v1 Input vector
/// @param s Input scalar
void sceVu0ScaleVectorXYZ(sceVu0FVECTOR v0, sceVu0FVECTOR v1, float s);

/// @brief Individually add the elements of v1 to the corresponding elements of v2 and store the result in v0
/// @param v0 Output vector
/// @param v1 Input vector
/// @param v2 Input vector
void sceVu0AddVector(sceVu0FVECTOR v0, sceVu0FVECTOR v1, sceVu0FVECTOR v2);

/// @brief Individually subtract the elements of v2 from the corresponding elements of v1 and store the result in v0
/// @param v0 Output vector
/// @param v1 Input vector
/// @param v2 Input vector
void sceVu0SubVector(sceVu0FVECTOR v0, sceVu0FVECTOR v1, sceVu0FVECTOR v2);

/// @brief Individually multiply the elements of v1 by the corresponding elements of v2 and store the result in v0
/// @param v0 Output vector
/// @param v1 Input vector
/// @param v2 Input vector
void sceVu0MulVector(sceVu0FVECTOR v0, sceVu0FVECTOR v1, sceVu0FVECTOR v2);

/// @brief Interpolation vector between two vectors and a parameter (v0 = v1*t + v2*(1-t))
/// @param v0 Output vector
/// @param v1 Input vector
/// @param v2 Input vector
/// @param r Interpolation parameter
void sceVu0InterVector(sceVu0FVECTOR v0, sceVu0FVECTOR v1, sceVu0FVECTOR v2, float r);

/// @brief Interpolation vector between two vectors and a parameter (v0 = v1*t + v2*(1-t)).
/// The W element of v1 is directly copied into v0 without modification.
/// @param v0 Output vector
/// @param v1 Input vector
/// @param v2 Input vector
/// @param r Interpolation parameter 
void sceVu0InterVectorXYZ(sceVu0FVECTOR v0, sceVu0FVECTOR v1, sceVu0FVECTOR v2, float r);

/// @brief Divide vector by scalar (v0 = v1 / q)
/// @param v0 Output vector
/// @param v1 Input vector
/// @param q Input scalar
void sceVu0DivVector(sceVu0FVECTOR v0, sceVu0FVECTOR v1, float q);

/// @brief Divide X, Y, and Z elements of an input vector by a scalar.
/// The W element of v1 is directly copied into v0 without modification.
/// @param v0 Output vector
/// @param v1 Input vector
/// @param q Input scalar
void sceVu0DivVectorXYZ(sceVu0FVECTOR v0, sceVu0FVECTOR v1, float q);

/// @brief Inner product of two vectors
/// @param v0 Input vector
/// @param v1 Input vector
/// @return Inner product of v0 and v1
float sceVu0InnerProduct(sceVu0FVECTOR v0, sceVu0FVECTOR v1);

/// @brief Outer product of two vectors
/// @param v0 Output vector
/// @param v1 Input vector
/// @param v2 Input vector
void sceVu0OuterProduct(sceVu0FVECTOR v0, sceVu0FVECTOR v1, sceVu0FVECTOR v2);

/// @brief Normalize a vector
/// @param v0 Output vector
/// @param v1 Input vector
void sceVu0Normalize(sceVu0FVECTOR v0, sceVu0FVECTOR v1);

/// @brief Multiply vector by matrix (v0 = m0 * v1)
/// @param v0 Output vector
/// @param m0 Input matrix
/// @param v1 Input vector
void sceVu0ApplyMatrix(sceVu0FVECTOR v0, sceVu0FMATRIX m, sceVu0FVECTOR v1);

/// @brief Generate a 4x4 unit matrix
/// @param m Output matrix
void sceVu0UnitMatrix(sceVu0FMATRIX m);

/// @brief Copy matrix m1 to m0
/// @param m0 Output matrix
/// @param m1 Input matrix
void sceVu0CopyMatrix(sceVu0FMATRIX m0, sceVu0FMATRIX m1);

/// @brief Transposed matrix of an input matrix
/// @param m0 Output matrix
/// @param m1 Input matrix
void sceVu0TransposeMatrix(sceVu0FMATRIX m0, sceVu0FMATRIX m1);

/// @brief Multiply two matrices (m0 = m1 * m2)
/// @param m0 Output matrix
/// @param m1 Input matrix
/// @param m2 Input matrix
void sceVu0MulMatrix(sceVu0FMATRIX m0, sceVu0FMATRIX m1, sceVu0FMATRIX m2);

/// @brief Inverse matrix of an input matrix
/// @param m0 Output matrix
/// @param m1 Input matrix, must be a regular (rotation or translation) matrix
void sceVu0InversMatrix(sceVu0FMATRIX m0, sceVu0FMATRIX m1);

/// @brief Only for use with RotMatrix functions. Finds the cosine and sine of an angle
/// @param t Valid range is -PI/2 to PI/2
static void _sceVu0ecossin(f32 t);

/// @brief Find the rotation matrix for rotatation about the X axis then multiply the input matrix by that matrix
/// @param m0 Output matrix
/// @param m1 Input matrix
/// @param rx Rotation angle. Valid range is -PI to PI
void sceVu0RotMatrixX(sceVu0FMATRIX m0, sceVu0FMATRIX m1, float rx);

/// @brief Find the rotation matrix for rotatation about the Y axis then multiply the input matrix by that matrix
/// @param m0 Output matrix
/// @param m1 Input matrix
/// @param ry Rotation angle. Valid range is -PI to PI
void sceVu0RotMatrixY(sceVu0FMATRIX m0, sceVu0FMATRIX m1, float ry);

/// @brief Find the rotation matrix for rotatation about the Z axis then multiply the input matrix by that matrix
/// @param m0 Output matrix
/// @param m1 Input matrix
/// @param rz Rotation angle. Valid range is -PI to PI
void sceVu0RotMatrixZ(sceVu0FMATRIX m0, sceVu0FMATRIX m1, float rz);

/// @brief Find the rotation matrix for rotatation about the Z, Y, and X axes,
/// then sequentially multiply the input matrix by those matrices
/// @param m0 Output matrix
/// @param m1 Input matrix
/// @param rot X, Y, and Z rotation angles. Valid range is -PI to PI
void sceVu0RotMatrix(sceVu0FMATRIX m0, sceVu0FMATRIX m1, sceVu0FVECTOR rot);

/// @brief Translate matrix using translation vector
/// @param m0 Output matrix
/// @param m1 Input matrix
/// @param tv Translation vector
void sceVu0TransMatrix(sceVu0FMATRIX m0, sceVu0FMATRIX m1, sceVu0FVECTOR tv);

/// @brief Generate world view matrix
/// @param m Output matrix
/// @param p Camera position in world coordinates
/// @param zd Line of sight direction
/// @param yd Vertical direction
void sceVu0CameraMatrix(sceVu0FMATRIX m, sceVu0FVECTOR p, sceVu0FVECTOR zd, sceVu0FVECTOR yd);

/// @brief Generate normal light matrix from light source directions
/// @param m Output matrix
/// @param l0 Light source 0 direction vector
/// @param l1 Light source 1 direction vector
/// @param l2 Light source 2 direction vector
void sceVu0NormalLightMatrix(sceVu0FMATRIX m, sceVu0FVECTOR l0, sceVu0FVECTOR l1, sceVu0FVECTOR l2);

/// @brief Generate light color matrix
/// @param m Output matrix containing light color
/// @param c0 Light source color 0
/// @param c1 Light source color 1
/// @param c2 Light source color 2
/// @param a Ambient light color
void sceVu0LightColorMatrix(sceVu0FMATRIX m, sceVu0FVECTOR c0, 
						sceVu0FVECTOR c1, sceVu0FVECTOR c2, sceVu0FVECTOR a);

/// @brief Generate view screen matrix
/// @param m Output matrix containing view screen
/// @param scrz Distance from viewpoint to screen
/// @param ax X-direction aspect ratio
/// @param ay Y-direction aspect ratio
/// @param cx X-coordinate of screen center
/// @param cy Y-coordinate of screen center
/// @param zmin Z-buffer minimum value
/// @param zmax Z-buffer maximum value
/// @param nearz Z of near clipping plane
/// @param farz Z of far clipping plane
void sceVu0ViewScreenMatrix(sceVu0FMATRIX m, float scrz, float ax, float ay, 
	float cx, float cy, float zmin, float zmax, float nearz, float farz);

/// @brief Generate drop shadow projection matrix
/// @param m Output matrix containing drop shadow projection
/// @param lp Light source position vector
/// @param a Projection plane of shadow
/// @param b Projection plane of shadow
/// @param c Projection plane of shadow
/// @param mode Light source type, 0 = Parallel, 1 = Point
void sceVu0DropShadowMatrix(sceVu0FMATRIX m, 
				sceVu0FVECTOR lp, float a, float b, float c, int mode);

/// @brief Check for clipping according to display range
/// @param minv Minimum value of the display range
/// @param maxv Maximum value of the display range
/// @param ms Model-screen matrix
/// @param vm Vertex vector pointer
/// @param n Number of vertices
/// @return 1 if all vertices are outside the display range
int sceVu0ClipAll(sceVu0FVECTOR minv, sceVu0FVECTOR maxv, sceVu0FMATRIX ms, sceVu0FVECTOR *vm, int n);

/// @brief Clamp each element of v1 to the range [min, max] and store the result in v0
/// @param v0 Output vector
/// @param v1 Input vector
/// @param min Minimum value
/// @param max Maximum value
void sceVu0ClampVector(sceVu0FVECTOR v0, sceVu0FVECTOR v1, float min, float max);

/// @brief Check for clipping outside of GS drawing range
/// @param v0 Input vector
/// @return 0 if vertex is inside the drawing range
int sceVu0ClipScreen(sceVu0FVECTOR v0);

/// @brief Check for clipping outside of GS drawing range
/// @param v0 Input vector
/// @param v1 Input vector
/// @param v2 Input vector
/// @return 0 if all vertices are inside the drawing range
int sceVu0ClipScreen3(sceVu0FVECTOR v0, sceVu0FVECTOR v1, sceVu0FVECTOR v2);

/// @brief Perspective transformation to screen coordinates on `n` vertices specified by `v1` using `m0`.
/// @param v0 Output pointer to vector representing screen coordinates
/// @param m0 Input matrix
/// @param v1 Input pointer to vector representing vertex
/// @param n Input number of vertices
/// @param mode Format of output values, 0 = Fixed-point with 4-bit fractional part, 1 = Fixed-point with 0-bit fractional part
void sceVu0RotTransPersN(sceVu0IVECTOR *v0, sceVu0FMATRIX m0, sceVu0FVECTOR *v1, int n, int mode);

/// @brief Perspective transformation to screen coordinates on a single vertex specified by `v1` using `m0`.
/// @param v0 Output vector representing screen coordinates
/// @param m0 Input perspective transformation matrix
/// @param v1 Input vertex representing vertex
/// @param mode Format of output values, 0 = Fixed-point with 4-bit fractional part, 1 = Fixed-point with 0-bit fractional part
void sceVu0RotTransPers(sceVu0IVECTOR v0, sceVu0FMATRIX m0, sceVu0FVECTOR v1, int mode);

/// @brief Initialize VU0 and VIF0
void sceVpu0Reset(void);

#ifdef __cplusplus
}
#endif

#endif /*  _LIB_VU0_H_ */
