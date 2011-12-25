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

		///
		/// Allows the writing of generic text to a stream.
		///
		class TEKAPI TextWriter
		{
		protected:
			IStream *m_pStream;

		public:
			///
			/// Initializes a new instance of TextWriter. With no underlying stream set.
			///
			TextWriter();

			///
			/// Initializes a new instance of TextWriter with an underlying stream.
			///
			TextWriter(IStream *pStream);

			///
			/// Sets the underlying stream destination.
			///
			virtual void SetDestination(IStream *pStream);


			///
			/// Writes a string to the stream.
			///
			virtual void Write(const std::string &text);

			///
			/// Writes a 32-bit integral number to the stream.
			///
			virtual void Write(int32_t number);

			///
			/// Writes a single character to the stream.
			///
			virtual void Write(char character);

			///
			/// Writes a 64-bit double floating-point number to the stream.
			///
			virtual void Write(double number);

			///
			/// Easily write any supported type to the stream.
			///
			template <class _Type>
			TextWriter& operator<<(const _Type &value)
			{
				Write(value);
				return *this;
			}
		};
	}
}

#endif /* _TEKSTORM_TEXTWRITER_H */