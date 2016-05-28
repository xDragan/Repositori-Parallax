#include "Application.h"
#include "Enemy_Can.h"
#include "Module_Points.h"
#include "Enemy.h"
#include "ModuleEnemies.h"
#include "ModuleCollision.h"

Enemy_Can::Enemy_Can(float x, float y) : Enemy(x, y)
{
	iddle.PushBack({ 165, 3055, 15, 17 });
	

	rightfly.PushBack({ 197, 3055, 15, 17 });
	rightfly.PushBack({ 214, 3055, 15, 17 });
	rightfly.PushBack({ 231, 3055, 15, 17 });
	rightfly.PushBack({ 252, 3055, 15, 17 });
	rightfly.PushBack({ 269, 3055, 15, 17 });
	rightfly.PushBack({ 284, 3055, 15, 17 });
	rightfly.PushBack({ 299, 3055, 15, 17 });
	rightfly.PushBack({ 192, 3055, 15, 17 });
	rightfly.speed = 0.20f;
	

	leftfly.PushBack({ 192, 3055, 15, 17 });
	leftfly.PushBack({ 214, 3055, 15, 17 });
	leftfly.PushBack({ 231, 3055, 15, 17 });
	leftfly.PushBack({ 252, 3055, 15, 17 });
	leftfly.PushBack({ 269, 3055, 15, 17 });
	leftfly.PushBack({ 284, 3055, 15, 17 });
	leftfly.PushBack({ 299, 3055, 15, 17 });
	leftfly.PushBack({ 192, 3055, 15, 17 });
	leftfly.speed = 0.20f;

	


	collider = App->collision->AddCollider({ 0, 0, 15, 17 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;


	animation = &iddle;
}

void Enemy_Can::Move()
{
	position = original_pos + path.GetCurrentSpeed(&animation);

	if (position.y >= 130){
		path.Erase();
		animation = &iddle;
		hit = false;
	}
	if (position.x >= SCREEN_WIDTH - 15 && position.y <= 130){
		path.Erase();
		path.Reset();
		path.PushBack({ -0.9f, -1.0f }, 5, &rightfly);
		path.PushBack({ -1.0f, -0.1f }, 5, &rightfly);
		path.PushBack({ -1.0f, 0.1f }, 5, &rightfly);
		path.PushBack({ -0.9f, 1.0f }, 5, &rightfly);
		path.PushBack({ -0.8f, 1.0f }, 5, &rightfly);
		path.PushBack({ -0.7f, 1.0f }, 5, &rightfly);
		path.PushBack({ -0.6f, 1.0f }, 5, &rightfly);
		path.PushBack({ -0.5f, 1.0f }, 5, &rightfly);
		path.PushBack({ -0.4f, 1.0f }, 5, &rightfly);
		path.PushBack({ -0.3f, 1.0f }, 5, &rightfly);
		path.PushBack({ -0.2f, 1.0f }, 5, &rightfly);
		path.PushBack({ -0.1f, 1.0f }, 5, &rightfly);
		path.PushBack({ 0, 1.0f }, 700, &leftfly);
	}
	if (position.x <= 0 && position.y <= 130){
		path.Erase();
		path.Reset();
		path.PushBack({ 0.9f, -1.0f }, 5, &leftfly);
		path.PushBack({ 1.0f, -0.1f }, 5, &leftfly);
		path.PushBack({ 1.0f, 0.1f }, 5, &leftfly);
		path.PushBack({ 0.9f, 1.0f }, 5, &leftfly);
		path.PushBack({ 0.8f, 1.0f }, 5, &leftfly);
		path.PushBack({ 0.7f, 1.0f }, 5, &leftfly);
		path.PushBack({ 0.6f, 1.0f }, 5, &leftfly);
		path.PushBack({ 0.5f, 1.0f }, 5, &leftfly);
		path.PushBack({ 0.4f, 1.0f }, 5, &leftfly);
		path.PushBack({ 0.3f, 1.0f }, 5, &leftfly);
		path.PushBack({ 0.2f, 1.0f }, 5, &leftfly);
		path.PushBack({ 0.1f, 1.0f }, 5, &leftfly);
		path.PushBack({ 0, 1.0f }, 700, &leftfly);
	}
}

void Enemy_Can::Die()
{
	position.y -= 1;
	if (fly == 0){
		path.Erase();
		path.Reset();
		path.PushBack({ -0.1f, -1.0f }, 5, &rightfly);
		path.PushBack({ -0.2f, -1.0f }, 5, &rightfly);
		path.PushBack({ -0.3f, -1.0f }, 5, &rightfly);
		path.PushBack({ -0.4f, -1.0f }, 5, &rightfly);
		path.PushBack({ -0.5f, -1.0f }, 5, &rightfly);
		path.PushBack({ -0.6f, -1.0f }, 5, &rightfly);
		path.PushBack({ -0.7f, -1.0f }, 5, &rightfly);
		path.PushBack({ -0.8f, -1.0f }, 5, &rightfly);
		path.PushBack({ -0.9f, -1.0f }, 5, &rightfly);
		path.PushBack({ -1.0f, -0.1f }, 5, &rightfly);
		path.PushBack({ -1.0f, 0.1f }, 5, &rightfly);
		path.PushBack({ -0.9f, 1.0f }, 5, &rightfly);
		path.PushBack({ -0.8f, 1.0f }, 5, &rightfly);
		path.PushBack({ -0.7f, 1.0f }, 5, &rightfly);
		path.PushBack({ -0.6f, 1.0f }, 5, &rightfly);
		path.PushBack({ -0.5f, 1.0f }, 5, &rightfly);
		path.PushBack({ -0.4f, 1.0f }, 5, &rightfly);
		path.PushBack({ -0.3f, 1.0f }, 5, &rightfly);
		path.PushBack({ -0.2f, 1.0f }, 5, &rightfly);
		path.PushBack({ -0.1f, 1.0f }, 5, &rightfly);
		path.PushBack({ -0.1f, 1.0f }, 700, &leftfly);
		path.loop = true;
		fly = 1;
	}
	else if (fly == 1){
		path.Erase();
		path.Reset();
		path.PushBack({ 0.1f, -1.0f }, 5, &leftfly);
		path.PushBack({ 0.2f, -1.0f }, 5, &leftfly);
		path.PushBack({ 0.3f, -1.0f }, 5, &leftfly);
		path.PushBack({ 0.4f, -1.0f }, 5, &leftfly);
		path.PushBack({ 0.5f, -1.0f }, 5, &leftfly);
		path.PushBack({ 0.6f, -1.0f }, 5, &leftfly);
		path.PushBack({ 0.7f, -1.0f }, 5, &leftfly);
		path.PushBack({ 0.8f, -1.0f }, 5, &leftfly);
		path.PushBack({ 0.9f, -1.0f }, 5, &leftfly);
		path.PushBack({ 1.0f, -0.1f }, 5, &leftfly);
		path.PushBack({ 1.0f, 0.1f }, 5, &leftfly);
		path.PushBack({ 0.9f, 1.0f }, 5, &leftfly);
		path.PushBack({ 0.8f, 1.0f }, 5, &leftfly);
		path.PushBack({ 0.7f, 1.0f }, 5, &leftfly);
		path.PushBack({ 0.6f, 1.0f }, 5, &leftfly);
		path.PushBack({ 0.5f, 1.0f }, 5, &leftfly);
		path.PushBack({ 0.4f, 1.0f }, 5, &leftfly);
		path.PushBack({ 0.3f, 1.0f }, 5, &leftfly);
		path.PushBack({ 0.2f, 1.0f }, 5, &leftfly);
		path.PushBack({ 0.1f, 1.0f }, 5, &leftfly);
		path.PushBack({ 0.1f, 1.0f }, 700, &leftfly);
		path.loop = true;
		fly = 0;
	}
	if (hit == true)
		App->points->AddEnemy(ENEMY_TYPES::POINTS, position.x + 5, position.y, 1, NULL);


	hit = true;


}