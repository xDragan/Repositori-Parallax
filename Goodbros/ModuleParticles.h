#ifndef __MODULEPARTICLES_H__
#define __MODULEPARTICLES_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleCollision.h"

#define MAX_ACTIVE_PARTICLES 500

struct SDL_Texture;
struct Collider;
enum COLLIDER_TYPE;

struct Particle
{
	Collider* collider = nullptr;
	Animation anim;
	uint fx = 0;
	iPoint position;
	iPoint speed;
	Uint32 born = 0;
	Uint32 life = 0;
	bool fx_played = false;
	iPoint dst;

	Particle();
	Particle(const Particle& p);
	~Particle();
	bool Update();
};

class ModuleParticles : public Module
{
public:
	ModuleParticles();
	~ModuleParticles();

	update_status Update();
	bool Start();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

	void AddParticle(const Particle& particle, float x, float y, COLLIDER_TYPE collider_type, Uint32 delay);

private:
	SDL_Texture* graphics = nullptr;
	Particle* active[MAX_ACTIVE_PARTICLES];

public:
	int explosiontime = 0;
	Particle explotionshot;
	Particle enemyDynamite;
	Particle dynamite;
	Particle dynamite_exp;
	Particle edynamite_exp;
	Particle building_explosion;
	Particle shot;
	Particle shotgunshot;
	Particle machineshot;
	Particle Credit;
	Particle love;
	Particle points;
	Particle weapontake;
	Particle WC;
	Particle enemyshot;
	Particle smoke;
	Particle barrel;
	Particle BarrowExpl;
	Particle coin;
	Particle bombthrow;
	Particle bombexplosion;
	Particle collapse;
};

#endif // __MODULEPARTICLES_H__