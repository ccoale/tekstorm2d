#ifndef _TIMESPAN_H
#define _TIMESPAN_H
#include "TimeStamp.h"

namespace Tekstorm
{
		// This class is used to store a span between two times. It is internally
		// stored as ticks between the two times, but methods exist
		// to obtain minutes, seconds, and milliseconds.
		class TimeSpan
		{
		private:
			// The time difference in ticks.
			__int64 Raw;

		public:
			// Initializes a new instance of TimeSpan and sets Raw to the value indicated in val.
			TimeSpan(__int64 val);

			// Initializes a new instance of TimeSpan.
			TimeSpan();

			// De-initializes this instance of TimeSpan.
			~TimeSpan();

			// Obtains the whole number seconds of this TimeSpan.
			__int64 GetSeconds() const;

			// Obtains the whole number minutes of this TimeSpan.
			__int64 GetMinutes() const;

			// Obtains the number of ticks of this TimeSpan.
			__int64 GetTicks() const;

			// Obtains the float number seconds of this TimeSpan.
			float GetRealSeconds() const;

			// Obtains the float number minutes of this TimeSpan.
			float GetRealMinutes() const;

			// Obtains the whole number milliseconds of this TimeSpan.
			__int64 GetMilliseconds() const;

			// Obtains the float number milliseconds of this TimeSpan.
			float GetRealMilliseconds() const;

			// Adds this TimeSpan with another.
			TimeSpan operator+(const TimeSpan& other) const;

			// Subtracts another TimeSpan from this TimeSpan.
			TimeSpan operator-(const TimeSpan& other) const;

			// Negates this TimeSpan.
			TimeSpan operator-() const;

			// Determines if this TimeSpan equals another.
			bool operator==(const TimeSpan& other) const;

			// Determines if this TimeSpan is greater than another.
			bool operator>(const TimeSpan& other) const;

			// Determines if this TimeSpan is less than another.
			bool operator<(const TimeSpan& other) const;

			// Determines if this TimeSpan is greater than or equal to another.
			bool operator>=(const TimeSpan& other) const;

			// Determines if this TimeSpan is less than or equal to another.
			bool operator<=(const TimeSpan& other) const;

			// Assigns this TimeSpan a new value.
			TimeSpan& operator=(const TimeSpan& other);
		};
}

#endif /* _TIMESPAN_H */