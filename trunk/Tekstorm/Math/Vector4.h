/*
**	This header file declares the Vector4 class. It is a 
** four dimensional (component) mathematical vector.
*/
#pragma once
#ifndef _TEKSTORM_VECTOR4_H
#define _TEKSTORM_VECTOR4_H
#include "Vector3.h"

namespace Tekstorm
{
	/* 
	**	This is the root Math namespace. It contains all classes, data-structures,
	** constants, and functions related to mathematical aspects of this game engine.
	*/
	namespace Math
	{
		class TEKAPI Vector2;
		class TEKAPI Vector3;
		class TEKAPI Quaternion;
		class TEKAPI Matrix3;
		class TEKAPI Matrix4;
		
		/* 
		** This is a four-dimensional Vector.
		*/
		class TEKAPI Vector4
		{
		public:
			/* The X-component of this Vector4 class. */
			real X;

			/* The Y-component of this Vector4 class. */
			real Y;

			/* The Z-component of this Vector4 class. */
			real Z;

			/* The W-component of this Vector4 class. */
			real W;

			/* The size, in bytes, of this Vector4 class. */
			static const int SizeInBytes;

			/* A static Vector4 whose components are all 0. */
			static const Vector4 Zero;

			/* A static Vector4 whose components are all 1. */
			static const Vector4 One;

			/* A static Vector4 whose X-component is 1 and Y-component is 0 and Z-component is 0 and W-component is 0. */
			static const Vector4 UnitX;

			/* A static Vector4 whose X-component is 0 and Y-component is 1 and Z-component is 0 and W-component is 0. */
			static const Vector4 UnitY;

			/* A static Vector4 whose X-component is 0, Y-component is 0, and Z-component is 1 and W-component is 0. */
			static const Vector4 UnitZ;

			/* A static Vector4 whose X-component is 0, Y-component is 0, Z-component is 0, and W-component is 1. */
			static const Vector4 UnitW;

			/*
			** Initializes a new instance of Vector4 class.
			** Parameters
			**	none
			** Returns
			**	none
			*/
			Vector4() : X((real)0.0), Y((real)0.0), Z((real)0.0), W((real)0.0)
			{
			}

			/*
			** Initializes a new instance of the Vector4 class.
			** Parameters
			**	value	- the value to X, Y, Z and W to.
			** Returns
			**	nothing
			*/
			Vector4(real value) : X(value), Y(value), Z(value), W(value)
			{
			}

			/*
			** Initializes a new instance of the Vector4 class.
			** Parameters
			**	x		- the value to set X to.
			**	y		- the value to set Y to.
			**	z		- the value to set Z to.
			**	w		- the value to set W to.
			** Returns
			**	nothing
			*/
			Vector4(real x, real y, real z, real w) : X(x), Y(y), Z(z), W(w)
			{
			}

			/*
			** Initializes a new instance of the Vector4 class.
			** Parameters
			**	arr		- a four element array of type real.
			**			- the X component is set to the value of arr[0]
			**			- the Y component is set to the value of arr[1]
			**			- the Z component is set to the value of arr[2]
			**			- the W component is set to the value of arr[3]
			** Returns
			**	nothing
			*/
			Vector4(const real arr[]) : X(arr[0]), Y(arr[1]), Z(arr[2]), W(arr[3])
			{
			}
			
			/*
			** Initializes a new instance of the Vector4 class.
			** Parameters
			**	other	- another Vector4 to copy the X and Y and Z and W components from.
			** Returns
			**	nothing
			*/
			Vector4(const Vector4 &other) : X(other.X), Y(other.Y), Z(other.Z), W(other.W)
			{
			}

			/*
			** Determines whether or not this Vector4 is normalized.
			** Parameters
			**	none
			** Returns
			**	True if this Vector4 is normalized.
			*/
			bool IsNormalized() const
			{
				return (CommonUtils::Abs((real)(X*X + Y*Y + Z*Z + W*W) - 1) < TEKSTORM_REAL_EPSILON);
			}

			/*
			** Calculates the length of this Vector4.
			** Parameters
			**	none
			** Returns
			**	The length of this Vector4.
			**	Length is calculated as sqrt(x^2 + y^2 + z^2 + w^2).
			*/
			real GetLength() const
			{
				return (real)sqrt(X*X + Y*Y + Z*Z + W*W);
			}

			/*
			** Calculates the squared length of this Vector4.
			** Parameters
			**	none
			** Returns
			**	The length of this Vector4 squared.
			**	Length squared is calculated as x^2 + y^2 + z^2 + w^2.
			*/
			real GetLengthSquared() const
			{
				return X*X + Y*Y + Z*Z + W*W;
			}

			/*
			** Normalizes this Vector4.
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
					W *= inv;
				}
			}

			/*
			** Adds two Vector4 objects together.
			** Parameters
			**	left	- the left Vector4 used in addition
			**	right	- the right Vector4 used in addition
			**	result	- a reference to a Vector4 that will store the result
			** Returns
			**	nothing
			*/
			static void Add(const Vector4 &left, const Vector4 &right, Vector4 &result)
			{
				result.X = left.X + right.X;
				result.Y = left.Y + right.Y;
				result.Z = left.Z + right.Z;
				result.W = left.W + right.W;
			}

			/*
			** Adds two Vector4 objects together.
			** Parameters
			**	left	- the left Vector4 used in addition
			**	right	- the right Vector4 used in addition
			** Returns
			**	the result of adding left and right together.
			*/
			static Vector4 Add(const Vector4 &left, const Vector4 &right)
			{
				return Vector4(left.X + right.X, left.Y + right.Y, left.Z + right.Z, left.W + right.W);
			}

			/*
			** Subtracts two Vector4 objects.
			** Parameters
			**	left	- the left Vector4 used in subtraction
			**	right	- the right Vector4 used in subtraction
			**	result	- a reference to a Vector4 object that will store the result
			** Returns
			**	nothing
			*/
			static void Subtract(const Vector4 &left, const Vector4 &right, Vector4 &result)
			{
				result.X = left.X - right.X;
				result.Y = left.Y - right.Y;
				result.Z = left.Z - right.Z;
				result.W = left.W - right.W;
			}

			/*
			** Subtracts two Vector4 objects.
			** Parameters
			**	left	- the left Vector4 used in subtraction
			**	right	- the right Vector4 used in subtraction
			** Returns
			**	the result of the subtraction.
			*/
			static Vector4 Subtract(const Vector4 &left, const Vector4 &right)
			{
				return Vector4(left.X - right.X, left.Y - right.Y, left.Z - right.Z, left.W - right.W);
			}

			/*
			** Multiplies a Vector4 object by a scalar.
			** Parameters
			**	value	- the Vector4 used in multiplication
			**	scale	- the scalar value to be used
			**	result	- a reference to a Vector4 object to store the result
			** Returns
			**	nothing
			*/
			static void Multiply(const Vector4 &value, real scale, Vector4 &result)
			{
				result.X = value.X * scale;
				result.Y = value.Y * scale;
				result.Z = value.Z * scale;
				result.W = value.W * scale;
			}

			/*
			** Multiplies a Vector4 object by a scalar.
			** Parameters
			**	value	- the Vector4 used in multiplication
			**	scale	- the scalar used 
			** Returns
			**	the result of multiplying value by scale.
			*/
			static Vector4 Multiply(const Vector4 &value, real scale)
			{
				return Vector4(value.X * scale, value.Y * scale, value.Z * scale, value.W * scale);
			}

			/*
			** Modulates a vector with another vector by performing component-wise multiplication.
			** Parameters
			**	left	- the left Vector4 used in modulation
			**	right	- the right Vector4 used in modulation
			**	result	- a reference to a Vector4 that will store the result
			** Returns
			**	nothing
			*/
			static void Modulate(const Vector4 &left, const Vector4 &right, Vector4 &result)
			{
				result.X = left.X * right.X;
				result.Y = left.Y * right.Y;
				result.Z = left.Z * right.Z;
				result.W = left.W * right.W;
			}

			/*
			** Modulates a vector with another vector by performing component-wise multiplication.
			** Parameters
			**	left	- the left Vector4 used in modulation
			**	right	- the right Vector4 used in modulation
			** Returns
			**	a Vector2 containing the result of modulation.
			*/
			static Vector4 Modulate(const Vector4 &left, const Vector4 &right)
			{
				return Vector4(left.X * right.X, left.Y * right.Y, left.Z * right.Z, left.W * right.W);
			}

			/*
			** Divides each component of this vector with the given scalar value.
			** Parameters
			**	value	- the Vector4 that will be divided
			**	scale	- the scalar value to divide by
			**	result	- a reference to a Vector4 that will store the result
			** Returns
			**	nothing
			*/
			static void Divide(const Vector4 &value, real scale, Vector4 &result)
			{
				result.X = value.X / scale;
				result.Y = value.Y / scale;
				result.Z = value.Z / scale;
				result.W = value.W / scale;
			}

			/*
			** Divides each component of this vector with the given scalar value.
			** Parameters
			**	value	- the Vector4 that will be divided
			**	scale	- the scalar value to divide by
			** Returns
			**	a Vector4 containing the result of the division.
			*/
			static Vector4 Divide(const Vector4 &value, real scale)
			{
				return Vector4(value.X / scale, value.Y / scale, value.Z / scale, value.W / scale);
			}

			/*
			** Negates each component of a vector.
			** Parameters
			**	value	- the Vector4 that should be negated
			**	result	- a reference to a Vector4 that will store the result
			** Returns
			**	nothing
			*/
			static void Negate(const Vector4 &value, Vector4 &result)
			{
				result.X = -value.X;
				result.Y = -value.Y;
				result.Z = -value.Z;
				result.W = -value.W;
			}

			/*
			** Negates each component of a vector.
			** Parameters
			**	value	- the Vector4 that should be negated
			** Returns
			**	the negated version of 'value'.
			*/
			static Vector4 Negate(const Vector4 &value)
			{
				return Vector4(-value.X, -value.Y, -value.Z, -value.W);
			}

			/*
			** Takes the absolute value of each component.
			** Parameters
			**	value	- the Vector4 to take the absolute value of
			**	result	- a reference to a Vector4 that will store the result
			** Returns
			**	nothing
			*/
			static void Abs(const Vector4 &value, Vector4 &result)
			{
				result.X = CommonUtils::Abs(value.X);
				result.Y = CommonUtils::Abs(value.Y);
				result.Z = CommonUtils::Abs(value.Z);
				result.W = CommonUtils::Abs(value.W);
			}

			/*
			** Takes the absolute value of each component.
			** Parameters
			**	value	- the Vector4 to take the absolute value of
			** Returns
			**	the absolute value version of 'value'.
			*/
			static Vector4 Abs(const Vector4 &value)
			{
				return Vector4((real)CommonUtils::Abs(value.X), (real)CommonUtils::Abs(value.Y), 
					(real)CommonUtils::Abs(value.Z), (real)CommonUtils::Abs(value.W));
			}

			/*
			** Returns a Vector4 containing the 4D cartesian coordinates of a point
			**	specified in Barycentric coordinates relative to a 4D triangle.
			** Parameters
			**	value1	- A Vector4 containing the 4D cartesian coordinates of vertex1 of the triangle.
			**	value2	- A Vector4 containing the 4D cartesian coordinates of vertex2 of the triangle.
			**	value3	- A Vector4 containing the 4D cartesian coordinates of vertex3 of the triangle.
			**	amount1	- Barycentric coordinate b2, which expresses the weighting factor toward vertex 2.
			**	amount2	- Barycentric coordinate b3, which expresses the weighting factor toward vertex 3.
			**	result	- A reference to a Vector4 which will store the 4D cartesian coordinates.
			** Returns
			**	nothing
			*/
			static void Barycentric(const Vector4 &value1, const Vector4 &value2, const Vector4 &value3,
				real amount1, real amount2, Vector4 &result)
			{
				result.X = (value1.X + (amount1 * (value2.X - value1.X))) + (amount2 * (value3.X - value1.X));
				result.Y = (value1.Y + (amount1 * (value2.Y - value1.Y))) + (amount2 * (value3.Y - value1.Y));
				result.Z = (value1.Z + (amount1 * (value2.Z - value1.Z))) + (amount2 * (value3.Z - value1.Z));
				result.W = (value1.W + (amount1 * (value2.W - value1.W))) + (amount2 * (value3.W - value1.W));
			}

			/*
			** Returns a Vector4 containing the 4D cartesian coordinates of a point
			**	specified in Barycentric coordinates relative to a 4D triangle.
			** Parameters
			**	value1	- A Vector4 containing the 4D cartesian coordinates of vertex1 of the triangle.
			**	value2	- A Vector4 containing the 4D cartesian coordinates of vertex2 of the triangle.
			**	value3	- A Vector4 containing the 4D cartesian coordinates of vertex3 of the triangle.
			**	amount1	- Barycentric coordinate b2, which expresses the weighting factor toward vertex 2.
			**	amount2	- Barycentric coordinate b3, which expresses the weighting factor toward vertex 3.
			** Returns
			**	a Vector4 which holds the 4D cartesian coordinates.
			*/
			static Vector4 Barycentric(const Vector4 &value1, const Vector4 &value2, const Vector4 &value3,
				real amount1, real amount2)
			{
				return Vector4((value1.X + (amount1 * (value2.X - value1.X))) + (amount2 * (value3.X - value1.X)),
					(value1.Y + (amount1 * (value2.Y - value1.Y))) + (amount2 * (value3.Y - value1.Y)),
					(value1.Z + (amount1 * (value2.Z - value1.Z))) + (amount2 * (value3.Z - value1.Z)),
					(value1.W + (amount1 * (value2.W - value1.W))) + (amount2 * (value3.W - value1.W)));
			}

			/*
			** Restricts a value to be within a specified range.
			** Parameters
			**	value	- The value to clamp
			**	min		- The minimum value
			**	max		- The maximum value
			**	result	- A reference to a Vector4 which will store the clamped value.
			** Returns
			**	nothing
			*/
			static void Clamp(const Vector4 &value, const Vector4 &min, const Vector4 &max, Vector4 &result)
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

				real w = value.W;
				w = (w > max.W) ? max.W : w;
				w = (w < min.W) ? min.W : w;

				result.X = x;
				result.Y = y;
				result.Z = z;
				result.W = w;
			}

			/*
			** Restricts a value to be within a specified range.
			** Parameters
			**	value	- The value to clamp
			**	min		- The minimum value
			**	max		- The maximum value
			** Returns
			**	a Vector4 whose components are within the min and max range.
			*/
			static Vector4 Clamp(const Vector4 &value, const Vector4 &min, const Vector4 &max)
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

				real w = value.W;
				w = (w > max.W) ? max.W : w;
				w = (w < min.W) ? min.W : w;

				return Vector4(x, y, z, w);
			}

			/*
			** Calculates the distance between two Vector4 objects.
			** Parameters
			**	value1	- The first Vector4
			**	value2	- The second Vector4
			** Returns
			**	the distance between the two vectors.
			*/
			static real GetDistance(const Vector4 &value1, const Vector4 &value2)
			{
				real x = value1.X - value2.X;
				real y = value1.Y - value2.Y;
				real z = value1.Z - value2.Z;
				real w = value1.W - value2.W;

				return (real)sqrt((real)(x*x + y*y + z*z + w*w));
			}

			/*
			** Calculates the distance squared between two Vector4 objects.
			** Parameters
			**	value1	- The first Vector4
			**	value2	- The second Vector4
			** Returns
			**	the distance squared between two vectors.
			*/
			static real GetDistanceSquared(const Vector4 &value1, const Vector4 &value2)
			{
				real x = value1.X - value2.X;
				real y = value1.Y - value2.Y;
				real z = value1.Z - value2.Z;
				real w = value1.W - value2.W;

				return x*x + y*y + z*z + w*w;
			}

			/*
			** Calculates the dot product of two vectors.
			** Parameters
			**	left	- The first source Vector4
			**	right	- The second source Vector4
			** Returns
			**	the dot product.
			*/
			static real GetDot(const Vector4 &value1, const Vector4 &value2)
			{
				return (value1.X * value2.X) + (value1.Y * value2.Y) + (value1.Z * value2.Z) + (value1.W * value2.W);
			}

			/*
			** Normalizes the given vetor.
			** Parameters
			**	source		- The vector to normalize
			**	result		- A reference to a Vector4 which will store the normalized Vector.
			** Returns
			**	nothing
			*/
			static void Normalize(const Vector4 &source, Vector4 &result)
			{
				result.X = source.X;
				result.Y = source.Y;
				result.Z = source.Z;
				result.W = source.W;
				result.Normalize();
			}

			/*
			** Normalizes the given vetor.
			** Parameters
			**	source		- The vector to normalize
			** Returns
			**	the normalized 'source' vector.
			*/
			static Vector4 Normalize(const Vector4 &source)
			{
				Vector4 temp = source;
				temp.Normalize();

				return temp;
			}

			/*
			** Performs a linear interpolation between two vectors.
			** Parameters
			**	start		- The starting vector.
			**	end			- The ending vector.
			**	amount		- A value between 0 and 1 indicating the weight of 'end'.
			**	result		- A reference to a Vector4 which will store the result.
			** Returns
			**	nothing
			*/
			static void Lerp(const Vector4 &start, const Vector4 &end, real amount, Vector4 &result)
			{
				result.X = start.X + ((end.X - start.X) * amount);
				result.Y = start.Y + ((end.Y - start.Y) * amount);
				result.Z = start.Z + ((end.Z - start.Z) * amount);
				result.W = start.W + ((end.W - start.W) * amount);
			}
			
			/*
			** Performs a linear interpolation between two vectors.
			** Parameters
			**	start		- The starting vector.
			**	end			- The ending vector.
			**	amount		- A value between 0 and 1 indicating the weight of 'end'.
			** Returns
			**	a Vector4 containing the result of the linear interpolation.
			*/
			static Vector4 Lerp(const Vector4 &start, const Vector4 &end, real amount)
			{
				return Vector4(start.X + ((end.X - start.X) * amount),
					start.Y + ((end.Y - start.Y) * amount), 
					start.Z + ((end.Z - start.Z) * amount),
					start.W + ((end.W - start.W) * amount));
			}

			/*
			** Performs a cubic interpolation between two vectors.
			** Parameters
			**	start		- The starting vector.
			**	end			- The ending vector.
			**	amount		- A value between 0 and 1 indicating the weight of 'end'.
			**	result		- A reference to a Vector4 which will store the result of the interpolation.
			** Returns
			**	nothing
			*/
			static void SmoothStep(const Vector4 &start, const Vector4 &end, real amount, Vector4 &result)
			{
				amount = (amount > (real)1.0) ? (real)1.0 : ((amount < (real)0.0) ? (real)0.0 : amount);
				amount = (amount * amount) * (real)(3.0 - (2.0 * amount));

				result.X = start.X + ((end.X - start.X) * amount);
				result.Y = start.Y + ((end.Y - start.Y) * amount);
				result.Z = start.Z + ((end.Z - start.Z) * amount);
				result.W = start.W + ((end.W - start.W) * amount);
			}

			/*
			** Performs a cubic interpolation between two vectors.
			** Parameters
			**	start		- The starting vector.
			**	end			- The ending vector.
			**	amount		- A value between 0 and 1 indicating the weight of 'end'.
			** Returns
			**	a Vector4 containing the result of the interpolation.
			*/
			static Vector4 SmoothStep(const Vector4 &start, const Vector4 &end, real amount)
			{
				amount = (amount > (real)1.0) ? (real)1.0 : ((amount < (real)0.0) ? (real)0.0 : amount);
				amount = (amount * amount) * (real)(3.0 - (2.0 * amount));

				return Vector4(start.X + ((end.X - start.X) * amount),
					start.Y + ((end.Y - start.Y) * amount),
					start.Z + ((end.Z - start.Z) * amount),
					start.W + ((end.W - start.W) * amount));
			}

			/*
			** Performs a Hermite spline interpolation
			** Parameters
			**	value1		- The first source vector.
			**	tangent1	- The first source tangent vector.
			**	value2		- The second source vector.
			**	tangent2	- The second source tangent vector.
			**	amount		- The weighting factor
			**	result		- A reference to a Vector4 that will store the result.
			** Returns
			**	nothing
			*/
			static void Hermite(const Vector4 &value1, const Vector4 &tangent1,
				const Vector4 &value2, const Vector4 &tangent2, real amount, Vector4 &result)
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
				result.W = (((value1.W * part1) + (value2.W * part2)) + (tangent1.W * part3)) + (tangent2.W * part4);
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
			**	a Vector4 containing the result of the interpolation
			*/
			static Vector4 Hermite(const Vector4 &value1, const Vector4 &tangent1,
				const Vector4 &value2, const Vector4 &tangent2, real amount)
			{
				real squared = amount * amount;
				real cubed = amount * squared;
				real part1 = (((real)2.0 * cubed) - ((real)3.0 * squared)) + (real)1.0;
				real part2 = ((real)-2.0 * cubed) + ((real)3.0 * squared);
				real part3 = (cubed - ((real)2.0 * squared)) + amount;
				real part4 = cubed - squared;

				return Vector4((((value1.X * part1) + (value2.X * part2)) + (tangent1.X * part3)) + (tangent2.X * part4), 
					(((value1.Y * part1) + (value2.Y * part2)) + (tangent1.Y * part3)) + (tangent2.Y * part4),
					(((value1.Z * part1) + (value2.Z * part2)) + (tangent1.Z * part3)) + (tangent2.Z * part4),
					(((value1.W * part1) + (value2.W * part2)) + (tangent1.W * part3)) + (tangent2.W * part4));
			}

			/*
			** Performs a Catmull-Rom interpolation using the specified positions.
			** Parameters
			**	value1		- The first position in the interpolation.
			**	value2		- The second position in the interpolation.
			**	value3		- The third position in the interpolation.
			**	value4		- The fourth position in the interpolation.
			**	amount		- The weighting factor.
			**	result		- A reference to a Vector4 which stores the result.
			** Returns
			**	nothing
			*/
			static void CatmullRom(const Vector4 &value1, const Vector4 &value2,
				const Vector4 &value3, const Vector4 &value4, real amount, Vector4 &result)
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

				result.W = (real)0.5 * (((((real)2.0 * value2.W) + ((-value1.W + value3.W) * amount)) +
					((((((real)2.0 * value1.W) - ((real)5.0 * value2.W)) + ((real)4.0 * value3.W)) - value4.W) * squared)) +
					((((-value1.W + ((real)3.0 * value2.W)) - ((real)3.0 * value3.W)) + value4.W) * cubed));
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
			**	a Vector4 containing the result of the interpolation.
			*/
			static Vector4 CatmullRom(const Vector4 &value1, const Vector4 &value2,
				const Vector4 &value3, const Vector4 &value4, real amount)
			{
				Vector4 temp;
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

				temp.W = (real)0.5 * (((((real)2.0 * value2.W) + ((-value1.W + value3.W) * amount)) +
					((((((real)2.0 * value1.W) - ((real)5.0 * value2.W)) + ((real)4.0 * value3.W)) - value4.W) * squared)) +
					((((-value1.W + ((real)3.0 * value2.W)) - ((real)3.0 * value3.W)) + value4.W) * cubed));

				return temp;
			}

			/*
			** Returns a vector containing the largst components of the specified vectors.
			** Parameters
			**	left		- The first source vector
			**	right		- The second source vector
			**	result		- A reference to a Vector4 which will store the result.
			** Returns
			**	nothing
			*/
			static void Max(const Vector4 &left, const Vector4 &right, Vector4 &result)
			{
				result.X = (left.X > right.X) ? left.X : right.X;
				result.Y = (left.Y > right.Y) ? left.Y : right.Y;
				result.Z = (left.Z > right.Z) ? left.Z : right.Z;
				result.W = (left.W > right.W) ? left.W : right.W;
			}

			/*
			** Returns a vector containing the largest components of the specified vectors.
			** Parameters
			**	left		- The first source vector
			**	right		- The second source vector
			** Returns
			**	the Vector4 which the largest components of each vector.
			*/
			static Vector4 Max(const Vector4 &left, const Vector4 &right)
			{
				return Vector4((left.X > right.X) ? left.X : right.X, (left.Y > right.Y) ? left.Y : right.Y,
					(left.Z > right.Z) ? left.Z : right.Z,
					(left.W > right.W) ? left.W : right.W);
			}

			/*
			** Returns a vector containing the smallest components of the specified vectors.
			** Parameters
			**	left		- The first source vector
			**	right		- The second source vector
			**	result		- A reference to a Vector4 which will store the result.
			** Returns
			**	nothing
			*/
			static void Min(const Vector4 &left, const Vector4 &right, Vector4 &result)
			{
				result.X = (left.X < right.X) ? left.X : right.X;
				result.Y = (left.Y < right.Y) ? left.Y : right.Y;
				result.Z = (left.Z < right.Z) ? left.Z : right.Z;
				result.W = (left.W < right.W) ? left.W : right.W;
			}

			/*
			** Returns a vector containing the smallest components of the specified vectors.
			** Parameters
			**	left		- The first source vector
			**	right		- The second source vector
			** Returns
			**	the Vector4 which the smallest components of each vector.
			*/
			static Vector4 Min(const Vector4 &left, const Vector4 &right)
			{
				return Vector4((left.X < right.X) ? left.X : right.X, 
					(left.Y < right.Y) ? left.Y : right.Y,
					(left.Z < right.Z) ? left.Z : right.Z,
					(left.W < right.W) ? left.W : right.W);
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
			static void Orthogonalize(Vector4 destination[], const Vector4 source[], int length)
			{
				for (int i = 0; i < length; ++i)
				{
					Vector4 newVector = source[i];
					
					for (int r = 0; r < i; ++r)
					{
						newVector -= destination[r] * (Vector4::GetDot(destination[r], newVector) / Vector4::GetDot(destination[r], destination[r]));
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
			static void Orthonormalize(Vector4 destination[], const Vector4 source[], int length)
			{
				for (int i = 0; i < length; ++i)
				{
					Vector4 newVector = source[i];

					for (int r = 0; r < i; ++r)
					{
						newVector -= destination[r] * Vector4::GetDot(destination[r], newVector);
					}

					newVector.Normalize();
					destination[i] = newVector;
				}
			}

			/*
			** Transforms a 4D vector by the given Quaternion rotation.
			** Parameters
			**	source		- The vector to rotate.
			**	rotation	- The Quaternion rotation to apply.
			**	result		- A reference to a Vector4 which stores the result of the rotation.
			** Returns
			**	nothing
			*/
			static void Transform(const Vector4 &source, const Quaternion &rotation, Vector4 &result);

			/*
			** Transforms a 4D vector by the given Quaternion rotation.
			** Parameters
			**	source		- The vector to rotate.
			**	rotation	- The Quaternion rotation to apply.
			** Returns
			**	the rotated Vector4.
			*/
			static Vector4 Transform(const Vector4 &source, const Quaternion &rotation);

			/*
			** Transforms an array of 4D vectors by the given Quaternion rotation.
			** Parameters
			**	source		- The array of vectors to rotate.
			**	rotation	- The Quaternion rotation to apply.
			**	destination	- The array of vectors that will have been rotated.
			**	length		- The number of elements in the array of vectors.
			** Returns
			**	nothing -- all results are returned via reference.
			*/
			static void Transform(const Vector4 source[], const Quaternion &rotation, Vector4 destination[], int length);

			/*
			** Transforms the given 4D vector by the given Matrix4.
			** Parameters
			**	source		- the vector to transform
			**	transform	- the transformation matrix
			**	result		- a reference to a Vector4 which will store the result of the transformation.
			** Returns
			**	nothing
			*/
			static void Transform(const Vector4 &source, const Matrix4 &transform, Vector4 &result);

			/*
			** Transforms the given 4D vector by the given Matrix4.
			** Parameters
			**	source		- the vector to transform
			**	transform	- the transformation matrix
			** Returns
			**	the transformed vector (as a Vector4).
			*/
			static Vector4 Transform(const Vector4 &source, const Matrix4 &transform);

			/*
			** Transforms the given 4D vectors by the given Matrix4.
			** Parameters
			**	source		- the array of vectors to transform
			**	transform	- the transformation matrix
			**	destination	- the destination of vectors
			**	length		- the number of elements in the source array
			** Returns
			**	nothing
			*/
			static void Transform(const Vector4 source[], const Matrix4 &transform, Vector4 destination[], int length);

			/*
			** Transforms a coordinate using the given Matrix4.
			** Parameters
			**	coordinate		- the coordinate to transform
			**	transform		- the Matrix4 transformation
			**	result			- the Vector4 which stores the result of the transformation
			** Returns
			**	nothing
			*/
			static void TransformCoordinate(const Vector4 &coordinate, const Matrix4 &transform, Vector4 &result);

			/*
			** Transforms a coordinate using the given Matrix4.
			** Parameters
			**	coordinate		- the coordinate to transform
			**	transform		- the Matrix4 transformation
			** Returns
			**	the transformed Vector4.
			*/
			static Vector4 TransformCoordinate(const Vector4 &coordinate, const Matrix4 &transform);

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
			static void TransformCoordinate(const Vector4 source[], const Matrix4 &transform, Vector4 destination[], int length);

			/*
			** Performs a normal transformation using the given Matrix4.
			** Parameters
			**	normal		- The normal vector to transform
			**	transform	- The Matrix4 transformation
			**	result		- A reference to a Vector4 that will store the result.
			** Returns
			**	nothing
			*/
			static void TransformNormal(const Vector4 &normal, const Matrix4 &transform, Vector4 &result);

			/*
			** Performs a normal transformation using the given Matrix4.
			** Parameters
			**	normal		- The normal vector to transform
			**	transform	- The Matrix4 transformation
			** Returns
			**	the transformed vector.
			*/
			static Vector4 TransformNormal(const Vector4 &normal, const Matrix4 &transform);

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
			static void TransformNormal(const Vector4 source[], const Matrix4&transform, Vector2 destination[], int length);

			/*
			** Adds two vectors
			*/
			Vector4 operator+(const Vector4 &other) const
			{
				return Vector4(X + other.X, Y + other.Y, Z + other.Z, W + other.W);
			}

			/*
			** Adds a scalar to a vector
			*/
			Vector4 operator+(real scale) const
			{
				return Vector4(X + scale, Y + scale, Z + scale, W + scale);
			}

			/*
			** Adds this vector with another vector
			*/
			Vector4& operator+=(const Vector4 &other)
			{
				X += other.X;
				Y += other.Y;
				Z += other.Z;
				W += other.W;

				return *this;
			}

			/*
			** Adds a scalar to this vector
			*/
			Vector4& operator+=(real scale)
			{
				X += scale;
				Y += scale;
				Z += scale;
				W += scale;

				return *this;
			}

			/*
			** Subtracts two vectors.
			*/
			Vector4 operator-(const Vector4 &other) const
			{
				return Vector4(X - other.X, Y - other.Y, Z - other.Z, W - other.W);
			}
			
			/*
			** Subtracts a scalar from a vector
			*/
			Vector4 operator-(real scale) const
			{
				return Vector4(X - scale, Y - scale, Z - scale, W - scale);
			}

			/*
			** Subtracts a vector from this vector
			*/
			Vector4& operator-=(const Vector4 &other)
			{
				X -= other.X;
				Y -= other.Y;
				Z -= other.Z;
				W -= other.W;

				return *this;
			}

			/*
			** Subtracts a scalar from this vector
			*/
			Vector4& operator-=(real scale)
			{
				X -= scale;
				Y -= scale;
				Z -= scale;
				W -= scale;

				return *this;
			}
			/*
			** Unary plus - does nothing
			*/
			Vector4 operator+() const
			{
				return Vector4(X, Y, Z, W);
			}

			/*
			** Negates a vector.
			*/
			Vector4 operator-() const
			{
				return Vector4(-X, -Y, -Z, -W);
			}

			/*
			** Scales a vector
			*/
			Vector4 operator*(real scale) const
			{
				return Vector4(X * scale, Y * scale, Z * scale, W * scale);
			}

			/*
			** Scales this vector
			*/
			Vector4& operator*=(real scale)
			{
				X *= scale;
				Y *= scale;
				Z *= scale;
				W *= scale;

				return *this;
			}

			/*
			** Divides a vector by a scalar.
			*/
			Vector4 operator/(real scale)
			{
				real inv = (real)1.0 / scale;
				return Vector4(X * inv, Y * inv, Z * inv, W * inv);
			}

			/*
			** Divides this vector by a scalar
			*/
			Vector4& operator/=(real scale)
			{
				real inv = (real)1.0 / scale;
				X *= inv;
				Y *= inv;
				Z *= inv;
				W *= inv;

				return *this;
			}

			/*
			** Tests for equality
			*/
			bool operator==(const Vector4 &other)
			{
				return ( X == other.X && Y == other.Y && Z == other.Z && W == other.W);
			}

			/*
			** Tests for inequality
			*/
			bool operator!=(const Vector4 &other)
			{
				return ( X != other.X || Y != other.Y || Z != other.Z || W != other.W);
			}

			/*
			** Index operator
			*/
			real& operator[](int index)
			{
				switch(index)
				{
				case 0: return X;
				case 1: return Y;
				case 2: return Z;
				case 3: return W;
				default:
					throw std::runtime_error("index out of range");
				};
			}
		};
	}
}
#endif /* _TEKSTORM_VECTOR4_H */