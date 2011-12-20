#pragma once
#ifndef _TEKSTORM_TEXTWRITER_H
#define _TEKSTORM_TEXTWRITER_H
#include "../tekconfig.h"
#include "IStream.h"

namespace Tekstorm
{
	namespace IO
	{
		class IStream;

		class TEKAPI TextWriter
		{
		protected:
			IStream *m_pStream;

		public:
			TextWriter();
			TextWriter(IStream *pStream);

			virtual void Write(const std::string &text);
		};
	}
}

#endif /* _TEKSTORM_TEXTWRITER_H */