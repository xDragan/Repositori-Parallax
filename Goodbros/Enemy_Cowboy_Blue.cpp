 #include "Application.h"
#include "Enemy_CowBoy_Blue.h"
#include "ModuleCollision.h"

Enemy_CowBoy_Blue::Enemy_CowBoy_Blue(int x, int y) : Enemy(x, y)
{
	forward.PushBack({ 117, 396, 30, 55 });
	forward.PushBack({ 152, 396, 30, 55 });
	forward.PushBack({ 188, 396, 30, 55 });
	forward.PushBack({ 224, 396, 30, 55 });
	forward.PushBack({ 261, 396, 30, 55 });
	forward.PushBack({ 299, 396, 30, 55 });
	forward.speed = 0.06f;

	backward.PushBack({ 117, 459, 30, 55 });
	backward.PushBack({ 152, 459, 30, 55 });
	backward.PushBack({ 188, 459, 30, 55 });
	backward.PushBack({ 224, 459, 30, 55 });
	backward.PushBack({ 261, 459, 30, 55 });
	backward.PushBack({ 299, 459, 30, 55 });
	backward.speed = 0.06f;

	stop_shoot.PushBack({ 353, 396, 30, 55 });
	stop_shoot.PushBack({ 392, 396, 30, 55 });
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
