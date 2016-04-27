#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "p2Point.h"
#include "Animation.h"
#include "Path.h"
#include "ModuleParticles.h"

struct SDL_Texture;
struct Collider;

class Enemy
{
protected:
	Animation* animation;
	Collider* collider;

public:
	iPoint position;
	iPoint position2;
	Path path;
	Path path2;
	uint fx = 0;
	bool to_delete = false;
	bool fx_played = false;

public:
	Enemy(int x, int y);
	virtual ~Enemy();

	const Collider* GetCollider() const;

	bool finished = false;

	virtual void Move() {};
	virtual void Draw(SDL_Texture* sprites);
	virtual void Die();
};

#endif // __ENEMY_H__