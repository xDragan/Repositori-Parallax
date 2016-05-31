#include "Application.h"
#include "Enemy_CowBoy_Blue_Top_Small.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"
#include "ModuleSceneFirst.h"

Enemy_CowBoy_Blue_Top_Small::Enemy_CowBoy_Blue_Top_Small(float x, float y) : Enemy(x, y)
{
	forward.PushBack({ 68, 1660, 17, 23 });
	forward.PushBack({ 94, 1660, 17, 23 });
	forward.PushBack({ 123, 1660, 17, 23 });
	forward.PushBack({ 151, 1660, 17, 23 });
	forward.PushBack({ 176, 1660, 17, 23 });
	forward.PushBack({ 202, 1660, 17, 23 });
	forward.speed = 0.15f;
	forward.loop = true;

	backward.PushBack({ 68, 1630, 17, 23 });
	backward.PushBack({ 94, 1630, 17, 23 });
	backward.PushBack({ 123, 1630, 17, 23 });
	backward.PushBack({ 151, 1630, 17, 23 });
	backward.PushBack({ 176, 1630, 17, 23 });
	backward.PushBack({ 202, 1630, 17, 23 });
	backward.speed = 0.09f;
	backward.loop = true;

	dieshot.PushBack({ 275, 1630, 17, 23 });
	dieshot.PushBack({ 297, 1630, 17, 23 });
	dieshot.PushBack({ 322, 1630, 17, 23 });
	dieshot.PushBack({ 342, 1630, 17, 23 });
	dieshot.speed = 0.09f;
	dieshot.loop = false;

	dieexplotion.PushBack({ 744, 397, 36, 54 });
	dieexplotion.PushBack({ 798, 397, 36, 54 });
	dieexplotion.PushBack({ 844, 397, 36, 54 });
	dieexplotion.PushBack({ 889, 397, 36, 54 });
	dieexplotion.speed = 0.3f;

	grenadeSm.PushBack({ 437, 1630, 15, 25 });
	grenadeSm.PushBack({ 454, 1630, 15, 25 });
	grenadeSm.PushBack({ 471, 1630, 15, 25 });
	grenadeSm.PushBack({ 491, 1630, 15, 25 });
	grenadeSm.PushBack({ 510, 1630, 15, 25 });
	grenadeSm.PushBack({ 527, 1630, 15, 25 });
	grenadeSm.speed = 0.1f;
	grenadeSm.loop = true;

	fwtumble.PushBack({ 1111, 1630, 15, 23 });
	fwtumble.PushBack({ 1080, 1630 , 15, 23 });
	fwtumble.PushBack({ 1064, 1630, 15, 23 });
	fwtumble.PushBack({ 1008, 1630, 15, 23 });
	fwtumble.PushBack({ 1026, 1630, 15, 23 });
	fwtumble.speed = 0.1f;
	fwtumble.loop = true;




	spawnn.PushBack({ 551, 1630, 17, 23 });
	spawnn.PushBack({ 570, 1630, 17, 23 });
	spawnn.PushBack({ 593, 1630, 17, 23 });
	spawnn.PushBack({ 618, 1630, 17, 23 });
	spawnn.PushBack({ 437, 1630, 17, 23 }); 
	spawnn.speed = 0.08f;


	collider = App->collision->AddCollider({ 0, -20, 24, 55 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);


	if (x == 10|| x==70){

		path.PushBack({ 0, 0 }, 50, &spawnn);
		path.PushBack({ 0.6f, 0 }, 40, &forward);
		path.PushBack({ 0, 0 }, 60, &grenadeSm);
		path.PushBack({ -0.6f, 0 }, 300, &backward);
		
		path.loop = false;
	}

	if (x==40  ){

		path.PushBack({ 0, 0 }, 50, &spawnn);
		path.PushBack({ 0.6f, 0 }, 40, &forward);
		path.PushBack({ 0, 0 }, 60, &grenadeSm);
		path.PushBack({ 0.6f, 0 }, 100, &forward);
		path.PushBack({ 1.0f, 0 }, 15, &fwtumble);
		path.PushBack({ 0, 0 }, 60, &grenadeSm);
		path.PushBack({ -0.6f, 0 }, 300, &backward);

		path.loop = false;

	}


	if (x == 195){

		path.PushBack({ 0, 0 }, 50, &spawnn);
		path.PushBack({ 1.0, 0 }, 50, &forward);
		path.PushBack({ 0, 0 }, 60, &grenadeSm);
		path.PushBack({ -1.0f, 0 }, 100, &backward);
		path.loop = false; 

	}




	original_pos.x = x;
	original_pos.y = y;

}

void Enemy_CowBoy_Blue_Top_Small::Move()
{
	position = original_pos + path.GetCurrentSpeed(&animation);

	if (dieshot.Finished() == true)
	{
		finished = true;
	}

}

void Enemy_CowBoy_Blue_Top_Small::Die()
{
	collider->type = COLLIDER_NONE;
	App->player->win_condition++;
	path.Erase();
	path.PushBack({ 0.0f, 0.0f }, 40, &dieshot);
	path.loop = false;
}