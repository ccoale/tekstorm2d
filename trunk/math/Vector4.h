/*
**
**
*/
#pragma once
#ifndef _TEKSTORM_MATH_VECTOR4_H
#define _TEKSTORM_MATH_VECTOR4_H
#include "../tekconfig.h"

namespace Tekstorm
{
	namespace Math
	{
		///
		/// Represents a 4-dimensional vector.
		///
		class TEKAPI Vector4
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
			/// The W-component of this vector.
			///
			tekreal W;

			///
			/// A Vector4 with both of its components set to one.
			///
			static const Vector4 One;

			///
			/// A unit vector for the x-axis.
			///
			static const Vector4 UnitX;

			///
			/// A unit vector for the y-axis.
			///
			static const Vector4 UnitY;

			///
			/// A unit vector for the z-axis.
			///
			static const Vector4 UnitZ;

			///
			/// A unit vector for the W-axis.
			///
			static const Vector4 UnitW;

			///
			/// A Vector4 with both of its components set to zero.
			///
			static const Vector4 Zero;


			///
			/// Creates a new vector, initialize the components to 0.
			///
			Vector4() ;

			///
			/// Creates a new vector, given the component values.
			///
			Vector4(tekreal x, tekreal y, tekreal z, tekreal w) ;

			///
			/// Creates a new vector, given the component values.
			///
			Vector4(const Vector4 &other) ;

			///
			/// Creates a new vector, given an array of component values. [0] = x, [1] = y, [2] = z, [3] = w
			/// 
			Vector4(const tekreal values[]) ;

			///
			/// Adds the left and right vector, returning the result.
			///
			static Vector4 Add(const Vector4 &left, const Vector4 &right) ;

			///
			/// Adds the left and right vector, returning the result via pointer.
			///
			static void Add(const Vector4 &left, const Vector4 &right, Vector4 *result) ;

			///
			/// Adds the left vector and a scalar, returning the result.
			///
			static Vector4 Add(const Vector4 &left, tekreal right) ;

			///
			/// Adds the left vector and a scalar, returning the result via pointer.
			///
			static void Add(const Vector4 &left, tekreal right, Vector4 *result) ;

			///
			/// Calculates the distance between the left and right vector, returning the result.
			///
			static tekreal GetDistance(const Vector4 &left, const Vector4 &right) ;

			///
			/// Calculates the distance squared (distance^2) between the left and right vector, returning the result.
			///
			static tekreal GetDistanceSquared(const Vector4 &left, const Vector4 &right) ;

			///
			/// Divides a vector by another vector (component-wise division).
			///
			static Vector4 Divide(const Vector4 &left, const Vector4 &right) ;

			///
			/// Divides a vector by another vector (component-wise division), and returns the result via pointer.
			///
			static void Divide(const Vector4 &left, const Vector4 &right, Vector4 *result) ;

			///
			/// Divides a vector by a scalar (component-wise division).
			///
			static Vector4 Divide(const Vector4 &left, tekreal right) ;

			///
			/// Divides a vector by a scalar (component-wise division), and returns the result via pointer.
			///
			static void Divide(const Vector4 &left, tekreal right, Vector4 *result) ;

			///
			/// Calculates the dot product of two vectors.
			///
			static tekreal GetDot(const Vector4 &left, const Vector4 &right) ;

			///
			/// Calculates the length of this vector.
			///
			tekreal GetLength() const ;

			///
			/// Calculates the length of the given vector.
			///
			static tekreal GetLength(const Vector4 &left) ;

			///
			/// Calculates the length squared (length^2) of this vector.
			///
			tekreal GetLengthSquared() const ;

			///
			/// Calculates the length squared (length^2) of the given vector.
			///
			static tekreal GetLengthSquared(const Vector4 &left) ;

			///
			/// Multiplies a vector by another vector.
			///
			static Vector4 Multiply(const Vector4 &left, const Vector4 &right) ;

			///
			/// Multiples a vector by another vector, returning the result via pointer.
			///
			static void Multiply(const Vector4 &left, const Vector4 &right, Vector4 *result) ;

			///
			/// Multiplies a vector by a scalar.
			///
			static Vector4 Multiply(const Vector4 &left, tekreal right) ;

			///
			/// Multiplies a vector by a scalar, returning the result via pointer.
			///
			static void Multiply(const Vector4 &left, tekreal right, Vector4 *result) ;

			///
			/// Returns the negation of the given vector.
			///
			static Vector4 Negate(const Vector4 &left) ;

			///
			/// Returns the negation via pointer of the given vector.
			///
			static void Negate(const Vector4 &left, Vector4 *result) ;

			///
			/// Turns this vector into a unit vector.
			///
			void Normalize() ;

			///
			/// Returns the normalized version of the given vector.
			///
			static Vector4 Normalize(const Vector4 &left) ;

			///
			/// Returns the normalized version of the given vector via pointer.
			///
			static void Normalize(const Vector4 &left, Vector4 *result) ;

			///
			/// Reflects the given vector against the given normal.
			///
			static Vector4 Reflect(const Vector4 &vector, const Vector4 &normal) ;

			///
			/// Reflects the given vector against the given normal.
			///
			static void Reflect(const Vector4 &vector, const Vector4 &normal, Vector4 *result) ;

			///
			/// Subtracts the right vector from the left vector, returning the result.
			///
			static Vector4 Subtract(const Vector4 &left, const Vector4 &right) ;

			///
			/// Subtracts the right vector from the left vector, returning the result via pointer.
			///
			static void Subtract(const Vector4 &left, const Vector4 &right, Vector4 *result) ;

			///
			/// Subtracts the scalar from both components of the left vector.
			///
			static Vector4 Subtract(const Vector4 &left, tekreal right) ;

			///
			/// Subtracts the scalar from both components of the left vector.
			///
			static void Subtract(const Vector4 &left, tekreal right, Vector4 *result) ;

			///
			/// Adds two vectors together.
			///
			Vector4 operator+(const Vector4 &right) const ;

			///
			/// Adds a scalar to a vector.
			///
			Vector4 operator+(tekreal right) const ;

			///
			/// Adds another vector to this vector.
			///
			Vector4& operator+=(const Vector4 &right) ;

			///
			/// Adds a scalar to this vector.
			///
			Vector4& operator+=(tekreal right) ;

			///
			/// Subtracts the right vector from the left vector.
			///
			Vector4 operator-(const Vector4 &right) const ;

			///
			/// Subtracts the scalar from the left vector.
			///
			Vector4 operator-(tekreal right) const ;

			///
			/// Subtracts the right vector from this vector.
			///
			Vector4 &operator-=(const Vector4 &right) ;

			///
			/// Subtracts the scalar from this vector.
			///
			Vector4 &operator-=(tekreal right) ;

			///
			/// Multiples the left vector by the right vector using component-wise multiplication.
			///
			Vector4 operator*(const Vector4 &right) const ;

			///
			/// Multiples the left vector by the scalar.
			///
			Vector4 operator*(tekreal right) const ;

			///
			/// Multiples this vector by another vector using component-wise multiplication.
			///
			Vector4& operator*=(const Vector4 &right) ;

			///
			/// Multiplies this vector by a scalar.
			///
			Vector4& operator*=(tekreal right) ;

			///
			/// Divides the left vector by the right vector using component-wise division.
			///
			Vector4 operator/(const Vector4 &right) const ;

			///
			/// Divides the left vector by the scalar.
			///
			Vector4 operator/(tekreal right) const ;

			///
			/// Divides this vector by another vector using component-wise division.
			///
			Vector4& operator/=(const Vector4 &right) ;

			///
			/// Divides this vector by a scalar.
			///
			Vector4& operator/=(tekreal right) ;
		};
	}
}

#endif /* _TEKSTORM_MATH_VECTOR2_H */