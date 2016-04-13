#ifndef __MODULELEVEL3_H__
#define __MODULELEVEL3_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleLevel3 : public Module
{
public:
	ModuleLevel3();
	~ModuleLevel3();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Rect background;
};

#endif // __MODULELEVEL2_H__