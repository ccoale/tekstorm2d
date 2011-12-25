#define TEKSTORM_BUILD
#include "TextWriter.h"
#include <sstream>

namespace Tekstorm
{
	namespace IO
	{

		TextWriter::TextWriter()
		{
			m_pStream = nullptr;
		}

		TextWriter::TextWriter(IStream *pStream)
		{
#if defined(TEKSTORM_DEBUG)
			if (pStream == nullptr) {
				TEKDEBUG_WF("pStream argument is null. Was this intended?");
			}
#endif
			m_pStream = pStream;
		}

		///
		/// Sets the underlying stream destination.
		///
		void TextWriter::SetDestination(IStream *pStream)
		{
#if defined(TEKSTORM_DEBUG)
			if (pStream == nullptr) {
				TEKDEBUG_WF("pStream argument is null. Was this intended?");
			}
#endif

			m_pStream = pStream;
		}


		///
		/// Writes a string to the stream.
		///
		void TextWriter::Write(const std::string &text)
		{
#if defined(TEKSTORM_DEBUG)
			if (m_pStream == nullptr) {
				TEKDEBUG_EF("Cannot write to a null stream.");
			}
#endif
			m_pStream->Write(text.c_str(), text.length(), 0);
		}

		///
		/// Writes a 32-bit integral number to the stream.
		///
		void TextWriter::Write(int32_t number)
		{
#if defined(TEKSTORM_DEBUG)
			if (m_pStream == nullptr) {
				TEKDEBUG_EF("Cannot write to a null stream.");
			}
#endif

			// 10 digits + 1 for sign + 1 for null
			static char tempBuff[10 + 1 + 1] = {0};
			//sprintf(tempBuff, "%d", number); // itoa is probably faster
			itoa(number, tempBuff, 10);
			int length = strlen(tempBuff);
			m_pStream->Write(tempBuff, length, 0);
		}

		///
		/// Writes a single character to the stream.
		///
		void TextWriter::Write(char character)
		{
#if defined(TEKSTORM_DEBUG)
			if (m_pStream == nullptr) {
				TEKDEBUG_EF("Cannot write to a null stream.");
			}
#endif

			m_pStream->WriteByte((int8_t)character);
		}

		///
		/// Writes a 64-bit double floating-point number to the stream.
		///
		void TextWriter::Write(double number)
		{
#if defined(TEKSTORM_DEBUG)
			if (m_pStream == nullptr) {
				TEKDEBUG_EF("Cannot write to a null stream.");
			}
#endif

			std::string temp = "";
			
			std::stringstream stream;
			stream << number;
			stream >> temp;
			m_pStream->Write(temp.c_str(), temp.length(), 0);
		}

	}
}