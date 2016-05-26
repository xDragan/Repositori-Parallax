#include "Application.h"
#include "Enemy_Cowboy_Blue3.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "Path.h"

Enemy_CowBoy_Blue3::Enemy_CowBoy_Blue3(float x, float y) : Enemy(x, y)
{
	forward.PushBack({ 117, 396, 36, 55 });
	forward.PushBack({ 152, 396, 36, 55 });
	forward.PushBack({ 188, 396, 36, 55 });
	forward.PushBack({ 224, 396, 36, 55 });
	forward.PushBack({ 261, 396, 36, 55 });
	forward.PushBack({ 299, 396, 36, 55 });
	forward.speed = 0.09f;
	forward.loop = true;

	dieshot.PushBack({ 507, 400, 35, 54 });
	dieshot.PushBack({ 549, 400, 35, 54 });
	dieshot.PushBack({ 589, 400, 35, 54 });
	dieshot.PushBack({ 632, 400, 35, 54 });
	
	dieshot.speed = 0.09f;
	dieshot.loop = false;

	dieexplotion.PushBack({ 744, 397, 36, 54 });
	dieexplotion.PushBack({ 798, 397, 36, 54 });
	dieexplotion.PushBack({ 844, 397, 36, 54 });
	dieexplotion.PushBack({ 889, 397, 36, 54 });
	dieexplotion.speed = 0.3f;

	grenadeSm.PushBack({ 591, 1058, 25, 40 });
	grenadeSm.PushBack({ 624, 1058, 25, 40 });
	grenadeSm.PushBack({ 655, 1058, 25, 40 });
	grenadeSm.PushBack({ 687, 1058, 25, 40 });
	grenadeSm.PushBack({ 717, 1058, 25, 40 });
	grenadeSm.PushBack({ 742, 1058, 25, 40 });
	grenadeSm.speed = 0.1f;
	grenadeSm.loop = false;

	falld.PushBack({ 1064, 581, 25, 40 });

	jumpSm.PushBack({ 1089, 581, 25, 40 });
	jumpSm.loop = true;

	jump.PushBack({ 1203, 685, 33, 49 });
	jump.loop = true;
	
	spawnn.PushBack({ 964, 581, 25, 40 });
	spawnn.PushBack({ 989, 581, 25, 40 });
	spawnn.PushBack({ 1014, 581, 25, 40 });
	spawnn.PushBack({ 1039, 581, 25, 40 });
	spawnn.PushBack({ 591, 1018, 25, 40 });
	spawnn.speed = 0.05f;

	collider = App->collision->AddCollider({ 0, -20, 24, 55 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	path.PushBack({ 0, 0 }, 100, &spawnn);
	path.PushBack({ 0, 0 }, 60, &grenadeSm);
	path.PushBack({ 0, 0 }, 20, &falld);
	path.PushBack({ 0, -1.0 }, 15, &jumpSm);
	path.PushBack({ 0, +1.0 }, 20, &jump);

	path.PushBack({ -1.0f, 0 }, 90, &forward);
	
	path.loop = false;

	original_pos.x = x;
	original_pos.y = y;
}

void Enemy_CowBoy_Blue3::Move()
{
	{
		position = original_pos + path.GetCurrentSpeed(&animation);

		if (forward.Finished() == true)
		{
			finished = true;
		}
		if (dieshot.Finished() == true)
		{
			finished = true;
		}
	}
}

void Enemy_CowBoy_Blue3::Die()
{
	collider->type = COLLIDER_NONE;
	App->player->win_condition++;
	path.Erase();
	path.PushBack({ 0.0f, 0.0f }, 40, &dieshot);
	path.loop = false;
}