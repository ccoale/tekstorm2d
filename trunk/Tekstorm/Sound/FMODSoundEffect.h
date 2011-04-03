#pragma once
#ifndef _TEKSTORM_FMODSOUNDEFFECT_H
#define _TEKSTORM_FMODSOUNDEFFECT_H
#include "ISoundEffect.h"
#include "FMODSoundManager.h"
#include "FMODSoundEffectInstance.h"
#include <map>

namespace Tekstorm
{
	namespace Sound
	{
		//class ISoundManager;
		/*
		** SoundEffect class used to play sounds via FMODEx.
		*/
		class TEKAPI FMODSoundEffect : public ISoundEffect
		{
			friend class FMODSoundManager;
		private:
			/*
			** List of sound effect instances that are currently running.
			*/
			std::map<int, ISoundEffectInstance *> mInstances;

			/*
			** The handle to the underlyig FMOD_Sound
			*/
			void *mSound;

			/*
			** The last played instance
			*/
			void *mLastInstance;

			/*
			** The index of the last sound effect instance
			*/
			int mLastIndex;

			/*
			** The owner of this sound effect.
			*/
			FMODSoundManager *mManager;

			/*
			** The "global" volume.
			*/
			float volume;

			/*
			** The "global" pan.
			*/
			float pan;

			/*
			** Initializes a new instance of FMODSoundEffect
			*/
			FMODSoundEffect(FMODSoundManager *manager, const char *szPath);
		public:
			/*
			** Destroys this instance of FMODSoundEffect.
			** Parameters
			**	none
			** Returns
			**	nothing
			*/
			~FMODSoundEffect();

			/*
			** Gets the underlying resource handle.
			** Parameters
			**	none
			** Returns
			**	nothing
			*/
			void *GetHandle() const;

			/*
			** Destroys this resource and all memory it uses. Once this method is called,
			** the resource can no longer be used.
			*/
			void Release();

			/*
			** Sets the volume that this sound effect is played at.
			** Parameters
			**	volume		- a value between 0 and 1 indicating the volume (0 = mute, 1 = full)
			** Returns
			**	nothing
			*/
			void SetVolume(float volume);

			/*
			** Gets the volume that this sound is currently being played at.
			** Parameters
			**	none
			** Returns
			**	the volume
			*/
			float GetVolume() const;

			/*
			** Sets the pan of this sound.
			** Parameters
			**	pan		- a value between -1.0 and 1.0 where -1 is far left, and 1 is far right.
			** Returns
			**	nothing
			*/
			void SetPan(float pan);

			/*
			** Gets the pan of this sound.
			** Parameters
			**	none
			** Returns
			**	the pan
			*/
			float GetPan() const;

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
			ISoundEffectInstance *Play(bool newInstance = true);

			/*
			** Stops ALL instances from playing and resets their seek position.
			** Parameters
			**	none
			** Returns
			**	nothing
			*/
			void Stop();
		};
	}
}

#endif /* _TEKSTORM_FMODSOUNDEFFECT_H */