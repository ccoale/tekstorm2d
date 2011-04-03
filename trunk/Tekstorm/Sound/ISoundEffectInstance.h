#pragma once
#ifndef _TEKSTORM_ISOUNDEFFECTINSTANCE_H
#define _TEKSTORM_ISOUNDEFFECTINSTANCE_H
#include "SoundConf.h"

namespace Tekstorm
{
	namespace Sound
	{
		/*
		** Abstract class used for playing sound effects.
		*/
		class ISoundEffectInstance : public IResource
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
			** Stops this instance from playing.
			** Parameters
			**	none
			** Returns
			**	nothing
			*/
			virtual void Stop() { }
		};
	}
}

#endif /* _TEKSTORM_ISOUNDEFFECTINSTANCE_H */