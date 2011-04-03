#define TEKSTORM_CONSOLE
#include "Console.h"
#include <string>

namespace Tekstorm
{
	namespace IO
	{
		bool StringEndsWith(const std::string &val, char c)
		{
			size_t t = val.find_last_of(c);
			size_t a = val.find_last_of(';');
			if (t == std::string::npos)
				return false;

			if (val.find_last_of(';') < val.find_last_of(c))
				return true;

			return false;
		}

		int ExecuteString(asIScriptEngine *engine, const char *code, asIScriptModule *mod, asIScriptContext *ctx)
		{
			// Wrap the code in a function so that it can be compiled and executed
			std::string funcCode = "void __ExecuteString() { ";
			funcCode += code;
			funcCode +=  "}";

			// If no module was provided, get a dummy from the engine
			asIScriptModule *execMod = mod ? mod : engine->GetModule("__ExecuteString", asGM_ALWAYS_CREATE);

			// Compile the function that can be executed
			asIScriptFunction *func = 0;
			int r = execMod->CompileFunction("__ExecuteString", funcCode.c_str(), -1, 0, &func);
			if( r < 0 )
				return r;

			// If no context was provided, request a new one from the engine
			asIScriptContext *execCtx = ctx ? ctx : engine->CreateContext();
			r = execCtx->Prepare(func->GetId());
			if( r < 0 )
			{
				func->Release();
				if( !ctx ) execCtx->Release();
				return r;
			}

			// Execute the function
			r = execCtx->Execute();
			execCtx->Execute();

			// Clean up
			func->Release();
			if( !ctx ) execCtx->Release();

			return r;
		}

		/*
		** Executes the given code
		*/
		void Console::Execute(const std::string &value)
		{
			ExecuteString(mEngine, value.c_str(), mModule, 0);
		}

		/*
		** Initializes a new Console class.
		*/
		Console::Console(IStream *in, IStream *out, asIScriptEngine *engine, asIScriptModule *mod)
		{
			inStream = in;
			outStream = out;
			mEngine = engine;
			mModule = mod;
		}

		/*
		** Destroys this instance of Console.
		*/
		Console::~Console()
		{
		}

		/*
		** Writes a character to the stream.
		*/
		void Console::Write(char c)
		{
			outStream->WriteByte(c);
		}

		/*
		** Writes an integer to the stream.
		*/
		void Console::Write(int n)
		{
			char buff[128] = {0};
			itoa(n, buff, 10);
			outStream->Write(buff, 0, strlen(buff));
		}

		/*
		** Writes a floating-point value to the stream.
		*/
		void Console::Write(double d)
		{
			char buff[128] = {0};
			sprintf(buff, "%ld", d);
			outStream->Write(buff, 0, strlen(buff));
		}

		/*
		** Writes a string value to the stream.
		*/
		void Console::Write(const std::string &str)
		{
			outStream->Write(str.c_str(), 0, str.length());
		}

		/*
		** Reads a string from the stream.
		*/
		std::string Console::ReadLine()
		{
			std::string str = "";
			char c  = 0;
			while ((c = inStream->ReadByte()) != '\n')
				str += c;

			return str;
		}

		/*
		** Updates the console. This should be called in a loop.
		*/
		void Console::Update()
		{
			std::string line = ReadLine();
			while (StringEndsWith(line, '\\'))
			{
				line = line.erase(line.find_last_of('\\'));
				line += "\n" + ReadLine();
			}
			this->Execute(line);
		}
	}
}
