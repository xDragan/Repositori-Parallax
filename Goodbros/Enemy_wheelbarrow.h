#ifndef __ENEMY_wheelbarrow_H__
#define __ENEMY_wheelbarrow_H__

#include "Enemy.h"

class Enemy_wheelbarrow : public Enemy
{
private:
	bool going_forward = true;
	bool stop = false;

	Animation wagon;

	iPoint original_pos;
public:

	Enemy_wheelbarrow(float x, float y, int direction);
	void Move();
	void Die();
};

#endif // __ENEMY_wheelbarrow_H__