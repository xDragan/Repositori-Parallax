#ifndef __ModuleEnemies_H__
#define __ModuleEnemies_H__

#include "Module.h"
#include "Enemy_Pig.h"

#define MAX_ENEMIES 100

enum ENEMY_TYPES
{
	NO_TYPE,
	PIG,
	GIRL,
	CAN,
	HORSE_RIGHT,
	BLUE_COWBOY,
	BLUE_COWBOY2,
	BLUE_COWBOY3,
	GREEN_COWBOY_BIG_LEFT,
	GREEN_COWBOY_BIG_RIGHT,
	GREEN_COWBOY_MEDIUM_LEFT,
	GREEN_COWBOY_MEDIUM_RIGHT,
	BAR_HOUSE,
	BARREL_ROLL,
	WHEELBARROW,
	POINTS
};

class Enemy;

struct EnemyInfo
{
	ENEMY_TYPES type = ENEMY_TYPES::NO_TYPE;
	int x, y;
	uint points;
};

class ModuleEnemies : public Module
{
public:

	ModuleEnemies();
	~ModuleEnemies();

	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();

	void check_explosion(fPoint location);

	bool Start();
	bool CleanUp();
	bool AddEnemy(ENEMY_TYPES type, int x, int y, uint points);

	void OnCollision(Collider* c1, Collider* c2);
private:

	void SpawnEnemy(const EnemyInfo& info);

private:
	EnemyInfo queue[MAX_ENEMIES];
	Enemy* enemies[MAX_ENEMIES];
	SDL_Texture* sprites;
};

#endif // __ModuleEnemies_H__