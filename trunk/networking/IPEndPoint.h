#pragma once
#ifndef _TEKSTORM_IPENDPOINT_H
#define _TEKSTORM_IPENDPOINT_H
#include "IPAddress.h"

namespace Tekstorm
{
	namespace Networking
	{
		///
		/// An IPEndPoint is a binding between an IPAddress and a Port.
		///
		class TEKAPI IPEndPoint
		{
		protected:
			///
			/// The underlying port number.
			///
			uint16_t m_nPort;

			///
			/// The IPAddress.
			///
			IPAddress m_ipAddress;

			///
			/// The complete socket address information.
			///
			sockaddr_in sockInfo;

		public:
			///
			/// Initializes a new instance of IPEndPoint.
			///
			IPEndPoint(const IPAddress &address, uint16_t port);

			///
			/// Initializes a new instance of IPEndPoint.
			///
			IPEndPoint();

			///
			/// Gets the bound port number.
			///
			uint16_t GetPort() const;

			///
			/// Gets the bound ip address.
			///
			IPAddress GetAddress() const;

			///
			/// Gets the underlying socket address.
			///
			sockaddr_in GetSocketAddress() const;
		};
	}
}

#endif /* _TEKSTORM_IPENDPOINT_H */