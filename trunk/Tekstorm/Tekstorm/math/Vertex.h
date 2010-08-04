#ifndef _TEKSTORM_VERTEX_H
#define _TEKSTORM_VERTEX_H
#include "../TekstormDecl.h"
#include "Vector2.h"
#include "Vector3.h"

namespace Tekstorm
{
	namespace Math
	{
		// This structure holds a graphics Vertex. It contains 3 position components (X, Y, and Z)
		// however, Z is generally kept at 1. It also contains a color component and texture coordinate pair.
		struct Vertex
		{
			// -- DO NOT CHANGE THE ORDER IN WHICH THESE COMPONENTS APPEAR --

			// The position of this Vertex in space.
			Vector3 Position;

			// The diffuse color of this Vertex.
			Color4 Diffuse;

			// The texture coordinates of this Vertex.
			Vector2 TexCoords;
		};
	}
}

#endif /* _TEKSTORM_VERTEX_H */