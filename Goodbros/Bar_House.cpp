#include "Application.h"
#include "Bar_House.h"
#include "ModuleCollision.h"

Bar_House::Bar_House(int x, int y) : Enemy(x, y)
{
	
	switch (hp){
	case 4: destroy.PushBack({ 80, 2266, 115, 147 });  //115x147
		break;
	case 3:	destroy.PushBack({ 218, 2266, 115, 147 });
		break;
	case 2:	destroy.PushBack({ 345, 2266, 115, 147 });
		break;
	case 1:	destroy.PushBack({ 490, 2266, 115, 147 });
		break;
	}
	//destroy.speed = 0.07f;

	animation = &destroy;

	collider = App->collision->AddCollider({ 145, 0, 115, 147 }, COLLIDER_TYPE::COLLIDER_STRUCTURE, (Module*)App->enemies);

}

