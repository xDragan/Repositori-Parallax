#include "Application.h"
#include "Bar_House.h"
#include "ModuleCollision.h"

Bar_House::Bar_House(int x, int y) : Enemy(x, y)
{
	run.PushBack({ 0, 11, 38, 27 });
	run.PushBack({ 39, 11, 38, 27 });
	run.speed = 0.07f;

	animation = &run;

	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_NONE, (Module*)App->enemies);

}

