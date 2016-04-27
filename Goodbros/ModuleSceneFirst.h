#ifndef __ModuleSceneFirst_H__
#define __ModuleSceneFirst_H__

#include "Module.h"

struct SDL_Texture;

class ModuleSceneFirst : public Module
{
public:
	ModuleSceneFirst();
	~ModuleSceneFirst();

	bool Start();
	update_status Update();
	bool CleanUp();
	uint enemy;
	bool spawn=false;
	uint time = 0;
	uint time2 = 0;
	uint time3 = 0;
public:
	
	SDL_Texture* background = nullptr;
	SDL_Texture* houses = nullptr;
};

#endif // __ModuleSceneFirst_H__
