#pragma once
#ifndef _TEKSTORM_IRESOURCE_H
#define _TEKSTORM_IRESOURCE_H
#include "BuildConf.h"

namespace Tekstorm
{
	/*
	** All in game resource inherit this class.
	*/
	class IResource
	{
	public:
		/*
		** Gets the underlying resource handle.
		** Parameters
		**	none
		** Returns
		**	nothing
		*/
		virtual void *GetHandle() const = 0;

		/*
		** Destroys this resource and all memory it uses. Once this method is called,
		** the resource can no longer be used.
		*/
		virtual void Release() = 0;
	};
}

#endif /* _TEKSTORM_IRESOURCE_H */