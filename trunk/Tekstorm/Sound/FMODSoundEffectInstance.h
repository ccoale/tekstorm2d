#pragma once
#ifndef _TEKSTORM_FMODSOUNDEFFECTINSTANCE_H
#define _TEKSTORM_FMODSOUNDEFFECTINSTANCE_H
#include "ISoundEffectInstance.h"
#include "FMODSoundEffect.h"
namespace Tekstorm
{
	namespace Sound
	{
		class TEKAPI FMODSoundEffect;

		class TEKAPI FMODSoundEffectInstance : public ISoundEffectInstance
		{
			friend class FMODSoundEffect;
		private:
			/*
			** The FMOD::Channel handle
			*/
			void *mChannel;

			/*
			** The ID of this instance
			*/
			int mId;

			/*
			** The SoundEffec that created this instance
			*/
			FMODSoundEffect *mParentEffect;

			FMODSoundEffectInstance(FMODSoundEffect *parent, void *chan, int id);
		public:
			~FMODSoundEffectInstance();

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
			** Stops this instance from playing.
			** Parameters
			**	none
			** Returns
			**	nothing
			*/
			void Stop();
		};
	}
}

#endif /* _TEKSTORM_FMODSOUNDEFFECTINSTANCE_H */