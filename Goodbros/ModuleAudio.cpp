#include"ModuleAudio.h"
#include "SDL_mixer\include\SDL_mixer.h"
#include "Globals.h"
#include "Application.h"
#include "SDL\include\SDL.h"

#pragma comment(lib, "SDL_mixer/libx86/SDL2_mixer.lib")

ModuleAudio::ModuleAudio(){ };
ModuleAudio::~ModuleAudio(){ };

bool ModuleAudio::Start() //receives int lvl that will load audio diferently depending on lvl
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

	return ret;
}

Mix_Music* ModuleAudio::Load(const char*location)
{
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
	music=Mix_LoadMUS(location);
	Mix_PlayMusic(music, -1);
	return music;
}

bool ModuleAudio::Disable()
{
	LOG("music clean");
	Mix_FreeMusic(music);
	music = NULL;
	return true;
}

bool ModuleAudio::CleanUp()
{
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
bool ModuleAudio::PlayFx(uint id, uint duration)
{
	bool ret = false;

	if (fx[id] != nullptr)
	{
		Mix_PlayChannelTimed(-1, fx[id], 1, duration);
		ret = true;
	}

	return ret;
}

// Play a music file
bool ModuleAudio::PlayMusic(const char* path, float fade_time)
{
	bool ret = true;

	if (music != NULL)
	{
		if (fade_time > 0.0f)
		{
			Mix_FadeOutMusic((int)(fade_time * 1000.0f));
		}
		else
		{
			Mix_HaltMusic();
		}

		// this call blocks until fade out is done
		Mix_FreeMusic(music);
	}

	music = Mix_LoadMUS(path);

	if (music == NULL)
	{
		LOG("Cannot load music %s. Mix_GetError(): %s\n", path, Mix_GetError());
		ret = false;
	}
	else
	{
		if (fade_time > 0.0f)
		{
			if (Mix_FadeInMusic(music, -1, (int)(fade_time * 1000.0f)) < 0)
			{
				LOG("Cannot fade in music %s. Mix_GetError(): %s", path, Mix_GetError());
				ret = false;
			}
		}
		else
		{
			if (Mix_PlayMusic(music, -1) < 0)
			{
				LOG("Cannot play in music %s. Mix_GetError(): %s", path, Mix_GetError());
				ret = false;
			}
		}
	}

	LOG("Successfully playing %s", path);
	return ret;
}