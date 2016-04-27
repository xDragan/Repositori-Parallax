#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;
struct Collider;

enum type
{
	NORMAL,
	ROLLING,
	DIE,
};
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
	update_status Update();
	bool CleanUp();
	bool Start();
	int looking_at() const;

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
	bool lose = 0;
	int timeout = 0;
};

#endif