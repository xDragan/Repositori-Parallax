#include"Audio0.h"
#include "SDL_mixer\include\SDL_mixer.h"
#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )
#include "Globals.h"
ModuleAudio0::ModuleAudio0(){ };
ModuleAudio0::~ModuleAudio0(){ };

bool ModuleAudio0::Start()
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

Mix_Music* ModuleAudio0::Load(){
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
	music0 = Mix_LoadMUS("TittleScreen.wav");
	Mix_PlayMusic(music0, -1);
	return music0;
}



bool ModuleAudio0::CleanUp(){
	LOG("Freeing textures and Audio library");
	Mix_CloseAudio();
	Mix_FreeMusic(music0);
	music0 = NULL;
	return true;
}


