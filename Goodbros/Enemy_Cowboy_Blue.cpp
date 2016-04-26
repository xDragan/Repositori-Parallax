 #include "Application.h"
#include "Enemy_CowBoy_Blue.h"
#include "ModuleCollision.h"

Enemy_CowBoy_Blue::Enemy_CowBoy_Blue(int x, int y) : Enemy(x, y)
{
	forward.PushBack({ 117, 396, 30, 55 });
	forward.PushBack({ 152, 396, 30, 55 });
	forward.PushBack({ 188, 396, 30, 55 });
	forward.PushBack({ 224, 396, 30, 55 });
	forward.PushBack({ 261, 396, 30, 55 });
	forward.PushBack({ 299, 396, 30, 55 });
	forward.speed = 0.09f;

	backward.PushBack({ 117, 459, 30, 55 });
	backward.PushBack({ 152, 459, 30, 55 });
	backward.PushBack({ 188, 459, 30, 55 });
	backward.PushBack({ 224, 459, 30, 55 });
	backward.PushBack({ 261, 459, 30, 55 });
	backward.PushBack({ 299, 459, 30, 55 });
	backward.speed = 0.09f;

	stop_shoot.PushBack({ 353, 396, 30, 55 });
	stop_shoot.PushBack({ 392, 396, 30, 55 });
	stop_shoot.PushBack({ 353, 396, 30, 55 });
	stop_shoot.speed = 0.04f;
	stop_shoot.loop = true;


	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);


	original_pos.x = x;
	original_pos.y = y;
	path.PushBack({ -1.0f, 0 }, 150, &forward);
	path.PushBack({ 0, 0 }, 67, &stop_shoot);
	path.PushBack({ 1.0f, 0 }, 150, &backward);

	original_y2 = y;
}

void Enemy_CowBoy_Blue::Move()
{
	position = original_pos + path.GetCurrentSpeed(&animation);
}
