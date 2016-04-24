#include "Application.h"
#include "Enemy_Pig.h"
#include "ModuleCollision.h"

Enemy_Pig::Enemy_Pig(int x, int y) : Enemy(x, y)
{
	run.PushBack({ 0, 11, 32, 21});
	run.PushBack({ 35, 11, 32, 21 });
	run.speed = 0.09f;

	animation = &run;

	collider = App->collision->AddCollider({0, 0, 24, 24}, COLLIDER_TYPE::COLLIDER_NONE, (Module*)App->enemies);

	original_y = y;
}

void Enemy_Pig::Move()
{
	position.y = original_y;
	position.x -= 1;
}
