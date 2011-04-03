#include "TimeSpan.h"
#include "TimeConstants.h" // for TickFrequency

namespace Tekstorm
{
	namespace Core
	{
		// Initializes a new instance of TimeSpan and sets Raw to the value indicated in val.
		TimeSpan::TimeSpan(__int64 val)
		{
			Raw = val;
		}

		// Initializes a new instance of TimeSpan.
		TimeSpan::TimeSpan()
		{
			Raw = 0;
		}

		// De-initializes this instance of TimeSpan.
		TimeSpan::~TimeSpan()
		{
		}

		// Obtains the whole number seconds of this TimeSpan.
		__int64 TimeSpan::GetSeconds() const
		{
			return (__int64) (Raw / (double)TimeConstants::TickFrequency);
		}

		// Obtains the whole number minutes of this TimeSpan.
		__int64 TimeSpan::GetMinutes() const
		{
			return (__int64) (Raw * TimeConstants::InvTickFrequency * TimeConstants::InvMinuteConv);
		}

		// Obtains the number of ticks of this TimeSpan.
		__int64 TimeSpan::GetTicks() const
		{
			return Raw;
		}

		// Obtains the real number seconds of this TimeSpan.
		float TimeSpan::GetRealSeconds() const
		{
			return (float)(Raw * TimeConstants::InvTickFrequency);
		}

		// Obtains the real number minutes of this TimeSpan.
		float TimeSpan::GetRealMinutes() const
		{
			return (float)(Raw * TimeConstants::InvTickFrequency * TimeConstants::InvMinuteConv);
		}

		// Obtains the whole number milliseconds of this TimeSpan.
		__int64 TimeSpan::GetMilliseconds() const
		{
			return (__int64) ((Raw * TimeConstants::InvTickFrequency) * 1000.0f);
		}

		// Obtains the real number milliseconds of this TimeSpan.
		float TimeSpan::GetRealMilliseconds() const
		{
			return (float)((Raw * TimeConstants::InvTickFrequency) * 1000.0f);
		}

		// Adds this TimeSpan with another.
		TimeSpan TimeSpan::operator+(const TimeSpan& other) const
		{
			return TimeSpan(Raw + other.Raw);
		}

		// Subtracts another TimeSpan from this TimeSpan.
		TimeSpan TimeSpan::operator-(const TimeSpan& other) const
		{
			return TimeSpan(Raw - other.Raw);
		}

		// Negates this TimeSpan.
		TimeSpan TimeSpan::operator-() const
		{
			return TimeSpan(-Raw);
		}

		// Determines if this TimeSpan equals another.
		bool TimeSpan::operator==(const TimeSpan& other) const
		{
			return ( Raw == other.Raw );
		}

		// Determines if this TimeSpan is greater than another.
		bool TimeSpan::operator>(const TimeSpan& other) const
		{
			return ( Raw > other.Raw );
		}

		// Determines if this TimeSpan is less than another.
		bool TimeSpan::operator<(const TimeSpan& other) const
		{
			return ( Raw < other.Raw );
		}

		// Determines if this TimeSpan is greater than or equal to another.
		bool TimeSpan::operator>=(const TimeSpan& other) const
		{
			return ( Raw >= other.Raw );
		}

		// Determines if this TimeSpan is less than or equal to another.
		bool TimeSpan::operator<=(const TimeSpan& other) const
		{
			return ( Raw <= other.Raw );
		}

		// Assigns this TimeSpan a new value.
		TimeSpan& TimeSpan::operator=(const TimeSpan& other)
		{
			Raw = other.Raw;

			return *this;
		}
	}
}