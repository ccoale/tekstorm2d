#ifndef _TEKSTORM_TIMESPAN_H
#define _TEKSTORM_TIMESPAN_H
#include "TimeStamp.h"

namespace Tekstorm
{
	namespace Core
	{
		// This class is used to store a span between two times. It is internally
		// stored as ticks between the two times, but methods exist
		// to obtain minutes, seconds, and milliseconds.
		class TEKDECL TimeSpan
		{
		private:
			// The time difference in ticks.
			long_t Raw;

		public:
			// Initializes a new instance of TimeSpan and sets Raw to the value indicated in val.
			TimeSpan(long_t val);

			// Initializes a new instance of TimeSpan.
			TimeSpan();

			// De-initializes this instance of TimeSpan.
			~TimeSpan();

			// Obtains the whole number seconds of this TimeSpan.
			long_t GetSeconds() const;

			// Obtains the whole number minutes of this TimeSpan.
			long_t GetMinutes() const;

			// Obtains the number of ticks of this TimeSpan.
			long_t GetTicks() const;

			// Obtains the real number seconds of this TimeSpan.
			real GetRealSeconds() const;

			// Obtains the real number minutes of this TimeSpan.
			real GetRealMinutes() const;

			// Obtains the whole number milliseconds of this TimeSpan.
			long_t GetMilliseconds() const;

			// Obtains the real number milliseconds of this TimeSpan.
			real GetRealMilliseconds() const;

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
}

#endif /* _TEKSTORM_TIMESPAN_H */