#define __BUILD
#include "Vector3.h"

namespace Tekstorm
{
	namespace Math
	{
		// A Vector3 with both components set to 1.
		TEKDECL Vector3 Vector3::One = Vector3(1.0f, 1.0f, 1.0f);

		// A Vector3 with both components set to 0.
		TEKDECL Vector3 Vector3::Zero = Vector3(0.0f, 0.0f, 0.0f);

		// A unit vector for the x-axis.
		TEKDECL Vector3 Vector3::UnitX = Vector3(1.0f, 0.0f, 0.0f);

		// A unit vector for the y-axis.
		TEKDECL Vector3 Vector3::UnitY = Vector3(0.0f, 1.0f, 0.0f);

		// A unit vector for the z-axis.
		TEKDECL Vector3 Vector3::UnitZ = Vector3(0.0f, 0.0f, 1.0f);

		// Initializes a new instance of this Vector3 with X and Y and Z set to 0.
		TEKDECL Vector3::Vector3()
		{
			X = Y = Z = 0.0f;
		}

		// Initializes a new instance of this Vector3 with the given x and y and z arguments.
		TEKDECL Vector3::Vector3(float x, float y, float z)
		{
			X = x;
			Y = y;
			Z = z;
		}

		// Initializes a new instance of this Vector3 with the given values from the Vector2, setting z to 0.
		TEKDECL Vector3::Vector3(const Vector2& v)
		{
			X = v.X;
			Y = v.Y;
			Z = 0.0f;
		}

		// Initializes a new instance of this Vector3 with the given scalar value.
		TEKDECL Vector3::Vector3(float scalar)
		{
			X = Y = Z = scalar;
		}

		// Gets the length of this Vector3.
		TEKDECL float Vector3::Length() const
		{
			return (float)sqrt((X * X) + (Y * Y) + (Z * Z));
		}

		// Gets the squared length of this Vector3.
		TEKDECL float Vector3::LengthSquared() const
		{
			return (X * X) + (Y * Y) + (Z * Z);
		}

		// Normalizes this Vector3 and returns a reference to itself.
		TEKDECL Vector3& Vector3::Normalize()
		{
			// force it to be inlined
			float invLen = 1.0f / (sqrt((X * X) + (Y * Y) + (Z * Z)));

			X *= invLen;
			Y *= invLen;
			Z *= invLen;

			return *this;
		}

		// Calculates the distance between this vector and another.
		TEKDECL float Vector3::Distance(const Vector3& other) const
		{
			return (float)(sqrt(( (X - other.X)*(X - other.X) ) + ( (Y - other.Y)*(Y - other.Y) ) + ( (Z - other.Z)*(Z - other.Z) )));
		}

		// Calculates the distance squared between this vector and another.
		TEKDECL float Vector3::DistanceSquared(const Vector3& other) const
		{
			return ( (X - other.X)*(X - other.X) ) + ( (Y - other.Y)*(Y - other.Y) ) + ( (Z - other.Z)*(Z - other.Z) );
		}

		// Calculates the dot product between this vector and another.
		TEKDECL float Vector3::Dot(const Vector3& other) const
		{
			return X*other.X + Y*other.Y + Z*other.Z;
		}

		// Calculates the cross product between this vector and another.
		TEKDECL Vector3 Vector3::Cross(const Vector3& other) const
		{
			return Vector3(
				(Y * other.Z) - (Z * other.Y),
				(Z * other.X) - (X * other.Z),
				(X * other.Y) - (Y * other.X));
		}

		// Clamps this vector to a specific range.
		TEKDECL Vector3& Vector3::Clamp(const Vector3& min, const Vector3& max)
		{
			X = (X < min.X ? min.X : (X > max.X ? max.X : X));
			Y = (Y < min.Y ? min.Y : (Y > max.Y ? max.Y : Y));
			Z = (Z < min.Z ? min.Z : (Z > max.Z ? max.Z : Z));

			return *this;
		}

		// Performs a linear interpolation between this vector and another.
		TEKDECL Vector3& Vector3::Lerp(const Vector3& other, float weight)
		{
			X = X + (other.X - X) * weight;
			Y = Y + (other.Y - Y) * weight;
			Z = Z + (other.Z - Z) * weight;

			return *this;
		}

		// Returns a vector containing the maximum component out of this vector and another.
		TEKDECL Vector3& Vector3::Max(const Vector3& other)
		{
			X = (X > other.X ? X : other.X);
			Y = (Y > other.Y ? Y : other.Y);
			Z = (Z > other.Z ? Z : other.Z);

			return *this;
		}

		// Returns a vector containing the minimum component out of this vector and another.
		TEKDECL Vector3& Vector3::Min(const Vector3& other) 
		{
			X = (X < other.X ? X : other.X);
			Y = (Y < other.Y ? Y : other.Y);
			Z = (Z < other.Z ? Z : other.Z);

			return *this;
		}

		// Determines the reflect vector given this vector and a normal.
		TEKDECL Vector3 Vector3::Reflect(const Vector3& normal) const
		{
			float dot = (X * normal.X) + (Y * normal.Y) + (Z * normal.Z);
			return Vector3(X - (2.0f * dot * normal.X), Y - (2.0f * dot * normal.Y), Z - (2.0f * dot * normal.Z));
		}

		// Interpolates between this vector and another given the weight.
		TEKDECL Vector3& Vector3::SmoothStep(const Vector3& other, float weight)
		{
			weight = (weight * weight) * (3.0f - (2.0f * weight));
			X = X + (other.X - X) * weight;
			Y = Y + (other.Y - Y) * weight;
			Z = Z + (other.Z - Z) * weight;

			return *this;
		}

		// Gets the length of the given Vector3.
		TEKDECL float Vector3::Length(const Vector3& vec)
		{
			return (float)sqrt(vec.X*vec.X + vec.Y*vec.Y + vec.Z*vec.Z);
		}

		// Gets the squared length of the given Vector3.
		TEKDECL float Vector3::LengthSquared(const Vector3& vec)
		{
			return vec.X*vec.X + vec.Y*vec.Y + vec.Z*vec.Z;
		}

		//  Normalizes the given vector and returns the result via a reference.
		TEKDECL void Vector3::Normalize(const Vector3& vec, Vector3& result)
		{
			// inverse of the length
			float invLen = 1.0f / sqrt(vec.X*vec.X + vec.Y*vec.Y + vec.Z*vec.Z);

			result.X = vec.X * invLen;
			result.Y = vec.Y * invLen;
			result.Z = vec.Z * invLen;
		}

		// Calculates the distance between two vectors.
		TEKDECL float Vector3::Distance(const Vector3& vec1, const Vector3& vec2)
		{
			return (float)sqrt( (vec2.X - vec1.X)*(vec2.X - vec1.X) + (vec2.Y - vec1.Y)*(vec2.Y - vec1.Y) + (vec2.Z - vec1.Z)*(vec2.Z - vec1.Z) );
		}

		// Calculates the distance squared between two vectors.
		TEKDECL float Vector3::DistanceSquared(const Vector3& vec1, const Vector3& vec2)
		{
			return (vec2.X - vec1.X)*(vec2.X - vec1.X) + (vec2.Y - vec1.Y)*(vec2.Y - vec1.Y) + (vec2.Z - vec1.Z)*(vec2.Z - vec1.Z);
		}

		// Calculates the dot product between two vectors.
		TEKDECL float Vector3::Dot(const Vector3& vec1, const Vector3& vec2)
		{
			return vec1.X*vec2.X + vec1.Y*vec2.Y + vec1.Z*vec2.Z;
		}

		// Calculates the cross product between two vectors.
		TEKDECL void Vector3::Cross(const Vector3& vec1, const Vector3 &vec2, Vector3& result)
		{
			result.X = (vec1.Y * vec2.Z) - (vec1.Z * vec2.Y);
			result.Y = (vec1.Z * vec2.X) - (vec1.X * vec2.Z);
			result.Z = (vec1.X * vec2.Y) - (vec1.Y * vec2.X);
		}

		// Puts a given vector into a specific range (as given by min and max) and the resulting vector is returned by reference.
		TEKDECL void Vector3::Clamp(const Vector3& value, const Vector3& min, const Vector3& max, Vector3& result)
		{
			result.X = (value.X < min.X ? min.X : (value.X > max.X ? max.X : value.X));
			result.Y = (value.Y < min.Y ? min.Y : (value.Y > max.Y ? max.Y : value.Y));
			result.Z = (value.Z < min.Z ? min.Z : (value.Z > max.Z ? max.Z : value.Z));
		}

		// Performs linear interpolation between the two given vectors, returning the new vector by reference.
		TEKDECL void Vector3::Lerp(const Vector3& start, const Vector3& end, float weight, Vector3& result)
		{
			result.X = start.X + (end.X - start.X) * weight;
			result.Y = start.Y + (end.Y - start.Y) * weight;
			result.Z = start.Z + (end.Z - start.Z) * weight;
		}

		// Returns a vector containg the maximum component out of the two given vectors by reference.
		TEKDECL void Vector3::Max(const Vector3& vec1, const Vector3& vec2, Vector3& result)
		{
			result.X = (vec1.X > vec2.X ? vec1.X : vec2.X);
			result.Y = (vec1.Y > vec2.Y ? vec1.Y : vec2.Y);
			result.Z = (vec1.Z > vec2.Z ? vec1.Z : vec2.Z);
		}

		// Returns a vector contain the minimum component out of the two given vectors by reference.
		TEKDECL void Vector3::Min(const Vector3& vec1, const Vector3& vec2, Vector3& result)
		{
			result.X = (vec1.X < vec2.X ? vec1.X : vec2.X);
			result.Y = (vec1.Y < vec2.Y ? vec1.Y : vec2.Y);
			result.Z = (vec1.Z < vec2.Z ? vec1.Z : vec2.Z);
		}

		// Reflects the given vector about the given normal and returns a reflection vector via reference.
		TEKDECL void Vector3::Reflect(const Vector3& vec, const Vector3& normal, Vector3& result)
		{
			float dot = vec.X*normal.X + vec.Y*normal.Y + vec.Z*normal.Z;
			result.X = vec.X - (2.0f * dot * normal.X);
			result.Y = vec.Y - (2.0f * dot * normal.Y);
			result.Z = vec.Z - (2.0f * dot * normal.Z);
		}

		// Performs linear interpolation smoothly between two vectors based on a given weight. Result is returned via a reference.
		TEKDECL void Vector3::SmoothStep(const Vector3& start, const Vector3& end, float weight, Vector3& result)
		{
			weight = (weight * weight) * (3.0f - (2.0f * weight));
			result.X = start.X + (end.X - start.X) * weight;
			result.Y = start.Y + (end.Y - start.Y) * weight;
			result.Z = start.Z + (end.Z - start.Z) * weight;
		}

		// Adds two vectors together and returns the result.
		TEKDECL Vector3 Vector3::operator+(const Vector3& other)
		{
			return Vector3(X + other.X, Y + other.Y, Z + other.Z);
		}

		TEKDECL Vector3& Vector3::operator+=(const Vector3& other)
		{
			X += other.X;
			Y += other.Y;
			Z += other.Z;
			return *this;
		}

		// Subtracts two vectors and returns the result.
		TEKDECL Vector3 Vector3::operator-(const Vector3& other)
		{
			return Vector3(X - other.X, Y - other.Y, Z - other.Z);
		}

		TEKDECL Vector3& Vector3::operator-=(const Vector3& other)
		{
			X -= other.X;
			Y -= other.Y;
			Z -= other.Z;
			return *this;
		}

		// Negates this vector and returns the result.
		TEKDECL Vector3 Vector3::operator-()
		{
			return Vector3(-X, -Y, -Z);
		}

		// Scales a vector by the given weight.
		TEKDECL Vector3 Vector3::operator*(float weight)
		{
			return Vector3(X * weight, Y * weight, Z * weight);
		}

		TEKDECL Vector3& Vector3::operator*=(float weight)
		{
			X *= weight;
			Y *= weight;
			Z *= weight;

			return *this;
		}

		// Scales a vector by the given weight.
		TEKDECL Vector3 Vector3::operator/(float weight)
		{
			return Vector3(X / weight, Y / weight, Z / weight);
		}


		TEKDECL Vector3& Vector3::operator/=(float weight)
		{
			X /= weight;
			Y /= weight;
			Z /= weight;

			return *this;
		}

		// Determines whether this vector is equal to another.
		TEKDECL bool Vector3::operator==(const Vector3& other)
		{
			return (X == other.X) && (Y == other.Y) && (Z == other.Z);
		}

		// Determines whether this vector is not equal to another.
		TEKDECL bool Vector3::operator!=(const Vector3& other)
		{
			return (X != other.X) || (Y != other.Y) || (Z != other.Z);
		}
	}
}