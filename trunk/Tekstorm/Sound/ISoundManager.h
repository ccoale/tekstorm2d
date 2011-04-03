#pragma once
#ifndef _TEKSTORM_ISOUNDMANAGER_H
#define _TEKSTORM_ISOUNDMANAGER_H
#include "ISoundEffect.h"

namespace Tekstorm
{
	namespace Sound
	{
		class ISoundEffect;
		class ISoundManager : public IResource
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
			** Creates a new sound effect.
			*/
			virtual ISoundEffect *LoadSoundEffect(const char *filePath, int id) = 0;

			/*
			** Finds a sound effect given its ID.
			*/
			virtual ISoundEffect *FindSoundEffectByID(int id) = 0;
		};
	}
}

#endif /* _TEKSTORM_ISOUNDMANAGER_H */