#include "Vector3.h"

namespace Tekstorm
{
	namespace Math
	{
		///
		/// A vector with three of its components set to one.
		///
		const Vector3 Vector3::One = Vector3(1, 1, 1);

		///
		/// A unit vector for the x-axis.
		///
		const Vector3 Vector3::UnitX = Vector3(1, 0, 0);

		///
		/// A unit vector for the y-axis.
		///
		const Vector3 Vector3::UnitY = Vector3(0, 1, 0);

		///
		/// A unit vector for the z-axis.
		///
		const Vector3 Vector3::UnitZ = Vector3(0, 0, 1);

		///
		/// A Vector with three of its components set to zero.
		///
		const Vector3 Vector3::Zero = Vector3(0, 0, 0);

		///
		/// A unit-vector pointing backward.
		///
		const Vector3 Vector3::Backward = Vector3(0, 0, -1);

		///
		/// A unit-vector pointing down.
		///
		const Vector3 Vector3::Down = Vector3(0, -1, 0);

		///
		/// A unit-vector pointing forward.
		///
		const Vector3 Vector3::Forward = Vector3(0, 0, 1);

		///
		/// A unit-vector pointing left.
		///
		const Vector3 Vector3::Left = Vector3(-1, 0, 0);

		///
		/// A unit-vector pointing right.
		///
		const Vector3 Vector3::Right = Vector3(1, 0, 0);

		///
		/// A unit-vector pointing Up.
		///
		const Vector3 Vector3::Up = Vector3(0, 1, 0);


		///
		/// Creates a new vector, initialize the components to 0.
		///
		Vector3::Vector3()
		{
			X = Y = Z = 0;
		}

		///
		/// Creates a new vector, given the component values.
		///
		Vector3::Vector3(tekreal x, tekreal y, tekreal z) 
		{
			X = x; Y = y; Z = z;
		}

		///
		/// Creates a new vector, given the component values.
		///
		Vector3::Vector3(const Vector3 &other) 
		{
			X = other.X;
			Y = other.Y;
			Z = other.Z;
		}

		///
		/// Creates a new vector, given an array of component values. [0] = x, [1] = y
		/// 
		Vector3::Vector3(const tekreal values[]) 
		{
			X = values[0]; Y = values[1]; Z = values[2];
		}

		///
		/// Adds the left and right vector, returning the result.
		///
		Vector3 Vector3::Add(const Vector3 &left, const Vector3 &right) 
		{
			return Vector3(left.X + right.X, left.Y + right.Y, left.Z + right.Z);
		}

		///
		/// Adds the left and right vector, returning the result via pointer.
		///
		void Vector3::Add(const Vector3 &left, const Vector3 &right, Vector3 *result) 
		{
			result->X = left.X + right.X;
			result->Y = left.Y + right.Y;
			result->Z = left.Z + right.Z;
		}

		///
		/// Adds the left vector and a scalar, returning the result.
		///
		Vector3 Vector3::Add(const Vector3 &left, tekreal right) 
		{
			return Vector3(left.X + right, left.Y + right, left.Z + right);
		}

		///
		/// Adds the left vector and a scalar, returning the result via pointer.
		///
		void Vector3::Add(const Vector3 &left, tekreal right, Vector3 *result) 
		{
			result->X = left.X + right;
			result->Y = left.Y + right;
		}

		///
		/// Calculates the distance between the left and right vector, returning the result.
		///
		tekreal Vector3::GetDistance(const Vector3 &left, const Vector3 &right)
		{
			tekreal dx = left.X - right.X;
			tekreal dy = left.Y - right.Y;
			tekreal dz = left.Z - right.Z;

			return (tekreal)sqrt(dx*dx + dy*dy + dz*dz);
		}

		///
		/// Calculates the distance squared (distance^2) between the left and right vector, returning the result.
		///
		tekreal Vector3::GetDistanceSquared(const Vector3 &left, const Vector3 &right) 
		{
			tekreal dx = left.X - right.X;
			tekreal dy = left.Y - right.Y;
			tekreal dz = left.Z - right.Z;

			return dx*dx + dy*dy + dz*dz;
		}

		///
		/// Divides a vector by another vector (component-wise division).
		///
		Vector3 Vector3::Divide(const Vector3 &left, const Vector3 &right) 
		{
			return Vector3(left.X / right.X, left.Y / right.Y, left.Z / right.Z);
		}

		///
		/// Divides a vector by another vector (component-wise division), and returns the result via pointer.
		///
		void Vector3::Divide(const Vector3 &left, const Vector3 &right, Vector3 *result) 
		{
			result->X = left.X/right.X;
			result->Y = left.Y/right.Y;
			result->Z = left.Z/right.Z;
		}

		///
		/// Divides a vector by a scalar (component-wise division).
		///
		Vector3 Vector3::Divide(const Vector3 &left, tekreal right) 
		{
			return Vector3(left.X / right, left.Y / right, left.Z / right);
		}

		///
		/// Divides a vector by a scalar (component-wise division), and returns the result via pointer.
		///
		void Vector3::Divide(const Vector3 &left, tekreal right, Vector3 *result) 
		{
			result->X = left.X / right;
			result->Y = left.Y / right;
			result->Z = left.Z / right;
		}

		///
		/// Calculates the dot product of two vectors.
		///
		tekreal Vector3::GetDot(const Vector3 &left, const Vector3 &right) 
		{
			return left.X*right.X + left.Y*right.Y + left.Z*right.Z;
		}

		///
		/// Calculates the cross product between two vectors.
		///
		Vector3 Vector3::GetCross(const Vector3 &left, const Vector3 &right) 
		{
			return Vector3(
				(left.Y * right.Z) - (left.Z * right.Y),
				(left.Z * right.X) - (left.X * right.Z),
				(left.X * right.Y) - (left.Y * right.X));
		}

		///
		/// Calculates the cross product between two vectors.
		///
		void Vector3::GetCross(const Vector3 &left, const Vector3 &right, Vector3 *result) 
		{
			*result = Vector3(
				(left.Y * right.Z) - (left.Z * right.Y),
				(left.Z * right.X) - (left.X * right.Z),
				(left.X * right.Y) - (left.Y * right.X));
		}

		///
		/// Calculates the length of this vector.
		///
		tekreal Vector3::GetLength() const
		{
			return (tekreal)sqrt( (tekreal)(X*X + Y*Y +Z*Z) );
		}

		///
		/// Calculates the length of the given vector.
		///
		tekreal Vector3::GetLength(const Vector3 &left) 
		{
			return (tekreal)sqrt( (tekreal)(left.X * left.X + left.Y*left.Y + left.Z*left.Z) );
		}

		///
		/// Calculates the length squared (length^2) of this vector.
		///
		tekreal Vector3::GetLengthSquared()  const
		{
			return (tekreal)(X*X + Y*Y + Z*Z);
		}

		///
		/// Calculates the length squared (length^2) of the given vector.
		///
		tekreal Vector3::GetLengthSquared(const Vector3 &left) 
		{
			return (tekreal)(left.X*left.X + left.Y*left.Y + left.Z*left.Z);
		}

		///
		/// Multiplies a vector by another vector.
		///
		Vector3 Vector3::Multiply(const Vector3 &left, const Vector3 &right) 
		{
			return Vector3(left.X*right.X, left.Y*right.Y, left.Z*right.Z);
		}

		///
		/// Multiples a vector by another vector, returning the result via pointer.
		///
		void Vector3::Multiply(const Vector3 &left, const Vector3 &right, Vector3 *result) 
		{
			result->X = left.X*right.X;
			result->Y = left.Y*right.Y;
			result->Z = left.Z*right.Z;
		}

		///
		/// Multiplies a vector by a scalar.
		///
		Vector3 Vector3::Multiply(const Vector3 &left, tekreal right) 
		{
			return Vector3(left.X * right, left.Y*right, left.Z*right);
		}

		///
		/// Multiplies a vector by a scalar, returning the result via pointer.
		///
		void Vector3::Multiply(const Vector3 &left, tekreal right, Vector3 *result) 
		{
			result->X = left.X * right;
			result->Y = left.Y * right;
			result->Z = left.Z * right;
		}

		///
		/// Returns the negation of the given vector.
		///
		Vector3 Vector3::Negate(const Vector3 &left) 
		{
			return Vector3(-left.X, -left.Y, -left.Z);
		}

		///
		/// Returns the negation via pointer of the given vector.
		///
		void Vector3::Negate(const Vector3 &left, Vector3 *result) 
		{
			result->X = -left.X;
			result->Y = -left.Y;
			result->Z = -left.Z;
		}

		///
		/// Turns this vector into a unit vector.
		///
		void Vector3::Normalize() 
		{
			tekreal len = (tekreal)sqrt((tekreal)(X*X + Y*Y + Z*Z));
			X /= len;
			Y /= len;
			Z /= len;
		}

		///
		/// Returns the normalized version of the given vector.
		///
		Vector3 Vector3::Normalize(const Vector3 &left)
		{
			tekreal len = (tekreal)sqrt((tekreal)(left.X*left.X + left.Y*left.Y + left.Z*left.Z));

			return Vector3(left.X / len, left.Y / len, left.Z / len);
		}

		///
		/// Returns the normalized version of the given vector via pointer.
		///
		void Vector3::Normalize(const Vector3 &left, Vector3 *result) 
		{
			tekreal len = (tekreal)sqrt((tekreal)(left.X*left.X + left.Y*left.Y + left.Z*left.Z));
			result->X = left.X / len;
			result->Y = left.Y / len;
			result->Z = left.Z / len;
		}

		///
		/// Reflects the given vector against the given normal.
		///
		Vector3 Vector3::Reflect(const Vector3 &vector, const Vector3 &normal) 
		{
			tekreal dot = Vector3::GetDot(normal, vector);
			return vector - (normal * dot);
			//return Vector3::Subtract(vector, Vector3::Multiply(normal, dot));
		}

		///
		/// Reflects the given vector against the given normal.
		///
		void Vector3::Reflect(const Vector3 &vector, const Vector3 &normal, Vector3 *result) 
		{
			tekreal dot = Vector3::GetDot(normal, vector);
			*result = vector - (normal * dot);
			//*result = Vector3::Subtract(vector, Vector3::Multiply(normal, dot));
		}

		///
		/// Subtracts the right vector from the left vector, returning the result.
		///
		Vector3 Vector3::Subtract(const Vector3 &left, const Vector3 &right) 
		{
			return Vector3(left.X - right.X, left.Y - right.Y, left.Z - right.Z);
		}

		///
		/// Subtracts the right vector from the left vector, returning the result via pointer.
		///
		void Vector3::Subtract(const Vector3 &left, const Vector3 &right, Vector3 *result) 
		{
			result->X = left.X - right.X;
			result->Y = left.Y - right.Y;
			result->Z = left.Z - right.Z;
		}

		///
		/// Subtracts the scalar from both components of the left vector.
		///
		Vector3 Vector3::Subtract(const Vector3 &left, tekreal right) 
		{
			return Vector3(left.X - right, left.Y - right, left.Z - right);
		}

		///
		/// Subtracts the scalar from both components of the left vector.
		///
		void Vector3::Subtract(const Vector3 &left, tekreal right, Vector3 *result) 
		{
			result->X = left.X - right;
			result->Y = left.Y - right;
			result->Z = left.Z - right;
		}

		///
		/// Adds two vectors together.
		///
		Vector3 Vector3::operator+(const Vector3 &right) const 
		{
			return Vector3(X + right.X, Y + right.Y, Z + right.Z);
		}

		///
		/// Adds a scalar to a vector.
		///
		Vector3 Vector3::operator+(tekreal right) const 
		{
			return Vector3(X + right, Y + right, Z + right);
		}

		///
		/// Adds another vector to this vector.
		///
		Vector3& Vector3::operator+=(const Vector3 &right) 
		{
			X += right.X;
			Y += right.Y;
			Z += right.Z;

			return *this;
		}

		///
		/// Adds a scalar to this vector.
		///
		Vector3& Vector3::operator+=(tekreal right) 
		{
			X += right;
			Y += right;
			Z += right;

			return *this;
		}

		///
		/// Subtracts the right vector from the left vector.
		///
		Vector3 Vector3::operator-(const Vector3 &right) const 
		{
			return Vector3(X - right.X, Y - right.Y, Z - right.Z);
		}

		///
		/// Subtracts the scalar from the left vector.
		///
		Vector3 Vector3::operator-(tekreal right) const 
		{
			return Vector3(X - right, Y - right, Z - right);
		}

		///
		/// Subtracts the right vector from this vector.
		///
		Vector3 &Vector3::operator-=(const Vector3 &right) 
		{
			X -= right.X;
			Y -= right.Y;
			Z -= right.Z;

			return *this;
		}

		///
		/// Subtracts the scalar from this vector.
		///
		Vector3 &Vector3::operator-=(tekreal right) 
		{
			X -= right;
			Y -= right;
			Z -= right;

			return *this;
		}

		///
		/// Multiples the left vector by the right vector using component-wise multiplication.
		///
		Vector3 Vector3::operator*(const Vector3 &right) const 
		{
			return Vector3(X * right.X, Y * right.Y, Z * right.Z);
		}

		///
		/// Multiples the left vector by the scalar.
		///
		Vector3 Vector3::operator*(tekreal right) const 
		{
			return Vector3(X * right, Y * right, Z * right);
		}

		///
		/// Multiples this vector by another vector using component-wise multiplication.
		///
		Vector3& Vector3::operator*=(const Vector3 &right) 
		{
			X *= right.X;
			Y *= right.Y;
			Z *= right.Z;

			return *this;
		}

		///
		/// Multiplies this vector by a scalar.
		///
		Vector3& Vector3::operator*=(tekreal right) 
		{
			X *= right;
			Y *= right;
			Z *= right;

			return *this;
		}

		///
		/// Divides the left vector by the right vector using component-wise division.
		///
		Vector3 Vector3::operator/(const Vector3 &right) const 
		{
			return Vector3(X / right.X, Y / right.Y, Z / right.Z);
		}

		///
		/// Divides the left vector by the scalar.
		///
		Vector3 Vector3::operator/(tekreal right) const 
		{
			return Vector3(X / right, Y / right, Z / right);
		}

		///
		/// Divides this vector by another vector using component-wise division.
		///
		Vector3& Vector3::operator/=(const Vector3 &right) 
		{
			X /= right.X;
			Y /= right.Y;
			Z /= right.Z;

			return *this;
		}

		///
		/// Divides this vector by a scalar.
		///
		Vector3& Vector3::operator/=(tekreal right) 
		{
			X /= right;
			Y /= right;
			Z /= right;

			return *this;
		}
	}
}
