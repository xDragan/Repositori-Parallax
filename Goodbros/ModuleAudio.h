#ifndef _AUDIO0_H
#define _AUDIO0_H
#include "Globals.h"
#include "Module.h"
#include "SDL_mixer\include\SDL_mixer.h"

#define N_MUSIC 4
#define MAX_FX 200

class ModuleAudio :public Module
{
public:
	ModuleAudio();
	~ModuleAudio();
public:
	void Enable(int lvl);
	bool Start(int lvl);
	bool CleanUp();
	Mix_Music *music;
	Mix_Music *Load(int lvl);

	// Load a WAV in memory
	uint LoadFx(const char* path);
	bool UnLoadFx(uint id);

	// Play a previously loaded WAV
	bool PlayFx(unsigned int fx, int repeat = 0);

private:

	Mix_Chunk*	fx[MAX_FX];
	uint			last_fx = 1;
};

#endif