#define TEKSTORM_BUILD
#include "Matrix4.h"

namespace Tekstorm
{
	namespace Math
	{	
		///
		/// Represents a matrix with all of its elements set to zero.
		///
		const Matrix4 Matrix4::Zero = Matrix4(0.0);

		///
		/// Represents an identity matrix.
		///
		const Matrix4 Matrix4::Identity = Matrix4(1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0);

		///
		/// Initializes a new instance of Matrix4, initializing
		/// all values to the given value.
		///
		Matrix4::Matrix4(tekreal value)
		{
			Data[0][0] = Data[0][1] = Data[0][2] = Data[0][3]
			= Data[1][0] = Data[1][1] = Data[1][2] = Data[1][3]
			= Data[2][0] = Data[2][1] = Data[2][2] = Data[2][3]
			= Data[3][0] = Data[3][1] = Data[3][2] = Data[3][3]
			= value;
		}

		///
		/// Initializes a new instance of Matrix4, given another matrix.
		///
		Matrix4::Matrix4(const Matrix4 &other)
		{
			Data[0][0] = other.Data[0][0];
			Data[0][1] = other.Data[0][1];
			Data[0][2] = other.Data[0][2];
			Data[0][3] = other.Data[0][3];

			Data[1][0] = other.Data[1][0];
			Data[1][1] = other.Data[1][1];
			Data[1][2] = other.Data[1][2];
			Data[1][3] = other.Data[1][3];

			Data[2][0] = other.Data[2][0];
			Data[2][1] = other.Data[2][1];
			Data[2][2] = other.Data[2][2];
			Data[2][3] = other.Data[2][3];

			Data[3][0] = other.Data[3][0];
			Data[3][1] = other.Data[3][1];
			Data[3][2] = other.Data[3][2];
			Data[3][3] = other.Data[3][3];
		}

		///
		/// Initializes a new instance of Matrix4, given a pointer to the start of the matrix.
		///
		Matrix4::Matrix4(const tekreal *data)
		{
			Data[0][0] = data[0];
			Data[0][1] = data[1];
			Data[0][2] = data[2];
			Data[0][3] = data[3];

			Data[1][0] = data[4];
			Data[1][1] = data[5];
			Data[1][2] = data[6];
			Data[1][3] = data[7];

			Data[2][0] = data[8];
			Data[2][1] = data[9];
			Data[2][2] = data[10];
			Data[2][3] = data[11];

			Data[3][0] = data[12];
			Data[3][1] = data[13];
			Data[3][2] = data[14];
			Data[3][3] = data[15];
		}

		///
		/// Initializes a new instance of Matrix4, given an entire list of values.
		///
		Matrix4::Matrix4(tekreal m11, tekreal m12, tekreal m13, tekreal m14,
			tekreal m21, tekreal m22, tekreal m23, tekreal m24,
			tekreal m31, tekreal m32, tekreal m33, tekreal m34,
			tekreal m41, tekreal m42, tekreal m43, tekreal m44)
		{

			Data[0][0] = m11;
			Data[0][1] = m12;
			Data[0][2] = m13;
			Data[0][3] = m14;

			Data[1][0] = m21;
			Data[1][1] = m22;
			Data[1][2] = m23;
			Data[1][3] = m24;

			Data[1][0] = m31;
			Data[1][1] = m32;
			Data[1][2] = m33;
			Data[1][3] = m34;

			Data[0][0] = m41;
			Data[1][1] = m42;
			Data[1][2] = m43;
			Data[1][3] = m44;
		}


		///
		/// Gets a pointer to the raw underlying data.
		///
		tekreal *Matrix4::GetData()
		{
			return Data[0];
		}

		///
		/// Gets the given row as a Vector4.
		///
		Vector4 Matrix4::GetRow(int32_t row) const
		{
			return Vector4(Data[row][0], Data[row][1], Data[row][2], Data[row][3]);
		}

		///
		/// Gets the given column as a Vector4.
		///
		Vector4 Matrix4::GetColumn(int32_t col) const
		{
			return Vector4(Data[0][col], Data[1][col], Data[2][col], Data[3][col]);
		}

		///
		/// Sets the given row, given a Vector4.
		///
		void Matrix4::SetRow(int32_t row, const Vector4 &data)
		{
			Data[row][0] = data.X;
			Data[row][1] = data.Y;
			Data[row][2] = data.Z;
			Data[row][3] = data.W;
		}

		///
		/// Sets a given column, given a Vector4.
		///
		void Matrix4::SetColumn(int32_t col, const Vector4 &data)
		{
			Data[0][col] = data.X;
			Data[1][col] = data.Y;
			Data[2][col] = data.Z;
			Data[3][col] = data.W;
		}

		///
		/// Determines whether or not this Matrix is an identity matrix.
		///
		bool Matrix4::IsIdentity() const
		{
			return (Data[0][0] == 1.0f && Data[1][1] == 1.0f && Data[2][2] == 1.0f && Data[3][3] == 1.0f)
				&& (Data[0][1] == 0.0f && Data[0][2] == 0.0f && Data[0][3] == 0.0f)
				&& (Data[1][0] == 0.0f && Data[1][2] == 0.0f && Data[1][3] == 0.0f)
				&& (Data[2][0] == 0.0f && Data[2][1] == 0.0f && Data[2][3] == 0.0f)
				&& (Data[3][0] == 0.0f && Data[3][1] == 0.0f && Data[3][2] == 0.0f);
		}

		///
		/// Adds this matrix with another.
		///
		Matrix4 Matrix4::operator+(const Matrix4 &other)
		{
			return Matrix4::Add(*this, other);
		}

		///
		/// Adds this matrix with another.
		///
		Matrix4 &Matrix4::operator+=(const Matrix4 &other)
		{
			Matrix4 temp;
			Matrix4::Add(*this, other, &temp);
			*this = temp;

			return *this;
		}

		///
		/// Subtracts another matrix from this matrix.
		///
		Matrix4 Matrix4::operator-(const Matrix4 &other)
		{
			return Matrix4::Subtract(*this, other);
		}

		///
		/// Subtracts another matrix from this matrix.
		///
		Matrix4 &Matrix4::operator-=(const Matrix4 &other)
		{
			Matrix4 temp;
			Matrix4::Subtract(*this, other);
			*this = temp;

			return *this;
		}

		///
		/// Multiples this matrix with a scalar.
		///
		Matrix4 Matrix4::operator*(tekreal scale)
		{
			return Matrix4::Multiply(*this, scale);
		}

		///
		/// Multiplies this matrix with a scalar;
		///
		Matrix4 &Matrix4::operator*=(tekreal scale)
		{
			Matrix4 temp;
			Matrix4::Multiply(*this, scale);
			*this = temp;
			return *this;
		}

		///
		/// Multiples this matrix by another matrix.
		///
		Matrix4 Matrix4::operator*(const Matrix4 &other)
		{
			return Matrix4::Multiply(*this, other);
		}

		///
		/// Multiplies this matrix by another matrix.
		///
		Matrix4 &Matrix4::operator*=(const Matrix4 &other)
		{
			Matrix4 temp;
			Matrix4::Multiply(*this, other);
			*this = temp;
			return *this;
		}

		///
		/// Gets the determinant of this matrix.
		///
		tekreal Matrix4::GetDeterminant() const
		{
			float temp1 = (M33 * M44) - (M34 * M43);
			float temp2 = (M32 * M44) - (M34 * M42);
			float temp3 = (M32 * M43) - (M33 * M42);
			float temp4 = (M31 * M44) - (M34 * M41);
			float temp5 = (M31 * M43) - (M33 * M41);
			float temp6 = (M31 * M42) - (M32 * M41);

			return ((((M11 * (((M22 * temp1) - (M23 * temp2)) + (M24 * temp3))) - (M12 * (((M21 * temp1) -
				(M23 * temp4)) + (M24 * temp5)))) + (M13 * (((M21 * temp2) - (M22 * temp4)) + (M24 * temp6)))) -
				(M14 * (((M21 * temp3) - (M22 * temp5)) + (M23 * temp6))));
		}

		///
		/// Negates this matrix.
		///
		void Matrix4::Negate()
		{
			Matrix4::Negate(*this, this);
		}

		///
		/// Negates the given matrix.
		///
		Matrix4 Matrix4::Negate(const Matrix4 &m1)
		{
			Matrix4 temp;
			Matrix4::Negate(m1, &temp);

			return temp;
		}

		///
		/// Negates the given matrix.
		///
		void Matrix4::Negate(const Matrix4 &value, Matrix4 *out)
		{
			out->M11= -value.M11;
			out->M12= -value.M12;
			out->M13= -value.M13;
			out->M14= -value.M14;
			out->M21= -value.M21;
			out->M22= -value.M22;
			out->M23= -value.M23;
			out->M24= -value.M24;
			out->M31= -value.M31;
			out->M32= -value.M32;
			out->M33= -value.M33;
			out->M34= -value.M34;
			out->M41= -value.M41;
			out->M42= -value.M42;
			out->M43= -value.M43;
			out->M44= -value.M44;
		}

		///
		/// Inverts this matrix.
		///
		void Matrix4::Invert()
		{
			Matrix4::Invert(*this, this);
		}

		///
		/// Inverts the given matrix.
		///
		Matrix4 Matrix4::Invert(const Matrix4 &m1)
		{
			Matrix4 temp;
			Matrix4::Invert(m1, &temp);

			return temp;
		}

		///
		/// Inverts the given matrix.
		///
		void Matrix4::Invert(const Matrix4 &value, Matrix4 *out)
		{
			float b0 = (value.M31 * value.M42) - (value.M32 * value.M41);
			float b1 = (value.M31 * value.M43) - (value.M33 * value.M41);
			float b2 = (value.M34 * value.M41) - (value.M31 * value.M44);
			float b3 = (value.M32 * value.M43) - (value.M33 * value.M42);
			float b4 = (value.M34 * value.M42) - (value.M32 * value.M44);
			float b5 = (value.M33 * value.M44) - (value.M34 * value.M43);

			float d11 = value.M22 * b5 + value.M23 * b4 + value.M24 * b3;
			float d12 = value.M21 * b5 + value.M23 * b2 + value.M24 * b1;
			float d13 = value.M21 * -b4 + value.M22 * b2 + value.M24 * b0;
			float d14 = value.M21 * b3 + value.M22 * -b1 + value.M23 * b0;

			float det = value.M11 * d11 - value.M12 * d12 + value.M13 * d13 - value.M14 * d14;
			if (det == 0.0f)
			{
				*out = Matrix4::Zero;
				return;
			}

			det = 1.0f / det;

			float a0 = (value.M11 * value.M22) - (value.M12 * value.M21);
			float a1 = (value.M11 * value.M23) - (value.M13 * value.M21);
			float a2 = (value.M14 * value.M21) - (value.M11 * value.M24);
			float a3 = (value.M12 * value.M23) - (value.M13 * value.M22);
			float a4 = (value.M14 * value.M22) - (value.M12 * value.M24);
			float a5 = (value.M13 * value.M24) - (value.M14 * value.M23);

			float d21 = value.M12 * b5 + value.M13 * b4 + value.M14 * b3;
			float d22 = value.M11 * b5 + value.M13 * b2 + value.M14 * b1;
			float d23 = value.M11 * -b4 + value.M12 * b2 + value.M14 * b0;
			float d24 = value.M11 * b3 + value.M12 * -b1 + value.M13 * b0;

			float d31 = value.M42 * a5 + value.M43 * a4 + value.M44 * a3;
			float d32 = value.M41 * a5 + value.M43 * a2 + value.M44 * a1;
			float d33 = value.M41 * -a4 + value.M42 * a2 + value.M44 * a0;
			float d34 = value.M41 * a3 + value.M42 * -a1 + value.M43 * a0;

			float d41 = value.M32 * a5 + value.M33 * a4 + value.M34 * a3;
			float d42 = value.M31 * a5 + value.M33 * a2 + value.M34 * a1;
			float d43 = value.M31 * -a4 + value.M32 * a2 + value.M34 * a0;
			float d44 = value.M31 * a3 + value.M32 * -a1 + value.M33 * a0;

			out->M11 = +d11 * det; out->M12 = -d21 * det; out->M13 = +d31 * det; out->M14 = -d41 * det;
			out->M21 = -d12 * det; out->M22 = +d22 * det; out->M23 = -d32 * det; out->M24 = +d42 * det;
			out->M31 = +d13 * det; out->M32 = -d23 * det; out->M33 = +d33 * det; out->M34 = -d43 * det;
			out->M41 = -d14 * det; out->M42 = +d24 * det; out->M43 = -d34 * det; out->M44 = +d44 * det;
		}

		///
		/// Transposes this matrix.
		///
		void Matrix4::Transpose()
		{
			Matrix4 temp;
			Matrix4::Transpose(*this, &temp);
			*this = temp;
		}

		///
		/// Transposes the given matrix.
		///
		Matrix4 Matrix4::Transpose(const Matrix4 &m1)
		{
			Matrix4 temp;
			Matrix4::Transpose(m1, &temp);
			return temp;
		}

		///
		/// Transposes the given matrix.
		///
		void Matrix4::Transpose(const Matrix4 &value, Matrix4 *out)
		{
			Matrix4 temp = Matrix4::Zero;
			temp.M11 = value.M11;
			temp.M12 = value.M21;
			temp.M13 = value.M31;
			temp.M14 = value.M41;
			temp.M21 = value.M12;
			temp.M22 = value.M22;
			temp.M23 = value.M32;
			temp.M24 = value.M42;
			temp.M31 = value.M13;
			temp.M32 = value.M23;
			temp.M33 = value.M33;
			temp.M34 = value.M43;
			temp.M41 = value.M14;
			temp.M42 = value.M24;
			temp.M43 = value.M34;
			temp.M44 = value.M44;

			*out = temp;
		}

		///
		/// Adds two matrices together, returning the new matrix.
		///
		Matrix4 Matrix4::Add(const Matrix4 &m1, const Matrix4 &m2)
		{
			Matrix4 temp;
			Matrix4::Add(m1, m2, &temp);

			return temp;
		}

		///
		/// Adds two matrices together, returning the third matrix via pointer.
		///
		void Matrix4::Add(const Matrix4 &left, const Matrix4 &right, Matrix4 *out)
		{
			out->M11 = left.M11 + right.M11;
			out->M12 = left.M12 + right.M12;
			out->M13 = left.M13 + right.M13;
			out->M14 = left.M14 + right.M14;
			out->M21 = left.M21 + right.M21;
			out->M22 = left.M22 + right.M22;
			out->M23 = left.M23 + right.M23;
			out->M24 = left.M24 + right.M24;
			out->M31 = left.M31 + right.M31;
			out->M32 = left.M32 + right.M32;
			out->M33 = left.M33 + right.M33;
			out->M34 = left.M34 + right.M34;
			out->M41 = left.M41 + right.M41;
			out->M42 = left.M42 + right.M42;
			out->M43 = left.M43 + right.M43;
			out->M44 = left.M44 + right.M44;
		}

		///
		/// Subtracts two matrices.
		//
		Matrix4 Matrix4::Subtract(const Matrix4 &m1, const Matrix4 &m2)
		{
			Matrix4 temp;
			Matrix4::Subtract(m1, m2, &temp);
			return temp;
		}

		///
		/// Subtracts two matrices.
		///
		void Matrix4::Subtract(const Matrix4 &left, const Matrix4 &right, Matrix4 *out)
		{
			out->M11 = left.M11 - right.M11;
			out->M12 = left.M12 - right.M12;
			out->M13 = left.M13 - right.M13;
			out->M14 = left.M14 - right.M14;
			out->M21 = left.M21 - right.M21;
			out->M22 = left.M22 - right.M22;
			out->M23 = left.M23 - right.M23;
			out->M24 = left.M24 - right.M24;
			out->M31 = left.M31 - right.M31;
			out->M32 = left.M32 - right.M32;
			out->M33 = left.M33 - right.M33;
			out->M34 = left.M34 - right.M34;
			out->M41 = left.M41 - right.M41;
			out->M42 = left.M42 - right.M42;
			out->M43 = left.M43 - right.M43;
			out->M44 = left.M44 - right.M44;
		}

		///
		/// Multiplies the given matrix by a scalar.
		///
		Matrix4 Matrix4::Multiply(const Matrix4 &m1, tekreal scalar)
		{
			Matrix4 temp;
			Matrix4::Multiply(m1, scalar, &temp);

			return temp;
		}

		///
		/// Multiples the given matrix by a scalar.
		///
		void Matrix4::Multiply(const Matrix4 &left, tekreal scalar, Matrix4 *out)
		{
			out->M11 = left.M11 * scalar;
			out->M12 = left.M12 * scalar;
			out->M13 = left.M13 * scalar;
			out->M14 = left.M14 * scalar;
			out->M21 = left.M21 * scalar;
			out->M22 = left.M22 * scalar;
			out->M23 = left.M23 * scalar;
			out->M24 = left.M24 * scalar;
			out->M31 = left.M31 * scalar;
			out->M32 = left.M32 * scalar;
			out->M33 = left.M33 * scalar;
			out->M34 = left.M34 * scalar;
			out->M41 = left.M41 * scalar;
			out->M42 = left.M42 * scalar;
			out->M43 = left.M43 * scalar;
			out->M44 = left.M44 * scalar;
		}

		///
		/// Multiples the given matrix by another matrix.
		///
		Matrix4 Matrix4::Multiply(const Matrix4 &m1, const Matrix4 &m2)
		{
			Matrix4 temp;
			Matrix4::Multiply(m1, m2, &temp);
			return temp;
		}

		///
		/// Multiplies the give matrix by another matrix.
		///
		void Matrix4::Multiply(const Matrix4 &left, const Matrix4 &right, Matrix4 *out)
		{
			out->M11 = (left.M11 * right.M11) + (left.M12 * right.M21) + (left.M13 * right.M31) + (left.M14 * right.M41);
			out->M12 = (left.M11 * right.M12) + (left.M12 * right.M22) + (left.M13 * right.M32) + (left.M14 * right.M42);
			out->M13 = (left.M11 * right.M13) + (left.M12 * right.M23) + (left.M13 * right.M33) + (left.M14 * right.M43);
			out->M14 = (left.M11 * right.M14) + (left.M12 * right.M24) + (left.M13 * right.M34) + (left.M14 * right.M44);
			out->M21 = (left.M21 * right.M11) + (left.M22 * right.M21) + (left.M23 * right.M31) + (left.M24 * right.M41);
			out->M22 = (left.M21 * right.M12) + (left.M22 * right.M22) + (left.M23 * right.M32) + (left.M24 * right.M42);
			out->M23 = (left.M21 * right.M13) + (left.M22 * right.M23) + (left.M23 * right.M33) + (left.M24 * right.M43);
			out->M24 = (left.M21 * right.M14) + (left.M22 * right.M24) + (left.M23 * right.M34) + (left.M24 * right.M44);
			out->M31 = (left.M31 * right.M11) + (left.M32 * right.M21) + (left.M33 * right.M31) + (left.M34 * right.M41);
			out->M32 = (left.M31 * right.M12) + (left.M32 * right.M22) + (left.M33 * right.M32) + (left.M34 * right.M42);
			out->M33 = (left.M31 * right.M13) + (left.M32 * right.M23) + (left.M33 * right.M33) + (left.M34 * right.M43);
			out->M34 = (left.M31 * right.M14) + (left.M32 * right.M24) + (left.M33 * right.M34) + (left.M34 * right.M44);
			out->M41 = (left.M41 * right.M11) + (left.M42 * right.M21) + (left.M43 * right.M31) + (left.M44 * right.M41);
			out->M42 = (left.M41 * right.M12) + (left.M42 * right.M22) + (left.M43 * right.M32) + (left.M44 * right.M42);
			out->M43 = (left.M41 * right.M13) + (left.M42 * right.M23) + (left.M43 * right.M33) + (left.M44 * right.M43);
			out->M44 = (left.M41 * right.M14) + (left.M42 * right.M24) + (left.M43 * right.M34) + (left.M44 * right.M44);
		}

		///
		/// Creates a matrix that rotates about the X-axis.
		///
		Matrix4 Matrix4::CreateRotationX(tekreal angle)
		{
			Matrix4 temp;
			Matrix4::CreateRotationX(angle, &temp);

			return temp;
		}

		///
		/// Creates a matrix that rotates about the X-axis.
		///
		void Matrix4::CreateRotationX(tekreal angle, Matrix4 *out)
		{
			float tcos = (float)cos(angle);
			float tsin = (float)sin(angle);

			*out = Matrix4::Identity;
			out->M22 = tcos;
			out->M23 = tsin;
			out->M32 = -tsin;
			out->M33 = tcos;
		}

		///
		/// Creates a matrix that rotates about the Y-axis.
		///
		Matrix4 Matrix4::CreateRotationY(tekreal angle)
		{
			Matrix4 temp;
			Matrix4::CreateRotationY(angle, &temp);

			return temp;
		}

		///
		/// Creates a matrix that rotates about the Y-axis.
		///
		void Matrix4::CreateRotationY(tekreal angle, Matrix4 *out)
		{
			float tcos = (float)cos(angle);
			float tsin = (float)sin(angle);

			*out = Matrix4::Identity;
			out->M11 = tcos;
			out->M13 = -tsin;
			out->M31 = tsin;
			out->M33 = tcos;
		}

		///
		/// Creates a matrix that rotates about the Z-axis.
		///
		Matrix4 Matrix4::CreateRotationZ(tekreal angle)
		{
			Matrix4 temp;
			Matrix4::CreateRotationZ(angle, &temp);
			
			return temp;
		}

		///
		/// Creates a matrix that rotates about the Z-axis.
		///
		void Matrix4::CreateRotationZ(tekreal angle, Matrix4 *out)
		{
			float tcos = (float)cos(angle);
			float tsin = (float)sin(angle);

			*out = Matrix4::Identity;
			out->M11 = tcos;
			out->M12 = tsin;
			out->M21 = -tsin;
			out->M22 = tcos;
		}

		///
		/// Creates a rotation matrix that rotates about all 3 axes.
		///
		Matrix4 Matrix4::CreateRotation(const Vector3 &yawPitchRoll)
		{
			Matrix4 temp;
			Matrix4::CreateRotation(yawPitchRoll, &temp);
			return temp;
		}

		///
		/// Creates a rotation matrix that rotates about all 3 axes.
		///
		void Matrix4::CreateRotation(const Vector3 &r, Matrix4 *out)
		{
			*out = (Matrix4::CreateRotationX(r.X) * Matrix4::CreateRotationY(r.Y) * Matrix4::CreateRotationZ(r.Z));
		}

		///
		/// Creates a scale matrix that scales about all 3 axes.
		///
		Matrix4 Matrix4::CreateScale(const Vector3 &scale)
		{
			Matrix4 temp;
			Matrix4::CreateScale(scale, &temp);
			return temp;
		}

		///
		/// Creates a scale matrix that scales about all 3 axes.
		///
		void Matrix4::CreateScale(const Vector3 &scale, Matrix4 *out)
		{
			*out = Matrix4::Identity;
			out->M11 = scale.X;
			out->M22 = scale.Y;
			out->M33 = scale.Z;
		}

		///
		/// Creates a translation matrix.
		///
		Matrix4 Matrix4::CreateTranslation(const Vector3 &translation)
		{
			Matrix4 temp;
			Matrix4::CreateTranslation(translation, &temp);
			return temp;
		}

		///
		/// Creates a translation matrix.
		///
		void Matrix4::CreateTranslation(const Vector3 &translation, Matrix4 *out)
		{
			*out = Matrix4::Identity;
			out->M41 = translation.X;
			out->M42 = translation.Y;
			out->M43 = translation.Z;
		}

		///
		/// Creates an off-centered left-handed orthographic projection matrix.
		///
		Matrix4 Matrix4::CreateOffCenterOrthoLH(tekreal left, tekreal right, tekreal bottom,
			tekreal top, tekreal znear, tekreal zfar)
		{
			Matrix4 temp;
			Matrix4::CreateOffCenterOrthoLH(left, right, bottom, top, znear, zfar, &temp);
			return temp;
		}

		///
		/// Creates an off-centered left-handed orthographic projection matrix.
		///
		void Matrix4::CreateOffCenterOrthoLH(tekreal left, tekreal right, tekreal bottom,
			tekreal top, tekreal znear, tekreal zfar, Matrix4 *out)
		{
			float zRange = 1.0f / (zfar - znear);

			*out = Matrix4::Identity;
			out->M11 = 2.0f / (right - left);
			out->M22 = 2.0f / (top - bottom);
			out->M33 = zRange;
			out->M41 = (left + right) / (left - right);
			out->M42 = (top + bottom) / (bottom - top);
			out->M43 = -znear * zRange;
		}
	}
}