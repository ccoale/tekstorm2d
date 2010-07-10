#ifndef _TEKSTORM_STOPWATCH_H
#define _TEKSTORM_STOPWATCH_H
#include "TimeSpan.h"
#include "TimeStamp.h"

namespace Tekstorm
{
	namespace Core
	{
		class TEKDECL StopWatch
		{
		private:
			// Whether or not the stop watch is running.
			bool running;

			// The total running time so far.
			TimeSpan totalTime;

			// The last start time.
			TimeStamp startTime;
		public:
			// Initializes the static fields of this StopWatch class.
			StopWatch();

			// De-initializes this instance of StopWatch.
			~StopWatch();

			// Starts the stop watch.
			void Start();

			// Stops the stop watch.
			void Stop();

			// Determines if the stop watch is currently running.
			bool IsRunning() const;

			// Resets the stop watch.
			void Reset();

			// Gets the ellapsed time.
			TimeSpan GetTime() const;
		};
	}
}

#endif /* _TEKSTORM_STOPWATCH_H */