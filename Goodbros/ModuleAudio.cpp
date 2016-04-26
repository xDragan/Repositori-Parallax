#include"ModuleAudio.h"
#include "SDL_mixer\include\SDL_mixer.h"
#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )
#include "Globals.h"
#include "Application.h"
#include "SDL\include\SDL.h"
ModuleAudio::ModuleAudio(){ };
ModuleAudio::~ModuleAudio(){ };

void ModuleAudio::Enable(int lvl)
{
	if (enabled == false)
	{
		enabled = true;
	}
	Start(lvl);
}

bool ModuleAudio::Start(int lvl) //receives int lvl that will load audio diferently depending on lvl
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
	Load(lvl);

	return ret;
}

Mix_Music* ModuleAudio::Load(int lvl){
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);

	switch (lvl){
	case 0: music = Mix_LoadMUS("bloodbros/TittleScreen.wav");
		break;
	case 1: music = Mix_LoadMUS("bloodbros/level1.wav");
		break;
	case 2: music = Mix_LoadMUS("bloodbros/Victory.wav");
		break;
	case 3: music = Mix_LoadMUS("bloodbros/PreStage.wav");
		break;
	}
	Mix_PlayMusic(music, 0);
	return music;
}

bool ModuleAudio::CleanUp(){
	LOG("Freeing textures and Audio library");
	Mix_CloseAudio();
	Mix_FreeMusic(music);
	music = NULL;
	return true;
}

// Load WAV
uint ModuleAudio::LoadFx(const char* path)
{
	uint ret = 0;
	Mix_Chunk* chunk = Mix_LoadWAV(path);

	if (chunk == nullptr)
	{
		LOG("Cannot load wav %s. Mix_GetError(): %s", path, Mix_GetError());
	}
	else
	{
		fx[last_fx] = chunk;
		ret = last_fx++;
	}

	return ret;
}

// UnLoad WAV
bool ModuleAudio::UnLoadFx(uint id)
{
	bool ret = false;

	if (fx[id] != nullptr)
	{
		Mix_FreeChunk(fx[id]);
		fx[id] = nullptr;
		ret = true;
	}

	return ret;
}

// Play WAV
bool ModuleAudio::PlayFx(uint id)
{
	bool ret = false;

	if (fx[id] != nullptr)
	{
		Mix_PlayChannelTimed(-1, fx[id], 1, 250);
		ret = true;
	}

	return ret;
}