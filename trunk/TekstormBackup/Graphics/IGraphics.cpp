#define TEKBUILD
#include "IGraphics.h"

namespace Tekstorm
{
	namespace Graphics
	{
		LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
		{
			return ::DefWindowProc(hWnd, msg, wParam, lParam);
		}

		// initializes a new instance of IGraphics
		IGraphics::IGraphics(Tekstorm::Core::IDevice *pDev, const Tekstorm::Core::DisplayMode &dispMode, 
			const char *szCaption, bool windowed, bool vsync, unsigned int multiSampleType, ::WNDPROC msgHandler) 
		{
			// make sure we have a valid device
			if (! pDev) {
				TEKTHROW(E_INVALIDARG);
				return;
			}

			// set window caption
			if (szCaption) strcpy_s(windowCaption, 64, szCaption);
			else strcpy_s(windowCaption, 64, "Tekstorm Game");

			// copy display mode
			displayMode = dispMode;
			isWindowed = windowed;
			isVsync = vsync;
			multiSampleAmount = multiSampleType;

			// message handler
			if (! msgHandler)
				msgHandler = WndProc; // our default message handler
		
			// fill our wndclass
			wndClass.cbSize = sizeof(WNDCLASSEXA);
			wndClass.style = 0;
			wndClass.lpfnWndProc = msgHandler;
			wndClass.cbClsExtra = sizeof(void *);
			wndClass.cbWndExtra = sizeof(void *);
			wndClass.hInstance = GetModuleHandleA(NULL);
			wndClass.hIcon = LoadIconA(NULL, IDI_APPLICATION);
			wndClass.hCursor = LoadCursorA(NULL, IDC_ARROW);
			wndClass.hbrBackground = (HBRUSH)(COLOR_WINDOWTEXT + 1);
			wndClass.lpszClassName = "TekstormGameWindow123";
			wndClass.hIconSm = LoadIconA(NULL, IDI_APPLICATION);
			wndClass.lpszMenuName = NULL;

			// attempt to register the class
			if (! RegisterClassExA(&wndClass)) {
				TEKTHROW((HRESULT)GetLastError());
				return;
			}

			// now we can create our window
			hWnd = CreateWindowExA(WS_EX_CLIENTEDGE,
				"TekstormGameWindow123",
				windowCaption,
				(windowed) ? (WS_BORDER | WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX) : WS_POPUP,
				CW_USEDEFAULT, CW_USEDEFAULT,
				displayMode.Width, displayMode.Height,
				HWND_DESKTOP,
				(HMENU)NULL,
				wndClass.hInstance,
				NULL);

			if (! hWnd) {
				UnregisterClassA("TekstormGameWindow123", wndClass.hInstance);
				TEKTHROW((HRESULT)GetLastError());
				return;
			}

			// create our device
			D3DPRESENT_PARAMETERS pp;
			::ZeroMemory(&pp, sizeof(D3DPRESENT_PARAMETERS));
			if (windowed) {
				pp.Windowed = windowed;
			} else {
				pp.BackBufferWidth = displayMode.Width;
				pp.BackBufferHeight = displayMode.Height;
			}
			pp.BackBufferFormat = (D3DFORMAT)displayMode.Format;
			pp.BackBufferCount = 1;
			pp.MultiSampleType = (D3DMULTISAMPLE_TYPE)multiSampleType;
			pp.MultiSampleQuality = 0;
			pp.SwapEffect = D3DSWAPEFFECT_DISCARD;
			pp.hDeviceWindow = hWnd;
			pp.EnableAutoDepthStencil = FALSE;
			pp.Flags = 0;
			pp.FullScreen_RefreshRateInHz = (windowed ? 0 : displayMode.Hz);
			pp.PresentationInterval = (vsync ? D3DPRESENT_INTERVAL_DEFAULT : D3DPRESENT_INTERVAL_IMMEDIATE);

			pD3D = (IDirect3D9 *)pDev->GetHandle();
			D3DCAPS9 caps;
			pD3D->GetDeviceCaps(D3DADAPTER_DEFAULT,
				D3DDEVTYPE_HAL, &caps);

			DWORD devCaps = caps.DevCaps;
			bool hwtl = false;
			if (devCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
				hwtl = true;

			HRESULT hr;

			// attempt to create a full hardware device
			if (FAILED(pD3D->CreateDevice(D3DADAPTER_DEFAULT,
				D3DDEVTYPE_HAL, hWnd, (hwtl ? D3DCREATE_HARDWARE_VERTEXPROCESSING : D3DCREATE_MIXED_VERTEXPROCESSING), &pp, 
					(IDirect3DDevice9 **)&pGraph))) {
						// try a mixed device
						if (FAILED(pD3D->CreateDevice(D3DADAPTER_DEFAULT,
							D3DDEVTYPE_HAL, hWnd, (hwtl ? D3DCREATE_MIXED_VERTEXPROCESSING : D3DCREATE_SOFTWARE_VERTEXPROCESSING),
							&pp, (IDirect3DDevice9 **)&pGraph))) {
								// finally try a software device
								if (FAILED(hr = pD3D->CreateDevice(D3DADAPTER_DEFAULT,
									D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &pp, (IDirect3DDevice9 **)&pGraph))) {
										TEKTHROW(hr);
										UnregisterClassA("TekstormGameWindow123", wndClass.hInstance);
										DestroyWindow(hWnd);
										return;
								}
						}
			}

			// our device was successfully created..
			// now we can show our window
			ShowWindow(hWnd, SW_SHOW);
			UpdateWindow(hWnd);
			nRef++;
		}

		IGraphics::~IGraphics()
		{
			nRef--;
			if (nRef == 0)
				Dispose();
		}
		
		// Updates and pumps the message queue
		void IGraphics::Update()
		{
			MSG msg;
			if (PeekMessageA(&msg, hWnd, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}

		// Clears the backbuffer to the specified color
		HRESULT IGraphics::Clear(const Tekstorm::Math::Color4& color)
		{
			HRESULT hr;
			if (FAILED(hr = pGraph->Clear(0,
				(D3DRECT *)NULL,
				D3DCLEAR_TARGET,
				color.GetARGB(),
				1.0f,
				0))) {
					TEKTHROW(hr);
					return hr;
			}

			return S_OK;
		}

		// Begins a scene
		HRESULT IGraphics::Begin()
		{
			HRESULT hr;
			if (FAILED(hr = pGraph->BeginScene()))
			{
				TEKTHROW(hr);
				return hr;
			}

			return S_OK;
		}

		// Ends a scene
		HRESULT IGraphics::End()
		{
			HRESULT hr;
			if (FAILED(hr = pGraph->EndScene()))
			{
				TEKTHROW(hr);
				return hr;
			}

			return S_OK;
		}

		// Presents a scene, or a specific portion of the scene
		HRESULT IGraphics::Present()
		{
			HRESULT hr;
			if (FAILED(hr = pGraph->Present(NULL, NULL, NULL, NULL)))
			{
				TEKTHROW(hr);
				return hr;
			}

			return S_OK;
		}

		// Resets the device (destroys and reloads all ContentManagers).
		HRESULT IGraphics::Reset(const Tekstorm::Core::DisplayMode &dispMode,		// the width, height, format, and hz of the display
			bool windowed,				// whether or not we are fullscreen or windowed
			bool vsync,					// whether or not to use virtical synchronization
			unsigned int multiSampleType)
		{
			// -- HERE IS WHERE WE NEED TO RELEASE ALL OF OUR CONTENT MANAGERS --
			// -- HERE IS WHERE WE NEED TO RELEASE ALL OF OUR CONTENT MANAGERS --


			// copy display mode
			displayMode = dispMode;
			isWindowed = windowed;
			isVsync = vsync;
			multiSampleAmount = multiSampleType;


			// prepare to reset the device
			D3DPRESENT_PARAMETERS pp;
			::ZeroMemory(&pp, sizeof(D3DPRESENT_PARAMETERS));
			if (windowed) {
				pp.Windowed = windowed;
			} else {
				pp.BackBufferWidth = displayMode.Width;
				pp.BackBufferHeight = displayMode.Height;
			}
			pp.BackBufferFormat = (D3DFORMAT)displayMode.Format;
			pp.BackBufferCount = 1;
			pp.MultiSampleType = (D3DMULTISAMPLE_TYPE)multiSampleType;
			pp.MultiSampleQuality = 0;
			pp.SwapEffect = D3DSWAPEFFECT_DISCARD;
			pp.hDeviceWindow = hWnd;
			pp.EnableAutoDepthStencil = FALSE;
			pp.Flags = 0;
			pp.FullScreen_RefreshRateInHz = (windowed ? 0 : displayMode.Hz);
			pp.PresentationInterval = (vsync ? D3DPRESENT_INTERVAL_DEFAULT : D3DPRESENT_INTERVAL_IMMEDIATE);

			HRESULT hr;
			if (FAILED(hr = pGraph->Reset(&pp))) {
				TEKTHROW(hr);
				return hr;
			}

			// -- HERE IS WHERE WE NEED TO RELOAD ALL OF OUR CONTENT MANAGERS --

			return S_OK;
		}

		// Resets the device, leaving all parameters the same.
		HRESULT IGraphics::Reset()
		{
			return Reset(displayMode,
				isWindowed,
				isVsync,
				multiSampleAmount);
		}

		// Returns the underlying handle to the resource that is to be disposed.
		void *IGraphics::GetHandle()
		{
			return (void *)pGraph;
		}

		// Returns the current reference count of this object.
		unsigned int IGraphics::GetRefCount()
		{
			return nRef;
		}

		// Releases any resources that were used by this object.
		// If all goes as planned, S_OK is returned.
		HRESULT IGraphics::Dispose()
		{
			HRESULT hr = S_OK;
			if (pGraph)
			{
				IDirect3DDevice9 *dev = (IDirect3DDevice9 *)pGraph;
				hr = dev->Release();
			}

			UnregisterClassA("TekstormGameWindow123", wndClass.hInstance);
			DestroyWindow(hWnd);

			return hr;
		}
	}
}