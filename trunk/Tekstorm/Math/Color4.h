#ifndef _TEKSTORM_COLOR4_H
#define _TEKSTORM_COLOR4_H
#include "../Core/TekDecl.h"

namespace Tekstorm
{
	namespace Math
	{
		class TEKAPI Color4
		{
		public:
			float A, R, G, B;

			Color4(float scalar = 0.0f);
			Color4(float a, float r, float g, float b);
			Color4(float r, float g, float b);
			Color4(const Color4& other);
			~Color4();

			Color4 operator+(const Color4 &other);
			Color4& operator+=(const Color4 &other);
			Color4 operator-();
			Color4 operator-(const Color4 &other);
			Color4& operator-=(const Color4 &other);
			Color4 operator*(const Color4 &other);
			Color4& operator*=(const Color4 &other);

			// converts this number to a 32-bit DWORD value
			// in AARRGGBB format.
			DWORD GetARGB() const;
		};
	}
}

#endif /* _TEKSTORM_COLOR4_H */