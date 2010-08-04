#ifndef _TEKSTORM_GRAPHICS_H
#define _TEKSTORM_GRAPHICS_H
#include "../TekstormDecl.h"
#include "Device.h"
#include "../Core/Exception.h"
#include "../Math/Color4.h"

namespace Tekstorm
{
	namespace Graphics
	{
		class TEKDECL Device;
		class TEKDECL Graphics
		{
		private:
			// The device that created this Graphics object.
			Device *device;

			// The window handle for which the Graphics object was created for
			HWND hWnd;

			// Last window message
			MSG msg;

			// The size of the window/screen
			uint_t screenWidth, screenHeight;

			// Whether or not it is fullscreen
			bool isFullscreen;

			// The graphics device.
			void *graph;

			// The vertex declaration.
			void *vertexDecl;

			// Creates this device given the parameters that were received from the constructor.
			bool Create();

			// Releases all resources
			void Release();
		public:
			// Creates a new instance of this Graphics object
			Graphics(Device* dev, const char *caption, uint_t width, uint_t height, bool fullscreen);

			// Creates a new instance of this Graphics object
			Graphics(HWND hWnd, Device *dev, const char *caption, uint_t width, uint_t height, bool fullscreen);

			// Destroys this instance of the Graphics object
			~Graphics();

			// Checks for a new message and passes it to the message proc
			void PumpMessages();

			// Returns the underlying d3d handle
			void* GetHandle();

			// Begins a scene
			void BeginScene();

			// Ends a scene
			void EndScene();

			// Presents a scene
			void Present();

			// Clears a scene
			void Clear(const Tekstorm::Math::Color4& color);

		};
	}
}

#endif /* _TEKSTORM_GRAPHICS_H */