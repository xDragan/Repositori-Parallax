#ifndef __ENEMY_COWBOY_BLUE_TOP_SMALL_H__
#define __ENEMY_COWBOY_BLUE_TOP_SMALL_H__

#include "Enemy.h"

class Enemy_CowBoy_Blue_Top_Small : public Enemy
{
private:
	bool going_forward = true;
	bool stop = false;

	Animation forward;
	Animation backward;
	Animation dieshot;
	Animation dieexplotion;
	Animation fwtumble;
	Animation grenadeSm;;
	Animation spawnn;

	bool isdead = false;

	iPoint original_pos;
public:

	Enemy_CowBoy_Blue_Top_Small(float x, float y);
	void Die();
	void Move();
};

#endif //  __ENEMY_COWBOY_BLUE_TOP_SMALL_H__