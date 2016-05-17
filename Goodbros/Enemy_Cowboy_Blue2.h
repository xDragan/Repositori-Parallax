#ifndef __ENEMY_COWBOY_BLUE2_H__
#define __ENEMY_COWBOY_BLUE2_H__

#include "Enemy.h"

class Enemy_CowBoy_Blue2 : public Enemy
{
private:
	bool going_forward = true;
	bool stop = false;

	Animation forward;
	Animation backward;
	Animation stop_shoot;
	Animation dieshot;
	Animation dieexplotion;
	Animation fwtumble;
	Animation fwtumbleshoot;
	Animation bwtumble;
	Animation bwtumbleshoot;
	Animation grenade;
	Animation jump;

	bool isdead = false;

	iPoint original_pos;

public:
	Enemy_CowBoy_Blue2(float x, float y);
	void Die();
	void Move();
};

#endif // __ENEMY_COWBOY_BLUE2_H__