/*
**	Provides an interface for communicating with the rendering device (HAL).
*/
#ifndef _TEKSTORM_IDEVICE_H
#define _TEKSTORM_IDEVICE_H
#include "TekDecl.h"
#include "Exception.h"
#include "IDisposable.h"
#include "DisplayMode.h"
#include "../Graphics/IGraphics.h"

namespace Tekstorm
{
	namespace Graphics { class TEKAPI IGraphics; }
	namespace Core
	{
		// Singleton class which holds a link
		// to the Direct3D driver
		class TEKAPI IDevice : public IDisposable
		{
		private:
			// singleton instance
			static IDevice* pDev;

			// reference count to the singleton instance
			unsigned int nRef;

			// The Direct3D driver handle
			TEKHANDLE(IDirect3D9, pD3D);

			// The list of supported display modes
			DisplayMode *pModes;

			// The current display mode
			DisplayMode curDispMode;

			// The number of supported display modes
			unsigned int nDispModeCount;

			// whether or not fullscreen hardware acceleration is available
			// whether or not windowed hardware acceleration is available
			bool fullAccel, winAccel;

			struct DeviceInfo {
				char          Driver[512];
				char          Description[512];
				char          DeviceName[32];
				LARGE_INTEGER DriverVersion;
				DWORD         DriverVersionLowPart;
				DWORD         DriverVersionHighPart;
				DWORD         VendorId;
				DWORD         DeviceId;
				DWORD         SubSysId;
				DWORD         Revision;
				GUID          DeviceIdentifier;
				DWORD         WHQLLevel;
			};

			DeviceInfo deviceId;

			// supported multisample levels
			bool winMultiSampleLevels[17];
			bool fullMultiSampleLevels[17];


			// Private constructor so the user is forced to call "GetDevice()".
			IDevice();
		public:
			// Decreases the reference count.
			// If the reference count hits 0, then "Dispose()" will be called.
			~IDevice();

			// Either
			// 1. Creates the device and returns it.
			// 2. Returns the already created device.
			// 3. Increases the reference count of the device.
			static IDevice *GetDevice();

			// Finds the closest match to the given video mode
			// and returns it via pointer.
			void FindDisplayMatch(DisplayMode *pMod);

			// Returns the number of available display modes
			unsigned int GetDisplayModeCount();

			// Returns the display mode of the given index
			void GetDisplayMode(unsigned int i, DisplayMode *pRet);

			// Gets the current display mode
			void GetCurrentDisplayMode(DisplayMode *pRet);

			// Whether or not Windowed hardware acceleration is supported
			bool HasWindowedAccel();

			// Whether or not Fullscreen hardware acceleration is supported
			bool HasFullAccel();

			// Get the name of this device
			const char *GetDeviceName();

			// Gets the name of this device's driver
			const char *GetDeviceDescription();

			// Checks whether or not the specified level of multisampling is supported for the given
			// window mode (fullscreen or windowed)
			bool CheckMultiSample(bool bWindowed, unsigned int level);

			// Returns the highest level of multisampling for the given window mode.
			unsigned int GetHighestMultiSample(bool bWindowed);

			// Creates a graphics device
			Tekstorm::Graphics::IGraphics* CreateDevice(const Tekstorm::Core::DisplayMode &dispMode,		// the width, height, format, and hz of the display
					const char *szCaption = "My Game",	// the caption of the window
					bool windowed = true,				// whether or not we are fullscreen or windowed
					bool vsync = true,					// whether or not to use virtical synchronization
					unsigned int multiSampleType = 0,	// amount of multisampling to use
					::WNDPROC msgHandler = NULL);

			// Returns the current reference count of this object.
			virtual unsigned int GetRefCount();

			// Returns the underlying handle to the resource that is to be disposed.
			virtual void *GetHandle();

			// Releases the Direct3D driver
			virtual HRESULT Dispose();
		};
	}
}

#endif /* _TEKSTORM_IDEVICE_H */