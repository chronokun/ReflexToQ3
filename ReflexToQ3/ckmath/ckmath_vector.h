//
//	Author:	Michael Cameron
//	Email:	chronokun@hotmail.com
//

#pragma once

#ifndef __MATH_VECTOR_H__
#define __MATH_VECTOR_H__

// Local Includes
#include "ckmath_types.h"

// Vector Function Prototypes


//
// Vector 4
//

const TVector4d& ZeroVector(TVector4d& _rResult);

const TVector4f& ZeroVector(TVector4f& _rResult);

const bool Equal(	const TVector4d& _krA,
					const TVector4d& _krB,
					const double _kdEpsilon);

const bool Equal(	const TVector4f& _krA,
					const TVector4f& _krB,
					const float _kfEpsilon);

const TVector4d& Add(	TVector4d& _rResult,
						const TVector4d& _krA, 
						const TVector4d& _krB);

const TVector4f& Add(	TVector4f& _rResult,
						const TVector4f& _krA, 
						const TVector4f& _krB);

const TVector4d& Subtract(	TVector4d& _rResult,
							const TVector4d& _krA,
							const TVector4d& _krB);

const TVector4f& Subtract(	TVector4f& _rResult,
							const TVector4f& _krA,
							const TVector4f& _krB);

const TVector4d& ScalarMultiply(TVector4d& _rResult,
								const TVector4d& _krV,
								const double _kdS);

const TVector4f& ScalarMultiply(TVector4f& _rResult,
								const TVector4f& _krV,
								const float _kfS);

const double VectorMagnitude(const TVector4d& _krV);

const float VectorMagnitude(const TVector4f& _krV);

const double DotProduct(const TVector4d& _krA,
						const TVector4d& _krB);

const float DotProduct(	const TVector4f& _krA,
						const TVector4f& _krB);

const TVector4d& Normalize(	TVector4d& _rResult,
							const TVector4d& _krV);

const TVector4f& Normalize(	TVector4f& _rResult,
							const TVector4f& _krV);

const TVector4d& Projection(TVector4d& _rResult,
							const TVector4d& _krA,
							const TVector4d& _krB);

const TVector4f& Projection(TVector4f& _rResult,
							const TVector4f& _krA,
							const TVector4f& _krB);

const double AngleBetween(	const TVector4d& _krA,
							const TVector4d& _krB);

const float AngleBetween(	const TVector4f& _krA,
							const TVector4f& _krB);

const double Distance(	const TVector4d& _krA,
						const TVector4d& _krB);

const float Distance(	const TVector4f& _krA,
						const TVector4f& _krB);

//
// Vector 3
//

const TVector3d& ZeroVector(TVector3d& _rResult);

const TVector3f& ZeroVector(TVector3f& _rResult);

const bool Equal(	const TVector3d& _krA,
					const TVector3d& _krB,
					const double _kdEpsilon);

const bool Equal(	const TVector3f& _krA,
					const TVector3f& _krB,
					const float _kfEpsilon);

const TVector3d& Add(	TVector3d& _rResult,
						const TVector3d& _krA, 
						const TVector3d& _krB);

const TVector3f& Add(	TVector3f& _rResult,
						const TVector3f& _krA, 
						const TVector3f& _krB);

const TVector3d& Subtract(	TVector3d& _rResult,
							const TVector3d& _krA,
							const TVector3d& _krB);

const TVector3f& Subtract(	TVector3f& _rResult,
							const TVector3f& _krA,
							const TVector3f& _krB);

const TVector3d& ScalarMultiply(TVector3d& _rResult,
								const TVector3d& _krV,
								const double _kdS);

const TVector3f& ScalarMultiply(TVector3f& _rResult,
								const TVector3f& _krV,
								const float _kfS);

const double VectorMagnitude(const TVector3d& _krV);

const float VectorMagnitude(const TVector3f& _krV);

const double DotProduct(const TVector3d& _krA,
						const TVector3d& _krB);

const float DotProduct(	const TVector3f& _krA,
						const TVector3f& _krB);

const TVector3d& CrossProduct(	TVector3d& _rResult,
								const TVector3d& _krA,
								const TVector3d& _krB);

const TVector3f& CrossProduct(	TVector3f& _rResult,
								const TVector3f& _krA,
								const TVector3f& _krB);

const TVector3d& Normalize(	TVector3d& _rResult,
							const TVector3d& _krV);

const TVector3f& Normalize(	TVector3f& _rResult,
							const TVector3f& _krV);

const TVector3d& Projection(TVector3d& _rResult,
							const TVector3d& _krA,
							const TVector3d& _krB);

const TVector3f& Projection(TVector3f& _rResult,
							const TVector3f& _krA,
							const TVector3f& _krB);

const double AngleBetween(	const TVector3d& _krA,
							const TVector3d& _krB);

const float AngleBetween(	const TVector3f& _krA,
							const TVector3f& _krB);

const double Distance(	const TVector3d& _krA,
						const TVector3d& _krB);

const float Distance(	const TVector3f& _krA,
						const TVector3f& _krB);

const double ScalarTripleProduct(	const TVector3d& _krA,
									const TVector3d& _krB,
									const TVector3d& _krC);

const float ScalarTripleProduct(	const TVector3f& _krA,
									const TVector3f& _krB,
									const TVector3f& _krC);

const TVector3d& VectorTripleProduct(	TVector3d& _rResult,
										const TVector3d& _krA,
										const TVector3d& _krB,
										const TVector3d& _krC);

const TVector3f& VectorTripleProduct(	TVector3f& _rResult,
										const TVector3f& _krA,
										const TVector3f& _krB,
										const TVector3f& _krC);

//
// Vector 2
//

const TVector2d& ZeroVector(TVector2d& _rResult);

const TVector2f& ZeroVector(TVector2f& _rResult);

const bool Equal(	const TVector2d& _krA,
					const TVector2d& _krB,
					const double _kdEpsilon);

const bool Equal(	const TVector2f& _krA,
					const TVector2f& _krB,
					const float _kfEpsilon);

const TVector2d& Add(	TVector2d& _rResult,
						const TVector2d& _krA, 
						const TVector2d& _krB);

const TVector2f& Add(	TVector2f& _rResult,
						const TVector2f& _krA, 
						const TVector2f& _krB);

const TVector2d& Subtract(	TVector2d& _rResult,
							const TVector2d& _krA,
							const TVector2d& _krB);

const TVector2f& Subtract(	TVector2f& _rResult,
							const TVector2f& _krA,
							const TVector2f& _krB);

const TVector2d& ScalarMultiply(TVector2d& _rResult,
								const TVector2d& _krV,
								const double _kdS);

const TVector2f& ScalarMultiply(TVector2f& _rResult,
								const TVector2f& _krV,
								const float _kfS);

const double VectorMagnitude(const TVector2d& _krV);

const float VectorMagnitude(const TVector2f& _krV);

const double DotProduct(const TVector2d& _krA,
						const TVector2d& _krB);

const float DotProduct(	const TVector2f& _krA,
						const TVector2f& _krB);

const TVector2d& Normalize(	TVector2d& _rResult,
							const TVector2d& _krV);

const TVector2f& Normalize(	TVector2f& _rResult,
							const TVector2f& _krV);

const TVector2d& Projection(TVector2d& _rResult,
							const TVector2d& _krA,
							const TVector2d& _krB);

const TVector2f& Projection(TVector2f& _rResult,
							const TVector2f& _krA,
							const TVector2f& _krB);

const double AngleBetween(	const TVector2d& _krA,
							const TVector2d& _krB);

const float AngleBetween(	const TVector2f& _krA,
							const TVector2f& _krB);

const double Distance(	const TVector2d& _krA,
						const TVector2d& _krB);

const float Distance(	const TVector2f& _krA,
						const TVector2f& _krB);


#endif