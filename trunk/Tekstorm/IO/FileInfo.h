#pragma once
#ifndef _TEKSTORM_FILEINFO_H
#define _TEKSTORM_FILEINFO_H
#include "../BuildConf.h"
#include "FileNotFoundException.h"

namespace Tekstorm
{
	namespace IO
	{
		class TEKAPI FileInfo
		{
		private:
			/*
			** The file system attributes of the given file.
			*/
			unsigned int dwAttributes;

		public:
			/*
			** Initializes a new instance of FileInfo
			** Parameters
			**	filePath		- the path to the file to get information from
			** Returns
			**	nothing; however, a FileNotFoundException may be thrown
			*/
			FileInfo(const std::string &filePath);

			/*
			** Returns whether or not the file is an archive.
			*/
			inline bool IsArchive()
			{
				return dwAttributes & 0x20 == 0x20;
			}

			/*
			** Returns whether or not the file is compressed.
			*/
			inline bool IsCompressed()
			{
				return dwAttributes & 0x800 == 0x800;
			}

			/*
			** Returns whether or not the file is a device.
			*/
			inline bool IsDevice()
			{
				return dwAttributes & 0x40 == 0x40;
			}

			/*
			** Returns whether or not the file is a directory.
			*/
			inline bool IsDirectory()
			{
				return dwAttributes & 0x10 == 0x10;
			}

			/*
			** Returns whether or not the file is encrypted.
			*/
			inline bool IsEncrypted()
			{
				return dwAttributes & 0x4000 == 0x4000;
			}

			/*
			** Returns whether or not the file is hidden
			*/
			inline bool IsHidden()
			{
				return dwAttributes & 0x02 == 0x02;
			}

			/*
			** Returns whether or not the file is a "normal" file.
			*/
			inline bool IsNormal()
			{
				return dwAttributes & 0x80 == 0x80;
			}

			/*
			** Whether or not the file is indexed by the Windows indexing service.
			*/
			inline bool IsIndexed()
			{
				return ! (dwAttributes & 0x2000 == 0x2000);
			}

			/*
			** Returns whether or not the file is ReadOnly.
			*/
			inline bool IsReadOnly()
			{
				return dwAttributes & 0x01 == 0x01;
			}

			/*
			** Returns whether or not the file is a reparse point.
			*/
			inline bool IsReparsePoint()
			{
				return dwAttributes & 0x400 == 0x400;
			}

			/*
			** Returns whether or not the file is a sparse file.
			*/
			inline bool IsSparseFile()
			{
				return dwAttributes & 0x200 == 0x200;
			}

			/*
			** Returns whether or not the file is a system file.
			*/
			inline bool IsSystemFile()
			{
				return (dwAttributes & 0x04) == 0x04;
			}

			/*
			** Returns whether or not the file is a temporary file
			*/
			inline bool IsTemporaryFile()
			{
				return dwAttributes & 0x100 == 0x100;
			}

		};
	}
}

#endif /* _TEKSTORM_FILEINFO_H */