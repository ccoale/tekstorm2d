/*
**	This header provides a data structure for storing
** a display mode. A display mode is simply a definition
** for the size of a display device and how information
** will be displayed on it.
**
** A Tekstorm Display Mode has the following fields:
** Width -- the width, in pixels, of the device
** Height -- the height, in pixels, of the device
** Hz -- the refresh rate, in hertz, of the device
** Format -- the pixel format of the device (i.e. the arrangement of the color components)
*/
#ifndef _TEKSTORM_DISPLAYMODE_H
#define _TEKSTORM_DISPLAYMODE_H
#include "TekDecl.h"

namespace Tekstorm
{
	namespace Core
	{
		// An enumeration of supported pixel formats
		enum PIXELFORMAT : unsigned int
		{
			PF_X8R8G8B8		= 22,	// 32bpp
			PF_DEFAULT		= PF_X8R8G8B8
		};

		// Represents a display mode
		struct DisplayMode
		{
			// The width, in pixels, of the display mode
			int Width;

			// The height, in pixels, of the display mode
			int Height;

			// The refresh rate, in hertz, of the display mode
			int Hz;

			// The pixel format of the display mode
			int Format;
		};
	}
}

#endif /* _TEKSTORM_DISPLAYMODE_H */