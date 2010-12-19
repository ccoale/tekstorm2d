#include "Core/Exception.h"
#include "Core/IDevice.h"
#include "Graphics/IGraphics.h"
#include "Core/TimeConstants.h"
#include "Core/IGame.h"

using namespace Tekstorm;
using namespace Core;
using namespace Graphics;
using namespace Math;

class MyGame : public IGame
{
public:
	bool Update(const TimeSpan &time)
	{
		printf("Update() -- %f\n", time.GetRealMilliseconds());
		return true;
	}
};

int main()
{
	TimeConstants::InitConstants();

	MyGame *myGame = new MyGame();
	myGame->Run("Hello World", 640, 480, 30);

	return 0;
}