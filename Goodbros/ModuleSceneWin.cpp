#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneFirst.h"
#include "ModuleSceneWin.h"
#include "ModuleAudio.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleAim.h"
#include "ModuleEnemies.h"
#include "ModuleStructures.h"
#include "moduleUI.h"
#include "SDL\include\SDL.h"

ModuleSceneWin::ModuleSceneWin()
{}

ModuleSceneWin::~ModuleSceneWin()
{}

// Load assets
bool ModuleSceneWin::Start()
{
	LOG("Loading win scene");	
	App->scene_space->CleanUp();
	App->scene_space->Disable();
	ticks = SDL_GetTicks();
	App->building_explosion->Disable();
	background = App->textures->Load("bloodbros/win_scene.png");
	App->render->camera.x = App->render->camera.y = 0;

	return true;
}

// UnLoad assets
bool ModuleSceneWin::CleanUp()
{
	LOG("Unloading win scene");
	App->textures->Unload(background);
	return true;
}

// Update: draw background
update_status ModuleSceneWin::Update()
{
	App->render->Blit(background, 0, 0, NULL);

	if (SDL_GetTicks() - ticks > 3500)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene_credit);
	}
	return UPDATE_CONTINUE;
}