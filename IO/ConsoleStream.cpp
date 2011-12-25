#define TEKSTORM_BUILD
#include "ConsoleStream.h"

namespace Tekstorm
{
	namespace IO
	{
		const ConsoleStream ConsoleStream::Default = ConsoleStream();

		///
		/// Returns whether or not this stream can be read from.
		///
		bool ConsoleStream::CanRead() const
		{
			return true;
		}

		///
		/// Returns whether or not this stream can be written to.
		///
		bool ConsoleStream::CanWrite() const
		{
			return true;
		}

		///
		/// Returns whether or not this stream can seek.
		///
		bool ConsoleStream::CanSeek() const
		{
			return false;
		}

		///
		/// Returns the length, in bytes, of this stream. If
		/// the length is not supported, the result is -1.
		///
		int32_t ConsoleStream::GetLength() const
		{
			return -1;
		}

		///
		/// Reads a single byte from the stream, and advances the
		/// current stream pointer forward by 1 byte.
		/// The result is the read byte.
		///
		int32_t ConsoleStream::ReadByte()
		{
			char x = 0;
			fread(&x, sizeof(int8_t), 1, stdin);

			return (int32_t)x;
		}

		///
		/// Reads an array of bytes from the stream, and advances the
		/// current stream pointer forward by the number of bytes
		/// that were actually read.
		/// The return value is the number of bytes that were actually read.
		/// count - the number of bytes to read from the stream
		/// offset - the offset into the destination buffer to begin reading to
		///
		int32_t ConsoleStream::Read(char *pDestination, int32_t count, int32_t offset)
		{
			return (int32_t)fread((void *)(&pDestination[offset]), sizeof(int8_t), count, stdin);
		}

		///
		/// Writes a single byte to the stream, and advances the current
		/// stream pointer forward by 1 byte.
		///
		void ConsoleStream::WriteByte(int8_t value)
		{
			fwrite(&value, sizeof(int8_t), 1, stdout);
		}

		///
		/// Writes an array of bytes from the stream, and advances the
		/// current stream pointer forward by the number of bytes
		/// that were actually written.
		/// The return value is the number of bytes that were actually written.
		/// count - the number of bytes to write to the stream
		/// offset - the offset into the source buffer to begin reading from
		///
		int32_t ConsoleStream::Write(const char *pSource, int32_t count, int32_t offset)
		{
			return fwrite((void *)(&pSource[offset]), sizeof(int8_t), count, stdout);
		}

		///
		/// Flushes this stream.
		///
		void ConsoleStream::Flush()
		{
			fflush(stdin);
			fflush(stdout);
		}

		///
		/// Closes this stream.
		///
		void ConsoleStream::Close()
		{
		}

		///
		/// Sets the current index into the stream.
		///
		void ConsoleStream::Seek(int32_t value, int32_t offset)
		{
#if defined(TEKSTORM_DEBUG)
			// can't seek console stream
#endif
		}
	}
}