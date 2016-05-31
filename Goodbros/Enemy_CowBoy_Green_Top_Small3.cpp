#include "Application.h"
#include "Enemy_CowBoy_Green_Top_Small3.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"
#include "ModuleSceneFirst.h"

Enemy_CowBoy_Green_Top_Small3::Enemy_CowBoy_Green_Top_Small3(float x, float y) : Enemy(x, y)
{
	forward.PushBack({ 898, 2903, 20, 30 });
	forward.PushBack({ 932, 2903, 20, 30 });
	forward.PushBack({ 965, 2903, 20, 30 });
	forward.PushBack({ 994, 2903, 20, 30 });
	forward.PushBack({ 1028, 2903, 20, 30 });
	forward.PushBack({ 1061, 2903, 20, 30 });
	forward.speed = 0.15f;
	forward.loop = true;

	backward.PushBack({ 460, 2934, 20, 30 });
	backward.PushBack({ 491, 2934, 20, 30 });
	backward.PushBack({ 522, 2934, 20, 30 });
	backward.PushBack({ 557, 2934, 20, 30 });
	backward.PushBack({ 589, 2934, 20, 30 });
	backward.PushBack({ 620, 2934, 20, 30 });
	backward.speed = 0.09f;
	backward.loop = true;

	dieshot.PushBack({ 714, 2934, 20, 30 });
	dieshot.PushBack({ 747, 2934, 20, 30 });
	dieshot.PushBack({ 777, 2934, 13, 30 });
	dieshot.PushBack({ 794, 2934, 20, 30 });
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

	shoot.PushBack({ 651, 2940, 25, 40 });
	shoot.PushBack({ 683, 2940, 25, 40 });
	shoot.speed = 0.10f;
	shoot.loop = false;


	spawnup.PushBack({ 1094, 2912, 15, 20 });
	spawnup.PushBack({ 1110, 2912, 15, 20 });
	spawnup.PushBack({ 1127, 2912, 15, 20 });
	spawnup.PushBack({ 1144, 2912, 15, 20 });
	spawnup.speed = 0.10f;
	spawnup.loop = false;



	spawndown.PushBack({ 1144, 2912, 15, 20 });
	spawndown.PushBack({ 1127, 2912, 15, 20 });
	spawndown.PushBack({ 1110, 2912, 15, 20 });
	spawndown.PushBack({ 1094, 2912, 15, 20 });
	spawndown.speed = 0.10f;
	spawndown.loop = false;


	jumpSm.PushBack({ 780, 2981, 20, 30 });
	jumpSm.PushBack({ 749, 2981, 20, 30 });
	jumpSm.PushBack({ 749, 2981, 20, 30 });
	jumpSm.PushBack({ 780, 2981, 25, 40 });
	jumpSm.loop = true;
	jumpSm.speed = 0.05f;



	spawnn.PushBack({ 477, 2984, 15, 20 });
	spawnn.PushBack({ 509, 2984, 15, 20 });
	spawnn.PushBack({ 541, 2984, 15, 20 });
	spawnn.PushBack({ 572, 2999, 15, 20 });
	spawnn.speed = 0.08f;


	collider = App->collision->AddCollider({ 0, -20, 24, 55 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);




	if (y == 31){

		path.PushBack({ 0, 0 }, 50, &spawnup);
		path.PushBack({ 0, 0 }, 50, &shoot);
		path.PushBack({ 0, 0 }, 50, &shoot);
		path.PushBack({ 0, 0 }, 50, &spawndown);
		path.loop = false;

	}

	if (y == 15){


		path.PushBack({ 0, 0 }, 50, &spawnup);
		path.PushBack({ 0, 0 }, 50, &shoot);
		path.PushBack({ 0, 0 }, 50, &shoot);
		path.PushBack({ 0, 0 }, 50, &spawndown);
		path.loop = false;



	}




	original_pos.x = x;
	original_pos.y = y;

}

void Enemy_CowBoy_Green_Top_Small3::Move()
{
	position = original_pos + path.GetCurrentSpeed(&animation);

	if (path.GetFrame() == 200){
		finished = true;
	}

	if (dieshot.Finished() == true)
	{
		finished = true;
	}

}

void Enemy_CowBoy_Green_Top_Small3::Die()
{
	collider->type = COLLIDER_NONE;
	App->player->win_condition++;
	path.Erase();
	path.PushBack({ 0.0f, 0.0f }, 40, &dieshot);
	path.loop = false;
}