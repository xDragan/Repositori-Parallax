#ifndef __MODULESCENEINTRO2_H__
#define __MODULESCENEINTRO2_H__

#include "Module.h"
#include "SDL\include\SDL.h"

struct SDL_Texture;

class ModuleSceneIntro2 : public Module
{
public:
	ModuleSceneIntro2();
	~ModuleSceneIntro2();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	uint ticks;
	SDL_Texture* background = nullptr;
	SDL_Texture* lvls = nullptr;
	uint fx = 0;
};

#endif // __MODULESCENEPRESTAGE_H__