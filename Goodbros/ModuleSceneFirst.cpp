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
#include "ModuleUI.h"

ModuleSceneFirst::ModuleSceneFirst()
{}

ModuleSceneFirst::~ModuleSceneFirst()
{}

// Load assets
bool ModuleSceneFirst::Start()
{
	// Loading textures
	LOG("Loading first stage scene");
	background = App->textures->Load("bloodbros/level1destroyed.png");
	App->audio->Load("bloodbros/level1.ogg");

	// Loading various modules
	App->player->Enable();
	App->particles->Enable();
	App->collision->Enable();
	App->aim->Enable();
	App->structuresfront->Enable();
	App->structuresmiddle->Enable();
	App->structuresback->Enable();
	App->enemies->Enable();
	App->UserUI->Enable();
	App->barrelroll->Enable();
	App->points->Enable();
	App->smoke->Enable();
	App->enemies->Enable();
	App->UserUI->Enable();

	// Player reset position & death animation
	App->player->position.x = 120;
	App->player->position.y = 150;

	// Buildings
	App->structuresback->AddStructure(App->structuresback->inn, 0, 32);
	App->structuresback->AddStructure(App->structuresback->hotel, 105, 35);
	App->structuresback->AddStructure(App->structuresback->smallest_b, 175, 42);
	App->structuresmiddle->AddStructure(App->structuresmiddle->fabten, 0, 8);
	App->structuresmiddle->AddStructure(App->structuresmiddle->bar, 145, 0);

	// Enemies
	App->enemies->AddEnemy(ENEMY_TYPES::BLUE_COWBOY2, 10, 101, NULL);
	App->enemies->AddEnemy(ENEMY_TYPES::BLUE_COWBOY3, 50, 101, NULL);
	App->barrelroll->AddEnemy(ENEMY_TYPES::BARREL_ROLL, 0, 130, NULL);
	App->enemies->AddEnemy(ENEMY_TYPES::CAN, 50, 105, NULL);
	App->enemies->AddEnemy(ENEMY_TYPES::GIRL, 0, 105, NULL);

	//Barrels
	App->structuresfront->AddStructure(App->structuresfront->barrel, 6, 144);
	App->structuresfront->AddStructure(App->structuresfront->barrel, 38, 144);
	App->structuresfront->AddStructure(App->structuresfront->barrel, 198, 144);

	// Time counters
	time = SDL_GetTicks();
	time2 = SDL_GetTicks();
	time3 = SDL_GetTicks();

	return true;
}

// UnLoad assets
bool ModuleSceneFirst::CleanUp()
{
	LOG("Unloading first scene");

	App->textures->Unload(background);
	
	App->player->Disable();
	App->particles->Disable();
	App->aim->Disable();
	App->structuresfront->CleanUp();
	App->structuresmiddle->CleanUp();
	App->structuresback->CleanUp();
	App->enemies->Disable();
	App->structuresfront->Disable();
	App->structuresmiddle->Disable();
	App->structuresback->Disable();
	App->barrelroll->Disable();
	App->points->Disable();
	App->smoke->Disable();
	App->collision->Disable();
	App->UserUI->Disable();
	return true;
}

// Update: draw background
update_status ModuleSceneFirst::Update()
{
	if (SDL_GetTicks() > time + 1000)
	{
		App->enemies->AddEnemy(ENEMY_TYPES::BLUE_COWBOY2, -14, 110, NULL);
		App->enemies->AddEnemy(ENEMY_TYPES::BLUE_COWBOY, -14, 110, NULL);
		App->enemies->AddEnemy(ENEMY_TYPES::GREEN_COWBOY_BIG_LEFT, -14, 110, NULL);
		App->enemies->AddEnemy(ENEMY_TYPES::GREEN_COWBOY_BIG_RIGHT, SCREEN_WIDTH, 110, NULL);
		App->enemies->AddEnemy(ENEMY_TYPES::GREEN_COWBOY_MEDIUM_LEFT, -14, 100, NULL);
		App->enemies->AddEnemy(ENEMY_TYPES::GREEN_COWBOY_MEDIUM_RIGHT, SCREEN_WIDTH, 100, NULL);
		time = SDL_GetTicks() + 5000;
	}
	if (SDL_GetTicks() > time2)
	{

		time2 = SDL_GetTicks() + 1000;
	}

	if (SDL_GetTicks() > time3)
	{
		App->enemies->AddEnemy(ENEMY_TYPES::PIG, 210, 150, NULL);
		App->enemies->AddEnemy(ENEMY_TYPES::WHEELBARROW, 200, 110, 1);
		time3 = SDL_GetTicks() + 10000;
	}

	// Draw everything
	App->render->Blit(background, 0, 0, NULL);

	if (App->player->win_condition >= 18)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene_win);
		App->player->win_condition = 0;

	}
	if (App->player->lose >= 3)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene_intro);
		App->player->lose = 0;
		App->player->win_condition = 0;
	}
	return UPDATE_CONTINUE;
}