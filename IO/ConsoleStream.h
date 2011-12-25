#pragma once
#ifndef _TEKSTORM_CONSOLESTREAM_H
#define _TEKSTORM_CONSOLESTREAM_H
#include "IStream.h"

namespace Tekstorm
{
	namespace IO
	{
		///
		/// Provides a stream for STDOUT/STDIN.
		///
		class TEKAPI ConsoleStream : public IStream
		{
		public:
			static const ConsoleStream Default;

			///
			/// Returns whether or not this stream can be read from.
			///
			virtual bool CanRead() const;

			///
			/// Returns whether or not this stream can be written to.
			///
			virtual bool CanWrite() const;

			///
			/// Returns whether or not this stream can seek.
			///
			virtual bool CanSeek() const;

			///
			/// Returns the length, in bytes, of this stream. If
			/// the length is not supported, the result is -1.
			///
			virtual int32_t GetLength() const;

			///
			/// Reads a single byte from the stream, and advances the
			/// current stream pointer forward by 1 byte.
			/// The result is the read byte.
			///
			virtual int32_t ReadByte();

			///
			/// Reads an array of bytes from the stream, and advances the
			/// current stream pointer forward by the number of bytes
			/// that were actually read.
			/// The return value is the number of bytes that were actually read.
			/// count - the number of bytes to read from the stream
			/// offset - the offset into the destination buffer to begin reading to
			///
			virtual int32_t Read(char *pDestination, int32_t count, int32_t offset = 0);

			///
			/// Writes a single byte to the stream, and advances the current
			/// stream pointer forward by 1 byte.
			///
			virtual void WriteByte(int8_t value);

			///
			/// Writes an array of bytes from the stream, and advances the
			/// current stream pointer forward by the number of bytes
			/// that were actually written.
			/// The return value is the number of bytes that were actually written.
			/// count - the number of bytes to write to the stream
			/// offset - the offset into the source buffer to begin reading from
			///
			virtual int32_t Write(const char *pSource, int32_t count, int32_t offset = 0);

			///
			/// Flushes this stream.
			///
			virtual void Flush();

			///
			/// Closes this stream.
			///
			virtual void Close();

			///
			/// Sets the current index into the stream.
			///
			virtual void Seek(int32_t value, int32_t offset = SEEK_SET);
		};
	}
}

#endif /* _TEKSTORM_CONSOLESTREAM_H */