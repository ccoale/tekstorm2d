#define __BUILD
#include "StopWatch.h"

namespace Tekstorm
{
	namespace Core
	{
		// Initializes the static fields of this StopWatch class.
		TEKDECL StopWatch::StopWatch()
		{
			running = false;
			totalTime = 0;
		}

		// De-initializes this instance of StopWatch.
		TEKDECL StopWatch::~StopWatch()
		{
		}

		// Starts the stop watch.
		TEKDECL void StopWatch::Start()
		{
			if (! running) {
				running = true;
				startTime = TimeStamp::GetNow();
			}
		}

		// Stops the stop watch.
		TEKDECL void StopWatch::Stop()
		{
			if (running) {
				running = false;
				totalTime = totalTime + (TimeStamp::GetNow() - startTime);
			}
		}

		// Determines if the stop watch is currently running.
		TEKDECL bool StopWatch::IsRunning() const
		{
			return running;
		}

		// Resets the stop watch.
		TEKDECL void StopWatch::Reset()
		{
			totalTime = 0;
		}

		// Gets the ellapsed time.
		TEKDECL TimeSpan StopWatch::GetTime() const
		{
			return totalTime;
		}
	}
}