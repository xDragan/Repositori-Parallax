#ifndef __MODULESCENEWIN_H__
#define __MODULESCENEWIN_H__

#include "Module.h"

struct SDL_Texture;

class ModuleSceneWin : public Module
{
public:
	ModuleSceneWin();
	~ModuleSceneWin();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* background = nullptr;
	uint fx = 0;
};

#endif // __MODULESCENEWIN_H__