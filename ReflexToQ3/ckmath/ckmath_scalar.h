//
//	Author:	Michael Cameron
//	Email:	chronokun@hotmail.com
//

#pragma once

#ifndef __MATH_SCALAR_H__
#define __MATH_SCALAR_H__

// Library Includes
#include <cmath>

// Scalar Function Prototypes

// double
inline const double Square(const double _kdScalar)
{
	return(_kdScalar * _kdScalar);
}

inline const double Magnitude(const double _kdScalar)
{
	return(abs(_kdScalar));
}

inline const double SquareRoot(const double _kdScalar)
{
	return(sqrt(_kdScalar));
}

inline const double ArcCos(const double _kdScalar)
{
	return(acos(_kdScalar));
}

inline const double ArcTan(const double _kdScalar)
{
	return(atan(_kdScalar));
}

inline const double ArcTan2(const double _kdX, const double _kdY)
{
	return(atan2(_kdX, _kdY));
}

inline const double Sine(const double _kdScalar)
{
	return(sin(_kdScalar));
}

inline const double Cosine(const double _kdScalar)
{
	return(cos(_kdScalar));
}

inline const bool Equal(const double _kdA, const double _kdB, const double _kdEpsilon)
{
	return((Magnitude(_kdA - _kdB) < _kdEpsilon));
}

// float
inline const float Square(const float _kfScalar)
{
	return(_kfScalar * _kfScalar);
}

inline const float Magnitude(const float _kfScalar)
{
	return(fabsf(_kfScalar));
}

inline const float SquareRoot(const float _kfScalar)
{
	return(sqrtf(_kfScalar));
}

inline const float ArcCos(const float _kfScalar)
{
	return(acosf(_kfScalar));
}

inline const float ArcTan(const float _kfScalar)
{
	return(atanf(_kfScalar));
}

inline const float ArcTan2(const float _kfX, const float _kfY)
{
	return(atan2f(_kfX, _kfY));
}

inline const float Sine(const float _kfScalar)
{
	return(sinf(_kfScalar));
}

inline const float Cosine(const float _kfScalar)
{
	return(cosf(_kfScalar));
}

inline const bool Equal(const float _kfA, const float _kfB, const float _kfEpsilon)
{
	return((Magnitude(_kfA - _kfB) < _kfEpsilon));
}


#endif