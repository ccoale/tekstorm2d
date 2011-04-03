#pragma once
#ifndef _TEKSTORM_FMODSOUNDMANAGER_H
#define _TEKSTORM_FMODSOUNDMANAGER_H
#include "FMODSoundEffect.h"
#include "ISoundManager.h"
#include <map>

namespace Tekstorm
{
	namespace Sound
	{
		class ISoundEffect;
		class FMODSoundEffect;
		class FMODSoundManager : public ISoundManager
		{
		private:
			std::map<int, FMODSoundEffect *> mSoundEffects;
			void *mSystem;
		public:
			/*
			** Initializes a new instance of FMODSoundManager.
			*/
			FMODSoundManager();

			/*
			** Destroys this instance of FMODSoundManager.
			*/
			~FMODSoundManager();

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
			** Creates a new sound effect.
			*/
			ISoundEffect *LoadSoundEffect(const char *filePath, int id);

			/*
			** Finds a sound effect given its ID.
			*/
			ISoundEffect *FindSoundEffectByID(int id);
		};
	}
}

#endif /* _TEKSTORM_ISOUNDMANAGER_H */