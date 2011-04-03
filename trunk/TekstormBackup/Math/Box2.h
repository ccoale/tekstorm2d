#ifndef _BOX2_H
#define _BOX2_H
#include "Vector2.h"

namespace Tekstorm
{
	namespace Math
	{
		class TEKAPI Box2
		{
		public:
			Vector2 Position;
			Vector2 Size;

		public:
			Box2();
			Box2(const float scalar);
			Box2(const float x, const float y, const float w, const float h);
			Box2(const Vector2& pos, const Vector2& size);
			Box2(const float[] arr);
			Box2(const Vector2[] arr);
			Box2(const Box2& other);

			Box2 operator+(const Box2& other);
			Box2 operator-(const Box2& other);
			Box2 operator-();
			Box2 operator*(const Box2& other);
			Box2 operator/(const Box2& other);

			Box2& operator+=(const Box2& other);
			Box2& operator-=(const Box2& other);
			Box2& operator*=(const Box2& other);
			Box2& operator/(const Box2& other);
		};
	}
}

#endif /* _BOX2_H */