#ifndef __Module_Points_H__
#define __Module_Points_H__

#include "Enemy.h"

class Module_Points : public Enemy
{
private:
	bool going_forward = true;
	bool stop = false;
	uint to_score;
	Animation p1000, p5000, p7000, p10000;

	iPoint original_pos;
public:

	Module_Points(float x, float y, uint points);
	void Move();
	void Die();
};

#endif // __Module_Points_H__