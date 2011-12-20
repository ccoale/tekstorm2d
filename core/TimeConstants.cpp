#include "TimeConstants.h"
#include <Windows.h>

namespace Tekstorm
{
	namespace Core
	{
		__int64 TimeConstants::TickFrequency;
		double TimeConstants::InvTickFrequency;
		double TimeConstants::InvMinuteConv;

		void TimeConstants::InitConstants()
		{
			QueryPerformanceFrequency((LARGE_INTEGER *)&TimeConstants::TickFrequency);
			TimeConstants::InvTickFrequency = 1.0 / (double)TimeConstants::TickFrequency;
			TimeConstants::InvMinuteConv = 1.0 / 60;
		}
	}
}