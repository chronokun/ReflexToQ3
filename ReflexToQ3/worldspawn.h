//
//	Author:	Michael Cameron
//	Email:	chronokun@hotmail.com
//

#pragma once

#ifndef __WORLDSPAWN_H__
#define __WORLDSPAWN_H__

struct TFace
{
	float m_fXOffset;
	float m_fYOffset;
	float m_fXScale;
	float m_fYScale;
	float m_fRotation;
	std::vector<int> m_Indices;
	std::string m_Material;
};

struct TBrush
{
	std::vector<TVector3f> m_Vertices;
	std::vector<TFace> m_Faces;

};

struct TWorldSpawn
{
	std::vector<TBrush> m_Brushes;
};

#endif