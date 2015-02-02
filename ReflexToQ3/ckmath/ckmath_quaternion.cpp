//
//	Author:	Michael Cameron
//	Email:	chronokun@hotmail.com
//

// Local Includes
#include "ckmath_quaternion.h"
#include "ckmath_scalar.h"
#include "ckmath_vector.h"


//
// Quaternion
//

const TVector4d& IdentityQuaternion(TVector4d& _rResult)
{
	_rResult.m_dW = 1.0;

	_rResult.m_dX = 0.0;
	_rResult.m_dY = 0.0;
	_rResult.m_dZ = 0.0;

	return(_rResult);
}

const TVector4f& IdentityQuaternion(TVector4f& _rResult)
{
	_rResult.m_fW = 1.0f;

	_rResult.m_fX = 0.0f;
	_rResult.m_fY = 0.0f;
	_rResult.m_fZ = 0.0f;

	return(_rResult);
}

const TVector4d& ConjugateQuaternion(TVector4d& _rResult, const TVector4d& _krQuaternion)
{
	_rResult.m_dW = _krQuaternion.m_dW;

	_rResult.m_dX = -_krQuaternion.m_dX;
	_rResult.m_dY = -_krQuaternion.m_dY;
	_rResult.m_dZ = -_krQuaternion.m_dZ;

	return(_rResult);
}

const TVector4f& ConjugateQuaternion(TVector4f& _rResult, const TVector4f& _krQuaternion)
{
	_rResult.m_fW = _krQuaternion.m_fW;

	_rResult.m_fX = -_krQuaternion.m_fX;
	_rResult.m_fY = -_krQuaternion.m_fY;
	_rResult.m_fZ = -_krQuaternion.m_fZ;

	return(_rResult);
}

const TVector4d& InverseQuaternion(TVector4d& _rResult, const TVector4d& _krQuaternion)
{
	_rResult = ScalarMultiply(_rResult, 
									ConjugateQuaternion(TVector4d(), _krQuaternion),
									(1.0 / Square(QuaternionMagnitude(_krQuaternion))));

	return(_rResult);
}

const TVector4f& InverseQuaternion(TVector4f& _rResult, const TVector4f& _krQuaternion)
{
	_rResult = ScalarMultiply(_rResult, 
									ConjugateQuaternion(TVector4f(), _krQuaternion),
									(1.0f / Square(QuaternionMagnitude(_krQuaternion))));

	return(_rResult);
}

const TVector4d& UnitQuaternion(TVector4d& _rResult, const TVector4d& _krQuaternion)
{
	_rResult = ScalarMultiply(	_rResult,
										_krQuaternion,
										(1.0 / QuaternionMagnitude(_krQuaternion)));

	return(_rResult);
}

const TVector4f& UnitQuaternion(TVector4f& _rResult, const TVector4f& _krQuaternion)
{
	_rResult = ScalarMultiply(	_rResult,
										_krQuaternion,
										(1.0f / QuaternionMagnitude(_krQuaternion)));

	return(_rResult);
}

const TVector4d& AxisAngleQuaternion(TVector4d& _rResult, const TVector3d& _krAxis, const double _kdAngle)
{
	_rResult.m_dW = Cosine(_kdAngle / 2.0);

	_rResult.m_dX = _krAxis.m_dX * Sine(_kdAngle / 2.0);
	_rResult.m_dY = _krAxis.m_dY * Sine(_kdAngle / 2.0);
	_rResult.m_dZ = _krAxis.m_dZ * Sine(_kdAngle / 2.0);

	return(_rResult);
}

const TVector4f& AxisAngleQuaternion(TVector4f& _rResult, const TVector3f& _krAxis, const float _kfAngle)
{
	_rResult.m_fW = Cosine(_kfAngle / 2.0f);

	_rResult.m_fX = _krAxis.m_fX * Sine(_kfAngle / 2.0f);
	_rResult.m_fY = _krAxis.m_fY * Sine(_kfAngle / 2.0f);
	_rResult.m_fZ = _krAxis.m_fZ * Sine(_kfAngle / 2.0f);

	return(_rResult);
}

const double QuaternionMagnitude(const TVector4d& _krQuaternion)
{
	return(SquareRoot(QuaternionProduct(TVector4d(),
													ConjugateQuaternion(	TVector4d(),
																				_krQuaternion),
													_krQuaternion).m_dW));
}

const float QuaternionMagnitude(const TVector4f& _krQuaternion)
{
	return(SquareRoot(QuaternionProduct(TVector4f(),
													ConjugateQuaternion(	TVector4f(),
																				_krQuaternion),
													_krQuaternion).m_fW));
}

const TVector4d& QuaternionProduct(TVector4d& _rResult, const TVector4d& _krA, const TVector4d& _krB)
{
	_rResult.m_dW = (_krA.m_dW * _krB.m_dW) - (_krA.m_dX * _krB.m_dX) - (_krA.m_dY * _krB.m_dY) - (_krA.m_dZ * _krB.m_dZ);
	_rResult.m_dX = (_krA.m_dW * _krB.m_dX) + (_krA.m_dX * _krB.m_dW) + (_krA.m_dY * _krB.m_dZ) - (_krA.m_dZ * _krB.m_dY);
	_rResult.m_dY = (_krA.m_dW * _krB.m_dY) - (_krA.m_dX * _krB.m_dZ) + (_krA.m_dY * _krB.m_dW) + (_krA.m_dZ * _krB.m_dX);
	_rResult.m_dZ = (_krA.m_dW * _krB.m_dZ) + (_krA.m_dX * _krB.m_dY) - (_krA.m_dY * _krB.m_dX) + (_krA.m_dZ * _krB.m_dW);

	return(_rResult);
}

const TVector4f& QuaternionProduct(TVector4f& _rResult, const TVector4f& _krA, const TVector4f& _krB)
{
	_rResult.m_fW = (_krA.m_fW * _krB.m_fW) - (_krA.m_fX * _krB.m_fX) - (_krA.m_fY * _krB.m_fY) - (_krA.m_fZ * _krB.m_fZ);
	_rResult.m_fX = (_krA.m_fW * _krB.m_fX) + (_krA.m_fX * _krB.m_fW) + (_krA.m_fY * _krB.m_fZ) - (_krA.m_fZ * _krB.m_fY);
	_rResult.m_fY = (_krA.m_fW * _krB.m_fY) - (_krA.m_fX * _krB.m_fZ) + (_krA.m_fY * _krB.m_fW) + (_krA.m_fZ * _krB.m_fX);
	_rResult.m_fZ = (_krA.m_fW * _krB.m_fZ) + (_krA.m_fX * _krB.m_fY) - (_krA.m_fY * _krB.m_fX) + (_krA.m_fZ * _krB.m_fW);

	return(_rResult);
}

const TVector3d& QuaternionRotate(TVector3d& _rResult, const TVector3d& _krVector, const TVector4d& _krQuaternion)
{
	const TVector4d kVecAsQuat{_krVector.m_dX, _krVector.m_dY, _krVector.m_dZ, 0.0};

	const TVector4d kResultAsQuat = QuaternionProduct(TVector4d(),
															QuaternionProduct(TVector4d(), _krQuaternion, kVecAsQuat),
															ConjugateQuaternion(TVector4d(), _krQuaternion));

	_rResult.m_dX = kResultAsQuat.m_dX;
	_rResult.m_dY = kResultAsQuat.m_dY;
	_rResult.m_dZ = kResultAsQuat.m_dZ;

	return(_rResult);
}

const TVector3f& QuaternionRotate(TVector3f& _rResult, const TVector3f& _krVector, const TVector4f& _krQuaternion)
{
	const TVector4f kVecAsQuat{_krVector.m_fX, _krVector.m_fY, _krVector.m_fZ, 0.0f};

	const TVector4f kResultAsQuat = QuaternionProduct(TVector4f(),
															QuaternionProduct(TVector4f(), _krQuaternion, kVecAsQuat),
															ConjugateQuaternion(TVector4f(), _krQuaternion));

	_rResult.m_fX = kResultAsQuat.m_fX;
	_rResult.m_fY = kResultAsQuat.m_fY;
	_rResult.m_fZ = kResultAsQuat.m_fZ;

	return(_rResult);
}

const TVector4d& Slerp(TVector4d& _rResult, const TVector4d& _krA, const TVector4d& _krB, const double _kdT)
{
	const double kdCosOmega = DotProduct(_krA, _krB);

	double dK0, dK1;
	if(Magnitude(kdCosOmega) == 1.0) // Avoid divide by zero using lerp
	{
		dK0 = 1.0 - _kdT;
		dK1 = _kdT;
	}
	else
	{
		const double kdSinOmega = SquareRoot(1.0 - Square(kdCosOmega));
		const double kdOmega = ArcTan2(kdSinOmega, kdCosOmega);

		dK0 = Sine((1.0 - _kdT) * kdOmega) * (1.0 / kdSinOmega);
		dK1 = Sine(_kdT * kdOmega) * (1.0 / kdSinOmega);
	}

	_rResult.m_dW = (_krA.m_dW * dK0) + (_krB.m_dW * dK1);
	_rResult.m_dX = (_krA.m_dX * dK0) + (_krB.m_dX * dK1);
	_rResult.m_dY = (_krA.m_dY * dK0) + (_krB.m_dY * dK1);
	_rResult.m_dZ = (_krA.m_dZ * dK0) + (_krB.m_dZ * dK1);

	return(_rResult);
}

const TVector4f& Slerp(TVector4f& _rResult, const TVector4f& _krA, const TVector4f& _krB, const float _kfT)
{
	const float kfCosOmega = DotProduct(_krA, _krB);

	float fK0, fK1;
	if(Magnitude(kfCosOmega) == 1.0f) // Avoid divide by zero using lerp
	{
		fK0 = 1.0f - _kfT;
		fK1 = _kfT;
	}
	else
	{
		const float kfSinOmega = SquareRoot(1.0f - Square(kfCosOmega));
		const float kfOmega = ArcTan2(kfSinOmega, kfCosOmega);

		fK0 = Sine((1.0f - _kfT) * kfOmega) * (1.0f / kfSinOmega);
		fK1 = Sine(_kfT * kfOmega) * (1.0f / kfSinOmega);
	}

	_rResult.m_fW = (_krA.m_fW * fK0) + (_krB.m_fW * fK1);
	_rResult.m_fX = (_krA.m_fX * fK0) + (_krB.m_fX * fK1);
	_rResult.m_fY = (_krA.m_fY * fK0) + (_krB.m_fY * fK1);
	_rResult.m_fZ = (_krA.m_fZ * fK0) + (_krB.m_fZ * fK1);

	return(_rResult);
}