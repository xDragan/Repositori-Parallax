#ifndef __ENEMY__HORSE_SMALL_RIGHT_H__
#define __ENEMY__HORSE_SMALL_RIGHT_H__

#include "Enemy.h"

class Enemy_Horse_Small_Right : public Enemy
{
private:
	bool going_forward = true;
	bool stop = false;

	
	Animation backward;
	Animation dieshot;



	bool isdead = false;
	bool spawn = false;
	iPoint original_pos;
public:

	Enemy_Horse_Small_Right(float x, float y);
	void Die();
	void Move();
};

#endif // __ENEMY_COWBOY_GREEN_H__