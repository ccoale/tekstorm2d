#ifndef _TEKSTORM_DEVICE_H
#define _TEKSTORM_DEVICE_H
#include "../TekstormDecl.h"
#include "DisplayMode.h"
#include "AdapterInfo.h"

namespace Tekstorm
{
	namespace Graphics
	{
		class TEKDECL Device
		{
		private:
			void *d3d9; // the underyling IDirect3D9 object
			std::vector<DisplayMode> displayModes; // a list of possibly fullscreen display modes
			std::vector<AdapterInfo> adapterInfos; // a list of information on all registered adapters
			uint_t adapterCount; // number of adapters

		public:
			// Creates a new instance of the Device class.
			Device();

			// Destroys this instance of the Device class, freeing its resources.
			~Device();

			// Returns the list of available display modes
			void GetDisplayModes(std::vector<DisplayMode> *modes);

			// Returns the list of adapter information structures
			void GetAdaptersInfo(std::vector<AdapterInfo> *info);

			// Returns the handle to the underlying directx device
			void* GetHandle();
		};
	}
}

#endif /* _TEKSTORM_DEVICE_H */