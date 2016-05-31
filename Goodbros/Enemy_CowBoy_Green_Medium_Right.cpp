#include "Application.h"
#include "Enemy_CowBoy_Green_Medium_Right.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"
#include "ModuleSceneFirst.h"

Enemy_CowBoy_Green_Medium_Right::Enemy_CowBoy_Green_Medium_Right(float x, float y) : Enemy(x, y)
{
	backward.PushBack({ 1340, 2860, 25, 40 });
	backward.PushBack({ 1302, 2860, 25, 40 });
	backward.PushBack({ 1271, 2860, 25, 40 });
	backward.PushBack({ 1229 , 2860, 25, 40 });
	backward.PushBack({ 1187, 2860, 25, 40 });
	backward.PushBack({ 1162, 2860, 25, 40 });
	backward.speed = 0.15f;

	stop_shoot.PushBack({ 1093, 2860, 25, 40 });
	stop_shoot.PushBack({ 1093, 2860, 25, 40 });
	stop_shoot.speed = 0.04f;
	stop_shoot.loop = true;

	dieshot.PushBack({ 1387, 2860, 25, 40 });
	dieshot.PushBack({ 1435, 2860, 25, 40 });
	dieshot.PushBack({ 1482, 2860, 25, 40 });
	dieshot.PushBack({ 1531, 2860, 25, 40 });
	dieshot.speed = 0.09f;
	dieshot.loop = false;

	


	dieexplotion.PushBack({ 1576, 2971, 25, 40 });
	dieexplotion.PushBack({ 1629, 2971, 25, 40 });
	dieexplotion.PushBack({ 1671, 2860, 25, 40 });
	dieexplotion.PushBack({ 1722, 2860, 25, 40 });
	
	dieexplotion.speed = 0.3f;

	collider = App->collision->AddCollider({ 0, -20, 24, 40 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	if (y == 107){
		path.PushBack({ -1.0f, 0 }, 110, &backward);
		path.PushBack({ 0, 0 }, 20, &stop_shoot);
		path.PushBack({ -1.0f, 0 }, 40, &backward);
		path.PushBack({ -1.0f, -1.0f }, 10, &backward);
		path.PushBack({ -1.0f, 0 }, 95, &backward);
		path.loop = true;
	}


	else{
		path.PushBack({ -1.0f, 0 }, 105, &backward);
		path.PushBack({ 0, 0 }, 20, &stop_shoot);
		path.PushBack({ -1.0f, 0 }, 10, &backward);
		path.PushBack({ -1.0f, 0.5f }, 10, &backward);
		path.PushBack({ -1.0f, 0 }, 95, &backward);
		path.loop = true;




	}

	original_pos.x = x;
	original_pos.y = y;
}

void Enemy_CowBoy_Green_Medium_Right::Move()
{
	position = original_pos + path.GetCurrentSpeed(&animation);

	if (dieshot.Finished() == true)
	{
		finished = true;
	}
}

void Enemy_CowBoy_Green_Medium_Right::Die()
{
	collider->type = COLLIDER_NONE;
	App->player->win_condition++;
	path.Erase();
	path.PushBack({ 0.0f, 0.0f }, 40, &dieshot);
	path.loop = false;
}