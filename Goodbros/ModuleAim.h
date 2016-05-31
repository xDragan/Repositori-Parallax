#ifndef __ModuleAim_H__
#define __ModuleAim_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"
#include "ModulePlayer.h"
#include "SDL/include/SDL_timer.h"

struct SDL_Texture;
struct Collider;
enum AIMTYPE{
	NORMAL,
	SHOTGUN,
	MACHINEGUN,
};
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
	Animation Aimshoot;
	Animation Aimshotgunshot;
	Animation Aimshotgun;
	Animation Aimmachine;
	Animation aimmachinegunshot;
	unsigned int time = 0;
	iPoint position;
	uint shotgunshots = 0;
	uint machineshots = 0;
	uint aimmode = NORMAL;
	bool normalaim = true;
};

#endif