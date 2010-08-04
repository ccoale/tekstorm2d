#ifndef _TEKSTORM_GAMETIME_H
#define _TEKSTORM_GAMETIME_H
#include "../TekstormDecl.h"
#include "TimeStamp.h"
#include "TimeSpan.h"

namespace Tekstorm
{
	namespace Core
	{
		// This structure stores information and the game time such as:
		// elapsed game time (time since the first frame) -- generally used for physics and logic
		// elapsed frame time (time since the start of the current frame)
		// last frame time (time it took the last whole frame to complete)
		struct GameTime
		{
			// The TimeStamp of when the actual game started.
			TimeStamp StartGameTime;

			// The TimeStamp of when the current frame started.
			TimeStamp StartFrameTime;

			// The TimeStamp of when the previous frame started.
			TimeStamp StartLastFrameTime;

			// The total amount of time that the game has been running for.
			TimeSpan ElapsedGameTime;

			// The total amount of time that the current frame has been executing for. (Update after Update and Draw).
			TimeSpan ElapsedFrameTime;

			// The total amount of time that the last frame took to execute (total frame time - Update and Draw).
			TimeSpan LastFrameTime;
		};
	}
}

#endif /* _TEKSTORM_GAMETIME_H */