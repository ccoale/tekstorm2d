#include "Vector2.h"

namespace Tekstorm
{
	namespace Math
	{
		///
			/// A Vector2 with both of its components set to one.
			///
			const Vector2 Vector2::One = Vector2(1, 1);

			///
			/// A unit vector for the x-axis.
			///
			const Vector2 Vector2::UnitX = Vector2(1, 0);

			///
			/// A unit vector for the y-axis.
			///
			const Vector2 Vector2::UnitY = Vector2(0, 1);

			///
			/// A Vector2 with both of its components set to zero.
			///
			const Vector2 Vector2::Zero = Vector2(0, 0);


			///
			/// Creates a new vector, initialize the components to 0.
			///
			Vector2::Vector2()
			{
				X = Y = 0;
			}

			///
			/// Creates a new vector, given the component values.
			///
			Vector2::Vector2(tekreal x, tekreal y) 
			{
				X = x; Y = y;
			}

			///
			/// Creates a new vector, given the component values.
			///
			Vector2::Vector2(const Vector2 &other) 
			{
				X = other.X;
				Y = other.Y;
			}

			///
			/// Creates a new vector, given an array of component values. [0] = x, [1] = y
			/// 
			Vector2::Vector2(const tekreal values[]) 
			{
				X = values[0]; Y = values[1];
			}

			///
			/// Adds the left and right vector, returning the result.
			///
			Vector2 Vector2::Add(const Vector2 &left, const Vector2 &right) 
			{
				return Vector2(left.X + right.X, left.Y + right.Y);
			}

			///
			/// Adds the left and right vector, returning the result via pointer.
			///
			void Vector2::Add(const Vector2 &left, const Vector2 &right, Vector2 *result) 
			{
				result->X = left.X + right.X;
				result->Y = left.Y + right.Y;
			}

			///
			/// Adds the left vector and a scalar, returning the result.
			///
			Vector2 Vector2::Add(const Vector2 &left, tekreal right) 
			{
				return Vector2(left.X + right, left.Y + right);
			}

			///
			/// Adds the left vector and a scalar, returning the result via pointer.
			///
			void Vector2::Add(const Vector2 &left, tekreal right, Vector2 *result) 
			{
				result->X = left.X + right;
				result->Y = left.Y + right;
			}

			///
			/// Calculates the distance between the left and right vector, returning the result.
			///
			tekreal Vector2::GetDistance(const Vector2 &left, const Vector2 &right)
			{
				tekreal dx = left.X - right.X;
				tekreal dy = left.Y - right.Y;

				return (tekreal)sqrt(dx*dx + dy*dy);
			}

			///
			/// Calculates the distance squared (distance^2) between the left and right vector, returning the result.
			///
			tekreal Vector2::GetDistanceSquared(const Vector2 &left, const Vector2 &right) 
			{
				tekreal dx = left.X - right.X;
				tekreal dy = left.Y - right.Y;

				return dx*dx + dy*dy;
			}

			///
			/// Divides a vector by another vector (component-wise division).
			///
			Vector2 Vector2::Divide(const Vector2 &left, const Vector2 &right) 
			{
				return Vector2(left.X / right.X, left.Y / right.Y);
			}

			///
			/// Divides a vector by another vector (component-wise division), and returns the result via pointer.
			///
			void Vector2::Divide(const Vector2 &left, const Vector2 &right, Vector2 *result) 
			{
				result->X = left.X/right.X;
				result->Y = left.Y/right.Y;
			}

			///
			/// Divides a vector by a scalar (component-wise division).
			///
			Vector2 Vector2::Divide(const Vector2 &left, tekreal right) 
			{
				return Vector2(left.X / right, left.Y / right);
			}

			///
			/// Divides a vector by a scalar (component-wise division), and returns the result via pointer.
			///
			void Vector2::Divide(const Vector2 &left, tekreal right, Vector2 *result) 
			{
				result->X = left.X / right;
				result->Y = left.Y / right;
			}

			///
			/// Calculates the dot product of two vectors.
			///
			tekreal Vector2::GetDot(const Vector2 &left, const Vector2 &right) 
			{
				return left.X*right.X + left.Y*right.Y;
			}

			///
			/// Calculates the length of this vector.
			///
			tekreal Vector2::GetLength() const
			{
				return (tekreal)sqrt( (tekreal)(X*X + Y*Y) );
			}

			///
			/// Calculates the length of the given vector.
			///
			tekreal Vector2::GetLength(const Vector2 &left) 
			{
				return (tekreal)sqrt( (tekreal)(left.X * left.X + left.Y*left.Y) );
			}

			///
			/// Calculates the length squared (length^2) of this vector.
			///
			tekreal Vector2::GetLengthSquared()  const
			{
				return (tekreal)(X*X + Y*Y);
			}

			///
			/// Calculates the length squared (length^2) of the given vector.
			///
			tekreal Vector2::GetLengthSquared(const Vector2 &left) 
			{
				return (tekreal)(left.X*left.X + left.Y*left.Y);
			}

			///
			/// Multiplies a vector by another vector.
			///
			Vector2 Vector2::Multiply(const Vector2 &left, const Vector2 &right) 
			{
				return Vector2(left.X*right.X, left.Y*right.Y);
			}

			///
			/// Multiples a vector by another vector, returning the result via pointer.
			///
			void Vector2::Multiply(const Vector2 &left, const Vector2 &right, Vector2 *result) 
			{
				result->X = left.X*right.X;
				result->Y = left.Y*right.Y;
			}

			///
			/// Multiplies a vector by a scalar.
			///
			Vector2 Vector2::Multiply(const Vector2 &left, tekreal right) 
			{
				return Vector2(left.X * right, left.Y*right);
			}

			///
			/// Multiplies a vector by a scalar, returning the result via pointer.
			///
			void Vector2::Multiply(const Vector2 &left, tekreal right, Vector2 *result) 
			{
				result->X = left.X * right;
				result->Y = left.Y * right;
			}

			///
			/// Returns the negation of the given vector.
			///
			Vector2 Vector2::Negate(const Vector2 &left) 
			{
				return Vector2(-left.X, -left.Y);
			}

			///
			/// Returns the negation via pointer of the given vector.
			///
			void Vector2::Negate(const Vector2 &left, Vector2 *result) 
			{
				result->X = -left.X;
				result->Y = -left.Y;
			}

			///
			/// Turns this vector into a unit vector.
			///
			void Vector2::Normalize() 
			{
				tekreal len = (tekreal)sqrt((tekreal)(X*X + Y*Y));
				X /= len;
				Y /= len;
			}

			///
			/// Returns the normalized version of the given vector.
			///
			Vector2 Vector2::Normalize(const Vector2 &left)
			{
				tekreal len = (tekreal)sqrt((tekreal)(left.X*left.X + left.Y*left.Y));

				return Vector2(left.X / len, left.Y / len);
			}

			///
			/// Returns the normalized version of the given vector via pointer.
			///
			void Vector2::Normalize(const Vector2 &left, Vector2 *result) 
			{
				tekreal len = (tekreal)sqrt((tekreal)(left.X*left.X + left.Y*left.Y));
				result->X = left.X / len;
				result->Y = left.Y / len;
			}

			///
			/// Reflects the given vector against the given normal.
			///
			Vector2 Vector2::Reflect(const Vector2 &vector, const Vector2 &normal) 
			{
				tekreal dot = Vector2::GetDot(normal, vector);
				return vector - (normal * dot);
				//return Vector2::Subtract(vector, Vector2::Multiply(normal, dot));
			}

			///
			/// Reflects the given vector against the given normal.
			///
			void Vector2::Reflect(const Vector2 &vector, const Vector2 &normal, Vector2 *result) 
			{
				tekreal dot = Vector2::GetDot(normal, vector);
				*result = vector - (normal * dot);
				//*result = Vector2::Subtract(vector, Vector2::Multiply(normal, dot));
			}

			///
			/// Subtracts the right vector from the left vector, returning the result.
			///
			Vector2 Vector2::Subtract(const Vector2 &left, const Vector2 &right) 
			{
				return Vector2(left.X - right.X, left.Y - right.Y);
			}

			///
			/// Subtracts the right vector from the left vector, returning the result via pointer.
			///
			void Vector2::Subtract(const Vector2 &left, const Vector2 &right, Vector2 *result) 
			{
				result->X = left.X - right.X;
				result->Y = left.Y - right.Y;
			}

			///
			/// Subtracts the scalar from both components of the left vector.
			///
			Vector2 Vector2::Subtract(const Vector2 &left, tekreal right) 
			{
				return Vector2(left.X - right, left.Y - right);
			}

			///
			/// Subtracts the scalar from both components of the left vector.
			///
			void Vector2::Subtract(const Vector2 &left, tekreal right, Vector2 *result) 
			{
				result->X = left.X - right;
				result->Y = left.Y - right;
			}

			///
			/// Adds two vectors together.
			///
			Vector2 Vector2::operator+(const Vector2 &right) const 
			{
				return Vector2(X + right.X, Y + right.Y);
			}

			///
			/// Adds a scalar to a vector.
			///
			Vector2 Vector2::operator+(tekreal right) const 
			{
				return Vector2(X + right, Y + right);
			}

			///
			/// Adds another vector to this vector.
			///
			Vector2& Vector2::operator+=(const Vector2 &right) 
			{
				X += right.X;
				Y += right.Y;

				return *this;
			}

			///
			/// Adds a scalar to this vector.
			///
			Vector2& Vector2::operator+=(tekreal right) 
			{
				X += right;
				Y += right;

				return *this;
			}

			///
			/// Subtracts the right vector from the left vector.
			///
			Vector2 Vector2::operator-(const Vector2 &right) const 
			{
				return Vector2(X - right.X, Y - right.Y);
			}

			///
			/// Subtracts the scalar from the left vector.
			///
			Vector2 Vector2::operator-(tekreal right) const 
			{
				return Vector2(X - right, Y - right);
			}

			///
			/// Subtracts the right vector from this vector.
			///
			Vector2 &Vector2::operator-=(const Vector2 &right) 
			{
				X -= right.X;
				Y -= right.Y;

				return *this;
			}

			///
			/// Subtracts the scalar from this vector.
			///
			Vector2 &Vector2::operator-=(tekreal right) 
			{
				X -= right;
				Y -= right;

				return *this;
			}

			///
			/// Multiples the left vector by the right vector using component-wise multiplication.
			///
			Vector2 Vector2::operator*(const Vector2 &right) const 
			{
				return Vector2(X * right.X, Y * right.Y);
			}

			///
			/// Multiples the left vector by the scalar.
			///
			Vector2 Vector2::operator*(tekreal right) const 
			{
				return Vector2(X * right, Y * right);
			}

			///
			/// Multiples this vector by another vector using component-wise multiplication.
			///
			Vector2& Vector2::operator*=(const Vector2 &right) 
			{
				X *= right.X;
				Y *= right.Y;

				return *this;
			}

			///
			/// Multiplies this vector by a scalar.
			///
			Vector2& Vector2::operator*=(tekreal right) 
			{
				X *= right;
				Y *= right;

				return *this;
			}

			///
			/// Divides the left vector by the right vector using component-wise division.
			///
			Vector2 Vector2::operator/(const Vector2 &right) const 
			{
				return Vector2(X / right.X, Y / right.Y);
			}

			///
			/// Divides the left vector by the scalar.
			///
			Vector2 Vector2::operator/(tekreal right) const 
			{
				return Vector2(X / right, Y / right);
			}

			///
			/// Divides this vector by another vector using component-wise division.
			///
			Vector2& Vector2::operator/=(const Vector2 &right) 
			{
				X /= right.X;
				Y /= right.Y;

				return *this;
			}

			///
			/// Divides this vector by a scalar.
			///
			Vector2& Vector2::operator/=(tekreal right) 
			{
				X /= right;
				Y /= right;

				return *this;
			}
	}
}
