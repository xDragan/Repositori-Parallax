#include "Application.h"
#include "Enemy_Pig.h"
#include "Module_Points.h"
#include "Enemy.h"
#include "ModuleEnemies.h"
#include "ModuleCollision.h"
#include "ModuleAudio.h"

Enemy_Pig::Enemy_Pig(float x, float y) : Enemy(x, y)
{
	run.PushBack({ 81, 127, 32, 24 });
	run.PushBack({ 127, 127, 32, 24 });
	run.speed = 0.07f;

	animation = &run;

	collider = App->collision->AddCollider({0, 0, 32, 24}, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
}

void Enemy_Pig::Move()
{
	position.y = original_y;
	if (hit == false){ position.x -= 1; }
	if (hit == true)
	{ 
		App->audio->PlayFx(App->particles->pig_hit.fx, 1000);
		position.x -= 3;
	}
}

void Enemy_Pig::Die()
{
	App->points->AddEnemy(ENEMY_TYPES::POINTS, position.x + 20, position.y, 2, NULL);
	hit = true;
}