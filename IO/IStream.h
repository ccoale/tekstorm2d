#pragma once
#ifndef _TEKSTORM_ISTREAM_H
#define _TEKSTORM_ISTREAM_H
#include "../tekconfig.h"

namespace Tekstorm
{
	namespace IO
	{
		///
		/// The parent IStream class that all streams must inherit
		/// and implement.
		///
		class IStream
		{
		public:
			///
			/// Returns whether or not this stream can be read from.
			///
			virtual bool CanRead() const = 0;

			///
			/// Returns whether or not this stream can be written to.
			///
			virtual bool CanWrite() const = 0;

			///
			/// Returns whether or not this stream can seek.
			///
			virtual bool CanSeek() const = 0;

			///
			/// Returns the length, in bytes, of this stream. If
			/// the length is not supported, the result is -1.
			///
			virtual int32_t GetLength() const = 0;

			///
			/// Reads a single byte from the stream, and advances the
			/// current stream pointer forward by 1 byte.
			/// The result is the read byte.
			///
			virtual int32_t ReadByte() const = 0;

			///
			/// Reads an array of bytes from the stream, and advances the
			/// current stream pointer forward by the number of bytes
			/// that were actually read.
			/// The return value is the number of bytes that were actually read.
			/// count - the number of bytes to read from the stream
			/// offset - the offset into the destination buffer to begin reading to
			///
			virtual int32_t Read(char *pDestination, int32_t count, int32_t offset = 0) = 0;

			///
			/// Writes a single byte to the stream, and advances the current
			/// stream pointer forward by 1 byte.
			///
			virtual void WriteByte(int8_t value) = 0;

			///
			/// Reads an array of bytes from the stream, and advances the
			/// current stream pointer forward by the number of bytes
			/// that were actually written.
			/// The return value is the number of bytes that were actually written.
			/// count - the number of bytes to write to the stream
			/// offset - the offset into the source buffer to begin reading from
			///
			virtual void Write(const char *pSource, int32_t count, int32_t offset = 0) = 0;

			///
			/// Flushes this stream.
			///
			virtual void Flush() = 0;

			///
			/// Closes this stream.
			///
			virtual void Close() = 0;
		};
	}
}

#endif /* _TEKSTORM_ISTREAM_H */