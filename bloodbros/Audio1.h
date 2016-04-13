#ifndef _AUDIO1_H
#define _AUDIO1_H
#include "Globals.h"
#include "Module.h"
#include "SDL_mixer\include\SDL_mixer.h"


class ModuleAudio1 :public Module
{
public:
	ModuleAudio1();
	~ModuleAudio1();

	bool Start();
	bool CleanUp();
	Mix_Music *music1;
	Mix_Music *Load();

};

#endif