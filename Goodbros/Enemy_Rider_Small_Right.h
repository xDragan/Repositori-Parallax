#ifndef __ENEMY_RIDER_SMALL_RIGHT_H__
#define __ENEMY_RIDER_SMALL_RIGHT_H__

#include "Enemy.h"

class Enemy_Rider_Small_Right : public Enemy
{
private:
	bool going_forward = true;
	bool stop = false;

	Animation backward;
	Animation stop_shoot;
	Animation dieshot;
	Animation dieexplotion;

	bool isdead = false;
	bool spawn = false;
	iPoint original_pos;
public:

	Enemy_Rider_Small_Right(float x, float y);
	void Die();
	void Move();
};

#endif // __ENEMY_COWBOY_GREEN_H__