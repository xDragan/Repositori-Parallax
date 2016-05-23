#include "Application.h"
#include "Enemy_Cowboy_Blue2.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "Path.h"

Enemy_CowBoy_Blue2::Enemy_CowBoy_Blue2(float x, float y) : Enemy(x, y)
{
	forward.PushBack({ 117, 396, 36, 55 });
	forward.PushBack({ 152, 396, 36, 55 });
	forward.PushBack({ 188, 396, 36, 55 });
	forward.PushBack({ 224, 396, 36, 55 });
	forward.PushBack({ 261, 396, 36, 55 });
	forward.PushBack({ 299, 396, 36, 55 });
	forward.speed = 0.09f;
	forward.loop = true;

	backward.PushBack({ 117, 459, 36, 55 });
	backward.PushBack({ 152, 459, 36, 55 });
	backward.PushBack({ 188, 459, 36, 55 });
	backward.PushBack({ 224, 459, 36, 55 });
	backward.PushBack({ 261, 459, 36, 55 });
	backward.PushBack({ 299, 459, 36, 55 });
	backward.speed = 0.15f;
	backward.loop = true;

	stop_shoot.PushBack({ 353, 396, 30, 55 });
	stop_shoot.PushBack({ 392, 396, 30, 55 });
	stop_shoot.PushBack({ 353, 396, 30, 55 });
	stop_shoot.speed = 0.04f;
	stop_shoot.loop = true;

	dieshot.PushBack({ 507, 400, 35, 54 });
	dieshot.PushBack({ 549, 400, 35, 54 });
	dieshot.PushBack({ 589, 400, 35, 54 });
	dieshot.PushBack({ 632, 400, 35, 54 });
	dieshot.speed = 0.09f;
	dieshot.loop = true;

	dieexplotion.PushBack({ 744, 397, 36, 54 });
	dieexplotion.PushBack({ 798, 397, 36, 54 });
	dieexplotion.PushBack({ 844, 397, 36, 54 });
	dieexplotion.PushBack({ 889, 397, 36, 54 });
	dieexplotion.speed = 0.3f;

	grenade.PushBack({ 1014, 397, 36, 54 });
	grenade.PushBack({ 1055, 397, 36, 54 });
	grenade.PushBack({ 1095, 397, 36, 54 });
	grenade.PushBack({ 1134, 397, 36, 54 });
	grenade.PushBack({ 1095, 397, 36, 54 });
	grenade.PushBack({ 1055, 397, 36, 54 });
	grenade.PushBack({ 1095, 397, 36, 54 });
	grenade.PushBack({ 1134, 397, 36, 54 });
	grenade.PushBack({ 1172, 397, 36, 54 });
	grenade.PushBack({ 1210, 397, 36, 54 });
	grenade.speed = 0.2f;

	grenadeSm.PushBack({ 591, 1058, 25, 40 });
	grenadeSm.PushBack({ 624, 1058, 25, 40 });
	grenadeSm.PushBack({ 655, 1058, 25, 40 });
	grenadeSm.PushBack({ 687, 1058, 25, 40 });
	grenadeSm.PushBack({ 717, 1058, 25, 40 });
	grenadeSm.PushBack({ 742, 1058, 25, 40 });
	grenadeSm.speed = 0.1f;
	grenadeSm.loop = true;



	bwtumble.PushBack({ 107, 565, 36, 54 });
	bwtumble.PushBack({ 149, 565, 41, 54 });
	bwtumble.PushBack({ 195, 565, 36, 54 });
	bwtumble.PushBack({ 237, 565, 36, 54 });
	bwtumble.PushBack({ 278, 565, 36, 54 });
	bwtumble.PushBack({ 319, 565, 36, 54 });
	bwtumble.speed = 0.2f;
	bwtumble.loop = true;

	bwtumbleshoot.PushBack({ 107, 619, 36, 54 });
	bwtumbleshoot.PushBack({ 149, 619, 41, 54 });
	bwtumbleshoot.PushBack({ 195, 565, 36, 54 });
	bwtumbleshoot.PushBack({ 237, 565, 36, 54 });
	bwtumbleshoot.PushBack({ 278, 565, 36, 54 });
	bwtumbleshoot.PushBack({ 319, 619, 36, 54 });
	bwtumbleshoot.PushBack({ 319, 673, 36, 54 });
	bwtumbleshoot.speed = 0.2f;
	bwtumbleshoot.loop = true;

	fwtumble.PushBack({ 107, 739, 36, 54 });
	fwtumble.PushBack({ 149, 739, 41, 54 });
	fwtumble.PushBack({ 195, 739, 36, 54 });
	fwtumble.PushBack({ 237, 739, 36, 54 });
	fwtumble.PushBack({ 278, 739, 36, 54 });
	fwtumble.PushBack({ 319, 739, 36, 54 });
	fwtumble.speed = 0.2f;
	fwtumble.loop = true;

	 falld.PushBack({ 1064, 581, 25, 40 });

	jumpSm.PushBack({ 1089, 581, 25, 40 });
	jumpSm.loop = true;
	    
	jump.PushBack({ 1203, 685, 33, 49 });
	jump.loop = true;
	

	fwtumbleshoot.PushBack({ 107, 793, 36, 54 });
	fwtumbleshoot.PushBack({ 149, 793, 41, 54 });
	fwtumbleshoot.PushBack({ 195, 739, 36, 54 });
	fwtumbleshoot.PushBack({ 237, 739, 36, 54 });
	fwtumbleshoot.PushBack({ 278, 739, 36, 54 });
	fwtumbleshoot.PushBack({ 319, 793, 36, 54 });
	fwtumbleshoot.PushBack({ 319, 845, 36, 54 });
	fwtumble.speed = 0.2f;
	fwtumbleshoot.loop = true; 

	spawnn.PushBack({ 964, 581, 25, 40 });
	spawnn.PushBack({ 989, 581, 25, 40 });
	spawnn.PushBack({ 1014, 581, 25, 40 });
	spawnn.PushBack({ 1039 , 581, 25, 40 });
	spawnn.PushBack({ 591, 1018, 25, 40 });
	spawnn.speed = 0.05f;
	spawnn.loop = true;

	collider = App->collision->AddCollider({ 0, -20, 24, 55 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	path.PushBack({ 0, 0 }, 100, &spawnn);
	path.PushBack({ 0, 0 }, 60, &grenadeSm);
	path.PushBack({ 0, 0}, 20, &falld);
	path.PushBack({ 0, -1.0 }, 15, &jumpSm);
	path.PushBack({ 0, +1.0 }, 20, &jump);
	

	path2.PushBack({ +1.0f, 0 }, 60, &backward);
	path2.PushBack({ 0, 0 }, 67, &stop_shoot);
	path2.PushBack({ +1.0f, 0 }, 30, &fwtumble);
	path2.PushBack({ 0, 0 }, 67, &stop_shoot);
	path2.loop = true;

	original_pos.x = x;
	original_pos.y = y;
}

void Enemy_CowBoy_Blue2::Move()
{
	if (path.GetFrame() < 215)
	{
		position = original_pos + path.GetCurrentSpeed(&animation);
		position2 = position;
	}
	else
	{
		position = position2 + path2.GetCurrentSpeed(&animation);
	}
	if (path.GetFrame() == 183 && isdead == false)
	{
		App->particles->AddParticle(App->particles->enemyshot, position.x + 10, position.y + 20, COLLIDER_ENEMY_SHOT, 0);
	}
	if (path2.GetFrame() == 93 && isdead == false)
	{
		App->particles->AddParticle(App->particles->enemyshot, position.x + 10, position.y + 20, COLLIDER_ENEMY_SHOT, 0);
	}
	if (path2.GetFrame() == 192 && isdead == false)
	{
		App->particles->AddParticle(App->particles->enemyshot, position.x + 10, position.y + 20, COLLIDER_ENEMY_SHOT, 0);
	}
	if (dieshot.Finished() == true)
	{
		finished = true;
	}
}

void Enemy_CowBoy_Blue2::Die()
{

	App->player->win_condition++;
	if (path.GetFrame() < 215)
	{
		path.Erase();
		path.PushBack({ 0.0f, 0.0f }, 40, &dieshot);
		path.loop = false;
	}
	else{
		path2.Erase();
		path2.PushBack({ 0.0f, 0.0f }, 40, &dieshot);
		path2.loop = false;
	}
	
}