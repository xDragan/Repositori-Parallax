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
#include "SDL\include\SDL.h"

ModuleSceneWin::ModuleSceneWin()
{}

ModuleSceneWin::~ModuleSceneWin()
{}

// Load assets
bool ModuleSceneWin::Start()
{
	LOG("Loading game intro");
	App->scene_space->background = nullptr;
	App->player->Disable();
	App->particles->Disable();
	App->aim->Disable();
	App->enemies->Disable();
	App->structures->Disable();
	ticks = SDL_GetTicks();
	background = App->textures->Load("bloodbros/win_scene.png");
	App->audio->Load("bloodbros/Victory.ogg");
	App->render->camera.x = App->render->camera.y = 0;

	return true;
}

// UnLoad assets
bool ModuleSceneWin::CleanUp()
{
	LOG("Unloading game scene");
	App->textures->Unload(background);
	//App->audio->Disable();
	return true;
}

// Update: draw background
update_status ModuleSceneWin::Update()
{
	App->render->Blit(background, 0, 0, NULL);

	if (SDL_GetTicks() - ticks > 6000){
		//App->fade->FadeToBlack(this, (Module*)App->scene_intro);
		exit(0);
	}
	return UPDATE_CONTINUE;
}