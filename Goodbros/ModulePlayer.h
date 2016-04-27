#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"
#include "SDL\include\SDL.h"

struct SDL_Texture;
struct Collider;

class ModulePlayer : public Module
{
public:
	enum type
	{
		NORMAL,
		ROLLING,
	};
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
	int const looking_at();
public:
	Collider* player_coll;
public:
	type Status;
	SDL_Texture* graphics = nullptr;
	SDL_Rect cowboy;
	Animation* current_animation = nullptr;
	Animation idle[7];
	Animation forward;
	Animation backward;
	Animation shoot[7];
	Animation shootdown[7];
	Animation down[7];
	Animation ftumble;
	Animation btumble;
	Animation downftumble;
	Animation downbtumble;
	iPoint position;
	Animation die;
	Animation win;
	Animation windance;

	int timeout = 0;
};

#endif