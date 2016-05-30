#include "Application.h"
#include "Enemy_CowBoy_Blue_Top_Fabten.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"
#include "ModuleSceneFirst.h"

Enemy_CowBoy_Blue_Top_Fabten::Enemy_CowBoy_Blue_Top_Fabten(float x, float y) : Enemy(x, y)
{
	forwardb.PushBack({ 117, 396, 36, 55 });
	forwardb.PushBack({ 152, 396, 36, 55 });
	forwardb.PushBack({ 188, 396, 36, 55 });
	forwardb.PushBack({ 224, 396, 36, 55 });
	forwardb.PushBack({ 261, 396, 36, 55 });
	forwardb.PushBack({ 299, 396, 36, 55 });
	forwardb.speed = 0.09f;
	forwardb.loop = true;

	dieshotb.PushBack({ 507, 400, 35, 54 });
	dieshotb.PushBack({ 549, 400, 35, 54 });
	dieshotb.PushBack({ 589, 400, 35, 54 });
	dieshotb.PushBack({ 632, 400, 35, 54 });

	dieshotb.speed = 0.09f;
	dieshotb.loop = false;

	dieexplotionb.PushBack({ 744, 397, 36, 54 });
	dieexplotionb.PushBack({ 798, 397, 36, 54 });
	dieexplotionb.PushBack({ 844, 397, 36, 54 });
	dieexplotionb.PushBack({ 889, 397, 36, 54 });
	dieexplotionb.speed = 0.3f;

	grenadesm.PushBack({ 591, 1058, 25, 40 });
	grenadesm.PushBack({ 624, 1058, 25, 40 });
	grenadesm.PushBack({ 655, 1058, 25, 40 });
	grenadesm.PushBack({ 687, 1058, 25, 40 });
	grenadesm.PushBack({ 717, 1058, 25, 40 });
	grenadesm.PushBack({ 742, 1058, 25, 40 });
	grenadesm.speed = 0.1f;
	grenadesm.loop = false;

	crouchsm.PushBack({ 1064, 581, 25, 40 });

	jumpsm.PushBack({ 1089, 581, 25, 40 });
	jumpsm.loop = true;

	

	spawnn.PushBack({ 964, 581, 25, 40 });
	spawnn.PushBack({ 989, 581, 25, 40 });
	spawnn.PushBack({ 1014, 581, 25, 40 });
	spawnn.PushBack({ 1039, 581, 25, 40 });
	spawnn.PushBack({ 591, 1018, 25, 40 });
	spawnn.speed = 0.05f;

	collider = App->collision->AddCollider({ 0, -20, 24, 55 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	path.PushBack({ 0, 0 }, 100, &spawnn);
	path.PushBack({ 0, 0 }, 60, &grenadesm);
	path.PushBack({ 0, 0 }, 20, &crouchsm);
	path.PushBack({ 0, 2.0 }, 35, &jumpsm);
	

	path.PushBack({ -1.0f, 0 }, 90, &forwardb);

	path.loop = false;

	original_pos.x = x;
	original_pos.y = y;

}

void Enemy_CowBoy_Blue_Top_Fabten::Move()
{
	position = original_pos + path.GetCurrentSpeed(&animation);

	if (dieshotsm.Finished() == true)
	{
		finished = true;
	}
	if (position.x >= SCREEN_WIDTH - 20)
	{
		collider->type = COLLIDER_NONE;
		path.Erase();
		finished = true;
	}
}

void Enemy_CowBoy_Blue_Top_Fabten::Die()
{
	collider->type = COLLIDER_NONE;
	App->player->win_condition++;
	path.Erase();
	path.PushBack({ 0.0f, 0.0f }, 40, &dieshotsm);
	path.loop = false;
}