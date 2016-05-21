#include "Application.h"
#include "Enemy_Barrel_Roll.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"

Enemy_Barrel_Roll::Enemy_Barrel_Roll(float x, float y) : Enemy(x, y)
{
	forward.PushBack({ 241, 2711, 48, 48 });
	forward.PushBack({ 293, 2711, 48, 48 });
	forward.PushBack({ 347, 2711, 48, 48 });
	forward.speed = 0.1f;

	backward.PushBack({ 347, 2711, 48, 48 });
	backward.PushBack({ 293, 2711, 48, 48 });
	backward.PushBack({ 241, 2711, 48, 48 });
	backward.speed = 0.1f;

	collider = App->collision->AddCollider({ 0, 0, 22, 55 }, COLLIDER_TYPE::COLLIDER_NONE, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;


	path.PushBack({ 1.0f, 0 }, 270, &backward);
	path.PushBack({ -1.0f, 0 }, 550, &forward);
	path.loop = true;
}

void Enemy_Barrel_Roll::Move()
{
	position = original_pos + path.GetCurrentSpeed(&animation);



	/*
	if (path.GetFrame() == 120)
	{
		App->particles->AddParticle(App->particles->enemyshot, position.x + 10, position.y + 20, COLLIDER_ENEMY_SHOT, 0);
	}
	if (path.GetFrame() == 237 && isdead == false)
	{
		App->particles->AddParticle(App->particles->enemyshot, position.x + 10, position.y + 20, COLLIDER_ENEMY_SHOT, 0);
	}
	*/
}

