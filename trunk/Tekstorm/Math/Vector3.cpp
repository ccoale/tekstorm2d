#define TEKSTORM_BUILD
#include "Vector3.h"

namespace Tekstorm
{
	namespace Math
	{
		const Vector3 Vector3::UnitX = Vector3((real)1.0, (real)0.0, (real)0.0);
		const Vector3 Vector3::UnitY = Vector3((real)0.0, (real)1.0, (real)0.0);
		const Vector3 Vector3::UnitZ = Vector3((real)0.0, (real)0.0, (real)1.0);
		const Vector3 Vector3::Zero = Vector3((real)0.0, (real)0.0, (real)0.0);
		const Vector3 Vector3::One = Vector3((real)1.0, (real)1.0, (real)1.0);
		const int Vector3::SizeInBytes = sizeof(Vector3);
	}
}