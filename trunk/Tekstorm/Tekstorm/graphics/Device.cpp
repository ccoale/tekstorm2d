#define __BUILD
#include "Device.h"
#include "../Core/Exception.h"

namespace Tekstorm
{
	namespace Graphics
	{


		// Creates a new instance of the Device class.
		Device::Device()
		{
			IDirect3D9 *pDev;

			// try to create the device
			if (NULL == (pDev = Direct3DCreate9(D3D_SDK_VERSION)))
			{
				throw Core::Exception(E_FAIL, "An error occurred while creating the Direct3D9 object.");
				return;
			}

			// get the number of adapters we're working with
			adapterCount = pDev->GetAdapterCount();

			// enumerate through all adapters to grab info about them
			for (uint_t i = 0; i < adapterCount; i++)
			{
				uint_t adapterModeCount = pDev->GetAdapterModeCount(i, D3DFMT_X8R8G8B8);
				for (uint_t j = 0; j < adapterModeCount; j++)
				{
					DisplayMode mode;
					mode.Adapter = i;

					if (FAILED(pDev->EnumAdapterModes(i, D3DFMT_X8R8G8B8, j, (D3DDISPLAYMODE *)&mode)))
						continue; // simply skip if it failed

					// add mode to the list
					displayModes.push_back(mode);
				}

				D3DADAPTER_IDENTIFIER9 ident;
				AdapterInfo info;

				if (FAILED(pDev->GetAdapterIdentifier(i, 0, &ident)))
					continue; // skip this identifier

				info.Adapter = i;
				info.Description = ident.Description;
				info.Name = ident.DeviceName;
				info.Version = ident.DriverVersion.QuadPart;
				info.VendorId = ident.VendorId;
				info.DeviceId = ident.DeviceId;
				info.SubSysId = ident.SubSysId;
				info.Revision = ident.Revision;
				adapterInfos.push_back(info);
			}

			d3d9 = pDev;
		}

		// Destroys this instance of the Device class, freeing its resources.
		Device::~Device()
		{
			IDirect3D9 *pDev = (IDirect3D9 *)d3d9;
			if (pDev) {
				pDev->Release();
				pDev = NULL;
			}
		}

		// Returns the list of available display modes
		void Device::GetDisplayModes(std::vector<DisplayMode> *modes)
		{
			*modes = displayModes;
		}

		// Returns the list of adapter information structures
		void Device::GetAdaptersInfo(std::vector<AdapterInfo> *info)
		{
			*info = adapterInfos;
		}

		// Returns the handle to the underlying directx device
		void* Device::GetHandle()
		{
			return d3d9;
		}
	}
}