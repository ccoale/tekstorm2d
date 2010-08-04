#ifndef _TEKSTORM_DISPLAYMODE_H
#define _TEKSTORM_DISPLAYMODE_H
#include "../TekstormDecl.h"

namespace Tekstorm
{
	namespace Graphics
	{
		// This structure stores information about a native display resolution supported
		// by the given adapter.
		struct DisplayMode
		{
			// The width of the screen in pixels.
			uint_t Width; 

			// The height of the screen in pixels.
			uint_t Height;

			// The refresh rate of the screen in hz.
			uint_t Hz;

			// The adapter that this display mode exists on (for multi-monitor support, 0 for default monitor).
			uint_t Adapter;
		};
	}
}

#endif /* _TEKSTORM_DISPLAYMODE_H */