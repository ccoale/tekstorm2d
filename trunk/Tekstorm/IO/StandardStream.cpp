#define TEKSTORM_BUILD
#include "StandardStream.h"

namespace Tekstorm
{
	namespace IO
	{
		/*
		** Causes any unbuffered data in the buffer to be written.
		** Parameters
		**	none
		** Returns
		**	nothing
		*/
		void StandardStream::Flush()
		{
			fflush(stdin);
			fflush(stdout);
		}

		/*
		** Reads an array of bytes from the stream, advancing the position in the stream by the number of bytes read.
		** Parameters
		**	destination		- the destination array
		**	offset			- the offset from destination where bytes will begin being read to
		**	count			- the number of bytes to read
		** Returns
		**	the actual number of bytes read. This value can be less than what was requested.
		**	a value of -1 indicates an error.
		*/
		int StandardStream::Read(char *destination, int offset, int count)
		{
			return fread((destination + offset), 1, count, stdin);
		}

		/*
		** Reads a single byte from the stream, advancing the position in the stream by 1.
		** Parameters
		**	none
		** Returns
		**	the byte read, as an int. A value of -1 indicates an error (or end of stream)
		*/
		int StandardStream::ReadByte()
		{
			char c = fgetc(stdin);
			return (int)c;
		}

		/*
		** Writes the given array to this stream at its current position.
		** Parameters
		**	buffer		- the array of bytes to write
		**	offset		- the offset in buffer to being writing from
		**	count		- the number of bytes to write
		** Returns
		**	nothing
		*/
		void StandardStream::Write(const char *buffer, int offset, int count)
		{
			fwrite((buffer + offset), 1, count, stdout);
		}

		/*
		** Writes a single byte to the stream at the current position.
		** Parameters
		**	value		- the value to write
		** Returns
		**	nothing
		*/
		void StandardStream::WriteByte(char value)
		{
			fputc(value, stdout);
		}
	}
}