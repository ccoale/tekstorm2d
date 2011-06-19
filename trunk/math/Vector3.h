/*
**
**
*/
#pragma once
#ifndef _TEKSTORM_MATH_VECTOR3_H
#define _TEKSTORM_MATH_VECTOR3_H
#include "../tekconfig.h"

namespace Tekstorm
{
	namespace Math
	{
		///
		/// Represents a 3-dimensional vector, using left-hand coordinate system.
		///
		class TEKAPI Vector3
		{
		public:
			///
			/// The X-component of this vector.
			///
			tekreal X;

			///
			/// The Y-component of this vector.
			///
			tekreal Y;

			///
			/// The Z-component of this vector.
			///
			tekreal Z;

			///
			/// A vector with three of its components set to one.
			///
			static const Vector3 One;

			///
			/// A unit vector for the x-axis.
			///
			static const Vector3 UnitX;

			///
			/// A unit vector for the y-axis.
			///
			static const Vector3 UnitY;

			///
			/// A unit vector for the z-axis.
			///
			static const Vector3 UnitZ;

			///
			/// A Vector with three of its components set to zero.
			///
			static const Vector3 Zero;

			///
			/// A unit-vector pointing backward.
			///
			static const Vector3 Backward;

			///
			/// A unit-vector pointing down.
			///
			static const Vector3 Down;

			///
			/// A unit-vector pointing forward.
			///
			static const Vector3 Forward;

			///
			/// A unit-vector pointing left.
			///
			static const Vector3 Left;

			///
			/// A unit-vector pointing right.
			///
			static const Vector3 Right;

			///
			/// A unit-vector poiting Up.
			///
			static const Vector3 Up;


			///
			/// Creates a new vector, initialize the components to 0.
			///
			Vector3() ;

			///
			/// Creates a new vector, given the component values.
			///
			Vector3(tekreal x, tekreal y, tekreal z) ;

			///
			/// Creates a new vector, given the component values.
			///
			Vector3(const Vector3 &other) ;

			///
			/// Creates a new vector, given an array of component values. [0] = x, [1] = y, [2] = z
			/// 
			Vector3(const tekreal values[]) ;

			///
			/// Adds the left and right vector, returning the result.
			///
			static Vector3 Add(const Vector3 &left, const Vector3 &right) ;

			///
			/// Adds the left and right vector, returning the result via pointer.
			///
			static void Add(const Vector3 &left, const Vector3 &right, Vector3 *result) ;

			///
			/// Adds the left vector and a scalar, returning the result.
			///
			static Vector3 Add(const Vector3 &left, tekreal right) ;

			///
			/// Adds the left vector and a scalar, returning the result via pointer.
			///
			static void Add(const Vector3 &left, tekreal right, Vector3 *result) ;

			///
			/// Calculates the distance between the left and right vector, returning the result.
			///
			static tekreal GetDistance(const Vector3 &left, const Vector3 &right) ;

			///
			/// Calculates the distance squared (distance^2) between the left and right vector, returning the result.
			///
			static tekreal GetDistanceSquared(const Vector3 &left, const Vector3 &right) ;

			///
			/// Divides a vector by another vector (component-wise division).
			///
			static Vector3 Divide(const Vector3 &left, const Vector3 &right) ;

			///
			/// Divides a vector by another vector (component-wise division), and returns the result via pointer.
			///
			static void Divide(const Vector3 &left, const Vector3 &right, Vector3 *result) ;

			///
			/// Divides a vector by a scalar (component-wise division).
			///
			static Vector3 Divide(const Vector3 &left, tekreal right) ;

			///
			/// Divides a vector by a scalar (component-wise division), and returns the result via pointer.
			///
			static void Divide(const Vector3 &left, tekreal right, Vector3 *result) ;

			///
			/// Calculates the dot product of two vectors.
			///
			static tekreal GetDot(const Vector3 &left, const Vector3 &right) ;

			///
			/// Calculates the cross product between two vectors.
			///
			static Vector3 GetCross(const Vector3 &left, const Vector3 &right) ;

			///
			/// Calculates the cross product between two vectors.
			///
			static void GetCross(const Vector3 &left, const Vector3 &right, Vector3 *result) ;

			///
			/// Calculates the length of this vector.
			///
			tekreal GetLength() const ;

			///
			/// Calculates the length of the given vector.
			///
			static tekreal GetLength(const Vector3 &left) ;

			///
			/// Calculates the length squared (length^2) of this vector.
			///
			tekreal GetLengthSquared() const ;

			///
			/// Calculates the length squared (length^2) of the given vector.
			///
			static tekreal GetLengthSquared(const Vector3 &left) ;

			///
			/// Multiplies a vector by another vector.
			///
			static Vector3 Multiply(const Vector3 &left, const Vector3 &right) ;

			///
			/// Multiples a vector by another vector, returning the result via pointer.
			///
			static void Multiply(const Vector3 &left, const Vector3 &right, Vector3 *result) ;

			///
			/// Multiplies a vector by a scalar.
			///
			static Vector3 Multiply(const Vector3 &left, tekreal right) ;

			///
			/// Multiplies a vector by a scalar, returning the result via pointer.
			///
			static void Multiply(const Vector3 &left, tekreal right, Vector3 *result) ;

			///
			/// Returns the negation of the given vector.
			///
			static Vector3 Negate(const Vector3 &left) ;

			///
			/// Returns the negation via pointer of the given vector.
			///
			static void Negate(const Vector3 &left, Vector3 *result) ;

			///
			/// Turns this vector into a unit vector.
			///
			void Normalize() ;

			///
			/// Returns the normalized version of the given vector.
			///
			static Vector3 Normalize(const Vector3 &left) ;

			///
			/// Returns the normalized version of the given vector via pointer.
			///
			static void Normalize(const Vector3 &left, Vector3 *result) ;

			///
			/// Reflects the given vector against the given normal.
			///
			static Vector3 Reflect(const Vector3 &vector, const Vector3 &normal) ;

			///
			/// Reflects the given vector against the given normal.
			///
			static void Reflect(const Vector3 &vector, const Vector3 &normal, Vector3 *result) ;

			///
			/// Subtracts the right vector from the left vector, returning the result.
			///
			static Vector3 Subtract(const Vector3 &left, const Vector3 &right) ;

			///
			/// Subtracts the right vector from the left vector, returning the result via pointer.
			///
			static void Subtract(const Vector3 &left, const Vector3 &right, Vector3 *result) ;

			///
			/// Subtracts the scalar from both components of the left vector.
			///
			static Vector3 Subtract(const Vector3 &left, tekreal right) ;

			///
			/// Subtracts the scalar from both components of the left vector.
			///
			static void Subtract(const Vector3 &left, tekreal right, Vector3 *result) ;

			///
			/// Adds two vectors together.
			///
			Vector3 operator+(const Vector3 &right) const ;

			///
			/// Adds a scalar to a vector.
			///
			Vector3 operator+(tekreal right) const ;

			///
			/// Adds another vector to this vector.
			///
			Vector3& operator+=(const Vector3 &right) ;

			///
			/// Adds a scalar to this vector.
			///
			Vector3& operator+=(tekreal right) ;

			///
			/// Subtracts the right vector from the left vector.
			///
			Vector3 operator-(const Vector3 &right) const ;

			///
			/// Subtracts the scalar from the left vector.
			///
			Vector3 operator-(tekreal right) const ;

			///
			/// Subtracts the right vector from this vector.
			///
			Vector3 &operator-=(const Vector3 &right) ;

			///
			/// Subtracts the scalar from this vector.
			///
			Vector3 &operator-=(tekreal right) ;

			///
			/// Multiples the left vector by the right vector using component-wise multiplication.
			///
			Vector3 operator*(const Vector3 &right) const ;

			///
			/// Multiples the left vector by the scalar.
			///
			Vector3 operator*(tekreal right) const ;

			///
			/// Multiples this vector by another vector using component-wise multiplication.
			///
			Vector3& operator*=(const Vector3 &right) ;

			///
			/// Multiplies this vector by a scalar.
			///
			Vector3& operator*=(tekreal right) ;

			///
			/// Divides the left vector by the right vector using component-wise division.
			///
			Vector3 operator/(const Vector3 &right) const ;

			///
			/// Divides the left vector by the scalar.
			///
			Vector3 operator/(tekreal right) const ;

			///
			/// Divides this vector by another vector using component-wise division.
			///
			Vector3& operator/=(const Vector3 &right) ;

			///
			/// Divides this vector by a scalar.
			///
			Vector3& operator/=(tekreal right) ;
		};
	}
}

#endif /* _TEKSTORM_MATH_VECTOR2_H */