#ifndef __MODULETITLESCREEN_H__
#define __MODULETITLESCREEN_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleTitleScreen : public Module
{
public:
	ModuleTitleScreen();
	~ModuleTitleScreen();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Rect titlescreen;
};

#endif // __MODULETITLESCREEN_H__