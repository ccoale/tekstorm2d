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
** TEKSTORM_OS_NIX32			- 32-bit unix/linux
** TEKSTORM_OS_NIX64			- 64-bit unix/linux
** TEKSTORM_OS_WIN32			- 32-bit windows
** TEKSTORM_OS_WIN64			- 64-bit windows
*/
#pragma once
#ifndef _TEKCONFIG_H
#define _TEKCONFIG_H


#if defined(__GNUC__) && defined(__cplusplus)
#define TEKSTORM_COMPILER_GPP
#	if defined(__linux__)
#		if defined(__LP64__)
#			define TEKSTORM_OS_NIX64
#		else
#			define TEKSTORM_OS_NIX32
#		endif
#	endif
#elif defined(__BORLANDC__)
#define TEKSTORM_COMPILER_BORLAND
#elif defined(__INTEL_COMPILER)
#define TEKSTORM_COMPILER_INTEL
#elif defined(__MINGW32__)
#define TEKSTORM_COMPILER_MINGW
#elif defined(_MSC_VER)
#define TEKSTORM_COMPILER_MSVC
#endif

#endif /* _TEKCONFIG_H */