#pragma once
#ifndef _TEKSTORM_IPADDRESS_H
#define _TEKSTORM_IPADDRESS_H
#include "../BuildConf.h"
#include "../Exception.h"
#include "AddressFamily.h"

namespace Tekstorm
{
	namespace Net
	{
		class IPAddress
		{
		private:
			/*
			** Whether or not the IP address is an IPv6 link local address.
			*/
			bool isIPv6LinkLocal;

			/*
			** Whether or not the IP address is an IPv6 Multicast address.
			*/
			bool isIPv6Multicast;

			/*
			** Whether or not the IP adddress is an IPv6 Site local address.
			*/
			bool isIPv6SiteLocal;

			/*
			** Whether or not the IP address is an IPv6 Teredo address.
			*/
			bool isIPv6Teredo;

			/*
			** The address family of this address.
			*/
			AddressFamily addressFamily;

			/*
			** The actual IP address.
			** bytes [0, 3] are used for the IPv4 address.
			** bytes[0,16] are used for the IPv6 address.
			*/
			unsigned char address[16];
		public:
			/*
			** Initializes a new instance of IPAddress.
			** Parameters
			**	addr		- a pointer to an array that stores each indvidual byte of the IP address.
			**	length		- the number of IP address components.
			**				- length must either be 4 or 16.
			**				- if length is 4, then the family is assumed to be IPv4
			**				- if length is 16, then the family is assumed to be IPv6
			* Returns
			**	nothing; however, an Exception may be thrown.
			*/
			IPAddress(unsigned char *addr, int length)
			{
				if (! addr)
					throw Exception("null argument");

				if (length == 4)
				{
					addressFamily = ADDRESS_FAMILY_INTERNETWORK;
					address[0] = addr[0];
					address[1] = addr[1];
					address[2] = addr[2];
					address[3] = addr[3];
					for (int i = 4; i < 16; i++)
						address[i] = 0;
				}
				else if (length == 16)
				{
					addressFamily = ADDRESS_FAMILY_INTERNETWORKV6;
					for (int i = 0; i < 16; i++)
						address[i] = addr[i];
				}
			}

			/*
			**	Gets the family associated with this IP address.
			** Parameters
			**	none
			** Returns
			**	the address family.
			*/
			inline AddressFamily GetAddressFamily() const { return addressFamily; }
		};
	}
}

#endif /* _TEKSTORM_IPADDRESS_H */