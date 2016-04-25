#include "Application.h"
#include "Enemy_CowBoy_Blue.h"
#include "ModuleCollision.h"

Enemy_CowBoy_Blue::Enemy_CowBoy_Blue(int x, int y) : Enemy(x, y)
{
	run2.PushBack({ 79, 47, 21, 44 });
	run2.speed = 0.09f;

	animation = &run2;

	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y2 = y;
}

void Enemy_CowBoy_Blue::Move()
{
	position.y = original_y2;
	position.x -= 1;
}
