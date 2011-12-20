#pragma once
#ifndef _TEKSTORM_IPADDRESS_H
#define _TEKSTORM_IPADDRESS_H
#include "../tekconfig.h"
#include "NetConfig.h"

namespace Tekstorm
{
	namespace Networking
	{
		///
		/// Represents an IPv4 address.
		///
		class TEKAPI IPAddress
		{
		protected:
			///
			/// The address information structure
			///
			sockaddr ip;

			///
			/// The underlying IPv4 address as a 32-bit long.
			///
			ULONG inetAddr;

			///
			/// The underlying textual address.
			///
			std::string textAddress;
		public:
			///
			/// An IPAddress is initialized from the given textual address.
			///
			IPAddress(const std::string &address);

			///
			/// A "null" IPAddress is initialized.
			///
			IPAddress();

			///
			/// Returns whether or not this IPAddress structure is empty.
			///
			virtual bool IsNull() const;

			///
			/// Gets the underlying socket address structure pointer.
			///
			virtual sockaddr GetSocketAddress() const;

			///
			/// Gets the underlying 32-bit IPv4 internet address.
			///
			virtual ULONG GetInetAddress() const;

			///
			/// Gets the underlying text address.
			///
			virtual std::string GetTextAddress() const;
		};
	}
}

#endif /* _TEKSTORM_IPADDRESS_H */