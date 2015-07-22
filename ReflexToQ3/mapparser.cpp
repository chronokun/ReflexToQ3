//
//	Author:	Michael Cameron
//	Email:	chronokun@hotmail.com
//

// Libraries Include
#include "libraries.h"
// This Include
#include "mapparser.h"

const bool CMapParser::LoadMap(const char* _kpcFileName)
{
	std::ifstream InFile;
	EParserState eState = PARSERSTATE_UNKNOWN;

	InFile.open(_kpcFileName, std::ios::in);
	if(InFile.is_open())
	{
		std::string Line;
		bool bAdvance = true;
		bool bGoing = true;
		while(bGoing)
		{
			if(bAdvance)
			{
				if(!std::getline(InFile, Line))
				{
					bGoing = false;
				}
			}
			bAdvance = true;
			if(eState == PARSERSTATE_UNKNOWN)
			{
				if(strcmp(Line.c_str(), "entity") == 0)
				{
					eState = PARSERSTATE_ENTITY;
					continue;
				}
			}
			else if(eState == PARSERSTATE_ENTITY)
			{
				eState = this->ParseEntity(Line);
			}
			else if(eState == PARSERSTATE_WORLDSPAWN)
			{
				eState = this->ParseWorldSpawn(Line);
			}
			else if(eState == PARSERSTATE_BRUSH)
			{
				eState = this->ParseBrush(Line);
				//bAdvance = false;
			}
			else if(eState == PARSERSTATE_VERTEX)
			{
				eState = this->ParseVertex(Line);
				if(eState != PARSERSTATE_VERTEX)
				{
					bAdvance = false;
				}
			}
			else if(eState == PARSERSTATE_FACE)
			{
				eState = this->ParseFace(Line);
				if(eState != PARSERSTATE_FACE)
				{
					bAdvance = false;
				}
			}
		}
		InFile.close();
	}
	else
	{
		return(false);
	}

	return(true);
}

EParserState CMapParser::ParseEntity(const std::string _Line)
{
	const size_t kszLineSize = 256;
	char pcLine[kszLineSize];
	const char* kpcDelim  = " ";
	char* pcToken;
	char* pcContext;

	strcpy_s(pcLine, _Line.c_str());
	pcToken = strtok_s(pcLine, kpcDelim, &pcContext);

	while(pcToken != nullptr)
	{
		if(strcmp(pcToken, "\ttype") == 0)
		{
			pcToken = strtok_s(nullptr, kpcDelim, &pcContext);
			if(strcmp(pcToken, "WorldSpawn") == 0)
			{
				return(PARSERSTATE_WORLDSPAWN);
			}
			else
			{
				return(PARSERSTATE_UNKNOWN);
			}
		}
		else
		{
			return(PARSERSTATE_ENTITY);
		}
	}
	return(PARSERSTATE_UNKNOWN);
}

EParserState CMapParser::ParseWorldSpawn(const std::string _Line)
{
	if(strcmp(_Line.c_str(), "brush") == 0)
	{
		this->m_WorldSpawn.m_Brushes.push_back(TBrush());
		return(PARSERSTATE_BRUSH);
	}
	return(PARSERSTATE_WORLDSPAWN);
}

EParserState CMapParser::ParseBrush(const std::string _Line)
{
	if(strcmp(_Line.c_str(), "brush") == 0)
	{
		this->m_WorldSpawn.m_Brushes.push_back(TBrush());
		return(PARSERSTATE_BRUSH);
	}
	if(strcmp(_Line.c_str(), "\tvertices") == 0)
	{
		return(PARSERSTATE_VERTEX);
	}
	else if(strcmp(_Line.c_str(), "\tfaces") == 0)
	{
		return(PARSERSTATE_FACE);
	}
	return(PARSERSTATE_BRUSH);
}

EParserState CMapParser::ParseVertex(const std::string _Line)
{
	const size_t kszLineSize = 2048;
	char pcLine[kszLineSize];
	const char* kpcDelim  = " \t";
	char* pcToken;
	char* pcContext;

	strcpy_s(pcLine, _Line.c_str());
	pcToken = strtok_s(pcLine, kpcDelim, &pcContext);

	TVector3f Vert;
	int iTokenNum = 0;
	while(pcToken != nullptr)
	{
		if(std::isdigit(pcToken[0], std::locale()) || pcToken[0] == '-')
		{
			double dValue = std::stod(pcToken);
			if(iTokenNum == 0)
			{
				Vert.m_fX = (float)dValue;
			}
			else if(iTokenNum == 1)
			{
				Vert.m_fY = (float)dValue;
			}
			else if(iTokenNum == 2)
			{
				Vert.m_fZ = (float)dValue;
			}
			iTokenNum++;
		}
		else
		{
			return(PARSERSTATE_BRUSH);
		}

		pcToken = strtok_s(nullptr, kpcDelim, &pcContext);
	}

	this->m_WorldSpawn.m_Brushes[this->m_WorldSpawn.m_Brushes.size()-1].m_Vertices.push_back(Vert);
	return(PARSERSTATE_VERTEX);
}

EParserState CMapParser::ParseFace(const std::string _Line)
{
	const size_t kszLineSize = 2048;
	char pcLine[kszLineSize];
	const char* kpcDelim  = " \t";
	char* pcToken;
	char* pcContext;

	strcpy_s(pcLine, _Line.c_str());
	pcToken = strtok_s(pcLine, kpcDelim, &pcContext);

	int iTokenNum = 0;

	std::string material;

	std::vector<int> Indices;
	while(pcToken != nullptr)
	{
		if(iTokenNum < 5)
		{
			if(std::isdigit(pcToken[0], std::locale()) || pcToken[0] == '-')
			{
				double dValue = std::stod(pcToken);
			}
			else
			{
				return(PARSERSTATE_BRUSH);
			}
		}
		else
		{
			if(std::isdigit(pcToken[0], std::locale()) || pcToken[0] == '-')
			{
				int iValue = std::stoi(pcToken);
				Indices.push_back(iValue);
			}
			else
			{
				material = pcToken;
			}
		}

		iTokenNum++;
		pcToken = strtok_s(nullptr, kpcDelim, &pcContext);
	}
	
	TFace Face;
	Face.m_Indices = Indices;
	Face.m_Material = material;
	this->m_WorldSpawn.m_Brushes[this->m_WorldSpawn.m_Brushes.size()-1].m_Faces.push_back(Face);
	return(PARSERSTATE_FACE);
}