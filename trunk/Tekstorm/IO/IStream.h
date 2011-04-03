#pragma once
#ifndef _TEKSTORM_ISTREAM_H
#define _TEKSTORM_ISTREAM_H
#include "../BuildConf.h"
#include "SeekOrigin.h"
#include "../Exception.h"

namespace Tekstorm
{
	namespace IO
	{
		/*
		** The base IStream class that should be inherited by all standard streams.
		** This class declares methods that all streams should define.
		*/
		class IStream
		{
		public:
			IStream() { }
			virtual ~IStream() { }

			/*
			** Gets a value indicating whether or not this stream supports reading.
			** Parameters
			**	none
			** Returns
			**	True if the stream supports reading.
			*/
			virtual bool CanRead() const { return false; }

			/*
			** Gets a value indicating whether or not this stream supports writing.
			** Parameters
			**	none
			** Returns
			**	True if the stream supports writing.
			*/
			virtual bool CanWrite() const { return false; }

			/*
			** Gets a value indicating whether or not this stream supports seeking.
			** Parameters
			**	none
			** Returns
			**	True if the stream supports seeking.
			*/
			virtual bool CanSeek() const { return false; }

			/*
			** If seeking is supported, gets a value indicating the current length of this stream.
			** Parameters
			**	none
			** Returns
			**	the length of this stream. A value of -1 indicates that the stream does not support seeking or
			**	another error occurred.
			*/
			virtual int GetLength() const { return -1; }

			/*
			** If seeking is supported, gets a value indicating the current position of this stream.
			** Parameters
			**	none
			** Returns
			**	the current position of this stream. A value of -1 indicates that the stream does not suport seeking or
			**	another error occurred.
			*/
			virtual int GetPosition() const { return -1; }

			/*
			** Gets the underlying resource handle, if one exists.
			** If no handle exists, this should return 0.
			** Therefore, 0 does not necessarily indicate a failure.
			** Parameters
			**	none
			** Returns
			**	the handle to the underlying resource, or 0 if none
			*/
			virtual void *GetHandle() const { return 0; }

			/*
			** Closes the underlying resource handle, if one exists.
			** Once the close method is called, no other methods on
			** this class should be called.
			** Parameters
			**	none
			** Returns
			**	nothing
			*/
			virtual void Close() { }

			/*
			** Writes all bytes from this stream to another stream.
			** Parameters
			**	destination		- the destination stream
			** Returns
			**	nothing
			*/
			virtual void CopyTo(IStream &destination) const { }

			/*
			** Causes any unbuffered data in the buffer to be written.
			** Parameters
			**	none
			** Returns
			**	nothing
			*/
			virtual void Flush() { }

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
			virtual int Read(char *destination, int offset, int count) { return -1; }

			/*
			** Reads a single byte from the stream, advancing the position in the stream by 1.
			** Parameters
			**	none
			** Returns
			**	the byte read, as an int. A value of -1 indicates an error (or end of stream)
			*/
			virtual int ReadByte() { return -1; }

			/*
			** Sets the position in the stream as an offset to the given origin.
			** Parameters
			**	offset		- offset
			**	origin		- origin to offset
			** Returns
			**	the new position in the stream
			*/
			virtual int Seek(int offset, SeekOrigin origin) { return 0; }

			/*
			** Writes the given array to this stream at its current position.
			** Parameters
			**	buffer		- the array of bytes to write
			**	offset		- the offset in buffer to being writing from
			**	count		- the number of bytes to write
			** Returns
			**	nothing
			*/
			virtual void Write(const char *buffer, int offset, int count) { }

			/*
			** Writes a single byte to the stream at the current position.
			** Parameters
			**	value		- the value to write
			** Returns
			**	nothing
			*/
			virtual void WriteByte(char value) { }
		};
	}
}


#endif /* _TEKSTORM_ISTREAM_H */