#pragma once
#ifndef _TEKSTORM_IDISPOSABLE_H
#define _TEKSTORM_IDISPOSABLE_H
#include "../tekconfig.h"

namespace Tekstorm
{
	namespace Core
	{
		///
		/// All disposable resources should inherit this class.
		///
		class TEKAPI IDisposable
		{
		public:
			///
			/// Releases this object from memory along with all of its resources.
			///
			virtual bool Dispose() = 0;
		};
	}
}

#endif /* _TEKSTORM_IDISPOSABLE_H */