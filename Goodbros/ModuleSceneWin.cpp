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
	App->player->Disable();
	App->particles->Disable();
	App->aim->Disable();
	App->enemies->Disable();
	App->structuresback->Disable();
	App->structuresmiddle->Disable();
	App->structuresfront->Disable();
	ticks = SDL_GetTicks();
	background = App->textures->Load("bloodbros/win_scene.png");
	App->audio->Load("bloodbros/Victory.ogg");
	App->render->camera.x = App->render->camera.y = 0;

	return true;
}

// UnLoad assets
bool ModuleSceneWin::CleanUp()
{
	LOG("Unloading win scene");
	App->textures->Unload(background);
	App->UserUI->score = 0;
	return true;
}

// Update: draw background
update_status ModuleSceneWin::Update()
{
	App->render->Blit(background, 0, 0, NULL);

	if (SDL_GetTicks() - ticks > 8000)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene_intro);
	}
	return UPDATE_CONTINUE;
}