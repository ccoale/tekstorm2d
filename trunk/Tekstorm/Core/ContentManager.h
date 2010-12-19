#ifndef _CONTENTMANAGER_H
#define _CONTENTMANAGER_H
#include "IResource.h"
#include <list>

namespace Tekstorm
{
	namespace Core
	{
		class TEKAPI ContentManager : public IDisposable
		{
		private:
			struct ResourceInfo {
				// a pointer to the resource
				IResource *pRes;

				// whether or not the resource is currently loaded
				bool bLoaded;

				// whether or not this resource needs to be unloaded and reloaded
				// on a device reset (i.e. text files, audio files, etc. do not)
				bool bReload;
			};

			// the list of resources
			std::list<ResourceInfo> resources;

			// the reference count of this ContentManager, once it hits 0 -- Dispose is called.
			unsigned int nRefCount;

			Tekstorm::Graphics::IGraphics *graph;
		public:
			ContentManager(Tekstorm::Graphics::IGraphics *pGraph);
			// DO NOT CALL THE COPY CONSTRUCTOR
			// UNLESS REQUIRED. THE COPY CONSTRUCTOR
			// MAKES A COPY OF -EVERY- RESOURCE CURRENTLY
			// BEING MANAGED.
			ContentManager(const ContentManager& other);
			~ContentManager();

			// Loads the given resource type from a file on disk.
			template <class _Tx> _Tx *Load(const char *szFilePath)
			{
				_Tx *pRes = new _Tx();
				if (! pRes)
				{
					TEKTHROW(E_OUTOFMEMORY);
					return NULL;
				}

				if (FAILED(pRes->LoadFromFile(graph, szFilePath)))
				{
					TEKTHROW(E_FAIL);
					return NULL;
				}

				ResourceInfo info;
				info.bLoaded = true;
				info.bReload = pRes->CheckReload();
				info.pRes = pRes;
				resources.push_back(info);

				return pRes;
			}

			// Loads the given resource type from a file in memory.
			template <class _Ty> _Ty *Load(const char *pFileData, unsigned int size)
			{
				_Tx *pRes = new _Tx();
				if (! pRes)
				{
					TEKTHROW(E_OUTOFMEMORY);
					return NULL;
				}

				if (FAILED(pRes->LoadFromMemory(graph, pFileData, size)))
				{
					TEKTHROW(E_FAIL);
					return NULL;
				}

				ResourceInfo info;
				info.bLoaded = true;
				info.bReload = pRes->CheckReload();
				info.pRes = pRes;
				resources.push_back(info);

				return pRes;
			}

			// Adds a resource to this list to be managed.
			// NOTE: once the resource is added to this list, it SHOULD NOT BE DESTROYED without FIRST
			// REMOVING IT FROM THIS MANAGER.
			HRESULT AddResource(IResource *pRes);

			// Removes a resource from this ContentManager.
			HRESULT RemoveResource(IResource *pRes);

			// Unloads all resources in this ContentManager (does not destroy them)
			HRESULT UnloadAll();

			// Reloads all resources in this ContentManager
			HRESULT ReloadAll();

			// Returns the current reference count of this object.
			virtual unsigned int GetRefCount();

			// Returns the underlying handle to the resource that is to be disposed.
			void *GetHandle();

			// Releases any resources that were used by this object.
			// If all goes as planned, S_OK is returned.
			HRESULT Dispose();
		};
	}
}

#endif /* _CONTENTMANAGER_H */