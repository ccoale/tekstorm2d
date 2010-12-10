#define TEKBUILD
#include "Exception.h"

namespace Tekstorm
{
	namespace Core
	{
		Exception::Exception()
		{
			nLine = 0;
			nErr = S_OK;
			srcFile[0] = 0; //empty string
			message[0] = 0; //empty string
		}

		Exception::Exception(const Exception& ex)
		{
			nLine = ex.nLine;
			nErr = ex.nErr;
			strcpy_s(srcFile, 128, ex.srcFile);
			strcpy_s(message, 256, ex.message);
		}

		Exception::Exception(const char *msg, HRESULT id, unsigned int line, const char *file)
		{
			if (msg) strcpy_s(message, 256, msg);
			else message[0] = 0;
			if (file) strcpy_s(srcFile, 128, file);
			else srcFile[0] = 0;

			nErr = id;
			nLine = line;
		}

		Exception::Exception(HRESULT id, unsigned int line, const char *file)
		{
			strcpy_s(message, 256, (const char *)DXGetErrorDescriptionA(id));
			if (file) strcpy_s(srcFile, 128, file);
			else srcFile[0] = 0;

			nErr = id;
			nLine = line;
		}

		// Gets the string portion of this message
		const char * Exception::GetMessage() const
		{
			return (const char *)message;
		}

		// Gets the error ID of this message
		HRESULT Exception::GetErrorId() const
		{
			return nErr;
		}

		// Gets the source file from which this error was generated
		const char * Exception::GetSourceFile() const
		{
			return (const char *)srcFile;
		}

		// Gets the line on which this error was generated
		unsigned int Exception::GetErrorLine() const
		{
			return nLine;
		}

		// Returns a fully formatted string that can be displayed in a messagebox. Format looks as follows:
		// Error <english name> (<hex error code>) in <file path> on line <line number>.
		// <error string>
		//
		// pBuff is a pointer to a pre-allocated buffer. It should hold enough
		// characters to store the entire message. A safe amount is 1,024. If the size is too small,
		// pBuff will not be set, and the "buffSize" pointer will store the value of the exact (which
		// includes the NULL value) buffer size required.
		// If pBuff is NULL, then buffSize is store the necessary size of the buffer.
		bool Exception::GetString(char *pBuff, unsigned int *buffSize)
		{
			// we need to determine the required size of the buffer.
			unsigned int requiredSize = 0;
			unsigned int provSize = 0;
			if (! buffSize)
				return false;

			provSize = *buffSize;

			unsigned int msgLen = strlen(message);
			unsigned int srcFileLen = strlen(srcFile);
			unsigned int lineLen = 0;
			unsigned int errLen = 0;
			unsigned int errNameLen = 0;
			//unsigned int errDescLen = 0;
			
			// first we need to lookup the name of the HRESULT error.
			const char *errName = (const char *)DXGetErrorStringA(nErr);
			errNameLen = strlen(errName);

			char errNumText[11];
			errLen = sprintf_s(errNumText, 11, "%d", (unsigned int)nErr);

			char lineNumText[11];
			lineLen = sprintf_s(lineNumText, 11, "%d", nLine);


			// now we need to get the error description
			//const char *errDesc = (const char *)DXGetErrorDescriptionA(nErr);
			//errDescLen = strlen(errDesc);

			// Error: <name>(<id>)\r\n
			// File: <srcfile>\r\n
			// Line: <linenumber>
			// \r\n
			// message
			requiredSize = (7 + errNameLen + 1 + errLen + 1 + 2)
						  +(6 + srcFileLen + 2)
						  +(6 + lineLen + 2)
						  +(2 + msgLen)
						  +1; // NULL character

			if (requiredSize <= provSize) {
				// we can copy!
				sprintf_s(pBuff, requiredSize, "Error: %s(%s)\r\nFile: %s\r\nLine: %s\r\n\r\n%s",
					errName, errNumText, srcFile, lineNumText, message);

				// let the user know how long the message is
				*buffSize = requiredSize;

				return true;
			} else {
				*buffSize = requiredSize;

				return false;
			}
		}

		// Displays an error box
		void Exception::DisplayErrorBox(const char *title)
		{
			char *tmpBuffer = new char[1024]; // try a 1,024 buffer
			unsigned int buffSize = 1024;
			if (! GetString(tmpBuffer, &buffSize)) {
				// we need to try again with the new buffSize
				delete[] tmpBuffer;
				tmpBuffer = new char[buffSize];
				GetString(tmpBuffer, &buffSize);
			}

			MessageBoxA(HWND_DESKTOP, tmpBuffer, title, MB_OK|MB_ICONERROR);
			delete[] tmpBuffer;
		}
	}
}