#pragma once
#ifndef _TEKSTORM_ISOUNDEFFECT_H
#define _TEKSTORM_ISOUNDEFFECT_H
#include "SoundConf.h"
#include "ISoundEffectInstance.h"

namespace Tekstorm
{
	namespace Sound
	{
		/*
		** Abstract class used for playing sound effects.
		*/
		class ISoundEffect : public IResource
		{
		public:
			/*
			** Gets the underlying resource handle.
			** Parameters
			**	none
			** Returns
			**	nothing
			*/
			virtual void *GetHandle() const = 0;

			/*
			** Destroys this resource and all memory it uses. Once this method is called,
			** the resource can no longer be used.
			*/
			virtual void Release() = 0;

			/*
			** Sets the volume that this sound effect is played at.
			** Parameters
			**	volume		- a value between 0 and 1 indicating the volume (0 = mute, 1 = full)
			** Returns
			**	nothing
			*/
			virtual void SetVolume(float volume) { }

			/*
			** Gets the volume that this sound is currently being played at.
			** Parameters
			**	none
			** Returns
			**	the volume
			*/
			virtual float GetVolume() const { return 0.0f; }

			/*
			** Sets the pan of this sound.
			** Parameters
			**	pan		- a value between -1.0 and 1.0 where -1 is far left, and 1 is far right.
			** Returns
			**	nothing
			*/
			virtual void SetPan(float pan) { }

			/*
			** Gets the pan of this sound.
			** Parameters
			**	none
			** Returns
			**	the pan
			*/
			virtual float GetPan() const { return 0.0f; }

			/*
			** Plays this sound effect.
			** Parameters
			**	newInstance		- whether or not a new sound effect instance should be created.
			**					- a new sound effect instance can control volume, pan, etc.
			**					- if this is false, only one instance will exist which means that
			**					- if the current sound is playing, it will be stopped.
			** Returns
			**	the new, or current (depending on the value of newInstance), sound effect instance.
			*/
			virtual ISoundEffectInstance *Play(bool newInstance) = 0;

			/*
			** Stops ALL instances from playing and resets their seek position.
			** Parameters
			**	none
			** Returns
			**	nothing
			*/
			virtual void Stop() { }
		};
	}
}

#endif /* _TEKSTORM_ISOUNDEFFECT_H */