#define TEKSTORM_BUILD
#include "MemoryStream.h"

namespace Tekstorm
{
	namespace IO
	{
		using namespace Tekstorm::Core;
		MemoryStream::MemoryStream()
		{
			m_pBuffer = nullptr;
			m_nLength = 0;
			m_nCurrentIndex = 0;
		}

		MemoryStream::MemoryStream(char *pDestination, int32_t size)
		{
#if defined(TEKSTORM_DEBUG)
			if ( (pDestination == nullptr) || (m_pBuffer == nullptr) || (m_nLength <= 0) || (size <= 0) )
			{
			}
#endif
			m_pBuffer = pDestination;
			m_nLength = size;
			m_nCurrentIndex = 0;
		}

		///
		/// Sets the destination buffer and size
		///
		void MemoryStream::SetDestination(char *pDest, int32_t size)
		{
#if defined(TEKSTORM_DEBUG)
			if (m_pBuffer == nullptr || m_nLength <= 0 || pDest == nullptr || size <= 0)
			{
			}
#endif
			m_pBuffer = pDest;
			m_nLength = size;
			m_nCurrentIndex = 0;
		}

		///
		/// Reads a single byte from the stream, and advances the
		/// current stream pointer forward by 1 byte.
		/// The result is the read byte.
		///
		int32_t MemoryStream::ReadByte() 
		{
#if defined(TEKSTORM_DEBUG)
			if (m_nCurrentIndex >= m_nLength || m_pBuffer == nullptr || m_nLength <= 0)
			{
			}
#endif
			return (int32_t)m_pBuffer[m_nCurrentIndex++];
		}

		///
		/// Reads an array of bytes from the stream, and advances the
		/// current stream pointer forward by the number of bytes
		/// that were actually read.
		/// The return value is the number of bytes that were actually read.
		/// count - the number of bytes to read from the stream
		/// offset - the offset into the destination buffer to begin reading to
		///
		int32_t MemoryStream::Read(char *pDestination, int32_t count, int32_t offset)
		{
#if defined(TEKSTORM_DEBUG)
			if ( (m_nCurrentIndex + count >= m_nLength) || count <= 0 || offset <= 0 || pDestination == nullptr || m_pBuffer == nullptr || m_nLength <= 0) 
			{
			}
#endif

			memcpy((void *)(&pDestination[offset]), (void *)(&m_pBuffer[m_nCurrentIndex]), sizeof(int8_t) * count);
			m_nCurrentIndex += count;
			return count;
		}

		///
		/// Writes a single byte to the stream, and advances the current
		/// stream pointer forward by 1 byte.
		///
		void MemoryStream::WriteByte(int8_t value)
		{
#if defined(TEKSTORM_DEBUG)
			if (m_pBuffer == nullptr || m_nLength <= 0 || m_nCurrentIndex >= m_nLength)
			{
			}
#endif
			m_pBuffer[m_nCurrentIndex++] = (char)value;
		}

		///
		/// Reads an array of bytes from the stream, and advances the
		/// current stream pointer forward by the number of bytes
		/// that were actually written.
		/// The return value is the number of bytes that were actually written.
		/// count - the number of bytes to write to the stream
		/// offset - the offset into the source buffer to begin reading from
		///
		int32_t MemoryStream::Write(const char *pSource, int32_t count, int32_t offset)
		{
#if defined(TEKSTORM_DEBUG)
			if ( (m_nCurrentIndex + count >= m_nLength) || count <= 0 || offset <= 0 || pSource == nullptr ||
				m_pBuffer == nullptr || m_nLength <= 0)
			{
			}
#endif
			memcpy((void *)(&m_pBuffer[m_nCurrentIndex]), (void *)(&pSource[offset]), sizeof(int8_t) * count);
			m_nCurrentIndex += count;
			return count;
		}

		///
		/// Flushes this stream.
		///
		void MemoryStream::Flush()
		{
			// stream isn't buffered so there's nothing to flush
		}

		///
		/// Closes this stream.
		///
		void MemoryStream::Close()
		{
			// stream isn't opened, nothing to close.
			m_pBuffer = nullptr;
			m_nLength = 0;
			m_nCurrentIndex = 0;
		}

		///
		/// Sets the current index into the stream.
		///
		void MemoryStream::Seek(int32_t value, int32_t offset)
		{
#if defined(TEKSTORM_DEBUG)
			if ((offset == SEEK_SET && offset <= 0) || (offset == SEEK_END && offset <= 0) || 
				(offset != SEEK_SET && offset != SEEK_END && offset != SEEK_CUR) || value >= m_nLength ||
				m_pBuffer == nullptr || m_nLength <= 0) 
			{
			}
#endif
			if (offset == SEEK_SET)
				m_nCurrentIndex = offset;
			else if (offset == SEEK_END)
				m_nCurrentIndex = m_nLength - offset;
			else if (offset == SEEK_CUR)
				m_nCurrentIndex += offset;
		}
	}
}