#ifndef __ENEMY_COWBOY_BLUE_TOP_FABTEN_H__
#define __ENEMY_COWBOY_BLUE_TOP_FABTEN_H__

#include "Enemy.h"

class Enemy_CowBoy_Blue_Top_Fabten : public Enemy
{
private:
	bool going_forward = true;
	bool stop = false;

	Animation forwardsm;
	Animation forwardb;
	Animation backwardsm;
	Animation backwardb;
	Animation bwtumbleb;
	Animation dieshotsm;
	Animation dieexplotionsm;
	Animation fwtumblesm;
	Animation grenadesm;
	Animation crouchsm ;
	Animation dieshotb;
	Animation dieexplotionb;
	Animation fwtumbleb;
	Animation grenadeb;
	Animation crouchb;
	Animation jumpsm;
	Animation jump;
	Animation spawnn;
	Animation shootb;
	Animation shootsm;
	Animation tumblersm;
	Animation tumblelsm;
	bool isdead = false;

	iPoint original_pos;
public:

	Enemy_CowBoy_Blue_Top_Fabten(float x, float y);
	void Die();
	void Move();
};

#endif //  __ENEMY_COWBOY_GREEN_TOP_FABTEN_1_H__