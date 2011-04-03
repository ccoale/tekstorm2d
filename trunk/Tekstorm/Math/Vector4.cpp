#define TEKSTORM_BUILD
#include "Vector4.h"

namespace Tekstorm
{
	namespace Math
	{
		const Vector4 Vector4::UnitX = Vector4((real)1.0, (real)0.0, (real)0.0, (real)0.0);
		const Vector4 Vector4::UnitY = Vector4((real)0.0, (real)1.0, (real)0.0, (real)0.0);
		const Vector4 Vector4::UnitZ = Vector4((real)0.0, (real)0.0, (real)1.0, (real)0.0);
		const Vector4 Vector4::UnitW = Vector4((real)0.0, (real)0.0, (real)0.0, (real)1.0);
		const Vector4 Vector4::Zero = Vector4((real)0.0, (real)0.0, (real)0.0, (real)0.0);
		const Vector4 Vector4::One = Vector4((real)1.0, (real)1.0, (real)1.0, (real)1.0);
		const int Vector4::SizeInBytes = sizeof(Vector4);
	}
}