#include "Application.h"
#include "Enemy_CowBoy_Blue_Top_Fabten.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleAudio.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModuleSceneFirst.h"

Enemy_CowBoy_Blue_Top_Fabten::Enemy_CowBoy_Blue_Top_Fabten(float x, float y) : Enemy(x, y)
{
	backwardb.PushBack({ 117, 396, 36, 55 });
	backwardb.PushBack({ 152, 396, 36, 55 });
	backwardb.PushBack({ 188, 396, 36, 55 });
	backwardb.PushBack({ 224, 396, 36, 55 });
	backwardb.PushBack({ 261, 396, 36, 55 });
	backwardb.PushBack({ 299, 396, 36, 55 });
	backwardb.speed = 0.09f;
	backwardb.loop = true;

	forwardb.PushBack({ 117, 459, 30, 55 });
	forwardb.PushBack({ 152, 459, 30, 55 });
	forwardb.PushBack({ 188, 459, 30, 55 });
	forwardb.PushBack({ 224, 459, 30, 55 });
	forwardb.PushBack({ 261, 459, 30, 55 });
	forwardb.PushBack({ 299, 459, 30, 55 });
	forwardb.speed = 0.09f;
	forwardb.loop = true;

	forwardsm.PushBack({ 1284, 1058, 25, 40 });
	forwardsm.PushBack({ 1323, 1058, 25, 40 });
	forwardsm.PushBack({ 1353, 1058, 25, 40 });
	forwardsm.PushBack({ 1386, 1058, 25, 40 });
	forwardsm.PushBack({ 1427, 1058, 25, 40 });
	forwardsm.PushBack({ 1468, 1058, 25, 40 });
	forwardsm.speed = 0.1f;
	forwardsm.loop = true;

	backwardsm.PushBack({ 54, 1066, 25, 40 });
	backwardsm.PushBack({ 87, 1066, 25, 40 });
	backwardsm.PushBack({ 119, 1066, 25, 40 });
	backwardsm.PushBack({ 152, 1066, 25, 40 });
	backwardsm.PushBack({ 186, 1066, 25, 40 });
	backwardsm.PushBack({ 215, 1066, 25, 40 });
	backwardsm.speed = 0.1f;
	backwardsm.loop = true;

	bwtumbleb.PushBack({ 107, 565, 36, 54 });
	bwtumbleb.PushBack({ 149, 565, 41, 54 });
	bwtumbleb.PushBack({ 195, 565, 36, 54 });
	bwtumbleb.PushBack({ 237, 565, 36, 54 });
	bwtumbleb.PushBack({ 278, 565, 36, 54 });
	bwtumbleb.PushBack({ 319, 565, 36, 54 });
	bwtumbleb.speed = 0.2f;
	bwtumbleb.loop = true;

	fwtumbleb.PushBack({ 107, 739, 36, 54 });
	fwtumbleb.PushBack({ 149, 739, 41, 54 });
	fwtumbleb.PushBack({ 195, 739, 36, 54 });
	fwtumbleb.PushBack({ 237, 739, 36, 54 });
	fwtumbleb.PushBack({ 278, 739, 36, 54 });
	fwtumbleb.PushBack({ 319, 739, 36, 54 });
	fwtumbleb.speed = 0.2f;
	fwtumbleb.loop = true;

	dieshotsm.PushBack({ 285, 1065, 30, 54 });
	dieshotsm.PushBack({ 317, 1065, 30, 54 });
	dieshotsm.PushBack({ 359, 1065, 30, 54 });
	dieshotsm.PushBack({ 395, 1055, 30, 54 });

	dieshotsm.speed = 0.09f;
	dieshotsm.loop = false;

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

	shootb.PushBack({ 353, 396, 30, 55 });
	shootb.PushBack({ 392, 396, 30, 55 });
	shootb.PushBack({ 353, 396, 30, 55 });
	shootb.speed = 0.04f;
	shootb.loop = true;

	shootsm.PushBack({ 591, 1019, 25, 40 });
	shootsm.PushBack({ 623, 1019, 25, 40 });
	shootsm.speed = 0.05f;
	shootsm.loop = false;

	crouchsm.PushBack({ 1064, 581, 25, 40 });

	jumpsm.PushBack({ 1089, 581, 25, 40 });
	jumpsm.loop = true;

	jump.PushBack({ 1203, 685, 33, 49 });
	jump.loop = true;

	tumblelsm.PushBack({ 791, 1048, 33, 40 });
	tumblelsm.PushBack({ 832, 1048, 33, 40 });
	tumblelsm.PushBack({ 888, 1074, 33, 40 });
	tumblelsm.PushBack({ 922, 1074, 33, 40 });
	tumblelsm.PushBack({ 955, 1074, 33, 40 });
	tumblelsm.speed = 0.15f;

	tumblersm.PushBack({ 1222, 1047, 33, 40 });
	tumblersm.PushBack({ 1172, 1047, 33, 40 });
	tumblersm.PushBack({ 1129, 1073, 33, 40 });
	tumblersm.PushBack({ 1088, 1073, 33, 40 });
	tumblersm.PushBack({ 1043, 1073, 33, 40 });
	tumblersm.speed = 0.15f;

	spawnn.PushBack({ 964, 581, 25, 40 });
	spawnn.PushBack({ 989, 581, 25, 40 });
	spawnn.PushBack({ 1014, 581, 25, 40 });
	spawnn.PushBack({ 1039, 581, 25, 40 });
	spawnn.PushBack({ 591, 1018, 25, 40 });
	spawnn.speed = 0.05f;

	collider = App->collision->AddCollider({ 0, -20, 24, 40 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	if (x >= 20 && x <= 150)
	{
		path.PushBack({ 0, 0 }, 80, &spawnn);
		path.PushBack({ 0, 0 }, 60, &grenadesm);
		path.PushBack({ 0, 0 }, 20, &crouchsm);
		path.PushBack({ 0, -2.0f }, 20, &crouchsm);
		path.PushBack({ 0, 2.0 }, 25, &jump);
		path.PushBack({ -1.0f, 0 }, 90, &backwardb);
		path.loop = false;
	}
	else if (x >= 0 && x <= 20)
	{
		path.PushBack({ 0, 0 }, 80, &spawnn);
		path.PushBack({ 0, 0 }, 60, &grenadesm);
		path.PushBack({ 0, 0 }, 20, &crouchsm);
		path.PushBack({ 0, -2.0f }, 20, &crouchsm);
		path.PushBack({ 0, 2.0 }, 25, &jump);
		path.PushBack({ 1.0f, 0 }, 140, &forwardb);
		path.PushBack({ 0, 0 }, 35, &shootb);
		path.PushBack({ -1.0f, 0 }, 35, &bwtumbleb);
		path.PushBack({ 0, 0 }, 35, &shootb);
		path.PushBack({ 1, 0 }, 35, &fwtumbleb);
		path.PushBack({ 1.0f, 0 }, 300, &forwardb);
	}
	else
	{
		path.PushBack({ 0, 0 }, 80, &spawnn);
		path.PushBack({ 0, 0 }, 40, &shootsm);
		path.PushBack({ -1.0f, 0 }, 30, &backwardsm);
		path.PushBack({ 0, 0 }, 60, &grenadesm);
		path.PushBack({ 0, -2.0f }, 20, &jumpsm);
		path.PushBack({ -0.3f, 2.0f },50, &jumpsm);
		path.PushBack({ 0, 0 }, 20, &shootsm);
		path.PushBack({ -1.0f, 0 }, 30, &tumblelsm);
		path.PushBack({ 0, 0 }, 5, &shootsm);
		path.PushBack({ 1.0f, 0 }, 30, &tumblersm);
		path.PushBack({ 0, 0 }, 20, &shootsm);
		path.PushBack({ -1.0f, 0 }, 500, &backwardsm);
		path.loop = false;
	}

	original_pos.x = x;
	original_pos.y = y;

}

void Enemy_CowBoy_Blue_Top_Fabten::Move()
{
	position = original_pos + path.GetCurrentSpeed(&animation);
	if (original_pos.x == 170)
	{
		if (path.GetFrame() == 110)
		{
			App->particles->AddParticle(App->particles->enemyshot, position.x + 5, position.y + 10, COLLIDER_ENEMY_SHOT, 0);
		}
	}
	if (path.GetFrame() == 160)
	{
		App->audio->PlayFx(App->particles->bombthrow.fx, 400);
		App->particles->AddParticle(App->particles->enemyDynamite, position.x + 10, position.y + 20, COLLIDER_BOMB, 0);
	}
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