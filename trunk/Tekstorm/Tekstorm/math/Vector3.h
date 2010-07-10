#ifndef _TEKSTORM_Vector3_H
#define _TEKSTORM_Vector3_H
#include "../TekstormDecl.h"
#include "Vector2.h"

namespace Tekstorm
{
	namespace Math
	{
		class TEKDECL Vector3
		{
		public:
			// The X and Y and Z component of this Vector3.
			float X, Y, Z;

			// A Vector3 with both components set to 1.
			static Vector3 One;

			// A Vector3 with both components set to 0.
			static Vector3 Zero;

			// A unit vector for the x-axis.
			static Vector3 UnitX;

			// A unit vector for the y-axis.
			static Vector3 UnitY;

			// A unit vector for the z-axis.
			static Vector3 UnitZ;

			// Initializes a new instance of this Vector3 with X and Y and Z set to 0.
			Vector3();

			// Initializes a new instance of this Vector3 with the given x and y and z arguments.
			Vector3(float x, float y, float z);

			// Initializes a new instance of this Vector3 with the given values from the Vector2, setting z to 0.
			Vector3(const Vector2& v);

			// Initializes a new instance of this Vector3 with the given scalar value.
			Vector3(float scalar);

			// Gets the length of this Vector3.
			float Length() const;

			// Gets the squared length of this Vector3.
			float LengthSquared() const;

			// Normalizes this Vector3 and returns a reference to itself.
			Vector3& Normalize();

			// Calculates the distance between this vector and another.
			float Distance(const Vector3& other) const;

			// Calculates the distance squared between this vector and another.
			float DistanceSquared(const Vector3& other) const;
			
			// Calculates the dot product between this vector and another.
			float Dot(const Vector3& other) const;

			// Calculates the cross product between this vector and another.
			Vector3 Cross(const Vector3& other) const;

			// Clamps this vector to a specific range.
			Vector3& Clamp(const Vector3& min, const Vector3& max);

			// Performs a linear interpolation between this vector and another.
			Vector3& Lerp(const Vector3& other, float weight);

			// Returns a vector containing the maximum component out of this vector and another.
			Vector3& Max(const Vector3& other);

			// Returns a vector containing the minimum component out of this vector and another.
			Vector3& Min(const Vector3& other);

			// Determines the reflect vector given this vector and a normal.
			Vector3 Reflect(const Vector3& normal) const;

			// Interpolates between this vector and another given the weight.
			Vector3& SmoothStep(const Vector3& other, float weight);

			// Gets the length of the given Vector3.
			static float Length(const Vector3& vec);

			// Gets the squared length of the given Vector3.
			static float LengthSquared(const Vector3& vec);

			//  Normalizes the given vector and returns the result via a reference.
			static void Normalize(const Vector3& vec, Vector3& result);

			// Calculates the distance between two vectors.
			static float Distance(const Vector3& vec1, const Vector3& vec2);

			// Calculates the distance squared between two vectors.
			static float DistanceSquared(const Vector3& vec1, const Vector3& vec2);

			// Calculates the dot product between two vectors.
			static float Dot(const Vector3& vec1, const Vector3& vec2);

			// Calculates the cross product between two vectors.
			static void Cross(const Vector3& vec1, const Vector3 &vec2, Vector3& result);

			// Puts a given vector into a specific range (as given by min and max) and the resulting vector is returned by reference.
			static void Clamp(const Vector3& value, const Vector3& min, const Vector3& max, Vector3& result);
			
			// Performs linear interpolation between the two given vectors, returning the new vector by reference.
			static void Lerp(const Vector3& start, const Vector3& end, float weight, Vector3& result);

			// Returns a vector containg the maximum component out of the two given vectors by reference.
			static void Max(const Vector3& vec1, const Vector3& vec2, Vector3& result);

			// Returns a vector contain the minimum component out of the two given vectors by reference.
			static void Min(const Vector3& vec1, const Vector3& vec2, Vector3& result);

			// Reflects the given vector about the given normal and returns a reflection vector via reference.
			static void Reflect(const Vector3& vec, const Vector3& normal, Vector3& result);

			// Performs linear interpolation smoothly between two vectors based on a given weight. Result is returned via a reference.
			static void SmoothStep(const Vector3& start, const Vector3& end, float weight, Vector3& result);

			// Adds two vectors together and returns the result.
			Vector3 operator+(const Vector3& other);
			Vector3& operator+=(const Vector3& other);

			// Subtracts two vectors and returns the result.
			Vector3 operator-(const Vector3& other);
			Vector3& operator-=(const Vector3& other);

			// Negates this vector and returns the result.
			Vector3 operator-();

			// Scales a vector by the given weight.
			Vector3 operator*(float weight);
			Vector3& operator*=(float weight);

			// Scales a vector by the given weight.
			Vector3 operator/(float weight);
			Vector3& operator/=(float weight);

			// Determines whether this vector is equal to another.
			bool operator==(const Vector3& other);

			// Determines whether this vector is not equal to another.
			bool operator!=(const Vector3& other);
		};
	}
}

#endif /* _TEKSTORM_Vector3_H */