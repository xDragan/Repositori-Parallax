#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "ModuleParticles.h"
#include "p2Point.h"

struct SDL_Texture;
struct Collider;

enum type
{
	IDLE,
	LEFT,
	RIGHT,
	DOWN,
	SHOOTING,
	SHOOTING_DOWN,
	ROLLING,
	DIE,
	WIN,

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
	int win_condition=0;
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
	Animation die;
	Animation win;
	Animation windance;
	Animation staydied;
	//GOD MODE
	Animation gidle[7];
	Animation gforward;
	Animation gbackward;
	Animation gshoot[7];
	Animation gshootdown[7];
	Animation gdown[7];
	Animation gftumble;
	Animation gbtumble;
	Animation gdownftumble;
	Animation gdownbtumble;
	Animation gwin;
	Animation gwindance;

	iPoint position;
	bool dying = false;
	Particle deathsound;
	uint timedied;
	bool godmode = false;
	bool blink = true;
	bool played = false;

	float speed = 0;

	int blink_t = 0;
	int Looking_at = 0;
	int AimSpeed = 0;
	int c_time = 0;
	int dmg_cd = 0;
	int lose = 0;
	bool lost = false;
	int timeout = 0;
};

#endif