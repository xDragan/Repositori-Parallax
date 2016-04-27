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

#include "SDL/include/SDL_timer.h"

Structure::Structure()
{
	position.SetToZero();
}

Structure::Structure(const Structure& p) :
Coll_Struct(p.Coll_Struct), position(p.position),
fx(p.fx), mytype(p.mytype), destroy(p.destroy)
{}

Structure::~Structure(){
	if (collider != nullptr){
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
	if (bar.collider != nullptr){
		App->collision->EraseCollider(bar.collider);
	}
}

// Load assets
bool ModuleStructures::Start()
{
	LOG("Loading particles");
	graphics = App->textures->Load("bloodbros/enemy.png");


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
			delete active[i];
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

		if (p == nullptr)
			continue;

		if (p->Update() == false)
		{
			p->collider->to_delete = true;
			delete p;
			active[i] = nullptr;

		}
		else if (p->hits <= 3)
		{
			App->render->Blit(graphics, p->position.x, p->position.y, &p->Coll_Struct, 0);
			if (p->fx_played == false)
			{
				p->fx_played = true;
				// Play particle fx here
			}
		}
		else if (p->hits > 3){
			App->collision->EraseCollider(p->collider);
			App->render->Blit(graphics, p->position.x, p->position.y += 0.6f, &p->destroy.GetCurrentFrame());
			
			/*p->collider->to_delete = true;
			delete p;*/
			if (p->destroy.Finished()){
				delete active[i];
				active[i] = nullptr;
				App->player->win_condition++;
			}
		}
	}

	return UPDATE_CONTINUE;
}

void ModuleStructures::AddStructure(const Structure& particle, int x, int y)
{
	Structure* p = new Structure(particle);
	p->position.x = x;
	p->position.y = y;
	p->collider = App->collision->AddCollider({ p->position.x, p->position.y, particle.Coll_Struct.w, particle.Coll_Struct.h }, COLLIDER_STRUCTURE, this);
	active[last_building++] = p;
}

const Collider* Structure::get_collider() const
{
	return collider;
}

// -------------------------------------------------------------
// -------------------------------------------------------------


void ModuleStructures::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_BUILDINGS; ++i){
		if (active[i] != nullptr && active[i]->get_collider() == c1 && active[i]->mytype == BAR){
			if (active[i]->hits == 0){
				active[i]->Coll_Struct.x = bar2.Coll_Struct.x;
				active[i]->Coll_Struct.y = bar2.Coll_Struct.y;
				active[i]->Coll_Struct.w = bar2.Coll_Struct.w;
				active[i]->Coll_Struct.h = bar2.Coll_Struct.h;
				active[i]->hits++;
				break;
			}
			else if (active[i]->hits == 1){
				active[i]->Coll_Struct.x = bar3.Coll_Struct.x;
				active[i]->Coll_Struct.y = bar3.Coll_Struct.y;
				active[i]->Coll_Struct.w = bar3.Coll_Struct.w;
				active[i]->Coll_Struct.h = bar3.Coll_Struct.h;
				active[i]->hits++;
				break;
			}
			else if (active[i]->hits == 2){
				active[i]->Coll_Struct.x = bar4.Coll_Struct.x;
				active[i]->Coll_Struct.y = bar4.Coll_Struct.y;
				active[i]->Coll_Struct.w = bar4.Coll_Struct.w;
				active[i]->Coll_Struct.h = bar4.Coll_Struct.h;
				active[i]->hits++;
				break;
			}
			else if (active[i]->hits == 3){
				active[i]->Coll_Struct.x = 0;
				active[i]->Coll_Struct.y = 0;
				active[i]->Coll_Struct.w = 0;
				active[i]->Coll_Struct.h = 0;
				active[i]->hits++;
			}
			/*delete[] active[i]->collider;
			active[i]->collider = nullptr;//PROBLEM//*/
		}
	}
}