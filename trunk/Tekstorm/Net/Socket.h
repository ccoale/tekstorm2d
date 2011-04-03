#pragma once
#ifndef _TEKSTORM_SOCKET_H
#define _TEKSTORM_SOCKET_H
#include "../BuildConf.h"
#include "../Exception.h"
#include "AddressFamily.h"
#include "ProtocolType.h"
#include "SocketType.h"

namespace Tekstorm
{
	namespace Net
	{
		class TEKAPI Socket
		{
		private:
			/*
			** The Address Family associated with this Socket.
			*/
			AddressFamily addressFamily;

			/*
			** The number of bytes that are available to be read.
			*/
			unsigned int availableBytes;

			/*
			** Whether or not this Socket performs blocking operations.
			*/
			bool isBlocking;

			/*
			** The underlying handle to the Socket.
			*/
			unsigned int handle;

			/*
			** The protcol type that this socket is using.
			*/
			ProtocolType protocolType;

			/*
			** The size of the receive buffer, in bytes.
			*/
			unsigned int receiveBufferSize;

			/*
			** The number of seconds to wait when receiving data before timing out.
			*/
			unsigned int receiveTimeout;

			/*
			** The size of the outgoing buffer, in bytes.
			*/
			unsigned int sendBufferSize;

			/*
			** The number of seconds to wait when sending data before timing out.
			*/
			unsigned int sendTimeout;

			/*
			** The type of this socket.
			*/
			SocketType socketType;
		public:
		};
	}
}

#endif /* _TEKSTORM_SOCKET_H */