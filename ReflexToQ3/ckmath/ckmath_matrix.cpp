//
//	Author:	Michael Cameron
//	Email:	chronokun@hotmail.com
//

// Local Includes
#include "ckmath_matrix.h"
#include "ckmath_vector.h"
#include "ckmath_scalar.h"
#include "ckmath_quaternion.h"

//
// Matrix 4
//

const bool Equal(const TMatrix4d& _krA, const TMatrix4d& _krB, const double _kdEpsilon)
{
	const bool kbEqual =	(Magnitude(_krA.m_d11 - _krB.m_d11) < _kdEpsilon)
						&&	(Magnitude(_krA.m_d12 - _krB.m_d12) < _kdEpsilon)
						&&	(Magnitude(_krA.m_d13 - _krB.m_d13) < _kdEpsilon)
						&&	(Magnitude(_krA.m_d14 - _krB.m_d14) < _kdEpsilon)
						&&	(Magnitude(_krA.m_d21 - _krB.m_d21) < _kdEpsilon)
						&&	(Magnitude(_krA.m_d22 - _krB.m_d22) < _kdEpsilon)
						&&	(Magnitude(_krA.m_d23 - _krB.m_d23) < _kdEpsilon)
						&&	(Magnitude(_krA.m_d24 - _krB.m_d24) < _kdEpsilon)
						&&	(Magnitude(_krA.m_d31 - _krB.m_d31) < _kdEpsilon)
						&&	(Magnitude(_krA.m_d32 - _krB.m_d32) < _kdEpsilon)
						&&	(Magnitude(_krA.m_d33 - _krB.m_d33) < _kdEpsilon)
						&&	(Magnitude(_krA.m_d34 - _krB.m_d34) < _kdEpsilon)
						&&	(Magnitude(_krA.m_d41 - _krB.m_d41) < _kdEpsilon)
						&&	(Magnitude(_krA.m_d42 - _krB.m_d42) < _kdEpsilon)
						&&	(Magnitude(_krA.m_d43 - _krB.m_d43) < _kdEpsilon)
						&&	(Magnitude(_krA.m_d44 - _krB.m_d44) < _kdEpsilon);

	return(kbEqual);
}

const bool Equal(const TMatrix4f& _krA, const TMatrix4f& _krB, const float _kfEpsilon)
{
	const bool kbEqual =	(Magnitude(_krA.m_f11 - _krB.m_f11) < _kfEpsilon)
						&&	(Magnitude(_krA.m_f12 - _krB.m_f12) < _kfEpsilon)
						&&	(Magnitude(_krA.m_f13 - _krB.m_f13) < _kfEpsilon)
						&&	(Magnitude(_krA.m_f14 - _krB.m_f14) < _kfEpsilon)
						&&	(Magnitude(_krA.m_f21 - _krB.m_f21) < _kfEpsilon)
						&&	(Magnitude(_krA.m_f22 - _krB.m_f22) < _kfEpsilon)
						&&	(Magnitude(_krA.m_f23 - _krB.m_f23) < _kfEpsilon)
						&&	(Magnitude(_krA.m_f24 - _krB.m_f24) < _kfEpsilon)
						&&	(Magnitude(_krA.m_f31 - _krB.m_f31) < _kfEpsilon)
						&&	(Magnitude(_krA.m_f32 - _krB.m_f32) < _kfEpsilon)
						&&	(Magnitude(_krA.m_f33 - _krB.m_f33) < _kfEpsilon)
						&&	(Magnitude(_krA.m_f34 - _krB.m_f34) < _kfEpsilon)
						&&	(Magnitude(_krA.m_f41 - _krB.m_f41) < _kfEpsilon)
						&&	(Magnitude(_krA.m_f42 - _krB.m_f42) < _kfEpsilon)
						&&	(Magnitude(_krA.m_f43 - _krB.m_f43) < _kfEpsilon)
						&&	(Magnitude(_krA.m_f44 - _krB.m_f44) < _kfEpsilon);

	return(kbEqual);
}

const TMatrix4d& ZeroMatrix(TMatrix4d& _rResult)
{
	_rResult.m_d11 = 0.0; _rResult.m_d12 = 0.0; _rResult.m_d13 = 0.0; _rResult.m_d14 = 0.0;
	_rResult.m_d21 = 0.0; _rResult.m_d22 = 0.0; _rResult.m_d23 = 0.0; _rResult.m_d24 = 0.0;
	_rResult.m_d31 = 0.0; _rResult.m_d32 = 0.0; _rResult.m_d33 = 0.0; _rResult.m_d34 = 0.0;
	_rResult.m_d41 = 0.0; _rResult.m_d42 = 0.0; _rResult.m_d43 = 0.0; _rResult.m_d44 = 0.0;

	return(_rResult);
}

const TMatrix4f& ZeroMatrix(TMatrix4f& _rResult)
{
	_rResult.m_f11 = 0.0f; _rResult.m_f12 = 0.0f; _rResult.m_f13 = 0.0f; _rResult.m_f14 = 0.0f;
	_rResult.m_f21 = 0.0f; _rResult.m_f22 = 0.0f; _rResult.m_f23 = 0.0f; _rResult.m_f24 = 0.0f;
	_rResult.m_f31 = 0.0f; _rResult.m_f32 = 0.0f; _rResult.m_f33 = 0.0f; _rResult.m_f34 = 0.0f;
	_rResult.m_f41 = 0.0f; _rResult.m_f42 = 0.0f; _rResult.m_f43 = 0.0f; _rResult.m_f44 = 0.0f;

	return(_rResult);
}

const TMatrix4d& IdentityMatrix(TMatrix4d& _rResult)
{
	_rResult.m_d11 = 1.0; _rResult.m_d12 = 0.0; _rResult.m_d13 = 0.0; _rResult.m_d14 = 0.0;
	_rResult.m_d21 = 0.0; _rResult.m_d22 = 1.0; _rResult.m_d23 = 0.0; _rResult.m_d24 = 0.0;
	_rResult.m_d31 = 0.0; _rResult.m_d32 = 0.0; _rResult.m_d33 = 1.0; _rResult.m_d34 = 0.0;
	_rResult.m_d41 = 0.0; _rResult.m_d42 = 0.0; _rResult.m_d43 = 0.0; _rResult.m_d44 = 1.0;

	return(_rResult);
}

const TMatrix4f& IdentityMatrix(TMatrix4f& _rResult)
{
	_rResult.m_f11 = 1.0f; _rResult.m_f12 = 0.0f; _rResult.m_f13 = 0.0f; _rResult.m_f14 = 0.0f;
	_rResult.m_f21 = 0.0f; _rResult.m_f22 = 1.0f; _rResult.m_f23 = 0.0f; _rResult.m_f24 = 0.0f;
	_rResult.m_f31 = 0.0f; _rResult.m_f32 = 0.0f; _rResult.m_f33 = 1.0f; _rResult.m_f34 = 0.0f;
	_rResult.m_f41 = 0.0f; _rResult.m_f42 = 0.0f; _rResult.m_f43 = 0.0f; _rResult.m_f44 = 1.0f;

	return(_rResult);
}

const TMatrix4d& Multiply(TMatrix4d& _rResult,
								const TMatrix4d& _krA,
								const TMatrix4d& _krB)
{
	for(size_t y = 1; y <= 4; ++y)
	{
		for(size_t x = 1; x <= 4; ++x)
		{
			double dAccumulate = 0.0;
			for(size_t n = 1; n <= 4; ++n)
			{
				dAccumulate += GetElement(_krA, y, n) * GetElement(_krB, n, x);
			}
			SetElement(_rResult, dAccumulate, y, x);
		}
	}

	return(_rResult);
}

const TMatrix4f& Multiply(TMatrix4f& _rResult,
								const TMatrix4f& _krA,
								const TMatrix4f& _krB)
{
	for(size_t x = 1; x <= 4; ++x)
	{
		for(size_t y = 1; y <= 4; ++y)
		{
			float fAccumulate = 0.0;
			for(size_t n = 1; n <= 4; ++n)
			{
				fAccumulate += GetElement(_krA, y, n) * GetElement(_krB, n, x);
			}
			SetElement(_rResult, fAccumulate, y, x);
		}
	}

	return(_rResult);
}

const TMatrix4d& ScalarMultiply(	TMatrix4d& _rResult,
										const TMatrix4d& _krMatrix,
										const double _kdScalar)
{
	_rResult.m_d11 = _krMatrix.m_d11 * _kdScalar;
	_rResult.m_d12 = _krMatrix.m_d12 * _kdScalar;
	_rResult.m_d13 = _krMatrix.m_d13 * _kdScalar;
	_rResult.m_d14 = _krMatrix.m_d14 * _kdScalar;

	_rResult.m_d21 = _krMatrix.m_d21 * _kdScalar;
	_rResult.m_d22 = _krMatrix.m_d22 * _kdScalar;
	_rResult.m_d23 = _krMatrix.m_d23 * _kdScalar;
	_rResult.m_d24 = _krMatrix.m_d24 * _kdScalar;

	_rResult.m_d31 = _krMatrix.m_d31 * _kdScalar;
	_rResult.m_d32 = _krMatrix.m_d32 * _kdScalar;
	_rResult.m_d33 = _krMatrix.m_d33 * _kdScalar;
	_rResult.m_d34 = _krMatrix.m_d34 * _kdScalar;

	_rResult.m_d41 = _krMatrix.m_d41 * _kdScalar;
	_rResult.m_d42 = _krMatrix.m_d42 * _kdScalar;
	_rResult.m_d43 = _krMatrix.m_d43 * _kdScalar;
	_rResult.m_d44 = _krMatrix.m_d44 * _kdScalar;

	return(_rResult);
}

const TMatrix4f& ScalarMultiply(	TMatrix4f& _rResult,
										const TMatrix4f& _krMatrix,
										const float _kfScalar)
{
	_rResult.m_f11 = _krMatrix.m_f11 * _kfScalar;
	_rResult.m_f12 = _krMatrix.m_f12 * _kfScalar;
	_rResult.m_f13 = _krMatrix.m_f13 * _kfScalar;
	_rResult.m_f14 = _krMatrix.m_f14 * _kfScalar;

	_rResult.m_f21 = _krMatrix.m_f21 * _kfScalar;
	_rResult.m_f22 = _krMatrix.m_f22 * _kfScalar;
	_rResult.m_f23 = _krMatrix.m_f23 * _kfScalar;
	_rResult.m_f24 = _krMatrix.m_f24 * _kfScalar;

	_rResult.m_f31 = _krMatrix.m_f31 * _kfScalar;
	_rResult.m_f32 = _krMatrix.m_f32 * _kfScalar;
	_rResult.m_f33 = _krMatrix.m_f33 * _kfScalar;
	_rResult.m_f34 = _krMatrix.m_f34 * _kfScalar;

	_rResult.m_f41 = _krMatrix.m_f41 * _kfScalar;
	_rResult.m_f42 = _krMatrix.m_f42 * _kfScalar;
	_rResult.m_f43 = _krMatrix.m_f43 * _kfScalar;
	_rResult.m_f44 = _krMatrix.m_f44 * _kfScalar;

	return(_rResult);
}

const TVector4d& VectorMultiply(	TVector4d& _rResult,
										const TMatrix4d& _krA,
										const TVector4d& _krB)
{
	_rResult.m_dX = (_krA.m_d11 * _krB.m_dX) + (_krA.m_d12 * _krB.m_dY) + (_krA.m_d13 * _krB.m_dZ) + (_krA.m_d14 * _krB.m_dW);
	_rResult.m_dY = (_krA.m_d21 * _krB.m_dX) + (_krA.m_d22 * _krB.m_dY) + (_krA.m_d23 * _krB.m_dZ) + (_krA.m_d24 * _krB.m_dW);
	_rResult.m_dZ = (_krA.m_d31 * _krB.m_dX) + (_krA.m_d32 * _krB.m_dY) + (_krA.m_d33 * _krB.m_dZ) + (_krA.m_d34 * _krB.m_dW);
	_rResult.m_dW = (_krA.m_d41 * _krB.m_dX) + (_krA.m_d42 * _krB.m_dY) + (_krA.m_d43 * _krB.m_dZ) + (_krA.m_d44 * _krB.m_dW);

	return(_rResult);
}

const TVector4f& VectorMultiply(	TVector4f& _rResult,
										const TMatrix4f& _krA,
										const TVector4f& _krB)
{
	_rResult.m_fX = (_krA.m_f11 * _krB.m_fX) + (_krA.m_f12 * _krB.m_fY) + (_krA.m_f13 * _krB.m_fZ) + (_krA.m_f14 * _krB.m_fW);
	_rResult.m_fY = (_krA.m_f21 * _krB.m_fX) + (_krA.m_f22 * _krB.m_fY) + (_krA.m_f23 * _krB.m_fZ) + (_krA.m_f24 * _krB.m_fW);
	_rResult.m_fZ = (_krA.m_f31 * _krB.m_fX) + (_krA.m_f32 * _krB.m_fY) + (_krA.m_f33 * _krB.m_fZ) + (_krA.m_f34 * _krB.m_fW);
	_rResult.m_fW = (_krA.m_f41 * _krB.m_fX) + (_krA.m_f42 * _krB.m_fY) + (_krA.m_f43 * _krB.m_fZ) + (_krA.m_f44 * _krB.m_fW);

	return(_rResult);
}

const TMatrix4d& Add(	TMatrix4d& _rResult,
							const TMatrix4d& _krA,
							const TMatrix4d& _krB)
{
	_rResult.m_d11 = _krA.m_d11 + _krB.m_d11;
	_rResult.m_d12 = _krA.m_d12 + _krB.m_d12;
	_rResult.m_d13 = _krA.m_d13 + _krB.m_d13;
	_rResult.m_d14 = _krA.m_d14 + _krB.m_d14;

	_rResult.m_d21 = _krA.m_d21 + _krB.m_d21;
	_rResult.m_d22 = _krA.m_d22 + _krB.m_d22;
	_rResult.m_d23 = _krA.m_d23 + _krB.m_d23;
	_rResult.m_d24 = _krA.m_d24 + _krB.m_d24;

	_rResult.m_d31 = _krA.m_d31 + _krB.m_d31;
	_rResult.m_d32 = _krA.m_d32 + _krB.m_d32;
	_rResult.m_d33 = _krA.m_d33 + _krB.m_d33;
	_rResult.m_d34 = _krA.m_d34 + _krB.m_d34;

	_rResult.m_d41 = _krA.m_d41 + _krB.m_d41;
	_rResult.m_d42 = _krA.m_d42 + _krB.m_d42;
	_rResult.m_d43 = _krA.m_d43 + _krB.m_d43;
	_rResult.m_d44 = _krA.m_d44 + _krB.m_d44;

	return(_rResult);
}

const TMatrix4f& Add(	TMatrix4f& _rResult,
							const TMatrix4f& _krA,
							const TMatrix4f& _krB)
{
	_rResult.m_f11 = _krA.m_f11 + _krB.m_f11;
	_rResult.m_f12 = _krA.m_f12 + _krB.m_f12;
	_rResult.m_f13 = _krA.m_f13 + _krB.m_f13;
	_rResult.m_f14 = _krA.m_f14 + _krB.m_f14;

	_rResult.m_f21 = _krA.m_f21 + _krB.m_f21;
	_rResult.m_f22 = _krA.m_f22 + _krB.m_f22;
	_rResult.m_f23 = _krA.m_f23 + _krB.m_f23;
	_rResult.m_f24 = _krA.m_f24 + _krB.m_f24;

	_rResult.m_f31 = _krA.m_f31 + _krB.m_f31;
	_rResult.m_f32 = _krA.m_f32 + _krB.m_f32;
	_rResult.m_f33 = _krA.m_f33 + _krB.m_f33;
	_rResult.m_f34 = _krA.m_f34 + _krB.m_f34;

	_rResult.m_f41 = _krA.m_f41 + _krB.m_f41;
	_rResult.m_f42 = _krA.m_f42 + _krB.m_f42;
	_rResult.m_f43 = _krA.m_f43 + _krB.m_f43;
	_rResult.m_f44 = _krA.m_f44 + _krB.m_f44;

	return(_rResult);
}

const TMatrix4d& Transpose(	TMatrix4d& _rResult,
									const TMatrix4d& _krMatrix)
{
	_rResult.m_d11 = _krMatrix.m_d11; _rResult.m_d12 = _krMatrix.m_d21; _rResult.m_d13 = _krMatrix.m_d31; _rResult.m_d14 = _krMatrix.m_d41;
	_rResult.m_d21 = _krMatrix.m_d12; _rResult.m_d22 = _krMatrix.m_d22; _rResult.m_d23 = _krMatrix.m_d32; _rResult.m_d24 = _krMatrix.m_d42;
	_rResult.m_d31 = _krMatrix.m_d13; _rResult.m_d32 = _krMatrix.m_d23; _rResult.m_d33 = _krMatrix.m_d33; _rResult.m_d34 = _krMatrix.m_d43;
	_rResult.m_d41 = _krMatrix.m_d14; _rResult.m_d42 = _krMatrix.m_d24; _rResult.m_d43 = _krMatrix.m_d34; _rResult.m_d44 = _krMatrix.m_d44;

	return(_rResult);
}

const TMatrix4f& Transpose(	TMatrix4f& _rResult,
									const TMatrix4f& _krMatrix)
{
	_rResult.m_f11 = _krMatrix.m_f11; _rResult.m_f12 = _krMatrix.m_f21; _rResult.m_f13 = _krMatrix.m_f31; _rResult.m_f14 = _krMatrix.m_f41;
	_rResult.m_f21 = _krMatrix.m_f12; _rResult.m_f22 = _krMatrix.m_f22; _rResult.m_f23 = _krMatrix.m_f32; _rResult.m_f24 = _krMatrix.m_f42;
	_rResult.m_f31 = _krMatrix.m_f13; _rResult.m_f32 = _krMatrix.m_f23; _rResult.m_f33 = _krMatrix.m_f33; _rResult.m_f34 = _krMatrix.m_f43;
	_rResult.m_f41 = _krMatrix.m_f14; _rResult.m_f42 = _krMatrix.m_f24; _rResult.m_f43 = _krMatrix.m_f34; _rResult.m_f44 = _krMatrix.m_f44;

	return(_rResult);
}

const double GetElement(	const TMatrix4d& _krMatrix,
								const size_t _kRow,
								const size_t _kColumn)
{
	double dResult;

	if(_kRow == 1)
	{
		if(_kColumn == 1)
		{
			dResult = _krMatrix.m_d11;
		}
		else if(_kColumn == 2)
		{
			dResult = _krMatrix.m_d12;
		}
		else if(_kColumn == 3)
		{
			dResult = _krMatrix.m_d13;
		}
		else if(_kColumn == 4)
		{
			dResult = _krMatrix.m_d14;
		}
	}
	else if(_kRow == 2)
	{
		if(_kColumn == 1)
		{
			dResult = _krMatrix.m_d21;
		}
		else if(_kColumn == 2)
		{
			dResult = _krMatrix.m_d22;
		}
		else if(_kColumn == 3)
		{
			dResult = _krMatrix.m_d23;
		}
		else if(_kColumn == 4)
		{
			dResult = _krMatrix.m_d24;
		}
	}
	else if(_kRow == 3)
	{
		if(_kColumn == 1)
		{
			dResult = _krMatrix.m_d31;
		}
		else if(_kColumn == 2)
		{
			dResult = _krMatrix.m_d32;
		}
		else if(_kColumn == 3)
		{
			dResult = _krMatrix.m_d33;
		}
		else if(_kColumn == 4)
		{
			dResult = _krMatrix.m_d34;
		}
	}
	else if(_kRow == 4)
	{
		if(_kColumn == 1)
		{
			dResult = _krMatrix.m_d41;
		}
		else if(_kColumn == 2)
		{
			dResult = _krMatrix.m_d42;
		}
		else if(_kColumn == 3)
		{
			dResult = _krMatrix.m_d43;
		}
		else if(_kColumn == 4)
		{
			dResult = _krMatrix.m_d44;
		}
	}

	return(dResult);
}

const float GetElement(	const TMatrix4f& _krMatrix,
								const size_t _kRow,
								const size_t _kColumn)
{
	float fResult;

	if(_kRow == 1)
	{
		if(_kColumn == 1)
		{
			fResult = _krMatrix.m_f11;
		}
		else if(_kColumn == 2)
		{
			fResult = _krMatrix.m_f12;
		}
		else if(_kColumn == 3)
		{
			fResult = _krMatrix.m_f13;
		}
		else if(_kColumn == 4)
		{
			fResult = _krMatrix.m_f14;
		}
	}
	else if(_kRow == 2)
	{
		if(_kColumn == 1)
		{
			fResult = _krMatrix.m_f21;
		}
		else if(_kColumn == 2)
		{
			fResult = _krMatrix.m_f22;
		}
		else if(_kColumn == 3)
		{
			fResult = _krMatrix.m_f23;
		}
		else if(_kColumn == 4)
		{
			fResult = _krMatrix.m_f24;
		}
	}
	else if(_kRow == 3)
	{
		if(_kColumn == 1)
		{
			fResult = _krMatrix.m_f31;
		}
		else if(_kColumn == 2)
		{
			fResult = _krMatrix.m_f32;
		}
		else if(_kColumn == 3)
		{
			fResult = _krMatrix.m_f33;
		}
		else if(_kColumn == 4)
		{
			fResult = _krMatrix.m_f34;
		}
	}
	else if(_kRow == 4)
	{
		if(_kColumn == 1)
		{
			fResult = _krMatrix.m_f41;
		}
		else if(_kColumn == 2)
		{
			fResult = _krMatrix.m_f42;
		}
		else if(_kColumn == 3)
		{
			fResult = _krMatrix.m_f43;
		}
		else if(_kColumn == 4)
		{
			fResult = _krMatrix.m_f44;
		}
	}

	return(fResult);
}


TMatrix4d& SetElement(	TMatrix4d& _rResult,
								const double _kdValue,
								const size_t _kRow,
								const size_t _kColumn)
{
	if(_kRow == 1)
	{
		if(_kColumn == 1)
		{
			_rResult.m_d11 = _kdValue;
		}
		else if(_kColumn == 2)
		{
			_rResult.m_d12 = _kdValue;
		}
		else if(_kColumn == 3)
		{
			_rResult.m_d13 = _kdValue;
		}
		else if(_kColumn == 4)
		{
			_rResult.m_d14 = _kdValue;
		}
	}
	else if(_kRow == 2)
	{
		if(_kColumn == 1)
		{
			_rResult.m_d21 = _kdValue;
		}
		else if(_kColumn == 2)
		{
			_rResult.m_d22 = _kdValue;
		}
		else if(_kColumn == 3)
		{
			_rResult.m_d23 = _kdValue;
		}
		else if(_kColumn == 4)
		{
			_rResult.m_d24 = _kdValue;
		}
	}
	else if(_kRow == 3)
	{
		if(_kColumn == 1)
		{
			_rResult.m_d31 = _kdValue;
		}
		else if(_kColumn == 2)
		{
			_rResult.m_d32 = _kdValue;
		}
		else if(_kColumn == 3)
		{
			_rResult.m_d33 = _kdValue;
		}
		else if(_kColumn == 4)
		{
			_rResult.m_d34 = _kdValue;
		}
	}
	else if(_kRow == 4)
	{
		if(_kColumn == 1)
		{
			_rResult.m_d41 = _kdValue;
		}
		else if(_kColumn == 2)
		{
			_rResult.m_d42 = _kdValue;
		}
		else if(_kColumn == 3)
		{
			_rResult.m_d43 = _kdValue;
		}
		else if(_kColumn == 4)
		{
			_rResult.m_d44 = _kdValue;
		}
	}

	return(_rResult);
}

TMatrix4f& SetElement(	TMatrix4f& _rResult,
								const float _kfValue,
								const size_t _kRow,
								const size_t _kColumn)
{
	if(_kRow == 1)
	{
		if(_kColumn == 1)
		{
			_rResult.m_f11 = _kfValue;
		}
		else if(_kColumn == 2)
		{
			_rResult.m_f12 = _kfValue;
		}
		else if(_kColumn == 3)
		{
			_rResult.m_f13 = _kfValue;
		}
		else if(_kColumn == 4)
		{
			_rResult.m_f14 = _kfValue;
		}
	}
	else if(_kRow == 2)
	{
		if(_kColumn == 1)
		{
			_rResult.m_f21 = _kfValue;
		}
		else if(_kColumn == 2)
		{
			_rResult.m_f22 = _kfValue;
		}
		else if(_kColumn == 3)
		{
			_rResult.m_f23 = _kfValue;
		}
		else if(_kColumn == 4)
		{
			_rResult.m_f24 = _kfValue;
		}
	}
	else if(_kRow == 3)
	{
		if(_kColumn == 1)
		{
			_rResult.m_f31 = _kfValue;
		}
		else if(_kColumn == 2)
		{
			_rResult.m_f32 = _kfValue;
		}
		else if(_kColumn == 3)
		{
			_rResult.m_f33 = _kfValue;
		}
		else if(_kColumn == 4)
		{
			_rResult.m_f34 = _kfValue;
		}
	}
	else if(_kRow == 4)
	{
		if(_kColumn == 1)
		{
			_rResult.m_f41 = _kfValue;
		}
		else if(_kColumn == 2)
		{
			_rResult.m_f42 = _kfValue;
		}
		else if(_kColumn == 3)
		{
			_rResult.m_f43 = _kfValue;
		}
		else if(_kColumn == 4)
		{
			_rResult.m_f44 = _kfValue;
		}
	}

	return(_rResult);
}

const TMatrix3d& Submatrix(	TMatrix3d& _rResult, 
									const TMatrix4d& _krMatrix,
									const size_t _kDeletedRow,
									const size_t _kDeletedColumn)
{
	for(size_t i = 1; i <= 4; ++i)
	{
		for(size_t j = 1; j <= 4; ++j)
		{
			if(		(i != _kDeletedRow)
				&&	(j != _kDeletedColumn))
			{
				size_t InsertI;
				size_t InsertJ;
				if(i < _kDeletedRow)
				{
					InsertI = i;
				}
				else
				{
					InsertI = i-1;
				}
				if(j < _kDeletedColumn)
				{
					InsertJ = j;
				}
				else
				{
					InsertJ = j-1;
				}

				SetElement(_rResult, GetElement(_krMatrix, i, j), InsertI, InsertJ);
			}
		}
	}

	return(_rResult);
}

const TMatrix3f& Submatrix(	TMatrix3f& _rResult, 
									const TMatrix4f& _krMatrix,
									const size_t _kDeletedRow,
									const size_t _kDeletedColumn)
{
	for(size_t i = 1; i <= 4; ++i)
	{
		for(size_t j = 1; j <= 4; ++j)
		{
			if(		(i != _kDeletedRow)
				&&	(j != _kDeletedColumn))
			{
				size_t InsertI;
				size_t InsertJ;
				if(i < _kDeletedRow)
				{
					InsertI = i;
				}
				else
				{
					InsertI = i-1;
				}
				if(j < _kDeletedColumn)
				{
					InsertJ = j;
				}
				else
				{
					InsertJ = j-1;
				}

				SetElement(_rResult, GetElement(_krMatrix, i, j), InsertI, InsertJ);
			}
		}
	}

	return(_rResult);
}

const double FirstMinor(	const TMatrix4d& _krMatrix,
								const size_t _kRow,
								const size_t _kColumn)
{
	const TMatrix3d kSubmatrix = Submatrix(TMatrix3d(), _krMatrix, _kRow, _kColumn);
	
	return(Determinant(kSubmatrix));
}

const float FirstMinor(	const TMatrix4f& _krMatrix,
								const size_t _kRow,
								const size_t _kColumn)
{
	const TMatrix3f kSubmatrix = Submatrix(TMatrix3f(), _krMatrix, _kRow, _kColumn);
	
	return(Determinant(kSubmatrix));
}

const TMatrix4d& MatrixOfMinors(	TMatrix4d& _rResult,
										const TMatrix4d& _krMatrix)
{
	_rResult.m_d11 = FirstMinor(_krMatrix, 1, 1);
	_rResult.m_d12 = FirstMinor(_krMatrix, 1, 2);
	_rResult.m_d13 = FirstMinor(_krMatrix, 1, 3);
	_rResult.m_d14 = FirstMinor(_krMatrix, 1, 4);

	_rResult.m_d21 = FirstMinor(_krMatrix, 2, 1);
	_rResult.m_d22 = FirstMinor(_krMatrix, 2, 2);
	_rResult.m_d23 = FirstMinor(_krMatrix, 2, 3);
	_rResult.m_d24 = FirstMinor(_krMatrix, 2, 4);

	_rResult.m_d31 = FirstMinor(_krMatrix, 3, 1);
	_rResult.m_d32 = FirstMinor(_krMatrix, 3, 2);
	_rResult.m_d33 = FirstMinor(_krMatrix, 3, 3);
	_rResult.m_d34 = FirstMinor(_krMatrix, 3, 4);

	_rResult.m_d41 = FirstMinor(_krMatrix, 4, 1);
	_rResult.m_d42 = FirstMinor(_krMatrix, 4, 2);
	_rResult.m_d43 = FirstMinor(_krMatrix, 4, 3);
	_rResult.m_d44 = FirstMinor(_krMatrix, 4, 4);

	return(_rResult);
}

const TMatrix4f& MatrixOfMinors(	TMatrix4f& _rResult,
										const TMatrix4f& _krMatrix)
{
	_rResult.m_f11 = FirstMinor(_krMatrix, 1, 1);
	_rResult.m_f12 = FirstMinor(_krMatrix, 1, 2);
	_rResult.m_f13 = FirstMinor(_krMatrix, 1, 3);
	_rResult.m_f14 = FirstMinor(_krMatrix, 1, 4);

	_rResult.m_f21 = FirstMinor(_krMatrix, 2, 1);
	_rResult.m_f22 = FirstMinor(_krMatrix, 2, 2);
	_rResult.m_f23 = FirstMinor(_krMatrix, 2, 3);
	_rResult.m_f24 = FirstMinor(_krMatrix, 2, 4);

	_rResult.m_f31 = FirstMinor(_krMatrix, 3, 1);
	_rResult.m_f32 = FirstMinor(_krMatrix, 3, 2);
	_rResult.m_f33 = FirstMinor(_krMatrix, 3, 3);
	_rResult.m_f34 = FirstMinor(_krMatrix, 3, 4);

	_rResult.m_f41 = FirstMinor(_krMatrix, 4, 1);
	_rResult.m_f42 = FirstMinor(_krMatrix, 4, 2);
	_rResult.m_f43 = FirstMinor(_krMatrix, 4, 3);
	_rResult.m_f44 = FirstMinor(_krMatrix, 4, 4);

	return(_rResult);
}

const TMatrix4d& MatrixOfCofactors(	TMatrix4d& _rResult,
											const TMatrix4d& _krMatrix)
{
	_rResult = MatrixOfMinors(_rResult, _krMatrix);

	_rResult.m_d12 *= -1.0;
	_rResult.m_d14 *= -1.0;

	_rResult.m_d21 *= -1.0;
	_rResult.m_d23 *= -1.0;

	_rResult.m_d32 *= -1.0;
	_rResult.m_d34 *= -1.0;

	_rResult.m_d41 *= -1.0;
	_rResult.m_d43 *= -1.0;

	return(_rResult);
}

const TMatrix4f& MatrixOfCofactors(	TMatrix4f& _rResult,
											const TMatrix4f& _krMatrix)
{
	_rResult = MatrixOfMinors(_rResult, _krMatrix);

	_rResult.m_f12 *= -1.0f;
	_rResult.m_f14 *= -1.0f;

	_rResult.m_f21 *= -1.0f;
	_rResult.m_f23 *= -1.0f;

	_rResult.m_f32 *= -1.0f;
	_rResult.m_f34 *= -1.0f;

	_rResult.m_f41 *= -1.0f;
	_rResult.m_f43 *= -1.0f;

	return(_rResult);
}

const double Determinant(const TMatrix4d& _krMatrix)
{
	const double kdDeterminant =	(_krMatrix.m_d11 * FirstMinor(_krMatrix, 1, 1))
								-	(_krMatrix.m_d12 * FirstMinor(_krMatrix, 1, 2))
								+	(_krMatrix.m_d13 * FirstMinor(_krMatrix, 1, 3))
								-	(_krMatrix.m_d14 * FirstMinor(_krMatrix, 1, 4));

	return(kdDeterminant);
}

const float Determinant(const TMatrix4f& _krMatrix)
{
	const float kfDeterminant =		(_krMatrix.m_f11 * FirstMinor(_krMatrix, 1, 1))
								-	(_krMatrix.m_f12 * FirstMinor(_krMatrix, 1, 2))
								+	(_krMatrix.m_f13 * FirstMinor(_krMatrix, 1, 3))
								-	(_krMatrix.m_f14 * FirstMinor(_krMatrix, 1, 4));

	return(kfDeterminant);
}

const TMatrix4d& Inverse(	TMatrix4d& _rResult,
								const TMatrix4d& _krMatrix)
{
	_rResult = ScalarMultiply(_rResult,
									Transpose(TMatrix4d(),
													MatrixOfCofactors(TMatrix4d(), _krMatrix)),
									1.0/Determinant(_krMatrix));

	return(_rResult);
}

const TMatrix4f& Inverse(	TMatrix4f& _rResult,
								const TMatrix4f& _krMatrix)
{
	_rResult = ScalarMultiply(_rResult,
									Transpose(TMatrix4f(),
													MatrixOfCofactors(TMatrix4f(), _krMatrix)),
									1.0f/Determinant(_krMatrix));

	return(_rResult);
}

const TMatrix4d& TranslationMatrix(	TMatrix4d& _rResult,
											const TVector3d& _krVector)
{
	_rResult.m_d11 = 1.0; _rResult.m_d12 = 0.0; _rResult.m_d13 = 0.0; _rResult.m_d14 = _krVector.m_dX;
	_rResult.m_d21 = 0.0; _rResult.m_d22 = 1.0; _rResult.m_d23 = 0.0; _rResult.m_d24 = _krVector.m_dY;
	_rResult.m_d31 = 0.0; _rResult.m_d32 = 0.0; _rResult.m_d33 = 1.0; _rResult.m_d34 = _krVector.m_dZ;
	_rResult.m_d41 = 0.0; _rResult.m_d42 = 0.0; _rResult.m_d43 = 0.0; _rResult.m_d44 = 1.0;

	return(_rResult);
}

const TMatrix4f& TranslationMatrix(	TMatrix4f& _rResult,
											const TVector3f& _krVector)
{
	_rResult.m_f11 = 1.0f; _rResult.m_f12 = 0.0f; _rResult.m_f13 = 0.0f; _rResult.m_f14 = _krVector.m_fX;
	_rResult.m_f21 = 0.0f; _rResult.m_f22 = 1.0f; _rResult.m_f23 = 0.0f; _rResult.m_f24 = _krVector.m_fY;
	_rResult.m_f31 = 0.0f; _rResult.m_f32 = 0.0f; _rResult.m_f33 = 1.0f; _rResult.m_f34 = _krVector.m_fZ;
	_rResult.m_f41 = 0.0f; _rResult.m_f42 = 0.0f; _rResult.m_f43 = 0.0f; _rResult.m_f44 = 1.0f;

	return(_rResult);
}

const TMatrix4d& ScalingMatrix(	TMatrix4d& _rResult,
										const double _kdX,
										const double _kdY,
										const double _kdZ)
{
	_rResult.m_d11 = _kdX; _rResult.m_d12 = 0.0; _rResult.m_d13 = 0.0; _rResult.m_d14 = 0.0;
	_rResult.m_d21 = 0.0; _rResult.m_d22 = _kdY; _rResult.m_d23 = 0.0; _rResult.m_d24 = 0.0;
	_rResult.m_d31 = 0.0; _rResult.m_d32 = 0.0; _rResult.m_d33 = _kdZ; _rResult.m_d34 = 0.0;
	_rResult.m_d41 = 0.0; _rResult.m_d42 = 0.0; _rResult.m_d43 = 0.0; _rResult.m_d44 = 1.0;

	return(_rResult);
}

const TMatrix4f& ScalingMatrix(	TMatrix4f& _rResult,
										const float _kfX,
										const float _kfY,
										const float _kfZ)
{
	_rResult.m_f11 = _kfX; _rResult.m_f12 = 0.0f; _rResult.m_f13 = 0.0f; _rResult.m_f14 = 0.0f;
	_rResult.m_f21 = 0.0f; _rResult.m_f22 = _kfY; _rResult.m_f23 = 0.0f; _rResult.m_f24 = 0.0f;
	_rResult.m_f31 = 0.0f; _rResult.m_f32 = 0.0f; _rResult.m_f33 = _kfZ; _rResult.m_f34 = 0.0f;
	_rResult.m_f41 = 0.0f; _rResult.m_f42 = 0.0f; _rResult.m_f43 = 0.0f; _rResult.m_f44 = 1.0f;

	return(_rResult);
}

const TMatrix4d& TransformationMatrix(TMatrix4d& _rResult,
											const TVector3d& _krBasisX,
											const TVector3d& _krBasisY,
											const TVector3d& _krBasisZ,
											const TVector3d& _krTranslation)
{
	_rResult.m_d11 = _krBasisX.m_dX; _rResult.m_d12 = _krBasisY.m_dX; _rResult.m_d13 = _krBasisZ.m_dX; _rResult.m_d14 = _krTranslation.m_dX;
	_rResult.m_d21 = _krBasisX.m_dY; _rResult.m_d22 = _krBasisY.m_dY; _rResult.m_d23 = _krBasisZ.m_dY; _rResult.m_d24 = _krTranslation.m_dY;
	_rResult.m_d31 = _krBasisX.m_dZ; _rResult.m_d32 = _krBasisY.m_dZ; _rResult.m_d33 = _krBasisZ.m_dZ; _rResult.m_d34 = _krTranslation.m_dZ;

	_rResult.m_d41 = 0.0; _rResult.m_d42 = 0.0; _rResult.m_d43 = 0.0; _rResult.m_d44 = 1.0;

	return(_rResult);
}

const TMatrix4f& TransformationMatrix(TMatrix4f& _rResult,
											const TVector3f& _krBasisX,
											const TVector3f& _krBasisY,
											const TVector3f& _krBasisZ,
											const TVector3f& _krTranslation)
{
	_rResult.m_f11 = _krBasisX.m_fX; _rResult.m_f12 = _krBasisY.m_fX; _rResult.m_f13 = _krBasisZ.m_fX; _rResult.m_f14 = _krTranslation.m_fX;
	_rResult.m_f21 = _krBasisX.m_fY; _rResult.m_f22 = _krBasisY.m_fY; _rResult.m_f23 = _krBasisZ.m_fY; _rResult.m_f24 = _krTranslation.m_fY;
	_rResult.m_f31 = _krBasisX.m_fZ; _rResult.m_f32 = _krBasisY.m_fZ; _rResult.m_f33 = _krBasisZ.m_fZ; _rResult.m_f34 = _krTranslation.m_fZ;

	_rResult.m_f41 = 0.0f; _rResult.m_f42 = 0.0f; _rResult.m_f43 = 0.0f; _rResult.m_f44 = 1.0f;

	return(_rResult);
}

const TMatrix4d& RotationMatrix(	TMatrix4d& _rResult,
											const TVector4d& _krQuaternion)
{
	_rResult = TransformationMatrix(	_rResult,
											QuaternionRotate(TVector3d(), TVector3d{1.0, 0.0, 0.0}, _krQuaternion),
											QuaternionRotate(TVector3d(), TVector3d{0.0, 1.0, 0.0}, _krQuaternion),
											QuaternionRotate(TVector3d(), TVector3d{0.0, 0.0, 1.0}, _krQuaternion),
											TVector3d{0.0, 0.0, 0.0});

	return(_rResult);
}

const TMatrix4f& RotationMatrix(	TMatrix4f& _rResult,
											const TVector4f& _krQuaternion)
{
	_rResult = TransformationMatrix(	_rResult,
											QuaternionRotate(TVector3f(), TVector3f{1.0f, 0.0f, 0.0f}, _krQuaternion),
											QuaternionRotate(TVector3f(), TVector3f{0.0f, 1.0f, 0.0f}, _krQuaternion),
											QuaternionRotate(TVector3f(), TVector3f{0.0f, 0.0f, 1.0f}, _krQuaternion),
											TVector3f{0.0f, 0.0f, 0.0f});

	return(_rResult);
}

const TMatrix4d& AxisRotationXMatrix(	TMatrix4d& _rResult,
												const double _kdAngle)
{
	_rResult.m_d11 = 1.0; _rResult.m_d12 = 0.0;						_rResult.m_d13 = 0.0;						_rResult.m_d14 = 0.0;
	_rResult.m_d21 = 0.0; _rResult.m_d22 = Cosine(_kdAngle);	_rResult.m_d23 = -Sine(_kdAngle);		_rResult.m_d24 = 0.0;
	_rResult.m_d31 = 0.0; _rResult.m_d32 = Sine(_kdAngle);	_rResult.m_d33 = Cosine(_kdAngle);	_rResult.m_d34 = 0.0;
	_rResult.m_d41 = 0.0; _rResult.m_d42 = 0.0;						_rResult.m_d43 = 0.0;						_rResult.m_d44 = 1.0;

	return(_rResult);
}

const TMatrix4f& AxisRotationXMatrix(	TMatrix4f& _rResult,
												const float _kfAngle)
{
	_rResult.m_f11 = 1.0f; _rResult.m_f12 = 0.0f;						_rResult.m_f13 = 0.0f;						_rResult.m_f14 = 0.0f;
	_rResult.m_f21 = 0.0f; _rResult.m_f22 = Cosine(_kfAngle);		_rResult.m_f23 = -Sine(_kfAngle);		_rResult.m_f24 = 0.0f;
	_rResult.m_f31 = 0.0f; _rResult.m_f32 = Sine(_kfAngle);		_rResult.m_f33 = Cosine(_kfAngle);	_rResult.m_f34 = 0.0f;
	_rResult.m_f41 = 0.0f; _rResult.m_f42 = 0.0f;						_rResult.m_f43 = 0.0f;						_rResult.m_f44 = 1.0f;

	return(_rResult);
}

const TMatrix4d& AxisRotationYMatrix(	TMatrix4d& _rResult,
												const double _kdAngle)
{
	_rResult.m_d11 = Cosine(_kdAngle);	_rResult.m_d12 = 0.0;	_rResult.m_d13 = Sine(_kdAngle);		_rResult.m_d14 = 0.0;
	_rResult.m_d21 = 0.0;						_rResult.m_d22 = 1.0;	_rResult.m_d23 = 0.0;						_rResult.m_d24 = 0.0;
	_rResult.m_d31 = -Sine(_kdAngle);		_rResult.m_d32 = 0.0;	_rResult.m_d33 = Cosine(_kdAngle);	_rResult.m_d34 = 0.0;
	_rResult.m_d41 = 0.0;						_rResult.m_d42 = 0.0;	_rResult.m_d43 = 0.0;						_rResult.m_d44 = 1.0;

	return(_rResult);
}

const TMatrix4f& AxisRotationYMatrix(	TMatrix4f& _rResult,
												const float _kfAngle)
{
	_rResult.m_f11 = Cosine(_kfAngle);	_rResult.m_f12 = 0.0f;	_rResult.m_f13 = Sine(_kfAngle);		_rResult.m_f14 = 0.0f;
	_rResult.m_f21 = 0.0f;						_rResult.m_f22 = 1.0f;	_rResult.m_f23 = 0.0f;						_rResult.m_f24 = 0.0f;
	_rResult.m_f31 = -Sine(_kfAngle);		_rResult.m_f32 = 0.0f;	_rResult.m_f33 = Cosine(_kfAngle);	_rResult.m_f34 = 0.0f;
	_rResult.m_f41 = 0.0f;						_rResult.m_f42 = 0.0f;	_rResult.m_f43 = 0.0f;						_rResult.m_f44 = 1.0f;

	return(_rResult);
}

const TMatrix4d& AxisRotationZMatrix(	TMatrix4d& _rResult,
												const double _kdAngle)
{
	_rResult.m_d11 = Cosine(_kdAngle);	_rResult.m_d12 = -Sine(_kdAngle);		_rResult.m_d13 = 0.0;	_rResult.m_d14 = 0.0;
	_rResult.m_d21 = Sine(_kdAngle);		_rResult.m_d22 = Cosine(_kdAngle);	_rResult.m_d23 = 0.0;	_rResult.m_d24 = 0.0;
	_rResult.m_d31 = 0.0;						_rResult.m_d32 = 0.0;						_rResult.m_d33 = 1.0;	_rResult.m_d34 = 0.0;
	_rResult.m_d41 = 0.0;						_rResult.m_d42 = 0.0;						_rResult.m_d43 = 0.0;	_rResult.m_d44 = 1.0;

	return(_rResult);
}

const TMatrix4f& AxisRotationZMatrix(	TMatrix4f& _rResult,
												const float _kfAngle)
{
	_rResult.m_f11 = Cosine(_kfAngle);	_rResult.m_f12 = -Sine(_kfAngle);		_rResult.m_f13 = 0.0f;	_rResult.m_f14 = 0.0f;
	_rResult.m_f21 = Sine(_kfAngle);		_rResult.m_f22 = Cosine(_kfAngle);	_rResult.m_f23 = 0.0f;	_rResult.m_f24 = 0.0f;
	_rResult.m_f31 = 0.0f;						_rResult.m_f32 = 0.0f;						_rResult.m_f33 = 1.0f;	_rResult.m_f34 = 0.0f;
	_rResult.m_f41 = 0.0f;						_rResult.m_f42 = 0.0f;						_rResult.m_f43 = 0.0f;	_rResult.m_f44 = 1.0f;

	return(_rResult);
}

const TMatrix4d& PerspectiveMatrix(	TMatrix4d& _rResult,
											const double _kdLeft,	const double _kdRight,
											const double _kdBottom,	const double _kdTop,
											const double _kdFar,	const double _kdNear)
{
	_rResult.m_d11 = ((2.0 * _kdNear) / (_kdRight - _kdLeft));	_rResult.m_d12 = 0.0;										_rResult.m_d13 = ((_kdRight + _kdLeft) / (_kdRight - _kdLeft));	_rResult.m_d14 = 0.0;
	_rResult.m_d21 = 0.0;										_rResult.m_d22 = ((2.0 * _kdNear) / (_kdTop - _kdBottom));	_rResult.m_d23 = ((_kdTop + _kdBottom) / (_kdTop - _kdBottom));	_rResult.m_d24 = 0.0;
	_rResult.m_d31 = 0.0;										_rResult.m_d32 = 0.0;										_rResult.m_d33 = (-(_kdFar + _kdNear) / (_kdFar - _kdNear));	_rResult.m_d34 = ((-2.0 * _kdFar * _kdNear) / (_kdFar - _kdNear));
	_rResult.m_d41 = 0.0;										_rResult.m_d42 = 0.0;										_rResult.m_d43 = -1.0;											_rResult.m_d44 = 0.0;

	return(_rResult);
}

const TMatrix4f& PerspectiveMatrix(	TMatrix4f& _rResult,
											const float _kfLeft,	const float _kfRight,
											const float _kfBottom,	const float _kfTop,
											const float _kfFar,		const float _kfNear)
{
	_rResult.m_f11 = ((2.0f * _kfNear) / (_kfRight - _kfLeft));	_rResult.m_f12 = 0.0f;										_rResult.m_f13 = ((_kfRight + _kfLeft) / (_kfRight - _kfLeft));	_rResult.m_f14 = 0.0f;
	_rResult.m_f21 = 0.0f;										_rResult.m_f22 = ((2.0f * _kfNear) / (_kfTop - _kfBottom));	_rResult.m_f23 = ((_kfTop + _kfBottom) / (_kfTop - _kfBottom));	_rResult.m_f24 = 0.0f;
	_rResult.m_f31 = 0.0f;										_rResult.m_f32 = 0.0f;										_rResult.m_f33 = (-(_kfFar + _kfNear) / (_kfFar - _kfNear));	_rResult.m_f34 = ((-2.0f * _kfFar * _kfNear) / (_kfFar - _kfNear));
	_rResult.m_f41 = 0.0f;										_rResult.m_f42 = 0.0f;										_rResult.m_f43 = -1.0f;											_rResult.m_f44 = 0.0f;

	return(_rResult);
}

const TMatrix4d& PerspectiveMatrix(	TMatrix4d& _rResult,
											const double _kdFovX, const double _kdFovY,
											const double _kdFar,	const double _kdNear)
{
	_rResult.m_d11 = ArcTan(_kdFovX / 2.0);	_rResult.m_d12 = 0.0;							_rResult.m_d13 = 0.0;											_rResult.m_d14 = 0.0;
	_rResult.m_d21 = 0.0;							_rResult.m_d22 = ArcTan(_kdFovY / 2.0);	_rResult.m_d23 = 0.0;											_rResult.m_d24 = 0.0;
	_rResult.m_d31 = 0.0;							_rResult.m_d32 = 0.0;							_rResult.m_d33 = (-(_kdFar + _kdNear) / (_kdFar - _kdNear));	_rResult.m_d34 = ((-2.0 * _kdFar * _kdNear) / (_kdFar - _kdNear));
	_rResult.m_d41 = 0.0;							_rResult.m_d42 = 0.0;							_rResult.m_d43 = -1.0;											_rResult.m_d44 = 0.0;

	return(_rResult);
}

const TMatrix4f& PerspectiveMatrix(	TMatrix4f& _rResult,
											const float _kfFovX, const float _kfFovY,
											const float _kfFar,	const float _kfNear)
{
	_rResult.m_f11 = ArcTan(_kfFovX / 2.0f);	_rResult.m_f12 = 0.0f;							_rResult.m_f13 = 0.0f;											_rResult.m_f14 = 0.0f;
	_rResult.m_f21 = 0.0f;							_rResult.m_f22 = ArcTan(_kfFovY / 2.0f);	_rResult.m_f23 = 0.0f;											_rResult.m_f24 = 0.0f;
	_rResult.m_f31 = 0.0f;							_rResult.m_f32 = 0.0f;						_rResult.m_f33 = (-(_kfFar + _kfNear) / (_kfFar - _kfNear));	_rResult.m_f34 = ((-2.0f * _kfFar * _kfNear) / (_kfFar - _kfNear));
	_rResult.m_f41 = 0.0f;							_rResult.m_f42 = 0.0f;						_rResult.m_f43 = -1.0f;											_rResult.m_f44 = 0.0f;

	return(_rResult);
}

const TMatrix4d& OrthographicMatrix(	TMatrix4d& _rResult,
											const double _kdLeft,	const double _kdRight,
											const double _kdBottom,	const double _kdTop,
											const double _kdFar,	const double _kdNear)
{
	_rResult.m_d11 = (2.0 / (_kdRight - _kdLeft));	_rResult.m_d12 = 0.0;							_rResult.m_d13 = 0.0;							_rResult.m_d14 = (-(_kdRight + _kdLeft) / (_kdRight - _kdLeft));
	_rResult.m_d21 = 0.0;							_rResult.m_d22 = (2.0 / (_kdTop - _kdBottom));	_rResult.m_d23 = 0.0;							_rResult.m_d24 = (-(_kdTop + _kdBottom) / (_kdTop - _kdBottom));
	_rResult.m_d31 = 0.0;							_rResult.m_d32 = 0.0;							_rResult.m_d33 = (-2.0 / (_kdFar - _kdNear));	_rResult.m_d34 = (-(_kdFar + _kdNear) / (_kdFar - _kdNear));
	_rResult.m_d41 = 0.0;							_rResult.m_d42 = 0.0;							_rResult.m_d43 = 0.0;							_rResult.m_d44 = 1.0;

	return(_rResult);
}

const TMatrix4f& OrthographicMatrix(	TMatrix4f& _rResult,
											const float _kfLeft,	const float _kfRight,
											const float _kfBottom,	const float _kfTop,
											const float _kfFar,		const float _kfNear)
{
	_rResult.m_f11 = (2.0f / (_kfRight - _kfLeft));	_rResult.m_f12 = 0.0f;							_rResult.m_f13 = 0.0f;							_rResult.m_f14 = (-(_kfRight + _kfLeft) / (_kfRight - _kfLeft));
	_rResult.m_f21 = 0.0f;							_rResult.m_f22 = (2.0f / (_kfTop - _kfBottom));	_rResult.m_f23 = 0.0f;							_rResult.m_f24 = (-(_kfTop + _kfBottom) / (_kfTop - _kfBottom));
	_rResult.m_f31 = 0.0f;							_rResult.m_f32 = 0.0f;							_rResult.m_f33 = (-2.0f / (_kfFar - _kfNear));	_rResult.m_f34 = (-(_kfFar + _kfNear) / (_kfFar - _kfNear));
	_rResult.m_f41 = 0.0f;							_rResult.m_f42 = 0.0f;							_rResult.m_f43 = 0.0f;							_rResult.m_f44 = 1.0f;

	return(_rResult);
}

const TMatrix4d& OrthographicMatrix(	TMatrix4d& _rResult,
											const double _kdWidth,	const double _kdHeight,
											const double _kdFar,	const double _kdNear)
{
	const double kdRight = _kdWidth / 2.0;
	const double kdTop = _kdHeight / 2.0;

	_rResult.m_d11 = (1.0 / kdRight);	_rResult.m_d12 = 0.0;			_rResult.m_d13 = 0.0;							_rResult.m_d14 = 0.0;
	_rResult.m_d21 = 0.0;				_rResult.m_d22 = (1.0 / kdTop);	_rResult.m_d23 = 0.0;							_rResult.m_d24 = 0.0;
	_rResult.m_d31 = 0.0;				_rResult.m_d32 = 0.0;			_rResult.m_d33 = (-2.0 / (_kdFar - _kdNear));	_rResult.m_d34 = (-(_kdFar + _kdNear) / (_kdFar - _kdNear));
	_rResult.m_d41 = 0.0;				_rResult.m_d42 = 0.0;			_rResult.m_d43 = 0.0;							_rResult.m_d44 = 1.0;

	return(_rResult);
}

const TMatrix4f& OrthographicMatrix(	TMatrix4f& _rResult,
											const float _kfWidth,	const float _kfHeight,
											const float _kfFar,		const float _kfNear)
{
	const float kfRight = _kfWidth / 2.0f;
	const float kfTop = _kfHeight / 2.0f;

	_rResult.m_f11 = (1.0f / kfRight);	_rResult.m_f12 = 0.0f;				_rResult.m_f13 = 0.0f;							_rResult.m_f14 = 0.0f;
	_rResult.m_f21 = 0.0f;				_rResult.m_f22 = (1.0f / kfTop);	_rResult.m_f23 = 0.0f;							_rResult.m_f24 = 0.0f;
	_rResult.m_f31 = 0.0f;				_rResult.m_f32 = 0.0f;				_rResult.m_f33 = (-2.0f / (_kfFar - _kfNear));	_rResult.m_f34 = (-(_kfFar + _kfNear) / (_kfFar - _kfNear));
	_rResult.m_f41 = 0.0f;				_rResult.m_f42 = 0.0f;				_rResult.m_f43 = 0.0f;							_rResult.m_f44 = 1.0f;

	return(_rResult);
}

//
// Matrix 3
//

const bool Equal(const TMatrix3d& _krA, const TMatrix3d& _krB, const double _kdEpsilon)
{
	const bool kbEqual =	(Magnitude(_krA.m_d11 - _krB.m_d11) < _kdEpsilon)
						&&	(Magnitude(_krA.m_d12 - _krB.m_d12) < _kdEpsilon)
						&&	(Magnitude(_krA.m_d13 - _krB.m_d13) < _kdEpsilon)
						&&	(Magnitude(_krA.m_d21 - _krB.m_d21) < _kdEpsilon)
						&&	(Magnitude(_krA.m_d22 - _krB.m_d22) < _kdEpsilon)
						&&	(Magnitude(_krA.m_d23 - _krB.m_d23) < _kdEpsilon)
						&&	(Magnitude(_krA.m_d31 - _krB.m_d31) < _kdEpsilon)
						&&	(Magnitude(_krA.m_d32 - _krB.m_d32) < _kdEpsilon)
						&&	(Magnitude(_krA.m_d33 - _krB.m_d33) < _kdEpsilon);

	return(kbEqual);
}

const bool Equal(const TMatrix3f& _krA, const TMatrix3f& _krB, const float _kfEpsilon)
{
	const bool kbEqual =	(Magnitude(_krA.m_f11 - _krB.m_f11) < _kfEpsilon)
						&&	(Magnitude(_krA.m_f12 - _krB.m_f12) < _kfEpsilon)
						&&	(Magnitude(_krA.m_f13 - _krB.m_f13) < _kfEpsilon)
						&&	(Magnitude(_krA.m_f21 - _krB.m_f21) < _kfEpsilon)
						&&	(Magnitude(_krA.m_f22 - _krB.m_f22) < _kfEpsilon)
						&&	(Magnitude(_krA.m_f23 - _krB.m_f23) < _kfEpsilon)
						&&	(Magnitude(_krA.m_f31 - _krB.m_f31) < _kfEpsilon)
						&&	(Magnitude(_krA.m_f32 - _krB.m_f32) < _kfEpsilon)
						&&	(Magnitude(_krA.m_f33 - _krB.m_f33) < _kfEpsilon);

	return(kbEqual);
}

const TMatrix3d& ZeroMatrix(TMatrix3d& _rResult)
{
	_rResult.m_d11 = 0.0; _rResult.m_d12 = 0.0; _rResult.m_d13 = 0.0;
	_rResult.m_d21 = 0.0; _rResult.m_d22 = 0.0; _rResult.m_d23 = 0.0;
	_rResult.m_d31 = 0.0; _rResult.m_d32 = 0.0; _rResult.m_d33 = 0.0;

	return(_rResult);
}

const TMatrix3f& ZeroMatrix(TMatrix3f& _rResult)
{
	_rResult.m_f11 = 0.0f; _rResult.m_f12 = 0.0f; _rResult.m_f13 = 0.0f;
	_rResult.m_f21 = 0.0f; _rResult.m_f22 = 0.0f; _rResult.m_f23 = 0.0f;
	_rResult.m_f31 = 0.0f; _rResult.m_f32 = 0.0f; _rResult.m_f33 = 0.0f;

	return(_rResult);
}

const TMatrix3d& IdentityMatrix(TMatrix3d& _rResult)
{
	_rResult.m_d11 = 1.0; _rResult.m_d12 = 0.0; _rResult.m_d13 = 0.0;
	_rResult.m_d21 = 0.0; _rResult.m_d22 = 1.0; _rResult.m_d23 = 0.0;
	_rResult.m_d31 = 0.0; _rResult.m_d32 = 0.0; _rResult.m_d33 = 1.0;

	return(_rResult);
}

const TMatrix3f& IdentityMatrix(TMatrix3f& _rResult)
{
	_rResult.m_f11 = 1.0f; _rResult.m_f12 = 0.0f; _rResult.m_f13 = 0.0f;
	_rResult.m_f21 = 0.0f; _rResult.m_f22 = 1.0f; _rResult.m_f23 = 0.0f;
	_rResult.m_f31 = 0.0f; _rResult.m_f32 = 0.0f; _rResult.m_f33 = 1.0f;

	return(_rResult);
}

const TMatrix3d& Multiply(TMatrix3d& _rResult,
								const TMatrix3d& _krA,
								const TMatrix3d& _krB)
{
	_rResult.m_d11 = ((_krA.m_d11 * _krB.m_d11) + (_krA.m_d12 * _krB.m_d21) + (_krA.m_d13 * _krB.m_d31));
	_rResult.m_d12 = ((_krA.m_d11 * _krB.m_d12) + (_krA.m_d12 * _krB.m_d22) + (_krA.m_d13 * _krB.m_d32));
	_rResult.m_d13 = ((_krA.m_d11 * _krB.m_d13) + (_krA.m_d12 * _krB.m_d23) + (_krA.m_d13 * _krB.m_d33));

	_rResult.m_d21 = ((_krA.m_d21 * _krB.m_d11) + (_krA.m_d22 * _krB.m_d21) + (_krA.m_d23 * _krB.m_d31));
	_rResult.m_d22 = ((_krA.m_d21 * _krB.m_d12) + (_krA.m_d22 * _krB.m_d22) + (_krA.m_d23 * _krB.m_d32));
	_rResult.m_d23 = ((_krA.m_d21 * _krB.m_d13) + (_krA.m_d22 * _krB.m_d23) + (_krA.m_d23 * _krB.m_d33));

	_rResult.m_d31 = ((_krA.m_d31 * _krB.m_d11) + (_krA.m_d32 * _krB.m_d21) + (_krA.m_d33 * _krB.m_d31));
	_rResult.m_d32 = ((_krA.m_d31 * _krB.m_d12) + (_krA.m_d32 * _krB.m_d22) + (_krA.m_d33 * _krB.m_d32));
	_rResult.m_d33 = ((_krA.m_d31 * _krB.m_d13) + (_krA.m_d32 * _krB.m_d23) + (_krA.m_d33 * _krB.m_d33));

	return(_rResult);
}

const TMatrix3f& Multiply(TMatrix3f& _rResult,
								const TMatrix3f& _krA,
								const TMatrix3f& _krB)
{
	_rResult.m_f11 = ((_krA.m_f11 * _krB.m_f11) + (_krA.m_f12 * _krB.m_f21) + (_krA.m_f13 * _krB.m_f31));
	_rResult.m_f12 = ((_krA.m_f11 * _krB.m_f12) + (_krA.m_f12 * _krB.m_f22) + (_krA.m_f13 * _krB.m_f32));
	_rResult.m_f13 = ((_krA.m_f11 * _krB.m_f13) + (_krA.m_f12 * _krB.m_f23) + (_krA.m_f13 * _krB.m_f33));

	_rResult.m_f21 = ((_krA.m_f21 * _krB.m_f11) + (_krA.m_f22 * _krB.m_f21) + (_krA.m_f23 * _krB.m_f31));
	_rResult.m_f22 = ((_krA.m_f21 * _krB.m_f12) + (_krA.m_f22 * _krB.m_f22) + (_krA.m_f23 * _krB.m_f32));
	_rResult.m_f23 = ((_krA.m_f21 * _krB.m_f13) + (_krA.m_f22 * _krB.m_f23) + (_krA.m_f23 * _krB.m_f33));

	_rResult.m_f31 = ((_krA.m_f31 * _krB.m_f11) + (_krA.m_f32 * _krB.m_f21) + (_krA.m_f33 * _krB.m_f31));
	_rResult.m_f32 = ((_krA.m_f31 * _krB.m_f12) + (_krA.m_f32 * _krB.m_f22) + (_krA.m_f33 * _krB.m_f32));
	_rResult.m_f33 = ((_krA.m_f31 * _krB.m_f13) + (_krA.m_f32 * _krB.m_f23) + (_krA.m_f33 * _krB.m_f33));

	return(_rResult);
}

const TMatrix3d& ScalarMultiply(	TMatrix3d& _rResult,
										const TMatrix3d& _krMatrix,
										const double _kdScalar)
{
	_rResult.m_d11 = _krMatrix.m_d11 * _kdScalar; _rResult.m_d12 = _krMatrix.m_d12 * _kdScalar; _rResult.m_d13 = _krMatrix.m_d13 * _kdScalar;
	_rResult.m_d21 = _krMatrix.m_d21 * _kdScalar; _rResult.m_d22 = _krMatrix.m_d22 * _kdScalar; _rResult.m_d23 = _krMatrix.m_d23 * _kdScalar;
	_rResult.m_d31 = _krMatrix.m_d31 * _kdScalar; _rResult.m_d32 = _krMatrix.m_d32 * _kdScalar; _rResult.m_d33 = _krMatrix.m_d33 * _kdScalar;

	return(_rResult);
}

const TMatrix3f& ScalarMultiply(	TMatrix3f& _rResult,
										const TMatrix3f& _krMatrix,
										const float _kfScalar)
{
	_rResult.m_f11 = _krMatrix.m_f11 * _kfScalar; _rResult.m_f12 = _krMatrix.m_f12 * _kfScalar; _rResult.m_f13 = _krMatrix.m_f13 * _kfScalar;
	_rResult.m_f21 = _krMatrix.m_f21 * _kfScalar; _rResult.m_f22 = _krMatrix.m_f22 * _kfScalar; _rResult.m_f23 = _krMatrix.m_f23 * _kfScalar;
	_rResult.m_f31 = _krMatrix.m_f31 * _kfScalar; _rResult.m_f32 = _krMatrix.m_f32 * _kfScalar; _rResult.m_f33 = _krMatrix.m_f33 * _kfScalar;

	return(_rResult);
}

const TVector3d& VectorMultiply(	TVector3d& _rResult,
										const TMatrix3d& _krA,
										const TVector3d& _krB)
{
	_rResult.m_dX = (_krA.m_d11 * _krB.m_dX) + (_krA.m_d12 * _krB.m_dY) + (_krA.m_d13 * _krB.m_dZ);
	_rResult.m_dY = (_krA.m_d21 * _krB.m_dX) + (_krA.m_d22 * _krB.m_dY) + (_krA.m_d23 * _krB.m_dZ);
	_rResult.m_dZ = (_krA.m_d31 * _krB.m_dX) + (_krA.m_d32 * _krB.m_dY) + (_krA.m_d33 * _krB.m_dZ);

	return(_rResult);
}

const TVector3f& VectorMultiply(	TVector3f& _rResult,
										const TMatrix3f& _krA,
										const TVector3f& _krB)
{
	_rResult.m_fX = (_krA.m_f11 * _krB.m_fX) + (_krA.m_f12 * _krB.m_fY) + (_krA.m_f13 * _krB.m_fZ);
	_rResult.m_fY = (_krA.m_f21 * _krB.m_fX) + (_krA.m_f22 * _krB.m_fY) + (_krA.m_f23 * _krB.m_fZ);
	_rResult.m_fZ = (_krA.m_f31 * _krB.m_fX) + (_krA.m_f32 * _krB.m_fY) + (_krA.m_f33 * _krB.m_fZ);

	return(_rResult);
}

const TMatrix3d& Add(	TMatrix3d& _rResult,
							const TMatrix3d& _krA,
							const TMatrix3d& _krB)
{
	_rResult.m_d11 = _krA.m_d11 + _krB.m_d11; _rResult.m_d12 = _krA.m_d12 + _krB.m_d12; _rResult.m_d13 = _krA.m_d13 + _krB.m_d13;
	_rResult.m_d21 = _krA.m_d21 + _krB.m_d21; _rResult.m_d22 = _krA.m_d22 + _krB.m_d22; _rResult.m_d23 = _krA.m_d23 + _krB.m_d23;
	_rResult.m_d31 = _krA.m_d31 + _krB.m_d31; _rResult.m_d32 = _krA.m_d32 + _krB.m_d32; _rResult.m_d33 = _krA.m_d33 + _krB.m_d33;

	return(_rResult);
}

const TMatrix3f& Add(	TMatrix3f& _rResult,
							const TMatrix3f& _krA,
							const TMatrix3f& _krB)
{
	_rResult.m_f11 = _krA.m_f11 + _krB.m_f11; _rResult.m_f12 = _krA.m_f12 + _krB.m_f12; _rResult.m_f13 = _krA.m_f13 + _krB.m_f13;
	_rResult.m_f21 = _krA.m_f21 + _krB.m_f21; _rResult.m_f22 = _krA.m_f22 + _krB.m_f22; _rResult.m_f23 = _krA.m_f23 + _krB.m_f23;
	_rResult.m_f31 = _krA.m_f31 + _krB.m_f31; _rResult.m_f32 = _krA.m_f32 + _krB.m_f32; _rResult.m_f33 = _krA.m_f33 + _krB.m_f33;

	return(_rResult);
}

const TMatrix3d& Transpose(	TMatrix3d& _rResult,
									const TMatrix3d& _krMatrix)
{
	_rResult.m_d11 = _krMatrix.m_d11; _rResult.m_d12 = _krMatrix.m_d21; _rResult.m_d13 = _krMatrix.m_d31;
	_rResult.m_d21 = _krMatrix.m_d12; _rResult.m_d22 = _krMatrix.m_d22; _rResult.m_d23 = _krMatrix.m_d32;
	_rResult.m_d31 = _krMatrix.m_d13; _rResult.m_d32 = _krMatrix.m_d23; _rResult.m_d33 = _krMatrix.m_d33;

	return(_rResult);
}

const TMatrix3f& Transpose(	TMatrix3f& _rResult,
									const TMatrix3f& _krMatrix)
{
	_rResult.m_f11 = _krMatrix.m_f11; _rResult.m_f12 = _krMatrix.m_f21; _rResult.m_f13 = _krMatrix.m_f31;
	_rResult.m_f21 = _krMatrix.m_f12; _rResult.m_f22 = _krMatrix.m_f22; _rResult.m_f23 = _krMatrix.m_f32;
	_rResult.m_f31 = _krMatrix.m_f13; _rResult.m_f32 = _krMatrix.m_f23; _rResult.m_f33 = _krMatrix.m_f33;
	
	return(_rResult);
}

const double GetElement(	const TMatrix3d& _krMatrix,
								const size_t _kRow,
								const size_t _kColumn)
{
	double dResult;

	if(_kRow == 1)
	{
		if(_kColumn == 1)
		{
			dResult = _krMatrix.m_d11;
		}
		else if(_kColumn == 2)
		{
			dResult = _krMatrix.m_d12;
		}
		else if(_kColumn == 3)
		{
			dResult = _krMatrix.m_d13;
		}
	}
	else if(_kRow == 2)
	{
		if(_kColumn == 1)
		{
			dResult = _krMatrix.m_d21;
		}
		else if(_kColumn == 2)
		{
			dResult = _krMatrix.m_d22;
		}
		else if(_kColumn == 3)
		{
			dResult = _krMatrix.m_d23;
		}
	}
	else if(_kRow == 3)
	{
		if(_kColumn == 1)
		{
			dResult = _krMatrix.m_d31;
		}
		else if(_kColumn == 2)
		{
			dResult = _krMatrix.m_d32;
		}
		else if(_kColumn == 3)
		{
			dResult = _krMatrix.m_d33;
		}
	}

	return(dResult);
}

const float GetElement(	const TMatrix3f& _krMatrix,
								const size_t _kRow,
								const size_t _kColumn)
{
	float fResult;

	if(_kRow == 1)
	{
		if(_kColumn == 1)
		{
			fResult = _krMatrix.m_f11;
		}
		else if(_kColumn == 2)
		{
			fResult = _krMatrix.m_f12;
		}
		else if(_kColumn == 3)
		{
			fResult = _krMatrix.m_f13;
		}
	}
	else if(_kRow == 2)
	{
		if(_kColumn == 1)
		{
			fResult = _krMatrix.m_f21;
		}
		else if(_kColumn == 2)
		{
			fResult = _krMatrix.m_f22;
		}
		else if(_kColumn == 3)
		{
			fResult = _krMatrix.m_f23;
		}
	}
	else if(_kRow == 3)
	{
		if(_kColumn == 1)
		{
			fResult = _krMatrix.m_f31;
		}
		else if(_kColumn == 2)
		{
			fResult = _krMatrix.m_f32;
		}
		else if(_kColumn == 3)
		{
			fResult = _krMatrix.m_f33;
		}
	}

	return(fResult);
}

TMatrix3d& SetElement(	TMatrix3d& _rResult,
								const double _kdValue,
								const size_t _kRow,
								const size_t _kColumn)
{
	if(_kRow == 1)
	{
		if(_kColumn == 1)
		{
			_rResult.m_d11 = _kdValue;
		}
		else if(_kColumn == 2)
		{
			_rResult.m_d12 = _kdValue;
		}
		else if(_kColumn == 3)
		{
			_rResult.m_d13 = _kdValue;
		}
	}
	else if(_kRow == 2)
	{
		if(_kColumn == 1)
		{
			_rResult.m_d21 = _kdValue;
		}
		else if(_kColumn == 2)
		{
			_rResult.m_d22 = _kdValue;
		}
		else if(_kColumn == 3)
		{
			_rResult.m_d23 = _kdValue;
		}
	}
	else if(_kRow == 3)
	{
		if(_kColumn == 1)
		{
			_rResult.m_d31 = _kdValue;
		}
		else if(_kColumn == 2)
		{
			_rResult.m_d32 = _kdValue;
		}
		else if(_kColumn == 3)
		{
			_rResult.m_d33 = _kdValue;
		}
	}

	return(_rResult);
}

TMatrix3f& SetElement(	TMatrix3f& _rResult,
								const float _kfValue,
								const size_t _kRow,
								const size_t _kColumn)
{
	if(_kRow == 1)
	{
		if(_kColumn == 1)
		{
			_rResult.m_f11 = _kfValue;
		}
		else if(_kColumn == 2)
		{
			_rResult.m_f12 = _kfValue;
		}
		else if(_kColumn == 3)
		{
			_rResult.m_f13 = _kfValue;
		}
	}
	else if(_kRow == 2)
	{
		if(_kColumn == 1)
		{
			_rResult.m_f21 = _kfValue;
		}
		else if(_kColumn == 2)
		{
			_rResult.m_f22 = _kfValue;
		}
		else if(_kColumn == 3)
		{
			_rResult.m_f23 = _kfValue;
		}
	}
	else if(_kRow == 3)
	{
		if(_kColumn == 1)
		{
			_rResult.m_f31 = _kfValue;
		}
		else if(_kColumn == 2)
		{
			_rResult.m_f32 = _kfValue;
		}
		else if(_kColumn == 3)
		{
			_rResult.m_f33 = _kfValue;
		}
	}

	return(_rResult);
}

const TMatrix2d& Submatrix(	TMatrix2d& _rResult, 
									const TMatrix3d& _krMatrix,
									const size_t _kDeletedRow,
									const size_t _kDeletedColumn)
{
	if(_kDeletedRow == 1)
	{
		if(_kDeletedColumn == 1)
		{
			_rResult.m_d11 = _krMatrix.m_d22; _rResult.m_d12 = _krMatrix.m_d23;
			_rResult.m_d21 = _krMatrix.m_d32; _rResult.m_d22 = _krMatrix.m_d33;
		}
		else if(_kDeletedColumn == 2)
		{
			_rResult.m_d11 = _krMatrix.m_d21; _rResult.m_d12 = _krMatrix.m_d23;
			_rResult.m_d21 = _krMatrix.m_d31; _rResult.m_d22 = _krMatrix.m_d33;
		}
		else if(_kDeletedColumn == 3)
		{
			_rResult.m_d11 = _krMatrix.m_d21; _rResult.m_d12 = _krMatrix.m_d22;
			_rResult.m_d21 = _krMatrix.m_d31; _rResult.m_d22 = _krMatrix.m_d32;
		}
	}
	else if(_kDeletedRow == 2)
	{
		if(_kDeletedColumn == 1)
		{
			_rResult.m_d11 = _krMatrix.m_d12; _rResult.m_d12 = _krMatrix.m_d13;
			_rResult.m_d21 = _krMatrix.m_d32; _rResult.m_d22 = _krMatrix.m_d33;
		}
		else if(_kDeletedColumn == 2)
		{
			_rResult.m_d11 = _krMatrix.m_d11; _rResult.m_d12 = _krMatrix.m_d13;
			_rResult.m_d21 = _krMatrix.m_d31; _rResult.m_d22 = _krMatrix.m_d33;
		}
		else if(_kDeletedColumn == 3)
		{
			_rResult.m_d11 = _krMatrix.m_d11; _rResult.m_d12 = _krMatrix.m_d12;
			_rResult.m_d21 = _krMatrix.m_d31; _rResult.m_d22 = _krMatrix.m_d32;
		}
	}
	else if(_kDeletedRow == 3)
	{
		if(_kDeletedColumn == 1)
		{
			_rResult.m_d11 = _krMatrix.m_d12; _rResult.m_d12 = _krMatrix.m_d13;
			_rResult.m_d21 = _krMatrix.m_d22; _rResult.m_d22 = _krMatrix.m_d23;
		}
		else if(_kDeletedColumn == 2)
		{
			_rResult.m_d11 = _krMatrix.m_d11; _rResult.m_d12 = _krMatrix.m_d13;
			_rResult.m_d21 = _krMatrix.m_d21; _rResult.m_d22 = _krMatrix.m_d23;
		}
		else if(_kDeletedColumn == 3)
		{
			_rResult.m_d11 = _krMatrix.m_d11; _rResult.m_d12 = _krMatrix.m_d12;
			_rResult.m_d21 = _krMatrix.m_d21; _rResult.m_d22 = _krMatrix.m_d22;
		}
	}

	return(_rResult);
}

const TMatrix2f& Submatrix(	TMatrix2f& _rResult, 
									const TMatrix3f& _krMatrix,
									const size_t _kDeletedRow,
									const size_t _kDeletedColumn)
{
	if(_kDeletedRow == 1)
	{
		if(_kDeletedColumn == 1)
		{
			_rResult.m_f11 = _krMatrix.m_f22; _rResult.m_f12 = _krMatrix.m_f23;
			_rResult.m_f21 = _krMatrix.m_f32; _rResult.m_f22 = _krMatrix.m_f33;
		}
		else if(_kDeletedColumn == 2)
		{
			_rResult.m_f11 = _krMatrix.m_f21; _rResult.m_f12 = _krMatrix.m_f23;
			_rResult.m_f21 = _krMatrix.m_f31; _rResult.m_f22 = _krMatrix.m_f33;
		}
		else if(_kDeletedColumn == 3)
		{
			_rResult.m_f11 = _krMatrix.m_f21; _rResult.m_f12 = _krMatrix.m_f22;
			_rResult.m_f21 = _krMatrix.m_f31; _rResult.m_f22 = _krMatrix.m_f32;
		}
	}
	else if(_kDeletedRow == 2)
	{
		if(_kDeletedColumn == 1)
		{
			_rResult.m_f11 = _krMatrix.m_f12; _rResult.m_f12 = _krMatrix.m_f13;
			_rResult.m_f21 = _krMatrix.m_f32; _rResult.m_f22 = _krMatrix.m_f33;
		}
		else if(_kDeletedColumn == 2)
		{
			_rResult.m_f11 = _krMatrix.m_f11; _rResult.m_f12 = _krMatrix.m_f13;
			_rResult.m_f21 = _krMatrix.m_f31; _rResult.m_f22 = _krMatrix.m_f33;
		}
		else if(_kDeletedColumn == 3)
		{
			_rResult.m_f11 = _krMatrix.m_f11; _rResult.m_f12 = _krMatrix.m_f12;
			_rResult.m_f21 = _krMatrix.m_f31; _rResult.m_f22 = _krMatrix.m_f32;
		}
	}
	else if(_kDeletedRow == 3)
	{
		if(_kDeletedColumn == 1)
		{
			_rResult.m_f11 = _krMatrix.m_f12; _rResult.m_f12 = _krMatrix.m_f13;
			_rResult.m_f21 = _krMatrix.m_f22; _rResult.m_f22 = _krMatrix.m_f23;
		}
		else if(_kDeletedColumn == 2)
		{
			_rResult.m_f11 = _krMatrix.m_f11; _rResult.m_f12 = _krMatrix.m_f13;
			_rResult.m_f21 = _krMatrix.m_f21; _rResult.m_f22 = _krMatrix.m_f23;
		}
		else if(_kDeletedColumn == 3)
		{
			_rResult.m_f11 = _krMatrix.m_f11; _rResult.m_f12 = _krMatrix.m_f12;
			_rResult.m_f21 = _krMatrix.m_f21; _rResult.m_f22 = _krMatrix.m_f22;
		}
	}

	return(_rResult);
}

const double Determinant(const TMatrix3d& _krMatrix)
{
	const double kdDeterminant =	(_krMatrix.m_d11 * _krMatrix.m_d22 * _krMatrix.m_d33)
								+	(_krMatrix.m_d12 * _krMatrix.m_d23 * _krMatrix.m_d31)
								+	(_krMatrix.m_d13 * _krMatrix.m_d21 * _krMatrix.m_d32)
								-	(_krMatrix.m_d13 * _krMatrix.m_d22 * _krMatrix.m_d31)
								-	(_krMatrix.m_d12 * _krMatrix.m_d21 * _krMatrix.m_d33)
								-	(_krMatrix.m_d11 * _krMatrix.m_d23 * _krMatrix.m_d32);

	return(kdDeterminant);
}

const float Determinant(const TMatrix3f& _krMatrix)
{
	const float kfDeterminant =		(_krMatrix.m_f11 * _krMatrix.m_f22 * _krMatrix.m_f33)
								+	(_krMatrix.m_f12 * _krMatrix.m_f23 * _krMatrix.m_f31)
								+	(_krMatrix.m_f13 * _krMatrix.m_f21 * _krMatrix.m_f32)
								-	(_krMatrix.m_f13 * _krMatrix.m_f22 * _krMatrix.m_f31)
								-	(_krMatrix.m_f12 * _krMatrix.m_f21 * _krMatrix.m_f33)
								-	(_krMatrix.m_f11 * _krMatrix.m_f23 * _krMatrix.m_f32);

	return(kfDeterminant);
}

const double FirstMinor(	const TMatrix3d& _krMatrix,
								const size_t _kRow,
								const size_t _kColumn)
{
	const TMatrix2d kSubmatrix = Submatrix(TMatrix2d(), _krMatrix, _kRow, _kColumn);
	
	return(Determinant(kSubmatrix));
}

const float FirstMinor(	const TMatrix3f& _krMatrix,
								const size_t _kRow,
								const size_t _kColumn)
{
	const TMatrix2f kSubmatrix = Submatrix(TMatrix2f(), _krMatrix, _kRow, _kColumn);
	
	return(Determinant(kSubmatrix));
}

const TMatrix3d& MatrixOfMinors(	TMatrix3d& _rResult,
										const TMatrix3d& _krMatrix)
{
	_rResult.m_d11 = FirstMinor(_krMatrix, 1, 1);
	_rResult.m_d12 = FirstMinor(_krMatrix, 1, 2);
	_rResult.m_d13 = FirstMinor(_krMatrix, 1, 3);

	_rResult.m_d21 = FirstMinor(_krMatrix, 2, 1);
	_rResult.m_d22 = FirstMinor(_krMatrix, 2, 2);
	_rResult.m_d23 = FirstMinor(_krMatrix, 2, 3);

	_rResult.m_d31 = FirstMinor(_krMatrix, 3, 1);
	_rResult.m_d32 = FirstMinor(_krMatrix, 3, 2);
	_rResult.m_d33 = FirstMinor(_krMatrix, 3, 3);

	return(_rResult);
}

const TMatrix3f& MatrixOfMinors(	TMatrix3f& _rResult,
										const TMatrix3f& _krMatrix)
{
	_rResult.m_f11 = FirstMinor(_krMatrix, 1, 1);
	_rResult.m_f12 = FirstMinor(_krMatrix, 1, 2);
	_rResult.m_f13 = FirstMinor(_krMatrix, 1, 3);

	_rResult.m_f21 = FirstMinor(_krMatrix, 2, 1);
	_rResult.m_f22 = FirstMinor(_krMatrix, 2, 2);
	_rResult.m_f23 = FirstMinor(_krMatrix, 2, 3);

	_rResult.m_f31 = FirstMinor(_krMatrix, 3, 1);
	_rResult.m_f32 = FirstMinor(_krMatrix, 3, 2);
	_rResult.m_f33 = FirstMinor(_krMatrix, 3, 3);

	return(_rResult);
}

const TMatrix3d& MatrixOfCofactors(	TMatrix3d& _rResult,
											const TMatrix3d& _krMatrix)
{
	_rResult = MatrixOfMinors(_rResult, _krMatrix);
	
	_rResult.m_d12 *= -1.0;

	_rResult.m_d21 *= -1.0;
	_rResult.m_d23 *= -1.0;

	_rResult.m_d32 *= -1.0;

	return(_rResult);
}

const TMatrix3f& MatrixOfCofactors(	TMatrix3f& _rResult,
											const TMatrix3f& _krMatrix)
{
	_rResult = MatrixOfMinors(_rResult, _krMatrix);

	_rResult.m_f12 *= -1.0f;

	_rResult.m_f21 *= -1.0f;
	_rResult.m_f23 *= -1.0f;

	_rResult.m_f32 *= -1.0f;

	return(_rResult);
}

const TMatrix3d& Inverse(	TMatrix3d& _rResult,
								const TMatrix3d& _krMatrix)
{
	_rResult = ScalarMultiply(_rResult,
									Transpose(TMatrix3d(),
													MatrixOfCofactors(TMatrix3d(), _krMatrix)),
									1.0/Determinant(_krMatrix));

	return(_rResult);
}

const TMatrix3f& Inverse(	TMatrix3f& _rResult,
								const TMatrix3f& _krMatrix)
{
	_rResult = ScalarMultiply(_rResult,
									Transpose(TMatrix3f(),
													MatrixOfCofactors(TMatrix3f(), _krMatrix)),
									1.0f/Determinant(_krMatrix));

	return(_rResult);
}

//
// Matrix 2
//

const bool Equal(const TMatrix2d& _krA, const TMatrix2d& _krB, const double _kdEpsilon)
{
	const bool kbEqual =	(Magnitude(_krA.m_d11 - _krB.m_d11) < _kdEpsilon)
						&&	(Magnitude(_krA.m_d12 - _krB.m_d12) < _kdEpsilon)
						&&	(Magnitude(_krA.m_d21 - _krB.m_d21) < _kdEpsilon)
						&&	(Magnitude(_krA.m_d22 - _krB.m_d22) < _kdEpsilon);

	return(kbEqual);
}

const bool Equal(const TMatrix2f& _krA, const TMatrix2f& _krB, const float _kfEpsilon)
{
	const bool kbEqual =	(Magnitude(_krA.m_f11 - _krB.m_f11) < _kfEpsilon)
						&&	(Magnitude(_krA.m_f12 - _krB.m_f12) < _kfEpsilon)
						&&	(Magnitude(_krA.m_f21 - _krB.m_f21) < _kfEpsilon)
						&&	(Magnitude(_krA.m_f22 - _krB.m_f22) < _kfEpsilon);

	return(kbEqual);
}

const TMatrix2d& ZeroMatrix(TMatrix2d& _rResult)
{
	_rResult.m_d11 = 0.0; _rResult.m_d12 = 0.0;
	_rResult.m_d21 = 0.0; _rResult.m_d22 = 0.0;

	return(_rResult);
}

const TMatrix2f& ZeroMatrix(TMatrix2f& _rResult)
{
	_rResult.m_f11 = 0.0f; _rResult.m_f12 = 0.0f;
	_rResult.m_f21 = 0.0f; _rResult.m_f22 = 0.0f;

	return(_rResult);
}

const TMatrix2d& IdentityMatrix(TMatrix2d& _rResult)
{
	_rResult.m_d11 = 1.0; _rResult.m_d12 = 0.0;
	_rResult.m_d21 = 0.0; _rResult.m_d22 = 1.0;

	return(_rResult);
}

const TMatrix2f& IdentityMatrix(TMatrix2f& _rResult)
{
	_rResult.m_f11 = 1.0f; _rResult.m_f12 = 0.0f;
	_rResult.m_f21 = 0.0f; _rResult.m_f22 = 1.0f;

	return(_rResult);
}

const TMatrix2d& Multiply(TMatrix2d& _rResult,
								const TMatrix2d& _krA,
								const TMatrix2d& _krB)
{
	_rResult.m_d11 = ((_krA.m_d11 * _krB.m_d11) + (_krA.m_d12 * _krB.m_d21));
	_rResult.m_d12 = ((_krA.m_d11 * _krB.m_d12) + (_krA.m_d12 * _krB.m_d22));
	_rResult.m_d21 = ((_krA.m_d21 * _krB.m_d11) + (_krA.m_d22 * _krB.m_d21));
	_rResult.m_d22 = ((_krA.m_d21 * _krB.m_d12) + (_krA.m_d22 * _krB.m_d22));

	return(_rResult);
}

const TMatrix2f& Multiply(TMatrix2f& _rResult,
								const TMatrix2f& _krA,
								const TMatrix2f& _krB)
{
	_rResult.m_f11 = ((_krA.m_f11 * _krB.m_f11) + (_krA.m_f12 * _krB.m_f21));
	_rResult.m_f12 = ((_krA.m_f11 * _krB.m_f12) + (_krA.m_f12 * _krB.m_f22));
	_rResult.m_f21 = ((_krA.m_f21 * _krB.m_f11) + (_krA.m_f22 * _krB.m_f21));
	_rResult.m_f22 = ((_krA.m_f21 * _krB.m_f12) + (_krA.m_f22 * _krB.m_f22));

	return(_rResult);
}

const TMatrix2d& ScalarMultiply(	TMatrix2d& _rResult,
										const TMatrix2d& _krMatrix,
										const double _kdScalar)
{
	_rResult.m_d11 = _krMatrix.m_d11 * _kdScalar; _rResult.m_d12 = _krMatrix.m_d12 * _kdScalar;
	_rResult.m_d21 = _krMatrix.m_d21 * _kdScalar; _rResult.m_d22 = _krMatrix.m_d22 * _kdScalar;

	return(_rResult);
}

const TMatrix2f& ScalarMultiply(	TMatrix2f& _rResult,
										const TMatrix2f& _krMatrix,
										const float _kfScalar)
{
	_rResult.m_f11 = _krMatrix.m_f11 * _kfScalar; _rResult.m_f12 = _krMatrix.m_f12 * _kfScalar;
	_rResult.m_f21 = _krMatrix.m_f21 * _kfScalar; _rResult.m_f22 = _krMatrix.m_f22 * _kfScalar;

	return(_rResult);
}

const TVector2d& VectorMultiply(	TVector2d& _rResult,
										const TMatrix2d& _krA,
										const TVector2d& _krB)
{
	_rResult.m_dX = (_krA.m_d11 * _krB.m_dX) + (_krA.m_d12 * _krB.m_dY);
	_rResult.m_dY = (_krA.m_d21 * _krB.m_dX) + (_krA.m_d22 * _krB.m_dY);

	return(_rResult);
}

const TVector2f& VectorMultiply(	TVector2f& _rResult,
										const TMatrix2f& _krA,
										const TVector2f& _krB)
{
	_rResult.m_fX = (_krA.m_f11 * _krB.m_fX) + (_krA.m_f12 * _krB.m_fY);
	_rResult.m_fY = (_krA.m_f21 * _krB.m_fX) + (_krA.m_f22 * _krB.m_fY);

	return(_rResult);
}

const TMatrix2d& Add(	TMatrix2d& _rResult,
							const TMatrix2d& _krA,
							const TMatrix2d& _krB)
{
	_rResult.m_d11 = _krA.m_d11 + _krB.m_d11; _rResult.m_d12 = _krA.m_d12 + _krB.m_d12;
	_rResult.m_d21 = _krA.m_d21 + _krB.m_d21; _rResult.m_d22 = _krA.m_d22 + _krB.m_d22;

	return(_rResult);
}

const TMatrix2f& Add(	TMatrix2f& _rResult,
							const TMatrix2f& _krA,
							const TMatrix2f& _krB)
{
	_rResult.m_f11 = _krA.m_f11 + _krB.m_f11; _rResult.m_f12 = _krA.m_f12 + _krB.m_f12;
	_rResult.m_f21 = _krA.m_f21 + _krB.m_f21; _rResult.m_f22 = _krA.m_f22 + _krB.m_f22;

	return(_rResult);
}

const TMatrix2d& Transpose(	TMatrix2d& _rResult,
									const TMatrix2d& _krMatrix)
{
	_rResult.m_d11 = _krMatrix.m_d11; _rResult.m_d12 = _krMatrix.m_d21;
	_rResult.m_d21 = _krMatrix.m_d12; _rResult.m_d22 = _krMatrix.m_d22;

	return(_rResult);
}

const TMatrix2f& Transpose(	TMatrix2f& _rResult,
									const TMatrix2f& _krMatrix)
{
	_rResult.m_f11 = _krMatrix.m_f11; _rResult.m_f12 = _krMatrix.m_f21;
	_rResult.m_f21 = _krMatrix.m_f12; _rResult.m_f22 = _krMatrix.m_f22;

	return(_rResult);
}

const double GetElement(	const TMatrix2d& _krMatrix,
								const size_t _kRow,
								const size_t _kColumn)
{
	double dResult;

	if(_kRow == 1)
	{
		if(_kColumn == 1)
		{
			dResult = _krMatrix.m_d11;
		}
		else if(_kColumn == 2)
		{
			dResult = _krMatrix.m_d12;
		}
	}
	else if(_kRow == 2)
	{
		if(_kColumn == 1)
		{
			dResult = _krMatrix.m_d21;
		}
		else if(_kColumn == 2)
		{
			dResult = _krMatrix.m_d22;
		}
	}

	return(dResult);
}

const float GetElement(	const TMatrix2f& _krMatrix,
								const size_t _kRow,
								const size_t _kColumn)
{
	float fResult;

	if(_kRow == 1)
	{
		if(_kColumn == 1)
		{
			fResult = _krMatrix.m_f11;
		}
		else if(_kColumn == 2)
		{
			fResult = _krMatrix.m_f12;
		}
	}
	else if(_kRow == 2)
	{
		if(_kColumn == 1)
		{
			fResult = _krMatrix.m_f21;
		}
		else if(_kColumn == 2)
		{
			fResult = _krMatrix.m_f22;
		}
	}

	return(fResult);
}

TMatrix2d& SetElement(	TMatrix2d& _rResult,
								const double _kdValue,
								const size_t _kRow,
								const size_t _kColumn)
{
	if(_kRow == 1)
	{
		if(_kColumn == 1)
		{
			_rResult.m_d11 = _kdValue;
		}
		else if(_kColumn == 2)
		{
			_rResult.m_d12 = _kdValue;
		}
	}
	else if(_kRow == 2)
	{
		if(_kColumn == 1)
		{
			_rResult.m_d21 = _kdValue;
		}
		else if(_kColumn == 2)
		{
			_rResult.m_d22 = _kdValue;
		}
	}

	return(_rResult);
}

TMatrix2f& SetElement(	TMatrix2f& _rResult,
								const float _kfValue,
								const size_t _kRow,
								const size_t _kColumn)
{
	if(_kRow == 1)
	{
		if(_kColumn == 1)
		{
			_rResult.m_f11 = _kfValue;
		}
		else if(_kColumn == 2)
		{
			_rResult.m_f12 = _kfValue;
		}
	}
	else if(_kRow == 2)
	{
		if(_kColumn == 1)
		{
			_rResult.m_f21 = _kfValue;
		}
		else if(_kColumn == 2)
		{
			_rResult.m_f22 = _kfValue;
		}
	}

	return(_rResult);
}

const TMatrix2d& Inverse(	TMatrix2d& _rResult,
								const TMatrix2d& _krMatrix)
{
	const TMatrix2d kTemp{	_krMatrix.m_d22, -_krMatrix.m_d12,
							-_krMatrix.m_d21, _krMatrix.m_d11};
	_rResult = ScalarMultiply(TMatrix2d(), kTemp, 1.0 / Determinant(_krMatrix));

	return(_rResult);
}

const TMatrix2f& Inverse(	TMatrix2f& _rResult,
								const TMatrix2f& _krMatrix)
{
	const TMatrix2f kTemp{	_krMatrix.m_f22, -_krMatrix.m_f12,
							-_krMatrix.m_f21, _krMatrix.m_f11};
	_rResult = ScalarMultiply(TMatrix2f(), kTemp, 1.0f / Determinant(_krMatrix));

	return(_rResult);
}

const double Determinant(const TMatrix2d& _krMatrix)
{
	return(		(_krMatrix.m_d11 * _krMatrix.m_d22)
			-	(_krMatrix.m_d12 * _krMatrix.m_d21));
}

const float Determinant(const TMatrix2f& _krMatrix)
{
	return(		(_krMatrix.m_f11 * _krMatrix.m_f22)
			-	(_krMatrix.m_f12 * _krMatrix.m_f21));
}