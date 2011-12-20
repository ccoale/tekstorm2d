#include "graphics/GraphicsAdapter.h"
using namespace Tekstorm;
using namespace Graphics;

int main()
{
	// get our adapter
	GraphicsAdapter *adapter = GraphicsAdapter::GetAdapter();

	// print display modes
	std::vector<DisplayMode> modes = adapter->QueryDisplayModes(-1, -1);

	for (auto i = modes.begin(); i != modes.end(); i++)
	{
		DisplayMode temp = *i;
		std::cout << temp.Width << ", " << temp.Height << " -- " << temp.RefreshTop << "/" << temp.RefreshBottom << "\n";
	}

	// now we want to find the best matching display for 640,480 @ 60Hz
	DisplayMode temp = adapter->FindBestDisplayMode(620, 440, 65, 1);
	std::cout << "\n\n\n" << temp.Width << ", " << temp.Height << " -- " << temp.RefreshTop << "/" << temp.RefreshBottom << "\n";

	return 0;
}