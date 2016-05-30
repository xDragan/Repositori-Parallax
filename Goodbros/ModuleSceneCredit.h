#ifndef __MODULEVICTORY_H__
#define __MODULEVICTORY_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleSceneCredit : public Module
{
public:
	ModuleSceneCredit();
	~ModuleSceneCredit();

	update_status Update();

	bool Start();
	bool CleanUp();
	
	Text* player_name;
	Text* score_counter;

public:

	SDL_Texture* background = nullptr;
	SDL_Rect victoryscreen;
};

#endif // __MODULEVICTORY_H__