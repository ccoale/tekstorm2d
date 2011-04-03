#define TEKBUILD
#include "Color4.h"

namespace Tekstorm
{
	namespace Math
	{
		Color4::Color4(float scalar)
		{
			A = R = G = B = scalar;
		}

		Color4::Color4(float a, float r, float g, float b)
		{
			A = a;
			R = r;
			G = g;
			B = b;
		}

		Color4::Color4(float r, float g, float b)
		{
			A = 1.0f;
			R = r;
			G = g;
			B = b;
		}

		Color4::Color4(const Color4& other)
		{
			A = other.A;
			R = other.R;
			G = other.G;
			B = other.B;
		}

		Color4::~Color4()
		{
		}

		Color4 Color4::operator+(const Color4 &other)
		{
			return Color4(A + other.A, R + other.R, G + other.G, B + other.B);
		}

		Color4& Color4::operator+=(const Color4 &other)
		{
			A += other.A;
			R += other.R;
			G += other.G;
			B += other.B;

			return *this;
		}

		Color4 Color4::operator-()
		{
			return Color4(1.0f - A, 1.0f - R, 1.0f - G, 1.0f - B);
		}

		Color4 Color4::operator-(const Color4 &other)
		{
			return Color4(A - other.A, R - other.R, G - other.G, B - other.B);
		}

		Color4& Color4::operator-=(const Color4 &other)
		{
			A -= other.A;
			R -= other.R;
			G -= other.G;
			B -= other.B;

			return *this;
		}

		Color4 Color4::operator*(const Color4 &other)
		{
			return Color4(A * other.A, R * other.R, G * other.G, B * other.B);
		}

		Color4& Color4::operator*=(const Color4 &other)
		{
			A *= other.A;
			R *= other.R;
			G *= other.G;
			B *= other.B;
			
			return *this;
		}

		// converts this number to a 32-bit DWORD value
		// in AARRGGBB format.
		DWORD Color4::GetARGB() const
		{
			unsigned int a = (unsigned int)A * 255.0f;
			unsigned int r = (unsigned int)R * 255.0f;
			unsigned int g = (unsigned int)G * 255.0f;
			unsigned int b = (unsigned int)B * 255.0f;

			return ( (a & 0xFF) << 24 ) | ( (r & 0xFF) << 16) | ( (g & 0xFF) << 8 ) | (b & 0xFF);
		}
	}
}