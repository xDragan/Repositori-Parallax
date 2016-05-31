#include "Application.h"
#include "Enemy_CowBoy_Green_Right_Tumble.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"
#include "ModuleSceneFirst.h"

Enemy_CowBoy_Green_Right_Tumble::Enemy_CowBoy_Green_Right_Tumble(float x, float y) : Enemy(x, y)
{
	spawnani.PushBack({ 1388, 2808, 13, 40 });
	spawnani.PushBack({ 1403, 2808, 13, 40 });
	spawnani.PushBack({ 1418, 2808, 13, 40 });
	spawnani.PushBack({ 1435, 2808, 13, 40 });
	spawnani.loop = false;
	spawnani.speed = 0.10f;

	forward.PushBack({ 1959, 2860, 25, 40 });
	forward.PushBack({ 2004, 2860, 25, 40 });
	forward.PushBack({ 2036, 2860, 25, 40 });
	forward.PushBack({ 2072, 2860, 25, 40 });
	forward.PushBack({ 2116, 2860, 25, 40 });
	forward.PushBack({ 2164, 2860, 25, 40 });
	forward.speed = 0.15f;

	backward.PushBack({ 1340, 2860, 25, 40 });
	backward.PushBack({ 1302, 2860, 25, 40 });
	backward.PushBack({ 1271, 2860, 25, 40 });
	backward.PushBack({ 1229, 2860, 25, 40 });
	backward.PushBack({ 1187, 2860, 25, 40 });
	backward.PushBack({ 1162, 2860, 25, 40 });
	backward.speed = 0.15f;

	stop_shoot.PushBack({ 1056, 2862, 25, 40 });
	stop_shoot.PushBack({ 1030, 2862, 25, 40 });
	stop_shoot.speed = 0.04f;
	stop_shoot.loop = true;

	dieshot.PushBack({ 1911, 2860, 25, 40 });
	dieshot.PushBack({ 1864, 2860, 25, 40 });
	dieshot.PushBack({ 1815, 2860, 25, 40 });
	dieshot.PushBack({ 1767, 2860, 25, 40 });
	dieshot.speed = 0.09f;
	dieshot.loop = false;

	dieexplotion.PushBack({ 662, 2848, 36, 54 });
	dieexplotion.PushBack({ 771, 2848, 36, 54 });
	dieexplotion.PushBack({ 759, 2848, 36, 54 });
	dieexplotion.PushBack({ 807, 2848, 36, 54 });
	dieexplotion.speed = 0.3f;
	
	crouched.PushBack({ 791, 2816, 36, 37 });
	crouched.PushBack({827,2816,36,37});
	crouched.speed = 0.05f;

	collider = App->collision->AddCollider({ 0, -20, 24, 40 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	path.PushBack({ 0, 0 }, 50, &spawnani);
	path.PushBack({ -1.0f, 0 }, 30, &backward);
	path.PushBack({ 0, 0 }, 45, &stop_shoot);
	path.PushBack({ 1.0f, 0 }, 200, &forward);
	path.loop = false;

	original_pos.x = x;
	original_pos.y = y;
}

void Enemy_CowBoy_Green_Right_Tumble::Move()
{
	position = original_pos + path.GetCurrentSpeed(&animation);

	if (path.GetFrame() == 100){
		App->particles->AddParticle(App->particles->enemyshot, position.x + 5, position.y + 10, COLLIDER_ENEMY_SHOT, 0);
	}
	if (dieshot.Finished() == true)
	{
		finished = true;
	}
	
}

void Enemy_CowBoy_Green_Right_Tumble::Die()
{
	collider->type = COLLIDER_NONE;
	App->player->win_condition++;
	path.Erase();
	path.PushBack({ 0.0f, 0.0f }, 40, &dieshot);
	path.loop = false;
}