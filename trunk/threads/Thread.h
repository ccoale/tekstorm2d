/*
** Defines a class used to work with threads.
*/
#pragma once
#ifndef _TEKSTORM_THREAD_H
#define _TEKSTORM_THREAD_H
#include "../tekconfig.h"

namespace Tekstorm
{
	namespace Threads
	{
		///
		/// Foreward declaration of Thread class.
		///
		class Thread;

		///
		/// Foreward declaration of ThreadStartArgs structure.
		///
		struct ThreadStartArgs;

		///
		/// Function-pointer type to a standard thread function.
		///
		typedef void(*ThreadStart)(ThreadStartArgs*);

		///
		/// This structure stores information to be passed
		/// to the thread as an argument.
		///
		struct ThreadStartArgs
		{
			///
			/// The Thread object that started this thread.
			///
			Thread *pHandle;

			///
			/// Any user-data that the user decided to pass.
			///
			void *UserData;

			///
			/// The function pointer which these arguments were passed to.
			///
			ThreadStart pThreadFunc;
		};

		///
		/// Represents a Thread object. It is used
		/// to create and manage threads.
		class Thread
		{
		protected:
			///
			/// The underlying handle of this thread.
			///
			TEKHANDLE hThreadHandle;

			///
			/// The arguments that are passed to the thread function.
			///
			ThreadStartArgs *pThreadArgs;
		public:
			///
			/// Initializes a new instance of Thread.
			/// if start is true, then the thread is started immediately.
			///
			Thread(ThreadStart func, void *data = NULL, bool start=false);

			///
			/// Aborts this thread, destroying the handle.
			///
			virtual ~Thread();

			///
			/// Starts execution of the thread.
			///
			virtual bool Start();

			///
			/// Waits for this thread to finish before returning.
			///
			virtual void Join();

			///
			/// Aborts this thread.
			///
			virtual void Abort();
		};
	}
}

#endif /* _TEKSTORM_THREAD_H */