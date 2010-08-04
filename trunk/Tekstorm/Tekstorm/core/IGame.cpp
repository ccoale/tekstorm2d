#define __BUILD
#include "IGame.h"

namespace Tekstorm
{
	namespace Core
	{
		// Creates a new instance of this game.
		IGame::IGame()
		{
			desiredFPS = 60;
			realFPS = 0.0f;
			gameTime.StartFrameTime = 0;
			gameTime.StartLastFrameTime = 0;
			gameTime.ElapsedGameTime = 0;
			gameTime.ElapsedFrameTime = 0;
			initialized = false;
		}

		// Destroys this instance of this game.
		IGame::~IGame()
		{
			if (! graphics)
				delete graphics; // force Release
			if (! device)
				delete device; // force Release
		}

		// This method is used for initializing this game's most internal resources. It is
		// not intended to be used for resource loading.
		// caption		-- The title of the window; unused if fullscreen is set to true.
		// width		-- The width of the window. If fullscreen, the width of the backbuffer.
		// height		-- The height of the window. If fullscreen, the height of the backbuffer.
		// fullscreen	-- Whether or not the window should cover the entire screen.
		bool IGame::Initialize(const char *caption, uint_t width, uint_t height, bool fullscreen)
		{
			try {
				// try to create our Direct3D device. If this fails, the game can't be created.
				device = new Tekstorm::Graphics::Device();
			} catch (Tekstorm::Core::Exception ex) {
				throw ex; // re-throw the exception
				return false;
			}

			try {
				// try to create our graphics object. If this fails, the game can't be created.
				graphics = new Tekstorm::Graphics::Graphics(device, caption, width, height, fullscreen);
			}  catch (Tekstorm::Core::Exception ex) {
				throw ex; // re-throw the exception
				return false;
			}

			// set and return initialized
			return (initialized = true);
		}

		// This method is used for uninitializing/freeing this game's most internal resources. It is NOT
		// intended to unload in-game content.
		void IGame::Uninitialize()
		{
		}

		// This method is intended to run the game. It manages the game loop and will not return until the game has finished,
		// as indicated by Update or Draw returning false, or the Stop method being called.
		// Each parameter of this method corresponds to the same parameters as declared in Initialize.
		void IGame::Run(const char *caption, uint_t width, uint_t height, bool fullscreen)
		{
			// initialize the game
			if (! Initialize(caption, width, height, fullscreen))
				return;

			// load initial resources
			if (! OnLoad())
				return;

			bool doUpdate = true;
			bool doDraw = true;
			bool didSkip = false; // true when we skipped the last scene
			running = true;

			// this is the number of milliseconds per frame
			float timePerFrame = (1.0f / (float)desiredFPS) * 1000; // max FPS = 1k (exactly)
			float lowestTimePerFrame = (1.0f / 20.0f) * 1000; // the lowest FPS before we start skipping scenes
			gameTime.StartGameTime = TimeStamp::GetNow();

			// our game loop
			while (doUpdate && doDraw && running)
			{
				// update messages
				graphics->PumpMessages();

				// update our total game time
				gameTime.ElapsedGameTime = TimeStamp::GetNow() - gameTime.StartGameTime;
				gameTime.StartFrameTime = TimeStamp::GetNow();
				gameTime.ElapsedFrameTime = TimeStamp::GetNow() - gameTime.StartFrameTime;

				// Update our game logic
				doUpdate = Update(gameTime);
				if (! doUpdate)
					break; // no need to continue

				// update our total game time
				gameTime.ElapsedGameTime = TimeStamp::GetNow() - gameTime.StartGameTime;

				// update the time for this frame
				gameTime.ElapsedFrameTime = TimeStamp::GetNow() - gameTime.StartFrameTime;
				float frameTime = gameTime.ElapsedFrameTime.GetRealMilliseconds();
				if ( (frameTime >= lowestTimePerFrame) && (! didSkip) ) {
					didSkip = true;
					continue; // skip rendering because the logic is too slow
				}
				didSkip = false;
				graphics->BeginScene();
				doDraw = Draw(gameTime);
				graphics->EndScene();
				graphics->Present();
				if (! doDraw)
					break; // no need to continue

				gameTime.ElapsedFrameTime = TimeStamp::GetNow() - gameTime.StartFrameTime;
				frameTime = gameTime.ElapsedFrameTime.GetRealMilliseconds();


				// how much time is left
				int timeLeft = (int)(timePerFrame - frameTime);
				
				if (timeLeft > 0)
					Sleep(timeLeft);

				gameTime.ElapsedFrameTime = TimeStamp::GetNow() - gameTime.StartFrameTime;
				frameTime = gameTime.ElapsedFrameTime.GetRealMilliseconds();
				realFPS = (1.0f / frameTime) * 1000;
			}
			running = false;

			// unload our resources
			OnUnload();

			// uninitialize our resources
			Uninitialize();
		}

		// This method is intended to stop the execution of this game. Calling this method WILL trigger the OnUnload and Uninitialize methods.
		void IGame::Stop()
		{
			running = false;
		}
	}
}