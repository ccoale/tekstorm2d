#define __BUILD
#include "Matrix.h"

namespace Tekstorm
{
	namespace Math
	{
		// Represents an empty matrix (all elements are set to 0.0f)
		Matrix Matrix::Zero = Matrix(0.f, 0.f, 0.f, 0.f,
									0.f, 0.f, 0.f, 0.f,
									0.f, 0.f, 0.f, 0.f,
									0.f, 0.f, 0.f, 0.f);

		// Represents an identity matrix (all diagonal elements are set to 1.0f)
		Matrix Matrix::Identity = Matrix(1.f, 0.f, 0.f, 0.f,
										0.f, 1.f, 0.f, 0.f,
										0.f, 0.f, 1.f, 0.f,
										0.f, 0.f, 0.f, 1.f);

		// Initializes a new instance of the Matrix class (and optionally assigns a scalar value to each element).
		Matrix::Matrix(float value)
		{
			M11 = M12 = M13 = M14 = M21 = M22 = M23 = M24 = M31 = M32 = M33 = M34 = M41 = M42 = M43 = M44 = value;
		}

		// Initializes a new instance of the Matrix class, allowing each element to be set individually.
		Matrix::Matrix(float m11, float m12, float m13, float m14, 
			float m21, float m22, float m23, float m24,
			float m31, float m32, float m33, float m34,
			float m41, float m42, float m43, float m44)
		{
			M11 = m11; M21 = m21; M31 = m31; M41 = m41;
			M12 = m12; M22 = m22; M32 = m32; M42 = m42;
			M13 = m13; M23 = m23; M33 = m33; M43 = m43;
			M14 = m14; M24 = m24; M34 = m34; M44 = m44;
		}

		// Transposes this matrix and returns a reference to itself.
		Matrix& Matrix::Transpose()
		{
			Matrix temp;
			temp.M11 = M11;
			temp.M12 = M21;
			temp.M13 = M31;
			temp.M14 = M41;
			temp.M21 = M12;
			temp.M22 = M22;
			temp.M23 = M32;
			temp.M24 = M42;
			temp.M31 = M13;
			temp.M32 = M23;
			temp.M34 = M43;
			temp.M41 = M14;
			temp.M42 = M24;
			temp.M43 = M34;
			temp.M44 = M44;
			*this = temp;

			return *this;
		}

		// Transposes the given matrix, returning the transposed matrix.
		Matrix Matrix::Transpose(const Matrix& mat)
		{
			return Matrix(
				mat.M11, mat.M21, mat.M31, mat.M41,
				mat.M12, mat.M22, mat.M32, mat.M42,
				mat.M13, mat.M23, mat.M33, mat.M43,
				mat.M14, mat.M24, mat.M34, mat.M44);
		}

		// Transposes the given matrix, returning the transposed matrix by reference.
		void Matrix::Transpose(const Matrix& mat, Matrix& result)
		{
			result.M11 = mat.M11;
			result.M12 = mat.M21;
			result.M13 = mat.M31;
			result.M14 = mat.M41;

			result.M21 = mat.M12;
			result.M22 = mat.M22;
			result.M23 = mat.M32;
			result.M24 = mat.M42;

			result.M31 = mat.M13;
			result.M32 = mat.M23;
			result.M33 = mat.M33;
			result.M34 = mat.M43;

			result.M41 = mat.M14;
			result.M42 = mat.M24;
			result.M43 = mat.M34;
			result.M44 = mat.M44;
		}

		// Lerps this matrix with another and returns a reference to itself.
		Matrix& Matrix::Lerp(const Matrix& other, float weight)
		{
			M11 = M11 + (other.M11 - M11) * weight;
			M12 = M12 + (other.M12 - M12) * weight;
			M13 = M13 + (other.M13 - M13) * weight;
			M14 = M14 + (other.M14 - M14) * weight;
			M21 = M21 + (other.M21 - M21) * weight;
			M22 = M22 + (other.M22 - M22) * weight;
			M23 = M23 + (other.M23 - M23) * weight;
			M24 = M24 + (other.M24 - M24) * weight;
			M31 = M31 + (other.M31 - M31) * weight;
			M32 = M32 + (other.M32 - M32) * weight;
			M33 = M33 + (other.M33 - M33) * weight;
			M34 = M34 + (other.M34 - M34) * weight;
			M41 = M41 + (other.M41 - M41) * weight;
			M42 = M42 + (other.M42 - M42) * weight;
			M43 = M43 + (other.M43 - M43) * weight;
			M44 = M44 + (other.M44 - M44) * weight;

			return *this;
		}

		// Lerps the start matrix with the end matrix given the weight, and returns a new matrix.
		Matrix Matrix::Lerp(const Matrix& start, const Matrix& end, float weight)
		{
			Matrix res;
			res.M11 = start.M11 + (end.M11 - start.M11) * weight;
			res.M12 = start.M12 + (end.M12 - start.M12) * weight;
			res.M13 = start.M13 + (end.M13 - start.M13) * weight;
			res.M14 = start.M14 + (end.M14 - start.M14) * weight;
			res.M21 = start.M21 + (end.M21 - start.M21) * weight;
			res.M22 = start.M22 + (end.M22 - start.M22) * weight;
			res.M23 = start.M23 + (end.M23 - start.M23) * weight;
			res.M24 = start.M24 + (end.M24 - start.M24) * weight;
			res.M31 = start.M31 + (end.M31 - start.M31) * weight;
			res.M32 = start.M32 + (end.M32 - start.M32) * weight;
			res.M33 = start.M33 + (end.M33 - start.M33) * weight;
			res.M34 = start.M34 + (end.M34 - start.M34) * weight;
			res.M41 = start.M41 + (end.M41 - start.M41) * weight;
			res.M42 = start.M42 + (end.M42 - start.M42) * weight;
			res.M43 = start.M43 + (end.M43 - start.M43) * weight;
			res.M44 = start.M44 + (end.M44 - start.M44) * weight;

			return res;
		}

		// Lerps the start matrix with the end matrix given the weight, and returns a new matrix via reference.
		void Matrix::Lerp(const Matrix& start, const Matrix& end, float weight, Matrix& res)
		{
			res.M11 = start.M11 + (end.M11 - start.M11) * weight;
			res.M12 = start.M12 + (end.M12 - start.M12) * weight;
			res.M13 = start.M13 + (end.M13 - start.M13) * weight;
			res.M14 = start.M14 + (end.M14 - start.M14) * weight;
			res.M21 = start.M21 + (end.M21 - start.M21) * weight;
			res.M22 = start.M22 + (end.M22 - start.M22) * weight;
			res.M23 = start.M23 + (end.M23 - start.M23) * weight;
			res.M24 = start.M24 + (end.M24 - start.M24) * weight;
			res.M31 = start.M31 + (end.M31 - start.M31) * weight;
			res.M32 = start.M32 + (end.M32 - start.M32) * weight;
			res.M33 = start.M33 + (end.M33 - start.M33) * weight;
			res.M34 = start.M34 + (end.M34 - start.M34) * weight;
			res.M41 = start.M41 + (end.M41 - start.M41) * weight;
			res.M42 = start.M42 + (end.M42 - start.M42) * weight;
			res.M43 = start.M43 + (end.M43 - start.M43) * weight;
			res.M44 = start.M44 + (end.M44 - start.M44) * weight;
		}

		// Negates this matrix and returns a reference to itself.
		Matrix& Matrix::Negate()
		{
			M11 = -M11;
			M12 = -M12;
			M13 = -M13;
			M14 = -M14;
			M21 = -M21;
			M22 = -M22;
			M23 = -M23;
			M24 = -M24;
			M31 = -M31;
			M32 = -M32;
			M33 = -M33;
			M34 = -M34;
			M41 = -M41;
			M42 = -M42;
			M43 = -M43;
			M44 = -M44;

			return *this;
		}

		// Returns the negation of the given matrix.
		Matrix Matrix::Negate(const Matrix& mat)
		{
			Matrix res;
			res.M11 = -mat.M11;
			res.M12 = -mat.M12;
			res.M13 = -mat.M13;
			res.M14 = -mat.M14;
			res.M21 = -mat.M21;
			res.M22 = -mat.M22;
			res.M23 = -mat.M23;
			res.M24 = -mat.M24;
			res.M31 = -mat.M31;
			res.M32 = -mat.M32;
			res.M33 = -mat.M33;
			res.M34 = -mat.M34;
			res.M41 = -mat.M41;
			res.M42 = -mat.M42;
			res.M43 = -mat.M43;
			res.M44 = -mat.M44;

			return res;
		}

		// Returns via reference the negation of the given matrix.
		void Matrix::Negate(const Matrix& mat, Matrix& res)
		{
			res.M11 = -mat.M11;
			res.M12 = -mat.M12;
			res.M13 = -mat.M13;
			res.M14 = -mat.M14;
			res.M21 = -mat.M21;
			res.M22 = -mat.M22;
			res.M23 = -mat.M23;
			res.M24 = -mat.M24;
			res.M31 = -mat.M31;
			res.M32 = -mat.M32;
			res.M33 = -mat.M33;
			res.M34 = -mat.M34;
			res.M41 = -mat.M41;
			res.M42 = -mat.M42;
			res.M43 = -mat.M43;
			res.M44 = -mat.M44;
		}

		// Performs a smooth step interpolation on this matrix with another, and returns a reference to itself.
		Matrix& Matrix::SmoothStep(const Matrix& other, float weight)
		{
			weight = (weight * weight) * (3.0f - (2.0f * weight));
			M11 = M11 + (other.M11 - M11) * weight;
			M12 = M12 + (other.M12 - M12) * weight;
			M13 = M13 + (other.M13 - M13) * weight;
			M14 = M14 + (other.M14 - M14) * weight;
			M21 = M21 + (other.M21 - M21) * weight;
			M22 = M22 + (other.M22 - M22) * weight;
			M23 = M23 + (other.M23 - M23) * weight;
			M24 = M24 + (other.M24 - M24) * weight;
			M31 = M31 + (other.M31 - M31) * weight;
			M32 = M32 + (other.M32 - M32) * weight;
			M33 = M33 + (other.M33 - M33) * weight;
			M34 = M34 + (other.M34 - M34) * weight;
			M41 = M41 + (other.M41 - M41) * weight;
			M42 = M42 + (other.M42 - M42) * weight;
			M43 = M43 + (other.M43 - M43) * weight;
			M44 = M44 + (other.M44 - M44) * weight;
			return *this;
		}

		// Performs a smooth step interpolation on the two given matrices, and returns a new matrix.
		Matrix Matrix::SmoothStep(const Matrix& start, const Matrix& end, float weight)
		{
			weight = (weight * weight) * (3.0f - (2.0f * weight));
			Matrix res;
			res.M11 = start.M11 + (end.M11 - start.M11) * weight;
			res.M12 = start.M12 + (end.M12 - start.M12) * weight;
			res.M13 = start.M13 + (end.M13 - start.M13) * weight;
			res.M14 = start.M14 + (end.M14 - start.M14) * weight;
			res.M21 = start.M21 + (end.M21 - start.M21) * weight;
			res.M22 = start.M22 + (end.M22 - start.M22) * weight;
			res.M23 = start.M23 + (end.M23 - start.M23) * weight;
			res.M24 = start.M24 + (end.M24 - start.M24) * weight;
			res.M31 = start.M31 + (end.M31 - start.M31) * weight;
			res.M32 = start.M32 + (end.M32 - start.M32) * weight;
			res.M33 = start.M33 + (end.M33 - start.M33) * weight;
			res.M34 = start.M34 + (end.M34 - start.M34) * weight;
			res.M41 = start.M41 + (end.M41 - start.M41) * weight;
			res.M42 = start.M42 + (end.M42 - start.M42) * weight;
			res.M43 = start.M43 + (end.M43 - start.M43) * weight;
			res.M44 = start.M44 + (end.M44 - start.M44) * weight;
			return res;
		}

		// Performs a smooth step interpolation on the two given matrices, and returns a new matrix via reference.
		void Matrix::SmoothStep(const Matrix& start, const Matrix& end, float weight, Matrix& res)
		{
			weight = (weight * weight) * (3.0f - (2.0f * weight));
			res.M11 = start.M11 + (end.M11 - start.M11) * weight;
			res.M12 = start.M12 + (end.M12 - start.M12) * weight;
			res.M13 = start.M13 + (end.M13 - start.M13) * weight;
			res.M14 = start.M14 + (end.M14 - start.M14) * weight;
			res.M21 = start.M21 + (end.M21 - start.M21) * weight;
			res.M22 = start.M22 + (end.M22 - start.M22) * weight;
			res.M23 = start.M23 + (end.M23 - start.M23) * weight;
			res.M24 = start.M24 + (end.M24 - start.M24) * weight;
			res.M31 = start.M31 + (end.M31 - start.M31) * weight;
			res.M32 = start.M32 + (end.M32 - start.M32) * weight;
			res.M33 = start.M33 + (end.M33 - start.M33) * weight;
			res.M34 = start.M34 + (end.M34 - start.M34) * weight;
			res.M41 = start.M41 + (end.M41 - start.M41) * weight;
			res.M42 = start.M42 + (end.M42 - start.M42) * weight;
			res.M43 = start.M43 + (end.M43 - start.M43) * weight;
			res.M44 = start.M44 + (end.M44 - start.M44) * weight;
		}

		// Inverts this matrix, returning a reference to itself.
		Matrix& Matrix::Invert()
		{
			// not yet implemented
			return *this;
		}

		// Inverts the given matrix, returning a new matrix.
		Matrix Matrix::Invert(const Matrix& mat)
		{
			// not yet implemented
			return mat;
		}

		// Inverts the given matrix, returning a new matrix via reference.
		void Matrix::Invert(const Matrix& mat, Matrix& result)
		{
			// not yet implemented
		}

		// Multiplies this matrix by a scalar, returning a new matrix.
		Matrix Matrix::operator*(float scalar)
		{
			return Matrix(M11 * scalar, M12 * scalar, M13 * scalar, M14 * scalar,
				M21 * scalar, M22 * scalar, M23 * scalar, M24 * scalar,
				M31 * scalar, M32 * scalar, M33 * scalar, M34 * scalar,
				M41 * scalar, M42 * scalar, M43 * scalar, M44 * scalar);
		}

		// Multiplies this matrix by another matrix, returning a new matrix.
		Matrix Matrix::operator*(const Matrix& other)
		{
			// -- CHANGE TO REAL MULTIPLY SOON --
			Matrix res;
			D3DXMatrixMultiply((D3DXMATRIX *)&res, (const D3DXMATRIX *)this, (const D3DXMATRIX *)&other);

			return res;
		}

		// Multiplies this matrix by a scalar and assigns this matrix that result.
		Matrix& Matrix::operator*=(float scalar)
		{
			M11 *= scalar;
			M12 *= scalar;
			M13 *= scalar;
			M14 *= scalar;
			M21 *= scalar;
			M22 *= scalar;
			M23 *= scalar;
			M24 *= scalar;
			M31 *= scalar;
			M32 *= scalar;
			M33 *= scalar;
			M34 *= scalar;
			M41 *= scalar;
			M42 *= scalar;
			M43 *= scalar;
			M44 *= scalar;

			return *this;
		}

		// Multiplies this matrix by a matrix and assigns this matrix that result.
		Matrix& Matrix::operator*=(const Matrix& other)
		{
			// -- CHANGE TO REAL MULTIPLY SOON --
			D3DXMatrixMultiply((D3DXMATRIX *)this, (const D3DXMATRIX *)this, (const D3DXMATRIX *)&other);
			return *this;
		}

		// Adds another matrix to this matrix returning a new matrix.
		Matrix Matrix::operator+(const Matrix& other)
		{
			return Matrix(M11 + other.M11, M12 + other.M12, M13 + other.M13, M14 + other.M14,
				M21 + other.M21, M22 + other.M22, M23 + other.M23, M24 + other.M24,
				M31 + other.M31, M32 + other.M32, M33 + other.M33, M34 + other.M34,
				M41 + other.M41, M42 + other.M42, M43 + other.M43, M44 + other.M44);
		}

		// Adds another matrix to this matrix, returning a reference to this matrix.
		Matrix& Matrix::operator+=(const Matrix& other)
		{
			M11 += other.M11;
			M12 += other.M12;
			M13 += other.M13;
			M14 += other.M14;
			M21 += other.M21;
			M22 += other.M22;
			M23 += other.M23;
			M24 += other.M24;
			M31 += other.M31;
			M32 += other.M32;
			M33 += other.M33;
			M34 += other.M34;
			M41 += other.M41;
			M42 += other.M42;
			M43 += other.M43;
			M44 += other.M44;

			return *this;
		}

		// Subtracts another matrix from this matrix, returning a new matrix.
		Matrix Matrix::operator-(const Matrix& other)
		{
			return Matrix(M11 - other.M11, M12 - other.M12, M13 - other.M13, M14 - other.M14,
				M21 - other.M21, M22 - other.M22, M23 - other.M23, M24 - other.M24,
				M31 - other.M31, M32 - other.M32, M33 - other.M33, M34 - other.M34,
				M41 - other.M41, M42 - other.M42, M43 - other.M43, M44 - other.M44);
		}

		// Subtracts another matrix from this matrix, assigning the new matrix to this matrix.
		Matrix& Matrix::operator-=(const Matrix& other)
		{
			M11 -= other.M11;
			M12 -= other.M12;
			M13 -= other.M13;
			M14 -= other.M14;
			M21 -= other.M21;
			M22 -= other.M22;
			M23 -= other.M23;
			M24 -= other.M24;
			M31 -= other.M31;
			M32 -= other.M32;
			M33 -= other.M33;
			M34 -= other.M34;
			M41 -= other.M41;
			M42 -= other.M42;
			M43 -= other.M43;
			M44 -= other.M44;

			return *this;
		}

		// Negates all elements within this matrix.
		Matrix& Matrix::operator-()
		{
			M11 = -M11;
			M12 = -M12;
			M13 = -M13;
			M14 = -M14;
			M21 = -M21;
			M22 = -M22;
			M23 = -M23;
			M24 = -M24;
			M31 = -M31;
			M32 = -M32;
			M33 = -M33;
			M34 = -M34;
			M41 = -M41;
			M42 = -M42;
			M43 = -M43;
			M44 = -M44;

			return *this;
		}

		// Divides this matrix by a scalar and returns the new matrix.
		Matrix Matrix::operator/(float scalar)
		{
			return Matrix(M11 / scalar, M12 / scalar, M13 / scalar, M14 / scalar,
				M21 / scalar, M22 / scalar, M23 / scalar, M24 / scalar,
				M31 / scalar, M32 / scalar, M33 / scalar, M34 / scalar,
				M41 / scalar, M42 / scalar, M43 / scalar, M44 / scalar);
		}

		// Divides this matrix by a scalar and returns this matrix.
		Matrix& Matrix::operator/=(float scalar)
		{
			M11 /= scalar;
			M12 /= scalar;
			M13 /= scalar;
			M14 /= scalar;
			M21 /= scalar;
			M22 /= scalar;
			M23 /= scalar;
			M24 /= scalar;
			M31 /= scalar;
			M32 /= scalar;
			M33 /= scalar;
			M34 /= scalar;
			M41 /= scalar;
			M42 /= scalar;
			M43 /= scalar;
			M44 /= scalar;

			return *this;
		}
	}
}