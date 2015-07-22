//
//	Author:	Michael Cameron
//	Email:	chronokun@hotmail.com
//

// Libraries Include
#include "libraries.h"
// Local Includes
#include "mapparser.h"

// Structs
struct TPlanePoints
{
	TVector3f m_A;
	TVector3f m_B;
	TVector3f m_C;
	std::string m_material;
};

TPlanePoints GetPlanePoints(const TVector3f* _kpPoints, const size_t _kNumPoints)
{
	TPlanePoints PlanePoints;

	// Find Normal
	const TVector3f kNormal = GetPolygonNormal(TVector3f(), _kpPoints, _kNumPoints);

	// Find center point
	TVector3f Temp{0.0f, 0.0f, 0.0f};
	for(size_t i = 0; i < _kNumPoints; ++i)
	{
		Temp = Add(Temp, Temp, _kpPoints[i]);
	}
	const TVector3f kCenter = ScalarMultiply(TVector3f(), Temp, (1.0f / (float)_kNumPoints));

	// Find Tangent
	const TVector3f kTangent = ScalarMultiply(TVector3f(), Normalize(TVector3f(), Subtract(TVector3f(), _kpPoints[1], _kpPoints[0])), 128.0f);

	// Find BiTangent
	const TVector3f kBiTangent = ScalarMultiply(TVector3f(), Normalize(TVector3f(), CrossProduct(TVector3f(), kNormal, kTangent)), 128.0f);

	PlanePoints.m_A = Add(TVector3f(), kCenter, kBiTangent);
	PlanePoints.m_B = kCenter;
	PlanePoints.m_C = Add(TVector3f(), kCenter, kTangent);

	return(PlanePoints);
}

std::vector<TPlanePoints> GetBrushPlanes(const TBrush& _krBrush)
{
	std::vector<TPlanePoints> Planes;
	for(const TFace& krFace : _krBrush.m_Faces)
	{
		std::vector<TVector3f> Verts(krFace.m_Indices.size());
		for(size_t i = 0; i < krFace.m_Indices.size(); ++i)
		{
			Verts[i] = _krBrush.m_Vertices[krFace.m_Indices[i]];
		}
		TPlanePoints PP = GetPlanePoints(Verts.data(), Verts.size());
		PP.m_material = krFace.m_Material;
		Planes.push_back(PP);
	}

	return(Planes);
}

std::string GetBrushString(const TBrush& _krBrush)
{
	std::vector<TPlanePoints> Planes = GetBrushPlanes(_krBrush);
	std::stringstream ssOutput;

	if(Planes.size())
	{
		ssOutput << "{" << std::endl;
		for(const TPlanePoints& krPlane : Planes)
		{
			ssOutput << "( " << krPlane.m_A.m_fX << " " << krPlane.m_A.m_fZ << " " << krPlane.m_A.m_fY << " ) ";
			ssOutput << "( " << krPlane.m_B.m_fX << " " << krPlane.m_B.m_fZ << " " << krPlane.m_B.m_fY << " ) ";
			ssOutput << "( " << krPlane.m_C.m_fX << " " << krPlane.m_C.m_fZ << " " << krPlane.m_C.m_fY << " ) ";
			if(krPlane.m_material.length())
			{
				ssOutput << krPlane.m_material << " 0 0 0 0.500000 0.500000 0 4 0" << std::endl;
			}
			else
			{
				ssOutput << "common/caulk 0 0 0 0.500000 0.500000 0 4 0" << std::endl;
			}
		}
		ssOutput << "}" << std::endl;
	}

	return(ssOutput.str());
}

int main(const int _kiArgC, const char** _kppcArgv)
{
	// Check we have correct number of parameters
	if(_kiArgC < 3)
	{
		return(3);
	}

	CMapParser Parser;

	const bool kbSuccess = Parser.LoadMap(_kppcArgv[1]);
	if(!kbSuccess)
	{
		return(1);
	}
	else
	{
		// Open output file
		std::ofstream OutFile;
		OutFile.open(_kppcArgv[2]);
		if(!OutFile.is_open())
		{
			return(2);
		}

		OutFile	<<	"{" << std::endl
				<<	"\"classname\" \"worldspawn\"" << std::endl;

		for(const TBrush& krBrush : Parser.m_WorldSpawn.m_Brushes)
		{
			OutFile << GetBrushString(krBrush);
		}

		OutFile << "}" << std::endl;
	}

	return(0);
}
