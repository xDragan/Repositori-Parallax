#ifndef __ENEMY__HORSE_RIGHT_H__
#define __ENEMY__HORSE_RIGHT_H__

#include "Enemy.h"

class Enemy_Horse_Right: public Enemy
{
private:
	bool going_forward = true;
	bool stop = false;

	Animation forward;
	Animation backward;	
	Animation dieshot;
	


	bool isdead = false;
	bool spawn = false;
	iPoint original_pos;
public:

	Enemy_Horse_Right(float x, float y);
	void Die();
	void Move();
};

#endif // __ENEMY_COWBOY_GREEN_H__