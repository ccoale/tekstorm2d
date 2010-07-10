#define __BUILD
#include "Color4.h"

namespace Tekstorm
{
	namespace Math
	{
		// Initializes a new instance of Color4, sets all components to 0.0
		TEKDECL Color4::Color4()
		{
			A = R = G = B = 0.0f;
		}

		// Initializes a new instance of Color4 given each component.
		TEKDECL Color4::Color4(float r, float g, float b, float a)
		{
			A = a;
			R = r;
			G = g;
			B = b;
		}

		// Initializes a new instance of Color4 given a 32-bit color value in the format AARRGGBB.
		TEKDECL Color4::Color4(DWORD color)
		{
			ubyte_t b = (ubyte_t)(color & 0x000000FF);
			ubyte_t g = (ubyte_t)(color & 0x0000FF00);
			ubyte_t r = (ubyte_t)(color & 0x00FF0000);
			ubyte_t a = (ubyte_t)(color & 0xFF000000);

			B = b / 255.0f;
			G = g / 255.0f;
			R = r / 255.0f;
			A = a / 255.0f;
		}

		// Scalar value that is assigned to each component of the color.
		TEKDECL Color4::Color4(float scalar)
		{
			A = R = G = B = scalar;
		}

		// De-initializes this instance of Color4.
		TEKDECL Color4::~Color4()
		{
		}

		// Adds this Color4 and another, yielding a new Color4.
		TEKDECL Color4 Color4::operator+(const Color4& other)
		{
			return Color4(R + other.R, G + other.G, B + other.B, A + other.A);
		}

		// Subtracts another Color4 from this Color4, yielding a new Color4.
		TEKDECL Color4 Color4::operator-(const Color4& other)
		{
			return Color4(R - other.R, G - other.G, B - other.B, A - other.A);
		}

		// Modulates this Color4 with another, yielding a new color.
		TEKDECL Color4 Color4::operator*(const Color4& other)
		{
			return Color4(R * other.R, G * other.G, B * other.B, A * other.A);
		}

		// Adds another Color4 to this color.
		TEKDECL Color4& Color4::operator+=(const Color4& other)
		{
			R += other.R;
			G += other.G;
			B += other.B;
			A += other.A;

			return *this;
		}

		// Subtracts another Color4 from this Color4.
		TEKDECL Color4& Color4::operator-=(const Color4& other)
		{
			R -= other.R;
			G -= other.G;
			B -= other.B;
			A -= other.A;

			return *this;
		}

		// Modulates this Color4 with another.
		TEKDECL Color4& Color4::operator*=(const Color4& other)
		{
			R *= other.R;
			G *= other.G;
			B *= other.B;
			A *= other.A;

			return *this;
		}

		// Returns the inverse of this color.
		TEKDECL Color4 Color4::operator-()
		{
			return Color4(1.0f - R, 1.0f - G, 1.0f - B, 1.0f - A);
		}
	}
}