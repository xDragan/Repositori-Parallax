#include "Application.h"
#include "Enemy_wheelbarrow.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"
Enemy_wheelbarrow::Enemy_wheelbarrow(float x, float y, int direction) : Enemy(x, y)
{

	switch (direction){
	case 1://from right to left
		wagon.PushBack({ 69, 3199, 48, 42 });
		wagon.PushBack({ 124, 3198, 48, 42 });
		wagon.PushBack({ 185, 3198, 48, 42 });
		wagon.PushBack({ 247, 3198, 48, 42 });
		wagon.speed = 0.1f;
		//path.PushBack({ 1.0f, 0 }, 270, &wagon);
		path.PushBack({ -1.0f, 0 }, 550, &wagon);
		break;
	case 2://viceversa
		wagon.PushBack({ 69, 3199, 48, 42 });
		wagon.PushBack({ 124, 3198, 48, 42 });
		wagon.PushBack({ 185, 3198, 48, 42 });
		wagon.PushBack({ 247, 3198, 48, 42 });
		wagon.speed = 0.1f;
		//path.PushBack({ -1.0f, 0 }, 550, &wagon);
		path.PushBack({ 1.0f, 0 }, 270, &wagon);
		break;
	}

	collider = App->collision->AddCollider({ 0, 0, 48, 48 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;


	path.loop = true;
}

void Enemy_wheelbarrow::Move()
{
	position = original_pos + path.GetCurrentSpeed(&animation);

}

void Enemy_wheelbarrow::Die()
{
	App->points->AddEnemy(ENEMY_TYPES::POINTS, position.x, position.y, 3);
	App->points->AddEnemy(ENEMY_TYPES::POINTS, position.x + 20, position.y, 4);
}