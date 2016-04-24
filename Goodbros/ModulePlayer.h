#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;
struct Collider;

class ModulePlayer : public Module
{
public:
	enum SCREEN_PORTION
	{
		far_left = 0,
		Middle_left,
		near_left,
		middle,
		near_right,
		middle_right,
		far_right,
	};
public:
	ModulePlayer();
	~ModulePlayer();
public:
	bool Start();
	update_status Update();
	bool CleanUp();
	int const portion_calculate();
public:
	Collider* player_coll;
public:
	SDL_Texture* graphics = nullptr;
	SDL_Rect cowboy;
	Animation* current_animation = nullptr;
	Animation idle[7];
	Animation forward;
	Animation backward;
	Animation shoot;
	Animation down[7];
	Animation ftumble;
	Animation btumble;
	Animation downftumble;
	Animation downbtumble;
	iPoint position;
	iPoint Aimposition;
	
};

#endif