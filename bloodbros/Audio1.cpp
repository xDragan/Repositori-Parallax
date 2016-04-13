#include"Audio1.h"
#include "SDL_mixer\include\SDL_mixer.h"
#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )
#include "Globals.h"


ModuleAudio1::ModuleAudio1(){ };
ModuleAudio1::~ModuleAudio1(){ };

bool ModuleAudio1::Start()
{
	LOG("Init Audio library");
	bool ret = true;

	// load support for the PNG image format
	int audioflags = MIX_INIT_OGG;

	int initted = Mix_Init(audioflags);

	if ((initted) != audioflags)
	{
		LOG("Could not initialize Audio lib. MIX_Init: %s", Mix_GetError());
		ret = false;
	}
	Load();

	return ret;
}

Mix_Music* ModuleAudio1::Load(){
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
	music1 = Mix_LoadMUS("level1.wav");
	Mix_PlayMusic(music1, -1);
	return music1;
}



bool ModuleAudio1::CleanUp(){
	LOG("Freeing textures and Audio library");
	Mix_CloseAudio();
	Mix_FreeMusic(music1);
	music1 = NULL;


	return true;
}