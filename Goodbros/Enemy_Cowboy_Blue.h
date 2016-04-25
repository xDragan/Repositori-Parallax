#ifndef __ENEMY_COWBOY_BLUE_H__
#define __ENEMY_COWBOY_BLUE_H__
#include "Enemy.h"

class Enemy_CowBoy_Blue : public Enemy
{
private:
	int original_y2 = 0;
	Animation run2;

public:

	Enemy_CowBoy_Blue(int x, int y);

	void Move();
};

#endif // __ENEMY_COWBOY_BLUE_H__