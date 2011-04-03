#pragma once
#ifndef _TEKSTORM_SOCKETTYPE_H
#define _TEKSTORM_SOCKETTYPE_H
#include "../BuildConf.h"

namespace Tekstorm
{
	namespace Net
	{
		enum SocketType : int
		{
			SOCKET_TYPE_STREAM,
			SOCKET_TYPE_DGRAM,
			SOCKET_TYPE_RAW,
			SOCKET_TYPE_RDM,
			SOCKET_TYPE_SEQPACKET,
			SOCKET_TYPE_UNKNOWN
		};
	}
}

#endif /* _TEKSTORM_SOCKETTYPE_H */