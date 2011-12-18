#include "Color3.h"

namespace Tekstorm
{
	namespace Math
	{
			///
			/// Creates a new color with all components set to 0.
			///
			Color3::Color3()
			{
				R = G = B = (tekreal)0.0;
			}

			///
			/// Creates a new color
			///
			Color3::Color3(const Color3 &other)
			{
				R = other.R;
				G = other.G;
				B = other.B;
			}

			///
			/// Creates a new color
			///
			Color3::Color3(tekreal r, tekreal g, tekreal b)
			{
				R = r; G = g; B = b;
			}

			///
			/// Creates a new color
			///
			Color3::Color3(int r, int g, int b)
			{
				R = (tekreal)(r & 0xFF) / (tekreal)255.0;
				G = (tekreal)(g & 0xFF) / (tekreal)255.0;
				B = (tekreal)(b & 0xFF) / (tekreal)255.0;
			}

			///
			/// Creates a new color from a Vector3. X = red, Y = green, Z = blue.
			///
			Color3::Color3(const Vector3& col)
			{
				R = col.X; G = col.Y; B = col.Z;
			}

			///
			/// Creates a new color from an array. [0] = red, [1] = green, [2] = blue
			///
			Color3::Color3(const tekreal values[])
			{
				R = values[0]; G = values[1]; B = values[2];
			}

			///
			/// Gets a Vector3 of each color component.
			///
			Vector3 Color3::GetVector3() const
			{
				return Vector3(R, G, B);
			}

			///
			/// Gets a Vector4 of each color component. W = 1.0
			///
			Vector4 Color3::GetVector4() const
			{
				return Vector4(R, G, B, (tekreal)1.0);
			}

			///
			/// Adds two colors together
			///
			Color3 Color3::Add(const Color3 &left, const Color3 &right)
			{
				return Color3(left.R + right.R, left.G + right.G, left.B + right.B);
			}

			///
			/// Adds two colors together
			///
			void Color3::Add(const Color3 &left, const Color3 &right, Color3 *result)
			{
				result->R = left.R + right.R;
				result->G = left.G + right.G;
				result->B = left.B + right.B;
			}

			///
			/// Adds two colors together
			///
			Color3 Color3::Add(const Color3 &left, tekreal right)
			{
				return Color3(left.R + right, left.G + right, left.B + right);
			}

			///
			/// Adds two colors together
			///
			void Color3::Add(const Color3 &left, tekreal right, Color3 *result)
			{
				result->R = left.R + right;
				result->G = left.G + right;
				result->B = left.B + right;
			}

			///
			/// Subtracts two colors
			///
			Color3 Color3::Subtract(const Color3 &left, const Color3 &right)
			{
				return Color3(left.R - right.R, left.G - right.G, left.B - right.B);
			}

			///
			/// Subtracts two colors
			///
			void Color3::Subtract(const Color3 &left, const Color3 &right, Color3 *result)
			{
				result->R = left.R - right.R;
				result->G = left.G - right.G;
				result->B = left.B - right.B;
			}

			///
			/// Subtracts two colors
			///
			Color3 Color3::Subtract(const Color3 &left, tekreal right)
			{
				return Color3(left.R - right, left.G - right, left.B - right);
			}

			///
			/// Subtracts two colors
			///
			void Color3::Subtract(const Color3 &left, tekreal right, Color3 *result)
			{
				result->R = left.R - right;
				result->G = left.G - right;
				result->B = left.B - right;
			}

			///
			/// Multiplies two colors
			///
			Color3 Color3::Multiply(const Color3 &left, const Color3 &right)
			{
				return Color3(left.R * right.R, left.G * right.G, left.B * right.B);
			}

			///
			/// Multiplies two colors
			///
			void Color3::Multiply(const Color3 &left, const Color3 &right, Color3 *result)
			{
				result->R = left.R * right.R;
				result->G = left.G * right.G;
				result->B = left.B * right.B;
			}

			///
			/// Multiplies two colors
			///
			Color3 Color3::Multiply(const Color3 &left, tekreal right)
			{
				return Color3(left.R * right, left.G * right, left.B * right);
			}

			///
			/// Multiplies two colors
			///
			void Color3::Multiply(const Color3 &left, tekreal right, Color3 *result)
			{
				result->R = left.R * right;
				result->G = left.G * right;
				result->B = left.B * right;
			}

			///
			/// Divides two colors
			///
			Color3 Color3::Divide(const Color3 &left, const Color3 &right)
			{
				return Color3(left.R / right.R, left.G / right.G, left.B / right.B);
			}

			///
			/// Divides two colors
			///
			void Color3::Divide(const Color3 &left, const Color3 &right, Color3 *result)
			{
				result->R = left.R / right.R;
				result->G = left.G / right.G;
				result->B = left.B / right.B;
			}

			///
			/// Divides two colors
			///
			Color3 Color3::Divide(const Color3 &left, tekreal right)
			{
				return Color3(left.R / right, left.G / right, left.B / right);
			}

			///
			/// Divides two colors
			///
			void Color3::Divide(const Color3 &left, tekreal right, Color3 *result)
			{
				result->R = left.R / right;
				result->G = left.G / right;
				result->B = left.B / right;
			}


			///
			/// Adds two colors
			///
			Color3 Color3::operator+(const Color3 &right)
			{
				return Color3(R + right.R, G + right.G, B + right.B);
			}

			///
			/// Adds two colors
			///
			Color3 Color3::operator+(tekreal right)
			{
				return Color3(R + right, G + right, B + right);
			}

			///
			/// Adds two colors
			///
			Color3& Color3::operator+=(const Color3 &right)
			{
				R += right.R;
				G += right.G;
				B += right.B;

				return *this;
			}

			///
			/// Adds two colors
			///
			Color3& Color3::operator+=(tekreal right)
			{
				R += right;
				G += right;
				B += right;

				return *this;
			}

			///
			/// Subtracts two colors
			///
			Color3 Color3::operator-(const Color3 &right)
			{
				return Color3(R - right.R, G - right.G, B - right.B);
			}

			///
			/// Subtracts two colors
			///
			Color3 Color3::operator-(tekreal right)
			{
				return Color3(R - right, G - right, B - right);
			}

			///
			/// Subtracts two colors
			///
			Color3& Color3::operator-=(const Color3 &right)
			{
				R -= right.R;
				G -= right.G;
				B -= right.B;

				return *this;
			}

			///
			/// Subtracts two colors
			///
			Color3& Color3::operator-=(tekreal right)
			{
				R -= right;
				G -= right;
				B -= right;

				return *this;
			}

			///
			/// Multiplies two colors
			///
			Color3 Color3::operator*(const Color3 &right)
			{
				return Color3(R * right.R, G * right.G, B * right.B);
			}
			
			///
			/// Multiplies two colors
			///
			Color3 Color3::operator*(tekreal right)
			{
				return Color3(R * right, G * right, B * right);
			}

			///
			/// Multiplies two colors
			///
			Color3& Color3::operator*=(const Color3 &right)
			{
				R *= right.R;
				G *= right.G;
				B *= right.B;

				return *this;
			}

			///
			/// Multiplies two colors
			///
			Color3& Color3::operator*=(tekreal right)
			{
				R *= right;
				G *= right;
				B *= right;

				return *this;
			}

			///
			/// Divides two colors
			///
			Color3 Color3::operator/(const Color3 &right)
			{
				return Color3(R / right.R, G / right.G, B / right.B);
			}

			///
			/// Divides two colors
			///
			Color3 Color3::operator/(tekreal right)
			{
				return Color3(R / right, G / right, B / right);
			}

			///
			/// Divides two colors
			///
			Color3& Color3::operator/=(const Color3 &right)
			{
				R /= right.R;
				G /= right.G;
				B /= right.B;
				
				return *this;
			}

			///
			/// Divides two colors
			///
			Color3& Color3::operator/=(tekreal right)
			{
				R /= right;
				G /= right;
				B /= right;

				return *this;
			}

			// -- standard colors --
			const Color3 Color3::AliceBlue = Color3(240, 248, 255);
			const Color3 Color3::AntiqueWhite = Color3(250, 235, 215);
			const Color3 Color3::Aqua = Color3(0, 255, 255);
			const Color3 Color3::Aquamarine = Color3(127, 255, 212);
			const Color3 Color3::Azure = Color3(240, 255, 255);
			const Color3 Color3::Beige = Color3(245, 245, 220);
			const Color3 Color3::Bisque = Color3(225, 228, 196);
			const Color3 Color3::Black = Color3(0, 0, 0);
			const Color3 Color3::BlanchedAlmond = Color3(225, 235, 205);
			const Color3 Color3::Blue = Color3(0, 0, 255);
			const Color3 Color3::BlueViolet = Color3(138, 226, 255);
			const Color3 Color3::Brown = Color3(165, 42, 255);
			const Color3 Color3::BurlyWood = Color3(222, 184, 135);
			const Color3 Color3::CadetBlue = Color3(95, 158, 160);
			const Color3 Color3::Chartreuse = Color3(127, 255, 0);
			const Color3 Color3::Chocolate = Color3(210, 105, 30);
			const Color3 Color3::Coral = Color3(255, 127, 80);
			const Color3 Color3::CornflowerBlue = Color3(100, 149, 237);
			const Color3 Color3::Cornsilk = Color3(255, 248, 220);
			const Color3 Color3::Crimson = Color3(220, 20, 60);
			const Color3 Color3::Cyan = Color3(0, 255, 255);
			const Color3 Color3::DarkBlue = Color3(0, 0, 139);
			const Color3 Color3::DarkCyan = Color3(0, 139, 139);
			const Color3 Color3::DarkGoldenrod = Color3(184, 134, 11);
			const Color3 Color3::DarkGray = Color3(169, 169, 169);
			const Color3 Color3::DarkGreen = Color3(0, 100, 0);
			const Color3 Color3::DarkKhaki = Color3(189, 183, 107);
			const Color3 Color3::DarkMagenta = Color3(139, 0, 139);
			const Color3 Color3::DarkOliveGreen = Color3(85, 107, 47);
			const Color3 Color3::DarkOrange = Color3(255, 140, 0);
			const Color3 Color3::DarkOrchid = Color3(153, 50, 204);
			const Color3 Color3::DarkRed = Color3(139, 0, 0);
			const Color3 Color3::DarkSalmon = Color3(233, 150, 122);
			const Color3 Color3::DarkSeaGreen = Color3(143, 188, 139);
			const Color3 Color3::DarkSlateBlue = Color3(72, 61, 139);
			const Color3 Color3::DarkSlateGray = Color3(47, 79, 79);
			const Color3 Color3::DarkTurquoise = Color3(0, 206, 209);
			const Color3 Color3::DarkViolet = Color3(148, 0, 211);
			const Color3 Color3::DeepPink = Color3(255, 20, 147);
			const Color3 Color3::DeepSkyBlue = Color3(0, 191, 255);
			const Color3 Color3::DimGray = Color3(105, 105, 105);
			const Color3 Color3::DodgerBlue = Color3(30, 144, 255);
			const Color3 Color3::Firebrick = Color3(178, 34, 34);
			const Color3 Color3::FloralWhite = Color3(255, 250, 240);
			const Color3 Color3::ForestGreen = Color3(34, 139, 34);
			const Color3 Color3::Fuchsia = Color3(255, 0, 255);
			const Color3 Color3::Grainsboro = Color3(220, 220, 220);
			const Color3 Color3::GhostWhite = Color3(248, 248, 255);
			const Color3 Color3::Gold = Color3(255, 215, 0);
			const Color3 Color3::Goldenrod = Color3(218, 165, 32);
			const Color3 Color3::Gray = Color3(128, 128, 128);
			const Color3 Color3::Green = Color3(0, 128, 0);
			const Color3 Color3::GreenYellow = Color3(173, 255, 47);
			const Color3 Color3::Honeydew = Color3(240, 255, 240);
			const Color3 Color3::HotPink = Color3(255, 105, 180);
			const Color3 Color3::IndianRed = Color3(205, 92, 92);
			const Color3 Color3::Indigo = Color3(75, 0, 130);
			const Color3 Color3::Ivory = Color3(255, 255, 240);
			const Color3 Color3::Khaki = Color3(240, 230, 140);
			const Color3 Color3::Lavender = Color3(230, 230, 250);
			const Color3 Color3::LavenderBlush = Color3(255, 240, 245);
			const Color3 Color3::LawnGreen = Color3(124, 252, 0);
			const Color3 Color3::LemonChiffon = Color3(255, 250, 205);
			const Color3 Color3::LightBlue = Color3(173, 216, 230);
			const Color3 Color3::LightCoral = Color3(240, 128, 128);
			const Color3 Color3::LightCyan = Color3(224, 255, 255);
			const Color3 Color3::LightGoldenrodYellow = Color3(250, 250, 210);
			const Color3 Color3::LightGray = Color3(211, 211, 211);
			const Color3 Color3::LightGreen = Color3(144, 238, 144);
			const Color3 Color3::LightPink = Color3(255, 182, 193);
			const Color3 Color3::LightSalmon = Color3(255, 160, 122);
			const Color3 Color3::LightSeaGreen = Color3(32, 178, 170);
			const Color3 Color3::LightSkyBlue = Color3(135, 206, 250);
			const Color3 Color3::LightSlateGray = Color3(119, 136, 153);
			const Color3 Color3::LightSteelBlue = Color3(176, 196, 222);
			const Color3 Color3::LightYellow = Color3(255, 255, 224);
			const Color3 Color3::Lime = Color3(0, 255, 0);
			const Color3 Color3::LimeGreen = Color3(50, 205, 50);
			const Color3 Color3::Linen = Color3(250, 240, 230);
			const Color3 Color3::Magenta = Color3(255, 0, 255);
			const Color3 Color3::Maroon = Color3(128, 0, 0);
			const Color3 Color3::MediumAquamarine = Color3(102, 105, 170);
			const Color3 Color3::MediumBlue = Color3(0, 0, 205);
			const Color3 Color3::MediumOrchid = Color3(186, 85, 211);
			const Color3 Color3::MediumPurple = Color3(147, 112, 219);
			const Color3 Color3::MediaSeaGreen = Color3(60, 179, 113);
			const Color3 Color3::MediumSlateBlue = Color3(123, 104, 238);
			const Color3 Color3::MediumSpringGreen = Color3(0, 250, 154);
			const Color3 Color3::MediumTurquoise = Color3(72, 209, 204);
			const Color3 Color3::MediumVioletRed = Color3(199, 21, 133);
			const Color3 Color3::MidnightBlue = Color3(25, 25, 112);
			const Color3 Color3::MintCream = Color3(245, 255, 250);
			const Color3 Color3::MistyRose = Color3(255, 228, 225);
			const Color3 Color3::Moccasin = Color3(255, 228, 181);
			const Color3 Color3::NavajoWhite = Color3(255, 222, 173);
			const Color3 Color3::Navy = Color3(0, 0, 128);
			const Color3 Color3::OldLace = Color3(253, 245, 230);
			const Color3 Color3::Olive = Color3(128, 128, 0);
			const Color3 Color3::OliveDrab = Color3(107, 142, 35);
			const Color3 Color3::Orange = Color3(255, 165, 0);
			const Color3 Color3::OrangeRed = Color3(255, 69, 0);
			const Color3 Color3::Orchid = Color3(218, 112, 214);
			const Color3 Color3::PaleGoldenrod = Color3(238, 232, 170);
			const Color3 Color3::PaleGreen = Color3(152, 251, 152);
			const Color3 Color3::PaleTurquoise = Color3(175, 238, 238);
			const Color3 Color3::PaleVioletRed = Color3(219, 112, 147);
			const Color3 Color3::PapayaWhip = Color3(255, 239, 213);
			const Color3 Color3::PeachPuff = Color3(255, 218, 185);
			const Color3 Color3::Peru = Color3(205, 133, 63);
			const Color3 Color3::Pink = Color3(255, 192, 203);
			const Color3 Color3::Plum = Color3(221, 160, 221);
			const Color3 Color3::PowderBlue = Color3(176, 224, 230);
			const Color3 Color3::Purple = Color3(128, 0, 128);
			const Color3 Color3::Red = Color3(255, 0, 0);
			const Color3 Color3::RosyBrown = Color3(188, 143, 143);
			const Color3 Color3::RoyalBlue = Color3(65, 105, 225);
			const Color3 Color3::SaddleBrown = Color3(139, 69, 19);
			const Color3 Color3::Salmon = Color3(250, 128, 114);
			const Color3 Color3::SandyBrown = Color3(244, 164, 96);
			const Color3 Color3::SeaGreen = Color3(46, 139, 87);
			const Color3 Color3::SeaShell = Color3(255, 245, 238);
			const Color3 Color3::Sienna = Color3(160, 82, 45);
			const Color3 Color3::Silver = Color3(192, 192, 192);
			const Color3 Color3::SkyBlue = Color3(135, 206, 235);
			const Color3 Color3::SlateBlue = Color3(106, 90, 205);
			const Color3 Color3::SlateGray = Color3(112, 128, 144);
			const Color3 Color3::Snow = Color3(255, 250, 250);
			const Color3 Color3::SpringGreen = Color3(0, 255, 127);
			const Color3 Color3::SteelBlue = Color3(70, 130, 180);
			const Color3 Color3::Tan = Color3(210, 180, 140);
			const Color3 Color3::Teal = Color3(0, 128, 128);
			const Color3 Color3::Thistle = Color3(216, 191, 216);
			const Color3 Color3::Tomato = Color3(255, 99, 71);
			const Color3 Color3::Turquoise = Color3(64, 224, 208);
			const Color3 Color3::Violet = Color3(238, 130, 238);
			const Color3 Color3::Wheat = Color3(245, 222, 179);
			const Color3 Color3::White = Color3(255, 255, 255);
			const Color3 Color3::WhiteSmoke = Color3(245, 245, 245);
			const Color3 Color3::Yellow = Color3(255, 255, 0);
			const Color3 Color3::YellowGreen = Color3(154, 205, 50);
	}
}