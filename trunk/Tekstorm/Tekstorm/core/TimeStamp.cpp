#define __BUILD
#include "TimeStamp.h"

namespace Tekstorm
{
	namespace Core
	{
		// Initializes a new instance of TimeStamp
		TEKDECL TimeStamp::TimeStamp(long_t stamp)
		{
			Raw = stamp;
		}

		// Initializes a new instance of this TimeStamp
		TEKDECL TimeStamp::TimeStamp()
		{
			Raw = 0;
		}

		// De-initializes this instance of GameTime
		TEKDECL TimeStamp::~TimeStamp()
		{
		}

		// Gets the raw time stamp associated with this instance.
		TEKDECL long_t TimeStamp::GetTimeStamp() const
		{
			return Raw;
		}

		// Gets the current time stamp.
		TEKDECL TimeStamp TimeStamp::GetNow()
		{
			__int64 nv = 0;
			QueryPerformanceCounter((LARGE_INTEGER *) &nv);
			return TimeStamp(nv);
		}

		// Determines if this TimeStamp is equal to another.
		TEKDECL bool TimeStamp::operator==(const TimeStamp& other) const
		{
			return (Raw == other.Raw);
		}

		// Determines if this TimeStamp is greater than (comes after) another.
		TEKDECL bool TimeStamp::operator>(const TimeStamp& other) const
		{
			return (Raw > other.Raw);
		}

		// Determines if this TimeStamp is greater than (comes after or at the same time) another.
		TEKDECL bool TimeStamp::operator>=(const TimeStamp& other) const
		{
			return (Raw >= other.Raw);
		}

		// Determines if this TimeStamp is less than (comes before) another.
		TEKDECL bool TimeStamp::operator<(const TimeStamp& other) const
		{
			return (Raw < other.Raw);
		}

		// Determines if this TimeStamp is less than or equal to (comes before or at the same time) another.
		TEKDECL bool TimeStamp::operator<=(const TimeStamp& other) const
		{
			return (Raw <= other.Raw);
		}

		// Adds a TimeSpan to this TimeStamp, returning a new TimeStamp.
		TEKDECL TimeStamp TimeStamp::operator+(const TimeSpan& other) const
		{
			return TimeStamp(Raw + other.GetTicks());
		}

		// Subtracts another TimeStamp from this TimeStamp.
		TEKDECL TimeSpan TimeStamp::operator-(const TimeStamp& other) const
		{
			return TimeSpan(Raw - other.Raw);
		}

		// Subtracts a TimeSpan from this TimeStamp, returning a new TimeStamp.
		TEKDECL TimeStamp TimeStamp::operator-(const TimeSpan& other) const
		{
			return TimeStamp(Raw - other.GetTicks());
		}
	}
}