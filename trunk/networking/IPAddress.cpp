#define TEKSTORM_BUILD
#include "IPAddress.h"

namespace Tekstorm
{
	namespace Networking
	{
		///
		/// An IPAddress is initialized from the given textual address.
		///
		TEKAPI IPAddress::IPAddress(const std::string &address)
		{
			int requiredSize = sizeof(in6_addr);
			int result = 0;
			textAddress = address;
			
			if (address == "0.0.0.0") {
				inetAddr = INADDR_ANY;
			} else {
				inetAddr = inet_addr(address.c_str());
			}

			result = WSAStringToAddressA((char *)address.c_str(), AF_INET, NULL,
				(LPSOCKADDR)&ip, &requiredSize);

			if (result == SOCKET_ERROR)
			{
				inetAddr = 0;
#if defined(TEKSTORM_DEBUG)
				// handle error message
#endif
			}
		}

		///
		/// A "null" IPAddress is initialized.
		///
		TEKAPI IPAddress::IPAddress()
		{
			inetAddr = 0;
		}

		///
		/// Returns whether or not this IPAddress structure is empty.
		///
		TEKAPI bool IPAddress::IsNull() const
		{
			return (inetAddr == 0);
		}

		///
		/// Gets the underlying socket address structure pointer.
		///
		TEKAPI sockaddr IPAddress::GetSocketAddress() const
		{
			return ip;
		}

		///
		/// Gets the underlying 32-bit IPv4 internet address.
		///
		ULONG IPAddress::GetInetAddress() const
		{
			return inetAddr;
		}

		///
		/// Gets the underlying text address.
		///
		std::string IPAddress::GetTextAddress() const
		{
			return textAddress;
		}
	}
}