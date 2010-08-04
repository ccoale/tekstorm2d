#ifndef _TEKSTORM_ADAPTERINFO_H
#define _TEKSTORM_ADAPTERINFO_H
#include "../TekstormDecl.h"

namespace Tekstorm
{
	namespace Graphics
	{
		// This structure stores identifier information about a specific adapter.
		struct AdapterInfo
		{
			// The filename of the driver used for this adapter.
			std::string DriverPath;

			// The description (used for presentation to the user) of this adapter.
			std::string Description;

			// The GDI device name for this adapter.
			std::string Name;

			// The version of this adapter's driver.
			long_t Version;

			// The registered ID of the vendor of the adapter. 0 if unknown.
			uint_t VendorId;

			// The registered ID of this device from the given vendor. 0 if unknown.
			uint_t DeviceId;

			// The subsystem ID of this device from the given vendor. 0 if unknown.
			uint_t SubSysId;

			// The revision number of this device. 0 if unknown.
			uint_t Revision;

			// The adapter index.
			uint_t Adapter;
		};
	}
}

#endif /* _TEKSTORM_ADAPTERINFO_H */