#ifndef _AUDIO0_H
#define _AUDIO0_H

#include "Globals.h"
#include "Module.h"
#include "SDL_mixer\include\SDL_mixer.h"

#define DEFAULT_MUSIC_FADE_TIME 2.0f
#define MAX_FX 200

class ModuleAudio :public Module
{
public:
	ModuleAudio();
	~ModuleAudio();
public:
	bool Start();
	bool CleanUp();
	Mix_Music *music;
	Mix_Music *Load(const char*location);
	bool PlayMusic(const char* path, float fade_time = DEFAULT_MUSIC_FADE_TIME);
	bool Disable();
	// Load a WAV in memory
	uint LoadFx(const char* path);
	bool UnLoadFx(uint id);

	// Play a previously loaded WAV
	bool PlayFx(unsigned int fx);

private:

	Mix_Chunk*	fx[MAX_FX];
	uint		last_fx = 1;
};

#endif