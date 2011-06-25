/*
** This header defines the Mutex class, which is used for thread safety.
** In actuality, it is not a Mutex, but a Critical Section. This necessarily
** indicates a performance gain.
*/
#pragma once
#ifndef _TEKSTORM_MUTEX_H
#define _TEKSTORM_MUTEX_H
#include "../tekconfig.h"

namespace Tekstorm
{
	namespace Threads
	{
		///
		/// Represents a critical section that guarentees a resource will be accessed by only
		/// one thread at a time.
		///
		class Mutex
		{
		protected:
			///
			/// The underlying mutex or critical section handle.
			///
			TEKHANDLE hMutexHandle;

		public:
			///
			/// Initializes a new Mutex.
			///
			Mutex();

			///
			/// Destroys this Mutex and releases its underlying handle.
			///
			virtual ~Mutex();

			///
			/// Releases this resource. If the resource is currently locked, it will be unlocked and destroyed.
			///
			virtual void Release();

			///
			/// Locks the mutex. If the mutex is already locked, it waits for it to become unlocked.
			///
			virtual void Lock();

			///
			/// Unlocks the mutex.
			///
			virtual void Unlock();
		};
	}
}

#endif /* _TEKSTORM_MUTEX_H */