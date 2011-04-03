#pragma once
#ifndef _TEKSTORM_SEEKORIGIN_H
#define _TEKSTORM_SEEKORIGIN_H
#include "../BuildConf.h"

namespace Tekstorm
{
	namespace IO
	{
#undef SEEK_BEGIN
#undef SEEK_CURRENT
#undef SEEK_END

		// VC++ 2010 doesn't support scoped enums yet!
		enum SeekOrigin
		{
			/*
			** The beginning of the stream (i.e. 0).
			*/
			SEEK_BEGIN,

			/*
			** The current position in the stream.
			*/
			SEEK_CURRENT,

			/*
			** The end of the stream.
			*/
			SEEK_END
		};
	}
}

#endif /* _TEKSTORM_SEEKORIGIN_H */