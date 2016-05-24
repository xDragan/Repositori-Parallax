#ifndef __ENEMY_GIRL_H__
#define __ENEMY_GIRL_H__

#include "Enemy.h"

class Enemy_Girl : public Enemy
{
private:
	float original_y = 0;
	
	Animation walk;
	Animation run;
	Animation dead;

	iPoint original_pos;
public:

	Enemy_Girl(float x, float y);
	void Die();
	bool hit = false;
	void Move();
};

#endif // __ENEMY_GIRL_H__