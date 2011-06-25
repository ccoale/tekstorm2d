/*
** This header defines an interface that all streams must inherit.
*/
#pragma once
#ifndef _TEKSTORM_ISTREAM_H
#define _TEKSTORM_ISTREAM_H
#include "../tekconfig.h"

namespace Tekstorm
{
	namespace IO
	{
		///
		/// Holds constants for the origin of a seek.
		///
		class SeekOrigin
		{
		public:
			///
			/// Offset is from the beginning of the stream.
			///
			static const int Begin;

			///
			/// Offset is from the end of the stream, in reverse.
			///
			static const int End;

			///
			/// Offset is from the current position in the stream.
			///
			static const int Current;
		};

		///
		/// Holds information about the result of an operation.
		///
		class StreamResult
		{
		public:
			///
			/// No error
			///
			static const int OK;

			///
			/// The requested operation is not supported.
			///
			static const int NotSupported;

			///
			/// No data is available
			///
			static const int NotAvailable;
		};

		///
		/// The base stream interface
		///
		class IStream
		{
		public:
			///
			/// Gets the length, in bytes, of this stream. If this function
			/// is not supported by this stream, the function will return -1.
			///
			virtual int GetLength() const;// { return -1; }

			///
			/// Gets the current position, in bytes, of this stream. If this function
			/// is not supported by this stream, the function will return -1.
			///
			virtual int GetPosition() const;// { return -1; }

			///
			/// Seeks the stream. If this function is not supported by this stream,
			/// the function will return -1. If the function succeeds, the return
			/// value is the new position as an offset from the beginning of the stream.
			///
			virtual int Seek(int offset, int origin = SeekOrigin::Begin);// { return -1; }

			///
			/// Closes this stream and destroys all resources it has allocated.
			///
			virtual void Close();

			///
			/// Reads a single byte from the stream, advancing the position by 1.
			/// Returns -1 if this operation is not supported. Otherwise, returns the 
			/// byte that was read.
			///
			virtual int ReadByte();

			///
			/// Reads a series of bytes from the stream, advancing the position accordingly.
			/// Returns -1 if this operation is not supported. Otherwise, returns the
			/// number of bytes that were actually read.
			/// destination		- the destination buffer
			///	offset			- the offset, in bytes, into the destination buffer to start writing
			///	length			- the number of bytes to read from the stream
			///
			virtual int Read(void *destination, int offset, int length);

			///
			/// Returns the first byte from the stream, but does not advance the position.
			/// Returns -1 if this operation is not supported. Returns -2 if no data is available to peek.
			///
			virtual int Peek();

			///
			/// Writes a byte to the stream, and advances the position by 1.
			/// Returns -1 if this operation is not supported, otherwise it returns the new position
			/// of the stream pointer.
			/// 
			virtual int WriteByte(unsigned char value);

			///
			/// Writes a series of bytes to the stream, and advances the position accordingly.
			/// Returns -1 if this operation is not supported, otherwise it returns the new position
			/// of the stream pointer.
			/// source		- the source buffer
			///	offset		- the offset into the source buffer to begin reading
			/// length		- the number of bytes to read from the source buffer.
			///
			virtual int Write(const void *source, int offset, int length);
		};
	}
}

#endif /* _TEKSTORM_ISTREAM_H */
