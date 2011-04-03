#pragma once
#ifndef _TEKSTORM_EXCEPTION_H
#define _TEKSTORM_EXCEPTION_H
#include "BuildConf.h"
#include <string>

namespace Tekstorm
{
	/*
	** An exception class that is used throughout the Tekstorm game engine.
	*/
	class Exception
	{
	protected:
		/*
		** The textual message associated with the exception.
		*/
		std::string Message;

		/*
		** The numeric error code associated with the exception.
		*/
		int ErrorCode;

	public:
		/*
		** Initializes a new instance of Exception.
		** Parameters
		**	msg		- the textual message of the exception
		**	code	- the numeric error code, if any.
		** Returns
		**	nothing
		*/
		Exception(const std::string &msg, int code = 0)
			: Message(msg), ErrorCode(code)
		{
		}

		/*
		** Destroys this instance of Exception
		*/
		virtual ~Exception() { }

		/*
		** Gets the textual message associated with this exception
		** Parameters
		**	none
		** Returns
		**	the textual message associated with this exception.
		*/
		virtual std::string GetMessage() const
		{
			return Message;
		}

		/*
		** Gets the numeric error code associated with this exception
		** Parameters
		**	none
		** Returns
		**	the numeric error code associated with this exception.
		*/
		virtual int GetErrorCode() const
		{
			return ErrorCode;
		}
	};
}

#endif /* _TEKSTORM_EXCEPTION_H */