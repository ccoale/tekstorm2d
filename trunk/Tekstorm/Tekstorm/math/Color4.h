#ifndef _TEKSTORM_COLOR4_H
#define _TEKSTORM_COLOR4_H
#include "../TekstormDecl.h"

namespace Tekstorm
{
	namespace Math
	{
		// Represents an RGBA color.
		class TEKDECL Color4
		{
		public:
			// The components of this color (value is between 0.0 and 1.0)
			float R, G, B, A;

			// Initializes a new instance of Color4, sets all components to 0.0
			Color4();

			// Initializes a new instance of Color4 given each component.
			Color4(float r, float g, float b, float a = 1.0f);

			// Initializes a new instance of Color4 given a 32-bit color value in the format AARRGGBB.
			Color4(DWORD color);

			// Scalar value that is assigned to each component of the color.
			Color4(float scalar);

			// De-initializes this instance of Color4.
			~Color4();

			// Adds this Color4 and another, yielding a new Color4.
			Color4 operator+(const Color4& other);

			// Subtracts another Color4 from this Color4, yielding a new Color4.
			Color4 operator-(const Color4& other);

			// Modulates this Color4 with another, yielding a new color.
			Color4 operator*(const Color4& other);

			// Adds another Color4 to this color.
			Color4& operator+=(const Color4& other);

			// Subtracts another Color4 from this Color4.
			Color4& operator-=(const Color4& other);

			// Modulates this Color4 with another.
			Color4& operator*=(const Color4& other);

			// Returns the inverse of this color.
			Color4 operator-();
		};
	}
}

#endif /* _TEKSTORM_COLOR4_H */