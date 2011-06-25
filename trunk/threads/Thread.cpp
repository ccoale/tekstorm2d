#include "Thread.h"
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
		void *ProxyThreadFunc(void *args)
		{
			ThreadStartArgs *threadArgs = (ThreadStartArgs *)args;
			threadArgs->pThreadFunc(threadArgs);

			return NULL;
		}

		///
		/// Initializes a new instance of Thread.
		/// if start is true, then the thread is started immediately.
		///
		Thread::Thread(ThreadStart func, bool start)
		{
			if (func == NULL)
				return;

			pThreadArgs = new ThreadStartArgs;
			pThreadArgs->UserData = NULL;
			pThreadArgs->pHandle = this;
			pThreadArgs->pThreadFunc = func;

			if (start)
				Start();
		}

		///
		/// Aborts this thread, destroying the handle.
		///
		Thread::~Thread()
		{
			if (pThreadArgs)
			{
				Abort();
				delete pThreadArgs;
				pThreadArgs = NULL;
			}
		}

		///
		/// Starts execution of the thread.
		///
		bool Thread::Start()
		{
#if defined(TEKSTORM_THREADS_WINDOWS)
			hThreadHandle = (TEKHANDLE)CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)pThreadArgs->pThreadFunc, 
				(LPVOID)pThreadArgs, 0, NULL);
			if (! hThreadHandle)
				return false;
#else
			pthread_t thread;
			int succ = pthread_create(&thread, NULL, ProxyThreadFunc, pThreadArgs);
			if (succ != 0)
				return false;

			hThreadHandle = (TEKHANDLE)thread;
#endif

			return true;
		}

		///
		/// Waits for this thread to finish before returning.
		///
		void Thread::Join()
		{
#if defined(TEKSTORM_THREADS_WINDOWS)
			WaitForSingleObject((HANDLE)hThreadHandle, INFINITE);
#else
			pthread_join((pthread_t)hThreadHandle, NULL);
#endif
		}

		///
		/// Aborts this thread.
		///
		void Thread::Abort()
		{
#if defined(TEKSTORM_THREADS_WINDOWS)
			TerminateThread((HANDLE)hThreadHandle, 0);
			CloseHandle((HANDLE)hThreadHandle);
#else
			pthread_cancel((pthread_t)hThreadHandle);
#endif
		}
	}
}
