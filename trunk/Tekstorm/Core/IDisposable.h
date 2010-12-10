/*
**	This header defines an interface for all disposable objects.
** This interface is abstract, and if implemented, MUST be filled
** out completely. Most volatile objects will inherit this interface.
*/
#ifndef _TEKSTORM_IDISPOSABLE_H
#define _TEKSTORM_IDISPOSABLE_H
#include "TekDecl.h"

namespace Tekstorm
{
	namespace Core
	{
		// Interface that defines a Dispose method, which on call, will 
		// destroy any resources allocated by this object.
		// Almost all resources will inherit IDisposable.
		// The interface implements a reference count as well.
		class TEKAPI IDisposable
		{
		public:
			// Returns the current reference count of this object.
			virtual unsigned int GetRefCount() = 0;

			// Returns the underlying handle to the resource that is to be disposed.
			virtual void *GetHandle() = 0;

			// Releases any resources that were used by this object.
			// If all goes as planned, S_OK is returned.
			virtual HRESULT Dispose() = 0;
		};
	}
}

#endif /* _TEKSTORM_IDISPOSABLE_H */