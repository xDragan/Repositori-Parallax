#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleEnemies.h"
#include "ModuleParticles.h"
#include "ModuleTextures.h"
#include "Enemy.h"
#include "Enemy_Pig.h"
#include "Enemy_Girl.h"
#include "Enemy_Cowboy_Blue.h"
#include "Enemy_Can.h"
#include "Enemy_Cowboy_Blue2.h"
#include "Enemy_Cowboy_Blue3.h"
#include "Enemy_Cowboy_Green_Big_Left.h"
#include "Enemy_Cowboy_Green_Big_Right.h"
#include "Enemy_Cowboy_Green_Medium_Left.h"
#include "Enemy_CowBoy_Green_Medium_Right.h"
#include "Enemy_CowBoy_Green_Right_Tumble.h"
#include "Enemy_Barrel_Roll.h"
#include "Enemy_Horse_Right.h"
#include "Enemy_Horse_Small_Right.h"
#include "Enemy_Rider_Medium.h"
#include "Enemy_Rider_Small_Right.h"
#include "Enemy_Couple_Guy.h"
#include "ModuleStructures.h"
#include "ModuleUI.h"
#include "Module_Points.h"
#include "Enemy_wheelbarrow.h"
#include "SDL/include/SDL_timer.h"

#define SPAWN_MARGIN 40

ModuleEnemies::ModuleEnemies()
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
		enemies[i] = nullptr;
}

// Destructor
ModuleEnemies::~ModuleEnemies()
{
}

bool ModuleEnemies::Start()
{
	// Create a prototype for each enemy available so we can copy them around
	sprites = App->textures->Load("bloodbros/enemy.png");

	return true;
}

update_status ModuleEnemies::PreUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (queue[i].type != ENEMY_TYPES::NO_TYPE)
		{
			if (queue[i].x * SCREEN_SIZE < App->render->camera.x + (App->render->camera.w * SCREEN_SIZE) + SPAWN_MARGIN)
			{
				SpawnEnemy(queue[i]);
				queue[i].type = ENEMY_TYPES::NO_TYPE;
				LOG("Spawning enemy at %d", queue[i].x * SCREEN_SIZE);
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before render is available
update_status ModuleEnemies::Update()
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	if (enemies[i] != nullptr) enemies[i]->Move();

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	if (enemies[i] != nullptr) enemies[i]->Draw(sprites);

	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		if (enemies[i] != nullptr && enemies[i]->finished == true)
		{
			delete enemies[i];
			enemies[i] = nullptr;
		}
	}

	return UPDATE_CONTINUE;
}

update_status ModuleEnemies::PostUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			if (enemies[i]->position.x * SCREEN_SIZE < (App->render->camera.x) - SPAWN_MARGIN)
			{
				LOG("DeSpawning enemy at %d", enemies[i]->position.x * SCREEN_SIZE);
				delete enemies[i];
				enemies[i] = nullptr;
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleEnemies::CleanUp()
{
	LOG("Freeing all enemies");

	App->textures->Unload(sprites);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			delete enemies[i];
			enemies[i] = nullptr;
		}
	}

	return true;
}

bool ModuleEnemies::AddEnemy(ENEMY_TYPES type, int x, int y, uint points)
{
	bool ret = false;

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (queue[i].type == ENEMY_TYPES::NO_TYPE)
		{
			queue[i].points = points;
			queue[i].type = type;
			queue[i].x = x;
			queue[i].y = y;
			ret = true;
			break;
		}
	}

	return ret;
}

void ModuleEnemies::SpawnEnemy(const EnemyInfo& info)
{
	// find room for the new enemy
	uint i = 0;
	for (; enemies[i] != nullptr && i < MAX_ENEMIES; ++i);

	if (i != MAX_ENEMIES)
	{
		switch (info.type)
		{
		case ENEMY_TYPES::PIG:
			enemies[i] = new Enemy_Pig(info.x, info.y);
			break;
		case ENEMY_TYPES::GIRL:
			enemies[i] = new Enemy_Girl(info.x, info.y);
			break;
		case ENEMY_TYPES::CAN:
			enemies[i] = new Enemy_Can(info.x, info.y);
			break;
		case ENEMY_TYPES::HORSE_RIGHT:
			enemies[i] = new Enemy_Horse_Right(info.x, info.y);
			break;
		case ENEMY_TYPES::HORSE_SMALL_RIGHT:
			enemies[i] = new Enemy_Horse_Small_Right(info.x, info.y);
			break;
		case ENEMY_TYPES::RIDER:
			enemies[i] = new Enemy_Rider_Medium(info.x, info.y);
			break;
		case ENEMY_TYPES::RIDER_SMALL_RIGHT:
			enemies[i] = new Enemy_Rider_Small_Right(info.x, info.y);
			break;
		case ENEMY_TYPES::COUPLE_GUY:
			enemies[i] = new Enemy_Couple_Guy(info.x, info.y);
			break;
		case ENEMY_TYPES::BLUE_COWBOY:
			enemies[i] = new Enemy_CowBoy_Blue(info.x, info.y);
			break;
		case ENEMY_TYPES::BLUE_COWBOY2:
			enemies[i] = new Enemy_CowBoy_Blue2(info.x, info.y);
			break;
		case ENEMY_TYPES::BLUE_COWBOY3:
			enemies[i] = new Enemy_CowBoy_Blue3(info.x, info.y);
			break;
		case ENEMY_TYPES::GREEN_COWBOY_BIG_LEFT:
			enemies[i] = new Enemy_CowBoy_Green_Big_Left(info.x, info.y);
			break;
		case ENEMY_TYPES::GREEN_COWBOY_BIG_RIGHT:
			enemies[i] = new Enemy_CowBoy_Green_Big_Right(info.x, info.y);
			break;
		case ENEMY_TYPES::GREEN_COWBOY_MEDIUM_LEFT:
			enemies[i] = new Enemy_CowBoy_Green_Medium_Left(info.x, info.y);
			break;
		case ENEMY_TYPES::GREEN_COWBOY_MEDIUM_RIGHT:
			enemies[i] = new Enemy_CowBoy_Green_Medium_Right(info.x, info.y);
			break;
		case ENEMY_TYPES::GREEN_COWBOY_RIGHT_TUMBLE:
			enemies[i] = new Enemy_CowBoy_Green_Right_Tumble(info.x, info.y);
			break;
		case ENEMY_TYPES::BARREL_ROLL:
			enemies[i] = new Enemy_Barrel_Roll(info.x, info.y);
			break;
		case ENEMY_TYPES::WHEELBARROW:
			enemies[i] = new Enemy_wheelbarrow(info.x, info.y,info.points);
			break;
		case ENEMY_TYPES::POINTS:
			enemies[i] = new Module_Points(info.x, info.y, info.points);
			break;
		}
	}
}

void ModuleEnemies::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr && enemies[i]->GetCollider() == c1)
		{
			App->UserUI->score += 100;
			enemies[i]->Die();
		}
		if (App->points->enemies[i] != nullptr && App->points->enemies[i]->GetCollider() == c1){
			App->UserUI->score += 100;
			App->points->enemies[i]->Die();
		}
	}
}

// PLACEHOLDER still not working with buildings
void ModuleEnemies::check_explosion(iPoint location)
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			if ((enemies[i]->position.x >(location.x - 100) && enemies[i]->position.x < (location.x + 60)) &&
				(enemies[i]->position.y - 30 >(location.y - 100) && enemies[i]->position.y - 30 < (location.y + 60)))
			{
				enemies[i]->Die();
				App->UserUI->score += 100;
			}
		}
	}
}
