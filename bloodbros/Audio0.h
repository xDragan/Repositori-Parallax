#ifndef _AUDIO0_H
#define _AUDIO0_H
#include "Globals.h"
#include "Module.h"
#include "SDL_mixer\include\SDL_mixer.h"


class ModuleAudio0 :public Module
{
public:
	ModuleAudio0();
	~ModuleAudio0();

	bool Start();
	bool CleanUp();
	Mix_Music *music0;
	Mix_Music *Load();

};

#endif