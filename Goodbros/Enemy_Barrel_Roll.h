#ifndef __ENEMY_BARREL_ROLL_H__
#define __ENEMY_BARREL_ROLL_H__

#include "Enemy.h"

class Enemy_Barrel_Roll : public Enemy
{
private:
	bool going_forward = true;
	bool stop = false;

	Animation forward;
	Animation backward;

	iPoint original_pos;
public:

	Enemy_Barrel_Roll(float x, float y);
	void Move();
};

#endif // __ENEMY_BARREL_ROLL_H__