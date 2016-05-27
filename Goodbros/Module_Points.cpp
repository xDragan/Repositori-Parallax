#include "Application.h"
#include "Module_Points.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleUI.h"

Module_Points::Module_Points(float x, float y, uint points) :Enemy(x, y)  //Y=5,, DF 6
{
	to_score = points;
	switch (points)
	{
	case 1000:
		point.PushBack({ 8, 11, 20, 11 });
		point.PushBack({ 32, 11, 20, 11 });
		point.speed = 0.15f;
		path.PushBack({ 0, -1.6f }, 12, &point);
		path.PushBack({ 0, -1.0f }, 7, &point);
		path.PushBack({ 0, 0 }, 5.5, &point);
		path.PushBack({ 0, 0.8f }, 4, &point);
		path.PushBack({ 0, 1.2f }, 5, &point);
		path.PushBack({ 0, 1.4f }, 8, &point);
		path.PushBack({ 0, 1.8f }, 23, &point);
		path.loop = false;
		collider = App->collision->AddCollider({ 0, 0, 20, 11 }, COLLIDER_TYPE::COLLIDER_POINTS, (Module*)App->enemies);
		break;
	case 5000:
		point.PushBack({ 55, 9, 26, 14 });
		point.PushBack({ 83, 9, 26, 14 });
		point.speed = 0.15f;
		path.PushBack({ 0, -1.0f }, 15, &point);
		path.PushBack({ 0, -0.4f }, 4, &point);
		path.PushBack({ 0, 0 }, 3.5, &point);
		path.PushBack({ 0, 1.2f }, 11, &point);
		path.PushBack({ 0, 1.4f }, 19, &point);
		path.PushBack({ 0, 1.8f }, 29, &point);
		path.PushBack({ 0, 2.1f }, 370, &point);
		path.loop = false;
		collider = App->collision->AddCollider({ 0, 0, 26, 14 }, COLLIDER_TYPE::COLLIDER_POINTS, (Module*)App->enemies);
		break;
	case 7000:
		point.PushBack({ 112, 9, 26, 14 });
		point.PushBack({ 145, 9, 26, 14 });
		point.speed = 0.15f;
		path.PushBack({ 0, -1.0f }, 15, &point);
		path.PushBack({ 0, -0.4f }, 4, &point);
		path.PushBack({ 0, 0 }, 3.5, &point);
		path.PushBack({ 0, 1.2f }, 11, &point);
		path.PushBack({ 0, 1.4f }, 19, &point);
		path.PushBack({ 0, 1.8f }, 29, &point);
		path.PushBack({ 0, 2.1f }, 370, &point);
		path.loop = false;
		collider = App->collision->AddCollider({ 0, 0, 26, 14 }, COLLIDER_TYPE::COLLIDER_POINTS, (Module*)App->enemies);
		break;
	case 10000:
		point.PushBack({ 173, 7, 39, 16 });
		point.PushBack({ 213, 7, 39, 16 });
		point.speed = 0.15f;
		path.PushBack({ 0, -1.0f }, 15, &point);
		path.PushBack({ 0, -0.4f }, 4, &point);
		path.PushBack({ 0, 0 }, 3.5, &point);
		path.PushBack({ 0, 1.2f }, 11, &point);
		path.PushBack({ 0, 1.4f }, 19, &point);
		path.PushBack({ 0, 1.8f }, 29, &point);
		path.PushBack({ 0, 2.1f }, 360, &point);
		path.loop = false;
		collider = App->collision->AddCollider({ 0, 0, 39, 16 }, COLLIDER_TYPE::COLLIDER_POINTS, (Module*)App->enemies);
		break;
	case 1: //1==grenade pop
		to_score = 1;
		point.PushBack({ 197, 33, 16, 16 });
		point.PushBack({ 217, 33, 16, 16 });
		point.speed = 0.18f;
		path.PushBack({ 0, -1.6f }, 15, &point);
		path.PushBack({ 0, -1.0f }, 7, &point);
		path.PushBack({ 0, 0 }, 6.5, &point);
		path.PushBack({ 0, 0.8f }, 13, &point);
		path.PushBack({ 0, 1.2f }, 13, &point);
		path.PushBack({ 0, 1.4f }, 20, &point);
		path.PushBack({ 0, 1.8f }, 280.5, &point);
		path.loop = false;
		collider = App->collision->AddCollider({ 0, 0, 16, 16 }, COLLIDER_TYPE::COLLIDER_POINTS, (Module*)App->enemies);
		break;
	case 2: //2==1up
		to_score = 2;
		point.PushBack({ 239, 33, 16, 16 });
		point.PushBack({ 261, 33, 16, 16 });
		point.speed = 0.12f;
		path.PushBack({ 0, -1.6f }, 15, &point);
		path.PushBack({ 0, -1.0f }, 7, &point);
		path.PushBack({ 0, 0 }, 5.5, &point);
		path.PushBack({ 0, 0.8f }, 4, &point);
		path.PushBack({ 0, 1.2f }, 4, &point);
		path.PushBack({ 0, 1.4f }, 9, &point);
		path.PushBack({ 0, 1.8f }, 210.5, &point);
		path.loop = false;
		collider = App->collision->AddCollider({ 0, 0, 16, 16 }, COLLIDER_TYPE::COLLIDER_POINTS, (Module*)App->enemies);
		break;
	case 3: //3==escopeta
		to_score = 2;
		point.PushBack({ 339, 7, 32, 16 });
		point.PushBack({ 373, 7, 32, 16 });
		point.speed = 0.12f;
		path.PushBack({ 0, -1.6f }, 15, &point);
		path.PushBack({ 0, -1.0f }, 7, &point);
		path.PushBack({ 0, 0 }, 8.5, &point);
		path.PushBack({ 0, 0.8f }, 14, &point);
		path.PushBack({ 0, 1.2f }, 14, &point);
		path.PushBack({ 0, 1.4f }, 19, &point);
		path.PushBack({ 0, 1.8f }, 280.5, &point);
		path.loop = false;
		collider = App->collision->AddCollider({ 0, 0, 32, 16 }, COLLIDER_TYPE::COLLIDER_POINTS, (Module*)App->enemies);
		break;
	case 4: //4==metralleta
		to_score = 2;
		point.PushBack({ 407, 7, 32, 16 });
		point.PushBack({ 457, 7, 32, 16 });
		point.speed = 0.12f;
		path.PushBack({ 0, -1.6f }, 15, &point);
		path.PushBack({ 0, -1.0f }, 7, &point);
		path.PushBack({ 0, 0 }, 8.5, &point);
		path.PushBack({ 0, 0.8f }, 14, &point);
		path.PushBack({ 0, 1.2f }, 14, &point);
		path.PushBack({ 0, 1.4f }, 19, &point);
		path.PushBack({ 0, 1.8f }, 280.5, &point);
		path.loop = false;
		collider = App->collision->AddCollider({ 0, 0, 16, 26 }, COLLIDER_TYPE::COLLIDER_POINTS, (Module*)App->enemies);
		break;
	}
	original_pos.x = x;
	original_pos.y = y;
}

void Module_Points::Move()
{
	if (position.y >= 181){
		path.Erase();
	}
	position = original_pos + path.GetCurrentSpeed(&animation);
}

void Module_Points::Die()
{

	path.Erase();
	switch (to_score){
	case 1:
		App->UserUI->dynamite++;
		break;
	case 2:
		App->UserUI->hitpoints--;
		break;
	case 3:

		break;
	case 4:

		break;
	default:
		App->UserUI->score += to_score - 100;
		break;
	}
	point.PushBack({ 0, 0, 0, 0 });
	point.loop = false;
	finished = true;
}