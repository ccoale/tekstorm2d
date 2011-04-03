/*
**	This header defines various constants, macros,
** data-types, and data-structures used throughout
** the Tekstorm game engine.
**
**	WARNING: this header should only be changed on re-builds. It
** should not be changed by the user of the library unless they
** are re-compiling the source.
**
**
**		DO NOT CHANGE ANYTHING BELOW THIS POINT
** -----------------------------------------------------
*/
#pragma once
#ifndef _TEK_BUILD_CONF_H
#define _TEK_BUILD_CONF_H

/*
**	This conditional block declares the import/export modifiers.
** TEKSTORM_BUILD should only be defined if the engine is being
** built from source. If the DLL is being used, it should NOT
** be defined.
*/
#if defined(TEKSTORM_BUILD)
#define TEKAPI __declspec(dllexport)
#else
#define TEKAPI
#endif

#if defined(_DEBUG)
#define TEKSTORM_DEBUG 1
#else
#define TEKSTORM_DEBUG 0
#endif

/*
**	The root Tekstorm namespace. All data-types and data-structures
** related to the game engine exist in the Tekstorm namespace. However, 
** due to the nature of macros, macro constants will be declared in the global
** namespace.
*/
namespace Tekstorm
{
	/*
	**	Declares the 'real' data-type based on speed vs. precision
	** preference. If you favor speed over precision, then TEKSTORM_FAST_MATH
	** should be defined. Otherwise, precision is favored.

	**	A floating-point decimal type that is either 32 or 64 bits in length.
	** The size changes based on the defined constant TEKSTORM_FAST_MATH.
	** If TEKSTORM_FAST_MATH is defined, then it will be defined as a float.
	** If TEKSTORM_FAST_MATH is NOT defined, then it will be defined as a double.
	*/
#if defined(TEKSTORM_FAST_MATH)
	typedef float real;
#define TEKSTORM_REAL_EPSILON ((real)1.0e-6)
#else
	typedef double real;
#define TEKSTORM_REAL_EPSILON ((real)4.94065645841247e-324)
#endif
}

#endif /* _TEK_BUILD_CONF_H */