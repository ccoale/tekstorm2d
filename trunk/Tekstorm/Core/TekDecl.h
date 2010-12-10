/*
**	This header provides constants and common includes
** that are used throughout this source.
**
**	The TEKBUILD macro is set in a source file ONLY
** prior to including this header, or any other header.
** It allows the compiler to only include things such
** as D3D in the source, and not the header the user
** will be using.
**	Use the TEKBUILD_DLL macro if you are building for a DLL.
*/
#ifndef _TEKDECL_H
#define _TEKDECL_H
#undef UNICODE
#include <Windows.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>

// here we need to define TEKBUILD_DLL
//#define TEKBUILD_DLL


#if defined(TEKBUILD_DLL)
#define TEKAPI __declspec(dllimport)
#else
#define TEKAPI
#endif

#if defined(TEKBUILD)
#	define TEKHANDLE(c,n)	c *n
#	define GETTEKHANDLE(c)		( (c*) )
#	if defined(TEKBUILD_DLL)
#		define TEKAPI __declspec(dllexport)
#	else
#		define TEKAPI
#	endif
#	if defined(_DEBUG)
#		define D3D_DEBUG_INFO
#	endif
#	include <d3d9.h>
#	include <d3dx9.h>
#	include <dxerr.h>
#else
#	define TEKHANDLE(c,n)	void *n
#	define GETTEKHANDLE(c)		( (void *) )
// TEKHANDLE usage ...
/*
**	TEKHANDLE(IDirect3DTexture9, myTexture);
**	myTexture = TEKHANDLE(IDirect3DTExture9)pGraph->CreateTexture(....);
**
*/
#endif

#endif /* _TEKDECL_H */