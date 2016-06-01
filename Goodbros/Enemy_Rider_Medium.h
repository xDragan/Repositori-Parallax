#ifndef __ENEMY_RIDER_MEDIUM_H__
#define __ENEMY_RIDER_MEDIUM_H__

#include "Enemy.h"

class Enemy_Rider_Medium : public Enemy
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

	Enemy_Rider_Medium(float x, float y);
	void Die();
	void Move();
	bool hit = false;
};

#endif // __ENEMY_COWBOY_GREEN_H__