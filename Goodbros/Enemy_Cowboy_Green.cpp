#include "Application.h"
#include "Enemy_CowBoy_Green.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"
#include "ModuleSceneFirst.h"

Enemy_CowBoy_Green::Enemy_CowBoy_Green(float x, float y) : Enemy(x, y)
{
	forward.PushBack({ 1095, 2797, 30, 55 });
	forward.PushBack({ 1056, 2797, 30, 55 });
	forward.PushBack({ 1008, 2797, 30, 55 });
	forward.PushBack({ 968, 2797, 30, 55 });
	forward.PushBack({ 931, 2797, 30, 55 });
	forward.PushBack({ 880, 2797, 30, 55 });
	forward.speed = 0.09f;

	backward.PushBack({ 110, 2848, 30, 55 });
	backward.PushBack({ 149, 2848, 30, 55 });
	backward.PushBack({ 201, 2848, 30, 55 });
	backward.PushBack({ 242 , 2848, 30, 55 });
	backward.PushBack({ 278 , 2848, 30, 55 });
	backward.PushBack({ 328 , 2848, 30, 55 });
	backward.speed = 0.09f;

	stop_shoot.PushBack({ 374, 2848, 30, 55 });
	stop_shoot.speed = 0.04f;
	stop_shoot.loop = true;

	dieshot.PushBack({ 472, 2848, 35, 54 });
	dieshot.PushBack({ 521, 2848, 35, 54 });
	dieshot.PushBack({ 567, 2848, 35, 54 });
	dieshot.PushBack({ 614, 2848, 35, 54 });
	dieshot.speed = 0.09f;
	dieshot.loop = false;

	dieexplotion.PushBack({ 662, 2848, 36, 54 });
	dieexplotion.PushBack({ 771, 2848, 36, 54 });
	dieexplotion.PushBack({ 759, 2848, 36, 54 });
	dieexplotion.PushBack({ 807, 2848, 36, 54 });
	dieexplotion.speed = 0.3f;
	 
	
	        
	collider = App->collision->AddCollider({ 0, -20, 24, 55 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	path.PushBack({ -1.0f, 0 }, 95, &backward);
	path.PushBack({ 0, 0 }, 67, &stop_shoot);
	path.PushBack({ -1.0f, 0 }, 95, &backward);
	path.PushBack({ 1.0f, 0 }, 95, &forward);
	path.PushBack({ 0, 0 }, 67, &stop_shoot);
	path.PushBack({ 1.0f, 0 }, 95, &forward);
	path.loop = true;

	original_pos.x = x;
	original_pos.y = y;
}

void Enemy_CowBoy_Green::Move()
{
	position = original_pos + path.GetCurrentSpeed(&animation);
	
	if (dieshot.Finished() == true)
	{
		finished = true;
	}
}

void Enemy_CowBoy_Green::Die()
{
	App->player->win_condition++;
	path.Erase();
	path.PushBack({ 0.0f, 0.0f }, 40, &dieshot);
	path.loop = false;
}