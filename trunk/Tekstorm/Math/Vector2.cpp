#define TEKSTORM_BUILD
#include "Vector2.h"

namespace Tekstorm
{
	namespace Math
	{
		const Vector2 Vector2::UnitX = Vector2((real)1.0, (real)0.0);
		const Vector2 Vector2::UnitY = Vector2((real)0.0, (real)1.0);
		const Vector2 Vector2::Zero = Vector2((real)0.0, (real)0.0);
		const Vector2 Vector2::One = Vector2((real)1.0, (real)1.0);
		const int Vector2::SizeInBytes = sizeof(Vector2);
	}
}