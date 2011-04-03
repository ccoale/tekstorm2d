#define TEKSTORM_BUILD
#include "GraphicsConf.h"
#include <WinUser.h>
#include "IWindow.h"

namespace Tekstorm
{
	namespace Graphics
	{
		/*
		** This is a proxy function for handling ALL window event procedures.
		** It automatically redirects to the appropriate events within the IWindow class.
		*/
		LRESULT CALLBACK WndProcProxy(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
		{
			/* temporary objects */
			ScreenPoint point;
			ScreenSize size;

			POINT pt;
			RECT rct;
			int val;
			int vk;

			/* get the IWindow associated with this message */
			IWindow *pWindow = (IWindow *)GetWindowLongA(hWnd, GWL_USERDATA);
			if (! pWindow)
				return DefWindowProc(hWnd, message, wParam, lParam);

			switch(message)
			{
			//case WM_CREATE: pWindow->OnCreate(); break; // this will be called by the engine
			case WM_DESTROY: pWindow->OnDestroy(); break;
			case WM_SIZE:
				size.Width = (int)LOWORD(lParam);
				size.Height = (int)HIWORD(lParam);
				pWindow->OnSize(size);
				break;

			case WM_MOVE:
				point.X = (int)LOWORD(lParam);
				point.Y = (int)HIWORD(lParam);
				pWindow->OnMove(point);
				break;

			// case WM_CLOSE: pWindow->OnClose(); break; // this will be called by the engine
			case WM_KEYDOWN:
				vk = (int)wParam;
				val = (int)LOWORD(lParam); // repeat count
				pWindow->OnKeyDown(val, vk);
				break;

			case WM_KEYUP:
				vk = (int)wParam;
				pWindow->OnKeyUp(vk);
				break;

			case WM_MOUSEMOVE:
				point.X = (int)LOWORD(lParam);
				point.Y = (int)HIWORD(lParam);
				pWindow->OnMouseMove(MouseState(point, 0, (wParam & MK_LBUTTON) == MK_LBUTTON,
					(wParam & MK_RBUTTON) == MK_RBUTTON,
					(wParam & MK_MBUTTON) == MK_MBUTTON,
					0));
				break;

			case WM_LBUTTONDOWN:
				point.X = (int)LOWORD(lParam);
				point.Y = (int)HIWORD(lParam);
				pWindow->OnLButtonDown(MouseState(point, 0, (wParam & MK_LBUTTON) == MK_LBUTTON,
					(wParam & MK_RBUTTON) == MK_RBUTTON,
					(wParam & MK_MBUTTON) == MK_MBUTTON,
					0));
				break;

			case WM_LBUTTONUP:
				point.X = (int)LOWORD(lParam);
				point.Y = (int)HIWORD(lParam);
				pWindow->OnLButtonUp(MouseState(point, 0, (wParam & MK_LBUTTON) == MK_LBUTTON,
					(wParam & MK_RBUTTON) == MK_RBUTTON,
					(wParam & MK_MBUTTON) == MK_MBUTTON,
					0));
				break;

			case WM_LBUTTONDBLCLK:
				point.X = (int)LOWORD(lParam);
				point.Y = (int)HIWORD(lParam);
				pWindow->OnLButtonDoubleClick(MouseState(point, 0, (wParam & MK_LBUTTON) == MK_LBUTTON,
					(wParam & MK_RBUTTON) == MK_RBUTTON,
					(wParam & MK_MBUTTON) == MK_MBUTTON,
					0));
				break;

			case WM_RBUTTONDOWN:
				point.X = (int)LOWORD(lParam);
				point.Y = (int)HIWORD(lParam);
				pWindow->OnRButtonDown(MouseState(point, 0, (wParam & MK_LBUTTON) == MK_LBUTTON,
					(wParam & MK_RBUTTON) == MK_RBUTTON,
					(wParam & MK_MBUTTON) == MK_MBUTTON,
					0));
				break;

			case WM_RBUTTONUP:
				point.X = (int)LOWORD(lParam);
				point.Y = (int)HIWORD(lParam);
				pWindow->OnRButtonUp(MouseState(point, 0, (wParam & MK_LBUTTON) == MK_LBUTTON,
					(wParam & MK_RBUTTON) == MK_RBUTTON,
					(wParam & MK_MBUTTON) == MK_MBUTTON,
					0));
				break;

			case WM_RBUTTONDBLCLK:
				point.X = (int)LOWORD(lParam);
				point.Y = (int)HIWORD(lParam);
				pWindow->OnRButtonDoubleClick(MouseState(point, 0, (wParam & MK_LBUTTON) == MK_LBUTTON,
					(wParam & MK_RBUTTON) == MK_RBUTTON,
					(wParam & MK_MBUTTON) == MK_MBUTTON,
					0));
				break;

			case WM_MBUTTONDOWN:
				point.X = (int)LOWORD(lParam);
				point.Y = (int)HIWORD(lParam);
				pWindow->OnMButtonDown(MouseState(point, 0, (wParam & MK_LBUTTON) == MK_LBUTTON,
					(wParam & MK_RBUTTON) == MK_RBUTTON,
					(wParam & MK_MBUTTON) == MK_MBUTTON,
					0));
				break;

			case WM_MBUTTONUP:
				point.X = (int)LOWORD(lParam);
				point.Y = (int)HIWORD(lParam);
				pWindow->OnMButtonUp(MouseState(point, 0, (wParam & MK_LBUTTON) == MK_LBUTTON,
					(wParam & MK_RBUTTON) == MK_RBUTTON,
					(wParam & MK_MBUTTON) == MK_MBUTTON,
					0));
				break;

			case WM_MBUTTONDBLCLK:
				point.X = (int)LOWORD(lParam);
				point.Y = (int)HIWORD(lParam);
				pWindow->OnMButtonDoubleClick(MouseState(point, 0, (wParam & MK_LBUTTON) == MK_LBUTTON,
					(wParam & MK_RBUTTON) == MK_RBUTTON,
					(wParam & MK_MBUTTON) == MK_MBUTTON,
					0));
				break;

			case WM_MOUSEWHEEL:
				point.X = (int)LOWORD(lParam);
				point.Y = (int)HIWORD(lParam);
				val = HIWORD(wParam) * 120;
				MouseState::ScrollWheelValue += val;
				pWindow->OnMouseScroll(MouseState(point, 0, (wParam & MK_LBUTTON) == MK_LBUTTON,
					(wParam & MK_RBUTTON) == MK_RBUTTON,
					(wParam & MK_MBUTTON) == MK_MBUTTON,
					val));
				break;
			};

			return 0;
		}
	}
}