#include "Application.h"
#include "Enemy_CowBoy_Green_Top_Bar.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"
#include "ModuleSceneFirst.h"

Enemy_CowBoy_Green_Top_Bar::Enemy_CowBoy_Green_Top_Bar(float x, float y) : Enemy(x, y)
{
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
	dieexplotion.loop = false;



	
	spawni.PushBack({ 1388, 2808, 13, 40 });
	spawni.PushBack({ 1403, 2808, 13, 40 });
	spawni.PushBack({ 1418, 2808, 13, 40 });
	spawni.PushBack({ 1435, 2808, 13, 40 });
	spawni.loop = false;
	spawni.speed = 0.15f;


	jump.PushBack({ 1466, 2808, 25, 40 });
	jump.PushBack({ 1466, 2808, 25, 40 });
	jump.PushBack({ 1498, 2793, 25, 40 });
	jump.speed = 0.05f;
	jump.loop = false;








	collider = App->collision->AddCollider({ 0, -20, 24, 55 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);


	if (x == 205){
		path.PushBack({ 0, 0 }, 30, &spawni);
		path.PushBack({ -1.0f, 0 }, 30, &backward);
		path.PushBack({ 0, 0 }, 40, &stop_shoot);
		path.PushBack({ 1.0f, 0 }, 140, &forward);
		path.loop = true;
	}

	else{

		path.PushBack({ 0, 0 }, 30, &spawni);
		path.PushBack({ 1.0f, 0 }, 30, &backward);
		path.PushBack({ 0, 0 }, 40, &stop_shoot);
		path.PushBack({ 0, 2.0f }, 40, &jump);
		path.PushBack({ 1.0f, 0 }, 20, &forward);
		path.PushBack({ 0, 0 }, 40, &stop_shoot);
		path.PushBack({ 1.0f, 0 }, 200, &forward);
		path.loop = true;



	}

	original_pos.x = x;
	original_pos.y = y;
}

void Enemy_CowBoy_Green_Top_Bar::Move()
{
	position = original_pos + path.GetCurrentSpeed(&animation);

	if (dieshot.Finished() == true)
	{
		finished = true;
	}
}

void Enemy_CowBoy_Green_Top_Bar::Die()
{
	collider->type = COLLIDER_NONE;
	App->player->win_condition++;
	path.Erase();
	path.PushBack({ 0.0f, 0.0f }, 40, &dieshot);
	path.loop = false;
}