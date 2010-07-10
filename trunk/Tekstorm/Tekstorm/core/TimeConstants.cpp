#define __BUILD
#include "TimeConstants.h"

namespace Tekstorm
{
	namespace Core
	{
		TEKDECL long_t TimeConstants::TickFrequency;
		TEKDECL double TimeConstants::InvTickFrequency;
		TEKDECL double TimeConstants::InvMinuteConv;

		TEKDECL void TimeConstants::InitConstants()
		{
			QueryPerformanceFrequency((LARGE_INTEGER *)&TimeConstants::TickFrequency);
			TimeConstants::InvTickFrequency = 1.0 / (double)TimeConstants::TickFrequency;
			TimeConstants::InvMinuteConv = 1.0 / 60;
		}
	}
}