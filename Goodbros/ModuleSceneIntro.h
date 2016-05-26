#ifndef __MODULESCENEINTRO_H__
#define __MODULESCENEINTRO_H__

#include "Module.h"
#include "SDL\include\SDL.h"
struct SDL_Texture;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro();
	~ModuleSceneIntro();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	SDL_Texture* background = nullptr;
	uint ticks;
	uint fx = 0;
};

#endif // __MODULESCENEINTRO_H__