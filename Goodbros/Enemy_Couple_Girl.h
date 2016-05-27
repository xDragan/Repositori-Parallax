#ifndef __ENEMY_COUPLE_GIRL_H__
#define __ENEMY_COUPLE_GIRL_H__

#include "Enemy.h"

class Enemy_Couple_Girl : public Enemy
{
private:
	float original_y = 0;

	Animation idle;
	Animation aware;
	Animation run;

	iPoint original_pos;
public:

	Enemy_Couple_Girl(float x, float y);
	void Die();
	bool hit = false;
	void Move();

};

#endif // __ENEMY_GIRL_H__