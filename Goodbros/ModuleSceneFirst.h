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

public:
	
	SDL_Texture* background = nullptr;
	SDL_Texture* stars = nullptr;
};

#endif // __ModuleSceneFirst_H__
