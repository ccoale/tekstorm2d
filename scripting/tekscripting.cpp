#define TEKSTORM_BUILD
#include "tekscripting.h"

#if !defined(TEKSTORM_NO_SCRIPTING)
	#if defined(TEKSTORM_DEBUG)
		#pragma comment(lib, "squirrelD.lib")
		#pragma comment(lib, "sqplusD.lib")
		#pragma comment(lib, "sqstdlibD.lib")
	#else
		#pragma comment(lib, "squirrel.lib")
		#pragma comment(lib, "sqplus.lib")
		#pragma comment(lib, "sqstdlib.lib")
	#endif
#endif