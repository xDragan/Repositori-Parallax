#ifndef __ENEMY_PIG_H__
#define __ENEMY_PIG_H__

#include "Enemy.h"

class Enemy_Pig : public Enemy
{
private:
	float original_y = 0;
	Animation run;

public:

	Enemy_Pig(float x, float y);
	void Die();
	bool hit = false;
	void Move();
};

#endif // __ENEMY_PIG_H__