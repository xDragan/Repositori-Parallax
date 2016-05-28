#ifndef __ENEMY_COWBOY_GREEN_TOP_FABTEN_2_H__
#define __ENEMY_COWBOY_GREEN_TOP_FABTEN_2_H__

#include "Enemy.h"

class Enemy_CowBoy_Green_Top_Fabten_2 : public Enemy
{
private:
	bool going_forward = true;
	bool stop = false;

	Animation forward;


	Animation dieshot;
	Animation dieexplotion;
	Animation fwtumble;
	Animation grenadeSm;
	Animation falld;
	Animation jumpSm;
	Animation jump;
	Animation spawnn;
	bool isdead = false;

	iPoint original_pos;
public:

	Enemy_CowBoy_Green_Top_Fabten_2(float x, float y);
	void Die();
	void Move();
};

#endif //  __ENEMY_COWBOY_GREEN_TOP_FABTEN_2_H__