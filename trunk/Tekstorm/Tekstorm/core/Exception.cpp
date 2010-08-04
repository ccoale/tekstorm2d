#define __BUILD
#include "Exception.h"

namespace Tekstorm
{
	namespace Core
	{
		// Creates a new exception with only a string value (error is set to 0)
		Exception::Exception(const std::string& s)
		{
			error = 0;
			sval = s;
		}

		// Creates a new exception with a string value and integer error
		Exception::Exception(HRESULT err, const std::string &s)
		{
			error = err;
			sval = s;
		}

		// Destroys this instance of this exception
		Exception::~Exception()
		{
		}

		// Gets the string value of this exception
		std::string Exception::GetValue()
		{
			return sval;
		}

		// Gets the integer error of this exception
		HRESULT Exception::GetError()
		{
			return error;
		}

		// Creates a string-representation of the proper error code, name, and string description
		// of this exception.
		std::string Exception::GetProper()
		{
			char temp[16] = {0};
			itoa((int)error, temp, 10);
			std::string res = "Engine Error [";
			res += temp;
			res += "]: ";
			res += DXGetErrorString(error);
			res += ".\r\n";
			res += DXGetErrorDescription(error);
			res += ".\r\n";
			res += sval;

			return res;
		}
	}
}