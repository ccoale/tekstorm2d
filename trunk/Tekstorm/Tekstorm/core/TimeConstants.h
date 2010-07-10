#ifndef _TEKSTORM_TIMECONSTANTS_H
#define _TEKSTORM_TIMECONSTANTS_H
#include "../TekstormDecl.h"

namespace Tekstorm
{
	namespace Core
	{
		// This class is used to store static time constants (such as frequency, invfrequency, etc.)
		class TEKDECL TimeConstants
		{
		public:
			static long_t TickFrequency;
			static double InvTickFrequency;
			static double InvMinuteConv;

			static void InitConstants();
		};
	}
}

#endif /* _TEKSTORM_TIMECONSTANTS_H */