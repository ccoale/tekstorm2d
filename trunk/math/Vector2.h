/*
**
**
*/
#pragma once
#ifndef _TEKSTORM_MATH_VECTOR2_H
#define _TEKSTORM_MATH_VECTOR2_H
#include "../tekconfig.h"

namespace Tekstorm
{
	namespace Math
	{
		///
		/// Represents a 2-dimensional vector.
		///
		class TEKAPI Vector2
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
			/// A Vector2 with both of its components set to one.
			///
			static const Vector2 One;

			///
			/// A unit vector for the x-axis.
			///
			static const Vector2 UnitX;

			///
			/// A unit vector for the y-axis.
			///
			static const Vector2 UnitY;

			///
			/// A Vector2 with both of its components set to zero.
			///
			static const Vector2 Zero;


			///
			/// Creates a new vector, initialize the components to 0.
			///
			Vector2() ;

			///
			/// Creates a new vector, given the component values.
			///
			Vector2(tekreal x, tekreal y) ;

			///
			/// Creates a new vector, given the component values.
			///
			Vector2(const Vector2 &other) ;

			///
			/// Creates a new vector, given an array of component values. [0] = x, [1] = y
			/// 
			Vector2(const tekreal values[]) ;

			///
			/// Adds the left and right vector, returning the result.
			///
			static Vector2 Add(const Vector2 &left, const Vector2 &right) ;

			///
			/// Adds the left and right vector, returning the result via pointer.
			///
			static void Add(const Vector2 &left, const Vector2 &right, Vector2 *result) ;

			///
			/// Adds the left vector and a scalar, returning the result.
			///
			static Vector2 Add(const Vector2 &left, tekreal right) ;

			///
			/// Adds the left vector and a scalar, returning the result via pointer.
			///
			static void Add(const Vector2 &left, tekreal right, Vector2 *result) ;

			///
			/// Calculates the distance between the left and right vector, returning the result.
			///
			static tekreal GetDistance(const Vector2 &left, const Vector2 &right) ;

			///
			/// Calculates the distance squared (distance^2) between the left and right vector, returning the result.
			///
			static tekreal GetDistanceSquared(const Vector2 &left, const Vector2 &right) ;

			///
			/// Divides a vector by another vector (component-wise division).
			///
			static Vector2 Divide(const Vector2 &left, const Vector2 &right) ;

			///
			/// Divides a vector by another vector (component-wise division), and returns the result via pointer.
			///
			static void Divide(const Vector2 &left, const Vector2 &right, Vector2 *result) ;

			///
			/// Divides a vector by a scalar (component-wise division).
			///
			static Vector2 Divide(const Vector2 &left, tekreal right) ;

			///
			/// Divides a vector by a scalar (component-wise division), and returns the result via pointer.
			///
			static void Divide(const Vector2 &left, tekreal right, Vector2 *result) ;

			///
			/// Calculates the dot product of two vectors.
			///
			static tekreal GetDot(const Vector2 &left, const Vector2 &right) ;

			///
			/// Calculates the length of this vector.
			///
			tekreal GetLength() const ;

			///
			/// Calculates the length of the given vector.
			///
			static tekreal GetLength(const Vector2 &left) ;

			///
			/// Calculates the length squared (length^2) of this vector.
			///
			tekreal GetLengthSquared() const ;

			///
			/// Calculates the length squared (length^2) of the given vector.
			///
			static tekreal GetLengthSquared(const Vector2 &left) ;

			///
			/// Multiplies a vector by another vector.
			///
			static Vector2 Multiply(const Vector2 &left, const Vector2 &right) ;

			///
			/// Multiples a vector by another vector, returning the result via pointer.
			///
			static void Multiply(const Vector2 &left, const Vector2 &right, Vector2 *result) ;

			///
			/// Multiplies a vector by a scalar.
			///
			static Vector2 Multiply(const Vector2 &left, tekreal right) ;

			///
			/// Multiplies a vector by a scalar, returning the result via pointer.
			///
			static void Multiply(const Vector2 &left, tekreal right, Vector2 *result) ;

			///
			/// Returns the negation of the given vector.
			///
			static Vector2 Negate(const Vector2 &left) ;

			///
			/// Returns the negation via pointer of the given vector.
			///
			static void Negate(const Vector2 &left, Vector2 *result) ;

			///
			/// Turns this vector into a unit vector.
			///
			void Normalize() ;

			///
			/// Returns the normalized version of the given vector.
			///
			static Vector2 Normalize(const Vector2 &left) ;

			///
			/// Returns the normalized version of the given vector via pointer.
			///
			static void Normalize(const Vector2 &left, Vector2 *result) ;

			///
			/// Reflects the given vector against the given normal.
			///
			static Vector2 Reflect(const Vector2 &vector, const Vector2 &normal) ;

			///
			/// Reflects the given vector against the given normal.
			///
			static void Reflect(const Vector2 &vector, const Vector2 &normal, Vector2 *result) ;

			///
			/// Subtracts the right vector from the left vector, returning the result.
			///
			static Vector2 Subtract(const Vector2 &left, const Vector2 &right) ;

			///
			/// Subtracts the right vector from the left vector, returning the result via pointer.
			///
			static void Subtract(const Vector2 &left, const Vector2 &right, Vector2 *result) ;

			///
			/// Subtracts the scalar from both components of the left vector.
			///
			static Vector2 Subtract(const Vector2 &left, tekreal right) ;

			///
			/// Subtracts the scalar from both components of the left vector.
			///
			static void Subtract(const Vector2 &left, tekreal right, Vector2 *result) ;

			///
			/// Adds two vectors together.
			///
			Vector2 operator+(const Vector2 &right) const ;

			///
			/// Adds a scalar to a vector.
			///
			Vector2 operator+(tekreal right) const ;

			///
			/// Adds another vector to this vector.
			///
			Vector2& operator+=(const Vector2 &right) ;

			///
			/// Adds a scalar to this vector.
			///
			Vector2& operator+=(tekreal right) ;

			///
			/// Subtracts the right vector from the left vector.
			///
			Vector2 operator-(const Vector2 &right) const ;

			///
			/// Subtracts the scalar from the left vector.
			///
			Vector2 operator-(tekreal right) const ;

			///
			/// Subtracts the right vector from this vector.
			///
			Vector2 &operator-=(const Vector2 &right) ;

			///
			/// Subtracts the scalar from this vector.
			///
			Vector2 &operator-=(tekreal right) ;

			///
			/// Multiples the left vector by the right vector using component-wise multiplication.
			///
			Vector2 operator*(const Vector2 &right) const ;

			///
			/// Multiples the left vector by the scalar.
			///
			Vector2 operator*(tekreal right) const ;

			///
			/// Multiples this vector by another vector using component-wise multiplication.
			///
			Vector2& operator*=(const Vector2 &right) ;

			///
			/// Multiplies this vector by a scalar.
			///
			Vector2& operator*=(tekreal right) ;

			///
			/// Divides the left vector by the right vector using component-wise division.
			///
			Vector2 operator/(const Vector2 &right) const ;

			///
			/// Divides the left vector by the scalar.
			///
			Vector2 operator/(tekreal right) const ;

			///
			/// Divides this vector by another vector using component-wise division.
			///
			Vector2& operator/=(const Vector2 &right) ;

			///
			/// Divides this vector by a scalar.
			///
			Vector2& operator/=(tekreal right) ;
		};
	}
}

#endif /* _TEKSTORM_MATH_VECTOR2_H */