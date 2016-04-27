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
	Path path;
	uint fx = 0;
	bool to_delete = false;
	bool fx_played = false;

public:
	Enemy(int x, int y);
	virtual ~Enemy();

	const Collider* GetCollider() const;

	virtual void Move() {};
	virtual void Draw(SDL_Texture* sprites);
	virtual void Die();
	bool finished = false;
	
};

#endif // __ENEMY_H__