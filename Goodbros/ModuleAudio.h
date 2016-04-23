#ifndef _AUDIO0_H
#define _AUDIO0_H
#include "Globals.h"
#include "Module.h"
#include "SDL_mixer\include\SDL_mixer.h"
#define N_MUSIC 4

class ModuleAudio :public Module
{
public:
	ModuleAudio();
	~ModuleAudio();
public:
	bool Start(int lvl);
	bool CleanUp();
	Mix_Music *music;
	Mix_Music *Load(int lvl);
};

#endif