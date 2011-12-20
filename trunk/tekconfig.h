#pragma once
#ifndef _TEKSTORM_TEKCONFIG_H
#define _TEKSTORM_TEKCONFIG_H 

///
/// Debug-build mode
///
#if defined(_DEBUG)
	#define TEKSTORM_DEBUG
#endif

///
/// Whether or not the build is as a DLL
///
#if defined(TEKSTORM_BUILD_DLL)
	#if defined (TEKSTORM_BUILD)
		#define TEKAPI __declspec(dllexport)
	#else
		#define TEKAPI __declspec(dllimport)
	#endif
#else
	#define TEKAPI
#endif

///
/// Whether or not to use float or double for real type.
///
#if defined(TEKSTORM_PRECISE_MATH)
	typedef double tekreal;
#else
	typedef float tekreal;
#endif

/// 
/// Allows declaring of external resources.
/// i.e. TEKHANDLE(SomeExternalHandleType, pDevice);
///
#define TEKHANDLE(a,b) void *b

///
/// Standard include libraries
///
#include <iostream>
#include <string>
#include <cmath>
#include <memory>
#include <stdint.h>
#include <vector>

namespace Tekstorm
{
	namespace Core
	{
	}

	namespace Graphics
	{
	}

	namespace IO
	{
		class TEKAPI IStream;
		class TEKAPI MemoryStream;
		class TEKAPI TextWriter;
	}

	namespace Math
	{
	}

	namespace Networking
	{
		class TEKAPI IPAddress;
		class TEKAPI IPEndPoint;
		class TEKAPI NetworkStream;
		class TEKAPI Socket;
	}

	namespace Physics
	{
	}

	namespace Scripting
	{
	}
}

#endif /* _TEKSTORM_TEKCONFIG_H */