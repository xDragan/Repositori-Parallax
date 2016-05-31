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
	App->enemiesback->Enable();
	App->enemiesfront->Enable();
	App->collision->Enable();
	App->aim->Enable();
	App->structuresfront->Enable();
	App->UserUI->Enable();
	App->enemies->Enable();


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
	//App->enemies->AddEnemy(ENEMY_TYPES::BLUE_COWBOY2, 10, 101, NULL, NULL);
	//App->enemies->AddEnemy(ENEMY_TYPES::BLUE_COWBOY3, 50, 101, NULL, NULL);
	//App->enemies->AddEnemy(ENEMY_TYPES::GREEN_COWBOY_RIGHT_TUMBLE, 210, 107, NULL, NULL);
	//App->enemies->AddEnemy(ENEMY_TYPES::CAN, SCREEN_WIDTH / 2 + 5, 130, NULL, NULL);
	App->enemies->AddEnemy(ENEMY_TYPES::GIRL, 0, 105, NULL, NULL);
	//App->barrelroll->AddEnemy(ENEMY_TYPES::BARREL_ROLL, 0, 130, NULL, NULL);
	//App->enemies->AddEnemy(ENEMY_TYPES::COUPLE_GUY, SCREEN_WIDTH - 100, 100, NULL, NULL);
	//App->enemies->AddEnemy(ENEMY_TYPES::COUPLE_GIRL, SCREEN_WIDTH - 90, 100, NULL, NULL);
	//App->enemies->AddEnemy(ENEMY_TYPES::GREEN_COWBOY_BIG_LEFT, -14, 110, NULL, NULL);
	//App->enemies->AddEnemy(ENEMY_TYPES::GREEN_COWBOY_BIG_LEFT, -14, 90, NULL, 1000);
	//App->enemies->AddEnemy(ENEMY_TYPES::GREEN_COWBOY_BIG_LEFT, -14, 70, NULL, 2000);
	//App->enemies->AddEnemy(ENEMY_TYPES::BLUE_COWBOY_TOP_FABTEN, 50, 45, NULL, 5000);
	//App->enemies->AddEnemy(ENEMY_TYPES::BLUE_COWBOY_TOP_FABTEN, 50, 45, NULL, 7000);
	//App->enemies->AddEnemy(ENEMY_TYPES::BLUE_COWBOY_TOP_FABTEN, 50, 45, NULL, 9000);
	//App->enemies->AddEnemy(ENEMY_TYPES::GREEN_COWBOY_TOP_BAR, 205, 50, NULL, 5000);

	
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
	App->enemies->CleanUp();
	App->enemies->Disable();
	App->structuresfront->Disable();
	App->structuresmiddle->Disable();
	App->structuresback->Disable();
	App->barrelroll->Disable();
	App->points->Disable();
	App->smoke->Disable();
	App->enemies->CleanUp();
	App->enemies->Disable();
	App->collision->Disable();
	App->UserUI->Disable();
	App->enemiesfront->CleanUp();
	App->enemiesback->CleanUp();
	App->enemiesfront->Disable();
	App->enemiesback->Disable();
	return true;
}

// Update: draw background
update_status ModuleSceneFirst::Update()
{
	if (SDL_GetTicks() > time+100)
	{
		//App->enemies->AddEnemy(ENEMY_TYPES::BLUE_COWBOY, SCREEN_WIDTH, 130, NULL, 0);
		App->enemiesfront->AddEnemy(ENEMY_TYPES::GREEN_COWBOY_BIG_LEFT, -14, 106, NULL, 5000);
		App->enemiesfront->AddEnemy(ENEMY_TYPES::GREEN_COWBOY_BIG_RIGHT, 250, 106, NULL, 5000);
		App->enemies->AddEnemy(ENEMY_TYPES::GREEN_COWBOY_MEDIUM_LEFT, -14, 107, NULL, 7000);
		App->enemies->AddEnemy(ENEMY_TYPES::GREEN_COWBOY_MEDIUM_RIGHT, 250, 107, NULL, 7000);
		App->enemies->AddEnemy(ENEMY_TYPES::GREEN_COWBOY_MEDIUM_LEFT, -14, 100, NULL, 8000);
		App->enemies->AddEnemy(ENEMY_TYPES::GREEN_COWBOY_MEDIUM_RIGHT, 250, 100, NULL, 8000);
		App->enemies->AddEnemy(ENEMY_TYPES::HORSE_RIGHT, 250, 90, NULL, 9000);
		App->enemiesfront->AddEnemy(ENEMY_TYPES::RIDER, 257, 98, NULL, 9000);
		
		if (App->structuresmiddle->bardest == false && App->structuresfront->bardest == false && App->structuresback->bardest == false){

			App->enemiesback->AddEnemy(ENEMY_TYPES::WHEELBARROW, 250, 95, 1, 10000);
			App->enemiesback->AddEnemy(ENEMY_TYPES::HORSE_SMALL_RIGHT, 250, 95, NULL, 9000);
			App->enemiesback->AddEnemy(ENEMY_TYPES::RIDER_SMALL_RIGHT, 257, 92, NULL, 9000);		
			App->enemies->AddEnemy(ENEMY_TYPES::GREEN_COWBOY_RIGHT_TUMBLE, 210, 100, NULL, 17000);
			App->enemies->AddEnemy(ENEMY_TYPES::BLUE_COWBOY_TOP_FABTEN, 170, 47, NULL, 18000);
			App->enemies->AddEnemy(ENEMY_TYPES::GREEN_COWBOY_TOP_BAR, 215, 45, NULL, 18000);

		}
		if (App->structuresmiddle->fabtendest == false && App->structuresfront->fabtendest == false && App->structuresback->fabtendest == false){


			
			App->enemies->AddEnemy(ENEMY_TYPES::BLUE_COWBOY_TOP_FABTEN, 7, 100, NULL,20500);
			App->enemies->AddEnemy(ENEMY_TYPES::BLUE_COWBOY_TOP_FABTEN, 45, 100, NULL, 20000);
			App->enemies->AddEnemy(ENEMY_TYPES::GREEN_COWBOY_TOP_BAR, 3, 47, NULL, 22000);
			App->enemies->AddEnemy(ENEMY_TYPES::GREEN_COWBOY_TOP_BAR, 25, 47, NULL, 22200);
			App->enemies->AddEnemy(ENEMY_TYPES::GREEN_COWBOY_TOP_BAR, 50, 47, NULL, 22400);





		}
	
		time = SDL_GetTicks() + 30000;
	}

	/*if (SDL_GetTicks() > time2)
	{

		time2 = SDL_GetTicks() + 1000;
	}

	if (SDL_GetTicks() > time3)
	{
		App->enemies->AddEnemy(ENEMY_TYPES::HORSE_RIGHT, SCREEN_WIDTH, 100, NULL);
		App->enemies->AddEnemy(ENEMY_TYPES::RIDER, SCREEN_WIDTH+7, 108, NULL);
		App->enemies->AddEnemy(ENEMY_TYPES::RIDER_SMALL_RIGHT, SCREEN_WIDTH + 7, 87, NULL);
		App->enemies->AddEnemy(ENEMY_TYPES::HORSE_SMALL_RIGHT, SCREEN_WIDTH, 90, NULL);
		App->enemies->AddEnemy(ENEMY_TYPES::PIG, 210, 150, NULL);
		App->enemies->AddEnemy(ENEMY_TYPES::WHEELBARROW, 200, 110, 1);
		time3 = SDL_GetTicks() + 6000;
	}
	*/



	if (App->input->keyboard[SDL_SCANCODE_F2] == KEY_STATE::KEY_DOWN)
	{
		App->enemies->AddEnemy(ENEMY_TYPES::GREEN_COWBOY_TOP_SMALL, 120, 55, NULL, 1000);
		App->enemies->AddEnemy(ENEMY_TYPES::GREEN_COWBOY_TOP_SMALL, 155, 55, NULL, 1000);
		App->enemies->AddEnemy(ENEMY_TYPES::GREEN_COWBOY_TOP_SMALL2, 185, 55, NULL, 1000);
		App->enemies->AddEnemy(ENEMY_TYPES::GREEN_COWBOY_TOP_SMALL2, 215, 55, NULL, 1000);

		App->enemies->AddEnemy(ENEMY_TYPES::GREEN_COWBOY_TOP_SMALL2, 135, 90, NULL, 1000);
		App->enemies->AddEnemy(ENEMY_TYPES::GREEN_COWBOY_TOP_SMALL, 195, 90, NULL, 1000);


		App->enemies->AddEnemy(ENEMY_TYPES::GREEN_COWBOY_TOP_SMALL3, 105, 31, NULL, 1000);
		App->enemies->AddEnemy(ENEMY_TYPES::GREEN_COWBOY_TOP_SMALL3, 172, 31, NULL, 1000);
		App->enemies->AddEnemy(ENEMY_TYPES::GREEN_COWBOY_TOP_SMALL3, 232, 31, NULL, 1000);
	

	}
	if (App->input->keyboard[SDL_SCANCODE_F3] == KEY_STATE::KEY_DOWN)
	{
		App->barrelroll->AddEnemy(ENEMY_TYPES::BARREL_ROLL, 0, 130, NULL, NULL);
		App->enemies->AddEnemy(ENEMY_TYPES::CAN, SCREEN_WIDTH / 2 + 5, 130, NULL, NULL);
	}
	if (App->input->keyboard[SDL_SCANCODE_F4] == KEY_STATE::KEY_DOWN)
	{
		App->enemies->AddEnemy(ENEMY_TYPES::GREEN_COWBOY_BIG_LEFT, -14, 110, NULL, NULL);
		App->enemies->AddEnemy(ENEMY_TYPES::GREEN_COWBOY_BIG_RIGHT, SCREEN_WIDTH, 110, NULL, NULL);
		App->enemies->AddEnemy(ENEMY_TYPES::GREEN_COWBOY_MEDIUM_LEFT, -14, 100, NULL, NULL);
		App->enemies->AddEnemy(ENEMY_TYPES::GREEN_COWBOY_MEDIUM_RIGHT, SCREEN_WIDTH, 100, NULL, NULL);
	}
	if (App->input->keyboard[SDL_SCANCODE_F5] == KEY_STATE::KEY_DOWN)
	{
		App->enemies->AddEnemy(ENEMY_TYPES::HORSE_RIGHT, SCREEN_WIDTH, 100, NULL, NULL);
		App->enemies->AddEnemy(ENEMY_TYPES::HORSE_SMALL_RIGHT, SCREEN_WIDTH, 100, NULL, NULL);
	}
	if (App->input->keyboard[SDL_SCANCODE_F6] == KEY_STATE::KEY_DOWN)
	{
		App->enemies->AddEnemy(ENEMY_TYPES::GREEN_COWBOY_RIGHT_TUMBLE, 210, 107, NULL, NULL);
	}
	if (App->input->keyboard[SDL_SCANCODE_F7] == KEY_STATE::KEY_DOWN)
	{
		
	}

	// Draw everything
	App->render->Blit(background, 0, 0, NULL);
	if (App->player->win_condition >= 18 && (App->player->windance.Finished() == true || App->player->gwindance.Finished()))
	{
		App->fade->FadeToBlack(this, (Module*)App->scene_win);
		App->player->win_condition = 0;

	}
	if (App->UserUI->continue_counter == 0)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene_intro);
		App->player->lose = 0;
		App->player->win_condition = 0;
	}
	return UPDATE_CONTINUE;
}