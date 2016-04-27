#ifndef __ModuleEnemies_H__
#define __ModuleEnemies_H__

#include "Module.h"
#include "Enemy_Pig.h"

#define MAX_ENEMIES 100

enum ENEMY_TYPES
{
	NO_TYPE,
	PIG,
	BLUE_COWBOY,
	BAR_HOUSE,
};

class Enemy;

struct EnemyInfo
{
	ENEMY_TYPES type = ENEMY_TYPES::NO_TYPE;
	int x, y;
};

class ModuleEnemies : public Module
{
public:

	ModuleEnemies();
	~ModuleEnemies();

	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();

	bool Start();
	bool CleanUp();
	bool AddEnemy(ENEMY_TYPES type, int x, int y);

	void OnCollision(Collider* c1, Collider* c2);

	EnemyInfo pig;
	EnemyInfo BlueCowboy;

private:

	void SpawnEnemy(const EnemyInfo& info);

private:
	int time = 0;
	EnemyInfo queue[MAX_ENEMIES];
	Enemy* enemies[MAX_ENEMIES];
	SDL_Texture* sprites;
};

#endif // __ModuleEnemies_H__