#ifndef _AUDIO3_H
#define _AUDIO3_H
#include "Globals.h"
#include "Module.h"
#include "SDL_mixer\include\SDL_mixer.h"


class ModuleAudio3 :public Module
{
public:
	ModuleAudio3();
	~ModuleAudio3();

	bool Start();
	bool CleanUp();
	Mix_Music *music3;
	Mix_Music *Load();

};

#endif