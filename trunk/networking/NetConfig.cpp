#define TEKSTORM_BUILD
#include "NetConfig.h"
#pragma comment(lib, "ws2_32.lib")

namespace Tekstorm
{
	namespace Networking
	{
		///
		/// Internal function used to initialize networking in the engine.
		///
		TEKAPI bool InitializeTekstormNetworking()
		{
			static WSADATA data;
			int err = WSAStartup(MAKEWORD(2,2), &data);
			if (err != 0)
			{
#if defined (TEKSTORM_DEBUG)
				// handle error
#endif
				return false;
			}

			return true;
		}
	}
}