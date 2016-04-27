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
	App->enemies->AddEnemy(ENEMY_TYPES::BLUE_COWBOY, 210, 80);
	App->enemies->AddEnemy(ENEMY_TYPES::BLUE_COWBOY2, 0, 30);
	App->enemies->AddEnemy(ENEMY_TYPES::PIG, 210, 130);

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

	// Draw everything --------------------------------------
	App->render->Blit(background, 0, 0, NULL);

	if (App->player->win_condition == 3)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene_win);
		App->player->win_condition = 0;
	}
	if (App->player->lose == 1)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene_intro);
		App->player->lose = 0;
	}
	return UPDATE_CONTINUE;
}