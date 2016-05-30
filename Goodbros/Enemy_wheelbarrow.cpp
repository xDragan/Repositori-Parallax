#include "Application.h"
#include "Enemy_wheelbarrow.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"
Enemy_wheelbarrow::Enemy_wheelbarrow(float x, float y, int direction) : Enemy(x, y)
{

	/*switch (direction){
	case 1://from right to left*/
	wagon.PushBack({ 81, 3208, 30, 28 });
	wagon.PushBack({ 136, 3207, 30, 28 });
	wagon.PushBack({ 197, 3207, 30, 28 });
	wagon.PushBack({ 259, 3207, 30, 28 });
	wagon.speed = 0.1f;
	path.PushBack({ -1.0f, 0 }, 550, &wagon);
	/*case 2://viceversa
	wagon.PushBack({ 69, 3199, 48, 42 });
	wagon.PushBack({ 124, 3198, 48, 42 });
	wagon.PushBack({ 185, 3198, 48, 42 });
	wagon.PushBack({ 247, 3198, 48, 42 });
	wagon.speed = 0.1f;
	path.PushBack({ -1.0f, 0 }, 550, &wagon);
	*/
	Hitted.PushBack({ 81, 3268, 30, 28 });
	Hitted.speed = 0.1f;
	Hitted.loop = true;
	/*Hittedleft.speed = 0.1f;
	Hittedleft.loop = true;
	Hittedleft.PushBack({ 200, 3269, 48, 42 });*/

	collider = App->collision->AddCollider({ 0, 0, 48, 48 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;


	path.loop = true;
}

void Enemy_wheelbarrow::Move()
{
	position = original_pos + path.GetCurrentSpeed(&animation);
	if (hit == false){
		collider->type = COLLIDER_ENEMY;
	}
	if (hits == 3){
		App->particles->AddParticle(App->particles->BarrowExpl, position.x +4, position.y + 4, COLLIDER_NONE, 0);
		finished = true;
	}
	if (hit == true){
		collider->type = COLLIDER_NONE;
		animation = &Hitted;
		if (animation->Finished() == true){
			Hitted.Reset();
			Hitted.loops = 0;
			hit = false;
		}
	}
}

void Enemy_wheelbarrow::Die()
{
	App->points->AddEnemy(ENEMY_TYPES::POINTS, position.x, position.y, 3, NULL);
	App->points->AddEnemy(ENEMY_TYPES::POINTS, position.x + 20, position.y, 4, NULL);
	hit = true;
	hits++;
}