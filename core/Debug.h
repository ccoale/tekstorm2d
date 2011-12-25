#pragma once
#ifndef _TEKSTORM_DEBUG_H
#define _TEKSTORM_DEBUG_H
#include "../tekconfig.h"
#include "../IO/IStream.h"
#include "../IO/TextWriter.h"

// Warning
#define TEKDEBUG_W(s) \
	Debug::GetWriter() << "Warning: " << s << "\n";

// Warning with error code
#define TEKDEBUG_WN(s, n) \
	Debug::GetWriter() << "Warning (" << n << "): " << s << "\n";

// Error
#define TEKDEBUG_E(s) \
	Debug::GetWriter() << "Error: " << s < "\n";

// Error with error code
#define TEKDEBUG_EN(s, n) \
	Debug::GetWriter() << "Error (" << n << "): " << s << "\n";

// Full warning
#define TEKDEBUG_WF(s) \
	Debug::GetWriter() << "Warning (Fn=" << __FUNCTION__ << ", File=" << __FILE__ \
	<< ", Line=" << __LINE__ << "): " << s "\n";

// Full warning with error code
#define TEKDEBUG_WFE(s, n) \
	Debug::GetWriter() << "Warning (Fn=" << __FUNCTION__ << ", Error=" << n \
	<< ", File=" << __FILE__ << ", Line=" << __LINE__ << "): " << s "\n";

// Full error
#define TEKDEBUG_EF(s) \
	Debug::GetWriter() << "Error (Fn=" << __FUNCTION__ << ", File=" << __FILE__ \
	<< ", Line=" << __LINE__ << "): " << s "\n";

// Full error with error code
#define TEKDEBUG_EFE(s, n) \
	Debug::GetWriter() << "Error (Fn=" << __FUNCTION__ << ", Error=" << n \
	<< ", File=" << __FILE__ << ", Line=" << __LINE__ << "): " << s "\n";

// Info
#define TEKDEBUG_INFO(s) \
	Debug::GetWriter() << "[Info]: " << s << "\n";

namespace Tekstorm
{
	namespace Core
	{
		using Tekstorm::IO::IStream;
		using Tekstorm::IO::TextWriter;

		///
		/// Provides static methods for debugging.
		///
		class TEKAPI Debug
		{
		private:
			static IStream *m_pOutputStream;

			///
			/// No public constructor
			///
			Debug();
		public:
			~Debug();

			///
			/// Sets the destination output stream.
			///
			static void SetDestination(IStream *pStream);

			///
			/// Gets the destination output stream.
			///
			static IStream *GetDestination();

			///
			/// Gets a TextWriter object for the underlying stream.
			///
			static TextWriter GetWriter();
		};
	}
}

#endif /* _TEKSTORM_DEBUG_H */