#pragma once
#ifndef _TEKSTORM_ScreenSize_H
#define _TEKSTORM_ScreenSize_H
#include "GraphicsConf.h"

namespace Tekstorm
{
	namespace Graphics
	{
		/*
		**	This class is used to hold a screen size.
		*/
		class ScreenSize
		{
		public:
			/*
			** The width.
			*/
			int Width;

			/*
			** The height.
			*/
			int Height;

			/*
			** Initializes a new instance of ScreenSize.
			** Parameters
			**	none
			** Returns
			**	nothing
			*/
			ScreenSize() : Width(0), Height(0) { }

			/*
			** Initializes a new instance of ScreenSize.
			** Parameters
			**	value		- a value to set both Width and Height to.
			** Returns
			**	nothing
			*/
			ScreenSize(int value) : Width(value), Height(value) { }

			/*
			** Initializes a new instance of ScreenSize.
			** Parameters
			**	width		- the Width value
			**	height		- the Height value
			** Returns
			**	nothing
			*/
			ScreenSize(int width, int height) : Width(width), Height(height) { }

			/*
			** Initializes a new instance of ScreenSize.
			** Parameters
			**	obj		- a separate ScreenSize object to take the values from.
			** Returns
			**	nothing
			*/
			ScreenSize(const ScreenSize &obj) : Width(obj.Width), Height(obj.Height) { }

			/*
			** Allows assignment of this class.
			*/
			ScreenSize &operator=(const ScreenSize &obj)
			{
				Width = obj.Width;
				Height = obj.Height;

				return *this;
			}

			/*
			** Adds two ScreenSizes together.
			*/
			ScreenSize operator+(const ScreenSize &right)
			{
				return ScreenSize(Width + right.Width, Height + right.Height);
			}

			/*
			** Adds a ScreenSize to this ScreenSize.
			*/
			ScreenSize& operator+=(const ScreenSize &right)
			{
				Width += right.Width;
				Height += right.Height;

				return *this;
			}

			/*
			** Subtracts a ScreenSize from this ScreenSize.
			*/
			ScreenSize operator-(const ScreenSize &right)
			{
				return ScreenSize(Width - right.Width, Height - right.Height);
			}

			/*
			** Subtracts a ScreenSize from this ScreenSize.
			*/
			ScreenSize &operator-=(const ScreenSize &right)
			{
				Width -= right.Width;
				Height -= right.Height;

				return *this;
			}

			/*
			** Tests for equality
			*/
			bool operator==(const ScreenSize &right)
			{
				return (Width == right.Width && Height == right.Height);
			}

			/*
			** Tests for inequality
			*/
			bool operator!=(const ScreenSize &right)
			{
				return (Width != right.Width || Height != right.Height);
			}
		};
	}
}

#endif /* _TEKSTORM_ScreenSize_H */