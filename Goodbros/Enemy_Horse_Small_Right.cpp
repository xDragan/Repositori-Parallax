#include "Application.h"
#include "Enemy_Horse_Small_Right.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"
#include "ModuleSceneFirst.h"

Enemy_Horse_Small_Right::Enemy_Horse_Small_Right(float x, float y) : Enemy(x, y)
{
	backward.PushBack({ 609, 1809, 30, 30 });
	backward.PushBack({ 652, 1809, 30, 30 });
	backward.PushBack({ 690, 1809, 30, 30 });
	backward.PushBack({ 728, 1809, 30, 30 });
	backward.PushBack({ 778, 1809, 30, 30 });
	backward.PushBack({ 820, 1809, 30, 30 });
	backward.PushBack({ 862, 1809, 30, 30 });
	backward.PushBack({ 905, 1809, 30, 30 });
	backward.speed = 0.15f;


	dieshot.PushBack({ 952, 1809, 30, 30 });
	dieshot.PushBack({ 999, 1809, 30, 30 });
	dieshot.PushBack({ 1043, 1809, 30, 30 });
	dieshot.PushBack({ 952, 1809, 30, 30 });
	dieshot.PushBack({ 999, 1809, 30, 30 });
	dieshot.PushBack({ 1043, 1809, 30, 30 });
	dieshot.PushBack({ 952, 1809, 30, 30 });
	dieshot.PushBack({ 999, 1809, 30, 30 });
	dieshot.PushBack({ 1043, 1809, 30, 30 });
	dieshot.PushBack({ 608, 1856, 30, 30 });

	dieshot.speed = 0.12f;
	dieshot.loop = true;





	collider = App->collision->AddCollider({ 0, -20, 30, 30 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	path.PushBack({ -1.0f, 0 }, 500, &backward);



	original_pos.x = x;
	original_pos.y = y;
}

void Enemy_Horse_Small_Right::Move()
{
	position = original_pos + path.GetCurrentSpeed(&animation);

	if (dieshot.Finished() == true)
	{
		finished = true;
	}
}

void Enemy_Horse_Small_Right::Die()
{
	collider->type = COLLIDER_NONE;
	App->player->win_condition++;
	path.Erase();
	path.PushBack({ 0.0f, 0.0f }, 150, &dieshot);
	path.PushBack({ -2.50f, 0.0f }, 200, &backward);


}