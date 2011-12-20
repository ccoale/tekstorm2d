#define TEKSTORM_BUILD
#include "Socket.h"

namespace Tekstorm
{
	namespace Networking
	{
		///
		/// Initialize a new Socket instance of the given type.
		///
		Socket::Socket(int32_t type, int32_t proto)
		{
			socketType = type;
			socketProto = proto;
			socketHandle = socket(AF_INET, type, proto);
			if (socketHandle == SOCKET_ERROR)
			{
				socketType = 0;
				socketProto = 0;
				socketHandle = 0;

#if defined(TEKSTORM_DEBUG)
				// handle error
#endif
			}
		}

		///
		/// Initializes a new socket instance, that is empty.
		///
		Socket::Socket()
		{
			socketType = 0;
			socketProto = 0;
			socketHandle = 0;
		}

		///
		/// Connects this socket to a remote endpoint with the given port number.
		///
		bool Socket::Connect(const IPEndPoint &endPoint)
		{
#if defined(TEKSTORM_DEBUG)
			if (socketType == 0 || socketProto == 0 || socketHandle == 0) { }
			// handle error
#endif

			this->endPoint = endPoint;
			sockaddr_in sin = endPoint.GetSocketAddress();
			int result = connect(socketHandle, (sockaddr *)&sin, sizeof(sockaddr_in));
			if (result != 0)
			{
#if defined(TEKSTORM_DEBUG)
				// handle error
#endif

				return false;
			}

			return true;
		}

		///
		/// Closes this socket.
		///
		void Socket::Close()
		{
#if defined(TEKSTORM_DEBUG)
			if (socketType == 0 || socketProto == 0 || socketHandle == 0) { }
			// handle error
#endif

			closesocket(socketHandle);
			socketHandle = 0;
		}

		///
		/// Sends data through this socket.
		///
		int32_t Socket::Send(const char *data, int32_t size)
		{
#if defined(TEKSTORM_DEBUG)
			if (socketType == 0 || socketProto == 0 || socketHandle == 0) { }
			// handle error
#endif
			return send(socketHandle, data, size, 0);
		}

		///
		/// Sends data through this socket to a specific endpoint.
		///
		int32_t Socket::SendTo(const IPEndPoint &endPoint, const char *data, int32_t size)
		{
#if defined(TEKSTORM_DEBUG)
			if (socketType == 0 || socketProto == 0 || socketHandle == 0) { }
			// handle error
#endif
			sockaddr_in sin = endPoint.GetSocketAddress();
			return sendto(socketHandle, data, size, 0, (sockaddr *)&sin, sizeof(sockaddr_in));
		}

		///
		/// Attempts to receive 'size' number of bytes from the socket.
		/// If that many bytes are not available, all available bytes
		/// are read into the buffer, and the number of bytes is returned.
		///
		int32_t Socket::Receive(char *buffer, int32_t size)
		{
#if defined(TEKSTORM_DEBUG)
			if (socketType == 0 || socketProto == 0 || socketHandle == 0) { }
			// handle error
#endif

			return recv(socketHandle, buffer, size, 0);
		}

		///
		/// Receives data from a specific host.
		///
		int32_t Socket::ReceiveFrom(IPEndPoint *endPoint, char *buffer, int32_t size)
		{
#if defined(TEKSTORM_DEBUG)
			if (socketType == 0 || socketProto == 0 || socketHandle == 0) { }
			// handle error
#endif
			sockaddr_in sin;
			int fromLen = sizeof(sockaddr_in);
			ZeroMemory(&sin, sizeof(sockaddr_in));
			int32_t res = recvfrom(socketHandle, buffer, size, 0, (sockaddr *)&sin, &fromLen);
			uint16_t port = sin.sin_port;
			char *addr = inet_ntoa(sin.sin_addr);
			*endPoint = IPEndPoint(IPAddress(std::string(addr)), ntohs(port));

			return res;
		}

		///
		/// Puts this socket in a listening state.
		///
		bool Socket::Listen(int32_t backlog)
		{
#if defined(TEKSTORM_DEBUG)
			if (socketType == 0 || socketProto == 0 || socketHandle == 0) { }
			// handle error
#endif
			int result = listen(socketHandle, backlog);
			if (result != 0) {
#if defined(TEKSTORM_DEBUG)
				// handle error
#endif
				return false;
			}

			return true;
		}

		///
		/// Binds this socket to the given end point.
		///
		bool Socket::Bind(const IPEndPoint &endPoint)
		{
#if defined(TEKSTORM_DEBUG)
			if (socketType == 0 || socketProto == 0 || socketHandle == 0) { }
			// handle error
#endif
			sockaddr_in sin = endPoint.GetSocketAddress();
			int result = bind(socketHandle, (const sockaddr *)&sin, sizeof(sockaddr_in));
			if (result != 0) {
#if defined(TEKSTORM_DEBUG)
				// handle error
#endif
				return false;
			}

			return true;
		}


		///
		/// Accepts an incoming connection.
		///
		Socket Socket::Accept()
		{
			sockaddr_in sin;
			int addrLen = sizeof(sockaddr_in);
			ZeroMemory(&sin, addrLen);
			SOCKET sock = accept(socketHandle, (sockaddr *)&sin, &addrLen);
			if (sock == SOCKET_ERROR)
			{
#if defined(TEKSTORM_DEBUG)
				// handle error
#endif
				sock = 0;
			}

			uint16_t port = ntohs(sin.sin_port);
			char *addr = inet_ntoa(sin.sin_addr);
			IPEndPoint point(IPAddress(std::string(addr)), port);

			Socket tempSock;
			tempSock.endPoint = point;
			tempSock.socketProto = socketProto;
			tempSock.socketType = socketType;
			tempSock.socketHandle = sock;

			return tempSock;
		}

		///
		/// Gets the end point.
		///
		IPEndPoint Socket::GetEndPoint()
		{
			return endPoint;
		}
	}
}