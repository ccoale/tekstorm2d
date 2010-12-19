#ifndef _TEKSTORM_IGAME_H
#define _TEKSTORM_IGAME_H
#include "IDevice.h"
#include "../Graphics/IGraphics.h"
#include "../Math/Color4.h"
#include "../Core/TimeSpan.h"

namespace Tekstorm
{
	namespace Core
	{
		class TEKAPI IGame
		{
		private:
			unsigned int DesiredFPS; // the desired FPS of this game
			float msPerFrame;		 // the number of milliseconds allowed per frame given the desired frame rate
			float FPS;				 // the current number of frames per second

		public:
			Tekstorm::Core::IDevice *Device;
			Tekstorm::Graphics::IGraphics *Graphics;
			Tekstorm::Core::TimeStamp LastDrawCall; //
			Tekstorm::Core::TimeStamp LastUpdateCall; // the timestamp when the last call to Update was made.

			IGame();
			~IGame();

			// Used to initialize any game code
			virtual void Initialize();

			// Used to load any initial game content
			virtual void OnLoad();

			// Used to unload any game content
			virtual void OnUnload();

			// Called when the game logic should be updated
			// this function should return true.
			// false will cause the game to end, and all resources to be destroyed,
			// and the game loop will return.
			// The time argument is the time since the last call to Update.
			virtual bool Update(const TimeSpan &time);

			// Called when the game's rendering should be re-rendered
			// this function should return true.
			// false will cause the game to end, and all resources to be destroyed,
			// and the game loop will return.
			// The time argument is the time since the last call to Draw.
			virtual bool Draw(const TimeSpan &time);

			// Initializes and runs the game loop.
			// This function will start by creating the IDevice object,
			// followed by the IGraphics object, followed by calling Initialize,
			// OnLoad, and then running the game loop. When the game loop ends,
			// a call to OnUnload will be made, followed by a destruction of
			// all game resources, and then this function will return.
			virtual bool Run(const char *caption = "Game Window", // the caption of the game window
				unsigned int width = 640, // the width of the game window
				unsigned int height = 480, // the height of the game window
				unsigned int desiredFps = 60, // the desired FPS of the game loop
				bool windowed = true, // whether or not the game should be in a window or fullscreen
				bool vsync = true, // whether or not to wait for a vertical refresh
				unsigned int multiSampleType = 0,
				::WNDPROC msgHandler = NULL); // whether or not to use a custom message handler

			// sets the desired fps (the value must be between 0 and 500)
			virtual void SetDesiredFPS(unsigned int fps);

			// calculates the -real- FPS (of the previous frame)
			virtual float GetRealFPS();

			// idle worker
			// 'ms' is the number of extra ms of time this IdleWorker function may use.
			virtual void IdleWorker(unsigned int ms);
		};
	}
}

#endif /* _TEKSTORM_IGAEM_H */