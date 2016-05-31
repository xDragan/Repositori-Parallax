#ifndef __ENEMY_COWBOY_GREEN_TOP_BAR_H__
#define __ENEMY_COWBOY_GREEN_TOP_BAR_H__

#include "Enemy.h"

class Enemy_CowBoy_Green_Top_Bar : public Enemy
{
private:
	bool going_forward = true;
	bool stop = false;

	Animation forward;
	Animation backward;
	Animation stop_shoot;
	Animation dieshot;
	Animation dieexplotion;
	Animation spawni;
	Animation jump;
	Animation idle;
	Animation crouch;
	

	bool isdead = false;
	bool spawn = false;
	iPoint original_pos;
public:

	Enemy_CowBoy_Green_Top_Bar(float x, float y);
	void Die();
	void Move();
};

#endif // __ENEMY_COWBOY_GREEN_H__