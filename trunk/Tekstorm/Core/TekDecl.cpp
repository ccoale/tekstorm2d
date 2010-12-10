#define TEKBUILD
#if defined(_DEBUG)
#	pragma comment(lib, "d3d9.lib")
#	pragma comment(lib, "d3dx9d.lib")
#	pragma comment(lib, "dxerr.lib")
#else
#	pragma comment(lib, "d3d9.lib")
#	pragma comment(lib, "d3dx9.lib")
#	pragma comment(lib, "dxerr.lib")
#endif