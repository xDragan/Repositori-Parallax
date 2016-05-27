#include "Application.h"
#include "Enemy_Rider_Small_Right.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"
#include "ModuleSceneFirst.h"

Enemy_Rider_Small_Right::Enemy_Rider_Small_Right(float x, float y) : Enemy(x, y)
{
	backward.PushBack({ 107, 2990, 15, 20 });
	backward.PushBack({ 107, 2989, 15, 20 });
	backward.PushBack({ 107, 2990, 15, 20 });
	backward.PushBack({ 107, 2989, 15, 20 });

	backward.speed = 0.15f;

	

	dieshot.PushBack({ 811, 2947, 15, 20 });
	dieshot.PushBack({ 828, 2947, 15, 20 });
	dieshot.PushBack({ 846, 2947, 15, 20 });
	dieshot.PushBack({ 863, 2947, 15, 20 });
	dieshot.speed = 0.20;
	dieshot.loop = false;




	collider = App->collision->AddCollider({ 0, -20, 25, 30 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	path.PushBack({ -1.0f, 0 }, 100, &backward);

	path.loop = true;

	original_pos.x = x;
	original_pos.y = y;
}

void Enemy_Rider_Small_Right::Move()
{
	position = original_pos + path.GetCurrentSpeed(&animation);

	if (dieshot.Finished() == true)
	{
		finished = true;
	}
}

void Enemy_Rider_Small_Right::Die()
{
	collider->type = COLLIDER_NONE;
	App->player->win_condition++;
	path.Erase();
	path.PushBack({ 0.0f, 0.5f }, 200, &dieshot);
	path.loop = false;
}