#include "Mutex.h"
#if defined(TEKSTORM_OS_WIN32) || defined(TEKSTORM_OS_WIN64)
#	define TEKSTORM_THREADS_WINDOWS
#	include <Windows.h>
#else
#	define TEKSTORM_THREADS_PTHREADS
#	include <pthread.h>
// for linux, -lpthreads
#endif

namespace Tekstorm
{
	namespace Threads
	{
		///
		/// Initializes a new Mutex.
		///
		Mutex::Mutex()
		{
#if defined(TEKSTORM_THREADS_WINDOWS)
			//CRITICAL_SECTION *pCritHandle = new CRITICAL_SECTION;
			//InitializeCriticalSection(pCritHandle);
			hMutexHandle = (TEKHANDLE)CreateMutex(NULL, false, NULL);
#elif defined(TEKSTORM_THREADS_PTHREADS)
			pthread_mutex_t *pCritHandle = new pthread_mutex_t;
			pthread_mutex_init(pCritHandle, NULL);
			hMutexHandle = (TEKHANDLE)pCritHandle;
#endif
		}

		///
		/// Destroys this Mutex and releases its underlying handle.
		///
		Mutex::~Mutex()
		{
			Release();
		}

		///
		/// Releases this resource. If the resource is currently locked, it will be unlocked and destroyed.
		///
		void Mutex::Release()
		{
			if (hMutexHandle)
			{
				Unlock();

#if defined(TEKSTORM_THREADS_WINDOWS)
				DeleteCriticalSection((LPCRITICAL_SECTION) hMutexHandle);
				delete (LPCRITICAL_SECTION)hMutexHandle;
#elif defined(TEKSTORM_THREADS_PTHREADS)
				pthread_mutex_destroy((pthread_mutex_t *) hMutexHandle);
				delete (pthread_mutex_t *)hMutexHandle;
#endif
			}
		}

		///
		/// Locks the mutex. If the mutex is already locked, it waits for it to become unlocked.
		///
		void Mutex::Lock()
		{
#if defined(TEKSTORM_THREADS_WINDOWS)
			EnterCriticalSection((LPCRITICAL_SECTION) hMutexHandle);
#elif defined(TEKSTORM_THREADS_PTHREADS)
			pthread_mutex_lock((pthread_mutex_t *) hMutexHandle);
#endif
		}

		///
		/// Unlocks the mutex.
		///
		void Mutex::Unlock()
		{
#if defined(TEKSTORM_THREADS_WINDOWS)
			LeaveCriticalSection((LPCRITICAL_SECTION) hMutexHandle);
#elif defined(TEKSTORM_THREADS_PTHREADS)
			pthread_mutex_unlock((pthread_mutex_t *) hMutexHandle);
#endif
		}
	}
}
