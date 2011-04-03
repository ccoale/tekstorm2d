#define TEKSTORM_BUILD
#include "FileInfo.h"
#include <Windows.h>

namespace Tekstorm
{
	namespace IO
	{
		/*
		** Initializes a new instance of FileInfo
		** Parameters
		**	filePath		- the path to the file to get information from
		** Returns
		**	nothing; however, a FileNotFoundException may be thrown
		*/
		FileInfo::FileInfo(const std::string &filePath) : dwAttributes(0)
		{
			HANDLE hFile = CreateFileA(filePath.c_str(), 
				0, 0, NULL, OPEN_EXISTING, 0, NULL);
			if (hFile == INVALID_HANDLE_VALUE)
			{
				if (GetLastError() == ERROR_FILE_NOT_FOUND)
					throw FileNotFoundException(filePath);
				else
					throw Exception("unknown error occurred while trying to open file", GetLastError());
			}

			BY_HANDLE_FILE_INFORMATION fileInformation;
			if(! GetFileInformationByHandle(hFile, &fileInformation))
				throw Exception("unable to extract file information", GetLastError());

			dwAttributes = fileInformation.dwFileAttributes;
			CloseHandle(hFile);
		}
	}
}