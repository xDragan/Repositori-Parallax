#ifndef __ENEMY_COWBOY_GREEN_TOP_FABTEN_1_H__
#define __ENEMY_COWBOY_GREEN_TOP_FABTEN_1_H__

#include "Enemy.h"

class Enemy_CowBoy_Green_Top_Fabten_1 : public Enemy
{
private:
	bool going_forward = true;
	bool stop = false;

	Animation forward;


	Animation dieshot;
	Animation dieexplotion;
	Animation fwtumble;
	Animation grenadeSm;
	Animation crouch ;
	Animation jumpSm;
	Animation spawnn;
	bool isdead = false;

	iPoint original_pos;
public:

	Enemy_CowBoy_Green_Top_Fabten_1(float x, float y);
	void Die();
	void Move();
};

#endif //  __ENEMY_COWBOY_GREEN_TOP_FABTEN_1_H__