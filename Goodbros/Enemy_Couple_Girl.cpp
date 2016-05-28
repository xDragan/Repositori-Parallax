#include "Application.h"
#include "Enemy_Couple_Girl.h"
#include "Module_Points.h"
#include "Enemy.h"
#include "ModuleEnemies.h"
#include "ModuleCollision.h"

Enemy_Couple_Girl::Enemy_Couple_Girl(float x, float y) : Enemy(x, y)
{
	idle.PushBack({ 1152, 3114, 30, 40 });



	aware.PushBack({ 1152, 3114, 30, 40 });
	aware.PushBack({ 1203, 3114, 30, 40 });
	aware.PushBack({ 1152, 3114, 30, 40 });
	aware.PushBack({ 1203, 3114, 30, 40 });
	aware.PushBack({ 1203, 3114, 30, 40 });
	aware.PushBack({ 1152, 3114, 30, 40 });
	aware.PushBack({ 1203, 3114, 30, 40 });
	aware.PushBack({ 1259, 3114, 30, 40 });
	aware.PushBack({ 1203, 3114, 30, 40 });
	aware.PushBack({ 1259, 3114, 30, 40 });
	aware.PushBack({ 1259, 3114, 30, 40 });
	aware.speed = 0.20f;
	aware.loop = true;


	run.PushBack({ 1307, 3114, 34, 45 });
	run.PushBack({ 1373, 3114, 34, 45 });
	

	run.speed = 0.10f;




	path.PushBack({ 0, 0 }, 200, &idle);
	path.PushBack({ 0, 0 }, 100, &aware);
	path.PushBack({ 1.0f, 0 }, 100, &run);

	collider = App->collision->AddCollider({ 0, 0, 26, 45 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;
}

void Enemy_Couple_Girl::Move()
{
	position = original_pos + path.GetCurrentSpeed(&animation);

}

void Enemy_Couple_Girl::Die()
{
	App->points->AddEnemy(ENEMY_TYPES::POINTS, position.x + 5, position.y, 1, NULL);


}