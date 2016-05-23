#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleEnemies.h"
#include "ModuleParticles.h"
#include "ModuleTextures.h"
#include "Enemy.h"
#include "Enemy_Pig.h"
#include "Enemy_Cowboy_Blue.h"
#include "Enemy_Cowboy_Blue2.h"
#include "Enemy_Cowboy_Blue3.h"
#include "Enemy_Cowboy_Green.h"
#include "Enemy_Barrel_Roll.h"
#include "ModuleUI.h"
#include "Module_Points.h"
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

		case ENEMY_TYPES::BLUE_COWBOY:
			enemies[i] = new Enemy_CowBoy_Blue(info.x, info.y);
			break;

		case ENEMY_TYPES::BLUE_COWBOY2:
			enemies[i] = new Enemy_CowBoy_Blue2(info.x, info.y);
			break;
		case ENEMY_TYPES::BLUE_COWBOY3:
			enemies[i] = new Enemy_CowBoy_Blue3(info.x, info.y);
			break;
		case ENEMY_TYPES::GREEN_COWBOY:
			enemies[i] = new Enemy_CowBoy_Green(info.x, info.y);
			break;
		case ENEMY_TYPES::BARREL_ROLL:
			enemies[i] = new Enemy_Barrel_Roll(info.x, info.y);
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
				enemies[i]->finished = true;
				App->UserUI->score += 100;
			}
		}
	}
}