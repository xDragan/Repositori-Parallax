#include "Application.h"
#include "Module_Points.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleUI.h"

Module_Points::Module_Points(float x, float y, uint points) :Enemy(x, y)
{
	to_score = points;
	switch (points){
	case 1000:
		p1000.PushBack({ 8, 11, 20, 12 });
		p1000.PushBack({ 32, 11, 20, 12 });
		p1000.speed = 0.15f;
		path.PushBack({ 0, -1.6f }, 12, &p1000);
		path.PushBack({ 0, -1.0f }, 7, &p1000);
		path.PushBack({ 0, 0 }, 5.5, &p1000);
		path.PushBack({ 0, 0.8f }, 5, &p1000);
		path.PushBack({ 0, 1.2f }, 5, &p1000);
		path.PushBack({ 0, 1.4f }, 10, &p1000);
		path.PushBack({ 0, 1.8f }, 25, &p1000);
		path.loop = false;
		collider = App->collision->AddCollider({ 0, 0, 20, 12 }, COLLIDER_TYPE::COLLIDER_POINTS, (Module*)App->enemies);
		break;
	case 5000:
		p5000.PushBack({ 55, 9, 26, 14 });
		p5000.PushBack({ 83, 9, 26, 14 });
		p5000.speed = 0.15f;
		path.PushBack({ 0, -1.0f }, 15, &p5000);
		path.PushBack({ 0, -0.4f }, 4, &p5000);
		path.PushBack({ 0, 0 }, 3.5, &p5000);
		path.PushBack({ 0, 1.2f }, 10, &p5000);
		path.PushBack({ 0, 1.4f }, 20, &p5000);
		path.PushBack({ 0, 1.8f }, 30, &p5000);
		path.PushBack({ 0, 2.1f }, 39, &p5000);
		path.loop = false;
		collider = App->collision->AddCollider({ 0, 0, 26, 14 }, COLLIDER_TYPE::COLLIDER_POINTS, (Module*)App->enemies);
		break;
	case 7000:
		p7000.PushBack({ 112, 9, 26, 14 });
		p7000.PushBack({ 145, 9, 26, 14 });
		p7000.speed = 0.15f;
		path.PushBack({ 0, -1.0f }, 15, &p7000);
		path.PushBack({ 0, -0.4f }, 4, &p7000);
		path.PushBack({ 0, 0 }, 3.5, &p7000);
		path.PushBack({ 0, 1.2f }, 10, &p7000);
		path.PushBack({ 0, 1.4f }, 20, &p7000);
		path.PushBack({ 0, 1.8f }, 30, &p7000);
		path.PushBack({ 0, 2.1f }, 39, &p7000);
		path.loop = false;
		collider = App->collision->AddCollider({ 0, 0, 26, 14 }, COLLIDER_TYPE::COLLIDER_POINTS, (Module*)App->enemies);
		break;
	case 10000:
		p10000.PushBack({ 173, 7, 39, 16 });
		p10000.PushBack({ 213, 7, 39, 16 });
		p10000.speed = 0.15f;
		path.PushBack({ 0, -1.0f }, 15, &p10000);
		path.PushBack({ 0, -0.4f }, 4, &p10000);
		path.PushBack({ 0, 0 }, 3.5, &p10000);
		path.PushBack({ 0, 1.2f }, 10, &p10000);
		path.PushBack({ 0, 1.4f }, 20, &p10000);
		path.PushBack({ 0, 1.8f }, 30, &p10000);
		path.PushBack({ 0, 2.1f }, 39, &p10000);
		path.loop = false;
		collider = App->collision->AddCollider({ 0, 0, 39, 16 }, COLLIDER_TYPE::COLLIDER_POINTS, (Module*)App->enemies);
		break;
	case 1: //1==grenade pop
		to_score = 1;
		grenade_pop.PushBack({ 197, 33, 16, 16 });
		grenade_pop.PushBack({ 217, 33, 16, 16 });
		grenade_pop.speed = 0.2f;
		path.PushBack({ 0, -1.6f }, 15, &grenade_pop);
		path.PushBack({ 0, -1.0f }, 7, &grenade_pop);
		path.PushBack({ 0, 0 }, 5.5, &grenade_pop);
		path.PushBack({ 0, 0.8f }, 5, &grenade_pop);
		path.PushBack({ 0, 1.2f }, 5, &grenade_pop);
		path.PushBack({ 0, 1.4f }, 10, &grenade_pop);
		path.PushBack({ 0, 1.8f }, 25.5, &grenade_pop);
		path.loop = false;
		collider = App->collision->AddCollider({ 0, 0, 16, 16 }, COLLIDER_TYPE::COLLIDER_POINTS, (Module*)App->enemies);
		break;
	case 2: //2==1up
		to_score = 2;
		up1.PushBack({239, 33, 16, 16 });
		up1.PushBack({ 261, 33, 16, 16 });
		up1.speed = 0.2f;
		path.PushBack({ 0, -1.6f }, 15, &up1);
		path.PushBack({ 0, -1.0f }, 7, &up1);
		path.PushBack({ 0, 0 }, 5.5, &up1);
		path.PushBack({ 0, 0.8f }, 5, &up1);
		path.PushBack({ 0, 1.2f }, 5, &up1);
		path.PushBack({ 0, 1.4f }, 10, &up1);
		path.PushBack({ 0, 1.8f }, 25.5, &up1);
		path.loop = false;
		collider = App->collision->AddCollider({ 0, 0, 16, 16 }, COLLIDER_TYPE::COLLIDER_POINTS, (Module*)App->enemies);
		break;
	}



	original_pos.x = x;
	original_pos.y = y;
}

void Module_Points::Move()
{

	position = original_pos + path.GetCurrentSpeed(&animation);

}

void Module_Points::Die()
{
	
	path.Erase();
	switch (to_score){
	case 1000:
		App->UserUI->score += to_score - 100;
		p1000.PushBack({ 0, 0, 0, 0 });
		p1000.loop = false;
		break;
	case 5000:
		App->UserUI->score += to_score - 100;
		p5000.PushBack({ 0, 0, 0, 0 });
		p5000.loop = false;
		break;
	case 10000:
		App->UserUI->score += to_score - 100;
		p10000.PushBack({ 0, 0, 0, 0 });
		p10000.loop = false;
		break;
	case 7000:
		App->UserUI->score += to_score - 100;
		p7000.PushBack({ 0, 0, 0, 0 });
		p7000.loop = false;
		break;
	case 1:
		App->UserUI->dynamite++;
		grenade_pop.PushBack({ 0, 0, 0, 0 });
		grenade_pop.loop = false;
		break;
	case 2:
		App->UserUI->hitpoints--;
		up1.PushBack({ 0, 0, 0, 0 });
		up1.loop = false;
		break;
	}

	
	finished = true; 
}