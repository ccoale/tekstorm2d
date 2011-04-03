#define TEKSTORM_BUILD
#include "Color3.h"

namespace Tekstorm
{
	namespace Math
	{
		/*
		** Initializes a new instance of Color3.
		** Parameters
		**	value		- a scalar value to set red, green and blue to.
		** Returns
		**	nothing
		*/
		Color3::Color3(real value)
		{
			Red = Green = Blue = value;
		}

		/*
		** Initializes a new instance of Color3.
		** Parameters
		**	r		- the value to set Red to
		**	g		- the value to set Green to
		**	b		- the value to set Blue to
		** Returns
		**	nothing
		*/
		Color3::Color3(real r, real g, real b)
		{
			Red = r;
			Green = g;
			Blue = b;
		}

		/*
		** Initializes a new instance of Color3.
		** Parameters
		**	value		- a Vector3 containing the values for the color components
		**				- X is Red, Y is Green, Z is blue.
		** Returns
		**	nothing
		*/
		Color3::Color3(const Vector3& value)
		{
			Red = value.X;
			Green = value.Y;
			Blue = value.Z;
		}

		/*
		** Initializes a new instance of this Color3.
		** Parameters
		**	argb		- a packed integer storing the color components.
		**				- RR is the high byte.
		** Returns
		**	nothing
		*/
		Color3::Color3(int rgb)
		{
			Red = ((rgb >> 16) & 0xFF) / (real)255;
			Green = ((rgb >> 8) & 0xFF) / (real)255;
			Blue = ((rgb & 0xFF)) / (real)255;
		}

		/*
		** Initializes a new instance of this Color3.
		** Parameters
		**	arr			- A 3-element array used to assign the color components of this color.
		**				- arr[0] = Red, arr[1] = Green, arr[2] = Blue
		** Returns
		**	nothing
		*/
		Color3::Color3(const real arr[])
		{
			Red = arr[0];
			Green = arr[1];
			Blue = arr[2];
		}

		/*
		** Converts this color to a packed integer.
		** Parameters
		**	none
		** Returns
		**	an integer containing the color components of this color.
		*/
		int Color3::GetRgb() const
		{
			unsigned int a = ((unsigned int)(255));
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
		void Color3::Add(const Color3 &left, const Color3 &right, Color3 &result)
		{
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
		Color3 Color3::Add(const Color3 &left, const Color3 &right)
		{
			return Color3(
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
		void Color3::Subtract(const Color3 &left, const Color3 &right, Color3 &result)
		{
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
		Color3 Color3::Subtract(const Color3 &left, const Color3 &right)
		{
			return Color3(
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
		void Color3::Modulate(const Color3 &left, const Color3 &right, Color3 &result)
		{
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
		Color3 Color3::Modulate(const Color3 &left, const Color3 &right)
		{
			return Color3(
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
		void Color3::Scale(const Color3 &left, real scale, Color3 &result)
		{
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
		Color3 Color3::Scale(const Color3 &left, real scale)
		{
			return Color3(
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
		void Color3::Negate(const Color3 &value, Color3 &result)
		{
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
		Color3 Color3::Negate(const Color3 &value)
		{
			return Color3(
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
		void Color3::Clamp(const Color3 &value, const Color3 &min, const Color3 &max, Color3 &result)
		{
			real red = value.Red;
			red = (red > max.Red) ? max.Red : red;
			red = (red < min.Red) ? min.Red : red;

			real green = value.Green;
			green = (green > max.Green) ? max.Green : green;
			green = (green < min.Green) ? min.Green : green;

			real blue = value.Blue;
			blue = (blue > max.Blue) ? max.Blue : blue;
			blue = (blue < min.Blue) ? min.Blue : blue;

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
		Color3 Color3::Clamp(const Color3 &value, const Color3 &min, const Color3 &max)
		{
			real red = value.Red;
			red = (red > max.Red) ? max.Red : red;
			red = (red < min.Red) ? min.Red : red;

			real green = value.Green;
			green = (green > max.Green) ? max.Green : green;
			green = (green < min.Green) ? min.Green : green;

			real blue = value.Blue;
			blue = (blue > max.Blue) ? max.Blue : blue;
			blue = (blue < min.Blue) ? min.Blue : blue;

			return Color3(red, green, blue);
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
		void Color3::Lerp(const Color3 &start, const Color3 &end, real amount, Color3 &result)
		{
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
		Color3 Color3::Lerp(const Color3 &start, const Color3 &end, real amount)
		{
			return Color3(
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
		void Color3::SmoothStep(const Color3 &start, const Color3 &end, real amount, Color3 &result)
		{
			amount = (amount > (real)1.0) ? (real)1.0 : ((amount < (real)0.0) ? (real)0.0 : amount);
			amount = (amount * amount) * ((real)3.0 - ((real)2.0 * amount));

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
		Color3 Color3::SmoothStep(const Color3 &start, const Color3 &end, real amount)
		{
			amount = (amount > (real)1.0) ? (real)1.0 : ((amount < (real)0.0) ? (real)0.0 : amount);
			amount = (amount * amount) * ((real)3.0 - ((real)2.0 * amount));

			return Color3(
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
		void Color3::Min(const Color3 &left, const Color3 &right, Color3 &result)
		{
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
		Color3 Color3::Min(const Color3 &left, const Color3 &right)
		{
			return Color3(
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
		void Color3::Max(const Color3 &left, const Color3 &right, Color3 &result)
		{
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
		Color3 Color3::Max(const Color3 &left, const Color3 &right)
		{
			return Color3(
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
		void Color3::AdjustContrast(const Color3 &value, real amount, Color3 &result)
		{
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
		Color3 Color3::AdjustContrast(const Color3 &value, real amount)
		{
			return Color3(
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
		void Color3::AdjustSaturation(const Color3 &value, real saturation, Color3 &result)
		{
			real grey = value.Red * (real)0.2125 + value.Green * (real)0.7154 + value.Blue * (real)0.721;

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
		Color3 Color3::AdjustSaturation(const Color3 &value, real saturation)
		{
			real grey = value.Red * (real)0.2125 + value.Green * (real)0.7154 + value.Blue * (real)0.721;

			return Color3(
				grey + saturation * (value.Red - grey),
				grey + saturation * (value.Green - grey),
				grey + saturation * (value.Blue - grey));
		}

		/*
		** Adds two colors.
		**/
		Color3 Color3::operator+(const Color3 &other)
		{
			return Color3(
				Red + other.Red,
				Green + other.Green,
				Blue + other.Blue);
		}

		/*
		** Adds a color to this color.
		*/
		Color3& Color3::operator+=(const Color3 &other)
		{
			Red += other.Red;
			Green += other.Green;
			Blue += other.Blue;

			return *this;
		}

		/*
		** Subtracts two colors.
		*/
		Color3 Color3::operator-(const Color3 &other)
		{
			return Color3(
				Red - other.Red,
				Green - other.Green,
				Blue - other.Blue);
		}

		/*
		** Subtracts a color from this color.
		*/
		Color3& Color3::operator-=(const Color3 &other)
		{
			Red -= other.Red;
			Green -= other.Green;
			Blue -= other.Blue;

			return *this;
		}

		/*
		** Negates this color
		*/
		Color3 Color3::operator-()
		{
			return Color3(
				(real)1.0 - Red,
				(real)1.0 - Green,
				(real)1.0 - Blue);
		}

		/*
		** Scales a color
		*/
		Color3 Color3::operator*(real scale)
		{
			return Color3(
				Red * scale,
				Green * scale,
				Blue * scale);
		}

		/*
		** Scales this color
		*/
		Color3 &Color3::operator*=(real scale)
		{
			Red *= scale;
			Green *= scale;
			Blue *= scale;

			return *this;
		}

		/*
		** Tests for equality
		*/
		bool Color3::operator==(const Color3 &other)
		{
			return (Red == other.Red) && (Green == other.Green) && (Blue == other.Blue);
		}

		/*
		** Tests for inequality
		*/
		bool Color3::operator!=(const Color3 &other)
		{
			return (Red != other.Red) || (Green != other.Green) || (Blue != other.Blue);
		}
	}
}