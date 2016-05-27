#include "Application.h"
#include "Enemy_Rider_Medium.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"
#include "ModuleSceneFirst.h"

Enemy_Rider_Medium::Enemy_Rider_Medium(float x, float y) : Enemy(x, y)
{
	backward.PushBack({ 1164, 2817, 25, 40 });
	backward.PushBack({ 1164, 2816, 25, 40 });
	backward.PushBack({ 1164, 2817, 25, 40 });
	backward.PushBack({ 1164, 2816, 25, 40 });

	
	backward.speed = 0.15f;

	stop_shoot.PushBack({ 1095, 2860, 25, 40 });
	stop_shoot.PushBack({ 1095, 2860, 25, 40 });
	stop_shoot.speed = 0.04f;
	stop_shoot.loop = true;

	dieshot.PushBack({ 662, 2848, 36, 54 });
	dieshot.PushBack({ 771, 2848, 36, 54 });
	dieshot.PushBack({ 759, 2848, 36, 54 });
	dieshot.PushBack({ 807, 2848, 36, 54 });
	dieshot.speed = 0.09f;
	dieshot.loop = false;




	collider = App->collision->AddCollider({ 0, -20, 25, 30 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	path.PushBack({ -1.0f, 0 }, 100, &backward);
	
	path.loop = true;

	original_pos.x = x;
	original_pos.y = y;
}

void Enemy_Rider_Medium::Move()
{
	position = original_pos + path.GetCurrentSpeed(&animation);

	if (dieshot.Finished() == true)
	{
		finished = true;
	}
}

void Enemy_Rider_Medium::Die()
{
	collider->type = COLLIDER_NONE;
	App->player->win_condition++;
	path.Erase();
	path.PushBack({ 0.0f, -0.05f }, 40, &dieshot);
	path.loop = false;
}