#include "Application.h"
#include "Enemy_Pig.h"
#include "ModuleCollision.h"

Enemy_Pig::Enemy_Pig(int x, int y) : Enemy(x, y)
{
	run.PushBack({ 0, 11, 38, 27 });
	run.PushBack({ 39, 11, 38, 27 });
	run.speed = 0.07f;

	animation = &run;

	collider = App->collision->AddCollider({0, 0, 24, 24}, COLLIDER_TYPE::COLLIDER_NONE, (Module*)App->enemies);

	original_y = y;
}

void Enemy_Pig::Move()
{
	position.y = original_y;
	position.x -= 0.6;
}
