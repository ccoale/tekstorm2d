#define TEKBUILD
#include "IDevice.h"

#define TMPABS(x) ( ((x) > 0) ? (x) : (-(x)) )
namespace Tekstorm
{
	namespace Core
	{
		// set our static pointer to NULL
		IDevice *IDevice::pDev = NULL;

		// Private constructor so the user is forced to call "GetDevice()".
		IDevice::IDevice()
		{
			nDispModeCount = 0;
			pModes = NULL;
			pD3D = NULL;
			fullAccel = winAccel = false;

			// initialize direct3D
			pD3D = Direct3DCreate9(D3D_SDK_VERSION);
			if (! pD3D) {
				TEKTHROW(GetLastError());
			}
		}

		// Decreases the reference count.
		// If the reference count hits 0, then "Dispose()" will be called.
		IDevice::~IDevice()
		{
			nRef--;
			if (nRef == 0)
				Dispose();
		}

		// Either
		// 1. Creates the device and returns it.
		// 2. Returns the already created device.
		// 3. Increases the reference count of the device.
		IDevice *IDevice::GetDevice()
		{
			if (pDev) {
				pDev->nRef++;
				return pDev;
			}

			// we have to create the device
			IDevice *dev = new IDevice();
			TEKHANDLE(IDirect3D9, pDX);
			pDX = Direct3DCreate9(D3D_SDK_VERSION);
			if (pDX == NULL)
			{
				TEKTHROW(E_FAIL);
				return NULL;
			}

			// now that we have our device, let's enum through display modes
			dev->nDispModeCount = pDX->GetAdapterModeCount(D3DADAPTER_DEFAULT, (D3DFORMAT)PF_X8R8G8B8);
			if (dev->nDispModeCount <= 0) {
				TEKTHROW(E_FAIL);
				dev->Dispose();
				delete dev;
				return NULL;
			}

			dev->pModes = new DisplayMode[dev->nDispModeCount];
			for (unsigned int i = 0; i < dev->nDispModeCount; i++)
			{
				// get display mode
				pDX->EnumAdapterModes(D3DADAPTER_DEFAULT,
					(D3DFORMAT)PF_X8R8G8B8, i, (D3DDISPLAYMODE *)&dev->pModes[i]);
			}

			// get the current display mode
			pDX->GetAdapterDisplayMode(D3DADAPTER_DEFAULT,
				(D3DDISPLAYMODE *)&dev->curDispMode);

			// check the hardware acceleration support (windowed)
			if (SUCCEEDED(pDX->CheckDeviceType(D3DADAPTER_DEFAULT,
				D3DDEVTYPE_HAL, (D3DFORMAT)PF_X8R8G8B8, (D3DFORMAT)PF_X8R8G8B8,
				TRUE)))
				dev->winAccel = true;
			else
				dev->winAccel = false;

			// check the hardware acceleration support (fullscreen)
			if (SUCCEEDED(pDX->CheckDeviceType(D3DADAPTER_DEFAULT,
				D3DDEVTYPE_HAL, (D3DFORMAT)PF_X8R8G8B8, (D3DFORMAT)PF_X8R8G8B8,
				FALSE)))
				dev->fullAccel = true;
			else
				dev->fullAccel = false;

			// get the driver identifier
			HRESULT hr;
			if (FAILED(hr = pDX->GetAdapterIdentifier(D3DADAPTER_DEFAULT, 0, (D3DADAPTER_IDENTIFIER9 *)&dev->deviceId)))
			{
				TEKTHROW(hr);
				dev->Dispose();
				delete dev;
				return NULL;
			}

			// now we must check each multisample level..
			for (unsigned int i = 0; i < 17; i++)
			{
				if (SUCCEEDED(pDX->CheckDeviceMultiSampleType(D3DADAPTER_DEFAULT,
					D3DDEVTYPE_HAL, (D3DFORMAT)PF_X8R8G8B8, TRUE, (D3DMULTISAMPLE_TYPE)i, NULL)))
					dev->winMultiSampleLevels[i] = true;
				else
					dev->winMultiSampleLevels[i] = false;

				if (SUCCEEDED(pDX->CheckDeviceMultiSampleType(D3DADAPTER_DEFAULT,
					D3DDEVTYPE_HAL, (D3DFORMAT)PF_X8R8G8B8, FALSE, (D3DMULTISAMPLE_TYPE)i, NULL)))
					dev->fullMultiSampleLevels[i] = true;
				else
					dev->fullMultiSampleLevels[i] = false;
			}

			IDevice::pDev = dev;
			pDev->nRef++; // add 1 to our reference count
			return pDev;
		}

		// Finds the closest match to the given video mode
		// and returns it via pointer.
		void IDevice::FindDisplayMatch(DisplayMode *pMod)
		{
			if (! pMod) {
				return TEKTHROW(E_INVALIDARG);
			}
				
			unsigned int nSmallestIndex = 0;
			unsigned int nSmallestDiff = 0xFFFFFFFE;
			DisplayMode thatMode = *pMod;

			for (unsigned int i = 0; i < nDispModeCount; i++)
			{
				DisplayMode thisMode = pModes[i];
				unsigned int diffSum = TMPABS(thatMode.Width - thisMode.Width)*3 + TMPABS(thatMode.Height - thisMode.Height)*3
					+ TMPABS(thatMode.Hz - thisMode.Hz) + TMPABS(thatMode.Format - thisMode.Format)*2;

				if (diffSum < nSmallestDiff) {
					nSmallestDiff = diffSum;
					nSmallestIndex = i;
				}
			}

			*pMod = pModes[nSmallestIndex];	
		}

		// Whether or not Windowed hardware acceleration is supported
		bool IDevice::HasWindowedAccel()
		{
			return winAccel;
		}

		// Whether or not Fullscreen hardware acceleration is supported
		bool IDevice::HasFullAccel()
		{
			return fullAccel;
		}

		// Returns the number of available display modes
		unsigned int IDevice::GetDisplayModeCount()
		{
			return nDispModeCount;
		}

		// Returns the display mode of the given index
		void IDevice::GetDisplayMode(unsigned int i, DisplayMode *pRet)
		{
			if ((i < 0 || i >= nDispModeCount) || (pRet == NULL))
				return TEKTHROW(E_INVALIDARG);

			*pRet = pModes[i];

		}

		// Gets the current display mode
		void IDevice::GetCurrentDisplayMode(DisplayMode *pRet)
		{
			if (! pRet)
				return TEKTHROW(E_INVALIDARG);

			*pRet = curDispMode;
		}

		// Get the name of this device
		const char *IDevice::GetDeviceName()
		{
			return (const char *)deviceId.DeviceName;
		}

		// Gets the name of this device's driver
		const char *IDevice::GetDeviceDescription()
		{
			return (const char *)deviceId.Description;
		}

		// Checks whether or not the specified level of multisampling is supported for the given
		// window mode (fullscreen or windowed)
		bool IDevice::CheckMultiSample(bool bWindowed, unsigned int level)
		{
			if (level < 0 || level >= 17)	
			{
				TEKTHROW(E_INVALIDARG);
				return false;
			}

			if (bWindowed)
				return winMultiSampleLevels[level];
		
			return fullMultiSampleLevels[level];
		}

		// Returns the highest level of multisampling for the given window mode.
		unsigned int IDevice::GetHighestMultiSample(bool bWindowed)
		{
			if (bWindowed) {
				for (unsigned int i = 16; i >= 0; i--) {
					if (winMultiSampleLevels[i])
						return i;
				}
			} else {
				for (unsigned int i = 16; i >= 0; i--) {
					if (fullMultiSampleLevels[i])
						return i;
				}
			}

			return 0;
		}

		// Creates a graphics device
		Tekstorm::Graphics::IGraphics* IDevice::CreateDevice(const DisplayMode &dispMode, const char *szCaption,
			bool windowed, bool vsync, unsigned int multiSampleType, WNDPROC msgHandler)
		{
			Tekstorm::Graphics::IGraphics *pGraph = NULL;
			try {
				pGraph = new Tekstorm::Graphics::IGraphics((IDevice *)this, dispMode, szCaption, windowed, vsync, multiSampleType, msgHandler);
			} catch (Core::Exception ex) {
				if (pGraph) delete pGraph;
				return NULL;
			}

			return pGraph;
		}

		// Returns the current reference count of this object.
		unsigned int IDevice::GetRefCount()
		{
			return nRef;
		}

		// Returns the underlying handle to the resource that is to be disposed.
		void *IDevice::GetHandle()
		{
			return (void *)pD3D;
		}

		// Releases the Direct3D driver
		HRESULT IDevice::Dispose()
		{
			nRef = 0; // override reference
			if (pModes)
				delete[] pModes;
			if (pDev)
				pDev->pD3D->Release();

			return S_OK;
		}
	}
}