/*
** This header provides configuration information for the entire
** Tekstorm2D Game Engine.
**
** All components should include and use this header.
**
** This header defines several macros:


** TEKSTORM_COMPILER_*			- denotes the compiler that is being used
**	- TEKSTORM_COMPILER_GPP		- g++
**	- TEKSTORM_COMPILER_BORLAND	- borland C++
**	- TEKSTORM_COMPILER_INTEL	- intel C++
**	- TEKSTORM_COMPILER_WATCOM	- watcom C++
**	- TEKSTORM_COMPILER_MINGW	- MinGW C++
**	- TEKSTORM_COMPILER_MSVC	- Microsoft Visual C++

** TEKSTORM_OS_*				- denotes the operating system that is being used
**	- TEKSTORM_OS_NIX32			- 32-bit unix/linux
**	- TEKSTORM_OS_NIX64			- 64-bit unix/linux
**	- TEKSTORM_OS_WIN32			- 32-bit windows
**	- TEKSTORM_OS_WIN64			- 64-bit windows

** TEKSTORM_MATH_*
**	- TEKSTORM_MATH_ACCURATE	- use 64-bit floating-point numbers for calculations (slower)
*/
#pragma once
#ifndef _TEKCONFIG_H
#define _TEKCONFIG_H
#include <cmath>
#include <cstdio>
#include <cstdlib>

#if defined(TEKSTORM_MATH_ACCURATE)
	typedef double tekreal;
#else
	typedef float tekreal;
#endif

#define TEKAPI

#endif /* _TEKCONFIG_H */