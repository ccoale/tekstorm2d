#define __BUILD
#include "TimeSpan.h"
#include "TimeConstants.h" // for TickFrequency

namespace Tekstorm
{
	namespace Core
	{
		// Initializes a new instance of TimeSpan and sets Raw to the value indicated in val.
		TEKDECL TimeSpan::TimeSpan(long_t val)
		{
			Raw = val;
		}

		// Initializes a new instance of TimeSpan.
		TEKDECL TimeSpan::TimeSpan()
		{
			Raw = 0;
		}

		// De-initializes this instance of TimeSpan.
		TEKDECL TimeSpan::~TimeSpan()
		{
		}

		// Obtains the whole number seconds of this TimeSpan.
		TEKDECL long_t TimeSpan::GetSeconds() const
		{
			return (long_t) (Raw / (double)TimeConstants::TickFrequency);
		}

		// Obtains the whole number minutes of this TimeSpan.
		TEKDECL long_t TimeSpan::GetMinutes() const
		{
			return (long_t) (Raw * TimeConstants::InvTickFrequency * TimeConstants::InvMinuteConv);
		}

		// Obtains the number of ticks of this TimeSpan.
		TEKDECL long_t TimeSpan::GetTicks() const
		{
			return Raw;
		}

		// Obtains the real number seconds of this TimeSpan.
		TEKDECL real TimeSpan::GetRealSeconds() const
		{
			return (real)(Raw * TimeConstants::InvTickFrequency);
		}

		// Obtains the real number minutes of this TimeSpan.
		TEKDECL real TimeSpan::GetRealMinutes() const
		{
			return (real)(Raw * TimeConstants::InvTickFrequency * TimeConstants::InvMinuteConv);
		}

		// Obtains the whole number milliseconds of this TimeSpan.
		TEKDECL long_t TimeSpan::GetMilliseconds() const
		{
			return (long_t) ((Raw * TimeConstants::InvTickFrequency) * 1000.0);
		}

		// Obtains the real number milliseconds of this TimeSpan.
		TEKDECL real TimeSpan::GetRealMilliseconds() const
		{
			return (real)((Raw * TimeConstants::InvTickFrequency) * (real)1000.0);
		}

		// Adds this TimeSpan with another.
		TEKDECL TimeSpan TimeSpan::operator+(const TimeSpan& other) const
		{
			return TimeSpan(Raw + other.Raw);
		}

		// Subtracts another TimeSpan from this TimeSpan.
		TEKDECL TimeSpan TimeSpan::operator-(const TimeSpan& other) const
		{
			return TimeSpan(Raw - other.Raw);
		}

		// Negates this TimeSpan.
		TEKDECL TimeSpan TimeSpan::operator-() const
		{
			return TimeSpan(-Raw);
		}

		// Determines if this TimeSpan equals another.
		TEKDECL bool TimeSpan::operator==(const TimeSpan& other) const
		{
			return ( Raw == other.Raw );
		}

		// Determines if this TimeSpan is greater than another.
		TEKDECL bool TimeSpan::operator>(const TimeSpan& other) const
		{
			return ( Raw > other.Raw );
		}

		// Determines if this TimeSpan is less than another.
		TEKDECL bool TimeSpan::operator<(const TimeSpan& other) const
		{
			return ( Raw < other.Raw );
		}

		// Determines if this TimeSpan is greater than or equal to another.
		TEKDECL bool TimeSpan::operator>=(const TimeSpan& other) const
		{
			return ( Raw >= other.Raw );
		}

		// Determines if this TimeSpan is less than or equal to another.
		TEKDECL bool TimeSpan::operator<=(const TimeSpan& other) const
		{
			return ( Raw <= other.Raw );
		}

		// Assigns this TimeSpan a new value.
		TEKDECL TimeSpan& TimeSpan::operator=(const TimeSpan& other)
		{
			Raw = other.Raw;

			return *this;
		}
	}
}