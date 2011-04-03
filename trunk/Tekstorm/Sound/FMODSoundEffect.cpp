#define TEKSTORM_BUILD
#include "../CommonUtils.h"
#include "FMODSoundEffect.h"
#include "../Exception.h"
#include "FMOD/fmod.hpp"

namespace Tekstorm
{
	namespace Sound
	{
		/*
		** Initializes a new instance of FMODSoundEffect
		*/
		FMODSoundEffect::FMODSoundEffect(FMODSoundManager *manager, const char *szPath) : volume(1.0f), pan(0.0f), mLastInstance(0), mLastIndex(-1)
		{
			if (!manager || !szPath)
				throw Exception("invalid argument");

			FMOD::System *sys = (FMOD::System *)manager->GetHandle();
			if (! sys)
				throw Exception("FMOD Sound System has not been intialized");

			FMOD::Sound *sound = 0;
			if (sys->createSound(szPath, FMOD_DEFAULT, 0, &sound) != FMOD_OK)
				throw Exception("could not load sound");

			mSound = (void *)sound;
			mManager = manager;
		}

		/*
		** Destroys this instance of FMODSoundEffect.
		** Parameters
		**	none
		** Returns
		**	nothing
		*/
		FMODSoundEffect::~FMODSoundEffect()
		{
			Release();
		}

		/*
		** Gets the underlying resource handle.
		** Parameters
		**	none
		** Returns
		**	nothing
		*/
		void *FMODSoundEffect::GetHandle() const
		{
			return mSound;
		}

		/*
		** Destroys this resource and all memory it uses. Once this method is called,
		** the resource can no longer be used.
		*/
		void FMODSoundEffect::Release()
		{
			Stop();

			auto it = mInstances.begin();
			for (; it != mInstances.end(); it++)
			{
				(*it).second->Release();
				delete (*it).second;
				(*it).second = 0;
			}

			mInstances.clear();
		}

		/*
		** Sets the volume that this sound effect is played at.
		** Parameters
		**	volume		- a value between 0 and 1 indicating the volume (0 = mute, 1 = full)
		** Returns
		**	nothing
		*/
		void FMODSoundEffect::SetVolume(float vol)
		{
			volume = vol;
		}

		/*
		** Gets the volume that this sound is currently being played at.
		** Parameters
		**	none
		** Returns
		**	the volume
		*/
		float FMODSoundEffect::GetVolume() const
		{
			return volume;
		}

		/*
		** Sets the pan of this sound.
		** Parameters
		**	pan		- a value between -1.0 and 1.0 where -1 is far left, and 1 is far right.
		** Returns
		**	nothing
		*/
		void FMODSoundEffect::SetPan(float p)
		{
			pan = p;
		}

		/*
		** Gets the pan of this sound.
		** Parameters
		**	none
		** Returns
		**	the pan
		*/
		float FMODSoundEffect::GetPan() const
		{
			return pan;
		}

		/*
		** Plays this sound effect.
		** Parameters
		**	newInstance		- whether or not a new sound effect instance should be created.
		**					- a new sound effect instance can control volume, pan, etc.
		**					- if this is false, only one instance will exist which means that
		**					- if the current sound is playing, it will be stopped.
		**	autoDestroy		- whether or not the instance returned should be automatically destroyed
		**					- when the instance is done playing (this is recommended)
		** Returns
		**	the new, or current (depending on the value of newInstance), sound effect instance.
		*/
		ISoundEffectInstance *FMODSoundEffect::Play(bool newInstance)
		{
			FMOD::Sound *sound = (FMOD::Sound *)mSound;
			FMOD::System *sys = (FMOD::System *)mManager->GetHandle();
			FMOD::Channel *chan;
			if (newInstance) {
				if (sys->playSound(FMOD_CHANNEL_FREE, sound, true, &chan) != FMOD_OK)
					return 0;
				mLastInstance = (void *)chan;
				chan->setPaused(true);
				// now we need to create a new ISoundEffectInstance
				int id = CommonUtils::GetId();
				FMODSoundEffectInstance *inst = new FMODSoundEffectInstance(this, mLastInstance, id);
				mInstances[id] = inst;
				mLastIndex = id;
			} else {
				chan = (FMOD::Channel *)mLastInstance;
				chan->setPaused(true);
				chan->setPosition(0, FMOD_TIMEUNIT_MS);
			}
			chan->setVolume(volume);
			chan->setPan(pan);
			chan->setPaused(false);

			return mInstances[mLastIndex];
		}

		/*
		** Stops ALL instances from playing and resets their seek position.
		** Parameters
		**	none
		** Returns
		**	nothing
		*/
		void FMODSoundEffect::Stop()
		{
			auto it = mInstances.begin();
			for (; it != mInstances.end(); it++)
				(*it).second->Stop();
		}
	}
}