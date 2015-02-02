//
//	Author:	Michael Cameron
//	Email:	chronokun@hotmail.com
//

#pragma once

#ifndef __MATH_TYPES_H__
#define __MATH_TYPES_H__

//
//
// Struct Prototypes
//
//


//
// Vector
//
struct TVector4d
{
	double m_dX;
	double m_dY;
	double m_dZ;
	double m_dW;
};

struct TVector4f
{
	float m_fX;
	float m_fY;
	float m_fZ;
	float m_fW;
};

struct TVector3d
{
	double m_dX;
	double m_dY;
	double m_dZ;
};

struct TVector3f
{
	float m_fX;
	float m_fY;
	float m_fZ;
};

struct TVector2d
{
	double m_dX;
	double m_dY;
};

struct TVector2f
{
	float m_fX;
	float m_fY;
};

//
// Matrix
//
struct TMatrix4d
{
	double m_d11, m_d12, m_d13, m_d14;
	double m_d21, m_d22, m_d23, m_d24;
	double m_d31, m_d32, m_d33, m_d34;
	double m_d41, m_d42, m_d43, m_d44;
};

struct TMatrix4f
{
	float m_f11, m_f12, m_f13, m_f14;
	float m_f21, m_f22, m_f23, m_f24;
	float m_f31, m_f32, m_f33, m_f34;
	float m_f41, m_f42, m_f43, m_f44;
};

struct TMatrix3d
{
	double m_d11, m_d12, m_d13;
	double m_d21, m_d22, m_d23;
	double m_d31, m_d32, m_d33;
};

struct TMatrix3f
{
	float m_f11, m_f12, m_f13;
	float m_f21, m_f22, m_f23;
	float m_f31, m_f32, m_f33;
};

struct TMatrix2d
{
	double m_d11, m_d12;
	double m_d21, m_d22;
};

struct TMatrix2f
{
	float m_f11, m_f12;
	float m_f21, m_f22;
};

//
// Plane
//
struct TPlane3d
{
	TVector3d m_Point;
	TVector3d m_Normal;
};

struct TPlane3f
{
	TVector3f m_Point;
	TVector3f m_Normal;

};

struct TPlane2d
{
	TVector2d m_Point;
	TVector2d m_Normal;
};

struct TPlane2f
{
	TVector2f m_Point;
	TVector2f m_Normal;
};

//
// Triangle
//
struct TTriangle3d
{
	TVector3d m_A;
	TVector3d m_B;
	TVector3d m_C;
};

struct TTriangle3f
{
	TVector3f m_A;
	TVector3f m_B;
	TVector3f m_C;
};

struct TTriangle2d
{
	TVector2d m_A;
	TVector2d m_B;
	TVector2d m_C;
};

struct TTriangle2f
{
	TVector2f m_A;
	TVector2f m_B;
	TVector2f m_C;
};

//
// Line
//
struct TLine3d
{
	TVector3d m_A;
	TVector3d m_B;
};

struct TLine3f
{
	TVector3f m_A;
	TVector3f m_B;
};

struct TLine2d
{
	TVector2d m_A;
	TVector2d m_B;
};

struct TLine2f
{
	TVector2f m_A;
	TVector2f m_B;
};

//
// Ray
//
struct TRay3d
{
	TVector3d m_Start;
	TVector3d m_Direction;
};

struct TRay3f
{
	TVector3f m_Start;
	TVector3f m_Direction;
};

struct TRay2d
{
	TVector2d m_Start;
	TVector2d m_Direction;
};

struct TRay2f
{
	TVector2f m_Start;
	TVector2f m_Direction;
};

//
// Sphere
//
struct TSphere3d
{
	TVector3d m_Center;
	double m_dRadius;
};

struct TSphere3f
{
	TVector3f m_Center;
	float m_fRadius;
};

//
// Circle
//
struct TCircle2d
{
	TVector2d m_Center;
	double m_dRadius;
};

struct TCircle2f
{
	TVector2f m_Center;
	float m_fRadius;
};

//
// Capsule
//
struct TCapsule3d
{
	TLine3d m_Line;
	double m_dRadius;
};

struct TCapsule3f
{
	TLine3f m_Line;
	float m_fRadius;
};

struct TCapsule2d
{
	TLine2d m_Line;
	double m_dRadius;
};

struct TCapsule2f
{
	TLine2f m_Line;
	float m_fRadius;
};

//
// AABB
//
struct TAABB3d
{
	TVector3d m_MinPoint;
	TVector3d m_MaxPoint;
};

struct TAABB3f
{
	TVector3f m_MinPoint;
	TVector3f m_MaxPoint;
};

struct TAABB2d
{
	TVector2d m_MinPoint;
	TVector2d m_MaxPoint;
};

struct TAABB2f
{
	TVector2f m_MinPoint;
	TVector2f m_MaxPoint;
};


#endif