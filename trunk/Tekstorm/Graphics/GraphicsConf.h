#pragma once
#ifndef _TEKSTORM_GRAPHICSCONF_H
#define _TEKSTORM_GRAPHICSCONF_H
#include "../BuildConf.h"

/* 
**	we only want to include d3d11.h if we are building
** the engine from source.
*/
#if defined(TEKSTORM_BUILD)
#include <D3D11.h>
#endif

namespace Tekstorm
{
	namespace Graphics
	{
	}
}

#endif /* _TEKSTORM_GRAPHICSCONF_H */