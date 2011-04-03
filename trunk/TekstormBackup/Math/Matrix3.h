#ifndef _MATRIX3_H
#define _MATRIX3_H
#include "Vector2.h"

namespace Tekstorm
{
	namespace Math
	{
		class TEKAPI Matrix3
		{
		public:
			float m[3][3];

		public:
			Matrix3();
			Matrix3(float scalar);
			Matrix3(float m11, float m12, float m13,
				float m21, float m22, float m23,
				float m31, float m32, float m33);
			Matrix3(const float[][3] arr);
			Matrix3(const Matrix3& other);

			Matrix3 operator+(const Matrix3& other);
			Matrix3 operator-(const Matrix3& other);
			Matrix3 operator-();
			Matrix3 operator*(const Matrix3& other);
			Matrix3 operator/(const Matrix3& other);

			Matrix3& operator+=(const Matrix3& other);
			Matrix3& operator-=(const Matrix3& other);
			Matrix3& operator*=(const Matrix3& other);
			Matrix3& operator/=(const Matrix3& other);
		};
	}
}

#endif /* _MATRIX3_H */