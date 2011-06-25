#include "IStream.h"

namespace Tekstorm
{
	namespace IO
	{
		///
		/// Offset is from the beginning of the stream.
		///
		const int SeekOrigin::Begin = 0;

		///
		/// Offset is from the end of the stream, in reverse.
		///
		const int SeekOrigin::End = 1;

		///
		/// Offset is from the current position in the stream.
		///
		const int SeekOrigin::Current = 2;
	}
}