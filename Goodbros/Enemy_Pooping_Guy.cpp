#include "Application.h"
#include "Enemy_Pooping_Guy.h"
#include "Module_Points.h"
#include "Enemy.h"
#include "ModuleEnemies.h"
#include "ModuleCollision.h"

Enemy_Pooping_Guy::Enemy_Pooping_Guy(float x, float y) : Enemy(x, y)
{
	idle.PushBack({ 578, 3214, 30, 40 });



	aware.PushBack({ 578, 3214, 30, 40 });
	aware.PushBack({ 626, 3214, 30, 40 });
	aware.PushBack({ 670, 3214, 30, 40 });
	aware.PushBack({ 578, 3214, 30, 40 });
	aware.PushBack({ 626, 3214, 30, 40 });
	aware.PushBack({ 670, 3214, 30, 40 });
	aware.PushBack({ 626, 3214, 30, 40 });
	aware.PushBack({ 670, 3214, 30, 40 });
	aware.PushBack({ 635, 3214, 30, 40 });
	aware.PushBack({ 626, 3214, 30, 40 });
	aware.PushBack({ 670, 3214, 30, 40 });
	aware.speed = 0.20f;
	aware.loop = true;


	run.PushBack({ 709, 3214, 34, 45 });
	run.PushBack({ 752, 3214, 34, 45 });
	run.PushBack({ 796, 3214, 34, 45 });
	run.PushBack({ 846, 3214, 34, 45 });
	run.speed = 0.20f;
	run.loop = true;




	path.PushBack({ 0, 0 }, 200, &idle);
	path.PushBack({ 0, 0 }, 100, &aware);
	path.PushBack({ -1.5f, 0 }, 200, &run);

	collider = App->collision->AddCollider({ 0, 0, 26, 45 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;
}

void Enemy_Pooping_Guy::Move()
{
	position = original_pos + path.GetCurrentSpeed(&animation);

}

void Enemy_Pooping_Guy::Die()
{
	App->points->AddEnemy(ENEMY_TYPES::POINTS, position.x + 5, position.y, 1, NULL);


}