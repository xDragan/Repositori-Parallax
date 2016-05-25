#ifndef __ENEMY_CAN_H__
#define __ENEMY_CAN_H__

#include "Enemy.h"

class Enemy_Can : public Enemy
{
private:
	float original_y = 0;

	Animation iddle;
	Animation leftfly;
	Animation rightfly;

	iPoint original_pos;
public:

	Enemy_Can(float x, float y);
	void Die();
	bool hit = false;
	uint fly = 0;
	void Move();
};

#endif // __ENEMY_CAN_H__