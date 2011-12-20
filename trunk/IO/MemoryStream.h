#pragma once
#ifndef _TEKSTORM_MEMORYSTREAM_H
#define _TEKSTORM_MEMORYSTREAM_H
#include "../tekconfig.h"
#include "IStream.h"

namespace Tekstorm
{
	namespace IO
	{
		///
		/// MemoryStream which allows writing to and reading from
		/// a predefined buffer/memory location..
		///
		class TEKAPI MemoryStream : public IStream
		{
		protected:
			// The size, in bytes, of the underlying buffer.
			int32_t m_nLength;

			// The current index into the buffer to read/write at.
			int32_t m_nCurrentIndex;

			// The buffer to read/write.
			char *m_pBuffer;

		public:
			MemoryStream();
			MemoryStream(char *pDestination, int32_t size);

			///
			/// Sets the destination buffer and size
			///
			virtual void SetDestination(char *pDest, int32_t size);

			///
			/// Returns whether or not this stream can be read from.
			///
			virtual bool CanRead() const { return true; }

			///
			/// Returns whether or not this stream can be written to.
			///
			virtual bool CanWrite() const { return true; }

			///
			/// Returns whether or not this stream can seek.
			///
			virtual bool CanSeek() const { return true; }

			///
			/// Returns the length, in bytes, of this stream. If
			/// the length is not supported, the result is -1.
			///
			virtual int32_t GetLength() const { return m_nLength; };

			///
			/// Reads a single byte from the stream, and advances the
			/// current stream pointer forward by 1 byte.
			/// The result is the read byte.
			///
			virtual int32_t ReadByte() ;

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
			/// Reads an array of bytes from the stream, and advances the
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

			///
			/// Writes an element to the stream.
			///
			template <class _ElementType>
			void Write(const _ElementType &value)
			{
				int nTypeSize = sizeof(_ElementType);
#if defined(TEKSTORM_DEBUG)
				if (m_pBuffer == nullptr || m_nLength <= 0) { }
				if (m_nCurrentIndex + nTypeSize >= m_nLength) { }
				// handle debug message
#endif

				memcpy((void *)(&m_pBuffer[m_nCurrentIndex]), (void *)&value, nTypeSize);
				m_nCurrentIndex += nTypeSize;
			}

			///
			/// Reads an element from the stream.
			///
			template <class _ElementType>
			_ElementType Read()
			{
				int nTypeSize = sizeof(_ElementType);
#if defined(TEKSTORM_DEBUG)
				if (m_nCurrentIndex + nTypeSize >= m_nLength) { }
				// handle debug message
#endif

				_ElementType temp = _ElementType();
				memcpy((void *)(&temp), (void *)(&m_pBuffer[m_nCurrentIndex]), nTypeSize);
				m_nCurrentIndex += nTypeSize;
				return temp;
			}
		};
	}
}

#endif /* _TEKSTORM_MEMORYSTREAM_H */