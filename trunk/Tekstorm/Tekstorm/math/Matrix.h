#ifndef _TEKSTORM_MATRIX_H
#define _TEKSTORM_MATRIX_H
#include "../TekstormDecl.h"
#include "Vector3.h"

namespace Tekstorm
{
	namespace Math
	{
		// Represents a 4x4 row-major matrix.
		class TEKDECL Matrix
		{
		public:
			// Represents an empty matrix (all elements are set to 0.0f)
			static Matrix Zero;

			// Represents an identity matrix (all diagonal elements are set to 1.0f)
			static Matrix Identity;

			// first row of values
			float M11, M12, M13, M14;

			// second row of values
			float M21, M22, M23, M24;

			// third row of values
			float M31, M32, M33, M34;

			// fourth row of values
			float M41, M42, M43, M44;

			// Initializes a new instance of the Matrix class (and optionally assigns a scalar value to each element).
			Matrix(float value = 0.0f);

			// Initializes a new instance of the Matrix class, allowing each element to be set individually.
			Matrix(float m11, float m12, float m13, float m14, 
				float m21, float m22, float m23, float m24,
				float m31, float m32, float m33, float m34,
				float m41, float m42, float m43, float m44);

			// Transposes this matrix and returns a reference to itself.
			Matrix& Transpose();

			// Transposes the given matrix, returning the transposed matrix.
			static Matrix Transpose(const Matrix& mat);

			// Transposes the given matrix, returning the transposed matrix by reference.
			static void Transpose(const Matrix& mat, Matrix& result);

			// Lerps this matrix with another and returns a reference to itself.
			Matrix& Lerp(const Matrix& other, float weight);

			// Lerps the start matrix with the end matrix given the weight, and returns a new matrix.
			static Matrix Lerp(const Matrix& start, const Matrix& end, float weight);

			// Lerps the start matrix with the end matrix given the weight, and returns a new matrix via reference.
			static void Lerp(const Matrix& start, const Matrix& end, float weight, Matrix& result);

			// Negates this matrix and returns a reference to itself.
			Matrix& Negate();

			// Returns the negation of the given matrix.
			static Matrix Negate(const Matrix& mat);

			// Returns via reference the negation of the given matrix.
			static void Negate(const Matrix& mat, Matrix& result);

			// Performs a smooth step interpolation on this matrix with another, and returns a reference to itself.
			Matrix& SmoothStep(const Matrix& other, float weight);

			// Performs a smooth step interpolation on the two given matrices, and returns a new matrix.
			static Matrix SmoothStep(const Matrix& start, const Matrix& end, float weight);

			// Performs a smooth step interpolation on the two given matrices, and returns a new matrix via reference.
			static void SmoothStep(const Matrix& start, const Matrix& end, float weight, Matrix& result);

			// Inverts this matrix, returning a reference to itself.
			Matrix& Invert();

			// Inverts the given matrix, returning a new matrix.
			static Matrix Invert(const Matrix& mat);

			// Inverts the given matrix, returning a new matrix via reference.
			static void Invert(const Matrix& mat, Matrix& result);

			// Multiplies this matrix by a scalar, returning a new matrix.
			Matrix operator*(float scalar);

			// Multiplies this matrix by another matrix, returning a new matrix.
			Matrix operator*(const Matrix& other);

			// Multiplies this matrix by a scalar and assigns this matrix that result.
			Matrix& operator*=(float scalar);

			// Multiplies this matrix by a matrix and assigns this matrix that result.
			Matrix& operator*=(const Matrix& other);

			// Adds another matrix to this matrix returning a new matrix.
			Matrix operator+(const Matrix& other);

			// Adds another matrix to this matrix, returning a reference to this matrix.
			Matrix& operator+=(const Matrix& other);

			// Subtracts another matrix from this matrix, returning a new matrix.
			Matrix operator-(const Matrix& other);

			// Subtracts another matrix from this matrix, assigning the new matrix to this matrix.
			Matrix& operator-=(const Matrix& other);

			// Negates all elements within this matrix.
			Matrix& operator-();

			// Divides this matrix by a scalar and returns the new matrix.
			Matrix operator/(float scalar);

			// Divides this matrix by a scalar and returns this matrix.
			Matrix& operator/=(float scalar);
		};
	}
}

#endif /* _TEKSTORM_MATRIX_H */