#include "Application.h"
#include "Enemy_Horse_Right.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"
#include "ModuleSceneFirst.h"
#include "ModuleAudio.h"

Enemy_Horse_Right::Enemy_Horse_Right(float x, float y) : Enemy(x, y)
{
	backward.PushBack({ 764, 1173, 46, 57 });
	backward.PushBack({ 864, 1173, 46, 57 });
	backward.PushBack({ 864, 1173, 46, 57 });
	backward.PushBack({ 1012, 1173, 46, 57 });
	backward.PushBack({ 1082, 1173, 46, 57 });
	backward.PushBack({ 1154, 1173, 46, 57 });
	backward.PushBack({ 1223, 1173, 46, 57 });
	backward.PushBack({ 1290, 1173, 46, 57 });
	backward.speed = 0.15f;
	backward.loop = true;
		

	dieshot.PushBack({ 698, 1173, 46, 57 });
	dieshot.PushBack({ 674, 1320, 46, 57 });
	dieshot.PushBack({ 742, 1320, 46, 57 }); 
	dieshot.PushBack({ 698, 1173, 46, 57 });
	dieshot.PushBack({ 674, 1320, 46, 57 });
	dieshot.PushBack({ 742, 1320, 46, 57 });
	dieshot.PushBack({ 698, 1173, 46, 57 });
	dieshot.PushBack({ 674, 1320, 46, 57 });
	dieshot.PushBack({ 742, 1320, 46, 57 });
	dieshot.PushBack({ 878, 1320, 46, 57 });
	
	dieshot.speed = 0.12f;
	dieshot.loop = true;

	



	collider = App->collision->AddCollider({ 0, -20, 40, 40 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	path.PushBack({ -1.5f, 0 }, 200, &backward);
	path.PushBack({ -1.5f, 0 }, 200, &backward);


	original_pos.x = x;
	original_pos.y = y;
}

void Enemy_Horse_Right::Move()
{
	position = original_pos + path.GetCurrentSpeed(&animation);

	if (dieshot.Finished() == true){
		path.PushBack({ -2.50f, 0.0f }, 200, &backward);
	}
	if (position.x <= -50)
	{
		finished = true;
	}
	if (hit == true && App->particles->horse_hit.fx_played == false)
	{
		App->audio->PlayFx(App->particles->horse_hit.fx, 1000);
		App->particles->horse_hit.fx_played = true;
	}
}

void Enemy_Horse_Right::Die()
{
	collider->type = COLLIDER_NONE;
	App->player->win_condition++;
	path.Erase();
	if (hit == false){
		path.PushBack({ 0.0f, 0.0f }, 130, &dieshot);
		path.loop = false;
	}	
	hit = true;
	
	
}