#define TEKSTORM_BUILD
#include "FMODSoundEffectInstance.h"
#include "FMOD/fmod.hpp"

namespace Tekstorm
{
	namespace Sound
	{
		FMODSoundEffectInstance::FMODSoundEffectInstance(FMODSoundEffect *parent, void *chan, int id)
		{
			mChannel = chan;
			mParentEffect = parent;
			mId = id;
		}

		FMODSoundEffectInstance::~FMODSoundEffectInstance()
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
		void *FMODSoundEffectInstance::GetHandle() const
		{
			return mChannel;
		}

		/*
		** Destroys this resource and all memory it uses. Once this method is called,
		** the resource can no longer be used.
		*/
		void FMODSoundEffectInstance::Release()
		{
			Stop();
			mChannel = 0;
		}

		/*
		** Sets the volume that this sound effect is played at.
		** Parameters
		**	volume		- a value between 0 and 1 indicating the volume (0 = mute, 1 = full)
		** Returns
		**	nothing
		*/
		void FMODSoundEffectInstance::SetVolume(float volume)
		{
			FMOD::Channel *chan = (FMOD::Channel *)mChannel;
			chan->setVolume(volume);
		}

		/*
		** Gets the volume that this sound is currently being played at.
		** Parameters
		**	none
		** Returns
		**	the volume
		*/
		float FMODSoundEffectInstance::GetVolume() const
		{
			FMOD::Channel *chan = (FMOD::Channel *)mChannel;
			float flt;
			chan->getVolume(&flt);

			return flt;
		}

		/*
		** Sets the pan of this sound.
		** Parameters
		**	pan		- a value between -1.0 and 1.0 where -1 is far left, and 1 is far right.
		** Returns
		**	nothing
		*/
		void FMODSoundEffectInstance::SetPan(float pan)
		{
			FMOD::Channel *chan = (FMOD::Channel *)mChannel;
			chan->setPan(pan);
		}

		/*
		** Gets the pan of this sound.
		** Parameters
		**	none
		** Returns
		**	the pan
		*/
		float FMODSoundEffectInstance::GetPan() const
		{
			FMOD::Channel *chan = (FMOD::Channel *)mChannel;
			float pn;
			chan->getPan(&pn);
			return pn;
		}

		/*
		** Stops this instance from playing.
		** Parameters
		**	none
		** Returns
		**	nothing
		*/
		void FMODSoundEffectInstance::Stop()
		{
			FMOD::Channel *chan = (FMOD::Channel *)mChannel;
			chan->stop();
		}
	}
}