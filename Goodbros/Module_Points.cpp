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
	}



	original_pos.x = x;
	original_pos.y = y;
	//path.loop = true;
}

void Module_Points::Move()
{

	position = original_pos + path.GetCurrentSpeed(&animation);

}

void Module_Points::Die()
{
	App->UserUI->score += to_score;
	path.Erase();
	p1000.PushBack({ 0, 0, 0, 0 });
	p1000.loop = false;
	p5000.PushBack({ 0, 0, 0, 0 });
	p5000.loop = false;
	p7000.PushBack({ 0, 0, 0, 0 });
	p7000.loop = false;
	p10000.PushBack({ 0, 0, 0, 0 });
	p10000.loop = false;
	collider->to_delete = false;
	delete collider;
	collider = nullptr;
}