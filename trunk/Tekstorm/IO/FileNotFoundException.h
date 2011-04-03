#pragma once
#ifndef _TEKSTORM_FILENOTFOUNDEXCEPTION_H
#define _TEKSTORM_FILENOTFOUNDEXCEPTION_H
#include "../Exception.h"

namespace Tekstorm
{
	namespace IO
	{
		/*
		** A general exception class used to indicate that a file does not exist
		*/
		class FileNotFoundException : public Exception
		{
		protected:
			/*
			** The file path that was requested but does not exist.
			*/
			std::string FilePath;

		public:
			/*
			** Initializes a new instance of FileNotFoundException
			** Parameters
			**	the requested file path that does not exist
			** Returns
			**	nothing
			*/
			FileNotFoundException(const std::string &file) : Exception("file not found"), FilePath(file)
			{
			}

			/*
			** Returns the file path that was requested
			** Parameters
			**	none
			** Returns
			**	the requested file path
			**/
			std::string GetFilePath()
			{
				return FilePath;
			}
		};
	}
}

#endif /* _TEKSTORM_FILENOTFOUNDEXCEPTION_H */