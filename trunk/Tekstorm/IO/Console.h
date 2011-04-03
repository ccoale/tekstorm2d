#pragma once
#ifndef _TEKSTORM_CONSOLE_H
#define _TEKSTORM_CONSOLE_H
#include "../BuildConf.h"
#include "../Scripting/angelscript.h"
#include "IStream.h"

namespace Tekstorm
{
	namespace IO
	{
		class TEKAPI Console
		{
		private:
			/*
			** The input stream. The console will read from this stream to get its input.
			*/
			IStream *inStream;

			/*
			** The output stream. The console writes all of its output to this stream.
			*/
			IStream *outStream;

			/*
			** The scripting engine that this Console has access to.
			*/
			asIScriptEngine *mEngine;

			/*
			** The scripting module that this console has access to.
			*/
			asIScriptModule *mModule;

			/*
			** Executes the given code
			*/
			void Execute(const std::string &value);
		public:
			/*
			** Initializes a new Console class.
			*/
			Console(IStream *in, IStream *out, asIScriptEngine *engine, asIScriptModule *mod);

			/*
			** Destroys this instance of Console.
			*/
			~Console();

			/*
			** Writes a character to the stream.
			*/
			void Write(char c);

			/*
			** Writes an integer to the stream.
			*/
			void Write(int n);

			/*
			** Writes a floating-point value to the stream.
			*/
			void Write(double d);

			/*
			** Writes a string value to the stream.
			*/
			void Write(const std::string &str);

			/*
			** Reads a string from the stream.
			*/
			std::string ReadLine();

			/*
			** Updates the console. This should be called in a loop.
			*/
			void Update();
		};
	}
}

#endif /* _TEKSTORM_CONSOLE_H */