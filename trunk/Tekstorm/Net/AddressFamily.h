#pragma once
#ifndef _TEKSTORM_ADDRESSFAMILY_H
#define _TEKSTORM_ADDRESSFAMILY_H
#include "../BuildConf.h"

namespace Tekstorm
{
	namespace Net
	{
		enum AddressFamily : int
		{
			/*
			** Unknown address family.
			*/
			ADDRESS_FAMILY_UNKNOWN = -1,

			/*
			** Unspecified address family.
			*/
			ADDRESS_FAMILY_UNSPECIFIED = 0,

			/*
			** Unix local to host address.
			*/
			ADDRESS_FAMILY_UNIX,

			/*
			** Address for IP version 4.
			*/
			ADDRESS_FAMILY_INTERNETWORK,

			/*
			** ARPANET IMP address.
			*/
			ADDRESS_FAMILY_IMPLINK,

			/*
			** Address for PUP protocols.
			*/
			ADDRESS_FAMILY_PUP,

			/*
			** Address for MIT CHAOS protocols.
			*/
			ADDRESS_FAMILY_CHAOS,

			/*
			** Address for Xerox NS protocols.
			*/
			ADDRESS_FAMILY_NS,

			/*
			** IPX or SPX address.
			*/
			ADDRESS_FAMILY_IPX,

			/*
			** Address for ISO protocols.
			*/
			ADDRESS_FAMILY_ISO,

			/*
			** Address for OSI protocols.
			*/
			ADDRESS_FAMILY_OSI = ADDRESS_FAMILY_ISO,

			/*
			** European Computer Manufacturers Association address.
			*/
			ADDRESS_FAMILY_ECMA,

			/*
			** Address for Datakit protocols.
			*/
			ADDRESS_FAMILY_DATAKIT,

			/*
			** Address for CCITT protocols, such as X.25.
			*/
			ADDRESS_FAMILY_CCITT,

			/*
			** IBM SNA address
			*/
			ADDRESS_FAMILY_SNA,

			/*
			** DECnet address.
			*/
			ADDRESS_FAMILY_DECNET,

			/*
			** Direct data-link interface.
			*/
			ADDRESS_FAMILY_DATALINK,

			/*
			** LAT address
			*/
			ADDRESS_FAMILY_LAT,

			/*
			** NSC Hyperchannel address.
			*/
			ADDRESS_FAMILY_HYPERCHANNEL,

			/*
			** AppleTalk address.
			*/
			ADDRESS_FAMILY_APPLETALK,

			/*
			** NetBios address.
			*/
			ADDRESS_FAMILY_NETBIOS,

			/*
			** VoiceView address.
			*/
			ADDRESS_FAMILY_VOICEVIEW,

			/*
			** FireFox address.
			*/
			ADDRESS_FAMILY_FIREFOX,

			/*
			** Banyan address.
			*/
			ADDRESS_FAMILY_BANYAN,

			/*
			** Native ATM services address.
			*/
			ADDRESS_FAMILY_ATM,

			/*
			** Address for IP version 6.
			*/
			ADDRESS_FAMILY_INTERNETWORKV6,

			/*
			** Address for Microsoft cluster products.
			*/
			ADDRESS_FAMILY_CLUSTER,

			/*
			** IEEE 1284.4 workgroup address.
			*/
			ADDRESS_FAMILY_IEEE12844,

			/*
			** IrDA address
			*/
			ADDRESS_FAMILY_IRDA,

			/*
			** Address for Network Designers OSI gateway
			*/
			ADDRESS_FAMILY_NETWORKDESIGNERS,

			/*
			** MAX address
			*/
			ADDRESS_FAMILY_MAX
		};
	}
}

#endif /* _TEKSTORM_ADDRESSFAMILY_H */