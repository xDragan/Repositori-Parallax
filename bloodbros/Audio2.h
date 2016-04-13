#ifndef _AUDIO2_H
#define _AUDIO2_H
#include "Globals.h"
#include "Module.h"
#include "SDL_mixer\include\SDL_mixer.h"


class ModuleAudio2 :public Module
{
public:
	ModuleAudio2();
	~ModuleAudio2();

	bool Start();
	bool CleanUp();
	Mix_Music *music2;
	Mix_Music *Load();

};

#endif