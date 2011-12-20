#pragma once
#ifndef _TEKSTORM_SOCKET_H
#define _TEKSTORM_SOCKET_H
#include "NetConfig.h"
#include "IPAddress.h"
#include "IPEndPoint.h"

namespace Tekstorm
{
	namespace Networking
	{
		class TEKAPI Socket
		{
		protected:
			///
			/// The bound/connected endpoint of the socket.
			///
			IPEndPoint endPoint;
			
			///
			/// The type of socket (SOCK_STREAM or SOCK_DGRAM)
			///
			int32_t socketType;

			///
			/// The protocol to use (IPPROTO_UDP or IPPROTO_TCP)
			///
			int32_t socketProto;

			///
			/// The underlying socket.
			///
			SOCKET socketHandle;
		public:
			///
			/// Initialize a new Socket instance of the given type.
			///
			Socket(int32_t type, int32_t proto = IPPROTO_TCP);

			///
			/// Initializes a new socket instance, that is empty.
			///
			Socket();

			///
			/// Connects this socket to a remote endpoint with the given port number.
			///
			virtual bool Connect(const IPEndPoint &endPoint);

			///
			/// Closes this socket.
			///
			virtual void Close();

			///
			/// Sends data through this socket.
			///
			virtual int32_t Send(const char *data, int32_t size);

			///
			/// Sends data through this socket to a specific endpoint.
			///
			virtual int32_t SendTo(const IPEndPoint &endPoint, const char *data, int32_t size);

			///
			/// Attempts to receive 'size' number of bytes from the socket.
			/// If that many bytes are not available, all available bytes
			/// are read into the buffer, and the number of bytes is returned.
			///
			virtual int32_t Receive(char *buffer, int32_t size);

			///
			/// Receives data from a specific host.
			///
			virtual int32_t ReceiveFrom(IPEndPoint *endPoint, char *buffer, int32_t size);

			///
			/// Puts this socket in a listening state.
			///
			virtual bool Listen(int32_t backlog = 16);

			///
			/// Binds this socket to the given end point.
			///
			virtual bool Bind(const IPEndPoint &endPoint);

			///
			/// Accepts an incoming connection.
			///
			virtual Socket Accept();

			///
			/// Gets the end point.
			///
			virtual IPEndPoint GetEndPoint();
		};
	}
}

#endif /* _TEKSTORM_SOCKET_H */