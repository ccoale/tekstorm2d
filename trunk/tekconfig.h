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
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

namespace Tekstorm
{
	namespace Core
	{
		class IDisposable;
		class IResource;
		class TEKAPI Debug;
	}

	namespace Graphics
	{
		class TEKAPI GraphicsAdapter;
		class TEKAPI GraphicsDevice;
		class TEKAPI VertexShader;
		class TEKAPI PixelShader;
		class TEKAPI VertexBuffer;
		class TEKAPI InputLayout;
		class TEKAPI Texture;
	}

	namespace IO
	{
		class TEKAPI IStream;
		class TEKAPI MemoryStream;
		class TEKAPI TextWriter;
	}

	namespace Math
	{
		class TEKAPI Color3;
		class TEKAPI Color4;
		class TEKAPI Matrix3;
		class TEKAPI Matrix4;
		class TEKAPI Vector2;
		class TEKAPI Vector3;
		class TEKAPI Vector4;
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

#if defined(TEKSTORM_DEBUG)
	#include "core/Debug.h"
	using Tekstorm::Core::Debug;
#endif

#endif /* _TEKSTORM_TEKCONFIG_H */