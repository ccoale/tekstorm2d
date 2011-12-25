#define TEKSTORM_BUILD
#include "Debug.h"
#include "../IO/ConsoleStream.h"

namespace Tekstorm
{
	namespace Core
	{
		IStream *Debug::m_pOutputStream = nullptr;

		///
		/// No public constructor
		///
		Debug::Debug()
		{
			m_pOutputStream = nullptr;
		}

		Debug::~Debug()
		{
		}

		///
		/// Sets the destination output stream.
		///
		void Debug::SetDestination(IStream *pStream)
		{
			m_pOutputStream = pStream;
		}

		///
		/// Gets the destination output stream.
		///
		IStream *Debug::GetDestination()
		{
			if (m_pOutputStream == nullptr)
			{
				return (IStream *)&Tekstorm::IO::ConsoleStream::Default;
			}
			else
			{
				return m_pOutputStream;
			}
		}

		///
		/// Gets a TextWriter object for the underlying stream.
		///
		TextWriter Debug::GetWriter()
		{
			return TextWriter(GetDestination());
		}
	}
}