#ifndef __ModuleAim_H__
#define __ModuleAim_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;
struct Collider;

class ModuleAim : public Module
{
public:
	ModuleAim();
	~ModuleAim();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	SDL_Texture* graphics = nullptr;
	SDL_Rect rearsight;
	Collider* Aim;
	Animation* current_animation = nullptr;
	Animation aim;
	Animation idle;
	iPoint position;
};

#endif