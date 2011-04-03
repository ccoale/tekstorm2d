/*
**	This header file defines common routines that will be used throughout the engine (such as optimized math functions and various
** helper functions).
*/
#pragma once
#ifndef _TEKSTORM_COMMONUTILS_H
#define _TEKSTORM_COMMONUTILS_H
#include "BuildConf.h"
#include <iostream> // bleh!
#include <cmath> // bleh
#include <stack>

namespace Tekstorm
{
	class TEKAPI CommonUtils
	{
	public:
		static std::stack<int> IdList;
		
		static inline void InitIdList(int max)
		{
			for (int i = 0; i < max; i++)
				IdList.push(i);
		}

		static inline int GetId() 
		{
			if (IdList.empty())
				return -1;

			int id = IdList.top();
			IdList.pop();

			return id;
		}

		static inline void RestoreId(int id)
		{
			IdList.push(id);
		}

		/* 
		** Returns the absolute value of a single-precision floating-point value
		** Parameters
		**	val			- the value to take the absolute value of
		** Returns
		**	the absolute value
		*/
		static inline float Abs(float val)
		{
			int *data = (int *)&val;
			float *res = (float *)data;
			
			*data &= 0x7FFFFFFF;

			return *res;
		}

		/*
		** Returns the absolute value of the double-precision floating-point value
		** Parameters
		**	val			- the value to take the absolute value of
		** Returns
		**	the absolute value
		*/
		static inline double Abs(double val)
		{
			long long *data = (long long *)&val;
			double *res = (double *)data;

			*data &= 0x7FFFFFFFFFFFFFFF;

			return *res;
		}
	};
}

#endif /* _TEKSTORM_COMMONUTILS_H */