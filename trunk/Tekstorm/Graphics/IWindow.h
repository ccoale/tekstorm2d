#pragma once
#ifndef _TEKSTORM_IWINDOW_H
#define _TEKSTORM_IWINDOW_H
#include "GraphicsConf.h"
#include "ScreenPoint.h"
#include "ScreenSize.h"
#include "../IO/MouseState.h"

namespace Tekstorm
{
	namespace Graphics
	{
		using Tekstorm::IO::MouseState;

		// forward declaration
		class IGraphics;

		class IWindow
		{
		public:
			/*
			** Initializes a new instance of IWindow.
			** Parameters
			**	none
			** Returns
			**	nothing
			*/
			IWindow() { }

			/*
			** Destroys this instance of IWindow.
			** Parameters
			**	none
			** Returns
			**	nothing
			*/
			virtual ~IWindow() { }

			/*
			** Returns a handle to the underlying window resource.
			** Parameters
			**	none
			** Returns
			**	the handle to the window.
			*/
			virtual void *GetWindowHandle() = 0;

			/* ALL CODE BELOW THIS POINT IS SOLELY EVENT FUNCTIONALITY */

			/*
			** This method is called after the Window itself
			** has been created. In release mode, this method is called
			** only after the Window becomes visible (i.e. ShowWindow). In
			** debug mode, the Window becomes visible before this method is called.
			** Parameters
			**	none
			** Returns
			**	nothing
			*/
			virtual void OnCreate() { }

			/*
			** This method is called when the window itself is finally destroyed.
			** This occurrs -AFTER- the Graphics device is destroyed, and is therefore
			** unusable in this method.
			** Parameters
			**	none
			** Returns
			**	nothing
			*/
			virtual void OnDestroy() { }

			/*
			** This method is called when the window itself is resized.
			** If resizing is allowed (or is a switch from full-screen to windowed mode, or vice-versa)
			** then this method is called -AFTER- the Window has been resized
			** and all resources have been restored.
			** Parameters
			**	newSize		- the new size of the Window.
			** Returns
			**	nothing
			*/
			virtual void OnSize(const ScreenSize &newSize) { }

			/*
			** This method is called when the window is moved.
			** Parameters
			**	newLocation		- the new location of the top-left of the Window.
			** Returns
			**	nothing
			*/
			virtual void OnMove(const ScreenPoint &newLocation) { }

			/*
			** This method is called when the user requests to close the window. (i.e. clicked the 'X')
			** Parameters
			**	none
			** Returns
			**	this function returns whether or not the window was closed and the engine should end.
			**	if this function returns true, then the engine will be shutdown.
			**  if this function returns false, the request will be gracefully ignored.
			*/
			virtual bool OnClose() { }

			/*
			** This method is called when the user presses a key. This method is called before the key is released.
			** Parameters
			**	repeat			- the repeat count of the key
			**	key				- the virtual keycode of the key that was pressed
			** Returns
			**	nothing
			*/
			virtual void OnKeyDown(int repeat, int key) { }

			/*
			** This method is called when the user releases a key. This method is called after the key is released.
			** Parameters
			**	key			- the virtual keycode of the key that was released
			** Returns
			**	nothing
			*/
			virtual void OnKeyUp(int key) { }

			/*
			** This method is called when the user moves the mouse over this window. This method is called
			** during the moving of the mouse; therefore, it may be called multiple times.
			** Parameters
			**	state		- the state of the mouse
			** Returns
			**	nothing
			*/
			virtual void OnMouseMove(const MouseState &state) { }

			/* 
			** This method is called when the user holds down the left mouse button. It does take into
			** account the logical mouse buttons.
			** Parameters
			**	state		- the state of the mouse
			** Returns
			**	nothing
			*/
			virtual void OnLButtonDown(const MouseState &state) { }

			/*
			** This method isc alled when the user releases the left mouse button. It does take into
			** account the logical mouse button.
			** Parameters
			**	state		- the state of the mouse
			** Returns
			**	nothing
			*/
			virtual void OnLButtonUp(const MouseState &state) { }

			/*
			** This method is called when the user double clicks with the mouse.
			** Parameters
			**	state		- the mouse state
			** Returns
			**	nothing
			*/
			virtual void OnLButtonDoubleClick(const MouseState &state) { }

			/*
			** This method is called when the user holds down the right mouse button.
			** Parameters
			**	state		- the mouse state
			** Returns
			**	nothing
			*/
			virtual void OnRButtonDown(const MouseState &state) { }

			/*
			** This method is called when the user double clicks the right mouse button.
			** Parameters
			**	state		- the mouse state
			** Returns
			**	nothing
			*/
			virtual void OnRButtonDoubleClick(const MouseState &state) { }

			/*
			** This method is called when the user releases the right mouse button.
			** Parameters
			**	state		- the mouse state
			** Returns
			**	nothing
			*/
			virtual void OnRButtonUp(const MouseState &state) { }

			/*
			** This method is called when the user holds down the middle mouse button (scroll wheel).
			** Parameters
			**	state		- the mouse state
			** Returns
			**	nothing
			*/
			virtual void OnMButtonDown(const MouseState &state) { }

			/*
			** This method is called when the user releases the midle mouse button.
			** Parameters
			**	state		- the mouse state
			** Returns
			**	nothing
			*/
			virtual void OnMButtonUp(const MouseState &state) { }

			/*
			** This method is called when the user doubles clicks with the middle mouse button.
			** Parameters
			**	state		- the mouse state
			** Returns
			**	nothing
			*/
			virtual void OnMButtonDoubleClick(const MouseState &state) { }

			/*
			** This method is called when the mouse wheel is scrolled.
			** Parameters
			**	state		- the mouse state
			** Returns
			**	nothing
			*/
			virtual void OnMouseScroll(const MouseState &state) { }

			/*
			** This method is called when the mouse cursor hovers over this Window for a period of time.
			** Parameters
			**	state		- the mouse state
			** Returns
			**	nothing
			*/
			virtual void OnMouseHover(const MouseState &state) { }

			/*
			** This method is called when the mouse cursor enters the Window.
			** Parameters
			**	state		- the mouse state
			** Returns
			**	nothing
			*/
			virtual void OnMouseEnter(const MouseState &state) { }

			/*
			** This method is called when the mouse leaves the Window.
			** Parameters
			**	state		- the mouse state
			** Returns
			**	nothing
			*/
			virtual void OnMouseLeave(const MouseState &state) { }

			/*
			** This method is called -immediately- after device creation
			** and -should- be overloaded to store the incoming IGraphics pointer.
			** Parameters
			**	graphics		- the IGraphics pointer to the newly created device
			** Returns
			**	nothing
			*/
			virtual void OnGraphicsCreated(IGraphics *graphics) { }
		};
	}
}

#endif /* _TEKSTORM_IWINDOW_H */