#ifndef _TEKSTORM_MATRIX_H
#define _TEKSTORM_MATRIX_H
#include "../TekstormDecl.h"
#include "Vector3.h"

namespace Tekstorm
{
	namespace Math
	{
		// Represents a 4x4 row-major matrix.
		class TEKDECL Matrix
		{
		public:
			// Represents an empty matrix (all elements are set to 0.0f)
			static Matrix Zero;

			// Represents an identity matrix (all diagonal elements are set to 1.0f)
			static Matrix Identity;

			// first row of values
			float M11, M12, M13, M14;

			// second row of values
			float M21, M22, M23, M24;

			// third row of values
			float M31, M32, M33, M34;

			// fourth row of values
			float M41, M42, M43, M44;

			// Initializes a new instance of the Matrix class (and optionally assigns a scalar value to each element).
			Matrix(float value = 0.0f);

			// Initializes a new instance of the Matrix class, allowing each element to be set individually.
			Matrix(float m11, float m12, float m13, float m14, 
				float m21, float m22, float m23, float m24,
				float m31, float m32, float m33, float m34,
				float m41, float m42, float m43, float m44);

			// Transposes this matrix and returns a reference to itself.
			Matrix4& Transpose();

			// Creates a translation matrix
			static Matrix CreateTranslation(const Vector3& trans);
			static void CreateTranslation(const Vector3& trans, Matrix& result);

			// Creates a rotation matrix
			static Matrix CreateRotation(const Vector3& rot);
			static void CreateRotation(const Vector3& rot, Matrix& result);

			// Creates a scaling matrix
			static Matrix CreateScaling(const Vector3& scale);
			static void CreateScaling(const Vector3& scale, Matrix& result);

			// Creates a transformation matrix
			static Matrix CreateTransform(const Vector3& trans, const Vector3& scale, const Vector3& rot);
		};
	}
}

#endif /* _TEKSTORM_MATRIX_H */