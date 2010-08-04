#define __BUILD
#include "Graphics.h"

namespace Tekstorm
{
	namespace Graphics
	{
		// our window handler
		LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
		{
			return DefWindowProc(hWnd, msg, wParam, lParam);
		}

		// Creates this device given the parameters that were received from the constructor.
		bool Graphics::Create()
		{
			IDirect3D9 *pDev = (IDirect3D9 *)device->GetHandle();
			IDirect3DDevice9 *pGraph;
			D3DPRESENT_PARAMETERS pp;
			ZeroMemory(&pp, sizeof(D3DPRESENT_PARAMETERS));
			pp.BackBufferCount				= 1;
			pp.MultiSampleType				= D3DMULTISAMPLE_NONE;
			pp.MultiSampleQuality			= 0;
			pp.SwapEffect					= D3DSWAPEFFECT_DISCARD;
			pp.hDeviceWindow				= hWnd;
			pp.Flags						= 0;
			pp.FullScreen_RefreshRateInHz	= D3DPRESENT_RATE_DEFAULT;
			pp.PresentationInterval			= D3DPRESENT_INTERVAL_IMMEDIATE;
			pp.BackBufferFormat				= D3DFMT_X8R8G8B8;
			pp.EnableAutoDepthStencil		= FALSE; //No depth/stencil buffer
			pp.Windowed = !isFullscreen;
			if (! isFullscreen)
			{
				pp.BackBufferWidth = screenWidth;
				pp.BackBufferHeight = screenHeight;
			}

			HRESULT hr;

			// try to create a pure hardware device
			if (FAILED(pDev->CreateDevice(0, D3DDEVTYPE_HAL, hWnd,
				D3DCREATE_HARDWARE_VERTEXPROCESSING, &pp, &pGraph))) {
					// if it failed, try to create a hard/soft mix
					if (FAILED(pDev->CreateDevice(0, D3DDEVTYPE_HAL, hWnd,
						D3DCREATE_SOFTWARE_VERTEXPROCESSING, &pp, &pGraph))) {
							// if THAT failed, then our last resort is to try to make
							// a pure software device. If it fails, then fail completely.
							if (FAILED(hr = pDev->CreateDevice(0, D3DDEVTYPE_SW, hWnd,
								D3DCREATE_SOFTWARE_VERTEXPROCESSING, &pp, &pGraph))) {
									throw Tekstorm::Core::Exception(hr, "An error ocurred while creating the graphics object.");
									return false;
							}
					}
			}


			graph = pGraph;

			// setup our vertex declaration element array
			D3DVERTEXELEMENT9 elems[] = {
				{0, 0, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0},
				{0, 12, D3DDECLTYPE_FLOAT4, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_COLOR, 0},
				{0, 28, D3DDECLTYPE_FLOAT2, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 0},

				D3DDECL_END()
			};

			IDirect3DVertexDeclaration9 *pVertDecl = NULL;
			if (FAILED(hr = pGraph->CreateVertexDeclaration(elems, &pVertDecl))) {
				throw Tekstorm::Core::Exception(hr, "An error ocurred while creating the vertex declaration.");
				return false;
			}
			if (FAILED(hr = pGraph->SetVertexDeclaration(pVertDecl))) {
				throw Tekstorm::Core::Exception(hr, "An error ocurred while setting the vertex declaration.");
				return false;
			}

			return true;
		}

		void Graphics::Release()
		{
			if (vertexDecl) {
				IDirect3DVertexDeclaration9 *pVertDecl = (IDirect3DVertexDeclaration9 *)vertexDecl;
				pVertDecl->Release();
			}

			if (graph) {
				IDirect3DDevice9 *pGraph = (IDirect3DDevice9 *)graph;
				pGraph->Release();
			}
		}

		// Creates a new instance of this Graphics object
		Graphics::Graphics(Device* dev, const char *caption, uint_t width, uint_t height, bool fullscreen)
		{
			device = dev;
			screenWidth = width;
			screenHeight = height;
			isFullscreen = fullscreen;

			// create our window to obtain a handle
			WNDCLASSEXA wc;
			wc.cbSize = sizeof(WNDCLASSEXA);
			wc.cbClsExtra = 0;
			wc.cbWndExtra = 0;
			wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
			wc.hCursor = LoadCursor(NULL, IDC_ARROW);
			wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
			wc.hIconSm = wc.hIcon;
			wc.hInstance = GetModuleHandleA(NULL);
			wc.lpfnWndProc = MsgProc;
			wc.lpszClassName = "TekStrm2D";
			wc.lpszMenuName = NULL;
			wc.style = CS_CLASSDC;
			uint_t sty = WS_OVERLAPPED | WS_VISIBLE;
			if (! RegisterClassExA(&wc))
			{
				throw Tekstorm::Core::Exception("Error registering the Window Class.");
				return;
			}

			hWnd = CreateWindowExA(0, "TekStrm2D", caption,
				(fullscreen ? (sty | WS_POPUP) : (sty | WS_SYSMENU)), CW_USEDEFAULT, CW_USEDEFAULT,
				width, height, NULL, NULL, wc.hInstance, NULL);
			if (! hWnd) {
				throw Tekstorm::Core::Exception("Error creating the game window.");
				return;
			}

			ShowWindow(hWnd, SW_SHOW);
			UpdateWindow(hWnd);

			try {
				if (! Create())
				{
					Release();
				}
			} catch (Tekstorm::Core::Exception ex) {
				throw ex; // re-throw the exception
			}
		}

		// Creates a new instance of this Graphics object
		Graphics::Graphics(HWND hwnd, Device *dev, const char *caption, uint_t width, uint_t height, bool fullscreen)
		{
		}

		// Destroys this instance of the Graphics object
		Graphics::~Graphics()
		{
			Release();
		}

		// Checks for a new message and passes it to the message proc
		void Graphics::PumpMessages()
		{
			if (PeekMessageA(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}

		// Returns the underlying d3d handle
		void* Graphics::GetHandle()
		{
			return graph;
		}

		// Begins a scene
		void Graphics::BeginScene()
		{
			IDirect3DDevice9* pDev = (IDirect3DDevice9 *)graph;
			pDev->BeginScene();
		}

		// Ends a scene
		void Graphics::EndScene()
		{
			IDirect3DDevice9* pDev = (IDirect3DDevice9 *)graph;
			pDev->EndScene();
		}

		// Presents a scene
		void Graphics::Present()
		{
			IDirect3DDevice9* pDev = (IDirect3DDevice9 *)graph;
			pDev->Present(NULL, NULL, NULL, NULL); // present the whole scene
		}

		// Clears a scene
		void Graphics::Clear(const Tekstorm::Math::Color4& color)
		{
			IDirect3DDevice9* pDev = (IDirect3DDevice9 *)graph;
			pDev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB((int)(color.R*255), (int)(color.G*255), (int)(color.B*255)), 1.0f, 0);
		}
	}
}