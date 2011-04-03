/*
**	This header implements an exception class that is used throughout
** the entire SDK. The exception class may be inherited and overrided.
*/
#ifndef _TEK_EXCEPTION_H
#define _TEK_EXCEPTION_H
#include "TekDecl.h"

#define TEKTHROW(id) \
	throw Tekstorm::Core::Exception(id, (unsigned int)(__LINE__), (const char *)(__FILE__))

namespace Tekstorm
{
	namespace Core
	{
		class TEKAPI Exception
		{
		private:
			// The line in which the exception was thrown
			unsigned int nLine;

			// The ID of the error
			HRESULT nErr;

			// The path to the file that threw the exception
			char srcFile[128];

			// The user-defined message of the exception
			char message[256];
		public:
			Exception();
			Exception(const Exception& ex);
			Exception(const char *msg, HRESULT id, unsigned int line = 0, const char *file = "");
			Exception(HRESULT id, unsigned int line = 0, const char *file = "");

			// Gets the string portion of this message
			const char *GetMessage() const;

			// Gets the error ID of this message
			HRESULT GetErrorId() const;

			// Gets the source file from which this error was generated
			const char *GetSourceFile() const;

			// Gets the line on which this error was generated
			unsigned int GetErrorLine() const;

			// Returns a fully formatted string that can be displayed in a messagebox. Format looks as follows:
			// Error <english name> (<hex error code>) in <file path> on line <line number>.
			// <error string>
			//
			// pBuff is a pointer to a pre-allocated buffer. It should hold enough
			// characters to store the entire message. A safe amount is 1,024. If the size is too small,
			// pBuff will not be set, and the "buffSize" pointer will store the value of the exact (which
			// includes the NULL value) buffer size required.
			// If pBuff is NULL, then buffSize is store the necessary size of the buffer.
			bool GetString(char *pBuff, unsigned int *buffSize = 0);

			// Displays an error box
			void DisplayErrorBox(const char *title);
		};
	}
}

#endif /* _TEK_EXCEPTION_H */