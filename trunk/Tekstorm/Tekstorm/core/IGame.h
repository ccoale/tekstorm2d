#ifndef _TEKSTORM_IGAME_H
#define _TEKSTORM_IGAME_H
#include "../TekstormDecl.h"
#include "TimeStamp.h"
#include "TimeSpan.h"
#include "GameTime.h"
#include "../Graphics/Device.h"
#include "../Graphics/Graphics.h"

namespace Tekstorm
{
	namespace Core
	{
		class TEKDECL Device;
		class TEKDECL Graphics;

		// The IGame class is the base class that all games should inherit. Although
		// it is not required to use this class, it is convenient as it provides an
		// entirely object-oriented approach to game development. It manages FPS timing,
		// frame-skipping (to keep the FPS from lagging), and resource management.
		class TEKDECL IGame
		{
		protected:
			// The desired FPS to be achieved. Although it is not guarenteed that this FPS will
			// be reached or passed, it is a good idea to set this member to a reasonable value
			// such as 60FPS. Be warned, however, that the FPS can jump +/- 5 FPS or more. Generally,
			// if a game's FPS is higher than the actual time time per frame, than the FPS will
			// be extremely steady (that is, the FPS will stay at about 60FPS). If the time per frame
			// is too high, the FPS may drop considerably, and frames may be skipped.
			uint_t desiredFPS;

			// The actual real-time calculated Frames Per Second. This member is calculated at the end
			// of every frame to give an accurate representation of the number of frames being rendered
			// per second. This value should not be compared to 'desiredFPS.'
			float realFPS;

			// An internal timing structure used by this class to keep track of FPS.
			GameTime gameTime;

			// The underlying Direct3D device resource. This value SHOULD NOT be changed.
			Tekstorm::Graphics::Device *device;

			// The underlying Direct3D backbuffer resource. This value SHOULD NOT be changed.
			Tekstorm::Graphics::Graphics *graphics;

			// A boolean value indicating whether or not this game's resources have been intialized
			// yet. This value is set to true after Initialize has been called and succeeded.
			bool initialized;

			// A boolean value that indicates whether or not the game loop is currently running. DO NOT set
			// this value directly.
			bool running;
		public:
			// Creates a new instance of this game.
			IGame();

			// Destroys this instance of this game.
			~IGame();

			// This method is used for initializing this game's most internal resources. It is
			// not intended to be used for resource loading.
			// caption		-- The title of the window; unused if fullscreen is set to true.
			// width		-- The width of the window. If fullscreen, the width of the backbuffer.
			// height		-- The height of the window. If fullscreen, the height of the backbuffer.
			// fullscreen	-- Whether or not the window should cover the entire screen.
			virtual bool Initialize(const char *caption, uint_t width = 640, uint_t height = 480, bool fullscreen = false);

			// This method is used for uninitializing/freeing this game's most internal resources. It is NOT
			// intended to unload in-game content.
			virtual void Uninitialize();

			// This method is used to load any initial in-game resources (graphics, sounds, etc.) after
			// the 'Initialize' method has been called and succeeded. If any resource-loading fails,
			// 'false' should be returned and the game will throw a proper exception and end. Otherwise,
			// 'true' should be returned.
			virtual bool OnLoad() { return true; }

			// This method is used to unload any in-game resources that were loaded in the 'OnLoad' method. Because
			// this method should only be called at the end of the game, no return value is needed.
			virtual void OnUnload() { }

			// This method is intended to be used to update in-game logic. It should
			// be designed to be as fast as possible as it can drastically affect the real FPS. When the game's logic
			// is finished being updated, a value of 'true' should be returned unless the logic calls for the game to end,
			// in which case, 'false' should be returned.
			// delta		-- The current timing information.
			virtual bool Update(const GameTime& delta) { return true; } 

			// This method is intended to be used to render in-game content. It should
			// be designed to be as fast as possible. When the rendering is finished, a value of 'true' should be
			// returned. If an error occurs, a value of 'false' should be returned. However, if the error is non-critical
			// and can be handled with no interruption, a value of 'true' should be returned so as not to end the game
			// unnecessarily.
			// delta		-- The current timing information.
			virtual bool Draw(const GameTime& delta) { return true; }

			// This method is intended to run the game. It manages the game loop and will not return until the game has finished,
			// as indicated by Update or Draw returning false, or the Stop method being called.
			// Each parameter of this method corresponds to the same parameters as declared in Initialize.
			virtual void Run(const char *caption, uint_t width = 640, uint_t height = 480, bool fullscreen = false);

			// This method is intended to stop the execution of this game. Calling this method WILL trigger the OnUnload and Uninitialize methods.
			virtual void Stop();

			// This method sets the desired FPS member of this class. There is no guarentee that this FPS will actually
			// be reached, however.
			virtual inline void SetDesiredFPS(uint_t fps) { desiredFPS = fps; }

			// Gets the current value of the desired FPS member of this class.
			virtual inline uint_t GetDesiredFPS() { return desiredFPS; }

			// Gets the real-time FPS calculation. The value returned by this method is accurate up to the previous frame.
			virtual inline float GetFPS() { return realFPS; }
		};
	}
}

#endif /* _TEKSTORM_IGAME_H */