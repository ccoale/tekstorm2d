#define TEKSTORM_BUILD
#include "MouseState.h"
#include <Windows.h>

namespace Tekstorm
{
	namespace IO
	{
		/*
		** The total cumulative value of the mouse scroll wheel.
		*/
		int MouseState::ScrollWheelValue = 0;
		
		/*
		** Gets the current mouse state.
		** Parameters
		**	none
		** Returns
		**	the current mouse state.
		*/
		TEKAPI MouseState MouseState::GetState()
		{
			POINT pos;

			GetCursorPos(&pos);
			bool lbutton = false;
			bool mbutton = false;
			bool rbutton = false;
			bool temp = lbutton;

			lbutton = GetAsyncKeyState(VK_LBUTTON) & 0x8000;
			rbutton = GetAsyncKeyState(VK_RBUTTON) & 0x8000;
			mbutton = GetAsyncKeyState(VK_MBUTTON) & 0x8000;
			if (GetSystemMetrics(SM_SWAPBUTTON)) {
				lbutton = rbutton;
				rbutton = temp;
			}

			return MouseState(Tekstorm::Graphics::ScreenPoint(pos.x, pos.y),
				MouseState::ScrollWheelValue, lbutton, rbutton, mbutton, 0);
		}
	}
}