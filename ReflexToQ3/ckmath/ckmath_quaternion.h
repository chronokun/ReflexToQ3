//
//	Author:	Michael Cameron
//	Email:	chronokun@hotmail.com
//

#pragma once

#ifndef __MATH_QUATERNION_H__
#define __MATH_QUATERNION_H__

// Local Includes
#include "ckmath_types.h"

// Quaternion Function Prototypes

const TVector4d& IdentityQuaternion(TVector4d& _rResult);

const TVector4f& IdentityQuaternion(TVector4f& _rResult);

const TVector4d& ConjugateQuaternion(TVector4d& _rResult, const TVector4d& _krQuaternion);

const TVector4f& ConjugateQuaternion(TVector4f& _rResult, const TVector4f& _krQuaternion);

const TVector4d& InverseQuaternion(TVector4d& _rResult, const TVector4d& _krQuaternion);

const TVector4f& InverseQuaternion(TVector4f& _rResult, const TVector4f& _krQuaternion);

const TVector4d& UnitQuaternion(TVector4d& _rResult, const TVector4d& _krQuaternion);

const TVector4f& UnitQuaternion(TVector4f& _rResult, const TVector4f& _krQuaternion);

const TVector4d& AxisAngleQuaternion(TVector4d& _rResult, const TVector3d& _krAxis, const double _kdAngle);

const TVector4f& AxisAngleQuaternion(TVector4f& _rResult, const TVector3f& _krAxis, const float _kfAngle);

const double QuaternionMagnitude(const TVector4d& _krQuaternion);

const float QuaternionMagnitude(const TVector4f& _krQuaternion);

const TVector4d& QuaternionProduct(TVector4d& _rResult, const TVector4d& _krA, const TVector4d& _krB);

const TVector4f& QuaternionProduct(TVector4f& _rResult, const TVector4f& _krA, const TVector4f& _krB);

const TVector3d& QuaternionRotate(TVector3d& _rResult, const TVector3d& _krVector, const TVector4d& _krQuaternion);

const TVector3f& QuaternionRotate(TVector3f& _rResult, const TVector3f& _krVector, const TVector4f& _krQuaternion);

const TVector4d& Slerp(TVector4d& _rResult, const TVector4d& _krA, const TVector4d& _krB, const double _kdT);

const TVector4f& Slerp(TVector4f& _rResult, const TVector4f& _krA, const TVector4f& _krB, const float _kfT);


#endif