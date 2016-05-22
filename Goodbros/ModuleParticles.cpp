#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleAudio.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleAim.h"

#include "SDL/include/SDL_timer.h"

ModuleParticles::ModuleParticles()
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		active[i] = nullptr;

	//shot.anim.PushBack({ 625, 288, 22, 14 });
	enemyshot.anim.PushBack({ 399, 494, 9, 9});
	enemyshot.anim.PushBack({ 429, 494, 9, 9 });
	
	enemyshot.anim.loop = true;
	enemyshot.anim.speed = 0.035f;
	enemyshot.speed.y = 1.5f;
	enemyshot.life = 10000;

	dynamite.anim.PushBack({ 505, 330, 17, 17 });
	dynamite.anim.PushBack({ 505, 330, 17, 17 });
	dynamite.anim.PushBack({ 505, 330, 17, 17 });
	dynamite.anim.PushBack({ 505, 330, 17, 17 });
	dynamite.anim.PushBack({ 505, 330, 17, 17 });
	dynamite.anim.PushBack({ 505, 330, 17, 17 });
	dynamite.anim.PushBack({ 505, 330, 17, 17 });
	dynamite.anim.PushBack({ 505, 330, 17, 17 });
	dynamite.anim.speed = 0.2f;

	//smoke.anim.pushback;
	smoke.anim.PushBack({ 27, 45, 127, 30 });
	smoke.anim.PushBack({ 27, 77, 127, 30 });
	smoke.anim.PushBack({ 27, 112, 127, 30 });
	smoke.anim.PushBack({ 27, 153, 127, 30 });
	smoke.anim.PushBack({ 27, 45, 127, 30 });
	smoke.anim.PushBack({ 27, 77, 127, 30 });
	smoke.anim.PushBack({ 27, 112, 127, 30 });
	smoke.anim.PushBack({ 27, 153, 127, 30 });
	smoke.anim.PushBack({ 27, 45, 127, 30 });
	smoke.anim.PushBack({ 27, 77, 127, 30 });
	smoke.anim.PushBack({ 27, 112, 127, 30 });
	smoke.anim.PushBack({ 27, 153, 127, 30 });
	smoke.anim.PushBack({ 27, 45, 127, 30 });
	smoke.anim.PushBack({ 27, 77, 127, 30 });
	smoke.anim.PushBack({ 27, 112, 127, 30 });
	smoke.anim.PushBack({ 27, 153, 127, 30 });
	smoke.anim.PushBack({ 27, 45, 127, 30 });
	smoke.anim.PushBack({ 27, 77, 127, 30 });
	smoke.anim.PushBack({ 27, 112, 127, 30 });
	smoke.anim.PushBack({ 27, 153, 127, 30 });
	smoke.anim.PushBack({ 27, 45, 127, 30 });
	smoke.anim.PushBack({ 27, 77, 127, 30 });
	smoke.anim.PushBack({ 27, 112, 127, 30 });
	smoke.anim.PushBack({ 27, 153, 127, 30 });
	smoke.anim.PushBack({ 27, 45, 127, 30 });
	smoke.anim.PushBack({ 27, 77, 127, 30 });
	smoke.anim.PushBack({ 27, 112, 127, 30 });
	smoke.anim.PushBack({ 27, 153, 127, 30 });
	smoke.anim.PushBack({ 27, 45, 127, 30 });
	smoke.anim.PushBack({ 27, 77, 127, 30 });
	smoke.anim.PushBack({ 27, 112, 127, 30 });
	smoke.anim.PushBack({ 27, 153, 127, 30 });
	smoke.anim.PushBack({ 27, 45, 127, 30 });
	smoke.anim.PushBack({ 27, 77, 127, 30 });
	smoke.anim.PushBack({ 27, 112, 127, 30 });
	smoke.anim.PushBack({ 27, 153, 127, 30 });
	smoke.anim.PushBack({ 27, 45, 127, 30 });
	smoke.anim.PushBack({ 27, 77, 127, 30 });

	smoke.anim.loop = true;
	smoke.anim.speed = 0.14f;
	smoke.life = 12000;

	barrel.anim.PushBack({ 25, 443, 23, 41 });
	barrel.anim.PushBack({ 60, 442, 47, 45 });
	barrel.anim.PushBack({ 112, 444, 62, 59 });
	barrel.anim.speed = 0.26f;
	barrel.life = 250;
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

void ModuleParticles::AddParticle(const Particle& particle, float x, float y, COLLIDER_TYPE collider_type, Uint32 delay)
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
			
			if (collider_type == COLLIDER_ENEMY_SHOT)
			{
				p->speed = p->position.GetDirection(2, App->player->position);
			}
			else if (collider_type == COLLIDER_DYNAMITE)
			{
				p->speed = App->player->position.GetSpeed(App->aim->position);
			}
			active[i] = p;
			break;
		}
	}
}

void ModuleParticles::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] != nullptr && active[i]->collider == c1)
		{
			delete active[i];
			active[i] = nullptr;
			break;
		}
	}
	if (c1 == App->player->player_coll || c2 == App->player->player_coll)
	{
		App->player->die.loops = 0;
		App->player->die.Reset();
		App->player->Status = DIE;
	}

}

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
	{
		collider->SetPos(position.x, position.y);
		if (collider->type == COLLIDER_DYNAMITE)
			speed.y -= CONST_GRAVITY;
	}

	return ret;
}

