#pragma once
#ifndef _TEKSTORM_COLOR4_H
#define _TEKSTORM_COLOR4_H
#include "../BuildConf.h"
#include "Vector4.h"

namespace Tekstorm
{
	namespace Math
	{
		class Color4
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
			**	A value between 0 and 1 which represents the alpha component
			** of this color.
			*/
			real Alpha;

			/*
			** Initializes a new instance of Color4.
			** Parameters
			**	value		- a scalar value to set alpha, red, green and blue to.
			** Returns
			**	nothing
			*/
			Color4(real value)
			{
				Alpha = Red = Green = Blue = value;
			}

			/*
			** Initializes a new instance of Color4.
			** Parameters
			**	a		- the value to set Alpha to
			**	r		- the value to set Red to
			**	g		- the value to set Green to
			**	b		- the value to set Blue to
			** Returns
			**	nothing
			*/
			Color4(real a, real r, real g, real b)
			{
				Alpha = a;
				Red = r;
				Green = g;
				Blue = b;
			}

			/*
			** Initializes a new instance of Color4.
			** Parameters
			**	value		- a Vector4 containing the values for the color components
			**				- X is Alpha, Y is Red, Z is Green, W is blue.
			** Returns
			**	nothing
			*/
			Color4(const Vector4& value)
			{
				Alpha = value.X;
				Red = value.Y;
				Green = value.Z;
				Blue = value.W;
			}

			/*
			** Initializes a new instance of Color4.
			** Parameters
			**	value		- a Vector3 containg the values for the Red, Green, and Blue color components.
			**				- X is Red, Y is Green, and Z is Blue.
			**	a			- the Alpha of this color
			** Returns
			**	nothing
			*/
			Color4(const Vector3& value, real a)
			{
				Red = value.X;
				Green = value.Y;
				Blue = value.Z;
				Alpha = a;
			}

			/*
			** Initializes a new instance of this Color4.
			** Parameters
			**	argb		- a packed integer storing the color components.
			**				- AA is the high byte.
			**				- BB is the low byte.
			** Returns
			**	nothing
			*/
			Color4(int argb)
			{
				Alpha = ((argb >> 24) & 0xFF) / (real)255;
				Red = ((argb >> 16) & 0xFF) / (real)255;
				Green = ((argb >> 8) & 0xFF) / (real)255;
				Blue = ((argb & 0xFF)) / (real)255;
			}

			/*
			** Initializes a new instance of this Color4.
			** Parameters
			**	arr			- A 4-element array used to assign the color components of this color.
			**				- arr[0] = Alpha, arr[1] = Red, arr[2] = Green, arr[3] = Blue.
			** Returns
			**	nothing
			*/
			Color4(const real arr[])
			{
				Alpha = arr[0];
				Red = arr[1];
				Green = arr[2];
				Blue = arr[3];
			}

			/*
			** Converts this color to a packed integer.
			** Parameters
			**	none
			** Returns
			**	an integer containing the color components of this color.
			*/
			int GetArgb() const
			{
				unsigned int a = ((unsigned int)(Alpha * (real)255) & 0xFF);
				unsigned int r = ((unsigned int)(Red * (real)255) & 0xFF);
				unsigned int g = ((unsigned int)(Green * (real)255) & 0xFF);
				unsigned int b = ((unsigned int)(Blue * (real)255) & 0xFF);

				unsigned int value = b | (g << 8) | (r << 16) | (a << 24);

				return (int)value;
			}

			/*
			** Adds two colors
			** Parameters
			**	left		- The first color to add.
			**	right		- The second color to add.
			**	result		- The sum of the two colors.
			** Returns
			**	nothing
			*/
			static void Add(const Color4 &left, const Color4 &right, Color4 &result)
			{
				result.Alpha = left.Alpha + right.Alpha;
				result.Red = left.Red + right.Red;
				result.Green = left.Green + right.Green;
				result.Blue = left.Blue + right.Blue;
			}

			/*
			** Adds two colors.
			** Parameters
			**	left		- the first color to add
			**	right		- the second color to add
			** Returns
			**	the sum of the two colors
			*/
			static Color4 Add(const Color4 &left, const Color4 &right)
			{
				return Color4(left.Alpha + right.Alpha,
					left.Red + right.Red,
					left.Green + right.Green,
					left.Blue + right.Blue);
			}

			/*
			** Subtracts two colors.
			** Parameters
			**	left		- The first color to subtract
			**	right		- the second color to subtract
			**	result		- the difference between the two colors
			** Returns
			**	nothing
			*/
			static void Subtract(const Color4 &left, const Color4 &right, Color4 &result)
			{
				result.Alpha = left.Alpha - right.Alpha;
				result.Red = left.Red - right.Red;
				result.Green = left.Green - right.Green;
				result.Blue = left.Blue - right.Blue;
			}

			/*
			** Subtracts two colors.
			** Parameters
			**	left		- The first color to subtract
			**	right		- the second color to subtract
			** Returns
			**	the difference between the two colors.
			*/
			static Color4 Subtract(const Color4 &left, const Color4 &right)
			{
				return Color4(left.Alpha - right.Alpha,
					left.Red - right.Red,
					left.Green - right.Green,
					left.Blue - right.Blue);
			}

			/*
			** Modulates two colors.
			** Parameters
			**	left		- the first color to modulate
			**	right		- the second color to modulate
			**	result		- the result of the modulation
			** Returns
			**	nothing
			*/
			static void Modulate(const Color4 &left, const Color4 &right, Color4 &result)
			{
				result.Alpha = left.Alpha * right.Alpha;
				result.Red = left.Red * right.Red;
				result.Green = left.Green * right.Green;
				result.Blue = left.Blue * right.Blue;
			}

			/*
			** Modulates two colors.
			** Parameters
			**	left		- the first color to modulate
			**	right		- the second color to modulate
			** Returns
			**	the modulated color.
			*/
			static Color4 Modulate(const Color4 &left, const Color4 &right)
			{
				return Color4(left.Alpha * right.Alpha,
					left.Red * right.Red,
					left.Green * right.Green,
					left.Blue * right.Blue);
			}

			/*
			** Scales a color.
			** Parameters
			**	left		- the first color to scale
			**	scale		- the scaling factor
			**	result		- the scaled color
			** Returns
			**	nothing
			*/
			static void Scale(const Color4 &left, real scale, Color4 &result)
			{
				result.Alpha = left.Alpha * scale;
				result.Red = left.Red * scale;
				result.Green = left.Green * scale;
				result.Blue = left.Blue * scale;
			}

			/*
			** Scales a color.
			** Parameters
			**	left		- the first color to scale
			**	scale		- the scaling factor
			** Returns
			**	the scaled color.
			*/
			static Color4 Scale(const Color4 &left, real scale)
			{
				return Color4(left.Alpha * scale,
					left.Red * scale,
					left.Green * scale,
					left.Blue * scale);
			}

			/*
			** Negates a color.
			** Parameters
			**	value		- the value to negate
			**	result		- the negated value
			** Returns
			**	nothing
			*/
			static void Negate(const Color4 &value, Color4 &result)
			{
				result.Alpha = (real)1.0 - value.Alpha;
				result.Red = (real)1.0 - value.Red;
				result.Green = (real)1.0 - value.Green;
				result.Blue = (real)1.0 - value.Blue;
			}

			/*
			** Negates a color.
			** Parameters
			**	value		- the value to negate
			** Returns
			**	the negated color
			*/
			static Color4 Negate(const Color4 &value)
			{
				return Color4((real)1.0 - value.Alpha,
					(real)1.0 - value.Red,
					(real)1.0 - value.Green,
					(real)1.0 - value.Blue);
			}

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
			static void Clamp(const Color4 &value, const Color4 &min, const Color4 &max, Color4 &result)
			{
				real alpha = value.Alpha;
				alpha = (alpha > max.Alpha) ? max.Alpha : alpha;
				alpha = (alpha < min.Alpha) ? min.Alpha : alpha;

				real red = value.Red;
				red = (red > max.Red) ? max.Red : red;
				red = (red < min.Red) ? min.Red : red;

				real green = value.Green;
				green = (green > max.Green) ? max.Green : green;
				green = (green < min.Green) ? min.Green : green;

				real blue = value.Blue;
				blue = (blue > max.Blue) ? max.Blue : blue;
				blue = (blue < min.Blue) ? min.Blue : blue;

				result.Alpha = alpha;
				result.Red = red;
				result.Green = green;
				result.Blue = blue;
			}

			/*
			** Clamps a color within a specific range.
			** Parameters
			**	value		- the value to clamp
			**	min			- the minimum value
			**	max			- the maximum value
			** Returns
			**	the restricted color.
			*/
			static Color4 Clamp(const Color4 &value, const Color4 &min, const Color4 &max)
			{
				real alpha = value.Alpha;
				alpha = (alpha > max.Alpha) ? max.Alpha : alpha;
				alpha = (alpha < min.Alpha) ? min.Alpha : alpha;

				real red = value.Red;
				red = (red > max.Red) ? max.Red : red;
				red = (red < min.Red) ? min.Red : red;

				real green = value.Green;
				green = (green > max.Green) ? max.Green : green;
				green = (green < min.Green) ? min.Green : green;

				real blue = value.Blue;
				blue = (blue > max.Blue) ? max.Blue : blue;
				blue = (blue < min.Blue) ? min.Blue : blue;

				return Color4(alpha, red, green, blue);
			}

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
			static void Lerp(const Color4 &start, const Color4 &end, real amount, Color4 &result)
			{
				result.Alpha = start.Alpha + amount * (end.Alpha - start.Alpha);
				result.Red = start.Red + amount * (end.Red - start.Red);
				result.Green = start.Green + amount * (end.Green - start.Green);
				result.Blue = start.Blue + amount * (end.Blue - start.Blue);
			}

			/*
			** Performs linear interpolation between two colors.
			** Parameters
			**	start		- the starting color
			**	end			- the ending color
			**	amount		- value between 0 and 1 indiciating the weight of end
			** Returns
			**	the resulting color.
			*/
			static Color4 Lerp(const Color4 &start, const Color4 &end, real amount)
			{
				return Color4(start.Alpha + amount * (end.Alpha - start.Alpha),
					start.Red + amount * (end.Red - start.Red),
					start.Green + amount * (end.Green - start.Green),
					start.Blue + amount * (end.Blue - start.Blue));
			}

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
			static void SmoothStep(const Color4 &start, const Color4 &end, real amount, Color4 &result)
			{
				amount = (amount > (real)1.0) ? (real)1.0 : ((amount < (real)0.0) ? (real)0.0 : amount);
				amount = (amount * amount) * ((real)3.0 - ((real)2.0 * amount));

				result.Alpha = start.Alpha + ((end.Alpha - start.Alpha) * amount);
				result.Red = start.Red + ((end.Red - start.Red) * amount);
				result.Green = start.Green + ((end.Green - start.Green) * amount);
				result.Blue = start.Blue + ((end.Blue - start.Blue) * amount);
			}

			/*
			** Performs cubic interpolation between two colors.
			** Parameters
			**	start		- the starting color
			**	end			- the ending color
			**	amount		- value between 0 and 1 indiciating weight of end
			** Returns
			**	the resulting color.
			*/
			static Color4 SmoothStep(const Color4 &start, const Color4 &end, real amount)
			{
				amount = (amount > (real)1.0) ? (real)1.0 : ((amount < (real)0.0) ? (real)0.0 : amount);
				amount = (amount * amount) * ((real)3.0 - ((real)2.0 * amount));

				return Color4(
					start.Alpha + ((end.Alpha - start.Alpha) * amount),
					start.Red + ((end.Red - start.Red) * amount),
					start.Green + ((end.Green - start.Green) * amount),
					start.Blue + ((end.Blue - start.Blue) * amount));
			}

			/*
			** Returns a color containing the smallest components of the specified colors.
			** Parameters
			**	left		- the first source color
			**	right		- the second source color
			**	result		- the resulting color
			** Returns
			**	nothing
			*/
			static void Min(const Color4 &left, const Color4 &right, Color4 &result)
			{
				result.Alpha = (left.Alpha < right.Alpha) ? left.Alpha : right.Alpha;
				result.Red = (left.Red < right.Red) ? left.Red : right.Red;
				result.Green = (left.Green < right.Green) ? left.Green : right.Green;
				result.Blue = (left.Blue < right.Blue) ? left.Blue : right.Blue;
			}

			/*
			** Returns a color containing the smallest components of the specified colors.
			** Parameters
			**	left		- the first source color
			**	right		- the second source color
			** Returns
			**	the resulting color.
			*/
			static Color4 Min(const Color4 &left, const Color4 &right)
			{
				return Color4(
					(left.Alpha < right.Alpha) ? left.Alpha : right.Alpha,
					(left.Red < right.Red) ? left.Red : right.Red,
					(left.Green < right.Green) ? left.Green : right.Green,
					(left.Blue < right.Blue) ? left.Blue : right.Blue);
			}

			/*
			** Returns a color containing the largest components of the specified colors.
			** Parameters
			**	left		- the first source color
			**	right		- the second source color
			**	result		- the resulting color
			** Returns
			**	nothing
			*/
			static void Max(const Color4 &left, const Color4 &right, Color4 &result)
			{
				result.Alpha = (left.Alpha > right.Alpha) ? left.Alpha : right.Alpha;
				result.Red = (left.Red > right.Red) ? left.Red : right.Red;
				result.Green = (left.Green > right.Green) ? left.Green : right.Green;
				result.Blue = (left.Blue > right.Blue) ? left.Blue : right.Blue;
			}

			/*
			** Returns a color containing the largest components of the specified colors.
			** Parameters
			**	left		- the first source color
			**	right		- the second source color
			** Returns
			**	the resulting color.
			*/
			static Color4 Max(const Color4 &left, const Color4 &right)
			{
				return Color4(
					(left.Alpha > right.Alpha) ? left.Alpha : right.Alpha,
					(left.Red > right.Red) ? left.Red : right.Red,
					(left.Green > right.Green) ? left.Green : right.Green,
					(left.Blue > right.Blue) ? left.Blue : right.Blue);
			}

			/*
			** Adjusts the contrast of a color.
			** Parameters
			**	value		- the color to adjust the contrast of
			**	amount		- a value between 0 and 1 indicating the amount to adjust the contrast by
			**	result		- the resulting color
			** Returns
			**	nothing
			*/
			static void AdjustContrast(const Color4 &value, real amount, Color4 &result)
			{
				result.Alpha = value.Alpha;
				result.Red = (real)0.5 + amount * (value.Red - (real)0.5);
				result.Green = (real)0.5 + amount * (value.Green - (real)0.5);
				result.Blue = (real)0.5 + amount * (value.Blue - (real)0.5);
			}

			/*
			** Adjusts the contrast of a color.
			** Parameters
			**	value		- the color to adjust the contrast of
			**	amount		- a value between 0 and 1 indicating the amount to adjust the contrast by
			** Returns
			**	the resulting color.
			*/
			static Color4 AdjustContrast(const Color4 &value, real amount)
			{
				return Color4(value.Alpha,
					(real)0.5 + amount * (value.Red - (real)0.5),
					(real)0.5 + amount * (value.Green - (real)0.5),
					(real)0.5 + amount * (value.Blue - (real)0.5));
			}

			/*
			** Adjusts the saturation of a color.
			** Parameters
			**	value		- the color to adjust
			**	saturation	- the amount by which to adjust the saturation
			**	result		- the resulting color
			** Returns
			**	nothing
			*/
			static void AdjustSaturation(const Color4 &value, real saturation, Color4 &result)
			{
				real grey = value.Red * (real)0.2125 + value.Green * (real)0.7154 + value.Blue * (real)0.721;

				result.Alpha = value.Alpha;
				result.Red = grey + saturation * (value.Red - grey);
				result.Green = grey + saturation * (value.Green - grey);
				result.Blue = grey + saturation * (value.Blue - grey);
			}

			/*
			** Adjusts the saturation of a color.
			** Parameters
			**	value		- the color to adjust
			**	saturation	- the amount by which to adjust the saturation
			** Returns
			**	the resulting color.
			*/
			static Color4 AdjustSaturation(const Color4 &value, real saturation)
			{
				real grey = value.Red * (real)0.2125 + value.Green * (real)0.7154 + value.Blue * (real)0.721;

				return Color4(value.Alpha,
					grey + saturation * (value.Red - grey),
					 grey + saturation * (value.Green - grey),
					 grey + saturation * (value.Blue - grey));
			}

			/*
			** Adds two colors.
			**/
			Color4 operator+(const Color4 &other)
			{
				return Color4(Alpha + other.Alpha,
					Red + other.Red,
					Green + other.Green,
					Blue + other.Blue);
			}

			/*
			** Adds a color to this color.
			*/
			Color4& operator+=(const Color4 &other)
			{
				Alpha += other.Alpha;
				Red += other.Red;
				Green += other.Green;
				Blue += other.Blue;

				return *this;
			}

			/*
			** Subtracts two colors.
			*/
			Color4 operator-(const Color4 &other)
			{
				return Color4(Alpha - other.Alpha,
					Red - other.Red,
					Green - other.Green,
					Blue - other.Blue);
			}

			/*
			** Subtracts a color from this color.
			*/
			Color4& operator-=(const Color4 &other)
			{
				Alpha -= other.Alpha;
				Red -= other.Red;
				Green -= other.Green;
				Blue -= other.Blue;

				return *this;
			}

			/*
			** Negates this color
			*/
			Color4 operator-()
			{
				return Color4((real)1.0 - Alpha,
					(real)1.0 - Red,
					(real)1.0 - Green,
					(real)1.0 - Blue);
			}

			/*
			** Scales a color
			*/
			Color4 operator*(real scale)
			{
				return Color4(Alpha * scale,
					Red * scale,
					Green * scale,
					Blue * scale);
			}

			/*
			** Scales this color
			*/
			Color4 &operator*=(real scale)
			{
				Alpha *= scale;
				Red *= scale;
				Green *= scale;
				Blue *= scale;

				return *this;
			}

			/*
			** Tests for equality
			*/
			bool operator==(const Color4 &other)
			{
				return (Alpha == other.Alpha) && (Red == other.Red) && (Green == other.Green) && (Blue == other.Blue);
			}

			/*
			** Tests for inequality
			*/
			bool operator!=(const Color4 &other)
			{
				return (Alpha != other.Alpha)
					|| (Red != other.Red)
					|| (Green != other.Green)
					|| (Blue != other.Blue);
			}
		};
	}
}

#endif /* _TEKSTORM_COLOR4_H */