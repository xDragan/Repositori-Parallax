#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleAudio.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "ModuleAim.h"

#include "SDL/include/SDL_timer.h"

ModuleParticles::ModuleParticles()
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		active[i] = nullptr;
	// Explotion shot
	explotionshot.anim.PushBack({ 330, 492, 16, 17 });
	explotionshot.anim.PushBack({ 349, 492, 16, 17 });
	explotionshot.anim.PushBack({ 365, 492, 16, 17 });
	explotionshot.anim.speed = 0.2f;
	// Enemy shot
	enemyshot.anim.PushBack({ 399, 494, 9, 9});
	enemyshot.anim.PushBack({ 429, 494, 9, 9 });
	enemyshot.anim.loop = true;
	enemyshot.anim.speed = 0.035f;
	enemyshot.speed.y = 1.5f;
	enemyshot.life = 10000;

	BarrowExpl.anim.PushBack({20,227,48,48});
	BarrowExpl.anim.PushBack({ 112, 227, 48, 48});
	BarrowExpl.anim.PushBack({ 174, 227, 48, 48 });
	BarrowExpl.anim.PushBack({ 244, 227, 48, 48 });
	BarrowExpl.anim.loop = true;
	BarrowExpl.anim.speed = 0.10;
	// Building explosion
	building_explosion.anim.PushBack({ 19, 239, 26, 26 });
	building_explosion.anim.PushBack({ 62, 236, 32, 32 });
	building_explosion.anim.PushBack({ 111, 227, 47, 47 });
	building_explosion.anim.PushBack({ 174, 228, 48, 48 });
	building_explosion.anim.PushBack({ 244, 230, 50, 50 });
	building_explosion.anim.PushBack({ 300, 230, 52, 52 });
	building_explosion.anim.loop = false;
	building_explosion.anim.speed = 0.25f;

	// Dynamite
	dynamite.anim.PushBack({ 505, 330, 17, 17 });
	dynamite.anim.PushBack({ 528, 330, 17, 17 });
	dynamite.anim.PushBack({ 540, 330, 17, 17 });
	dynamite.anim.PushBack({ 559, 330, 17, 17 });
	dynamite.anim.PushBack({ 578, 330, 17, 17 });
	dynamite.anim.PushBack({ 596, 330, 17, 17 });
	dynamite.anim.PushBack({ 611, 330, 17, 17 });
	dynamite.anim.PushBack({ 627, 330, 17, 17 });
	dynamite.anim.loop = false;
	dynamite.anim.speed = 0.1f;

	dynamite_exp.anim.PushBack({ 8, 370, 34, 65 });
	dynamite_exp.anim.PushBack({ 42, 370, 34, 65 });
	dynamite_exp.anim.PushBack({ 82, 370, 34, 64 });
	dynamite_exp.anim.PushBack({ 122, 370, 34, 65 });
	dynamite_exp.anim.PushBack({ 165, 370, 34, 64 });
	dynamite_exp.anim.PushBack({ 200, 370, 34, 65 });
	dynamite_exp.anim.PushBack({ 234, 370, 34, 65 });
	dynamite_exp.anim.PushBack({ 268, 370, 34, 65 });
	
	dynamite_exp.anim.loop = false;
	dynamite_exp.anim.speed = 0.2f;

	// Enemy dynamite
	enemyDynamite.anim.PushBack({ 778, 330, 17, 17 });
	enemyDynamite.anim.PushBack({ 761, 330, 17, 17 });
	enemyDynamite.anim.PushBack({ 744, 330, 17, 17 });
	enemyDynamite.anim.PushBack({ 727, 330, 17, 17 });
	enemyDynamite.anim.PushBack({ 710, 330, 17, 17 });
	enemyDynamite.anim.PushBack({ 693, 330, 17, 17 });
	enemyDynamite.anim.PushBack({ 676, 330, 17, 17 });
	enemyDynamite.anim.PushBack({ 659, 330, 17, 17 });
	enemyDynamite.anim.PushBack({ 642, 330, 17, 17 });
	enemyDynamite.anim.loop = false;
	enemyDynamite.anim.speed = 0.1f;

	// Smoke animation
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

	barrel.anim.PushBack({ 42, 452, 23, 41 });
	barrel.anim.PushBack({ 94, 449, 47, 45 });
	barrel.anim.PushBack({ 148, 444, 62, 59 });
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
			p->born = SDL_GetTicks() + delay;
			p->position.x = x;
			p->position.y = y;
			if (collider_type != COLLIDER_NONE)
				p->collider = App->collision->AddCollider(p->anim.GetCurrentFrame(), collider_type, this);
			
			if (collider_type == COLLIDER_ENEMY_SHOT)
			{
				p->speed = p->position.GetDirection(2, App->player->position);
			}
			if (collider_type == COLLIDER_BOMB)
			{
				p->speed = p->position.GetDirectionbomb(App->player->position);
			}
			if (collider_type == COLLIDER_BOMB_EXPLOSION)
			{
				p->speed = p->position.bombExplosion();
			}
			if (collider_type == COLLIDER_DYNAMITE)
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
	{
		ret = false;
		if (collider != nullptr && collider->type == COLLIDER_DYNAMITE)
		{
			App->particles->AddParticle(App->particles->dynamite_exp, position.x, position.y, COLLIDER_PLAYER_SHOT, 0);
		}
		if (collider != nullptr && collider->type == COLLIDER_BOMB)
		{
			App->particles->AddParticle(App->particles->dynamite_exp, position.x-10, position.y-45, COLLIDER_BOMB_EXPLOSION, 0);
		}
	}

	position.x += speed.x;
	position.y += speed.y;

	if (collider != nullptr)
	{
		collider->SetPos(position.x, position.y);
		if (collider->type == COLLIDER_DYNAMITE)
		{
			speed.y -= CONST_GRAVITY;
		}
		if (collider->type == COLLIDER_BOMB)
		{
			speed.y -= CONST_GRAVITY;
		}
	}

	return ret;
}

