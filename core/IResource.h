#pragma once
#ifndef _TEKSTORM_IRESOURCE_H
#define _TEKSTORM_IRESOURCE_H
#include "../tekconfig.h"
#include "IDisposable.h"

namespace Tekstorm
{
	namespace Core
	{
		///
		/// All disposable resources must inherit this class.
		///
		class IResource : public IDisposable
		{
		public:
			///
			/// Loads a resource from file.
			///
			virtual bool LoadFromFile(const std::string &filePath, void *args = nullptr) = 0;

			///
			/// Loads a resource from memory.
			///
			virtual bool LoadFromMemory(const char *memory, int32_t size, void *args = nullptr) = 0;

			///
			/// Destroys this resource. Once destroyed, it cannot be re-used unless reloaded.
			///
			virtual bool Dispose() = 0;

			///
			/// Returns true if this resource type is volatile (i.e. should be destroyed and re-created
			/// when D3D loses its device.)
			///
			virtual bool IsVolatile() const = 0;
		};
	}
}

#endif /* _TEKSTORM_IRESOURCE_H */