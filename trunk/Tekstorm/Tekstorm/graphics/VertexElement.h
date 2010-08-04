#ifndef _TEKSTORM_VERTEXELEMENT_H
#define _TEKSTORM_VERTEXELEMENT_H
#include "../TekstormDecl.h"

namespace Tekstorm
{
	namespace Graphics
	{
		// An enumeration of 'Type's for the VertexElement.
		enum _tagVERTEXELEMENTTYPE : ubyte_t
		{
			// A single floating-point value
			DECLTYPE_FLOAT1 = 0,

			// A two-component floating-point value
			DECLTYPE_FLOAT2 = 1,

			// A three-component floating-point value
			DECLTYPE_FLOAT3 = 2,

			// A four-component floating-point value (also used for colors)
			DECLTYPE_FLOAT4 = 3,
			
			// The standard Direct3D color format (ARGB) as a 32-bit unsigned integer.
			DECLTYPE_D3DCOLOR = 4,

			// A four-component unsigned byte value.
			DECLTYPE_UBYTE4 = 5,

			// A two-component signed short value.
			DECLTYPE_SHORT2 = 6,

			// A four-component signed short value.
			DECLTYPE_SHORT4 = 7,

			// A four-component unsigned byte value with each value normalized.
			DECLTYPE_UBYTE4N = 8,

			// A two-component signed short value with each value normalized.
			DECLTYPE_SHORT2N = 9,

			// A four-component signed short value with each value normalized.
		    DECLTYPE_SHORT4N = 10,

			// A two-component unsigned short value with each value normalized.
			DECLTYPE_USHORT2N = 11,

			// A four-component unsigned short value with each value normalized.
			DECLTYPE_USHORT4N = 12,
			DECLTYPE_UDEC3 = 13,
			DECLTYPE_DEC3N = 14,
			DECLTYPE_FLOAT16_2 = 15,
			DECLTYPE_FLOAT16_4 = 16,
			DECLTYPE_UNUSED = 17
		};

		// A VertexElement structure describes a specific aspect of an element
		// that is stored inside a custom vertex. For example, a position, diffuse color,
		// texture coordinates, etc.
		struct VertexElement
		{
			// The stream number that this VertexElement is associated with (generally set to 0).
			ushort_t Stream;

			// The offset, in bytes, of this element within the Vertex structure.
			ushort_t Offset;

			// The type of data this element is (FLOAT4, etc.)
			ubyte_t Type;

			// The method of interpretation by the "tessellator".
			ubyte_t Method;

			// How this element is intended to be used (position, color, etc.)
			ubyte_t Usage;

			// Allows multiple usages of this element.
			ubyte_t UsageIndex;

			// Initializes a new instance of VertexElement
			VertexElement(ushort_t offset, ubyte_t type, ubyte_t usage)
			{
				Stream = 0;
				Offset = offset;
				Type = type;
				Method = 0; // D3DDECLMETHOD_DEFAULT
				Usage = usage;
				UsageIndex = 0;
			}

			// Initializes a new instance of VertexElement
			VertexElement()
			{
				Stream = Offset = Type = Method = Usage = UsageIndex = 0;
			}

			// Initializes a new instance of Vertex Element
			VertexElement(ushort_t stream, ushort_t offset, ubyte_t type, ubyte_t method, ubyte_t usage, ubyte_t usageIndex)
			{
				Stream = stream;
				Offset = offset;
				Type = type;
				Method = method;
				Usage = usage;
				UsageIndex = usageIndex;
			}
		};
	}
}

#endif /* _TEKSTORM_VERTEXELEMENT_H */