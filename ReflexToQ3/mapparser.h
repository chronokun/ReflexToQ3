//
//	Author:	Michael Cameron
//	Email:	chronokun@hotmail.com
//

#pragma once

#ifndef __MAPPARSER_H__
#define __MAPPARSER_H__

// Includes
#include "worldspawn.h"

// enums
enum EParserState
{
	PARSERSTATE_UNKNOWN,
	PARSERSTATE_ENTITY,
	PARSERSTATE_WORLDSPAWN,
	PARSERSTATE_BRUSH,
	PARSERSTATE_VERTEX,
	PARSERSTATE_FACE
};

class CMapParser
{
	// Variables
public:
	TWorldSpawn m_WorldSpawn;

	// Functions
public:
	const bool LoadMap(const char* _kpcFileName);

protected:
	EParserState ParseEntity(const std::string _Line);
	EParserState ParseWorldSpawn(const std::string _Line);
	EParserState ParseBrush(const std::string _Line);
	EParserState ParseVertex(const std::string _Line);
	EParserState ParseFace(const std::string _Line);

};

#endif