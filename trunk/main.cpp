#include <iostream>
#include "math/Vector2.h"
using namespace Tekstorm;
using namespace Math;

int main()
{
	Vector2 pos(cos(3.14159 / 4), sin(3.14159 / 4));
	printf("(%f, %f)\n", pos.X, pos.Y);
	Vector2 res = Vector2::Reflect(pos, Vector2::UnitY);
	printf("(%f, %f)\n", res.X, res.Y);
}
