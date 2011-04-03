#define TEKSTORM_BUILD
#pragma comment(lib, "fmodex_vc.lib")
#include "FMOD/fmod.hpp"
#include "FMODSoundManager.h"
#include "../Exception.h"


namespace Tekstorm
{
	namespace Sound
	{
			/*
			** Initializes a new instance of FMODSoundManager.
			*/
			FMODSoundManager::FMODSoundManager()
			{
				FMOD::System *sys = 0;
				if (FMOD::System_Create(&sys) != FMOD_OK)
				{
					throw Exception("Unable to create FMOD Sound System");
				}

				mSystem = (void *)sys;

				if (sys->init(100, FMOD_INIT_NORMAL, 0) != FMOD_OK)
					throw Exception("Unable to initialize FMOD Sound System");
			}

			/*
			** Destroys this instance of FMODSoundManager.
			*/
			FMODSoundManager::~FMODSoundManager()
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
			void *FMODSoundManager::GetHandle() const
			{
				return mSystem;
			}

			/*
			** Destroys this resource and all memory it uses. Once this method is called,
			** the resource can no longer be used.
			*/
			void FMODSoundManager::Release()
			{
				// first we need to release all sounds
				auto it = mSoundEffects.begin();
				for (; it != mSoundEffects.end(); it++)
				{
					(*it).second->Release();
					it = mSoundEffects.erase(it);
				}

				FMOD::System *sys = (FMOD::System *)mSystem;
				sys->close();
				mSystem = 0;
			}

			/*
			** Creates a new sound effect.
			*/
			ISoundEffect *FMODSoundManager::LoadSoundEffect(const char *filePath, int id)
			{
				FMODSoundEffect *eff = new FMODSoundEffect(this, filePath);
				mSoundEffects[id] = eff;

				return (ISoundEffect *)eff;
			}

			/*
			** Finds a sound effect given its ID.
			*/
			ISoundEffect *FMODSoundManager::FindSoundEffectByID(int id)
			{
				auto it = mSoundEffects.begin();
				if ((it = mSoundEffects.find(id)) != mSoundEffects.end())
					return (*it).second;

				return 0;
			}
	}
}