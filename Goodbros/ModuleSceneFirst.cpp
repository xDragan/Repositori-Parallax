#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleSceneFirst.h"
#include "ModuleAim.h"
#include "ModuleAudio.h"
#include "ModuleEnemies.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleStructures.h"

ModuleSceneFirst::ModuleSceneFirst()
{}

ModuleSceneFirst::~ModuleSceneFirst()
{}

// Load assets
bool ModuleSceneFirst::Start()
{
	LOG("Loading space scene");
	background = App->textures->Load("bloodbros/level1destroyed.png");
	App->audio->Load("bloodbros/level1.ogg");
	App->player->Enable();
	App->particles->Enable();
	App->collision->Enable();
	App->aim->Enable();
	App->structures->Enable();
	App->enemies->Enable();

	// Colliders ---	
	App->collision->AddCollider({0, 224, 3930, 16}, COLLIDER_STRUCTURE);
	App->structures->AddStructure(App->structures->bar, 145, 0);
	
	App->enemies->AddEnemy(ENEMY_TYPES::BLUE_COWBOY2, 170, 30);
	time = SDL_GetTicks();
	time2 = SDL_GetTicks();
	time3 = SDL_GetTicks();

	return true;
}

// UnLoad assets
bool ModuleSceneFirst::CleanUp()
{
	LOG("Unloading space scene");
	//App->audio->Disable();
	App->textures->Unload(background);
	App->player->Disable();
	App->particles->Disable();
	App->aim->Disable();
	App->enemies->Disable();
	App->structures->Disable();
	App->collision->Disable();
	return true;
}

// Update: draw background
update_status ModuleSceneFirst::Update()
{
	// Move camera forward -----------------------------
	int scroll_speed = 0;

	App->player->position.x += 0;
	App->render->camera.x -= 0;

	if (SDL_GetTicks() > time)
	{
		App->enemies->AddEnemy(ENEMY_TYPES::BLUE_COWBOY, 210, 110);
		time = SDL_GetTicks() + 5000;
	}
	if (SDL_GetTicks() > time2)
	{
		App->enemies->AddEnemy(ENEMY_TYPES::GREEN_COWBOY, 210, 100);
		time2 = SDL_GetTicks() + 7000;
	}
	
	if (SDL_GetTicks() > time3)
	{
		App->enemies->AddEnemy(ENEMY_TYPES::PIG, 210, 150);
		time3 = SDL_GetTicks() + 10000;
	}

	// Draw everything --------------------------------------
	App->render->Blit(background, 0, 0, NULL);

	if (App->player->win_condition == 8)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene_win);
		
	}
	if (App->player->lose == 1)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene_intro);
		App->player->lose = 0;
		App->player->win_condition = 0;
	}
	return UPDATE_CONTINUE;
}