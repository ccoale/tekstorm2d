#ifndef _TEKSTORM_VECTOR2_H
#define _TEKSTORM_VECTOR2_H
#include "../TekstormDecl.h"

namespace Tekstorm
{
	namespace Math
	{
		class TEKDECL Vector2
		{
		public:
			// The X and Y component of this Vector2.
			float X, Y;

			// A Vector2 with both components set to 1.
			static Vector2 One;

			// A Vector2 with both components set to 0.
			static Vector2 Zero;

			// A unit vector for the x-axis.
			static Vector2 UnitX;

			// A unit vector for the y-axis.
			static Vector2 UnitY;

			// Initializes a new instance of this Vector2 with X and Y set to 0.
			Vector2();

			// Initializes a new instance of this Vector2 with the given x and y arguments.
			Vector2(float x, float y);

			// Initializes a new instance of this Vector2 with the given scalar value.
			Vector2(float scalar);

			// Gets the length of this Vector2.
			float Length() const;

			// Gets the squared length of this Vector2.
			float LengthSquared() const;

			// Normalizes this Vector2 and returns a reference to itself.
			Vector2& Normalize();

			// Calculates the distance between this vector and another.
			float Distance(const Vector2& other) const;

			// Calculates the distance squared between this vector and another.
			float DistanceSquared(const Vector2& other) const;
			
			// Calculates the dot product between this vector and another.
			float Dot(const Vector2& other) const;

			// Clamps this vector to a specific range.
			Vector2& Clamp(const Vector2& min, const Vector2& max);

			// Performs a linear interpolation between this vector and another.
			Vector2& Lerp(const Vector2& other, float weight);

			// Returns a vector containing the maximum component out of this vector and another.
			Vector2& Max(const Vector2& other);

			// Returns a vector containing the minimum component out of this vector and another.
			Vector2& Min(const Vector2& other);

			// Determines the reflect vector given this vector and a normal.
			Vector2 Reflect(const Vector2& normal) const;

			// Interpolates between this vector and another given the weight.
			Vector2& SmoothStep(const Vector2& other, float weight);

			// Gets the length of the given Vector2.
			static float Length(const Vector2& vec);

			// Gets the squared length of the given Vector2.
			static float LengthSquared(const Vector2& vec);

			//  Normalizes the given vector and returns the result via a reference.
			static void Normalize(const Vector2& vec, Vector2& result);

			// Calculates the distance between two vectors.
			static float Distance(const Vector2& vec1, const Vector2& vec2);

			// Calculates the distance squared between two vectors.
			static float DistanceSquared(const Vector2& vec1, const Vector2& vec2);

			// Calculates the dot product between two vectors.
			static float Dot(const Vector2& vec1, const Vector2& vec2);

			// Puts a given vector into a specific range (as given by min and max) and the resulting vector is returned by reference.
			static void Clamp(const Vector2& value, const Vector2& min, const Vector2& max, Vector2& result);
			
			// Performs linear interpolation between the two given vectors, returning the new vector by reference.
			static void Lerp(const Vector2& start, const Vector2& end, float weight, Vector2& result);

			// Returns a vector containg the maximum component out of the two given vectors by reference.
			static void Max(const Vector2& vec1, const Vector2& vec2, Vector2& result);

			// Returns a vector contain the minimum component out of the two given vectors by reference.
			static void Min(const Vector2& vec1, const Vector2& vec2, Vector2& result);

			// Reflects the given vector about the given normal and returns a reflection vector via reference.
			static void Reflect(const Vector2& vec, const Vector2& normal, Vector2& result);

			// Performs linear interpolation smoothly between two vectors based on a given weight. Result is returned via a reference.
			static void SmoothStep(const Vector2& start, const Vector2& end, float weight, Vector2& result);

			// Adds two vectors together and returns the result.
			Vector2 operator+(const Vector2& other);
			Vector2& operator+=(const Vector2& other);

			// Subtracts two vectors and returns the result.
			Vector2 operator-(const Vector2& other);
			Vector2& operator-=(const Vector2& other);

			// Negates this vector and returns the result.
			Vector2 operator-();

			// Scales a vector by the given weight.
			Vector2 operator*(float weight);
			Vector2& operator*=(float weight);

			// Scales a vector by the given weight.
			Vector2 operator/(float weight);
			Vector2& operator/=(float weight);

			// Determines whether this vector is equal to another.
			bool operator==(const Vector2& other);

			// Determines whether this vector is not equal to another.
			bool operator!=(const Vector2& other);
		};
	}
}

#endif /* _TEKSTORM_VECTOR2_H */