#ifndef __ENEMY_PIG_H__
#define __ENEMY_PIG_H__

#include "Enemy.h"

class Enemy_Pig : public Enemy
{
private:
	int original_y = 0;
	Animation run;

public:

	Enemy_Pig(int x, int y);
	void Die();
	bool hit = false;
	void Move();
};

#endif // __ENEMY_PIG_H__