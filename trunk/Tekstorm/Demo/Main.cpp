#include "../Tekstorm/Tekstorm.h"
#pragma comment(lib, "../Debug/Tekstorm.lib")
using namespace Tekstorm;
using namespace Core;
using namespace Math;
using namespace Graphics;

class MyGame : public IGame
{
public:
	virtual bool Update(const GameTime &delta)
	{
		return true;
	}

	virtual bool Draw(const GameTime &delta)
	{ 
		graphics->Clear(Color4(1.0f, 0.5f, 0.5f, 1.0f));
		return true;
	}
};

int main()
{
	MyGame *myGame = new MyGame();
	myGame->SetDesiredFPS(30);

	try
	{
		myGame->Run("My 2D Game");
	}
	catch (Exception ex)
	{
		std::cout << ex.GetProper() << "\n";
	}
}