#include "Application.h"
#include "Bar_House.h"
#include "ModuleCollision.h"

Bar_House::Bar_House(int x, int y) : Enemy(x, y)
{
	destroy.PushBack({ 0, 11, 38, 27 });
	destroy.PushBack({ 39, 11, 38, 27 });
	destroy.speed = 0.07f;

	animation = &destroy;

	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_NONE, (Module*)App->enemies);

}

