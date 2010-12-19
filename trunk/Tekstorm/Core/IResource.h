/*
**
** All manageable resources MUST inherit IResource. It provides a common interface
** for all resources, and is required if a resource is to be managed.
*/
#ifndef _IRESOURCE_H
#define _IRESOURCE_H
#include "TekDecl.h"
#include "IDisposable.h"
#include "../Graphics/IGraphics.h"

namespace Tekstorm
{
	namespace Core
	{
		// Resources should have a member that stores the path to a file and/or the file contents and size,
		// so that it can reload data when Load() is called.
		class IResource : public IDisposable
		{
		public:
			IResource() { }
			virtual IResource() { }

			// This method is called when the resource needs to be loaded for the first time, by file on disk.
			virtual HRESULT LoadFromFile(Tekstorm::Graphics::IGraphics *pGraph, const char *szFile) = 0;

			// This method is called when the resource needs to be loaded for the first time, by file in memory.
			virtual HRESULT LoadFromMemory(Tekstorm::Graphics::IGraphics *pGraph, const char *pFileData, unsigned int size) = 0;

			// Creates an exact copy of this resource, and returns an IResource handle to it.
			// NOTE: the new resource is NOT automagically managed by a ContentManager. It 
			// must manually be added.
			virtual IResource *Copy() = 0;

			// Returns whether or not a resource needs to be reloaded on a lost device.
			virtual bool CheckReload() = 0;

			// This method is called when the resource needs to be reloaded after
			// being unloaded.
			virtual HRESULT Load() = 0;

			// This method is called when the resource needs to be temporarily unloaded.
			// This method works in accord with Load. THIS METHOD SHOULD NOT COMPLETELY
			// DESTROY A RESOURCE -- "Dipose" IS USED FOR THAT.
			virtual HRESULT Unload() = 0;

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

#endif /* _IRESOURCE_H */