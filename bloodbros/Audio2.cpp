#include"Audio2.h"
#include "SDL_mixer\include\SDL_mixer.h"
#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )
#include "Globals.h"


ModuleAudio2::ModuleAudio2(){ };
ModuleAudio2::~ModuleAudio2(){ };

bool ModuleAudio2::Start()
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

Mix_Music* ModuleAudio2::Load(){
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
	music2 = Mix_LoadMUS("Victory.wav");
	Mix_PlayMusic(music2, -1);
	return music2;
}



bool ModuleAudio2::CleanUp(){
	LOG("Freeing textures and Audio library");
	Mix_CloseAudio();
	Mix_FreeMusic(music2);
	music2 = NULL;


	return true;
}