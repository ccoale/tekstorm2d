/*
**	This header file declares the Vector2 class. It is a 
** two dimensional (component) mathematical vector.
*/
#pragma once
#ifndef _TEKSTORM_VECTOR2_H
#define _TEKSTORM_VECTOR2_H
#include "../BuildConf.h"
#include "../CommonUtils.h"

namespace Tekstorm
{
	/* 
	**	This is the root Math namespace. It contains all classes, data-structures,
	** constants, and functions related to mathematical aspects of this game engine.
	*/
	namespace Math
	{
		class TEKAPI Vector3;
		class TEKAPI Vector4;
		class TEKAPI Quaternion;
		class TEKAPI Matrix3;
		class TEKAPI Matrix4;
		
		/* 
		** This is a two-dimensional (two component) Vector class.
		*/
		class TEKAPI Vector2
		{
		public:
			/* The X-component of this Vector2 class. */
			real X;

			/* The Y-component of this Vector2 class. */
			real Y;

			/* The size, in bytes, of this Vector2 class. */
			static const int SizeInBytes;

			/* A static Vector2 whose components are all 0. */
			static const Vector2 Zero;

			/* A static Vector2 whose components are all 1. */
			static const Vector2 One;

			/* A static Vector2 whose X-component is 1 and Y-component is 0. */
			static const Vector2 UnitX;

			/* A static Vector2 whose X-component is 0 and Y-component is 1. */
			static const Vector2 UnitY;

			/*
			** Initializes a new instance of Vector2 class.
			** Parameters
			**	none
			** Returns
			**	none
			*/
			Vector2() : X((real)0.0), Y((real)0.0)
			{
			}

			/*
			** Initializes a new instance of the Vector2 class.
			** Parameters
			**	value	- the value to set both the X and Y components to.
			** Returns
			**	nothing
			*/
			Vector2(real value) : X(value), Y(value)
			{
			}

			/*
			** Initializes a new instance of the Vector2 class.
			** Parameters
			**	x		- the value to set X to.
			**	y		- the value to set Y to.
			** Returns
			**	nothing
			*/
			Vector2(real x, real y) : X(x), Y(y)
			{
			}

			/*
			** Initializes a new instance of the Vector2 class.
			** Parameters
			**	arr		- a two element array of type real.
			**			- the X component is set to the value of arr[0]
			**			- the Y component is set to the value of arr[1]
			** Returns
			**	nothing
			*/
			Vector2(const real arr[]) : X(arr[0]), Y(arr[1])
			{
			}
			
			/*
			** Initializes a new instance of the Vector2 class.
			** Parameters
			**	other	- another Vector2 to copy the X and Y components from.
			** Returns
			**	nothing
			*/
			Vector2(const Vector2 &other) : X(other.X), Y(other.Y)
			{
			}

			/*
			** Determines whether or not this Vector2 is normalized.
			** Parameters
			**	none
			** Returns
			**	True if this Vector2 is normalized.
			*/
			bool IsNormalized() const
			{
				return (CommonUtils::Abs((real)(X*X + Y*Y) - 1) < TEKSTORM_REAL_EPSILON);
			}

			/*
			** Calculates the length of this Vector2.
			** Parameters
			**	none
			** Returns
			**	The length of this Vector2.
			**	Length is calculated as sqrt(x^2 + y^2).
			*/
			real GetLength() const
			{
				return (real)sqrt(X*X + Y*Y);
			}

			/*
			** Calculates the squared length of this Vector2.
			** Parameters
			**	none
			** Returns
			**	The length of this Vector2 squared.
			**	Length squared is calculated as x^2 + y^2.
			*/
			real GetLengthSquared() const
			{
				return X*X + Y*Y;
			}

			/*
			** Normalizes this Vector2.
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
				}
			}

			/*
			** Adds two Vector2 objects together.
			** Parameters
			**	left	- the left Vector2 used in addition
			**	right	- the right Vector2 used in addition
			**	result	- a reference to a Vector2 that will store the result
			** Returns
			**	nothing
			*/
			static void Add(const Vector2 &left, const Vector2 &right, Vector2 &result)
			{
				result.X = left.X + right.X;
				result.Y = left.Y + right.Y;
			}

			/*
			** Adds two Vector2 objects together.
			** Parameters
			**	left	- the left Vector2 used in addition
			**	right	- the right Vector2 used in addition
			** Returns
			**	the result of adding left and right together.
			*/
			static Vector2 Add(const Vector2 &left, const Vector2 &right)
			{
				return Vector2(left.X + right.X, left.Y + right.Y);
			}

			/*
			** Subtracts two Vector2 objects.
			** Parameters
			**	left	- the left Vector2 used in subtraction
			**	right	- the right Vector2 used in subtraction
			**	result	- a reference to a Vector2 object that will store the result
			** Returns
			**	nothing
			*/
			static void Subtract(const Vector2 &left, const Vector2 &right, Vector2 &result)
			{
				result.X = left.X - right.X;
				result.Y = left.Y - right.Y;
			}

			/*
			** Subtracts two Vector2 objects.
			** Parameters
			**	left	- the left Vector2 used in subtraction
			**	right	- the right Vector2 used in subtraction
			** Returns
			**	the result of the subtraction.
			*/
			static Vector2 Subtract(const Vector2 &left, const Vector2 &right)
			{
				return Vector2(left.X - right.X, left.Y - right.Y);
			}

			/*
			** Multiplies a Vector2 object by a scalar.
			** Parameters
			**	value	- the Vector2 used in multiplication
			**	scale	- the scalar value to be used
			**	result	- a reference to a Vector2 object to store the result
			** Returns
			**	nothing
			*/
			static void Multiply(const Vector2 &value, real scale, Vector2 &result)
			{
				result.X = value.X * scale;
				result.Y = value.Y * scale;
			}

			/*
			** Multiplies a Vector2 object by a scalar.
			** Parameters
			**	value	- the Vector2 used in multiplication
			**	scale	- the scalar used 
			** Returns
			**	the result of multiplying value by scale.
			*/
			static Vector2 Multiply(const Vector2 &value, real scale)
			{
				return Vector2(value.X * scale, value.Y * scale);
			}

			/*
			** Modulates a vector with another vector by performing component-wise multiplication.
			** Parameters
			**	left	- the left Vector2 used in modulation
			**	right	- the right Vector2 used in modulation
			**	result	- a reference to a Vector2 that will store the result
			** Returns
			**	nothing
			*/
			static void Modulate(const Vector2 &left, const Vector2 &right, Vector2 &result)
			{
				result.X = left.X * right.X;
				result.Y = left.Y * right.Y;
			}

			/*
			** Modulates a vector with another vector by performing component-wise multiplication.
			** Parameters
			**	left	- the left Vector2 used in modulation
			**	right	- the right Vector2 used in modulation
			** Returns
			**	a Vector2 containing the result of modulation.
			*/
			static Vector2 Modulate(const Vector2 &left, const Vector2 &right)
			{
				return Vector2(left.X * right.X, left.Y * right.Y);
			}

			/*
			** Divides each component of this vector with the given scalar value.
			** Parameters
			**	value	- the Vector2 that will be divided
			**	scale	- the scalar value to divide by
			**	result	- a reference to a Vector2 that will store the result
			** Returns
			**	nothing
			*/
			static void Divide(const Vector2 &value, real scale, Vector2 &result)
			{
				result.X = value.X / scale;
				result.Y = value.Y / scale;
			}

			/*
			** Divides each component of this vector with the given scalar value.
			** Parameters
			**	value	- the Vector2 that will be divided
			**	scale	- the scalar value to divide by
			** Returns
			**	a Vector2 containing the result of the division.
			*/
			static Vector2 Divide(const Vector2 &value, real scale)
			{
				return Vector2(value.X / scale, value.Y / scale);
			}

			/*
			** Negates each component of a vector.
			** Parameters
			**	value	- the Vector2 that should be negated
			**	result	- a reference to a Vector2 that will store the result
			** Returns
			**	nothing
			*/
			static void Negate(const Vector2 &value, Vector2 &result)
			{
				result.X = -value.X;
				result.Y = -value.Y;
			}

			/*
			** Negates each component of a vector.
			** Parameters
			**	value	- the Vector2 that should be negated
			** Returns
			**	the negated version of 'value'.
			*/
			static Vector2 Negate(const Vector2 &value)
			{
				return Vector2(-value.X, -value.Y);
			}

			/*
			** Takes the absolute value of each component.
			** Parameters
			**	value	- the Vector2 to take the absolute value of
			**	result	- a reference to a Vector2 that will store the result
			** Returns
			**	nothing
			*/
			static void Abs(const Vector2 &value, Vector2 &result)
			{
				result.X = CommonUtils::Abs(value.X);
				result.Y = CommonUtils::Abs(value.Y);
			}

			/*
			** Takes the absolute value of each component.
			** Parameters
			**	value	- the Vector2 to take the absolute value of
			** Returns
			**	the absolute value version of 'value'.
			*/
			static Vector2 Abs(const Vector2 &value)
			{
				return Vector2((real)CommonUtils::Abs(value.X), (real)CommonUtils::Abs(value.Y));
			}

			/*
			** Returns a Vector2 containing the 2D cartesian coordinates of a point
			**	specified in Barycentric coordinates relative to a 2D triangle.
			** Parameters
			**	value1	- A Vector2 containing the 2D cartesian coordinates of vertex1 of the triangle.
			**	value2	- A Vector2 containing the 2D cartesian coordinates of vertex2 of the triangle.
			**	value3	- A Vector2 containing the 2D cartesian coordinates of vertex3 of the triangle.
			**	amount1	- Barycentric coordinate b2, which expresses the weighting factor toward vertex 2.
			**	amount2	- Barycentric coordinate b3, which expresses the weighting factor toward vertex 3.
			**	result	- A reference to a Vector2 which will store the 2D cartesian coordinates.
			** Returns
			**	nothing
			*/
			static void Barycentric(const Vector2 &value1, const Vector2 &value2, const Vector2 &value3,
				real amount1, real amount2, Vector2 &result)
			{
				result.X = (value1.X + (amount1 * (value2.X - value1.X))) + (amount2 * (value3.X - value1.X));
				result.Y = (value1.Y + (amount1 * (value2.Y - value1.Y))) + (amount2 * (value3.Y - value1.Y));
			}

			/*
			** Returns a Vector2 containing the 2D cartesian coordinates of a point
			**	specified in Barycentric coordinates relative to a 2D triangle.
			** Parameters
			**	value1	- A Vector2 containing the 2D cartesian coordinates of vertex1 of the triangle.
			**	value2	- A Vector2 containing the 2D cartesian coordinates of vertex2 of the triangle.
			**	value3	- A Vector2 containing the 2D cartesian coordinates of vertex3 of the triangle.
			**	amount1	- Barycentric coordinate b2, which expresses the weighting factor toward vertex 2.
			**	amount2	- Barycentric coordinate b3, which expresses the weighting factor toward vertex 3.
			** Returns
			**	a Vector2 which holds the 2D cartesian coordinates.
			*/
			static Vector2 Barycentric(const Vector2 &value1, const Vector2 &value2, const Vector2 &value3,
				real amount1, real amount2)
			{
				return Vector2((value1.X + (amount1 * (value2.X - value1.X))) + (amount2 * (value3.X - value1.X)),
                (value1.Y + (amount1 * (value2.Y - value1.Y))) + (amount2 * (value3.Y - value1.Y)));
			}

			/*
			** Restricts a value to be within a specified range.
			** Parameters
			**	value	- The value to clamp
			**	min		- The minimum value
			**	max		- The maximum value
			**	result	- A reference to a Vector2 which will store the clamped value.
			** Returns
			**	nothing
			*/
			static void Clamp(const Vector2 &value, const Vector2 &min, const Vector2 &max, Vector2 &result)
			{
				real x = value.X;
				x = (x > max.X) ? max.X : x;
				x = (x < min.X) ? min.X : x;

				real y = value.Y;
				y = (y > max.Y) ? max.Y : y;
				y = (y < min.Y) ? min.Y : y;

				result.X = x;
				result.Y = y;
			}

			/*
			** Restricts a value to be within a specified range.
			** Parameters
			**	value	- The value to clamp
			**	min		- The minimum value
			**	max		- The maximum value
			** Returns
			**	a Vector2 whose components are within the min and max range.
			*/
			static Vector2 Clamp(const Vector2 &value, const Vector2 &min, const Vector2 &max)
			{
				real x = value.X;
				x = (x > max.X) ? max.X : x;
				x = (x < min.X) ? min.X : x;

				real y = value.Y;
				y = (y > max.Y) ? max.Y : y;
				y = (y < min.Y) ? min.Y : y;

				return Vector2(x, y);
			}

			/*
			** Calculates the distance between two Vector2 objects.
			** Parameters
			**	value1	- The first Vector2
			**	value2	- The second Vector2
			** Returns
			**	the distance between the two vectors.
			*/
			static real GetDistance(const Vector2 &value1, const Vector2 &value2)
			{
				real x = value1.X - value2.X;
				real y = value1.Y - value2.Y;

				return (real)sqrt((real)(x*x + y*y));
			}

			/*
			** Calculates the distance squared between two Vector2 objects.
			** Parameters
			**	value1	- The first Vector2
			**	value2	- The second Vector2
			** Returns
			**	the distance squared between two vectors.
			*/
			static real GetDistanceSquared(const Vector2 &value1, const Vector2 &value2)
			{
				real x = value1.X - value2.X;
				real y = value1.Y - value2.Y;

				return x*x + y*y;
			}

			/*
			** Calculates the dot product of two vectors.
			** Parameters
			**	left	- The first source Vector2
			**	right	- The second source Vector2
			** Returns
			**	the dot product.
			*/
			static real GetDot(const Vector2 &value1, const Vector2 &value2)
			{
				return (value1.X * value2.X) + (value1.Y * value2.Y);
			}

			/*
			** Calculates a vector that is perpendicular to the given vector.
			** Parameters
			**	source	- The source Vector2.
			**	result	- A reference to a Vector2 that will store the result.
			** Returns
			**	nothing
			*/
			static void GetPerp(const Vector2 &source, Vector2 &result)
			{
				result.X = -source.Y;
				result.Y = source.X;
			}

			/*
			** Calculates a vector that is perpendicular to the given vector.
			** Parameters
			**	source	- The source Vector2.
			** Returns
			**	the Vector2 that is perpendicular to source.
			*/
			static Vector2 GetPerp(const Vector2 &source)
			{
				return Vector2(-source.Y, source.X);
			}

			/*
			** Calculates the perpendicular dot product.
			** Parameters
			**	source1		- The first source Vector2
			**	source2		- The second source Vector2
			** Returns
			**	the perpendicular dot product.
			*/
			static real GetPerpDot(const Vector2 &source1, const Vector2 &source2)
			{
				return (-source1.Y*source2.X + source1.X*source2.Y);
			}

			/*
			** Normalizes the given vetor.
			** Parameters
			**	source		- The vector to normalize
			**	result		- A reference to a Vector2 which will store the normalized Vector.
			** Returns
			**	nothing
			*/
			static void Normalize(const Vector2 &source, Vector2 &result)
			{
				result.X = source.X;
				result.Y = source.Y;
				result.Normalize();
			}

			/*
			** Normalizes the given vetor.
			** Parameters
			**	source		- The vector to normalize
			** Returns
			**	the normalized 'source' vector.
			*/
			static Vector2 Normalize(const Vector2 &source)
			{
				Vector2 temp = source;
				temp.Normalize();

				return temp;
			}

			/*
			** Performs a linear interpolation between two vectors.
			** Parameters
			**	start		- The starting vector.
			**	end			- The ending vector.
			**	amount		- A value between 0 and 1 indicating the weight of 'end'.
			**	result		- A reference to a Vector2 which will store the result.
			** Returns
			**	nothing
			*/
			static void Lerp(const Vector2 &start, const Vector2 &end, real amount, Vector2 &result)
			{
				result.X = start.X + ((end.X - start.X) * amount);
				result.Y = start.Y + ((end.Y - start.Y) * amount);
			}
			
			/*
			** Performs a linear interpolation between two vectors.
			** Parameters
			**	start		- The starting vector.
			**	end			- The ending vector.
			**	amount		- A value between 0 and 1 indicating the weight of 'end'.
			** Returns
			**	a Vector2 containing the result of the linear interpolation.
			*/
			static Vector2 Lerp(const Vector2 &start, const Vector2 &end, real amount)
			{
				return Vector2(start.X + ((end.X - start.X) * amount),
					start.Y + ((end.Y - start.Y) * amount));
			}

			/*
			** Performs a cubic interpolation between two vectors.
			** Parameters
			**	start		- The starting vector.
			**	end			- The ending vector.
			**	amount		- A value between 0 and 1 indicating the weight of 'end'.
			**	result		- A reference to a Vector2 which will store the result of the interpolation.
			** Returns
			**	nothing
			*/
			static void SmoothStep(const Vector2 &start, const Vector2 &end, real amount, Vector2 &result)
			{
				amount = (amount > (real)1.0) ? (real)1.0 : ((amount < (real)0.0) ? (real)0.0 : amount);
				amount = (amount * amount) * (real)(3.0 - (2.0 * amount));

				result.X = start.X + ((end.X - start.X) * amount);
				result.Y = start.Y + ((end.Y - start.Y) * amount);
			}

			/*
			** Performs a cubic interpolation between two vectors.
			** Parameters
			**	start		- The starting vector.
			**	end			- The ending vector.
			**	amount		- A value between 0 and 1 indicating the weight of 'end'.
			** Returns
			**	a Vector2 containing the result of the interpolation.
			*/
			static Vector2 SmoothStep(const Vector2 &start, const Vector2 &end, real amount)
			{
				amount = (amount > (real)1.0) ? (real)1.0 : ((amount < (real)0.0) ? (real)0.0 : amount);
				amount = (amount * amount) * (real)(3.0 - (2.0 * amount));

				return Vector2(start.X + ((end.X - start.X) * amount),
					start.Y + ((end.Y - start.Y) * amount));
			}

			/*
			** Performs a Hermite spline interpolation
			** Parameters
			**	value1		- The first source vector.
			**	tangent1	- The first source tangent vector.
			**	value2		- The second source vector.
			**	tangent2	- The second source tangent vector.
			**	amount		- The weighting factor
			**	result		- A reference to a Vector2 that will store the result.
			** Returns
			**	nothing
			*/
			static void Hermite(const Vector2 &value1, const Vector2 &tangent1,
				const Vector2 &value2, const Vector2 &tangent2, real amount, Vector2 &result)
			{
				real squared = amount * amount;
				real cubed = amount * squared;
				real part1 = (((real)2.0 * cubed) - ((real)3.0 * squared)) + (real)1.0;
				real part2 = ((real)-2.0 * cubed) + ((real)3.0 * squared);
				real part3 = (cubed - ((real)2.0 * squared)) + amount;
				real part4 = cubed - squared;

				result.X = (((value1.X * part1) + (value2.X * part2)) + (tangent1.X * part3)) + (tangent2.X * part4);
				result.Y = (((value1.Y * part1) + (value2.Y * part2)) + (tangent1.Y * part3)) + (tangent2.Y * part4);
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
			**	a Vector2 containing the result of the interpolation
			*/
			static Vector2 Hermite(const Vector2 &value1, const Vector2 &tangent1,
				const Vector2 &value2, const Vector2 &tangent2, real amount)
			{
								real squared = amount * amount;
				real cubed = amount * squared;
				real part1 = (((real)2.0 * cubed) - ((real)3.0 * squared)) + (real)1.0;
				real part2 = ((real)-2.0 * cubed) + ((real)3.0 * squared);
				real part3 = (cubed - ((real)2.0 * squared)) + amount;
				real part4 = cubed - squared;

				return Vector2((((value1.X * part1) + (value2.X * part2)) + (tangent1.X * part3)) + (tangent2.X * part4), 
					(((value1.Y * part1) + (value2.Y * part2)) + (tangent1.Y * part3)) + (tangent2.Y * part4));
			}

			/*
			** Performs a Catmull-Rom interpolation using the specified positions.
			** Parameters
			**	value1		- The first position in the interpolation.
			**	value2		- The second position in the interpolation.
			**	value3		- The third position in the interpolation.
			**	value4		- The fourth position in the interpolation.
			**	amount		- The weighting factor.
			**	result		- A reference to a Vector2 which stores the result.
			** Returns
			**	nothing
			*/
			static void CatmullRom(const Vector2 &value1, const Vector2 &value2,
				const Vector2 &value3, const Vector2 &value4, real amount, Vector2 &result)
			{
				real squared = amount * amount;
				real cubed = amount * squared;

				result.X = (real)0.5 * (((((real)2.0 * value2.X) + ((-value1.X + value3.X) * amount)) +
					((((((real)2.0 * value1.X) - ((real)5.0 * value2.X)) + ((real)4.0 * value3.X)) - value4.X) * squared)) +
					((((-value1.X + ((real)3.0 * value2.X)) - ((real)3.0 * value3.X)) + value4.X) * cubed));

				result.Y = (real)0.5 * (((((real)2.0 * value2.Y) + ((-value1.Y + value3.Y) * amount)) +
					((((((real)2.0 * value1.Y) - ((real)5.0 * value2.Y)) + ((real)4.0 * value3.Y)) - value4.Y) * squared)) +
					((((-value1.Y + ((real)3.0 * value2.Y)) - ((real)3.0 * value3.Y)) + value4.Y) * cubed));
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
			**	a Vector2 containing the result of the interpolation.
			*/
			static Vector2 CatmullRom(const Vector2 &value1, const Vector2 &value2,
				const Vector2 &value3, const Vector2 &value4, real amount)
			{
				Vector2 temp;
				real squared = amount * amount;
				real cubed = amount * squared;

				temp.X = (real)0.5 * (((((real)2.0 * value2.X) + ((-value1.X + value3.X) * amount)) +
					((((((real)2.0 * value1.X) - ((real)5.0 * value2.X)) + ((real)4.0 * value3.X)) - value4.X) * squared)) +
					((((-value1.X + ((real)3.0 * value2.X)) - ((real)3.0 * value3.X)) + value4.X) * cubed));

				temp.Y = (real)0.5 * (((((real)2.0 * value2.Y) + ((-value1.Y + value3.Y) * amount)) +
					((((((real)2.0 * value1.Y) - ((real)5.0 * value2.Y)) + ((real)4.0 * value3.Y)) - value4.Y) * squared)) +
					((((-value1.Y + ((real)3.0 * value2.Y)) - ((real)3.0 * value3.Y)) + value4.Y) * cubed));

				return temp;
			}

			/*
			** Returns a vector containing the largst components of the specified vectors.
			** Parameters
			**	left		- The first source vector
			**	right		- The second source vector
			**	result		- A reference to a Vector2 which will store the result.
			** Returns
			**	nothing
			*/
			static void Max(const Vector2 &left, const Vector2 &right, Vector2 &result)
			{
				result.X = (left.X > right.X) ? left.X : right.X;
				result.Y = (left.Y > right.Y) ? left.Y : right.Y;
			}

			/*
			** Returns a vector containing the largest components of the specified vectors.
			** Parameters
			**	left		- The first source vector
			**	right		- The second source vector
			** Returns
			**	the Vector2 which the largest components of each vector.
			*/
			static Vector2 Max(const Vector2 &left, const Vector2 &right)
			{
				return Vector2((left.X > right.X) ? left.X : right.X, (left.Y > right.Y) ? left.Y : right.Y);
			}

			/*
			** Returns a vector containing the smallest components of the specified vectors.
			** Parameters
			**	left		- The first source vector
			**	right		- The second source vector
			**	result		- A reference to a Vector2 which will store the result.
			** Returns
			**	nothing
			*/
			static void Min(const Vector2 &left, const Vector2 &right, Vector2 &result)
			{
				result.X = (left.X < right.X) ? left.X : right.X;
				result.Y = (left.Y < right.Y) ? left.Y : right.Y;
			}

			/*
			** Returns a vector containing the smallest components of the specified vectors.
			** Parameters
			**	left		- The first source vector
			**	right		- The second source vector
			** Returns
			**	the Vector2 which the smallest components of each vector.
			*/
			static Vector2 Min(const Vector2 &left, const Vector2 &right)
			{
				return Vector2((left.X < right.X) ? left.X : right.X, (left.Y < right.Y) ? left.Y : right.Y);
			}

			/*
			** Returns the reflection of a vector off of a surface that has the specified normal.
			** Parameters
			**	source		- The source vector.
			**	normal		- The normal of the surface.
			**	result		- A reference to a Vector2 that will store the result.
			** Returns
			**	nothing
			*/
			static void Reflect(const Vector2 &source, const Vector2 &normal, Vector2 &result)
			{
				real dot = (source.X * normal.X) + (source.Y * normal.Y);

				result.X = source.X - (((real)2.0 * dot) * normal.X);
				result.Y = source.Y - (((real)2.0 * dot) * normal.Y);
			}

			/*
			** Returns the reflection of a vector off of a surface that has the specified normal.
			** Parameters
			**	source		- The source vector.
			**	normal		- The normal of the surface.
			** Returns
			**	a Vector2 that contains the reflection of source.
			*/
			static Vector2 Reflect(const Vector2 &source, const Vector2 &normal)
			{
				real dot = (source.X * normal.X) + (source.Y * normal.Y);

				return Vector2(source.X - (((real)2.0 * dot) * normal.X), 
					source.Y - (((real)2.0 * dot) * normal.Y));
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
			static void Orthogonalize(Vector2 destination[], const Vector2 source[], int length)
			{
				for (int i = 0; i < length; ++i)
				{
					Vector2 newVector = source[i];

					for (int r = 0; r < i; ++r)
					{
						newVector -= destination[r] * (real)(Vector2::GetDot(destination[r], newVector) / Vector2::GetDot(destination[r], destination[r]));
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
			static void Orthonormalize(Vector2 destination[], const Vector2 source[], int length)
			{
				for (int i = 0; i < length; ++i)
				{
					Vector2 newVector = source[i];

					for (int r = 0; r < i; ++r)
					{
						newVector -= destination[r] * Vector2::GetDot(destination[r], newVector);
					}

					newVector.Normalize();
					destination[i] = newVector;
				}
			}

			/*
			** Transforms a 2D vector by the given Quaternion rotation.
			** Parameters
			**	source		- The vector to rotate.
			**	rotation	- The Quaternion rotation to apply.
			**	result		- A reference to a Vector2 which stores the result of the rotation.
			** Returns
			**	nothing
			*/
			static void Transform(const Vector2 &source, const Quaternion &rotation, Vector2 &result);

			/*
			** Transforms a 2D vector by the given Quaternion rotation.
			** Parameters
			**	source		- The vector to rotate.
			**	rotation	- The Quaternion rotation to apply.
			** Returns
			**	the rotated Vector2.
			*/
			static Vector2 Transform(const Vector2 &source, const Quaternion &rotation);

			/*
			** Transforms an array of 2D vectors by the given Quaternion rotation.
			** Parameters
			**	source		- The array of vectors to rotate.
			**	rotation	- The Quaternion rotation to apply.
			**	destination	- The array of vectors that will have been rotated.
			**	length		- The number of elements in the array of vectors.
			** Returns
			**	nothing -- all results are returned via reference.
			*/
			static void Transform(const Vector2 source[], const Quaternion &rotation, Vector2 destination[], int length);

			/*
			** Transforms the given 2D vector by the given Matrix3.
			** Parameters
			**	source		- the vector to transform
			**	transform	- the transformation matrix
			**	result		- a reference to a Vector3 which will store the result of the transformation.
			** Returns
			**	nothing
			*/
			static void Transform(const Vector2 &source, const Matrix3 &transform, Vector3 &result);

			/*
			** Transforms the given 2D vector by the given Matrix3.
			** Parameters
			**	source		- the vector to transform
			**	transform	- the transformation matrix
			** Returns
			**	the transformed vector (as a Vector3).
			*/
			static Vector3 Transform(const Vector2 &source, const Matrix3 &transform);

			/*
			** Transforms the given 2D vectors by the given Matrix3.
			** Parameters
			**	source		- the array of vectors to transform
			**	transform	- the transformation matrix
			**	destination	- the destination of vectors
			**	length		- the number of elements in the source array
			** Returns
			**	nothing
			*/
			static void Transform(const Vector2 source[], const Matrix3 &transform, Vector3 destination[], int length);

			/*
			** Transforms the given 2D vector by the given Matrix4.
			** Parameters
			**	source		- the vector to transform
			**	transform	- the transformation matrix
			**	result		- a reference to a Vector4 which will store the result of the transformation.
			** Returns
			**	nothing
			*/
			static void Transform(const Vector2 &source, const Matrix4 &transform, Vector4 &result);

			/*
			** Transforms the given 2D vector by the given Matrix4.
			** Parameters
			**	source		- the vector to transform
			**	transform	- the transformation matrix
			** Returns
			**	the transformed vector (as a Vector3).
			*/
			static Vector4 Transform(const Vector2 &source, const Matrix4 &transform);

			/*
			** Transforms the given 2D vectors by the given Matrix4.
			** Parameters
			**	source		- the array of vectors to transform
			**	transform	- the transformation matrix
			**	destination	- the destination of vectors
			**	length		- the number of elements in the source array
			** Returns
			**	nothing
			*/
			static void Transform(const Vector2 source[], const Matrix4 &transform, Vector4 destination[], int length);

			/*
			** Transforms a coordinate using the given Matrix3.
			** Parameters
			**	coordinate		- the coordinate to transform
			**	transform		- the Matrix3 transformation
			**	result			- the Vector2 which stores the result of the transformation
			** Returns
			**	nothing
			*/
			static void TransformCoordinate(const Vector2 &coordinate, const Matrix3 &transform, Vector2 &result);

			/*
			** Transforms a coordinate using the given Matrix3.
			** Parameters
			**	coordinate		- the coordinate to transform
			**	transform		- the Matrix3 transformation
			** Returns
			**	the transformed Vector2.
			*/
			static Vector2 TransformCoordinate(const Vector2 &coordinate, const Matrix3 &transform);

			/*
			** Transforms a coordinate using the given Matrix4.
			** Parameters
			**	coordinate		- the coordinate to transform
			**	transform		- the Matrix4 transformation
			**	result			- the Vector2 which stores the result of the transformation
			** Returns
			**	nothing
			*/
			static void TransformCoordinate(const Vector2 &coordinate, const Matrix4 &transform, Vector2 &result);

			/*
			** Transforms a coordinate using the given Matrix4.
			** Parameters
			**	coordinate		- the coordinate to transform
			**	transform		- the Matrix4 transformation
			** Returns
			**	the transformed Vector2.
			*/
			static Vector2 TransformCoordinate(const Vector2 &coordinate, const Matrix4 &transform);

			/*
			** Transforms an array of coordinates using the given Matrix3.
			** Parameters
			**	source			- the coordinates to transform
			**	transform		- the Matrix3 transformation
			**	destination		- the destination array
			**	length			- the number of coordinates to transform
			** Returns
			**	nothing
			*/
			static void TransformCoordinate(const Vector2 source[], const Matrix3 &transform, Vector2 destination[], int length);

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
			static void TransformCoordinate(const Vector2 source[], const Matrix4 &transform, Vector2 destination[], int length);

			/*
			** Performs a normal transformation using the given Matrix3.
			** Parameters
			**	normal		- The normal vector to transform
			**	transform	- The Matrix3 transformation
			**	result		- A reference to a Vector2 that will store the result.
			** Returns
			**	nothing
			*/
			static void TransformNormal(const Vector2 &normal, const Matrix3 &transform, Vector2 &result);

			/*
			** Performs a normal transformation using the given Matrix3.
			** Parameters
			**	normal		- The normal vector to transform
			**	transform	- The Matrix3 transformation
			** Returns
			**	the transformed vector.
			*/
			static Vector2 TransformNormal(const Vector2 &normal, const Matrix3 &transform);

			/*
			** Performs a normal transformation using the given Matrix4.
			** Parameters
			**	normal		- The normal vector to transform
			**	transform	- The Matrix4 transformation
			**	result		- A reference to a Vector2 that will store the result.
			** Returns
			**	nothing
			*/
			static void TransformNormal(const Vector2 &normal, const Matrix4 &transform, Vector2 &result);

			/*
			** Performs a normal transformation using the given Matrix4.
			** Parameters
			**	normal		- The normal vector to transform
			**	transform	- The Matrix4 transformation
			** Returns
			**	the transformed vector.
			*/
			static Vector2 TransformNormal(const Vector2 &normal, const Matrix4 &transform);

			/*
			** Performs a normal transformation using the given Matrix3.
			** Parameters
			**	source		- The array of normal vectors to transform
			**	transform	- The Matrix3 transformation
			**	destination	- The destination array
			**	length		- The number of vectors in the source array.
			** Returns
			**	nothing
			*/
			static void TransformNormal(const Vector2 source[], const Matrix3 &transform, Vector2 destination[], int length);

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
			static void TransformNormal(const Vector2 source[], const Matrix4 &transform, Vector2 destination[], int length);

			/*
			** Adds two vectors
			*/
			Vector2 operator+(const Vector2 &other) const
			{
				return Vector2(X + other.X, Y + other.Y);
			}

			/*
			** Adds a scalar to a vector
			*/
			Vector2 operator+(real scale) const
			{
				return Vector2(X + scale, Y + scale);
			}

			/*
			** Adds this vector with another vector
			*/
			Vector2& operator+=(const Vector2 &other)
			{
				X += other.X;
				Y += other.Y;

				return *this;
			}

			/*
			** Adds a scalar to this vector
			*/
			Vector2& operator+=(real scale)
			{
				X += scale;
				Y += scale;

				return *this;
			}


			/*
			** Subtracts two vectors.
			*/
			Vector2 operator-(const Vector2 &other) const
			{
				return Vector2(X - other.X, Y - other.Y);
			}
			
			/*
			** Subtracts a scalar from a vector
			*/
			Vector2 operator-(real scale) const
			{
				return Vector2(X - scale, Y - scale);
			}

			/*
			** Subtracts a vector from this vector
			*/
			Vector2& operator-=(const Vector2 &other)
			{
				X -= other.X;
				Y -= other.Y;

				return *this;
			}

			/*
			** Subtracts a scalar from this vector
			*/
			Vector2& operator-=(real scale)
			{
				X -= scale;
				Y -= scale;

				return *this;
			}
			/*
			** Unary plus - does nothing
			*/
			Vector2 operator+() const
			{
				return Vector2(X, Y);
			}

			/*
			** Negates a vector.
			*/
			Vector2 operator-() const
			{
				return Vector2(-X, -Y);
			}

			/*
			** Scales a vector
			*/
			Vector2 operator*(real scale) const
			{
				return Vector2(X * scale, Y * scale);
			}

			/*
			** Scales this vector
			*/
			Vector2& operator*=(real scale)
			{
				X *= scale;
				Y *= scale;

				return *this;
			}

			/*
			** Divides a vector by a scalar.
			*/
			Vector2 operator/(real scale)
			{
				real inv = (real)1.0 / scale;
				return Vector2(X * inv, Y * inv);
			}

			/*
			** Divides this vector by a scalar
			*/
			Vector2& operator/=(real scale)
			{
				real inv = (real)1.0 / scale;
				X *= inv;
				Y *= inv;

				return *this;
			}

			/*
			** Tests for equality
			*/
			bool operator==(const Vector2 &other)
			{
				return ( X == other.X && Y == other.Y );
			}

			/*
			** Tests for inequality
			*/
			bool operator!=(const Vector2 &other)
			{
				return ( X != other.X || Y != other.Y );
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
				default:
					throw std::runtime_error("index out of range");
				};
			}
		};
	}
}
#endif /* _TEKSTORM_VECTOR2_H */