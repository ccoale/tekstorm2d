/*
**	This header file declares the Vector3 class. It is a 
** three dimensional (component) mathematical vector.
*/
#pragma once
#ifndef _TEKSTORM_VECTOR3_H
#define _TEKSTORM_VECTOR3_H
#include "Vector2.h"

namespace Tekstorm
{
	/* 
	**	This is the root Math namespace. It contains all classes, data-structures,
	** constants, and functions related to mathematical aspects of this game engine.
	*/
	namespace Math
	{
		class TEKAPI Vector2;
		class TEKAPI Vector4;
		class TEKAPI Quaternion;
		class TEKAPI Matrix3;
		class TEKAPI Matrix4;
		
		/* 
		** This is a three-dimensional Vector.
		*/
		class TEKAPI Vector3
		{
		public:
			/* The X-component of this Vector3 class. */
			real X;

			/* The Y-component of this Vector3 class. */
			real Y;

			/* The Z-component of this Vector3 class. */
			real Z;

			/* The size, in bytes, of this Vector3 class. */
			static const int SizeInBytes;

			/* A static Vector3 whose components are all 0. */
			static const Vector3 Zero;

			/* A static Vector3 whose components are all 1. */
			static const Vector3 One;

			/* A static Vector3 whose X-component is 1 and Y-component is 0 and Z-component is 0. */
			static const Vector3 UnitX;

			/* A static Vector3 whose X-component is 0 and Y-component is 1 and Z-component is 0. */
			static const Vector3 UnitY;

			/* A static Vector3 whose X-component is 0, Y-component is 0, and Z-component is 1. */
			static const Vector3 UnitZ;

			/*
			** Initializes a new instance of Vector3 class.
			** Parameters
			**	none
			** Returns
			**	none
			*/
			Vector3() : X((real)0.0), Y((real)0.0), Z((real)0.0)
			{
			}

			/*
			** Initializes a new instance of the Vector3 class.
			** Parameters
			**	value	- the value to X, Y, and Z to.
			** Returns
			**	nothing
			*/
			Vector3(real value) : X(value), Y(value), Z(value)
			{
			}

			/*
			** Initializes a new instance of the Vector3 class.
			** Parameters
			**	x		- the value to set X to.
			**	y		- the value to set Y to.
			**	z		- the value to set Z to.
			** Returns
			**	nothing
			*/
			Vector3(real x, real y, real z) : X(x), Y(y), Z(z)
			{
			}

			/*
			** Initializes a new instance of the Vector3 class.
			** Parameters
			**	xy		- the Vector2 to set XY to.
			**	z		- the value to set Z to.
			** Returns
			**	nothing
			*/
			Vector3(const Vector2 &xy, real z) : X(xy.X), Y(xy.Y), Z(z)
			{
			}

			/*
			** Initializes a new instance of the Vector3 class.
			** Parameters
			**	arr		- a two element array of type real.
			**			- the X component is set to the value of arr[0]
			**			- the Y component is set to the value of arr[1]
			**			- the Z component is set to the value of arr[2]
			** Returns
			**	nothing
			*/
			Vector3(const real arr[]) : X(arr[0]), Y(arr[1]), Z(arr[2])
			{
			}
			
			/*
			** Initializes a new instance of the Vector3 class.
			** Parameters
			**	other	- another Vector3 to copy the X and Y and Z components from.
			** Returns
			**	nothing
			*/
			Vector3(const Vector3 &other) : X(other.X), Y(other.Y), Z(other.Z)
			{
			}

			/*
			** Determines whether or not this Vector3 is normalized.
			** Parameters
			**	none
			** Returns
			**	True if this Vector3 is normalized.
			*/
			bool IsNormalized() const
			{
				return (CommonUtils::Abs((real)(X*X + Y*Y + Z*Z) - 1) < TEKSTORM_REAL_EPSILON);
			}

			/*
			** Calculates the length of this Vector3.
			** Parameters
			**	none
			** Returns
			**	The length of this Vector3.
			**	Length is calculated as sqrt(x^2 + y^2 + z^2).
			*/
			real GetLength() const
			{
				return (real)sqrt(X*X + Y*Y + Z*Z);
			}

			/*
			** Calculates the squared length of this Vector3.
			** Parameters
			**	none
			** Returns
			**	The length of this Vector3 squared.
			**	Length squared is calculated as x^2 + y^2 + z^2.
			*/
			real GetLengthSquared() const
			{
				return X*X + Y*Y + Z*Z;
			}

			/*
			** Normalizes this Vector3.
			** Parameters
			**	none
			** Returns
			**	nothing
			*/
			void Normalize()
			{
				real len = GetLength();
				if (len > TEKSTORM_REAL_EPSILON) // make sure we don't divide by 0
				{
					real inv = (real)1.0 / len;
					X *= inv;
					Y *= inv;
					Z *= inv;
				}
			}

			/*
			** Adds two Vector3 objects together.
			** Parameters
			**	left	- the left Vector3 used in addition
			**	right	- the right Vector3 used in addition
			**	result	- a reference to a Vector3 that will store the result
			** Returns
			**	nothing
			*/
			static void Add(const Vector3 &left, const Vector3 &right, Vector3 &result)
			{
				result.X = left.X + right.X;
				result.Y = left.Y + right.Y;
				result.Z = left.Z + right.Z;
			}

			/*
			** Adds two Vector3 objects together.
			** Parameters
			**	left	- the left Vector3 used in addition
			**	right	- the right Vector3 used in addition
			** Returns
			**	the result of adding left and right together.
			*/
			static Vector3 Add(const Vector3 &left, const Vector3 &right)
			{
				return Vector3(left.X + right.X, left.Y + right.Y, left.Z + right.Z);
			}

			/*
			** Subtracts two Vector3 objects.
			** Parameters
			**	left	- the left Vector3 used in subtraction
			**	right	- the right Vector3 used in subtraction
			**	result	- a reference to a Vector3 object that will store the result
			** Returns
			**	nothing
			*/
			static void Subtract(const Vector3 &left, const Vector3 &right, Vector3 &result)
			{
				result.X = left.X - right.X;
				result.Y = left.Y - right.Y;
				result.Z = left.Z - right.Z;
			}

			/*
			** Subtracts two Vector3 objects.
			** Parameters
			**	left	- the left Vector3 used in subtraction
			**	right	- the right Vector3 used in subtraction
			** Returns
			**	the result of the subtraction.
			*/
			static Vector3 Subtract(const Vector3 &left, const Vector3 &right)
			{
				return Vector3(left.X - right.X, left.Y - right.Y, left.Z - right.Z);
			}

			/*
			** Multiplies a Vector3 object by a scalar.
			** Parameters
			**	value	- the Vector3 used in multiplication
			**	scale	- the scalar value to be used
			**	result	- a reference to a Vector3 object to store the result
			** Returns
			**	nothing
			*/
			static void Multiply(const Vector3 &value, real scale, Vector3 &result)
			{
				result.X = value.X * scale;
				result.Y = value.Y * scale;
				result.Z = value.Z * scale;
			}

			/*
			** Multiplies a Vector3 object by a scalar.
			** Parameters
			**	value	- the Vector3 used in multiplication
			**	scale	- the scalar used 
			** Returns
			**	the result of multiplying value by scale.
			*/
			static Vector3 Multiply(const Vector3 &value, real scale)
			{
				return Vector3(value.X * scale, value.Y * scale, value.Z * scale);
			}

			/*
			** Modulates a vector with another vector by performing component-wise multiplication.
			** Parameters
			**	left	- the left Vector3 used in modulation
			**	right	- the right Vector3 used in modulation
			**	result	- a reference to a Vector3 that will store the result
			** Returns
			**	nothing
			*/
			static void Modulate(const Vector3 &left, const Vector3 &right, Vector3 &result)
			{
				result.X = left.X * right.X;
				result.Y = left.Y * right.Y;
				result.Z = left.Z * right.Z;
			}

			/*
			** Modulates a vector with another vector by performing component-wise multiplication.
			** Parameters
			**	left	- the left Vector3 used in modulation
			**	right	- the right Vector3 used in modulation
			** Returns
			**	a Vector2 containing the result of modulation.
			*/
			static Vector3 Modulate(const Vector3 &left, const Vector3 &right)
			{
				return Vector3(left.X * right.X, left.Y * right.Y, left.Z * right.Z);
			}

			/*
			** Divides each component of this vector with the given scalar value.
			** Parameters
			**	value	- the Vector3 that will be divided
			**	scale	- the scalar value to divide by
			**	result	- a reference to a Vector3 that will store the result
			** Returns
			**	nothing
			*/
			static void Divide(const Vector3 &value, real scale, Vector3 &result)
			{
				result.X = value.X / scale;
				result.Y = value.Y / scale;
				result.Z = value.Z / scale;
			}

			/*
			** Divides each component of this vector with the given scalar value.
			** Parameters
			**	value	- the Vector3 that will be divided
			**	scale	- the scalar value to divide by
			** Returns
			**	a Vector3 containing the result of the division.
			*/
			static Vector3 Divide(const Vector3 &value, real scale)
			{
				return Vector3(value.X / scale, value.Y / scale, value.Z / scale);
			}

			/*
			** Negates each component of a vector.
			** Parameters
			**	value	- the Vector3 that should be negated
			**	result	- a reference to a Vector3 that will store the result
			** Returns
			**	nothing
			*/
			static void Negate(const Vector3 &value, Vector3 &result)
			{
				result.X = -value.X;
				result.Y = -value.Y;
				result.Z = -value.Z;
			}

			/*
			** Negates each component of a vector.
			** Parameters
			**	value	- the Vector3 that should be negated
			** Returns
			**	the negated version of 'value'.
			*/
			static Vector3 Negate(const Vector3 &value)
			{
				return Vector3(-value.X, -value.Y, -value.Z);
			}

			/*
			** Takes the absolute value of each component.
			** Parameters
			**	value	- the Vector3 to take the absolute value of
			**	result	- a reference to a Vector3 that will store the result
			** Returns
			**	nothing
			*/
			static void Abs(const Vector3 &value, Vector3 &result)
			{
				result.X = CommonUtils::Abs(value.X);
				result.Y = CommonUtils::Abs(value.Y);
				result.Z = CommonUtils::Abs(value.Z);
			}

			/*
			** Takes the absolute value of each component.
			** Parameters
			**	value	- the Vector3 to take the absolute value of
			** Returns
			**	the absolute value version of 'value'.
			*/
			static Vector3 Abs(const Vector3 &value)
			{
				return Vector3((real)CommonUtils::Abs(value.X), (real)CommonUtils::Abs(value.Y), 
					(real)CommonUtils::Abs(value.Z));
			}

			/*
			** Returns a Vector3 containing the 2D cartesian coordinates of a point
			**	specified in Barycentric coordinates relative to a 3D triangle.
			** Parameters
			**	value1	- A Vector3 containing the 3D cartesian coordinates of vertex1 of the triangle.
			**	value2	- A Vector3 containing the 3D cartesian coordinates of vertex2 of the triangle.
			**	value3	- A Vector3 containing the 3D cartesian coordinates of vertex3 of the triangle.
			**	amount1	- Barycentric coordinate b2, which expresses the weighting factor toward vertex 2.
			**	amount2	- Barycentric coordinate b3, which expresses the weighting factor toward vertex 3.
			**	result	- A reference to a Vector3 which will store the 3D cartesian coordinates.
			** Returns
			**	nothing
			*/
			static void Barycentric(const Vector3 &value1, const Vector3 &value2, const Vector3 &value3,
				real amount1, real amount2, Vector3 &result)
			{
				result.X = (value1.X + (amount1 * (value2.X - value1.X))) + (amount2 * (value3.X - value1.X));
				result.Y = (value1.Y + (amount1 * (value2.Y - value1.Y))) + (amount2 * (value3.Y - value1.Y));
				result.Z = (value1.Z + (amount1 * (value2.Z - value1.Z))) + (amount2 * (value3.Z - value1.Z));
			}

			/*
			** Returns a Vector3 containing the 3D cartesian coordinates of a point
			**	specified in Barycentric coordinates relative to a 3D triangle.
			** Parameters
			**	value1	- A Vector3 containing the 3D cartesian coordinates of vertex1 of the triangle.
			**	value2	- A Vector3 containing the 3D cartesian coordinates of vertex2 of the triangle.
			**	value3	- A Vector3 containing the 3D cartesian coordinates of vertex3 of the triangle.
			**	amount1	- Barycentric coordinate b2, which expresses the weighting factor toward vertex 2.
			**	amount2	- Barycentric coordinate b3, which expresses the weighting factor toward vertex 3.
			** Returns
			**	a Vector3 which holds the 3D cartesian coordinates.
			*/
			static Vector3 Barycentric(const Vector3 &value1, const Vector3 &value2, const Vector3 &value3,
				real amount1, real amount2)
			{
				return Vector3((value1.X + (amount1 * (value2.X - value1.X))) + (amount2 * (value3.X - value1.X)),
                (value1.Y + (amount1 * (value2.Y - value1.Y))) + (amount2 * (value3.Y - value1.Y)),
				(value1.Z + (amount1 * (value2.Z - value1.Z))) + (amount2 * (value3.Z - value1.Z)));
			}

			/*
			** Restricts a value to be within a specified range.
			** Parameters
			**	value	- The value to clamp
			**	min		- The minimum value
			**	max		- The maximum value
			**	result	- A reference to a Vector3 which will store the clamped value.
			** Returns
			**	nothing
			*/
			static void Clamp(const Vector3 &value, const Vector3 &min, const Vector3 &max, Vector3 &result)
			{
				real x = value.X;
				x = (x > max.X) ? max.X : x;
				x = (x < min.X) ? min.X : x;

				real y = value.Y;
				y = (y > max.Y) ? max.Y : y;
				y = (y < min.Y) ? min.Y : y;

				real z = value.Z;
				z = (z > max.Z) ? max.Z : z;
				z = (z < min.Z) ? min.Z : z;

				result.X = x;
				result.Y = y;
				result.Z = z;
			}

			/*
			** Restricts a value to be within a specified range.
			** Parameters
			**	value	- The value to clamp
			**	min		- The minimum value
			**	max		- The maximum value
			** Returns
			**	a Vector3 whose components are within the min and max range.
			*/
			static Vector3 Clamp(const Vector3 &value, const Vector3 &min, const Vector3 &max)
			{
				real x = value.X;
				x = (x > max.X) ? max.X : x;
				x = (x < min.X) ? min.X : x;

				real y = value.Y;
				y = (y > max.Y) ? max.Y : y;
				y = (y < min.Y) ? min.Y : y;

				real z = value.Z;
				z = (z > max.Z) ? max.Z : z;
				z = (z < min.Z) ? min.Z : z;

				return Vector3(x, y, z);
			}

			/*
			** Calculates the cross product of two vectors.
			** Parameters
			**	left		- The first source vector
			**	right		- The second source vector
			**	result		- A reference to a vector that stores the result
			** Returns
			**	nothing
			*/
			static void GetCross(const Vector3 &left, const Vector3 &right, Vector3 &result)
			{
				result.X = (left.Y * right.Z) - (left.Z * right.Y);
				result.Y = (left.Z * right.X) - (left.X * right.Z);
				result.Z = (left.X * right.Y) - (left.Y * right.X);
			}

			/*
			** Calculates the cross product of two vectors.
			** Parameters
			**	left		- The first source vector
			**	right		- The second source vector
			** Returns
			**	the resulting vector.
			*/
			static Vector3 GetCross(const Vector3 &left, const Vector3 &right)
			{
				return Vector3((left.Y * right.Z) - (left.Z * right.Y),
					(left.Z * right.X) - (left.X * right.Z),
					(left.X * right.Y) - (left.Y * right.X));
			}

			// Add TripleProduct -----
			/*
			** Calculates the distance between two Vector3 objects.
			** Parameters
			**	value1	- The first Vector3
			**	value2	- The second Vector3
			** Returns
			**	the distance between the two vectors.
			*/
			static real GetDistance(const Vector3 &value1, const Vector3 &value2)
			{
				real x = value1.X - value2.X;
				real y = value1.Y - value2.Y;
				real z = value1.Z - value2.Z;

				return (real)sqrt((real)(x*x + y*y + z*z));
			}

			/*
			** Calculates the distance squared between two Vector3 objects.
			** Parameters
			**	value1	- The first Vector3
			**	value2	- The second Vector3
			** Returns
			**	the distance squared between two vectors.
			*/
			static real GetDistanceSquared(const Vector3 &value1, const Vector3 &value2)
			{
				real x = value1.X - value2.X;
				real y = value1.Y - value2.Y;
				real z = value1.Z - value2.Z;

				return x*x + y*y + z*z;
			}

			/*
			** Calculates the dot product of two vectors.
			** Parameters
			**	left	- The first source Vector3
			**	right	- The second source Vector3
			** Returns
			**	the dot product.
			*/
			static real GetDot(const Vector3 &value1, const Vector3 &value2)
			{
				return (value1.X * value2.X) + (value1.Y * value2.Y) + (value1.Z * value2.Z);
			}

			/*
			** Normalizes the given vetor.
			** Parameters
			**	source		- The vector to normalize
			**	result		- A reference to a Vector3 which will store the normalized Vector.
			** Returns
			**	nothing
			*/
			static void Normalize(const Vector3 &source, Vector3 &result)
			{
				result.X = source.X;
				result.Y = source.Y;
				result.Z = source.Z;
				result.Normalize();
			}

			/*
			** Normalizes the given vetor.
			** Parameters
			**	source		- The vector to normalize
			** Returns
			**	the normalized 'source' vector.
			*/
			static Vector3 Normalize(const Vector3 &source)
			{
				Vector3 temp = source;
				temp.Normalize();

				return temp;
			}

			/*
			** Performs a linear interpolation between two vectors.
			** Parameters
			**	start		- The starting vector.
			**	end			- The ending vector.
			**	amount		- A value between 0 and 1 indicating the weight of 'end'.
			**	result		- A reference to a Vector3 which will store the result.
			** Returns
			**	nothing
			*/
			static void Lerp(const Vector3 &start, const Vector3 &end, real amount, Vector3 &result)
			{
				result.X = start.X + ((end.X - start.X) * amount);
				result.Y = start.Y + ((end.Y - start.Y) * amount);
				result.Z = start.Z + ((end.Z - start.Z) * amount);
			}
			
			/*
			** Performs a linear interpolation between two vectors.
			** Parameters
			**	start		- The starting vector.
			**	end			- The ending vector.
			**	amount		- A value between 0 and 1 indicating the weight of 'end'.
			** Returns
			**	a Vector3 containing the result of the linear interpolation.
			*/
			static Vector3 Lerp(const Vector3 &start, const Vector3 &end, real amount)
			{
				return Vector3(start.X + ((end.X - start.X) * amount),
					start.Y + ((end.Y - start.Y) * amount), start.Z + ((end.Z - start.Z) * amount));
			}

			/*
			** Performs a cubic interpolation between two vectors.
			** Parameters
			**	start		- The starting vector.
			**	end			- The ending vector.
			**	amount		- A value between 0 and 1 indicating the weight of 'end'.
			**	result		- A reference to a Vector3 which will store the result of the interpolation.
			** Returns
			**	nothing
			*/
			static void SmoothStep(const Vector3 &start, const Vector3 &end, real amount, Vector3 &result)
			{
				amount = (amount > (real)1.0) ? (real)1.0 : ((amount < (real)0.0) ? (real)0.0 : amount);
				amount = (amount * amount) * (real)(3.0 - (2.0 * amount));

				result.X = start.X + ((end.X - start.X) * amount);
				result.Y = start.Y + ((end.Y - start.Y) * amount);
				result.Z = start.Z + ((end.Z - start.Z) * amount);
			}

			/*
			** Performs a cubic interpolation between two vectors.
			** Parameters
			**	start		- The starting vector.
			**	end			- The ending vector.
			**	amount		- A value between 0 and 1 indicating the weight of 'end'.
			** Returns
			**	a Vector3 containing the result of the interpolation.
			*/
			static Vector3 SmoothStep(const Vector3 &start, const Vector3 &end, real amount)
			{
				amount = (amount > (real)1.0) ? (real)1.0 : ((amount < (real)0.0) ? (real)0.0 : amount);
				amount = (amount * amount) * (real)(3.0 - (2.0 * amount));

				return Vector3(start.X + ((end.X - start.X) * amount),
					start.Y + ((end.Y - start.Y) * amount),
					start.Z + ((end.Z - start.Z) * amount));
			}

			/*
			** Performs a Hermite spline interpolation
			** Parameters
			**	value1		- The first source vector.
			**	tangent1	- The first source tangent vector.
			**	value2		- The second source vector.
			**	tangent2	- The second source tangent vector.
			**	amount		- The weighting factor
			**	result		- A reference to a Vector3 that will store the result.
			** Returns
			**	nothing
			*/
			static void Hermite(const Vector3 &value1, const Vector3 &tangent1,
				const Vector3 &value2, const Vector3 &tangent2, real amount, Vector3 &result)
			{
				real squared = amount * amount;
				real cubed = amount * squared;
				real part1 = (((real)2.0 * cubed) - ((real)3.0 * squared)) + (real)1.0;
				real part2 = ((real)-2.0 * cubed) + ((real)3.0 * squared);
				real part3 = (cubed - ((real)2.0 * squared)) + amount;
				real part4 = cubed - squared;

				result.X = (((value1.X * part1) + (value2.X * part2)) + (tangent1.X * part3)) + (tangent2.X * part4);
				result.Y = (((value1.Y * part1) + (value2.Y * part2)) + (tangent1.Y * part3)) + (tangent2.Y * part4);
				result.Z = (((value1.Z * part1) + (value2.Z * part2)) + (tangent1.Z * part3)) + (tangent2.Z * part4);
			}

						/*
			** Performs a Hermite spline interpolation
			** Parameters
			**	value1		- The first source vector.
			**	tangent1	- The first source tangent vector.
			**	value2		- The second source vector.
			**	tangent2	- The second source tangent vector.
			**	amount		- The weighting factor
			** Returns
			**	a Vector3 containing the result of the interpolation
			*/
			static Vector3 Hermite(const Vector3 &value1, const Vector3 &tangent1,
				const Vector3 &value2, const Vector3 &tangent2, real amount)
			{
				real squared = amount * amount;
				real cubed = amount * squared;
				real part1 = (((real)2.0 * cubed) - ((real)3.0 * squared)) + (real)1.0;
				real part2 = ((real)-2.0 * cubed) + ((real)3.0 * squared);
				real part3 = (cubed - ((real)2.0 * squared)) + amount;
				real part4 = cubed - squared;

				return Vector3((((value1.X * part1) + (value2.X * part2)) + (tangent1.X * part3)) + (tangent2.X * part4), 
					(((value1.Y * part1) + (value2.Y * part2)) + (tangent1.Y * part3)) + (tangent2.Y * part4),
					(((value1.Z * part1) + (value2.Z * part2)) + (tangent1.Z * part3)) + (tangent2.Z * part4));
			}

			/*
			** Performs a Catmull-Rom interpolation using the specified positions.
			** Parameters
			**	value1		- The first position in the interpolation.
			**	value2		- The second position in the interpolation.
			**	value3		- The third position in the interpolation.
			**	value4		- The fourth position in the interpolation.
			**	amount		- The weighting factor.
			**	result		- A reference to a Vector3 which stores the result.
			** Returns
			**	nothing
			*/
			static void CatmullRom(const Vector3 &value1, const Vector3 &value2,
				const Vector3 &value3, const Vector3 &value4, real amount, Vector3 &result)
			{
				real squared = amount * amount;
				real cubed = amount * squared;

				result.X = (real)0.5 * (((((real)2.0 * value2.X) + ((-value1.X + value3.X) * amount)) +
					((((((real)2.0 * value1.X) - ((real)5.0 * value2.X)) + ((real)4.0 * value3.X)) - value4.X) * squared)) +
					((((-value1.X + ((real)3.0 * value2.X)) - ((real)3.0 * value3.X)) + value4.X) * cubed));

				result.Y = (real)0.5 * (((((real)2.0 * value2.Y) + ((-value1.Y + value3.Y) * amount)) +
					((((((real)2.0 * value1.Y) - ((real)5.0 * value2.Y)) + ((real)4.0 * value3.Y)) - value4.Y) * squared)) +
					((((-value1.Y + ((real)3.0 * value2.Y)) - ((real)3.0 * value3.Y)) + value4.Y) * cubed));

				result.Z = (real)0.5 * (((((real)2.0 * value2.Z) + ((-value1.Z + value3.Z) * amount)) +
					((((((real)2.0 * value1.Z) - ((real)5.0 * value2.Z)) + ((real)4.0 * value3.Z)) - value4.Z) * squared)) +
					((((-value1.Z + ((real)3.0 * value2.Z)) - ((real)3.0 * value3.Z)) + value4.Z) * cubed));
			}

			/*
			** Performs a Catmull-Rom interpolation using the specified positions.
			** Parameters
			**	value1		- The first position in the interpolation.
			**	value2		- The second position in the interpolation.
			**	value3		- The third position in the interpolation.
			**	value4		- The fourth position in the interpolation.
			**	amount		- The weighting factor.
			** Returns
			**	a Vector3 containing the result of the interpolation.
			*/
			static Vector3 CatmullRom(const Vector3 &value1, const Vector3 &value2,
				const Vector3 &value3, const Vector3 &value4, real amount)
			{
				Vector3 temp;
				real squared = amount * amount;
				real cubed = amount * squared;

				temp.X = (real)0.5 * (((((real)2.0 * value2.X) + ((-value1.X + value3.X) * amount)) +
					((((((real)2.0 * value1.X) - ((real)5.0 * value2.X)) + ((real)4.0 * value3.X)) - value4.X) * squared)) +
					((((-value1.X + ((real)3.0 * value2.X)) - ((real)3.0 * value3.X)) + value4.X) * cubed));

				temp.Y = (real)0.5 * (((((real)2.0 * value2.Y) + ((-value1.Y + value3.Y) * amount)) +
					((((((real)2.0 * value1.Y) - ((real)5.0 * value2.Y)) + ((real)4.0 * value3.Y)) - value4.Y) * squared)) +
					((((-value1.Y + ((real)3.0 * value2.Y)) - ((real)3.0 * value3.Y)) + value4.Y) * cubed));

				temp.Z = (real)0.5 * (((((real)2.0 * value2.Z) + ((-value1.Z + value3.Z) * amount)) +
					((((((real)2.0 * value1.Z) - ((real)5.0 * value2.Z)) + ((real)4.0 * value3.Z)) - value4.Z) * squared)) +
					((((-value1.Z + ((real)3.0 * value2.Z)) - ((real)3.0 * value3.Z)) + value4.Z) * cubed));

				return temp;
			}

			/*
			** Returns a vector containing the largst components of the specified vectors.
			** Parameters
			**	left		- The first source vector
			**	right		- The second source vector
			**	result		- A reference to a Vector3 which will store the result.
			** Returns
			**	nothing
			*/
			static void Max(const Vector3 &left, const Vector3 &right, Vector3 &result)
			{
				result.X = (left.X > right.X) ? left.X : right.X;
				result.Y = (left.Y > right.Y) ? left.Y : right.Y;
				result.Z = (left.Z > right.Z) ? left.Z : right.Z;
			}

			/*
			** Returns a vector containing the largest components of the specified vectors.
			** Parameters
			**	left		- The first source vector
			**	right		- The second source vector
			** Returns
			**	the Vector3 which the largest components of each vector.
			*/
			static Vector3 Max(const Vector3 &left, const Vector3 &right)
			{
				return Vector3((left.X > right.X) ? left.X : right.X, (left.Y > right.Y) ? left.Y : right.Y,
					(left.Z > right.Z) ? left.Z : right.Z);
			}

			/*
			** Returns a vector containing the smallest components of the specified vectors.
			** Parameters
			**	left		- The first source vector
			**	right		- The second source vector
			**	result		- A reference to a Vector3 which will store the result.
			** Returns
			**	nothing
			*/
			static void Min(const Vector3 &left, const Vector3 &right, Vector3 &result)
			{
				result.X = (left.X < right.X) ? left.X : right.X;
				result.Y = (left.Y < right.Y) ? left.Y : right.Y;
				result.Z = (left.Z < right.Z) ? left.Z : right.Z;
			}

			/*
			** Returns a vector containing the smallest components of the specified vectors.
			** Parameters
			**	left		- The first source vector
			**	right		- The second source vector
			** Returns
			**	the Vector3 which the smallest components of each vector.
			*/
			static Vector3 Min(const Vector3 &left, const Vector3 &right)
			{
				return Vector3((left.X < right.X) ? left.X : right.X, (left.Y < right.Y) ? left.Y : right.Y,
					(left.Z < right.Z) ? left.Z : right.Z);
			}

			/*
			** Projects a 3D vector from object space into screen space.
			** Parameters
			**	vector		- the vector to project
			**	x			- the x position of the viewport
			**	y			- the y position of the viewport
			**	width		- the width of the viewport
			**	height		- the height of the viewport
			**	minz		- the minimum depth of the viewport
			**	maxz		- the maximum depth of the viewport
			**	wvp			- the WorldViewProject matrix
			**	result		- a reference to a vector that will store the result
			** Returns
			**	nothing
			*/
			static void Project(const Vector3 &vector, real x, real y, real width, real height,
				real minz, real maxz, const Matrix4 &wvp, Vector3 &result);

			/*
			** Projects a 3D vector from object space into screen space.
			** Parameters
			**	vector		- the vector to project
			**	x			- the x position of the viewport
			**	y			- the y position of the viewport
			**	width		- the width of the viewport
			**	height		- the height of the viewport
			**	minz		- the minimum depth of the viewport
			**	maxz		- the maximum depth of the viewport
			**	wvp			- the WorldViewProject matrix
			** Returns
			**	the resulting vector in screen space
			*/
			static Vector3 Project(const Vector3 &vector, real x, real y, real width, real height,
				real minz, real maxz, const Matrix4 &wvp);

			/*
			** Projects a 3D vector from screen space into object space.
			** Parameters
			**	vector		- the vector to project
			**	x			- the x position of the viewport
			**	y			- the y position of the viewport
			**	width		- the width of the viewport
			**	height		- the height of the viewport
			**	minz		- the minimum depth of the viewport
			**	maxz		- the maximum depth of the viewport
			**	wvp			- the WorldViewProject matrix
			**	result		- a reference to a vector that will store the result
			** Returns
			**	nothing
			*/
			static void Unproject(const Vector3 &vector, real x, real y, real width, real height,
				real minz, real maxz, const Matrix4 &wvp, Vector3 &result);

			/*
			** Projects a 3D vector from screen space into object space.
			** Parameters
			**	vector		- the vector to project
			**	x			- the x position of the viewport
			**	y			- the y position of the viewport
			**	width		- the width of the viewport
			**	height		- the height of the viewport
			**	minz		- the minimum depth of the viewport
			**	maxz		- the maximum depth of the viewport
			**	wvp			- the WorldViewProject matrix
			** Returns
			**	the unprojected vector
			*/
			static Vector3 Unproject(const Vector3 &vector, real x, real y, real width, real height,
				real minz, real maxz, const Matrix4 &wvp);



			/*
			** Returns the reflection of a vector off of a surface that has the specified normal.
			** Parameters
			**	source		- The source vector.
			**	normal		- The normal of the surface.
			**	result		- A reference to a Vector3 that will store the result.
			** Returns
			**	nothing
			*/
			static void Reflect(const Vector3 &source, const Vector3 &normal, Vector3 &result)
			{
				real dot = (source.X * normal.X) + (source.Y * normal.Y) + (source.Z * normal.Z);

				result.X = source.X - (((real)2.0 * dot) * normal.X);
				result.Y = source.Y - (((real)2.0 * dot) * normal.Y);
				result.Z = source.Z - (((real)2.0 * dot) * normal.Z);
			}

			/*
			** Returns the reflection of a vector off of a surface that has the specified normal.
			** Parameters
			**	source		- The source vector.
			**	normal		- The normal of the surface.
			** Returns
			**	a Vector3 that contains the reflection of source.
			*/
			static Vector3 Reflect(const Vector3 &source, const Vector3 &normal)
			{
				real dot = (source.X * normal.X) + (source.Y * normal.Y) + (source.Z * normal.Z);

				return Vector3(source.X - (((real)2.0 * dot) * normal.X), 
					source.Y - (((real)2.0 * dot) * normal.Y),
					source.Z - (((real)2.0 * dot) * normal.Z));
			}

			/*
			** Orthogonalizes a list of vectors.
			** Parameters
			**	destination		- the list of orthogonalized vectors
			**	source			- the list of vectors to orthogonalize
			**	length			- the number of elements in each array
			** Returns
			**	nothing -- all results are returned via reference.
			*/
			static void Orthogonalize(Vector3 destination[], const Vector3 source[], int length)
			{
				for (int i = 0; i < length; ++i)
				{
					Vector3 newVector = source[i];
					
					for (int r = 0; r < i; ++r)
					{
						newVector -= destination[r] * (Vector3::GetDot(destination[r], newVector) / Vector3::GetDot(destination[r], destination[r]));
					}

					destination[i] = newVector;
				}
			}

			/*
			** Orthonormalizes a list of vectors.
			** Parameters
			**	destination		- the list of orthonormalized vectors
			**	source			- the list of vectors to orthonormalize
			**	length			- the number of elements in each array
			** Returns
			**	nothing -- all results are returned via reference.
			*/
			static void Orthonormalize(Vector3 destination[], const Vector3 source[], int length)
			{
				for (int i = 0; i < length; ++i)
				{
					Vector3 newVector = source[i];

					for (int r = 0; r < i; ++r)
					{
						newVector -= destination[r] * Vector3::GetDot(destination[r], newVector);
					}

					newVector.Normalize();
					destination[i] = newVector;
				}
			}

			/*
			** Transforms a 3D vector by the given Quaternion rotation.
			** Parameters
			**	source		- The vector to rotate.
			**	rotation	- The Quaternion rotation to apply.
			**	result		- A reference to a Vector3 which stores the result of the rotation.
			** Returns
			**	nothing
			*/
			static void Transform(const Vector3 &source, const Quaternion &rotation, Vector3 &result);

			/*
			** Transforms a 3D vector by the given Quaternion rotation.
			** Parameters
			**	source		- The vector to rotate.
			**	rotation	- The Quaternion rotation to apply.
			** Returns
			**	the rotated Vector3.
			*/
			static Vector3 Transform(const Vector3 &source, const Quaternion &rotation);

			/*
			** Transforms an array of 3D vectors by the given Quaternion rotation.
			** Parameters
			**	source		- The array of vectors to rotate.
			**	rotation	- The Quaternion rotation to apply.
			**	destination	- The array of vectors that will have been rotated.
			**	length		- The number of elements in the array of vectors.
			** Returns
			**	nothing -- all results are returned via reference.
			*/
			static void Transform(const Vector3 source[], const Quaternion &rotation, Vector3 destination[], int length);

			/*
			** Transforms the given 3D vector by the given Matrix4.
			** Parameters
			**	source		- the vector to transform
			**	transform	- the transformation matrix
			**	result		- a reference to a Vector4 which will store the result of the transformation.
			** Returns
			**	nothing
			*/
			static void Transform(const Vector3 &source, const Matrix4 &transform, Vector4 &result);

			/*
			** Transforms the given 3D vector by the given Matrix4.
			** Parameters
			**	source		- the vector to transform
			**	transform	- the transformation matrix
			** Returns
			**	the transformed vector (as a Vector4).
			*/
			static Vector4 Transform(const Vector3 &source, const Matrix4 &transform);

			/*
			** Transforms the given 3D vectors by the given Matrix4.
			** Parameters
			**	source		- the array of vectors to transform
			**	transform	- the transformation matrix
			**	destination	- the destination of vectors
			**	length		- the number of elements in the source array
			** Returns
			**	nothing
			*/
			static void Transform(const Vector3 source[], const Matrix4 &transform, Vector4 destination[], int length);

			/*
			** Transforms a coordinate using the given Matrix3.
			** Parameters
			**	coordinate		- the coordinate to transform
			**	transform		- the Matrix4 transformation
			**	result			- the Vector3 which stores the result of the transformation
			** Returns
			**	nothing
			*/
			static void TransformCoordinate(const Vector3 &coordinate, const Matrix4 &transform, Vector3 &result);

			/*
			** Transforms a coordinate using the given Matrix4.
			** Parameters
			**	coordinate		- the coordinate to transform
			**	transform		- the Matrix4 transformation
			** Returns
			**	the transformed Vector3.
			*/
			static Vector3 TransformCoordinate(const Vector3 &coordinate, const Matrix4 &transform);

			/*
			** Transforms an array of coordinates using the given Matrix4.
			** Parameters
			**	source			- the coordinates to transform
			**	transform		- the Matrix4 transformation
			**	destination		- the destination array
			**	length			- the number of coordinates to transform
			** Returns
			**	nothing
			*/
			static void TransformCoordinate(const Vector3 source[], const Matrix4 &transform, Vector3 destination[], int length);

			/*
			** Performs a normal transformation using the given Matrix4.
			** Parameters
			**	normal		- The normal vector to transform
			**	transform	- The Matrix4 transformation
			**	result		- A reference to a Vector3 that will store the result.
			** Returns
			**	nothing
			*/
			static void TransformNormal(const Vector3 &normal, const Matrix4 &transform, Vector3 &result);

			/*
			** Performs a normal transformation using the given Matrix4.
			** Parameters
			**	normal		- The normal vector to transform
			**	transform	- The Matrix4 transformation
			** Returns
			**	the transformed vector.
			*/
			static Vector3 TransformNormal(const Vector3 &normal, const Matrix4 &transform);

			/*
			** Performs a normal transformation using the given Matrix4.
			** Parameters
			**	source		- The array of normal vectors to transform
			**	transform	- The Matrix4 transformation
			**	destination	- The destination array
			**	length		- The number of vectors in the source array.
			** Returns
			**	nothing
			*/
			static void TransformNormal(const Vector3 source[], const Matrix4&transform, Vector2 destination[], int length);

			/*
			** Adds two vectors
			*/
			Vector3 operator+(const Vector3 &other) const
			{
				return Vector3(X + other.X, Y + other.Y, Z + other.Z);
			}

			/*
			** Adds a scalar to a vector
			*/
			Vector3 operator+(real scale) const
			{
				return Vector3(X + scale, Y + scale, Z + scale);
			}

			/*
			** Adds this vector with another vector
			*/
			Vector3& operator+=(const Vector3 &other)
			{
				X += other.X;
				Y += other.Y;
				Z += other.Z;

				return *this;
			}

			/*
			** Adds a scalar to this vector
			*/
			Vector3& operator+=(real scale)
			{
				X += scale;
				Y += scale;
				Z += scale;
				return *this;
			}

			/*
			** Subtracts two vectors.
			*/
			Vector3 operator-(const Vector3 &other) const
			{
				return Vector3(X - other.X, Y - other.Y, Z - other.Z);
			}
			
			/*
			** Subtracts a scalar from a vector
			*/
			Vector3 operator-(real scale) const
			{
				return Vector3(X - scale, Y - scale, Z - scale);
			}

			/*
			** Subtracts a vector from this vector
			*/
			Vector3& operator-=(const Vector3 &other)
			{
				X -= other.X;
				Y -= other.Y;
				Z -= other.Z;

				return *this;
			}

			/*
			** Subtracts a scalar from this vector
			*/
			Vector3& operator-=(real scale)
			{
				X -= scale;
				Y -= scale;
				Z -= scale;

				return *this;
			}
			/*
			** Unary plus - does nothing
			*/
			Vector3 operator+() const
			{
				return Vector3(X, Y, Z);
			}

			/*
			** Negates a vector.
			*/
			Vector3 operator-() const
			{
				return Vector3(-X, -Y, -Z);
			}

			/*
			** Scales a vector
			*/
			Vector3 operator*(real scale) const
			{
				return Vector3(X * scale, Y * scale, Z * scale);
			}

			/*
			** Scales this vector
			*/
			Vector3& operator*=(real scale)
			{
				X *= scale;
				Y *= scale;
				Z *= scale;

				return *this;
			}

			/*
			** Divides a vector by a scalar.
			*/
			Vector3 operator/(real scale)
			{
				real inv = (real)1.0 / scale;
				return Vector3(X * inv, Y * inv, Z * inv);
			}

			/*
			** Divides this vector by a scalar
			*/
			Vector3& operator/=(real scale)
			{
				real inv = (real)1.0 / scale;
				X *= inv;
				Y *= inv;
				Z *= inv;

				return *this;
			}

			/*
			** Tests for equality
			*/
			bool operator==(const Vector3 &other)
			{
				return ( X == other.X && Y == other.Y && Z == other.Z);
			}

			/*
			** Tests for inequality
			*/
			bool operator!=(const Vector3 &other)
			{
				return ( X != other.X || Y != other.Y || Z != other.Z);
			}

			/*
			** Index operator
			*/
			real& operator[](int index)
			{
				switch(index)
				{
				case 0:
					return X;
				case 1:
					return Y;
				case 2:
					return Z;
				default:
					throw std::runtime_error("index out of range");
				};
			}
		};
	}
}
#endif /* _TEKSTORM_VECTOR3_H */