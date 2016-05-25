#include "Application.h"
#include "Enemy_Can.h"
#include "Module_Points.h"
#include "Enemy.h"
#include "ModuleEnemies.h"
#include "ModuleCollision.h"

Enemy_Can::Enemy_Can(float x, float y) : Enemy(x, y)
{
	iddle.PushBack({ 165, 3055, 15, 17 });
	

	rightfly.PushBack({ 197, 3055, 15, 17 });
	rightfly.PushBack({ 214, 3055, 15, 17 });
	rightfly.PushBack({ 231, 3055, 15, 17 });
	rightfly.PushBack({ 252, 3055, 15, 17 });
	rightfly.PushBack({ 269, 3055, 15, 17 });
	rightfly.PushBack({ 284, 3055, 15, 17 });
	rightfly.PushBack({ 299, 3055, 15, 17 });
	rightfly.PushBack({ 192, 3055, 15, 17 });
	rightfly.speed = 0.20f;
	
	


	leftfly.PushBack({ 192, 3055, 15, 17 });
	leftfly.PushBack({ 214, 3055, 15, 17 });
	leftfly.PushBack({ 231, 3055, 15, 17 });
	leftfly.PushBack({ 252, 3055, 15, 17 });
	leftfly.PushBack({ 269, 3055, 15, 17 });
	leftfly.PushBack({ 284, 3055, 34, 45 });
	leftfly.PushBack({ 299, 3055, 15, 17 });
	leftfly.PushBack({ 192, 3055, 15, 17 });
	leftfly.speed = 0.10f;

	leftfly.speed = 0.07f;

	

	collider = App->collision->AddCollider({ 0, 0, 15, 17 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;


	animation = &iddle;
}

void Enemy_Can::Move()
{
	position = original_pos + path.GetCurrentSpeed(&animation);

	
}

void Enemy_Can::Die()
{
	
	path.Erase();
	path.PushBack({ 0, -1.0f }, 100, &rightfly);
	App->points->AddEnemy(ENEMY_TYPES::POINTS, position.x + 5, position.y, 1);
	hit = true;

}