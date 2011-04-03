#include <iostream>
#include <string>
#include "Scripting/angelscript.h"
#include "Sound/ISoundManager.h"
#include "Sound/FMODSoundManager.h"
#include "IO/StandardStream.h"
#include "IO/Console.h"
#include <Windows.h>
using namespace Tekstorm;
using namespace Sound;
using namespace IO;

#define SOUND_CHIMES	0x01

ISoundManager *soundManager;

void PlaySound2(int id, int val)
{
	std::cout << "test";
	ISoundEffect *effect = soundManager->FindSoundEffectByID(id);
	effect->Play(val);
}


// Implement a simple message callback function
void MessageCallback(const asSMessageInfo *msg, void *param)
{
  const char *type = "ERR ";
  if( msg->type == asMSGTYPE_WARNING ) 
    type = "WARN";
  else if( msg->type == asMSGTYPE_INFORMATION ) 
    type = "INFO";
  printf("%s (%d, %d) : %s : %s\n", msg->section, msg->row, msg->col, type, msg->message);
}
int main()
{
	const char *code = "void myEventFunction() { PlaySound(1, 1); }";
	soundManager = new FMODSoundManager();
	ISoundEffect *effect = soundManager->LoadSoundEffect("C:\\Windows\\Media\\Chimes.wav", SOUND_CHIMES);

	asIScriptEngine *pEngine = asCreateScriptEngine(ANGELSCRIPT_VERSION);
	pEngine->SetMessageCallback(asFUNCTION(MessageCallback), 0, asCALL_CDECL);
	asIScriptModule *mod = pEngine->GetModule("module", asGM_ALWAYS_CREATE);

	pEngine->RegisterGlobalFunction("void PlaySound(int,int)", asFUNCTION(PlaySound2), asCALL_CDECL);
	pEngine->RegisterGlobalFunction("int rand()", asFUNCTION(rand), asCALL_CDECL);

	mod->AddScriptSection("myScript", code);
	mod->Build();
	StandardStream *std = new StandardStream();

	Console *con = new Console(std, std, pEngine, mod);
	while (true)
	{
		con->Update();
	}
}