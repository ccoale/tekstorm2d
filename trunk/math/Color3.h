/*
**
**
*/
#pragma once
#ifndef _TEKSTORM_MATH_COLOR3_H
#define _TEKSTORM_MATH_COLOR3_H
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
		class TEKAPI Color3
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
			/// Creates a new color with all components set to 0.
			///
			Color3();

			///
			/// Creates a new color
			///
			Color3(const Color3 &other);

			///
			/// Creates a new color
			///
			Color3(tekreal r, tekreal g, tekreal b);

			///
			/// Creates a new color
			///
			explicit Color3(int r, int g, int b);

			///
			/// Creates a new color from a Vector3. X = red, Y = green, Z = blue.
			///
			Color3(const Vector3& col);

			///
			/// Creates a new color from an array. [0] = red, [1] = green, [2] = blue
			///
			Color3(const tekreal values[]);

			///
			/// Gets a Vector3 of each color component.
			///
			Vector3 GetVector3() const;

			///
			/// Gets a Vector4 of each color component. W = 1.0
			///
			Vector4 GetVector4() const;

			static Color3 Add(const Color3 &left, const Color3 &right);
			static void Add(const Color3 &left, const Color3 &right, Color3 *result);
			static Color3 Add(const Color3 &left, tekreal right);
			static void Add(const Color3 &left, tekreal right, Color3 *result);

			static Color3 Subtract(const Color3 &left, const Color3 &right);
			static void Subtract(const Color3 &left, const Color3 &right, Color3 *result);
			static Color3 Subtract(const Color3 &left, tekreal right);
			static void Subtract(const Color3 &left, tekreal right, Color3 *result);

			static Color3 Multiply(const Color3 &left, const Color3 &right);
			static void Multiply(const Color3 &left, const Color3 &right, Color3 *result);
			static Color3 Multiply(const Color3 &left, tekreal right);
			static void Multiply(const Color3 &left, tekreal right, Color3 *result);

			static Color3 Divide(const Color3 &left, const Color3 &right);
			static void Divide(const Color3 &left, const Color3 &right, Color3 *result);
			static Color3 Divide(const Color3 &left, tekreal right);
			static void Divide(const Color3 &left, tekreal right, Color3 *result);

			Color3 operator+(const Color3 &right);
			Color3 operator+(tekreal right);
			Color3& operator+=(const Color3 &right);
			Color3& operator+=(tekreal right);

			Color3 operator-(const Color3 &right);
			Color3 operator-(tekreal right);
			Color3& operator-=(const Color3 &right);
			Color3& operator-=(tekreal right);

			Color3 operator*(const Color3 &right);
			Color3 operator*(tekreal right);
			Color3& operator*=(const Color3 &right);
			Color3& operator*=(tekreal right);

			Color3 operator/(const Color3 &right);
			Color3 operator/(tekreal right);
			Color3& operator/=(const Color3 &right);
			Color3& operator/=(tekreal right);

			// -- standard colors --
			static const Color3 AliceBlue;
			static const Color3 AntiqueWhite;
			static const Color3 Aqua;
			static const Color3 Aquamarine;
			static const Color3 Azure;
			static const Color3 Beige;
			static const Color3 Bisque;
			static const Color3 Black;
			static const Color3 BlanchedAlmond;
			static const Color3 Blue;
			static const Color3 BlueViolet;
			static const Color3 Brown;
			static const Color3 BurlyWood;
			static const Color3 CadetBlue;
			static const Color3 Chartreuse;
			static const Color3 Chocolate;
			static const Color3 Coral;
			static const Color3 CornflowerBlue;
			static const Color3 Cornsilk;
			static const Color3 Crimson;
			static const Color3 Cyan;
			static const Color3 DarkBlue;
			static const Color3 DarkCyan;
			static const Color3 DarkGoldenrod;
			static const Color3 DarkGray;
			static const Color3 DarkGreen;
			static const Color3 DarkKhaki;
			static const Color3 DarkMagenta;
			static const Color3 DarkOliveGreen;
			static const Color3 DarkOrange;
			static const Color3 DarkOrchid;
			static const Color3 DarkRed;
			static const Color3 DarkSalmon;
			static const Color3 DarkSeaGreen;
			static const Color3 DarkSlateBlue;
			static const Color3 DarkSlateGray;
			static const Color3 DarkTurquoise;
			static const Color3 DarkViolet;
			static const Color3 DeepPink;
			static const Color3 DeepSkyBlue;
			static const Color3 DimGray;
			static const Color3 DodgerBlue;
			static const Color3 Firebrick;
			static const Color3 FloralWhite;
			static const Color3 ForestGreen;
			static const Color3 Fuchsia;
			static const Color3 Grainsboro;
			static const Color3 GhostWhite;
			static const Color3 Gold;
			static const Color3 Goldenrod;
			static const Color3 Gray;
			static const Color3 Green;
			static const Color3 GreenYellow;
			static const Color3 Honeydew;
			static const Color3 HotPink;
			static const Color3 IndianRed;
			static const Color3 Indigo;
			static const Color3 Ivory;
			static const Color3 Khaki;
			static const Color3 Lavender;
			static const Color3 LavenderBlush;
			static const Color3 LawnGreen;
			static const Color3 LemonChiffon;
			static const Color3 LightBlue;
			static const Color3 LightCoral;
			static const Color3 LightCyan;
			static const Color3 LightGoldenrodYellow;
			static const Color3 LightGray;
			static const Color3 LightGreen;
			static const Color3 LightPink;
			static const Color3 LightSalmon;
			static const Color3 LightSeaGreen;
			static const Color3 LightSkyBlue;
			static const Color3 LightSlateGray;
			static const Color3 LightSteelBlue;
			static const Color3 LightYellow;
			static const Color3 Lime;
			static const Color3 LimeGreen;
			static const Color3 Linen;
			static const Color3 Magenta;
			static const Color3 Maroon;
			static const Color3 MediumAquamarine;
			static const Color3 MediumBlue;
			static const Color3 MediumOrchid;
			static const Color3 MediumPurple;
			static const Color3 MediaSeaGreen;
			static const Color3 MediumSlateBlue;
			static const Color3 MediumSpringGreen;
			static const Color3 MediumTurquoise;
			static const Color3 MediumVioletRed;
			static const Color3 MidnightBlue;
			static const Color3 MintCream;
			static const Color3 MistyRose;
			static const Color3 Moccasin;
			static const Color3 NavajoWhite;
			static const Color3 Navy;
			static const Color3 OldLace;
			static const Color3 Olive;
			static const Color3 OliveDrab;
			static const Color3 Orange;
			static const Color3 OrangeRed;
			static const Color3 Orchid;
			static const Color3 PaleGoldenrod;
			static const Color3 PaleGreen;
			static const Color3 PaleTurquoise;
			static const Color3 PaleVioletRed;
			static const Color3 PapayaWhip;
			static const Color3 PeachPuff;
			static const Color3 Peru;
			static const Color3 Pink;
			static const Color3 Plum;
			static const Color3 PowderBlue;
			static const Color3 Purple;
			static const Color3 Red;
			static const Color3 RosyBrown;
			static const Color3 RoyalBlue;
			static const Color3 SaddleBrown;
			static const Color3 Salmon;
			static const Color3 SandyBrown;
			static const Color3 SeaGreen;
			static const Color3 SeaShell;
			static const Color3 Sienna;
			static const Color3 Silver;
			static const Color3 SkyBlue;
			static const Color3 SlateBlue;
			static const Color3 SlateGray;
			static const Color3 Snow;
			static const Color3 SpringGreen;
			static const Color3 SteelBlue;
			static const Color3 Tan;
			static const Color3 Teal;
			static const Color3 Thistle;
			static const Color3 Tomato;
			static const Color3 Turquoise;
			static const Color3 Violet;
			static const Color3 Wheat;
			static const Color3 White;
			static const Color3 WhiteSmoke;
			static const Color3 Yellow;
			static const Color3 YellowGreen;
		};
	}
}

#endif /* _TEKSTORM_COLOR3_H */