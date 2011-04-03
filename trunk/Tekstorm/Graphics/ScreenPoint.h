#pragma once
#ifndef _TEKSTORM_SCREENPOINT_H
#define _TEKSTORM_SCREENPOINT_H
#include "GraphicsConf.h"

namespace Tekstorm
{
	namespace Graphics
	{
		/*
		**	This class is used to hold a screen point. That is,
		** an integral pair of values used to represent the x-coordinate
		** location and y-coordinate location.
		*/
		class ScreenPoint
		{
		public:
			/*
			** The x-coordinate location.
			*/
			int X;

			/*
			** The y-coordinate location.
			*/
			int Y;

			/*
			** Initializes a new instance of ScreenPoint.
			** Parameters
			**	none
			** Returns
			**	nothing
			*/
			ScreenPoint() : X(0), Y(0) { }

			/*
			** Initializes a new instance of ScreenPoint.
			** Parameters
			**	value		- a value to set both X and Y to.
			** Returns
			**	nothing
			*/
			ScreenPoint(int value) : X(value), Y(value) { }

			/*
			** Initializes a new instance of ScreenPoint.
			** Parameters
			**	x		- the x value
			**	y		- the y value
			** Returns
			**	nothing
			*/
			ScreenPoint(int x, int y) : X(x), Y(y) { }

			/*
			** Initializes a new instance of ScreenPoint.
			** Parameters
			**	obj		- a separate ScreenPoint object to take the values from.
			** Returns
			**	nothing
			*/
			ScreenPoint(const ScreenPoint &obj) : X(obj.X), Y(obj.Y) { }

			/*
			** Allows assignment of this class.
			*/
			ScreenPoint &operator=(const ScreenPoint &obj)
			{
				X = obj.X;
				Y = obj.Y;

				return *this;
			}

			/*
			** Adds two ScreenPoints together.
			*/
			ScreenPoint operator+(const ScreenPoint &right)
			{
				return ScreenPoint(X + right.X, Y + right.Y);
			}

			/*
			** Adds a ScreenPoint to this screen point.
			*/
			ScreenPoint& operator+=(const ScreenPoint &right)
			{
				X += right.X;
				Y += right.Y;

				return *this;
			}

			/*
			** Subtracts a ScreenPoint from this ScreenPoint.
			*/
			ScreenPoint operator-(const ScreenPoint &right)
			{
				return ScreenPoint(X - right.X, Y - right.Y);
			}

			/*
			** Subtracts a ScreenPoint from this ScreenPoint.
			*/
			ScreenPoint &operator-=(const ScreenPoint &right)
			{
				X -= right.X;
				Y -= right.Y;

				return *this;
			}

			/*
			** Tests for equality
			*/
			bool operator==(const ScreenPoint &right)
			{
				return (X == right.X && Y == right.Y);
			}

			/*
			** Tests for inequality
			*/
			bool operator!=(const ScreenPoint &right)
			{
				return (X != right.X || Y != right.Y);
			}
		};
	}
}

#endif /* _TEKSTORM_SCREENPOINT_H */