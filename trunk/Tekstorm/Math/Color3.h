#pragma once
#ifndef _TEKSTORM_COLOR3_H
#define _TEKSTORM_COLOR3_H
#include "../BuildConf.h"
#include "Vector3.h"

namespace Tekstorm
{
	namespace Math
	{
		class TEKAPI Color3
		{
		public:
			/*
			**	A value between 0 and 1 which represents the red component
			** of this color. 
			*/
			real Red;

			/*
			**	A value between 0 and 1 which represents the green component
			** of this color.
			*/
			real Green;

			/*
			**	A value between 0 and 1 which represents the blue component
			** of this color.
			*/
			real Blue;

			/*
			** Initializes a new instance of Color3.
			** Parameters
			**	value		- a scalar value to set red, green and blue to.
			** Returns
			**	nothing
			*/
			Color3(real value);

			/*
			** Initializes a new instance of Color3.
			** Parameters
			**	r		- the value to set Red to
			**	g		- the value to set Green to
			**	b		- the value to set Blue to
			** Returns
			**	nothing
			*/
			Color3(real r, real g, real b);

			/*
			** Initializes a new instance of Color3.
			** Parameters
			**	value		- a Vector3 containing the values for the color components
			**				- X is Red, Y is Green, Z is blue.
			** Returns
			**	nothing
			*/
			Color3(const Vector3& value);

			/*
			** Initializes a new instance of this Color3.
			** Parameters
			**	argb		- a packed integer storing the color components.
			**				- RR is the high byte.
			** Returns
			**	nothing
			*/
			Color3(int rgb);

			/*
			** Initializes a new instance of this Color3.
			** Parameters
			**	arr			- A 3-element array used to assign the color components of this color.
			**				- arr[0] = Red, arr[1] = Green, arr[2] = Blue
			** Returns
			**	nothing
			*/
			Color3(const real arr[]);

			/*
			** Converts this color to a packed integer.
			** Parameters
			**	none
			** Returns
			**	an integer containing the color components of this color.
			*/
			int GetRgb() const;

			/*
			** Adds two colors
			** Parameters
			**	left		- The first color to add.
			**	right		- The second color to add.
			**	result		- The sum of the two colors.
			** Returns
			**	nothing
			*/
			static void Add(const Color3 &left, const Color3 &right, Color3 &result);

			/*
			** Adds two colors.
			** Parameters
			**	left		- the first color to add
			**	right		- the second color to add
			** Returns
			**	the sum of the two colors
			*/
			static Color3 Add(const Color3 &left, const Color3 &right);

			/*
			** Subtracts two colors.
			** Parameters
			**	left		- The first color to subtract
			**	right		- the second color to subtract
			**	result		- the difference between the two colors
			** Returns
			**	nothing
			*/
			static void Subtract(const Color3 &left, const Color3 &right, Color3 &result);

			/*
			** Subtracts two colors.
			** Parameters
			**	left		- The first color to subtract
			**	right		- the second color to subtract
			** Returns
			**	the difference between the two colors.
			*/
			static Color3 Subtract(const Color3 &left, const Color3 &right);

			/*
			** Modulates two colors.
			** Parameters
			**	left		- the first color to modulate
			**	right		- the second color to modulate
			**	result		- the result of the modulation
			** Returns
			**	nothing
			*/
			static void Modulate(const Color3 &left, const Color3 &right, Color3 &result);

			/*
			** Modulates two colors.
			** Parameters
			**	left		- the first color to modulate
			**	right		- the second color to modulate
			** Returns
			**	the modulated color.
			*/
			static Color3 Modulate(const Color3 &left, const Color3 &right);

			/*
			** Scales a color.
			** Parameters
			**	left		- the first color to scale
			**	scale		- the scaling factor
			**	result		- the scaled color
			** Returns
			**	nothing
			*/
			static void Scale(const Color3 &left, real scale, Color3 &result);

			/*
			** Scales a color.
			** Parameters
			**	left		- the first color to scale
			**	scale		- the scaling factor
			** Returns
			**	the scaled color.
			*/
			static Color3 Scale(const Color3 &left, real scale);

			/*
			** Negates a color.
			** Parameters
			**	value		- the value to negate
			**	result		- the negated value
			** Returns
			**	nothing
			*/
			static void Negate(const Color3 &value, Color3 &result);

			/*
			** Negates a color.
			** Parameters
			**	value		- the value to negate
			** Returns
			**	the negated color
			*/
			static Color3 Negate(const Color3 &value);

			/*
			** Clamps a color within a specific range.
			** Parameters
			**	value		- the value to clamp
			**	min			- the minimum value
			**	max			- the maximum value
			**	result		- the restricted color
			** Returns
			**	nothing
			*/
			static void Clamp(const Color3 &value, const Color3 &min, const Color3 &max, Color3 &result);

			/*
			** Clamps a color within a specific range.
			** Parameters
			**	value		- the value to clamp
			**	min			- the minimum value
			**	max			- the maximum value
			** Returns
			**	the restricted color.
			*/
			static Color3 Clamp(const Color3 &value, const Color3 &min, const Color3 &max);

			/*
			** Performs linear interpolation between two colors.
			** Parameters
			**	start		- the starting color
			**	end			- the ending color
			**	amount		- value between 0 and 1 indiciating the weight of end
			**	result		- the resulting color
			** Returns
			**	nothing
			*/
			static void Lerp(const Color3 &start, const Color3 &end, real amount, Color3 &result);

			/*
			** Performs linear interpolation between two colors.
			** Parameters
			**	start		- the starting color
			**	end			- the ending color
			**	amount		- value between 0 and 1 indiciating the weight of end
			** Returns
			**	the resulting color.
			*/
			static Color3 Lerp(const Color3 &start, const Color3 &end, real amount);

			/*
			** Performs cubic interpolation between two colors.
			** Parameters
			**	start		- the starting color
			**	end			- the ending color
			**	amount		- value between 0 and 1 indiciating weight of end
			**	result		- the resulting color
			** Returns
			**	nothing
			*/
			static void SmoothStep(const Color3 &start, const Color3 &end, real amount, Color3 &result);

			/*
			** Performs cubic interpolation between two colors.
			** Parameters
			**	start		- the starting color
			**	end			- the ending color
			**	amount		- value between 0 and 1 indiciating weight of end
			** Returns
			**	the resulting color.
			*/
			static Color3 SmoothStep(const Color3 &start, const Color3 &end, real amount);

			/*
			** Returns a color containing the smallest components of the specified colors.
			** Parameters
			**	left		- the first source color
			**	right		- the second source color
			**	result		- the resulting color
			** Returns
			**	nothing
			*/
			static void Min(const Color3 &left, const Color3 &right, Color3 &result);

			/*
			** Returns a color containing the smallest components of the specified colors.
			** Parameters
			**	left		- the first source color
			**	right		- the second source color
			** Returns
			**	the resulting color.
			*/
			static Color3 Min(const Color3 &left, const Color3 &right);

			/*
			** Returns a color containing the largest components of the specified colors.
			** Parameters
			**	left		- the first source color
			**	right		- the second source color
			**	result		- the resulting color
			** Returns
			**	nothing
			*/
			static void Max(const Color3 &left, const Color3 &right, Color3 &result);

			/*
			** Returns a color containing the largest components of the specified colors.
			** Parameters
			**	left		- the first source color
			**	right		- the second source color
			** Returns
			**	the resulting color.
			*/
			static Color3 Max(const Color3 &left, const Color3 &right);

			/*
			** Adjusts the contrast of a color.
			** Parameters
			**	value		- the color to adjust the contrast of
			**	amount		- a value between 0 and 1 indicating the amount to adjust the contrast by
			**	result		- the resulting color
			** Returns
			**	nothing
			*/
			static void AdjustContrast(const Color3 &value, real amount, Color3 &result);

			/*
			** Adjusts the contrast of a color.
			** Parameters
			**	value		- the color to adjust the contrast of
			**	amount		- a value between 0 and 1 indicating the amount to adjust the contrast by
			** Returns
			**	the resulting color.
			*/
			static Color3 AdjustContrast(const Color3 &value, real amount);

			/*
			** Adjusts the saturation of a color.
			** Parameters
			**	value		- the color to adjust
			**	saturation	- the amount by which to adjust the saturation
			**	result		- the resulting color
			** Returns
			**	nothing
			*/
			static void AdjustSaturation(const Color3 &value, real saturation, Color3 &result);

			/*
			** Adjusts the saturation of a color.
			** Parameters
			**	value		- the color to adjust
			**	saturation	- the amount by which to adjust the saturation
			** Returns
			**	the resulting color.
			*/
			static Color3 AdjustSaturation(const Color3 &value, real saturation);

			/*
			** Adds two colors.
			**/
			Color3 operator+(const Color3 &other);

			/*
			** Adds a color to this color.
			*/
			Color3& operator+=(const Color3 &other);

			/*
			** Subtracts two colors.
			*/
			Color3 operator-(const Color3 &other);

			/*
			** Subtracts a color from this color.
			*/
			Color3& operator-=(const Color3 &other);

			/*
			** Negates this color
			*/
			Color3 operator-();

			/*
			** Scales a color
			*/
			Color3 operator*(real scale);

			/*
			** Scales this color
			*/
			Color3 &operator*=(real scale);

			/*
			** Tests for equality
			*/
			bool operator==(const Color3 &other);

			/*
			** Tests for inequality
			*/
			bool operator!=(const Color3 &other);
		};
	}
}

#endif /* _TEKSTORM_Color3_H */