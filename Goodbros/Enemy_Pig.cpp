#include "Application.h"
#include "Enemy_Pig.h"
#include "ModuleCollision.h"

Enemy_Pig::Enemy_Pig(int x, int y) : Enemy(x, y)
{
	run.PushBack({ 81, 127, 32, 24 });
	run.PushBack({ 127, 127, 32, 24 });
	run.speed = 0.07f;

	animation = &run;

	collider = App->collision->AddCollider({0, 0, 24, 24}, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
}

void Enemy_Pig::Move()
{
	position.y = original_y;
	if (hit == false){ position.x -= 1; }
	if (hit == true) { position.x -= 3; }
}

void Enemy_Pig::Die()
{
	hit = true;
}