#define TEKBUILD
#include "IGame.h"

namespace Tekstorm
{
	namespace Core
	{
		IGame::IGame()
		{
		}

		IGame::~IGame()
		{
		}

		// Used to initialize any game code
		void IGame::Initialize()
		{
		}

		// Used to load any initial game content
		void IGame::OnLoad()
		{
		}

		// Used to unload any game content
		void IGame::OnUnload()
		{
		}

		// Called when the game logic should be updated
		// this function should return true.
		// false will cause the game to end, and all resources to be destroyed,
		// and the game loop will return.
		bool IGame::Update(const TimeSpan &time)
		{
			return true;
		}

		// Called when the game's rendering should be re-rendered
		// this function should return true.
		// false will cause the game to end, and all resources to be destroyed,
		// and the game loop will return.
		bool IGame::Draw(const TimeSpan &time)
		{
			// clear the screen to cornflower blue
			Graphics->Clear(Tekstorm::Math::Color4(1.0f, 0.39f, 0.58f, 0.93f));

			return true;
		}

		// Initializes and runs the game loop.
		// This function will start by creating the IDevice object,
		// followed by the IGraphics object, followed by calling Initialize,
		// OnLoad, and then running the game loop. When the game loop ends,
		// a call to OnUnload will be made, followed by a destruction of
		// all game resources, and then this function will return.
		bool IGame::Run(const char *caption, // the caption of the game window
			unsigned int width, // the width of the game window
			unsigned int height, // the height of the game window
			unsigned int desiredFps, // the desired FPS of the game loop
			bool windowed, // whether or not the game should be in a window or fullscreen
			bool vsync, // whether or not to wait for a vertical refresh
			unsigned int multiSampleType,
			::WNDPROC msgHandler) // whether or not to use a custom message handler
		{
			Device = Tekstorm::Core::IDevice::GetDevice();
			if (! Device)
				return false;

			DisplayMode mode;
			mode.Width = width;
			mode.Height = height;
			mode.Hz = 60;
			mode.Format = PF_DEFAULT;
			Device->FindDisplayMatch(&mode); // find the closest match for the display mode given

			DesiredFPS = desiredFps;

			// create the graphics device
			Graphics = Device->CreateDevice(mode, caption, windowed, vsync, multiSampleType, msgHandler);
			if (! Graphics)
				return false;

			Initialize();
			OnLoad();
			bool isRunning = true;
			LastDrawCall = TimeStamp::GetNow();
			LastUpdateCall = TimeStamp::GetNow();

			while (isRunning)
			{
				
			}
		}

		// sets the desired fps (the value must be between 0 and 500)
		void IGame::SetDesiredFPS(unsigned int fps)
		{
			if (fps < 0 || fps > 500)
				return; // don't waste time

			DesiredFPS = fps;
			msPerFrame = (unsigned int)(1000.0 / (double)DesiredFPS);
		}
	}
}