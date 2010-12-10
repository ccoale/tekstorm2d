#include "Core/Exception.h"
#include "Core/IDevice.h"
#include "Graphics/IGraphics.h"
#include "Core/TimeConstants.h"

using namespace Tekstorm;
using namespace Core;
using namespace Graphics;
using namespace Math;

int main()
{
	/*TimeConstants::InitConstants();
	IDevice *pDev = IDevice::GetDevice();
	DisplayMode mode;
	mode.Width = 640;
	mode.Height = 470;
	mode.Hz = 60;
	mode.Format = PF_DEFAULT;
	pDev->FindDisplayMatch(&mode);

	IGraphics *graph = pDev->CreateDevice(mode, "My Game");


	Color4 col(1.0f, 1.0f, 1.0f, 1.0f);

	while (true)
	{
		Sleep(100);
		graph->Update();
		graph->Clear(col);
		graph->Begin();
		graph->End();
		graph->Present();
	}*/

	__asm mov EAX, 0; add EAX, 10;
	return 0;
}