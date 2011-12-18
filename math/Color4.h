/*
**
**
*/
#pragma once
#ifndef _TEKSTORM_MATH_COLOR4_H
#define _TEKSTORM_MATH_COLOR4_H
#include "../tekconfig.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

namespace Tekstorm
{
	namespace Math
	{
		///
		/// A Red, Green, Blue color.
		class TEKAPI Color4
		{
		public:
			///
			/// The Red-component of this color.
			///
			tekreal R;

			///
			/// The Green-component of this color.
			///
			tekreal G;

			///
			/// The Blue-component of this color.
			///
			tekreal B;

			///
			/// The Alpha-component of this color.
			///
			tekreal A;

			///
			/// Creates a new color with all components set to 0.
			///
			Color4();

			///
			/// Creates a new color
			///
			Color4(const Color4 &other);

			///
			/// Creates a new color
			///
			Color4(tekreal r, tekreal g, tekreal b, tekreal a);

			///
			/// Creates a new color
			///
			explicit Color4(int r, int g, int b, int a = 255);

			///
			/// Creates a new color from a Vector4. X = red, Y = green, Z = blue, W = alpha
			///
			Color4(const Vector4& col);

			///
			/// Creates a new color from an array. [0] = red, [1] = green, [2] = blue, [3] = alpha
			///
			Color4(const tekreal values[]);

			///
			/// Gets a Vector3 of each color component.
			///
			Vector3 GetVector3() const;

			///
			/// Gets a Vector4 of each color component.
			///
			Vector4 GetVector4() const;

			static Color4 Add(const Color4 &left, const Color4 &right);
			static void Add(const Color4 &left, const Color4 &right, Color4 *result);
			static Color4 Add(const Color4 &left, tekreal right);
			static void Add(const Color4 &left, tekreal right, Color4 *result);

			static Color4 Subtract(const Color4 &left, const Color4 &right);
			static void Subtract(const Color4 &left, const Color4 &right, Color4 *result);
			static Color4 Subtract(const Color4 &left, tekreal right);
			static void Subtract(const Color4 &left, tekreal right, Color4 *result);

			static Color4 Multiply(const Color4 &left, const Color4 &right);
			static void Multiply(const Color4 &left, const Color4 &right, Color4 *result);
			static Color4 Multiply(const Color4 &left, tekreal right);
			static void Multiply(const Color4 &left, tekreal right, Color4 *result);

			static Color4 Divide(const Color4 &left, const Color4 &right);
			static void Divide(const Color4 &left, const Color4 &right, Color4 *result);
			static Color4 Divide(const Color4 &left, tekreal right);
			static void Divide(const Color4 &left, tekreal right, Color4 *result);

			Color4 operator+(const Color4 &right);
			Color4 operator+(tekreal right);
			Color4& operator+=(const Color4 &right);
			Color4& operator+=(tekreal right);

			Color4 operator-(const Color4 &right);
			Color4 operator-(tekreal right);
			Color4& operator-=(const Color4 &right);
			Color4& operator-=(tekreal right);

			Color4 operator*(const Color4 &right);
			Color4 operator*(tekreal right);
			Color4& operator*=(const Color4 &right);
			Color4& operator*=(tekreal right);

			Color4 operator/(const Color4 &right);
			Color4 operator/(tekreal right);
			Color4& operator/=(const Color4 &right);
			Color4& operator/=(tekreal right);

			// -- standard colors --
			static const Color4 AliceBlue;
			static const Color4 AntiqueWhite;
			static const Color4 Aqua;
			static const Color4 Aquamarine;
			static const Color4 Azure;
			static const Color4 Beige;
			static const Color4 Bisque;
			static const Color4 Black;
			static const Color4 BlanchedAlmond;
			static const Color4 Blue;
			static const Color4 BlueViolet;
			static const Color4 Brown;
			static const Color4 BurlyWood;
			static const Color4 CadetBlue;
			static const Color4 Chartreuse;
			static const Color4 Chocolate;
			static const Color4 Coral;
			static const Color4 CornflowerBlue;
			static const Color4 Cornsilk;
			static const Color4 Crimson;
			static const Color4 Cyan;
			static const Color4 DarkBlue;
			static const Color4 DarkCyan;
			static const Color4 DarkGoldenrod;
			static const Color4 DarkGray;
			static const Color4 DarkGreen;
			static const Color4 DarkKhaki;
			static const Color4 DarkMagenta;
			static const Color4 DarkOliveGreen;
			static const Color4 DarkOrange;
			static const Color4 DarkOrchid;
			static const Color4 DarkRed;
			static const Color4 DarkSalmon;
			static const Color4 DarkSeaGreen;
			static const Color4 DarkSlateBlue;
			static const Color4 DarkSlateGray;
			static const Color4 DarkTurquoise;
			static const Color4 DarkViolet;
			static const Color4 DeepPink;
			static const Color4 DeepSkyBlue;
			static const Color4 DimGray;
			static const Color4 DodgerBlue;
			static const Color4 Firebrick;
			static const Color4 FloralWhite;
			static const Color4 ForestGreen;
			static const Color4 Fuchsia;
			static const Color4 Grainsboro;
			static const Color4 GhostWhite;
			static const Color4 Gold;
			static const Color4 Goldenrod;
			static const Color4 Gray;
			static const Color4 Green;
			static const Color4 GreenYellow;
			static const Color4 Honeydew;
			static const Color4 HotPink;
			static const Color4 IndianRed;
			static const Color4 Indigo;
			static const Color4 Ivory;
			static const Color4 Khaki;
			static const Color4 Lavender;
			static const Color4 LavenderBlush;
			static const Color4 LawnGreen;
			static const Color4 LemonChiffon;
			static const Color4 LightBlue;
			static const Color4 LightCoral;
			static const Color4 LightCyan;
			static const Color4 LightGoldenrodYellow;
			static const Color4 LightGray;
			static const Color4 LightGreen;
			static const Color4 LightPink;
			static const Color4 LightSalmon;
			static const Color4 LightSeaGreen;
			static const Color4 LightSkyBlue;
			static const Color4 LightSlateGray;
			static const Color4 LightSteelBlue;
			static const Color4 LightYellow;
			static const Color4 Lime;
			static const Color4 LimeGreen;
			static const Color4 Linen;
			static const Color4 Magenta;
			static const Color4 Maroon;
			static const Color4 MediumAquamarine;
			static const Color4 MediumBlue;
			static const Color4 MediumOrchid;
			static const Color4 MediumPurple;
			static const Color4 MediaSeaGreen;
			static const Color4 MediumSlateBlue;
			static const Color4 MediumSpringGreen;
			static const Color4 MediumTurquoise;
			static const Color4 MediumVioletRed;
			static const Color4 MidnightBlue;
			static const Color4 MintCream;
			static const Color4 MistyRose;
			static const Color4 Moccasin;
			static const Color4 NavajoWhite;
			static const Color4 Navy;
			static const Color4 OldLace;
			static const Color4 Olive;
			static const Color4 OliveDrab;
			static const Color4 Orange;
			static const Color4 OrangeRed;
			static const Color4 Orchid;
			static const Color4 PaleGoldenrod;
			static const Color4 PaleGreen;
			static const Color4 PaleTurquoise;
			static const Color4 PaleVioletRed;
			static const Color4 PapayaWhip;
			static const Color4 PeachPuff;
			static const Color4 Peru;
			static const Color4 Pink;
			static const Color4 Plum;
			static const Color4 PowderBlue;
			static const Color4 Purple;
			static const Color4 Red;
			static const Color4 RosyBrown;
			static const Color4 RoyalBlue;
			static const Color4 SaddleBrown;
			static const Color4 Salmon;
			static const Color4 SandyBrown;
			static const Color4 SeaGreen;
			static const Color4 SeaShell;
			static const Color4 Sienna;
			static const Color4 Silver;
			static const Color4 SkyBlue;
			static const Color4 SlateBlue;
			static const Color4 SlateGray;
			static const Color4 Snow;
			static const Color4 SpringGreen;
			static const Color4 SteelBlue;
			static const Color4 Tan;
			static const Color4 Teal;
			static const Color4 Thistle;
			static const Color4 Tomato;
			static const Color4 TransparentBlack;
			static const Color4 TransparentWhite;
			static const Color4 Turquoise;
			static const Color4 Violet;
			static const Color4 Wheat;
			static const Color4 White;
			static const Color4 WhiteSmoke;
			static const Color4 Yellow;
			static const Color4 YellowGreen;
		};
	}
}

#endif /* _TEKSTORM_COLOR4_H */