#include "TekstormDecl.h"
#include "core/TimeConstants.h"
#pragma comment(lib, "d3d9.lib")

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	switch(fdwReason)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
		Tekstorm::Core::TimeConstants::InitConstants();
		break;
	};

	return TRUE;
}
