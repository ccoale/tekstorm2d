#ifndef _TEKSTORM_VERTEXDECLARATION_H
#define _TEKSTORM_VERTEXDECLARATION_H
#include "../TekstormDecl.h"
#include "VertexElement.h"

namespace Tekstorm
{
	namespace Graphics
	{
		class TEKDECL VertexDeclaration
		{
		private:
			void *vertDecl; // the underyling vertex declaration

		public:
			VertexDeclaration(const Graphics *graph, const VertexElement *elements);
		};
	}
}

#endif /* _TEKSTORM_VERTEXDECLARATION_H */