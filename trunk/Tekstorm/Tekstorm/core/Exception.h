#ifndef _TEKSTORM_EXCEPTION_H
#define _TEKSTORM_EXCEPTION_H
#include "../TekstormDecl.h"
#include "Errors.h"
#include <iostream>
#include <string>

namespace Tekstorm
{
	namespace Core
	{
		// This exception class is used throughout the game engine as a way of communicating
		// errors in various forms, including a user-friendly form. Most functions/methods
		// will throw an exception as well as return a boolean result for quick testing and
		// then a strong implementation.
		class TEKDECL Exception
		{
		public:
			// Creates a new exception with only a string value (error is set to 0)
			// s		-- the value to give this exception's description
			Exception(const std::string& s);

			// Creates a new exception with a string value and integer error
			// err		-- the HRESULT error code to assign this exception
			// s		-- the value to give this exception's description
			Exception(HRESULT err, const std::string &s);

			// Destroys this instance of this exception
			~Exception();

			// Gets the string value of this exception (the description)
			std::string GetValue();

			// Gets the integer error of this exception (the HRESULT error code)
			HRESULT GetError();

			// Creates a string-representation of the proper error code, name, and string description
			// of this exception.
			// String returned is in the format of:
			//
			// Engine Error [#######]: E_ERROR_NAME.
			// DirectX Error Code Description.
			// Actual exception message.
			std::string GetProper();
		private:
			// string value representation of this exception
			std::string sval;

			// integer id error
			HRESULT error;
		};
	}
}

#endif /* _TEKSTORM_EXCEPTION_H */