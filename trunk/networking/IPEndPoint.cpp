#define TEKSTORM_BUILD
#include "IPEndPoint.h"

namespace Tekstorm
{
	namespace Networking
	{
			///
			/// Initializes a new instance of IPEndPoint.
			///
			IPEndPoint::IPEndPoint(const IPAddress &address, uint16_t port)
			{
				m_nPort = port;
				m_ipAddress = address;
				ZeroMemory(&sockInfo, sizeof(sockaddr_in));
				sockInfo.sin_addr.s_addr = address.GetInetAddress();
				sockInfo.sin_port = htons(port);
				sockInfo.sin_family = AF_INET;
			}

			///
			/// Initializes a new instance of IPEndPoint.
			///
			IPEndPoint::IPEndPoint()
			{
				m_nPort = 0;
				m_ipAddress = IPAddress();
				sockInfo.sin_addr.s_addr = 0;
				sockInfo.sin_family = 0;
				sockInfo.sin_port = 0;
			}

			///
			/// Gets the bound port number.
			///
			uint16_t IPEndPoint::GetPort() const
			{
				return m_nPort;
			}

			///
			/// Gets the bound ip address.
			///
			IPAddress IPEndPoint::GetAddress() const
			{
				return m_ipAddress;
			}

			///
			/// Gets the underlying socket address.
			///
			sockaddr_in IPEndPoint::GetSocketAddress() const
			{
				return sockInfo;
			}
	}
}