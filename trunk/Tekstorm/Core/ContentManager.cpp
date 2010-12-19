#define TEKBUILD
#include "ContentManager.h"

namespace Tekstorm
{
	namespace Core
	{
		ContentManager::ContentManager(Tekstorm::Graphics::IGraphics *pGraph)
		{
			graph = pGraph;
		}

		ContentManager::ContentManager(const ContentManager& other)
		{
			// attempt to copy the other graph
			graph = other.graph;

			std::list<ResourceInfo>::const_iterator it = other.resources.begin();
			for (; it != other.resources.end(); it++)
			{
				ResourceInfo info;
				info = *it;
				if (info.pRes)
					info.pRes = info.pRes->Copy();

				resources.push_back(info);
			}
		}

		ContentManager::~ContentManager()
		{
			HRESULT hr = Dispose();
			if (FAILED(hr))
			{
				TEKTHROW(hr);
			}
		}

		// Adds a resource to this list to be managed.
		// NOTE: once the resource is added to this list, it SHOULD NOT BE DESTROYED without FIRST
		// REMOVING IT FROM THIS MANAGER.
		HRESULT ContentManager::AddResource(IResource *pRes)
		{
			if (! pRes)
			{
				TEKTHROW(E_INVALIDARG);
				return E_INVALIDARG;
			}

			ResourceInfo info;
			info.bLoaded = true;
			info.bReload = pRes->CheckReload();
			info.pRes = pRes;

			resources.push_back(info);
			return S_OK;
		}

		// Removes a resource from this ContentManager.
		HRESULT ContentManager::RemoveResource(IResource *pRes)
		{
			std::list<ResourceInfo>::iterator it = resources.begin();
			for (; it != resources.end(); it++)
			{
				if ( (*it).pRes == pRes ) {
					resources.erase(it);
					return S_OK;
				}
			}

			return E_FAIL;
		}

		// Unloads all resources in this ContentManager (does not destroy them)
		HRESULT ContentManager::UnloadAll()
		{
			HRESULT hr;
			std::list<ResourceInfo>::iterator it = resources.begin();
			for (; it != resources.end(); it++)
			{
				hr = (*it).pRes->Unload();
				if (FAILED(hr)) {
					TEKTHROW(hr);
					return hr;
				}
			}

			return S_OK;
		}

		// Reloads all resources in this ContentManager
		HRESULT ContentManager::ReloadAll()
		{
			HRESULT hr;
			std::list<ResourceInfo>::iterator it = resources.begin();
			for (; it != resources.end(); it++)
			{
				hr = (*it).pRes->Load();
				if (FAILED(hr)) {
					TEKTHROW(hr);
					return hr;
				}
			}

			return S_OK;
		}

		// Returns the current reference count of this object.
		unsigned int ContentManager::GetRefCount()
		{
			return 1;
		}

		// Returns the underlying handle to the resource that is to be disposed.
		void *ContentManager::GetHandle()
		{
			return 0;
		}

		// Releases any resources that were used by this object.
		// If all goes as planned, S_OK is returned.
		HRESULT ContentManager::Dispose()
		{
			std::list<ResourceInfo>::iterator it = resources.begin();
			for (; it != resources.end(); it++)
			{
				if ((*it).pRes)
				{
					(*it).pRes->Unload();
					delete (*it).pRes;
				}

				resources.erase(it);
			}

			return S_OK;
		}
	}
}