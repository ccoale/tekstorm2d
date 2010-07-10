#define __BUILD
#include "Vector2.h"

namespace Tekstorm
{
	namespace Math
	{
		// A Vector2 with both components set to 1.
		TEKDECL Vector2 Vector2::One = Vector2(1.0f, 1.0f);

		// A Vector2 with both components set to 0.
		TEKDECL Vector2 Vector2::Zero = Vector2(0.0f, 0.0f);

		// A unit vector for the x-axis.
		TEKDECL Vector2 Vector2::UnitX = Vector2(1.0f, 0.0f);

		// A unit vector for the y-axis.
		TEKDECL Vector2 Vector2::UnitY = Vector2(0.0f, 1.0f);

		// Initializes a new instance of this Vector2 with X and Y set to 0.
		TEKDECL Vector2::Vector2()
		{
			X = Y = 0.0f;
		}

		// Initializes a new instance of this Vector2 with the given x and y arguments.
		TEKDECL Vector2::Vector2(float x, float y)
		{
			X = x;
			Y = y;
		}

		// Initializes a new instance of this Vector2 with the given scalar value.
		TEKDECL Vector2::Vector2(float scalar)
		{
			X = Y = scalar;
		}

		// Gets the length of this Vector2.
		TEKDECL float Vector2::Length() const
		{
			return (float)sqrt((X * X) + (Y * Y));
		}

		// Gets the squared length of this Vector2.
		TEKDECL float Vector2::LengthSquared() const
		{
			return (X * X) + (Y * Y);
		}

		// Normalizes this Vector2 and returns a reference to itself.
		TEKDECL Vector2& Vector2::Normalize()
		{
			// force it to be inlined
			float invLen = 1.0f / (sqrt((X * X) + (Y * Y)));

			X *= invLen;
			Y *= invLen;
			return *this;
		}

		// Calculates the distance between this vector and another.
		TEKDECL float Vector2::Distance(const Vector2& other) const
		{
			return (float)(sqrt(( (X - other.X)*(X - other.X) ) + ( (Y - other.Y)*(Y - other.Y) )));
		}

		// Calculates the distance squared between this vector and another.
		TEKDECL float Vector2::DistanceSquared(const Vector2& other) const
		{
			return ( (X - other.X)*(X - other.X) ) + ( (Y - other.Y)*(Y - other.Y) );
		}

		// Calculates the dot product between this vector and another.
		TEKDECL float Vector2::Dot(const Vector2& other) const
		{
			return X*other.X + Y*other.Y;
		}

		// Clamps this vector to a specific range.
		TEKDECL Vector2& Vector2::Clamp(const Vector2& min, const Vector2& max)
		{
			X = (X < min.X ? min.X : (X > max.X ? max.X : X));
			Y = (Y < min.Y ? min.Y : (Y > max.Y ? max.Y : Y));

			return *this;
		}

		// Performs a linear interpolation between this vector and another.
		TEKDECL Vector2& Vector2::Lerp(const Vector2& other, float weight)
		{
			X = X + (other.X - X) * weight;
			Y = Y + (other.Y - Y) * weight;

			return *this;
		}

		// Returns a vector containing the maximum component out of this vector and another.
		TEKDECL Vector2& Vector2::Max(const Vector2& other)
		{
			X = (X > other.X ? X : other.X);
			Y = (Y > other.Y ? Y : other.Y);

			return *this;
		}

		// Returns a vector containing the minimum component out of this vector and another.
		TEKDECL Vector2& Vector2::Min(const Vector2& other) 
		{
			X = (X < other.X ? X : other.X);
			Y = (Y < other.Y ? Y : other.Y);

			return *this;
		}

		// Determines the reflect vector given this vector and a normal.
		TEKDECL Vector2 Vector2::Reflect(const Vector2& normal) const
		{
			float dot = (X * normal.X) + (Y * normal.Y);
			return Vector2(X - (2.0f * dot * normal.X), Y - (2.0f * dot * normal.Y));
		}

		// Interpolates between this vector and another given the weight.
		TEKDECL Vector2& Vector2::SmoothStep(const Vector2& other, float weight)
		{
			weight = (weight * weight) * (3.0f - (2.0f * weight));
			X = X + (other.X - X) * weight;
			Y = Y + (other.Y - Y) * weight;

			return *this;
		}

		// Gets the length of the given Vector2.
		TEKDECL float Vector2::Length(const Vector2& vec)
		{
			return (float)sqrt(vec.X*vec.X + vec.Y*vec.Y);
		}

		// Gets the squared length of the given Vector2.
		TEKDECL float Vector2::LengthSquared(const Vector2& vec)
		{
			return vec.X*vec.X + vec.Y*vec.Y;
		}

		//  Normalizes the given vector and returns the result via a reference.
		TEKDECL void Vector2::Normalize(const Vector2& vec, Vector2& result)
		{
			// inverse of the length
			float invLen = 1.0f / sqrt(vec.X*vec.X + vec.Y*vec.Y);

			result.X = vec.X * invLen;
			result.Y = vec.Y * invLen;
		}

		// Calculates the distance between two vectors.
		TEKDECL float Vector2::Distance(const Vector2& vec1, const Vector2& vec2)
		{
			return (float)sqrt( (vec2.X - vec1.X)*(vec2.X - vec1.X) + (vec2.Y - vec1.Y)*(vec2.Y - vec1.Y) );
		}

		// Calculates the distance squared between two vectors.
		TEKDECL float Vector2::DistanceSquared(const Vector2& vec1, const Vector2& vec2)
		{
			return (vec2.X - vec1.X)*(vec2.X - vec1.X) + (vec2.Y - vec1.Y)*(vec2.Y - vec1.Y);
		}

		// Calculates the dot product between two vectors.
		TEKDECL float Vector2::Dot(const Vector2& vec1, const Vector2& vec2)
		{
			return vec1.X*vec2.X + vec1.Y*vec2.Y;
		}

		// Puts a given vector into a specific range (as given by min and max) and the resulting vector is returned by reference.
		TEKDECL void Vector2::Clamp(const Vector2& value, const Vector2& min, const Vector2& max, Vector2& result)
		{
			result.X = (value.X < min.X ? min.X : (value.X > max.X ? max.X : value.X));
			result.Y = (value.Y < min.Y ? min.Y : (value.Y > max.Y ? max.Y : value.Y));
		}

		// Performs linear interpolation between the two given vectors, returning the new vector by reference.
		TEKDECL void Vector2::Lerp(const Vector2& start, const Vector2& end, float weight, Vector2& result)
		{
			result.X = start.X + (end.X - start.X) * weight;
			result.Y = start.Y + (end.Y - start.Y) * weight;
		}

		// Returns a vector containg the maximum component out of the two given vectors by reference.
		TEKDECL void Vector2::Max(const Vector2& vec1, const Vector2& vec2, Vector2& result)
		{
			result.X = (vec1.X > vec2.X ? vec1.X : vec2.X);
			result.Y = (vec1.Y > vec2.Y ? vec1.Y : vec2.Y);
		}

		// Returns a vector contain the minimum component out of the two given vectors by reference.
		TEKDECL void Vector2::Min(const Vector2& vec1, const Vector2& vec2, Vector2& result)
		{
			result.X = (vec1.X < vec2.X ? vec1.X : vec2.X);
			result.Y = (vec1.Y < vec2.Y ? vec1.Y : vec2.Y);
		}

		// Reflects the given vector about the given normal and returns a reflection vector via reference.
		TEKDECL void Vector2::Reflect(const Vector2& vec, const Vector2& normal, Vector2& result)
		{
			float dot = vec.X*normal.X + vec.Y*normal.Y;
			result.X = vec.X - (2.0f * dot * normal.X);
			result.Y = vec.Y - (2.0f * dot * normal.Y);
		}

		// Performs linear interpolation smoothly between two vectors based on a given weight. Result is returned via a reference.
		TEKDECL void Vector2::SmoothStep(const Vector2& start, const Vector2& end, float weight, Vector2& result)
		{
			weight = (weight * weight) * (3.0f - (2.0f * weight));
			result.X = start.X + (end.X - start.X) * weight;
			result.Y = start.Y + (end.Y - start.Y) * weight;
		}

		// Adds two vectors together and returns the result.
		TEKDECL Vector2 Vector2::operator+(const Vector2& other)
		{
			return Vector2(X + other.X, Y + other.Y);
		}

		TEKDECL Vector2& Vector2::operator+=(const Vector2& other)
		{
			X += other.X;
			Y += other.Y;
			
			return *this;
		}

		// Subtracts two vectors and returns the result.
		TEKDECL Vector2 Vector2::operator-(const Vector2& other)
		{
			return Vector2(X - other.X, Y - other.Y);
		}

		TEKDECL Vector2& Vector2::operator-=(const Vector2& other)
		{
			X -= other.X;
			Y -= other.Y;

			return *this;
		}

		// Negates this vector and returns the result.
		TEKDECL Vector2 Vector2::operator-()
		{
			return Vector2(-X, -Y);
		}

		// Scales a vector by the given weight.
		TEKDECL Vector2 Vector2::operator*(float weight)
		{
			return Vector2(X * weight, Y * weight);
		}

		TEKDECL Vector2& Vector2::operator*=(float weight)
		{
			X *= weight;
			Y *= weight;

			return *this;
		}

		// Scales a vector by the given weight.
		TEKDECL Vector2 Vector2::operator/(float weight)
		{
			return Vector2(X / weight, Y / weight);
		}


		TEKDECL Vector2& Vector2::operator/=(float weight)
		{
			X /= weight;
			Y /= weight;

			return *this;
		}

		// Determines whether this vector is equal to another.
		TEKDECL bool Vector2::operator==(const Vector2& other)
		{
			return (X == other.X) && (Y == other.Y);
		}

		// Determines whether this vector is not equal to another.
		TEKDECL bool Vector2::operator!=(const Vector2& other)
		{
			return (X != other.X) || (Y != other.Y);
		}
	}
}