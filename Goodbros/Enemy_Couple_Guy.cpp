#include "Application.h"
#include "Enemy_Couple_Guy.h"
#include "Module_Points.h"
#include "Enemy.h"
#include "ModuleEnemies.h"
#include "ModuleCollision.h"

Enemy_Couple_Guy::Enemy_Couple_Guy(float x, float y) : Enemy(x, y)
{
	idle.PushBack({ 579, 3114, 30, 40 });
	
	
	
	aware.PushBack({ 579, 3114, 30, 40 });
	aware.PushBack({ 635, 3114, 30, 40 });
	aware.PushBack({ 579, 3114, 30, 40 });
	aware.PushBack({ 635, 3114, 30, 40 });
	aware.PushBack({ 635, 3114, 30, 40 });
	aware.PushBack({ 579, 3114, 30, 40 });
	aware.PushBack({ 635, 3114, 30, 40 });
	aware.PushBack({ 696, 3114, 30, 40 });
	aware.PushBack({ 635, 3114, 30, 40 });
	aware.PushBack({ 696, 3114, 30, 40 }); 
	aware.PushBack({ 696, 3114, 30, 40 });
	aware.speed = 0.20f;
	aware.loop = true;


	run.PushBack({ 757, 3114, 34, 45 });
	run.PushBack({ 803, 3114, 34, 45 });
	run.PushBack({ 863, 3114, 34, 45 });
	run.PushBack({ 907, 3114, 34, 45 });
	
	run.speed = 0.20f;

	


	path.PushBack({ 0, 0 }, 200, &idle);
	path.PushBack({ 0, 0 }, 100, &aware);
	path.PushBack({ 2.0f, 0 }, 200, &run);

	collider = App->collision->AddCollider({ 0, 0, 26, 40 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;
}

void Enemy_Couple_Guy::Move()
{
	position = original_pos + path.GetCurrentSpeed(&animation);

}

void Enemy_Couple_Guy::Die()
{
	App->points->AddEnemy(ENEMY_TYPES::POINTS, position.x + 5, position.y, 1, NULL);
	

}