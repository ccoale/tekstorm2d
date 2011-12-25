#pragma once
#ifndef _TEKSTORM_MATH_MATRIX4_H
#define _TEKSTORM_MATH_MATRIX4_H
#include "../tekconfig.h"
#include "Vector3.h"
#include "Vector4.h"

namespace Tekstorm
{
	namespace Math
	{
		///
		/// Represents a 4x4 mathematical matrix
		/// (Original class design from Alex @ http://code.google.com/p/slimmath/source/browse/trunk/SlimMath/Matrix.cs)
		/// (However this implementation is in no way endorsed by the slimmath project.)
		///
		class TEKAPI Matrix4
		{
		public:
			union
			{
				// The underlying matrix members.
				tekreal Data[4][4];

				struct {
					tekreal M11;
					tekreal M12;
					tekreal M13;
					tekreal M14;

					tekreal M21;
					tekreal M22;
					tekreal M23;
					tekreal M24;

					tekreal M31;
					tekreal M32;
					tekreal M33;
					tekreal M34;

					tekreal M41;
					tekreal M42;
					tekreal M43;
					tekreal M44;
				};
			};
		public:

			///
			/// Represents a matrix with all of its elements set to zero.
			///
			static const Matrix4 Zero;

			///
			/// Represents an identity matrix.
			///
			static const Matrix4 Identity;

			///
			/// Initializes a new instance of Matrix4, initializing
			/// all values to the given value.
			///
			Matrix4(tekreal value = 0);

			///
			/// Initializes a new instance of Matrix4, given another matrix.
			///
			Matrix4(const Matrix4 &other);

			///
			/// Initializes a new instance of Matrix4, given a pointer to the start of the matrix.
			///
			Matrix4(const tekreal *data);

			///
			/// Initializes a new instance of Matrix4, given an entire list of values.
			///
			Matrix4(tekreal m11, tekreal m12, tekreal m13, tekreal m14,
				tekreal m21, tekreal m22, tekreal m23, tekreal m24,
				tekreal m31, tekreal m32, tekreal m33, tekreal m34,
				tekreal m41, tekreal m42, tekreal m43, tekreal m44);

			///
			/// Gets a pointer to the raw underlying data.
			///
			tekreal *GetData();

			///
			/// Gets the given row as a Vector4.
			///
			Vector4 GetRow(int32_t row) const;

			///
			/// Gets the given column as a Vector4.
			///
			Vector4 GetColumn(int32_t col) const;

			///
			/// Sets the given row, given a Vector4.
			///
			void SetRow(int32_t row, const Vector4 &data);

			///
			/// Sets a given column, given a Vector4.
			///
			void SetColumn(int32_t col, const Vector4 &data);

			///
			/// Determines whether or not this Matrix is an identity matrix.
			///
			bool IsIdentity() const;

			///
			/// Adds this matrix with another.
			///
			Matrix4 operator+(const Matrix4 &other);

			///
			/// Adds this matrix with another.
			///
			Matrix4 &operator+=(const Matrix4 &other);

			///
			/// Subtracts another matrix from this matrix.
			///
			Matrix4 operator-(const Matrix4 &other);

			///
			/// Subtracts another matrix from this matrix.
			///
			Matrix4 &operator-=(const Matrix4 &other);

			///
			/// Multiples this matrix with a scalar.
			///
			Matrix4 operator*(tekreal scale);

			///
			/// Multiplies this matrix with a scalar;
			///
			Matrix4 &operator*=(tekreal scale);

			///
			/// Multiples this matrix by another matrix.
			///
			Matrix4 operator*(const Matrix4 &other);

			///
			/// Multiplies this matrix by another matrix.
			///
			Matrix4 &operator*=(const Matrix4 &other);

			///
			/// Gets the determinant of this matrix.
			///
			tekreal GetDeterminant() const;

			///
			/// Negates this matrix.
			///
			void Negate();

			///
			/// Negates the given matrix.
			///
			static Matrix4 Negate(const Matrix4 &m1);

			///
			/// Negates the given matrix.
			///
			static void Negate(const Matrix4 &m1, Matrix4 *out);

			///
			/// Inverts this matrix.
			///
			void Invert();

			///
			/// Inverts the given matrix.
			///
			static Matrix4 Invert(const Matrix4 &m1);

			///
			/// Inverts the given matrix.
			///
			static void Invert(const Matrix4 &m1, Matrix4 *out);

			///
			/// Transposes this matrix.
			///
			void Transpose();

			///
			/// Transposes the given matrix.
			///
			static Matrix4 Transpose(const Matrix4 &m1);

			///
			/// Transposes the given matrix.
			///
			static void Transpose(const Matrix4 &m1, Matrix4 *out);

			///
			/// Adds two matrices together, returning the new matrix.
			///
			static Matrix4 Add(const Matrix4 &m1, const Matrix4 &m2);

			///
			/// Adds two matrices together, returning the third matrix via pointer.
			///
			static void Add(const Matrix4 &m1, const Matrix4 &m2, Matrix4 *out);

			///
			/// Subtracts two matrices.
			//
			static Matrix4 Subtract(const Matrix4 &m1, const Matrix4 &m2);

			///
			/// Subtracts two matrices.
			///
			static void Subtract(const Matrix4 &m1, const Matrix4 &m2, Matrix4 *out);

			///
			/// Multiplies the given matrix by a scalar.
			///
			static Matrix4 Multiply(const Matrix4 &m1, tekreal scalar);

			///
			/// Multiples the given matrix by a scalar.
			///
			static void Multiply(const Matrix4 &m1, tekreal scalar, Matrix4 *out);

			///
			/// Multiples the given matrix by another matrix.
			///
			static Matrix4 Multiply(const Matrix4 &m1, const Matrix4 &m2);

			///
			/// Multiplies the give matrix by another matrix.
			///
			static void Multiply(const Matrix4 &m1, const Matrix4 &m2, Matrix4 *out);

			///
			/// Creates a matrix that rotates about the X-axis.
			///
			static Matrix4 CreateRotationX(tekreal angle);

			///
			/// Creates a matrix that rotates about the X-axis.
			///
			static void CreateRotationX(tekreal angle, Matrix4 *out);

			///
			/// Creates a matrix that rotates about the Y-axis.
			///
			static Matrix4 CreateRotationY(tekreal angle);

			///
			/// Creates a matrix that rotates about the Y-axis.
			///
			static void CreateRotationY(tekreal angle, Matrix4 *out);

			///
			/// Creates a matrix that rotates about the Z-axis.
			///
			static Matrix4 CreateRotationZ(tekreal angle);

			///
			/// Creates a matrix that rotates about the Z-axis.
			///
			static void CreateRotationZ(tekreal angle, Matrix4 *out);

			///
			/// Creates a rotation matrix that rotates about all 3 axes.
			///
			static Matrix4 CreateRotation(const Vector3 &yawPitchRoll);

			///
			/// Creates a rotation matrix that rotates about all 3 axes.
			///
			static void CreateRotation(const Vector3 &yawPitchRoll, Matrix4 *out);

			///
			/// Creates a scale matrix that scales about all 3 axes.
			///
			static Matrix4 CreateScale(const Vector3 &scale);

			///
			/// Creates a scale matrix that scales about all 3 axes.
			///
			static void CreateScale(const Vector3 &scale, Matrix4 *out);

			///
			/// Creates a translation matrix.
			///
			static Matrix4 CreateTranslation(const Vector3 &translation);

			///
			/// Creates a translation matrix.
			///
			static void CreateTranslation(const Vector3 &translation, Matrix4 *out);

			///
			/// Creates an off-centered left-handed orthographic projection matrix.
			///
			static Matrix4 CreateOffCenterOrthoLH(tekreal left, tekreal right, tekreal bottom,
				tekreal top, tekreal znear, tekreal zfar);

			///
			/// Creates an off-centered left-handed orthographic projection matrix.
			///
			static void CreateOffCenterOrthoLH(tekreal left, tekreal right, tekreal bottom,
				tekreal top, tekreal znear, tekreal zfar, Matrix4 *out);
		};
	}
}

#endif /* _TEKSTORM_MATH_MATRIX4_H */