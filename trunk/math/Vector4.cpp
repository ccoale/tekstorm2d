#include "Vector4.h"

namespace Tekstorm
{
	namespace Math
	{		
			///
			/// A Vector4 with both of its components set to one.
			///
			const Vector4 Vector4::One = Vector4(1, 1, 1, 1);

			///
			/// A unit vector for the x-axis.
			///
			const Vector4 Vector4::UnitX = Vector4(1, 0, 0, 0);

			///
			/// A unit vector for the y-axis.
			///
			const Vector4 Vector4::UnitY = Vector4(0, 1, 0, 0);

			///
			/// A unit vector for the z-axis.
			///
			const Vector4 Vector4::UnitZ = Vector4(0, 0, 1, 0);

			///
			/// A unit vector for the W-axis.
			///
			const Vector4 Vector4::UnitW = Vector4(0, 0, 0, 1);

			///
			/// A Vector4 with both of its components set to zero.
			///
			const Vector4 Vector4::Zero = Vector4(0, 0, 0, 0);


			///
			/// Creates a new vector, initialize the components to 0.
			///
			Vector4::Vector4()
			{
				X = Y = Z = W = 0;
			}

			///
			/// Creates a new vector, given the component values.
			///
			Vector4::Vector4(tekreal x, tekreal y, tekreal z, tekreal w) 
			{
				X = x; Y = y; Z = z; W = w;
			}

			///
			/// Creates a new vector, given the component values.
			///
			Vector4::Vector4(const Vector4 &other) 
			{
				X = other.X;
				Y = other.Y;
				Z = other.Z;
				W = other.W;
			}

			///
			/// Creates a new vector, given an array of component values. [0] = x, [1] = y, [2] = z, [3] = w
			/// 
			Vector4::Vector4(const tekreal values[]) 
			{
				X = values[0]; Y = values[1]; Z = values[2]; W = values[3];
			}

			///
			/// Adds the left and right vector, returning the result.
			///
			Vector4 Vector4::Add(const Vector4 &left, const Vector4 &right) 
			{
				return Vector4(left.X + right.X, left.Y + right.Y, left.Z + right.Z, left.W + right.W);
			}

			///
			/// Adds the left and right vector, returning the result via pointer.
			///
			void Vector4::Add(const Vector4 &left, const Vector4 &right, Vector4 *result) 
			{
				result->X = left.X + right.X;
				result->Y = left.Y + right.Y;
				result->Z = left.Z + right.Z;
				result->W = left.W + right.W;
			}

			///
			/// Adds the left vector and a scalar, returning the result.
			///
			Vector4 Vector4::Add(const Vector4 &left, tekreal right) 
			{
				return Vector4(left.X + right, left.Y + right, left.Z + right, left.W + right);
			}

			///
			/// Adds the left vector and a scalar, returning the result via pointer.
			///
			void Vector4::Add(const Vector4 &left, tekreal right, Vector4 *result) 
			{
				result->X = left.X + right;
				result->Y = left.Y + right;
				result->Z = left.Z + right;
				result->W = left.W + right;
			}

			///
			/// Calculates the distance between the left and right vector, returning the result.
			///
			tekreal Vector4::GetDistance(const Vector4 &left, const Vector4 &right)
			{
				tekreal dx = left.X - right.X;
				tekreal dy = left.Y - right.Y;
				tekreal dz = left.Z - right.Z;
				tekreal dw = left.W - right.W;

				return (tekreal)sqrt(dx*dx + dy*dy + dz*dz + dw*dw);
			}

			///
			/// Calculates the distance squared (distance^2) between the left and right vector, returning the result.
			///
			tekreal Vector4::GetDistanceSquared(const Vector4 &left, const Vector4 &right) 
			{
				tekreal dx = left.X - right.X;
				tekreal dy = left.Y - right.Y;
				tekreal dz = left.Z - right.Z;
				tekreal dw = left.W - right.W;

				return dx*dx + dy*dy + dz*dz + dw*dw;
			}

			///
			/// Divides a vector by another vector (component-wise division).
			///
			Vector4 Vector4::Divide(const Vector4 &left, const Vector4 &right) 
			{
				return Vector4(left.X / right.X, left.Y / right.Y, left.Z / right.Z, left.W / right.W);
			}

			///
			/// Divides a vector by another vector (component-wise division), and returns the result via pointer.
			///
			void Vector4::Divide(const Vector4 &left, const Vector4 &right, Vector4 *result) 
			{
				result->X = left.X/right.X;
				result->Y = left.Y/right.Y;
				result->Z = left.Z / right.Z;
				result->W = left.W / right.W;
			}

			///
			/// Divides a vector by a scalar (component-wise division).
			///
			Vector4 Vector4::Divide(const Vector4 &left, tekreal right) 
			{
				return Vector4(left.X / right, left.Y / right, left.Z / right, left.W / right);
			}

			///
			/// Divides a vector by a scalar (component-wise division), and returns the result via pointer.
			///
			void Vector4::Divide(const Vector4 &left, tekreal right, Vector4 *result) 
			{
				result->X = left.X / right;
				result->Y = left.Y / right;
				result->Z = left.Z / right;
				result->W = left.W / right;
			}

			///
			/// Calculates the dot product of two vectors.
			///
			tekreal Vector4::GetDot(const Vector4 &left, const Vector4 &right) 
			{
				return left.X*right.X + left.Y*right.Y + left.Z * right.Z + left.W*right.W;
			}

			///
			/// Calculates the length of this vector.
			///
			tekreal Vector4::GetLength() const
			{
				return (tekreal)sqrt( (tekreal)(X*X + Y*Y + Z*Z + W*W) );
			}

			///
			/// Calculates the length of the given vector.
			///
			tekreal Vector4::GetLength(const Vector4 &left) 
			{
				return (tekreal)sqrt( (tekreal)(left.X * left.X + left.Y*left.Y + left.Z*left.Z + left.W*left.W) );
			}

			///
			/// Calculates the length squared (length^2) of this vector.
			///
			tekreal Vector4::GetLengthSquared()  const
			{
				return (tekreal)(X*X + Y*Y + Z*Z + W*W);
			}

			///
			/// Calculates the length squared (length^2) of the given vector.
			///
			tekreal Vector4::GetLengthSquared(const Vector4 &left) 
			{
				return (tekreal)(left.X*left.X + left.Y*left.Y + left.Z*left.Z + left.W*left.W);
			}

			///
			/// Multiplies a vector by another vector.
			///
			Vector4 Vector4::Multiply(const Vector4 &left, const Vector4 &right) 
			{
				return Vector4(left.X*right.X, left.Y*right.Y, left.Z*right.Z, left.W*right.W);
			}

			///
			/// Multiples a vector by another vector, returning the result via pointer.
			///
			void Vector4::Multiply(const Vector4 &left, const Vector4 &right, Vector4 *result) 
			{
				result->X = left.X*right.X;
				result->Y = left.Y*right.Y;
				result->Z = left.Z*right.Z;
				result->W = left.W*right.W;
			}

			///
			/// Multiplies a vector by a scalar.
			///
			Vector4 Vector4::Multiply(const Vector4 &left, tekreal right) 
			{
				return Vector4(left.X * right, left.Y*right, left.Z*right, left.W*right);
			}

			///
			/// Multiplies a vector by a scalar, returning the result via pointer.
			///
			void Vector4::Multiply(const Vector4 &left, tekreal right, Vector4 *result) 
			{
				result->X = left.X * right;
				result->Y = left.Y * right;
				result->Z = left.Z * right;
				result->W = left.W * right;
			}

			///
			/// Returns the negation of the given vector.
			///
			Vector4 Vector4::Negate(const Vector4 &left) 
			{
				return Vector4(-left.X, -left.Y, -left.Z, -left.W);
			}

			///
			/// Returns the negation via pointer of the given vector.
			///
			void Vector4::Negate(const Vector4 &left, Vector4 *result) 
			{
				result->X = -left.X;
				result->Y = -left.Y;
				result->Z = -left.Z;
				result->W = -left.W;
			}

			///
			/// Turns this vector into a unit vector.
			///
			void Vector4::Normalize() 
			{
				tekreal len = (tekreal)sqrt((tekreal)(X*X + Y*Y + Z*Z + W*W));
				X /= len;
				Y /= len;
				Z /= len;
				W /= len;
			}

			///
			/// Returns the normalized version of the given vector.
			///
			Vector4 Vector4::Normalize(const Vector4 &left)
			{
				tekreal len = (tekreal)sqrt((tekreal)(left.X*left.X + left.Y*left.Y + left.Z*left.Z + left.W*left.W));

				return Vector4(left.X / len, left.Y / len, left.Z / len, left.W / len);
			}

			///
			/// Returns the normalized version of the given vector via pointer.
			///
			void Vector4::Normalize(const Vector4 &left, Vector4 *result) 
			{
				tekreal len = (tekreal)sqrt((tekreal)(left.X*left.X + left.Y*left.Y + left.Z*left.Z + left.W*left.W));
				result->X = left.X / len;
				result->Y = left.Y / len;
				result->Z = left.Z / len;
				result->W = left.W / len;
			}

			///
			/// Reflects the given vector against the given normal.
			///
			Vector4 Vector4::Reflect(const Vector4 &vector, const Vector4 &normal) 
			{
				tekreal dot = Vector4::GetDot(normal, vector);
				return vector - (normal * dot);
				//return Vector4::Subtract(vector, Vector4::Multiply(normal, dot));
			}

			///
			/// Reflects the given vector against the given normal.
			///
			void Vector4::Reflect(const Vector4 &vector, const Vector4 &normal, Vector4 *result) 
			{
				tekreal dot = Vector4::GetDot(normal, vector);
				*result = vector - (normal * dot);
				//*result = Vector4::Subtract(vector, Vector4::Multiply(normal, dot));
			}

			///
			/// Subtracts the right vector from the left vector, returning the result.
			///
			Vector4 Vector4::Subtract(const Vector4 &left, const Vector4 &right) 
			{
				return Vector4(left.X - right.X, left.Y - right.Y, left.Z - right.Z, left.W - right.W);
			}

			///
			/// Subtracts the right vector from the left vector, returning the result via pointer.
			///
			void Vector4::Subtract(const Vector4 &left, const Vector4 &right, Vector4 *result) 
			{
				result->X = left.X - right.X;
				result->Y = left.Y - right.Y;
				result->Z = left.Z - right.Z;
				result->W = left.W - right.W;
			}

			///
			/// Subtracts the scalar from both components of the left vector.
			///
			Vector4 Vector4::Subtract(const Vector4 &left, tekreal right) 
			{
				return Vector4(left.X - right, left.Y - right, left.Z - right, left.W - right);
			}

			///
			/// Subtracts the scalar from both components of the left vector.
			///
			void Vector4::Subtract(const Vector4 &left, tekreal right, Vector4 *result) 
			{
				result->X = left.X - right;
				result->Y = left.Y - right;
				result->Z = left.Z - right;
				result->W = left.W - right;
			}

			///
			/// Adds two vectors together.
			///
			Vector4 Vector4::operator+(const Vector4 &right) const 
			{
				return Vector4(X + right.X, Y + right.Y, Z + right.Z, W + right.W);
			}

			///
			/// Adds a scalar to a vector.
			///
			Vector4 Vector4::operator+(tekreal right) const 
			{
				return Vector4(X + right, Y + right, Z + right, W + right);
			}

			///
			/// Adds another vector to this vector.
			///
			Vector4& Vector4::operator+=(const Vector4 &right) 
			{
				X += right.X;
				Y += right.Y;
				Z += right.Z;
				W += right.W;

				return *this;
			}

			///
			/// Adds a scalar to this vector.
			///
			Vector4& Vector4::operator+=(tekreal right) 
			{
				X += right;
				Y += right;
				Z += right;
				W += right;

				return *this;
			}

			///
			/// Subtracts the right vector from the left vector.
			///
			Vector4 Vector4::operator-(const Vector4 &right) const 
			{
				return Vector4(X - right.X, Y - right.Y, Z - right.Z, W - right.W);
			}

			///
			/// Subtracts the scalar from the left vector.
			///
			Vector4 Vector4::operator-(tekreal right) const 
			{
				return Vector4(X - right, Y - right, Z - right, W - right);
			}

			///
			/// Subtracts the right vector from this vector.
			///
			Vector4 &Vector4::operator-=(const Vector4 &right) 
			{
				X -= right.X;
				Y -= right.Y;
				Z -= right.Z;
				W -= right.W;

				return *this;
			}

			///
			/// Subtracts the scalar from this vector.
			///
			Vector4 &Vector4::operator-=(tekreal right) 
			{
				X -= right;
				Y -= right;
				Z -= right;
				W -= right;

				return *this;
			}

			///
			/// Multiples the left vector by the right vector using component-wise multiplication.
			///
			Vector4 Vector4::operator*(const Vector4 &right) const 
			{
				return Vector4(X * right.X, Y * right.Y, Z * right.Z, W * right.W);
			}

			///
			/// Multiples the left vector by the scalar.
			///
			Vector4 Vector4::operator*(tekreal right) const 
			{
				return Vector4(X * right, Y * right, Z * right, W * right);
			}

			///
			/// Multiples this vector by another vector using component-wise multiplication.
			///
			Vector4& Vector4::operator*=(const Vector4 &right) 
			{
				X *= right.X;
				Y *= right.Y;
				Z *= right.Z;
				W *= right.W;

				return *this;
			}

			///
			/// Multiplies this vector by a scalar.
			///
			Vector4& Vector4::operator*=(tekreal right) 
			{
				X *= right;
				Y *= right;
				Z *= right;
				W *= right;

				return *this;
			}

			///
			/// Divides the left vector by the right vector using component-wise division.
			///
			Vector4 Vector4::operator/(const Vector4 &right) const 
			{
				return Vector4(X / right.X, Y / right.Y, Z / right.Z, W / right.W);
			}

			///
			/// Divides the left vector by the scalar.
			///
			Vector4 Vector4::operator/(tekreal right) const 
			{
				return Vector4(X / right, Y / right, Z / right, W / right);
			}

			///
			/// Divides this vector by another vector using component-wise division.
			///
			Vector4& Vector4::operator/=(const Vector4 &right) 
			{
				X /= right.X;
				Y /= right.Y;
				Z /= right.Z;
				W /= right.W;

				return *this;
			}

			///
			/// Divides this vector by a scalar.
			///
			Vector4& Vector4::operator/=(tekreal right) 
			{
				X /= right;
				Y /= right;
				Z /= right;
				W /= right;

				return *this;
			}
	}
}
