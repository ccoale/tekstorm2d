#ifndef _TEKSTORMDECL_H
#define _TEKSTORMDECL_H
#include <windows.h>
#include <cstring>
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <list>
#include <stack>
#include <math.h>

/* define our basic data-types that will be used throughout the engine */
typedef unsigned char ubyte_t;
typedef signed char byte_t;
typedef unsigned short ushort_t;
typedef signed short short_t;
typedef unsigned int uint_t;
typedef signed int int_t;
typedef unsigned __int64 ulong_t;
typedef signed __int64 long_t;

/* typedef for real number */
typedef float real;

/* declare import/export settings */
#ifdef __BUILD
#define TEKDECL	__declspec(dllexport)
#include <d3d9.h>
#include <d3dx9.h>
#include <dxerr.h>
#else
#define TEKDECL __declspec(dllimport)
#endif

#endif /* _TEKSTORMDECL_H */