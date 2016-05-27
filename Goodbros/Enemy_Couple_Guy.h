#ifndef __ENEMY_COUPLE_GUY_H__
#define __ENEMY_COUPLE_GUY_H__

#include "Enemy.h"

class Enemy_Couple_Guy : public Enemy
{
private:
	float original_y = 0;

	Animation idle;
	Animation aware;
	Animation run;

	iPoint original_pos;
public:

	Enemy_Couple_Guy(float x, float y);
	void Die();
	bool hit = false;
	void Move();

};

#endif // __ENEMY_GIRL_H__