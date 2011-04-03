#pragma once
#ifndef _TEKSTORM_MOUSESTATE_H
#define _TEKSTORM_MOUSESTATE_H
#include "../BuildConf.h"
#include "../Graphics/ScreenPoint.h"

namespace Tekstorm
{
	namespace IO
	{
		/*
		** This class stores information about the current state of the mouse.
		*/
		class MouseState
		{
		public:
			/*
			** The total cumulative value of the mouse scroll wheel.
			*/
			static int ScrollWheelValue;

			/*
			** The current location of the mouse
			*/
			const Tekstorm::Graphics::ScreenPoint Location;

			/*
			** The Z-value of the mouse (i.e. the scroll wheel).
			*/
			const int Z;

			/*
			** Whether or not the left mouse button is currently down.
			*/
			const bool LButton;

			/*
			** Whether or not the right mouse button is currently down.
			*/
			const bool RButton;

			/*
			** Whether or not the middle mouse button is currently down.
			*/
			const bool MButton;

			/*
			** The delta scroll wheel value -- this is only set when coming from
			** a OnMouseScroll event.
			*/
			const int ScrollWheelDelta;

			/*
			** Initializes a new instance of MouseState.
			** Parameters
			**	none
			** Returns
			**	nothing
			*/
			MouseState() : Location(0), Z(0), LButton(false), RButton(false), MButton(false), ScrollWheelDelta(0)
			{
			}

			/*
			** Initializes a new instance of MouseState.
			** Parameters
			**	location		- the location of the mouse
			**	z				- the z value of the mouse
			**	lbutton			- the lbutton value
			**	rbutton			- the rbutton value
			**	mbutton			- the mbutton value
			**	delta			- the relative scroll wheel value
			** Returns
			**	nothing
			*/
			MouseState(const Tekstorm::Graphics::ScreenPoint &location,
				int z, bool lbutton, bool rbutton, bool mbutton, int delta) : Location(location), Z(z), LButton(lbutton), 
																	RButton(rbutton), MButton(mbutton), ScrollWheelDelta(delta)
			{
			}

			/*
			** Gets the current mouse state.
			** Parameters
			**	none
			** Returns
			**	the current mouse state.
			*/
			static TEKAPI MouseState GetState();
		};
	}
}

#endif /* _TEKSTORM_MOUSESTATE_H */