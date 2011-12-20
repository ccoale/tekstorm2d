#pragma once
#ifndef _TEKSTORM_NETCONFIG_H
#define _TEKSTORM_NETCONFIG_H
#include <WinSock2.h>
#include <Ws2tcpip.h>
#include <Windows.h>
#include "../tekconfig.h"

namespace Tekstorm
{
	namespace Networking
	{
		///
		/// Internal function used to initialize networking in the engine.
		///
		TEKAPI bool InitializeTekstormNetworking();
	}
}

#endif /* _TEKSTORM_NETCONFIG_H */