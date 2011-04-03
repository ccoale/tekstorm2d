#pragma once
#ifndef _TEKSTORM_MEMORYSTREAM_H
#define _TEKSTORM_MEMORYSTREAM_H
#include "IStream.h"

namespace Tekstorm
{
	namespace IO
	{
		class MemoryStream : public IStream
		{
		private:
			/*
			** Whether or not this memory stream expands the data that it has allocated.
			*/
			bool expands;

			/*
			** Current index into the buffer.
			*/
			int index;

			/*
			** The current allocated size of the buffer.
			*/
			int size;

			/*
			** The current readable length of the buffer.
			*/
			int length;

			/*
			** The data buffer pointer.
			*/
			char *buffer;

			/*
			** Whether or not the stream is open
			*/
			bool open;

			/*
			** Reallocates the buffer to be a new size
			*/
			void Realloc(int newSize)
			{
				char *temp = new char[newSize];
				memcpy(temp, buffer, length);
				delete[] buffer;
				
				buffer = temp;
				size = newSize;
			}
		public:
			/*
			** Initializes a non-expandable MemoryStream.
			** Parameters
			**	destBuff		- the constant-sized buffer this Stream operates upon
			**	size			- the size of the buffer
			** Returns
			**	nothing
			*/
			MemoryStream(char *destBuff, int _size) : expands(false), size(_size),
				length(_size), index(0)
			{
				if (! destBuff || !_size)
				{
					throw Exception("invalid argument in MemoryStream constructor");
				}

				buffer = destBuff;
				open = true;
			}

			/*
			** Initializes an expandable MemoryStream.
			** Parameters
			**	size		- the initialize size of the buffer
			** Returns
			**	nothing
			*/
			MemoryStream(int _size = 1024) : expands(true), size(_size),
				length(0), index(0)
			{
				if (! _size)
				{
					throw Exception("invalid argument in MemoryStream constructor");
				}

				buffer = new char[size];
				open = true;
			}

			/*
			** Gets a value indicating whether or not this stream supports reading.
			** Parameters
			**	none
			** Returns
			**	True if the stream supports reading.
			*/
			virtual bool CanRead() const { return open; }

			/*
			** Gets a value indicating whether or not this stream supports writing.
			** Parameters
			**	none
			** Returns
			**	True if the stream supports writing.
			*/
			virtual bool CanWrite() const { return open; }

			/*
			** Gets a value indicating whether or not this stream supports seeking.
			** Parameters
			**	none
			** Returns
			**	True if the stream supports seeking.
			*/
			virtual bool CanSeek() const { return open; }

			/*
			** If seeking is supported, gets a value indicating the current length of this stream.
			** Parameters
			**	none
			** Returns
			**	the length of this stream. A value of -1 indicates that the stream does not support seeking or
			**	another error occurred.
			*/
			virtual int GetLength() const { return length; }

			/*
			** If seeking is supported, gets a value indicating the current position of this stream.
			** Parameters
			**	none
			** Returns
			**	the current position of this stream. A value of -1 indicates that the stream does not suport seeking or
			**	another error occurred.
			*/
			virtual int GetPosition() const { return index; }

			/*
			** Gets the underlying resource handle, if one exists.
			** If no handle exists, this should return 0.
			** Therefore, 0 does not necessarily indicate a failure.
			** Parameters
			**	none
			** Returns
			**	the handle to the underlying resource, or 0 if none
			*/
			void *GetHandle() const { return buffer; }

			/*
			** Closes the underlying resource handle, if one exists.
			** Once the close method is called, no other methods on
			** this class should be called.
			** Parameters
			**	none
			** Returns
			**	nothing
			*/
			virtual void Close() 
			{ 
				if (expands)
				{
					if (buffer) 
					{ 
						delete[] buffer;
					}
				}

				buffer = 0;
				index = 0;
				length = 0;
				expands = false;
				open = false;
			}

			/*
			** Writes all bytes from this stream to another stream.
			** Parameters
			**	destination		- the destination stream
			** Returns
			**	nothing
			*/
			virtual void CopyTo(IStream &destination) const
			{ 
				destination.Write(buffer, 0, length);
			}

			/*
			** Causes any unbuffered data in the buffer to be written.
			** Parameters
			**	none
			** Returns
			**	nothing
			*/
			virtual void Flush() 
			{ 

			}

			/*
			** Reads an array of bytes from the stream, advancing the position in the stream by the number of bytes read.
			** Parameters
			**	destination		- the destination array
			**	offset			- the offset from destination where bytes will begin being read to
			**	count			- the number of bytes to read
			** Returns
			**	the actual number of bytes read. This value can be less than what was requested.
			**	a value of -1 indicates an error. A value of 0 indiciates no more data to read.
			*/
			virtual int Read(char *destination, int offset, int count) 
			{ 
				/* calculate actual number of bytes available to read */
				int available = length - index;
				if (available <= 0)
					return 0; // nothing to read

				/* set the amount to read only to that which is available */
				if (available < count)
					count = available;

				memcpy(destination, &buffer[index], count);
				index += count;

				return count;
			}

			/*
			** Reads a single byte from the stream, advancing the position in the stream by 1.
			** Parameters
			**	none
			** Returns
			**	the byte read, as an int. A value of -1 indicates an error (or end of stream)
			*/
			virtual int ReadByte() 
			{ 
				/* there is nothing to read */
				if (length - index <= 0)
					return -1;

				return (int)buffer[index++];
			}

			/*
			** Sets the position in the stream as an offset to the given origin.
			** Parameters
			**	offset		- offset
			**	origin		- origin to offset
			** Returns
			**	the new position in the stream
			*/
			virtual int Seek(int offset, SeekOrigin origin) 
			{
				int newIndex = 0;
				switch(origin)
				{
				case SEEK_BEGIN: newIndex = offset; break;
				case SEEK_CURRENT: newIndex = index + offset; break;
				case SEEK_END: newIndex = length - offset; break;
				default:
					throw Exception("unsupported SeekOrigin value");
				}

				if (expands)
				{
					if (newIndex < 0)
						throw Exception("the new position cannot be negative");

					/* reallocate the stream */
					Realloc(newIndex + 1024);
					index = newIndex;
					length = index;
				}
				else
				{
					if (newIndex < 0 || newIndex > length)
						throw Exception("the new position cannot be negative or greater than length");

					index = newIndex;
				}

				return index; 
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
			virtual void Write(const char *_buffer, int offset, int count) 
			{
				if (! buffer || !count || (offset < 0))
					throw Exception("invalid argument in MemoryStream::Write");

				if (index + count > size)
				{
					Realloc(size + count + 1024);
				}

				memcpy(&buffer[index], &_buffer[offset], count);
				length += count;
				index += count;
			}

			/*
			** Writes a single byte to the stream at the current position.
			** Parameters
			**	value		- the value to write
			** Returns
			**	nothing
			*/
			virtual void WriteByte(char value) 
			{
				if (index + 1 > size)
				{
					if (! expands)
						throw Exception("MemoryStream cannot store any more data");

					Realloc(size + 1024);
					length = size + 1;
				}

				buffer[index++] = value;
			}
		};
	}
}

#endif /* _TEKSTORM_MEMORYSTREAM_H */