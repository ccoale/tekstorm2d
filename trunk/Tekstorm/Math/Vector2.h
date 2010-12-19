#ifndef _VECTOR2_H
#define _VECTOR2_H
#include "../TekDecl.h"

namespace Tekstorm
{
	namespace Math
	{
		class TEKAPI Vector2
		{
		public:
			float X, Y;

		public:
			Vector2();
			Vector2(const float scalar);
			Vector2(const float x, const float y);
			Vector2(const float[] arr);
			Vector2(const Vector2& other);

			Vector2 operator+(const Vector2& other);
			Vector2 operator-(const Vector2& other);
			Vector2 operator-();
			Vector2 operator*(const Vector2& other);
			Vector2 operator/(const Vector2& other);
			
			Vector2& operator+=(const Vector2& other);
			Vector2& operator-=(const Vector2& other);
			Vector2& operator*=(const Vector2& other);
			Vector2& operator/=(const Vector2& other);
		};
	}
}

#endif /* _VECTOR2_H */