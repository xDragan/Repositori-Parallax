#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleAudio.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"

#include "SDL/include/SDL_timer.h"

ModuleParticles::ModuleParticles()
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		active[i] = nullptr;

	//shot.anim.PushBack({ 625, 288, 22, 14 });
	enemyshot.anim.PushBack({ 471, 495, 3, 3});
	enemyshot.anim.PushBack({ 487, 494, 5, 5 });
	enemyshot.anim.PushBack({503, 493, 7, 7 });
	enemyshot.anim.PushBack({ 519, 494, 9, 9 });
	enemyshot.anim.PushBack({ 236, 294, 9, 9 });
	enemyshot.anim.PushBack({ 236, 294, 9, 9 });
	enemyshot.anim.loop = true;
	enemyshot.anim.speed = 0.05f;
	enemyshot.speed.y = 1.5f;
	enemyshot.life = 2000;
}

ModuleParticles::~ModuleParticles()
{}

// Load assets
bool ModuleParticles::Start()
{
	LOG("Loading particles");

	shot.fx = App->audio->LoadFx("bloodbros/shot.wav");

	graphics = App->textures->Load("bloodbros/Stuff.png");

	return true;
}

// Unload assets
bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");
	App->textures->Unload(graphics);

	// Unload fx

	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] != nullptr)
		{
			delete active[i];
			active[i] = nullptr;
		}
	}

	return true;
}

// Update: draw background
update_status ModuleParticles::Update()
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle* p = active[i];

		if (p == nullptr)
			continue;

		if (p->Update() == false)
		{
			delete p;
			active[i] = nullptr;
		}
		else if (SDL_GetTicks() >= p->born)
		{
			App->render->Blit(graphics, p->position.x, p->position.y, &(p->anim.GetCurrentFrame()));
			if (p->fx_played == false)
			{
				p->fx_played = true;
				App->audio->PlayFx(p->fx);
				
			}
		}
	}
	return UPDATE_CONTINUE;
}

void ModuleParticles::AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type, Uint32 delay)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] == nullptr)
		{
			Particle* p = new Particle(particle);
			p->position.x = x;
			p->position.y = y;
			if (collider_type != COLLIDER_NONE)
				p->collider = App->collision->AddCollider(p->anim.GetCurrentFrame(), collider_type, this);

			active[i] = p;
			break;
		}
	}
}

void ModuleParticles::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		// Always destroy particles that collide
		if (active[i] != nullptr && active[i]->collider == c1)
		{
			//AddParticle(explosion, active[i]->position.x, active[i]->position.y);
			delete active[i];
			active[i] = nullptr;
			break;
		}
	}
}

// -------------------------------------------------------------
// -------------------------------------------------------------

Particle::Particle()
{
	position.SetToZero();
	speed.SetToZero();
}

Particle::Particle(const Particle& p) :
anim(p.anim), position(p.position), speed(p.speed),
fx(p.fx), born(p.born), life(p.life)
{}

Particle::~Particle()
{
	if (collider != nullptr)
		App->collision->EraseCollider(collider);
}

bool Particle::Update()
{
	bool ret = true;

	if (anim.Finished())
		ret = false;

	position.x += speed.x;
	position.y += speed.y;

	if (collider != nullptr)
		collider->SetPos(position.x, position.y);

	return ret;
}

