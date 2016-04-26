#include "Application.h"
#include "Bar_House.h"
#include "ModuleCollision.h"

Bar_House::Bar_House(int x, int y) : Enemy(x, y)
{
	
	if (hp >= 80){
		destroy.PushBack({ 80, 2266, 115, 147 });  //115x147
	}
	else if (hp >= 60){
		destroy.PushBack({ 345, 2266, 115, 147 });  //115x147
	}
	//destroy.speed = 0.07f;

	animation = &destroy;

	collider = App->collision->AddCollider({ 145, 0, 115, 147 }, COLLIDER_TYPE::COLLIDER_NONE, (Module*)App->enemies);

}

