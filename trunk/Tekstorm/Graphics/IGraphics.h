#ifndef _TEKSTORM_IGRAPHICS_H
#define _TEKSTORM_IGRAPHICS_H
#include "../Core/TekDecl.h"
#include "../Core/IDisposable.h"
#include "../Core/DisplayMode.h"
#include "../Core/IDevice.h"
#include "../Math/Color4.h"

namespace Tekstorm
{
	namespace Core { class TEKAPI IDevice; }
	namespace Graphics
	{
		class TEKAPI IGraphics : public Core::IDisposable
		{
		private:
			// The Direct3D Graphics Device handle
			TEKHANDLE(IDirect3DDevice9, pGraph);

			// The IDevice parent of this graphics interface
			Core::IDevice *pDevice;

			// The handle to the created window
			HWND hWnd;

			// The window class information
			WNDCLASSEXA wndClass;

			char windowCaption[64];
			Core::DisplayMode displayMode;
			bool isWindowed;
			bool isVsync;
			unsigned int multiSampleAmount;
			unsigned int nRef;

			TEKHANDLE(IDirect3D9, pD3D);
		public:
			// initializes a new instance of IGraphics
			IGraphics(Tekstorm::Core::IDevice *pDev,
				const Tekstorm::Core::DisplayMode &dispMode,		// the width, height, format, and hz of the display
				const char *szCaption = "My Game",	// the caption of the window
				bool windowed = true,				// whether or not we are fullscreen or windowed
				bool vsync = true,					// whether or not to use virtical synchronization
				unsigned int multiSampleType = 0,	// amount of multisampling to use
				::WNDPROC msgHandler = NULL);			// user-defined (optional) message handler

			// Destroys this instance of IGraphics
			~IGraphics();

			// Updates and pumps the message queue
			void Update();

			// Clears the backbuffer to the specified color
			HRESULT Clear(const Tekstorm::Math::Color4& color);

			// Begins a scene
			HRESULT Begin();

			// Ends a scene
			HRESULT End();

			// Presents a scene, or a specific portion of the scene
			HRESULT Present();

			// Resets the device (destroys and reloads all ContentManagers).
			HRESULT Reset(const Tekstorm::Core::DisplayMode &dispMode,		// the width, height, format, and hz of the display
				bool windowed = true,				// whether or not we are fullscreen or windowed
				bool vsync = true,					// whether or not to use virtical synchronization
				unsigned int multiSampleType = 0	// amount of multisampling to use
				);

			// Resets the device, leaving all parameters the same.
			HRESULT Reset();

			// Returns the current reference count of this object.
			virtual unsigned int GetRefCount();

			// Returns the underlying handle to the resource that is to be disposed.
			virtual void *GetHandle();

			// Releases any resources that were used by this object.
			// If all goes as planned, S_OK is returned.
			virtual HRESULT Dispose();
		};
	}
}

#endif /* _TEKSTORM_IGRAPHICS_H */