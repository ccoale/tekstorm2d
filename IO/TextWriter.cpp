#define TEKSTORM_BUILD
#include "TextWriter.h"

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
				if (pStream)
					m_pStream = pStream;
			}

			void TextWriter::Write(const std::string &text)
			{
				if (m_pStream)
				{
					if (m_pStream->CanWrite())
						m_pStream->Write(text.c_str(), text.length(), 0);
				}
			}
	}
}