#include "TimeStamp.h"
#include <Windows.h>

namespace Tekstorm
{
		// Initializes a new instance of TimeStamp
		TimeStamp::TimeStamp(__int64 stamp)
		{
			Raw = stamp;
		}

		// Initializes a new instance of this TimeStamp
		TimeStamp::TimeStamp()
		{
			Raw = 0;
		}

		// De-initializes this instance of GameTime
		TimeStamp::~TimeStamp()
		{
		}

		// Gets the raw time stamp associated with this instance.
		__int64 TimeStamp::GetTimeStamp() const
		{
			return Raw;
		}

		// Gets the current time stamp.
		TimeStamp TimeStamp::GetNow()
		{
			__int64 nv = 0;
			QueryPerformanceCounter((LARGE_INTEGER *) &nv);
			return TimeStamp(nv);
		}

		// Determines if this TimeStamp is equal to another.
		bool TimeStamp::operator==(const TimeStamp& other) const
		{
			return (Raw == other.Raw);
		}

		// Determines if this TimeStamp is greater than (comes after) another.
		bool TimeStamp::operator>(const TimeStamp& other) const
		{
			return (Raw > other.Raw);
		}

		// Determines if this TimeStamp is greater than (comes after or at the same time) another.
		bool TimeStamp::operator>=(const TimeStamp& other) const
		{
			return (Raw >= other.Raw);
		}

		// Determines if this TimeStamp is less than (comes before) another.
		bool TimeStamp::operator<(const TimeStamp& other) const
		{
			return (Raw < other.Raw);
		}

		// Determines if this TimeStamp is less than or equal to (comes before or at the same time) another.
		bool TimeStamp::operator<=(const TimeStamp& other) const
		{
			return (Raw <= other.Raw);
		}

		// Adds a TimeSpan to this TimeStamp, returning a new TimeStamp.
		TimeStamp TimeStamp::operator+(const TimeSpan& other) const
		{
			return TimeStamp(Raw + other.GetTicks());
		}

		// Subtracts another TimeStamp from this TimeStamp.
		TimeSpan TimeStamp::operator-(const TimeStamp& other) const
		{
			return TimeSpan(Raw - other.Raw);
		}

		// Subtracts a TimeSpan from this TimeStamp, returning a new TimeStamp.
		TimeStamp TimeStamp::operator-(const TimeSpan& other) const
		{
			return TimeStamp(Raw - other.GetTicks());
		}
}