#ifndef __MODULESCENEPRESTAGE_H__
#define __MODULESCENEPRESTAGE_H__

#include "Module.h"

struct SDL_Texture;

class ModuleScenePreStage : public Module
{
public:
	ModuleScenePreStage();
	~ModuleScenePreStage();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* background = nullptr;
	SDL_Texture* lvls = nullptr;
	uint fx = 0;
};

#endif // __MODULESCENEPRESTAGE_H__