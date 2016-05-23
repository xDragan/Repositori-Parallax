#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "Animation.h"
#include "ModuleFadeToBlack.h"
#include "ModuleScenefirst.h"
#include "ModuleAudio.h"
#include "ModuleStructures.h"
#include "Module_Points.h"
#include "ModuleEnemies.h"
#include "SDL/include/SDL_timer.h"

Structure::Structure()
{
	position.SetToZero();
}

Structure::Structure(const Structure& p):
Coll_Struct(p.Coll_Struct), position(p.position),
fx(p.fx), mytype(p.mytype), destroy(p.destroy)
{}

Structure::~Structure(){
	if (collider != nullptr)
	{
		App->collision->EraseCollider(collider);
	}
}

bool Structure::Update()
{
	bool ret = true;

	return ret;
}

ModuleStructures::ModuleStructures()
{
	for (uint i = 0; i < MAX_BUILDINGS; ++i)
		active[i] = nullptr;
}

ModuleStructures::~ModuleStructures()
{
	if (bar.collider != nullptr)
	{
		App->collision->EraseCollider(bar.collider);
	}
	if (inn.collider != nullptr)
	{
		App->collision->EraseCollider(inn.collider);
	}
	if (barrel.collider != nullptr)
	{
		App->collision->EraseCollider(barrel.collider);
	}
}

// Load assets
bool ModuleStructures::Start()
{
	LOG("Loading particles");
	graphics = App->textures->Load("bloodbros/enemy.png");

	///BAR
	bar.Coll_Struct.x = 80;
	bar.Coll_Struct.y = 2266;
	bar.Coll_Struct.w = 115;
	bar.Coll_Struct.h = 147;
	bar.mytype = BAR;

	bar2.Coll_Struct.x = 218;
	bar2.Coll_Struct.y = 2266;
	bar2.Coll_Struct.w = 115;
	bar2.Coll_Struct.h = 147;

	bar3.Coll_Struct.x = 345;
	bar3.Coll_Struct.y = 2266;
	bar3.Coll_Struct.w = 115;
	bar3.Coll_Struct.h = 147;

	bar4.Coll_Struct.x = 490;
	bar4.Coll_Struct.y = 2266;
	bar4.Coll_Struct.w = 115;
	bar4.Coll_Struct.h = 147;

	bar5.Coll_Struct.x = 638;
	bar5.Coll_Struct.y = 2266;
	bar5.Coll_Struct.w = 115;
	bar5.Coll_Struct.h = 147;

	bar.destroy.PushBack({ 638, 2266, 115, 147 });
	bar.destroy.PushBack({ 638, 2266, 115, 132 });
	bar.destroy.PushBack({ 638, 2266, 115, 121 });
	bar.destroy.PushBack({ 638, 2266, 115, 110 });
	bar.destroy.PushBack({ 638, 2266, 115, 99 });
	bar.destroy.PushBack({ 638, 2266, 115, 87 });
	bar.destroy.PushBack({ 638, 2266, 115, 74 });
	bar.destroy.PushBack({ 638, 2266, 115, 60 });
	bar.destroy.PushBack({ 638, 2266, 115, 49 });
	bar.destroy.PushBack({ 638, 2266, 115, 32 });
	bar.destroy.PushBack({ 638, 2266, 115, 20 });
	bar.destroy.PushBack({ 638, 2266, 115, 12 });
	bar.destroy.PushBack({ 638, 2266, 115, 4 });
	bar.destroy.loop = false;
	bar.destroy.speed = 0.05f;

	///GREY BUILDING
	inn.Coll_Struct.x = 91;
	inn.Coll_Struct.y = 2150;
	inn.Coll_Struct.w = 105;
	inn.Coll_Struct.h = 92;
	inn.mytype = INN;

	inn2.Coll_Struct.x = 91;
	inn2.Coll_Struct.y = 2150;
	inn2.Coll_Struct.w = 105;
	inn2.Coll_Struct.h = 92;

	inn3.Coll_Struct.x = 91;
	inn3.Coll_Struct.y = 2150;
	inn3.Coll_Struct.w = 105;
	inn3.Coll_Struct.h = 92;

	inn4.Coll_Struct.x = 91;
	inn4.Coll_Struct.y = 2150;
	inn4.Coll_Struct.w = 105;
	inn4.Coll_Struct.h = 92;

	// HOTEL
	hotel.Coll_Struct.x = 203;
	hotel.Coll_Struct.y = 2151;
	hotel.Coll_Struct.w = 72;
	hotel.Coll_Struct.h = 90;
	hotel.mytype = HOTEL;

	hotel2.Coll_Struct.x = 203;
	hotel2.Coll_Struct.y = 2151;
	hotel2.Coll_Struct.w = 72;
	hotel2.Coll_Struct.h = 90;

	hotel3.Coll_Struct.x = 203;
	hotel3.Coll_Struct.y = 2151;
	hotel3.Coll_Struct.w = 72;
	hotel3.Coll_Struct.h = 90;

	hotel4.Coll_Struct.x = 203;
	hotel4.Coll_Struct.y = 2151;
	hotel4.Coll_Struct.w = 72;
	hotel4.Coll_Struct.h = 90;

	hotel4.Coll_Struct.x = 203;
	hotel4.Coll_Struct.y = 2151;
	hotel4.Coll_Struct.w = 72;
	hotel4.Coll_Struct.h = 90;

	// FABTEN
	fabten.Coll_Struct.x = 76;
	fabten.Coll_Struct.y = 2548;
	fabten.Coll_Struct.w = 105;
	fabten.Coll_Struct.h = 138;
	fabten.mytype = FABTEN;

	fabten2.Coll_Struct.x = 197;
	fabten2.Coll_Struct.y = 2548;
	fabten2.Coll_Struct.w = 105;
	fabten2.Coll_Struct.h = 138;

	fabten3.Coll_Struct.x = 331;
	fabten3.Coll_Struct.y = 2548;
	fabten3.Coll_Struct.w = 105;
	fabten3.Coll_Struct.h = 138;

	fabten4.Coll_Struct.x = 468;
	fabten4.Coll_Struct.y = 2548;
	fabten4.Coll_Struct.w = 105;
	fabten4.Coll_Struct.h = 138;

	fabten5.Coll_Struct.x = 585;
	fabten5.Coll_Struct.y = 2548;
	fabten5.Coll_Struct.w = 105;
	fabten5.Coll_Struct.h = 138;

	fabten.destroy.PushBack({ 585, 2548, 105, 138 });
	fabten.destroy.PushBack({ 585, 2548, 105, 128 });
	fabten.destroy.PushBack({ 585, 2548, 105, 118 });
	fabten.destroy.PushBack({ 585, 2548, 105, 108 });
	fabten.destroy.PushBack({ 585, 2548, 105, 98 });
	fabten.destroy.PushBack({ 585, 2548, 105, 88 });
	fabten.destroy.PushBack({ 585, 2548, 105, 78 });
	fabten.destroy.PushBack({ 585, 2548, 105, 68 });
	fabten.destroy.PushBack({ 585, 2548, 105, 58 });
	fabten.destroy.PushBack({ 585, 2548, 105, 48 });
	fabten.destroy.PushBack({ 585, 2548, 105, 38 });
	fabten.destroy.PushBack({ 585, 2548, 105, 28 });
	fabten.destroy.PushBack({ 585, 2548, 105, 18 });
	fabten.destroy.loop = false;
	fabten.destroy.speed = 0.05f;

	// BARREL
	barrel.Coll_Struct.x = 69;
	barrel.Coll_Struct.y = 2710;
	barrel.Coll_Struct.w = 31;
	barrel.Coll_Struct.h = 49;
	barrel.mytype = BARREL;

	barrel2.Coll_Struct.x = 105;
	barrel2.Coll_Struct.y = 2710;
	barrel2.Coll_Struct.w = 31;
	barrel2.Coll_Struct.h = 49;
	barrel2.mytype = BARREL;

	barrel3.Coll_Struct.x = 139;
	barrel3.Coll_Struct.y = 2710;
	barrel3.Coll_Struct.w = 31;
	barrel3.Coll_Struct.h = 49;
	barrel3.mytype = BARREL;

	return true;
}

// Unload assets
bool ModuleStructures::CleanUp()
{
	LOG("Unloading particles");
	App->textures->Unload(graphics);

	for (uint i = 0; i < MAX_BUILDINGS; ++i)
	{
		if (active[i] != nullptr)
		{
			active[i] = nullptr;
		}
	}
	return true;
}

// Update: draw background
update_status ModuleStructures::Update()
{
	for (uint i = 0; i < MAX_BUILDINGS; ++i)
	{
		Structure* p = active[i];


		// STRUCTURES
		if (p == nullptr)
			continue;

		if (p->Update() == false)
		{
			p->collider->to_delete = true;
			delete p;
			active[i] = nullptr;
		}

		if (p->hits <= 3 || p->INN_hits <= 3 || p->FABTEN_hits <= 3 || p->HOTEL_hits <= 30)
		{
			App->render->Blit(graphics, p->position.x, p->position.y, &p->Coll_Struct, 0);
			if (p->fx_played == false)
			{
				// Play particle fx here
				p->fx_played = true;
			}
		}

		if (p->hits > 3 || p->INN_hits > 3 || p->BARREL_hits > 2 || p->FABTEN_hits > 3 || p->HOTEL_hits > 30 )
		{
			App->collision->EraseCollider(p->collider);
			if (p->position.y >= 140)
			{
				App->structures->fabten.destroy.GetCurrentFrame();
			}
			else
			{
				App->render->Blit(graphics, p->position.x, p->position.y += 0.53f, &p->destroy.GetCurrentFrame());
			}
			if (p->destroy.Finished() == true)
			{
				delete active[i];
				active[i] = nullptr;
				App->player->win_condition++;
			}
		}
		if (p->BARREL_hits == 1)
		{
			App->render->Blit(graphics, p->position.x, p->position.y, &p->Coll_Struct, 0);
			p->collider->SetPos(p->position.x, p->position.y + 8);
			if (p->fx_played == false)
			{
				p->fx_played = true;
			}
		}
		if (p->BARREL_hits == 2)
		{
			App->render->Blit(graphics, p->position.x, p->position.y, &p->Coll_Struct, 0);
			p->collider->SetPos(p->position.x, p->position.y + 23);
			if (p->fx_played == false)
			{
				p->fx_played = true;
			}
		}
	}
	return UPDATE_CONTINUE;
}

void ModuleStructures::AddStructure(Structure& particle, int x, int y)
{
	Structure* p = new Structure(particle);
	p->position.x = x;
	p->position.y = y;
	if (particle.mytype==BARREL){
		p->collider = App->collision->AddCollider({ p->position.x, p->position.y, particle.Coll_Struct.w, particle.Coll_Struct.h }, COLLIDER_DESTRUCT, this);
	}
	else{
		p->collider = App->collision->AddCollider({ p->position.x, p->position.y, particle.Coll_Struct.w, particle.Coll_Struct.h }, COLLIDER_STRUCTURE, this);
	}
	active[last_building++] = p;
}

const Collider* Structure::get_collider() const
{
	return collider;
}


void ModuleStructures::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_BUILDINGS; ++i)
	{
		if (active[i] != nullptr && active[i]->get_collider() == c1 && active[i]->mytype == BAR)
		{
			if (active[i]->hits == 0)
			{
				active[i]->Coll_Struct.x = bar2.Coll_Struct.x;
				active[i]->Coll_Struct.y = bar2.Coll_Struct.y;
				active[i]->Coll_Struct.w = bar2.Coll_Struct.w;
				active[i]->Coll_Struct.h = bar2.Coll_Struct.h;
				active[i]->hits++;
				break;
			}
			else if (active[i]->hits == 1)
			{
				active[i]->Coll_Struct.x = bar3.Coll_Struct.x;
				active[i]->Coll_Struct.y = bar3.Coll_Struct.y;
				active[i]->Coll_Struct.w = bar3.Coll_Struct.w;
				active[i]->Coll_Struct.h = bar3.Coll_Struct.h;
				active[i]->hits++;
				break;
			}
			else if (active[i]->hits == 2)
			{
				active[i]->Coll_Struct.x = bar4.Coll_Struct.x;
				active[i]->Coll_Struct.y = bar4.Coll_Struct.y;
				active[i]->Coll_Struct.w = bar4.Coll_Struct.w;
				active[i]->Coll_Struct.h = bar4.Coll_Struct.h;
				active[i]->hits++;
				break;
			}
			else if (active[i]->hits == 3)
			{
				App->enemies->AddEnemy(ENEMY_TYPES::POINTS, active[i]->position.x + 45, active[i]->position.y + 28, 10000);
				active[i]->Coll_Struct.x = 0;
				active[i]->Coll_Struct.y = 0;
				active[i]->Coll_Struct.w = 0;
				active[i]->Coll_Struct.h = 0;
				active[i]->hits++;
				App->particles->AddParticle(App->particles->smoke, active[i]->position.x - 10, active[i]->position.y + 125, COLLIDER_NONE, 0);
			}
		}
			// INN
		if (active[i] != nullptr && active[i]->get_collider() == c1 && active[i]->mytype == INN)
		{
			if (active[i]->INN_hits == 0)
			{
				active[i]->Coll_Struct.x = inn2.Coll_Struct.x;
				active[i]->Coll_Struct.y = inn2.Coll_Struct.y;
				active[i]->Coll_Struct.w = inn2.Coll_Struct.w;
				active[i]->Coll_Struct.h = inn2.Coll_Struct.h;
				active[i]->INN_hits++;
				break;
			}
			else if (active[i]->INN_hits == 1)
			{
				active[i]->Coll_Struct.x = inn3.Coll_Struct.x;
				active[i]->Coll_Struct.y = inn3.Coll_Struct.y;
				active[i]->Coll_Struct.w = inn3.Coll_Struct.w;
				active[i]->Coll_Struct.h = inn3.Coll_Struct.h;
				active[i]->INN_hits++;;
				break;
			}
			else if (active[i]->INN_hits == 2)
			{
				active[i]->Coll_Struct.x = inn4.Coll_Struct.x;
				active[i]->Coll_Struct.y = inn4.Coll_Struct.y;
				active[i]->Coll_Struct.w = inn4.Coll_Struct.w;
				active[i]->Coll_Struct.h = inn4.Coll_Struct.h;
				active[i]->INN_hits++;
				break;
			}
			else if (active[i]->INN_hits == 3)
			{
				App->enemies->AddEnemy(ENEMY_TYPES::POINTS, active[i]->position.x + 30, active[i]->position.y, 7000);
				active[i]->Coll_Struct.x = 0;
				active[i]->Coll_Struct.y = 0;
				active[i]->Coll_Struct.w = 0;
				active[i]->Coll_Struct.h = 0;
				active[i]->INN_hits++;
			}
		}

		// FABTEN
		if (active[i] != nullptr && active[i]->get_collider() == c1 && active[i]->mytype == FABTEN)
		{
			if (active[i]->FABTEN_hits == 0)
			{
				active[i]->Coll_Struct.x = fabten2.Coll_Struct.x;
				active[i]->Coll_Struct.y = fabten2.Coll_Struct.y;
				active[i]->Coll_Struct.w = fabten2.Coll_Struct.w;
				active[i]->Coll_Struct.h = fabten2.Coll_Struct.h;
				active[i]->FABTEN_hits++;
				break;
			}
			else if (active[i]->FABTEN_hits == 1)
			{
				active[i]->Coll_Struct.x = fabten3.Coll_Struct.x;
				active[i]->Coll_Struct.y = fabten3.Coll_Struct.y;
				active[i]->Coll_Struct.w = fabten3.Coll_Struct.w;
				active[i]->Coll_Struct.h = fabten3.Coll_Struct.h;
				active[i]->FABTEN_hits++;
				break;
			}
			else if (active[i]->FABTEN_hits == 2)
			{
				active[i]->Coll_Struct.x = fabten4.Coll_Struct.x;
				active[i]->Coll_Struct.y = fabten4.Coll_Struct.y;
				active[i]->Coll_Struct.w = fabten4.Coll_Struct.w;
				active[i]->Coll_Struct.h = fabten4.Coll_Struct.h;
				active[i]->FABTEN_hits++;
				break;
			}
			else if (active[i]->FABTEN_hits == 3)
			{
				App->enemies->AddEnemy(ENEMY_TYPES::POINTS, active[i]->position.x + 25, active[i]->position.y + 20, 10000);
				active[i]->Coll_Struct.x = 0;
				active[i]->Coll_Struct.y = 0;
				active[i]->Coll_Struct.w = 0;
				active[i]->Coll_Struct.h = 0;
				active[i]->FABTEN_hits++;
				App->particles->AddParticle(App->particles->smoke, active[i]->position.x - 10, active[i]->position.y + 125, COLLIDER_NONE, 0);
			}
		}

		// HOTEL
		if (active[i] != nullptr && active[i]->get_collider() == c1 && active[i]->mytype == HOTEL)
		{
			if (active[i]->HOTEL_hits >= 0)
			{
				active[i]->Coll_Struct.x = hotel2.Coll_Struct.x;
				active[i]->Coll_Struct.y = hotel2.Coll_Struct.y;
				active[i]->Coll_Struct.w = hotel2.Coll_Struct.w;
				active[i]->Coll_Struct.h = hotel2.Coll_Struct.h;
				active[i]->HOTEL_hits++;
				break;
			}
		
			else if (active[i]->HOTEL_hits >= 10)
			{
				App->enemies->AddEnemy(ENEMY_TYPES::POINTS, active[i]->position.x + 30, active[i]->position.y, 5000);
				active[i]->Coll_Struct.x = 0;
				active[i]->Coll_Struct.y = 0;
				active[i]->Coll_Struct.w = 0;
				active[i]->Coll_Struct.h = 0;
				active[i]->HOTEL_hits++;
			}
		}

		// BARREL
		if (active[i] != nullptr && active[i]->get_collider() == c1 && active[i]->mytype == BARREL)
		{
			if (active[i]->BARREL_hits == 0)
			{
				active[i]->Coll_Struct.x = barrel2.Coll_Struct.x;
				active[i]->Coll_Struct.y = barrel2.Coll_Struct.y;
				active[i]->Coll_Struct.w = barrel2.Coll_Struct.w;
				active[i]->Coll_Struct.h = barrel2.Coll_Struct.h;
				active[i]->BARREL_hits++;
				App->particles->AddParticle(App->particles->barrel, active[i]->position.x -12, active[i]->position.y -20 , COLLIDER_NONE, 0);
				break;
			}
			else if (active[i]->BARREL_hits == 1)
			{
				active[i]->Coll_Struct.x = barrel3.Coll_Struct.x;
				active[i]->Coll_Struct.y = barrel3.Coll_Struct.y;
				active[i]->Coll_Struct.w = barrel3.Coll_Struct.w;
				active[i]->Coll_Struct.h = barrel3.Coll_Struct.h;
				active[i]->BARREL_hits++;
				App->particles->AddParticle(App->particles->barrel, active[i]->position.x -12, active[i]->position.y -5, COLLIDER_NONE, 0);
				break;
			}
			else if (active[i]->BARREL_hits == 2)
			{
				App->enemies->AddEnemy(ENEMY_TYPES::POINTS, active[i]->position.x + 3, active[i]->position.y, 1000);
				active[i]->Coll_Struct.x = 0;
				active[i]->Coll_Struct.y = 0;
				active[i]->Coll_Struct.w = 0;
				active[i]->Coll_Struct.h = 0;
				active[i]->BARREL_hits++;
				App->particles->AddParticle(App->particles->barrel, active[i]->position.x - 12, active[i]->position.y + 10 , COLLIDER_NONE, 0);
				break;
			}
		}
	}
}
