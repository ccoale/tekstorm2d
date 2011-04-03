#pragma once
#ifndef _TEKSTORM_QUATERNION_H
#define _TEKSTORM_QUATERNION_H
#include "../CommonUtils.h"
#include "Vector4.h"

namespace Tekstorm
{
	namespace Math
	{
		class Quaternion
		{
		public:
			/*
			** The size of the quaternion, in bytes.
			*/
			static const int SizeInBytes;

			/*
			** A quaternion with all elements set to 0.
			*/
			static const Quaternion Zero;

			/*
			** A quaternion with all elements set to 1.
			*/
			static const Quaternion One;

			/*
			** The identity quaternion (0, 0, 0, 1)
			*/
			static const Quaternion Identity;

			/*
			** The X-component of the quaternion
			*/
			real X;

			/*
			** The Y-component of the quaternion
			*/
			real Y;

			/*
			** The Z-component of the quaternion
			*/
			real Z;

			/*
			** The W-component of the quaternion
			*/
			real W;

			/*
			** Initializes a new instance of Quaternion
			** Parameters
			**	none
			** Returns
			**	nothing
			*/
			Quaternion()
			{
				X = Y = Z = W = (real)0.0;
			}

			/*
			** Initializes a new instance of Quaternion.
			** Parameters
			**	value		- a Vector4 describing all elements of this quaternion.
			** Returns
			**	nothing
			*/
			Quaternion(const Vector4 &value)
			{
				X = value.X;
				Y = value.Y;
				Z = value.Z;
				W = value.W;
			}

			/*
			** Initializes a new instance of Quaternion.
			** Parameters
			**	value		- A vector3 describing the first 3 elements of this quaternion
			**	w			- the value of the 4th element of this quaternion
			** Returns
			**	nothing
			*/
			Quaternion(const Vector3 &value, real w)
			{
				X = value.X;
				Y = value.Y;
				Z = value.Z;
				W = w;
			}

			/*
			** Initializes a new instance of Quaternion.
			** Parameters
			**	value		- A Vector2 describing the first 2 elements of this quaternion
			**	z			- the value of the z component of this quaternion
			**	w			- the value of the w component of this quaternion
			** Returns
			**	nothing
			*/
			Quaternion(const Vector2 &value, real z, real w)
			{
				X = value.X;
				Y = value.Y;
				Z = z;
				W = w;
			}

			/*
			** Initializes a new instance of Quaternion
			** Parameters
			**	x			- value of the x component
			**	y			- value of the y component
			**	z			- value of the z component
			**	w			- value of the w component
			** Returns
			**	nothing
			*/
			Quaternion(real x, real y, real z, real w)
			{
				X = x;
				Y = y;
				Z = z;
				W = w;
			}

			/*
			** Initializes a new instance of Quaternion
			** Parameters
			**	values		- a 4 element array which contains the values of each Quaternion component
			**				- values[0] = X, values[1] = Y, values[2] = Z, values[3] = W
			** Returns
			**	nothing
			*/
			Quaternion(const real values[])
			{
				X = values[0];
				Y = values[1];
				Z = values[2];
				W = values[3];
			}

			/*
			** Gets a value indiciating whether this instance is an identity.
			** Parameters
			**	none
			** Returns
			**	true if this instance is an identity
			*/
			bool IsIdentity() const
			{
				return (X == (real)0) && (Y == (real)0) && (Z == (real)0) && (W == (real)1);
			}

			/*
			** Gets the angle (in radians) of this Quaternion.
			** Parameters
			**	none
			** Returns
			**	the angle, in radians
			*/
			real GetAngle() const
			{
				real len = X*X + Y*Y + Z*Z;
				if (len == (real)0)
					return len;

				return (real)((real)2.0 * acos(W));
			}

			/*
			** Gets the axis components of this Quaternion
			** Parameters
			**	none
			** Returns
			**	the axis components o fthe quaternion
			*/
			Vector3 GetAxes() const
			{
				real len = X*X + Y*Y + Z*Z;
				if (len == (real)0)
					return Vector3::UnitX;

				real inv = (real)1.0 / len;
				return Vector3(X * inv, Y * inv, Z * inv);
			}

			/*
			** Calculates the length of this Quaternion
			** Parameters
			**	none
			** Returns
			**	the length of this quaternion
			*/
			real GetLength() const
			{
				return (real)sqrt(X*X + Y*Y + Z*Z + W*W);
			}

			/*
			** Calculates the squared length of this Quaternion
			** Parameters
			**	none
			** Returns
			**	the length of this quaternion, squared
			*/
			real GetLengthSquared() const
			{
				return X*X + Y*Y + Z*Z + W*W;
			}

			/*
			** Conjugates this Quaternion
			** Parameters
			**	none
			** Returns
			**	nothing
			*/
			void Conjugate()
			{
				X = -X;
				Y = -Y;
				Z = -Z;
			}

			/*
			** Conjugates and renormalizes this Quaternion
			** Parameters
			**	none
			** Returns
			**	nothing
			*/
			void Invert()
			{
				real lenSq = X*X + Y*Y + Z*Z + W*W;
				if (lenSq > (real)0.0)
				{
					lenSq = (real)1.0 / lenSq;

					X *= -lenSq;
					Y *= -lenSq;
					Z *= -lenSq;
					W *= lenSq; // this is purposely not -lenSq
				}
			}

			/*
			** Converts this Quaternion into a unit Quaternion
			** Parameters
			**	none
			** Returns
			**	nothing
			*/
			void Normalize()
			{
				real len = (real)sqrt(X*X + Y*Y + Z*Z + W*W);
				if (len > (real)0.0)
				{
					real inv = (real)1.0 / len;
					X *= inv;
					Y *= inv;
					Z *= inv;
					W *= inv;
				}
			}

			/*
			** Adds two quaternions
			** Parameters
			**	left		- The first quaternion to add
			**	right		- The second quaternion to add
			**	result		- The reesulting quaternion
			** Returns
			**	nothing
			*/
			static void Add(const Quaternion &left, const Quaternion &right, Quaternion &result)
			{
				result.X = left.X + right.X;
				result.Y = left.Y + right.Y;
				result.Z = left.Z + right.Z;
				result.W = left.W + right.W;
			}

			/*
			** Adds two quaternions
			** Parameters
			**	left		- The first quaternion to add
			**	right		- The second quaternion to add
			** Returns
			**	the resulting quaternion
			*/
			static Quaternion Add(const Quaternion &left, const Quaternion &right)
			{
				return Quaternion(left.X + right.X,
					left.Y + right.Y,
					left.Z + right.Z,
					left.W + right.W);
			}

			/*
			** Subtracts two quaternions
			** Parameters
			**	left		- The first quaternion to subtract
			**	right		- The second quaternion to subtract
			**	result		- The reesulting quaternion
			** Returns
			**	nothing
			*/
			static void Subtract(const Quaternion &left, const Quaternion &right, Quaternion &result)
			{
				result.X = left.X - right.X;
				result.Y = left.Y - right.Y;
				result.Z = left.Z - right.Z;
				result.W = left.W - right.W;
			}

			/*
			** Subtracts two quaternions
			** Parameters
			**	left		- The first quaternion to subtract
			**	right		- The second quaternion to subtract
			** Returns
			**	the resulting quaternion
			*/
			static Quaternion Subtract(const Quaternion &left, const Quaternion &right)
			{
				return Quaternion(left.X - right.X,
					left.Y - right.Y,
					left.Z - right.Z,
					left.W - right.W);
			}

			/*
			** Scales a quaternion by the given value.
			** Parameters
			**	value		- the quaternion to scale
			**	scale		- the amount by which to scale
			**	result		- the resulting quaternion
			** Returns
			**	nothing
			*/
			static void Multiply(const Quaternion &value, real scale, Quaternion &result)
			{
				result.X = value.X * scale;
				result.Y = value.Y * scale;
				result.Z = value.Z * scale;
				result.W = value.W * scale;
			}

			/*
			** Scales a quaternion by the given value.
			** Parameters
			**	value		- the quaternion to scale
			**	scale		- the amount by which to scale
			** Returns
			**	the resulting quaternion
			*/
			static Quaternion Multiply(const Quaternion &value, real scale)
			{
				return Quaternion(value.X * scale;
					value.Y * scale,
					value.Z * scale,
					value.W * scale);
			}

			/*
			** Modulates a quaternion by another
			** Parameters
			**	left		- the first quaternion to modulate
			**	right		- the second quaternion to modulate
			**	result		- the resulting quaternion
			** Returns
			**	nothing
			*/
			static void Multiply(const Quaternion &left, const Quaternion &right, Quaternion &result)
			{
				real lx = left.X;
				real ly = left.Y;
				real lz = left.Z;
				real lw = left.W;
				real rx = right.X;
				real ry = right.Y;
				real rz = right.Z;
				real rw = right.W;

				result.X = (rx * lw + lx * rw + ry * lz) - (rz * ly);
				result.Y = (ry * lw + ly * rw + rz * lx) - (rx * lz);
				result.Z = (rz * lw + lz * rw + rx * ly) - (ry * lx);
				result.W = (rw * lw) - (rx * lx + ry * ly + rz * lz);
			}

			/*
			** Modulates a quaternion by another
			** Parameters
			**	left		- the first quaternion to modulate
			**	right		- the second quaternion to modulate
			** Returns
			**	the resulting quaternion
			*/
			static Quaternion Multiply(const Quaternion &left, const Quaternion &right)
			{
				real lx = left.X;
				real ly = left.Y;
				real lz = left.Z;
				real lw = left.W;
				real rx = right.X;
				real ry = right.Y;
				real rz = right.Z;
				real rw = right.W;

				return Quaternion((rx * lw + lx * rw + ry * lz) - (rz * ly),
					(ry * lw + ly * rw + rz * lx) - (rx * lz),
					(rz * lw + lz * rw + rx * ly) - (ry * lx),
					(rw * lw) - (rx * lx + ry * ly + rz * lz));
			}

			/*
			** Negates the given quaternion
			** Parameters
			**	value		- the value to negate
			**	result		- the resulting quaternion
			** Returns
			**	nothing
			*/
			static void Negate(const Quaternion &value, Quaternion &result)
			{
				result.X = -value.X;
				result.Y = -value.Y;
				result.Z = -value.Z;
				result.W = -value.W;
			}

			/*
			** Negates the given quaternion
			** Parameters
			**	value		- the value to negate
			** Returns
			**	the negated quaternion
			*/
			static Quaternion Negate(const Quaternion &value)
			{
				return Quaternion(-value.X, -value.Y, -value.Z, -value.W);
			}

			/*
			** Returns a Quaternion containing the 4D cartesian coordinates of a point
			** specified in Barycentric coordinates relative to a 2D triangle.
			** Parameters
			**	value1			- vertex 1
			**	value2			- vertex 2
			**	value3			- vertex 3
			**	amount1			- Barycentric coordinate b2
			**	amount2			- Barycentric coordinate b3
			**	result			- the resulting quaternion
			** Returns
			**	nothing
			*/
			static void Barycentric(const Quaternion &value1, const Quaternion &value2, const Quaternion &value3,
				real amount1, real amount2, Quaternion &result)
			{
				Quaternion start, end;
				Slerp(value1, value2, amount1 + amount2, start);
				Slerp(value1, value3, amount1 + amount2, end);
				Slerp(start, end, amount2 / (amount1 + amount2), result);
			}

			/*
			** Returns a Quaternion containing the 4D cartesian coordinates of a point
			** specified in Barycentric coordinates relative to a 2D triangle.
			** Parameters
			**	value1			- vertex 1
			**	value2			- vertex 2
			**	value3			- vertex 3
			**	amount1			- Barycentric coordinate b2
			**	amount2			- Barycentric coordinate b3
			** Returns
			**	the resulting quaternion
			*/
			static Quaternion Barycentric(const Quaternion &value1, const Quaternion &value2, const Quaternion &value3,
				real amount1, real amount2)
			{
				Quaternion start, end, result;
				Slerp(value1, value2, amount1 + amount2, start);
				Slerp(value1, value3, amount1 + amount2, end);
				Slerp(start, end, amount2 / (amount1 + amount2), result);

				return result;
			}

			/*
			** Conjugates a quaternion
			** Parameters
			**	value		- the value to conjugate
			**	result		- the resulting quaternion
			** Returns
			**	nothing
			*/
			static void GetConjugate(const Quaternion &value, Quaternion &result)
			{
				result.X = -value.X;
				result.Y = -value.Y;
				result.Z = -value.Z;
				result.W = value.W; // not negative
			}

			/*
			** Conjugates a quaternion
			** Parameters
			**	value		- the value to conjugate
			** Returns
			**	the conjugated quaternion
			*/
			static Quaternion GetConjugate(const Quaternion &value)
			{
				return Quaternion(-value.X, -value.Y, -value.Z, value.W);
			}

			/*
			** Calculates the dot product of two quaternions.
			** Parameters
			**	left		- the first source quaternion
			**	right		- the second source quaternion
			** Returns
			**	the dot product
			*/
			static real GetDot(const Quaternion &left, const Quaternion &right)
			{
				return left.X*right.X + left.Y*right.Y + left.Z*right.Z + left.W*right.W;
			}

			/*
			** Exponentiates a quaternion
			** Parameters
			**	value		- the quaternion to exponentiate
			**	result		- the resulting quaternion
			** Returns
			**	nothing
			*/
			static void Exponentiate(const Quaternion &value, Quaternion &result)
			{
				real angle = (real)sqrt(value.X*value.X + value.Y*value.Y + value.Z*value.Z);
				real _sin = (real)sin(angle);

				if (CommonUtils::Abs(_sin) > (real)0.0)
				{
					real coeff = _sin / angle;
					result.X = coeff * value.X;
					result.Y = coeff * value.Y;
					result.Z = coeff * value.Z;
				}
				else
				{
					result = value;
				}

				result.W = (real)cos(angle);
			}

			/*
			** Exponentiates a quaternion
			** Parameters
			**	value		- the quaternion to exponentiate
			** Returns
			**	the resulting quaternion
			*/
			static Quaternion Exponentiate(const Quaternion &value)
			{
				Quaternion result;

				real angle = (real)sqrt(value.X*value.X + value.Y*value.Y + value.Z*value.Z);
				real _sin = (real)sin(angle);

				if (CommonUtils::Abs(_sin) > (real)0.0)
				{
					real coeff = _sin / angle;
					result.X = coeff * value.X;
					result.Y = coeff * value.Y;
					result.Z = coeff * value.Z;
				}
				else
				{
					result = value;
				}

				result.W = (real)cos(angle);
			}

			/*
			** Conjugates and renormalizes a quaternion
			** Parameters
			**	value		- the quaternion to invert
			**	result		- the resulting quaternion
			** Returns
			**	nothing
			*/
			static void Invert(const Quaternion &value, Quaternion &result)
			{
				result = value;
				result.Invert();
			}

			/*
			** Conjugates and renormalizes a quaternion
			** Parameters
			**	value		- the quaternion to invert
			** Returns
			**	the inverted quaternion
			*/
			static Quaternion Invert(const Quaternion &value)
			{
				Quaternion result = value;
				result.Invert();
				return result;
			}

			/*
			** Performs linear interpolation between two quaternions.
			** Parameters
			**	start		- the starting quaternion
			**	end			- the ending quaternion
			**	amount		- a value between 0 and 1 indiciating end weight
			**	result		- the resulting quaternion
			** Returns
			**	nothing
			*/
			static void Lerp(const Quaternion &start, const Quaternion &end, real amount, Quaternion &result)
			{
				real inverse = (real)1.0 - amount;
				if (GetDot(start, end) >= (real)0.0)
				{
					result.X = (inverse * start.X) + (amount * end.X);
					result.Y = (inverse * start.Y) + (amount * end.Y);
					result.Z = (inverse * start.Z) + (amount * end.Z);
					result.W = (inverse * start.W) + (amount * end.W);
				}
				else
				{
					result.X = (inverse * start.X) - (amount * end.X);
					result.Y = (inverse * start.Y) - (amount * end.Y);
					result.Z = (inverse * start.Z) - (amount * end.Z);
					result.W = (inverse * start.W) - (amount * end.W);
				}

				result.Normalize();
			}

			/*
			** Performs linear interpolation between two quaternions.
			** Parameters
			**	start		- the starting quaternion
			**	end			- the ending quaternion
			**	amount		- a value between 0 and 1 indiciating end weight
			** Returns
			**	the resulting quaternion
			*/
			static Quaternion Lerp(const Quaternion &start, const Quaternion &end, real amount)
			{
				Quaternion result;
				real inverse = (real)1.0 - amount;
				if (GetDot(start, end) >= (real)0.0)
				{
					result.X = (inverse * start.X) + (amount * end.X);
					result.Y = (inverse * start.Y) + (amount * end.Y);
					result.Z = (inverse * start.Z) + (amount * end.Z);
					result.W = (inverse * start.W) + (amount * end.W);
				}
				else
				{
					result.X = (inverse * start.X) - (amount * end.X);
					result.Y = (inverse * start.Y) - (amount * end.Y);
					result.Z = (inverse * start.Z) - (amount * end.Z);
					result.W = (inverse * start.W) - (amount * end.W);
				}

				result.Normalize();
				return result;
			}

			/*
			** Takes the natural log of the specified quaternion.
			** Parameters
			**	value		- the quaternion to take the log of
			**	result		- the resulting quaternion
			** Returns
			**	nothing
			*/
			static void Log(const Quaternion &value, Quaternion &result)
			{
				if (CommonUtils::Abs(value.W) < (real)1.0)
				{
					real angle = (real)acos(value.W);
					real _sin = (real)sin(angle);

					if (CommonUtils::Abs(_sin) > (real)0.0)
					{
						real coeff = angle / _sin;
						result.X = value.X * coeff;
						result.Y = value.Y * coeff;
						result.Z = value.Z * coeff;
					}
					else
					{
						result = value;
					}
				}
				else
				{
					result = value;
				}

				result.W = (real)0.0;
			}

			/*
			** Takes the natural log of the specified quaternion.
			** Parameters
			**	value		- the quaternion to take the log of
			**	result		- the resulting quaternion
			** Returns
			**	nothing
			*/
			static Quaternion Log(const Quaternion &value)
			{
				Quaternion result;
				if (CommonUtils::Abs(value.W) < (real)1.0)
				{
					real angle = (real)acos(value.W);
					real _sin = (real)sin(angle);

					if (CommonUtils::Abs(_sin) > (real)0.0)
					{
						real coeff = angle / _sin;
						result.X = value.X * coeff;
						result.Y = value.Y * coeff;
						result.Z = value.Z * coeff;
					}
					else
					{
						result = value;
					}
				}
				else
				{
					result = value;
				}

				result.W = (real)0.0;
				return result;
			}

			/*
			** Converts a quaternion into a unit quaternion
			** Parameters
			**	value		- the quaternion to normalize
			**	result		- the resulting quaternion
			** Returns
			**	nothing
			*/
			static void Normalize(const Quaternion &value, Quaternion &result)
			{
				result = value;
				real len = (real)sqrt(value.X*value.X + value.Y*value.Y + value.Z*value.Z + value.W*value.W);
				if (len > (real)0.0)
				{
					real inv = (real)1.0 / len;
					result.X *= inv;
					result.Y *= inv;
					result.Z *= inv;
					result.W *= inv;
				}
			}

			/*
			** Converts a quaternion into a unit quaternion
			** Parameters
			**	value		- the quaternion to normalize
			** Returns
			**	the resulting quaternion
			*/
			static Quaternion Normalize(const Quaternion &value)
			{
				Quaternion result = value;
				real len = (real)sqrt(value.X*value.X + value.Y*value.Y + value.Z*value.Z + value.W*value.W);
				if (len > (real)0.0)
				{
					real inv = (real)1.0 / len;
					result.X *= inv;
					result.Y *= inv;
					result.Z *= inv;
					result.W *= inv;
				}
			}

			/*
			** Creates a quaternion given the rotation and axis.
			** Parameters
			**	axis		- the axis
			**	angle		- the angle of rotation
			**	result		- the resulting quaternion
			** Returns
			**	nothing
			*/
			static void RotationAxis(const Vector3 &axis, real angle, Quaternion &result)
			{
				Vector3 normalized;
				Vector3::Normalize(axis, normalized);

				real half = angle * (real)0.5;
				real _sin = (real)sin(half);
				real _cos = (real)cos(half);

				result.X = normalized.X * _sin;
				result.Y = normalized.Y * _sin;
				result.Z = normalized.Z * _sin;
				result.W = _cos;
			}

			/*
			** Creates a quaternion given the rotation and axis.
			** Parameters
			**	axis		- the axis
			**	angle		- the angle of rotation
			** Returns
			**	the resulting quaternion
			*/
			static Quaternion RotationAxis(const Vector3 &axis, real angle)
			{
				Quaternion result;
				Vector3 normalized;
				Vector3::Normalize(axis, normalized);

				real half = angle * (real)0.5;
				real _sin = (real)sin(half);
				real _cos = (real)cos(half);

				result.X = normalized.X * _sin;
				result.Y = normalized.Y * _sin;
				result.Z = normalized.Z * _sin;
				result.W = _cos;

				return result;
			}

			/*
			** Creates a quaternion given a rotation Matrix4
			** Parameters
			**	matrix		- the rotation matrix
			**	result		- the resulting quaternion
			** Returns
			**	nothing
			*/
			static void RotationMatrix(const Matrix4 &matrix, Quaternion &result)
			{
				real sqrt;
				real half;
				real scale = matrix.M11 + matrix.M22 + matrix.M33;

				if (scale > 0.0f)
				{
					sqrt = (real)::sqrt(scale + 1.0f);
					result.W = sqrt * (real)0.5;
					sqrt = (real)0.5 / sqrt;

					result.X = (matrix.M23 - matrix.M32) * sqrt;
					result.Y = (matrix.M31 - matrix.M13) * sqrt;
					result.Z = (matrix.M12 - matrix.M21) * sqrt;
				}
				else if ((matrix.M11 >= matrix.M22) && (matrix.M11 >= matrix.M33))
				{
					sqrt = (real)::qrt((real)1.0 + matrix.M11 - matrix.M22 - matrix.M33);
					half = (real)0.5 / sqrt;

					result.X = (real)0.5 * sqrt;
					result.Y = (matrix.M12 + matrix.M21) * half;
					result.Z = (matrix.M13 + matrix.M31) * half;
					result.W = (matrix.M23 - matrix.M32) * half;
				}
				else if (matrix.M22 > matrix.M33)
				{
					sqrt = (real)::sqrt((real)1.0 + matrix.M22 - matrix.M11 - matrix.M33);
					half = (real)0.5 / sqrt;

					result.X = (matrix.M21 + matrix.M12) * half;
					result.Y = (real)0.5 * sqrt;
					result.Z = (matrix.M32 + matrix.M23) * half;
					result.W = (matrix.M31 - matrix.M13) * half;
				}
				else
				{
					sqrt = (real)::sqrt((real)1.0 + matrix.M33 - matrix.M11 - matrix.M22);
					half = (real)0.5 / sqrt;

					result.X = (matrix.M31 + matrix.M13) * half;
					result.Y = (matrix.M32 + matrix.M23) * half;
					result.Z = (real)0.5 * sqrt;
					result.W = (matrix.M12 - matrix.M21) * half;
				}
			}

			/*
			** Creates a quaternion given a rotation Matrix4
			** Parameters
			**	matrix		- the rotation matrix
			** Returns
			**	the resulting quaternion
			*/
			static void RotationMatrix(const Matrix4 &matrix)
			{
				Quaternion result;
				Quaternion::RotationMatrix(matrix, result);
			}

			/*
			** Creates a quaternion given yaw, pitch, and roll.
			** Parameters
			**	yaw		- the yaw of rotation
			**	pitch	- the pitch of rotation
			**	roll	- the roll of rotation
			**	result	- the resulting quaternion
			** Returns
			**	nothing
			*/
			static void RotationYawPitchRoll(real yaw, real pitch, real roll, Quaternion &result)
			{
				real halfRoll = roll * 0.5f;
				real halfPitch = pitch * 0.5f;
				real halfYaw = yaw * 0.5f;

				real sinRoll = (real)::sin(halfRoll);
				real cosRoll = (real)::cos(halfRoll);
				real sinPitch = (real)::sin(halfPitch);
				real cosPitch = (real)::cos(halfPitch);
				real sinYaw = (real)::sin(halfYaw);
				real cosYaw = (real)::cos(halfYaw);

				result.X = (cosYaw * sinPitch * cosRoll) + (sinYaw * cosPitch * sinRoll);
				result.Y = (sinYaw * cosPitch * cosRoll) - (cosYaw * sinPitch * sinRoll);
				result.Z = (cosYaw * cosPitch * sinRoll) - (sinYaw * sinPitch * cosRoll);
				result.W = (cosYaw * cosPitch * cosRoll) + (sinYaw * sinPitch * sinRoll);
			}

			/*
			** Creates a quaternion given yaw, pitch, and roll.
			** Parameters
			**	yaw		- the yaw of rotation
			**	pitch	- the pitch of rotation
			**	roll	- the roll of rotation
			** Returns
			**	the resulting quaternion
			*/
			static Quaternion RotationYawPitchRoll(real yaw, real pitch, real roll)			
			{
				Quaternion result;
				real halfRoll = roll * 0.5f;
				real halfPitch = pitch * 0.5f;
				real halfYaw = yaw * 0.5f;

				real sinRoll = (real)::sin(halfRoll);
				real cosRoll = (real)::cos(halfRoll);
				real sinPitch = (real)::sin(halfPitch);
				real cosPitch = (real)::cos(halfPitch);
				real sinYaw = (real)::sin(halfYaw);
				real cosYaw = (real)::cos(halfYaw);

				result.X = (cosYaw * sinPitch * cosRoll) + (sinYaw * cosPitch * sinRoll);
				result.Y = (sinYaw * cosPitch * cosRoll) - (cosYaw * sinPitch * sinRoll);
				result.Z = (cosYaw * cosPitch * sinRoll) - (sinYaw * sinPitch * cosRoll);
				result.W = (cosYaw * cosPitch * cosRoll) + (sinYaw * sinPitch * sinRoll);
				return result;
			}
		};

	}
}
#endif /* _TEKSTORM_QUATERNION_H */