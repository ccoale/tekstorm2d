#ifndef _TIMESTAMP_H
#define _TIMESTAMP_H
#include "TimeSpan.h"

namespace Tekstorm
{
	class TimeSpan; // forward declare

	class TimeStamp
	{
	private:
		// The raw time stamp (the number of ticks since the computer has been started).
		__int64 Raw;

	public:
		// Initializes a new instance of TimeStamp
		TimeStamp(__int64 stamp);

		// Initializes a new instance of this TimeStamp
		TimeStamp();

		// De-initializes this instance of TimeStamp
		~TimeStamp();

		// Gets the raw time stamp associated with this instance.
		__int64 GetTimeStamp() const;

		// Gets the current time stamp.
		static TimeStamp GetNow();

		// Determines if this TimeStamp is equal to another.
		bool operator==(const TimeStamp& other) const;

		// Determines if this TimeStamp is greater than (comes after) another.
		bool operator>(const TimeStamp& other) const;

		// Determines if this TimeStamp is greater than (comes after or at the same time) another.
		bool operator>=(const TimeStamp& other) const;

		// Determines if this TimeStamp is less than (comes before) another.
		bool operator<(const TimeStamp& other) const;

		// Determines if this TimeStamp is less than or equal to (comes before or at the same time) another.
		bool operator<=(const TimeStamp& other) const;

		// Adds a TimeSpan to this TimeStamp, returning a new TimeStamp.
		TimeStamp operator+(const TimeSpan& other) const;

		// Subtracts another TimeStamp from this TimeStamp.
		TimeSpan operator-(const TimeStamp& other) const;

		// Subtracts a TimeSpan from this TimeStamp, returning a new TimeStamp.
		TimeStamp operator-(const TimeSpan& other) const;
	};
}

#endif /* _TIMESTAMP_H */