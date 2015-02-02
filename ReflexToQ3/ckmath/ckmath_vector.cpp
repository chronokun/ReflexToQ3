//
//	Author:	Michael Cameron
//	Email:	chronokun@hotmail.com
//


// Local Includes
#include "ckmath_vector.h"
#include "ckmath_scalar.h"


//
// Vector 4
//

const TVector4d& ZeroVector(TVector4d& _rResult)
{
	_rResult.m_dX = 0.0;
	_rResult.m_dY = 0.0;
	_rResult.m_dZ = 0.0;
	_rResult.m_dW = 0.0;

	return(_rResult);
}

const TVector4f& ZeroVector(TVector4f& _rResult)
{
	_rResult.m_fX = 0.0f;
	_rResult.m_fY = 0.0f;
	_rResult.m_fZ = 0.0f;
	_rResult.m_fW = 0.0f;

	return(_rResult);
}

const bool Equal(	const TVector4d& _krA,
						const TVector4d& _krB,
						const double _kdEpsilon)
{
	const bool kbEqual =	(Magnitude(_krA.m_dX - _krB.m_dX) < _kdEpsilon)
						&&	(Magnitude(_krA.m_dY - _krB.m_dY) < _kdEpsilon)
						&&	(Magnitude(_krA.m_dZ - _krB.m_dZ) < _kdEpsilon)
						&&	(Magnitude(_krA.m_dW - _krB.m_dW) < _kdEpsilon);

	return(kbEqual);
}

const bool Equal(	const TVector4f& _krA,
						const TVector4f& _krB,
						const float _kfEpsilon)
{
	const bool kbEqual =	(Magnitude(_krA.m_fX - _krB.m_fX) < _kfEpsilon)
						&&	(Magnitude(_krA.m_fY - _krB.m_fY) < _kfEpsilon)
						&&	(Magnitude(_krA.m_fZ - _krB.m_fZ) < _kfEpsilon)
						&&	(Magnitude(_krA.m_fW - _krB.m_fW) < _kfEpsilon);

	return(kbEqual);
}

const TVector4d& Add(	TVector4d& _rResult,
							const TVector4d& _krA, 
							const TVector4d& _krB)
{
	_rResult.m_dX = _krA.m_dX + _krB.m_dX;
	_rResult.m_dY = _krA.m_dY + _krB.m_dY;
	_rResult.m_dZ = _krA.m_dZ + _krB.m_dZ;
	_rResult.m_dW = _krA.m_dW + _krB.m_dW;

	return(_rResult);
}

const TVector4f& Add(	TVector4f& _rResult,
							const TVector4f& _krA, 
							const TVector4f& _krB)
{
	_rResult.m_fX = _krA.m_fX + _krB.m_fX;
	_rResult.m_fY = _krA.m_fY + _krB.m_fY;
	_rResult.m_fZ = _krA.m_fZ + _krB.m_fZ;
	_rResult.m_fW = _krA.m_fW + _krB.m_fW;

	return(_rResult);
}

const TVector4d& Subtract(TVector4d& _rResult,
								const TVector4d& _krA,
								const TVector4d& _krB)
{
	_rResult.m_dX = _krA.m_dX - _krB.m_dX;
	_rResult.m_dY = _krA.m_dY - _krB.m_dY;
	_rResult.m_dZ = _krA.m_dZ - _krB.m_dZ;
	_rResult.m_dW = _krA.m_dW - _krB.m_dW;

	return(_rResult);
}

const TVector4f& Subtract(TVector4f& _rResult,
								const TVector4f& _krA,
								const TVector4f& _krB)
{
	_rResult.m_fX = _krA.m_fX - _krB.m_fX;
	_rResult.m_fY = _krA.m_fY - _krB.m_fY;
	_rResult.m_fZ = _krA.m_fZ - _krB.m_fZ;
	_rResult.m_fW = _krA.m_fW - _krB.m_fW;

	return(_rResult);
}

const TVector4d& ScalarMultiply(	TVector4d& _rResult,
										const TVector4d& _krV,
										const double _kdS)
{
	_rResult.m_dX = _krV.m_dX * _kdS;
	_rResult.m_dY = _krV.m_dY * _kdS;
	_rResult.m_dZ = _krV.m_dZ * _kdS;
	_rResult.m_dW = _krV.m_dW * _kdS;

	return(_rResult);
}

const TVector4f& ScalarMultiply(	TVector4f& _rResult,
										const TVector4f& _krV,
										const float _kfS)
{
	_rResult.m_fX = _krV.m_fX * _kfS;
	_rResult.m_fY = _krV.m_fY * _kfS;
	_rResult.m_fZ = _krV.m_fZ * _kfS;
	_rResult.m_fW = _krV.m_fW * _kfS;

	return(_rResult);
}

const double VectorMagnitude(const TVector4d& _krV)
{
	return(SquareRoot(	Square(_krV.m_dX)
							+	Square(_krV.m_dY)
							+	Square(_krV.m_dZ)
							+	Square(_krV.m_dW)));
}

const float VectorMagnitude(const TVector4f& _krV)
{
	return(SquareRoot(	Square(_krV.m_fX)
							+	Square(_krV.m_fY)
							+	Square(_krV.m_fZ)
							+	Square(_krV.m_fW)));
}

const double DotProduct(	const TVector4d& _krA,
								const TVector4d& _krB)
{
	const double kdResult = (	(_krA.m_dX * _krB.m_dX)
							+	(_krA.m_dY * _krB.m_dY)
							+	(_krA.m_dZ * _krB.m_dZ)
							+	(_krA.m_dW * _krB.m_dW));

	return(kdResult);
}

const float DotProduct(	const TVector4f& _krA,
								const TVector4f& _krB)
{
	const float kfResult = (	(_krA.m_fX * _krB.m_fX)
							+	(_krA.m_fY * _krB.m_fY)
							+	(_krA.m_fZ * _krB.m_fZ)
							+	(_krA.m_fW * _krB.m_fW));

	return(kfResult);
}

const TVector4d& Normalize(	TVector4d& _rResult,
									const TVector4d& _krV)
{
	ScalarMultiply(_rResult, _krV, (1.0 / VectorMagnitude(_krV)) );
	return(_rResult);
}

const TVector4f& Normalize(	TVector4f& _rResult,
									const TVector4f& _krV)
{
	ScalarMultiply(_rResult, _krV, (1.0f / VectorMagnitude(_krV)) );
	return(_rResult);
}

const TVector4d& Projection(	TVector4d& _rResult,
									const TVector4d& _krA,
									const TVector4d& _krB)
{
	const double kdDenom = Square(VectorMagnitude(_krB));

	const TVector4d kNumer = ScalarMultiply(TVector4d(), _krB, DotProduct(_krA, _krB));

	_rResult = ScalarMultiply(_rResult, kNumer, kdDenom);

	return(_rResult);
}

const TVector4f& Projection(	TVector4f& _rResult,
									const TVector4f& _krA,
									const TVector4f& _krB)
{
	const float kfDenom = Square(VectorMagnitude(_krB));

	const TVector4f kNumer = ScalarMultiply(TVector4f(), _krB, DotProduct(_krA, _krB));

	_rResult = ScalarMultiply(_rResult, kNumer, kfDenom);

	return(_rResult);
}

const double AngleBetween(const TVector4d& _krA,
								const TVector4d& _krB)
{
	const double kdAngle = ArcCos(	DotProduct(_krA, _krB) 
										/	( VectorMagnitude(_krA) * VectorMagnitude(_krB) ) );

	return(kdAngle);
}

const float AngleBetween(	const TVector4f& _krA,
								const TVector4f& _krB)
{
	const float kfAngle = ArcCos(		DotProduct(_krA, _krB) 
										/	( VectorMagnitude(_krA) * VectorMagnitude(_krB) ) );

	return(kfAngle);
}

const double Distance(const TVector4d& _krA,
							const TVector4d& _krB)
{
	const double kdDistance = VectorMagnitude(Subtract(TVector4d(), _krA, _krB));

	return(kdDistance);
}

const float Distance(	const TVector4f& _krA,
							const TVector4f& _krB)
{
	const float kfDistance = VectorMagnitude(Subtract(TVector4f(), _krA, _krB));

	return(kfDistance);
}

//
// Vector 3
//

const TVector3d& ZeroVector(TVector3d& _rResult)
{
	_rResult.m_dX = 0.0;
	_rResult.m_dY = 0.0;
	_rResult.m_dZ = 0.0;

	return(_rResult);
}

const TVector3f& ZeroVector(TVector3f& _rResult)
{
	_rResult.m_fX = 0.0f;
	_rResult.m_fY = 0.0f;
	_rResult.m_fZ = 0.0f;

	return(_rResult);
}

const bool Equal(	const TVector3d& _krA,
						const TVector3d& _krB,
						const double _kdEpsilon)
{
	const bool kbEqual =	(Magnitude(_krA.m_dX - _krB.m_dX) < _kdEpsilon)
						&&	(Magnitude(_krA.m_dY - _krB.m_dY) < _kdEpsilon)
						&&	(Magnitude(_krA.m_dZ - _krB.m_dZ) < _kdEpsilon);

	return(kbEqual);
}

const bool Equal(	const TVector3f& _krA,
						const TVector3f& _krB,
						const float _kfEpsilon)
{
	const bool kbEqual =	(Magnitude(_krA.m_fX - _krB.m_fX) < _kfEpsilon)
						&&	(Magnitude(_krA.m_fY - _krB.m_fY) < _kfEpsilon)
						&&	(Magnitude(_krA.m_fZ - _krB.m_fZ) < _kfEpsilon);

	return(kbEqual);
}

const TVector3d& Add(	TVector3d& _rResult,
							const TVector3d& _krA, 
							const TVector3d& _krB)
{
	_rResult.m_dX = _krA.m_dX + _krB.m_dX;
	_rResult.m_dY = _krA.m_dY + _krB.m_dY;
	_rResult.m_dZ = _krA.m_dZ + _krB.m_dZ;

	return(_rResult);
}

const TVector3f& Add(	TVector3f& _rResult,
							const TVector3f& _krA, 
							const TVector3f& _krB)
{
	_rResult.m_fX = _krA.m_fX + _krB.m_fX;
	_rResult.m_fY = _krA.m_fY + _krB.m_fY;
	_rResult.m_fZ = _krA.m_fZ + _krB.m_fZ;

	return(_rResult);
}

const TVector3d& Subtract(TVector3d& _rResult,
								const TVector3d& _krA,
								const TVector3d& _krB)
{
	_rResult.m_dX = _krA.m_dX - _krB.m_dX;
	_rResult.m_dY = _krA.m_dY - _krB.m_dY;
	_rResult.m_dZ = _krA.m_dZ - _krB.m_dZ;

	return(_rResult);
}

const TVector3f& Subtract(TVector3f& _rResult,
								const TVector3f& _krA,
								const TVector3f& _krB)
{
	_rResult.m_fX = _krA.m_fX - _krB.m_fX;
	_rResult.m_fY = _krA.m_fY - _krB.m_fY;
	_rResult.m_fZ = _krA.m_fZ - _krB.m_fZ;

	return(_rResult);
}

const TVector3d& ScalarMultiply(	TVector3d& _rResult,
										const TVector3d& _krV,
										const double _kdS)
{
	_rResult.m_dX = _krV.m_dX * _kdS;
	_rResult.m_dY = _krV.m_dY * _kdS;
	_rResult.m_dZ = _krV.m_dZ * _kdS;

	return(_rResult);
}

const TVector3f& ScalarMultiply(	TVector3f& _rResult,
										const TVector3f& _krV,
										const float _kfS)
{
	_rResult.m_fX = _krV.m_fX * _kfS;
	_rResult.m_fY = _krV.m_fY * _kfS;
	_rResult.m_fZ = _krV.m_fZ * _kfS;

	return(_rResult);
}

const double VectorMagnitude(const TVector3d& _krV)
{
	return(SquareRoot(	Square(_krV.m_dX)
							+	Square(_krV.m_dY)
							+	Square(_krV.m_dZ)));
}

const float VectorMagnitude(const TVector3f& _krV)
{
	return(SquareRoot(	Square(_krV.m_fX)
							+	Square(_krV.m_fY)
							+	Square(_krV.m_fZ)));
}

const double DotProduct(	const TVector3d& _krA,
								const TVector3d& _krB)
{
	return(		(_krA.m_dX * _krB.m_dX)
			+	(_krA.m_dY * _krB.m_dY)
			+	(_krA.m_dZ * _krB.m_dZ));
}

const float DotProduct(	const TVector3f& _krA,
								const TVector3f& _krB)
{
	return(		(_krA.m_fX * _krB.m_fX)
			+	(_krA.m_fY * _krB.m_fY)
			+	(_krA.m_fZ * _krB.m_fZ));
}

const TVector3d& CrossProduct(TVector3d& _rResult,
									const TVector3d& _krA,
									const TVector3d& _krB)
{
	_rResult.m_dX = (_krA.m_dY * _krB.m_dZ) - ( _krA.m_dZ * _krB.m_dY);
	_rResult.m_dY = (_krA.m_dZ * _krB.m_dX) - ( _krA.m_dX * _krB.m_dZ);
	_rResult.m_dZ = (_krA.m_dX * _krB.m_dY) - ( _krA.m_dY * _krB.m_dX);

	return(_rResult);
}

const TVector3f& CrossProduct(TVector3f& _rResult,
									const TVector3f& _krA,
									const TVector3f& _krB)
{
	_rResult.m_fX = (_krA.m_fY * _krB.m_fZ) - ( _krA.m_fZ * _krB.m_fY);
	_rResult.m_fY = (_krA.m_fZ * _krB.m_fX) - ( _krA.m_fX * _krB.m_fZ);
	_rResult.m_fZ = (_krA.m_fX * _krB.m_fY) - ( _krA.m_fY * _krB.m_fX);

	return(_rResult);
}

const TVector3d& Normalize(	TVector3d& _rResult,
									const TVector3d& _krV)
{
	ScalarMultiply(_rResult, _krV, (1.0 / VectorMagnitude(_krV)) );
	return(_rResult);
}

const TVector3f& Normalize(	TVector3f& _rResult,
									const TVector3f& _krV)
{
	ScalarMultiply(_rResult, _krV, (1.0f / VectorMagnitude(_krV)) );
	return(_rResult);
}

const TVector3d& Projection(	TVector3d& _rResult,
									const TVector3d& _krA,
									const TVector3d& _krB)
{
	const double kdDenom = Square(VectorMagnitude(_krB));

	const TVector3d kNumer = ScalarMultiply(TVector3d(), _krB, DotProduct(_krA, _krB));

	_rResult = ScalarMultiply(_rResult, kNumer, kdDenom);

	return(_rResult);
}

const TVector3f& Projection(	TVector3f& _rResult,
									const TVector3f& _krA,
									const TVector3f& _krB)
{
	const float kfDenom = Square(VectorMagnitude(_krB));

	const TVector3f kNumer = ScalarMultiply(TVector3f(), _krB, DotProduct(_krA, _krB));

	_rResult = ScalarMultiply(_rResult, kNumer, kfDenom);

	return(_rResult);
}

const double AngleBetween(const TVector3d& _krA,
								const TVector3d& _krB)
{
	const double kdAngle = ArcCos(	DotProduct(_krA, _krB) 
										/	( VectorMagnitude(_krA) * VectorMagnitude(_krB) ) );

	return(kdAngle);
}

const float AngleBetween(	const TVector3f& _krA,
								const TVector3f& _krB)
{
	const float kfAngle = ArcCos(		DotProduct(_krA, _krB) 
										/	( VectorMagnitude(_krA) * VectorMagnitude(_krB) ) );

	return(kfAngle);
}

const double Distance(const TVector3d& _krA,
							const TVector3d& _krB)
{
	const double kdDistance = VectorMagnitude(Subtract(TVector3d(), _krA, _krB));

	return(kdDistance);
}

const float Distance(	const TVector3f& _krA,
							const TVector3f& _krB)
{
	const float kfDistance = VectorMagnitude(Subtract(TVector3f(), _krA, _krB));

	return(kfDistance);
}

const double ScalarTripleProduct(	const TVector3d& _krA,
										const TVector3d& _krB,
										const TVector3d& _krC)
{
	return(DotProduct(_krA, CrossProduct(TVector3d(), _krB, _krC)));
}

const float ScalarTripleProduct(	const TVector3f& _krA,
										const TVector3f& _krB,
										const TVector3f& _krC)
{
	return(DotProduct(_krA, CrossProduct(TVector3f(), _krB, _krC)));
}

const TVector3d& VectorTripleProduct(	TVector3d& _rResult,
											const TVector3d& _krA,
											const TVector3d& _krB,
											const TVector3d& _krC)
{
	return(CrossProduct(_rResult, _krA, CrossProduct(TVector3d(), _krB, _krC)));
}

const TVector3f& VectorTripleProduct(	TVector3f& _rResult,
											const TVector3f& _krA,
											const TVector3f& _krB,
											const TVector3f& _krC)
{
	return(CrossProduct(_rResult, _krA, CrossProduct(TVector3f(), _krB, _krC)));
}

//
// Vector 2
//

const TVector2d& ZeroVector(TVector2d& _rResult)
{
	_rResult.m_dX = 0.0;
	_rResult.m_dY = 0.0;

	return(_rResult);
}

const TVector2f& ZeroVector(TVector2f& _rResult)
{
	_rResult.m_fX = 0.0f;
	_rResult.m_fY = 0.0f;

	return(_rResult);
}

const bool Equal(	const TVector2d& _krA,
						const TVector2d& _krB,
						const double _kdEpsilon)
{
	const bool kbEqual =	(Magnitude(_krA.m_dX - _krB.m_dX) < _kdEpsilon)
						&&	(Magnitude(_krA.m_dY - _krB.m_dY) < _kdEpsilon);

	return(kbEqual);
}

const bool Equal(	const TVector2f& _krA,
						const TVector2f& _krB,
						const float _kfEpsilon)
{
	const bool kbEqual =	(Magnitude(_krA.m_fX - _krB.m_fX) < _kfEpsilon)
						&&	(Magnitude(_krA.m_fY - _krB.m_fY) < _kfEpsilon);

	return(kbEqual);
}

const TVector2d& Add(	TVector2d& _rResult,
							const TVector2d& _krA, 
							const TVector2d& _krB)
{
	_rResult.m_dX = _krA.m_dX + _krB.m_dX;
	_rResult.m_dY = _krA.m_dY + _krB.m_dY;

	return(_rResult);
}

const TVector2f& Add(	TVector2f& _rResult,
							const TVector2f& _krA, 
							const TVector2f& _krB)
{
	_rResult.m_fX = _krA.m_fX + _krB.m_fX;
	_rResult.m_fY = _krA.m_fY + _krB.m_fY;

	return(_rResult);
}

const TVector2d& Subtract(TVector2d& _rResult,
								const TVector2d& _krA,
								const TVector2d& _krB)
{
	_rResult.m_dX = _krA.m_dX - _krB.m_dX;
	_rResult.m_dY = _krA.m_dY - _krB.m_dY;

	return(_rResult);
}

const TVector2f& Subtract(TVector2f& _rResult,
								const TVector2f& _krA,
								const TVector2f& _krB)
{
	_rResult.m_fX = _krA.m_fX - _krB.m_fX;
	_rResult.m_fY = _krA.m_fY - _krB.m_fY;

	return(_rResult);
}

const TVector2d& ScalarMultiply(	TVector2d& _rResult,
										const TVector2d& _krV,
										const double _kdS)
{
	_rResult.m_dX = _krV.m_dX * _kdS;
	_rResult.m_dY = _krV.m_dY * _kdS;

	return(_rResult);
}

const TVector2f& ScalarMultiply(	TVector2f& _rResult,
										const TVector2f& _krV,
										const float _kfS)
{
	_rResult.m_fX = _krV.m_fX * _kfS;
	_rResult.m_fY = _krV.m_fY * _kfS;

	return(_rResult);
}

const double VectorMagnitude(const TVector2d& _krV)
{
	return(SquareRoot(	Square(_krV.m_dX)
							+	Square(_krV.m_dY)));
}

const float VectorMagnitude(const TVector2f& _krV)
{
	return(SquareRoot(	Square(_krV.m_fX)
							+	Square(_krV.m_fY)));
}

const double DotProduct(	const TVector2d& _krA,
								const TVector2d& _krB)
{
	return(		(_krA.m_dX * _krB.m_dX)
			+	(_krA.m_dY * _krB.m_dY));
}

const float DotProduct(	const TVector2f& _krA,
								const TVector2f& _krB)
{
	return(		(_krA.m_fX * _krB.m_fX)
			+	(_krA.m_fY * _krB.m_fY));
}

const TVector2d& Normalize(	TVector2d& _rResult,
									const TVector2d& _krV)
{
	ScalarMultiply(_rResult, _krV, (1.0 / VectorMagnitude(_krV)) );
	return(_rResult);
}

const TVector2f& Normalize(	TVector2f& _rResult,
									const TVector2f& _krV)
{
	ScalarMultiply(_rResult, _krV, (1.0f / VectorMagnitude(_krV)) );
	return(_rResult);
}

const TVector2d& Projection(	TVector2d& _rResult,
									const TVector2d& _krA,
									const TVector2d& _krB)
{
	const double kdDenom = Square(VectorMagnitude(_krB));

	const TVector2d kNumer = ScalarMultiply(TVector2d(), _krB, DotProduct(_krA, _krB));

	_rResult = ScalarMultiply(_rResult, kNumer, kdDenom);

	return(_rResult);
}

const TVector2f& Projection(	TVector2f& _rResult,
									const TVector2f& _krA,
									const TVector2f& _krB)
{
	const float kfDenom = Square(VectorMagnitude(_krB));

	const TVector2f kNumer = ScalarMultiply(TVector2f(), _krB, DotProduct(_krA, _krB));

	_rResult = ScalarMultiply(_rResult, kNumer, kfDenom);

	return(_rResult);
}

const double AngleBetween(const TVector2d& _krA,
								const TVector2d& _krB)
{
	const double kdAngle = ArcCos(	DotProduct(_krA, _krB) 
										/	( VectorMagnitude(_krA) * VectorMagnitude(_krB) ) );

	return(kdAngle);
}

const float AngleBetween(	const TVector2f& _krA,
								const TVector2f& _krB)
{
	const float kfAngle = ArcCos(		DotProduct(_krA, _krB) 
										/	( VectorMagnitude(_krA) * VectorMagnitude(_krB) ) );

	return(kfAngle);
}

const double Distance(const TVector2d& _krA,
							const TVector2d& _krB)
{
	const double kdDistance = VectorMagnitude(Subtract(TVector2d(), _krA, _krB));

	return(kdDistance);
}

const float Distance(	const TVector2f& _krA,
							const TVector2f& _krB)
{
	const float kfDistance = VectorMagnitude(Subtract(TVector2f(), _krA, _krB));

	return(kfDistance);
}