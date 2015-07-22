//
//	Author:	Michael Cameron
//	Email:	chronokun@hotmail.com
//

#pragma once

#ifndef __LIBRARIES_H__
#define __LIBRARIES_H__

// Visual Leak Detector
#if defined(DEBUG) || defined(_DEBUG)  
//#include <vld.h>
#endif

// Platform Libraries
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

// Chronokun Libraries
#include "ckmath/ckmath.h"

// C++ Libraries
#include <cstdint>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>
#include <array>
#include <fstream>
#include <chrono>
#include <ctime>
#include <iostream>
#include <sstream>
#include <locale>

#endif