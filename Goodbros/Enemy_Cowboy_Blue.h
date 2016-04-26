#ifndef __ENEMY_COWBOY_BLUE_H__
#define __ENEMY_COWBOY_BLUE_H__
#include "Enemy.h"

class Enemy_CowBoy_Blue : public Enemy
{
private:
	bool going_forward = true;
	bool stop = false;
	int original_y2 = 0;

	Animation forward;
	Animation backward;
	Animation stop_shoot;
	iPoint original_pos;
public:

	Enemy_CowBoy_Blue(int x, int y);

	void Move();
};

#endif // __ENEMY_COWBOY_BLUE_H__