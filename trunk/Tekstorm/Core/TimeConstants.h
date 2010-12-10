#ifndef __TIMECONSTANTS_H
#define _TIMECONSTANTS_H

namespace Tekstorm
{
	namespace Core
	{
		// This class is used to store static time constants (such as frequency, invfrequency, etc.)
		class TimeConstants
		{
		public:
			static __int64 TickFrequency;
			static double InvTickFrequency;
			static double InvMinuteConv;

			static void InitConstants();
		};
	}
}

#endif /* _TEKSTORM_TIMECONSTANTS_H */