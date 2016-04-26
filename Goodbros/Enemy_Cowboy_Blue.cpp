#include "Application.h"
#include "Enemy_CowBoy_Blue.h"
#include "ModuleCollision.h"

Enemy_CowBoy_Blue::Enemy_CowBoy_Blue(int x, int y) : Enemy(x, y)
{
	forward.PushBack({ 88, 405, 20, 44 });
	forward.PushBack({ 123, 405, 26, 44 });
	forward.PushBack({ 176, 405, 26, 44 });
	forward.PushBack({ 229, 405, 26, 44 });
	forward.PushBack({ 267, 405, 26, 44 });
	forward.PushBack({ 310, 405, 26, 44 });
	forward.speed = 0.06f;

	backward.PushBack({ 88, 469, 20, 44 });
	backward.PushBack({ 135, 469, 26, 44 });
	backward.PushBack({ 181, 469, 26, 44 });
	backward.PushBack({ 221, 469, 31, 44 });
	backward.PushBack({ 278, 469, 26, 44 });
	backward.PushBack({ 319, 469, 26, 44 });
	backward.speed = 0.06f;
	
	stop_shoot.PushBack({ 491, 406, 29, 44 });
	stop_shoot.PushBack({ 523, 406, 26, 54 });
	stop_shoot.speed = 0.02f;

	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y2 = y;
}

void Enemy_CowBoy_Blue::Move()
{
	if (position.x == 50)
	{
		going_forward = false;
	}
	if (position.x == 210)
	{
		going_forward = true;
	}
	/*if (position.x == 105)
	{
		stop = true;
	}
	if (stop == true)
	{
		animation = &stop_shoot;
	}*/
	if (going_forward == true && stop == false)
	{
		position.x -= 0.5;
		animation = &forward;
	}
	if (going_forward == false && stop == false)
	{
		position.x += 0.5;
		animation = &backward;
	}
	position.y = original_y2;
}
