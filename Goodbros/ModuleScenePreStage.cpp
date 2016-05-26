#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleFadeToBlack.h"
#include "ModuleScenePreStage.h"
#include "ModuleAudio.h"
#include "ModuleSceneFirst.h"
#include "ModuleUIntro.h"
ModuleScenePreStage::ModuleScenePreStage()
{}

ModuleScenePreStage::~ModuleScenePreStage()
{}

// Load assets
bool ModuleScenePreStage::Start()
{
	LOG("Loading game intro");
	ticks = SDL_GetTicks();
	background = App->textures->Load("bloodbros/windows_page.png");
	lvls = App->textures->Load("bloodbros/lvls_window_page.png");
	App->audio->Load("bloodbros/PreStage.ogg");
	App->introUI->Enable();
	App->render->camera.x = App->render->camera.y = 0;

	return true;
}

// UnLoad assets
bool ModuleScenePreStage::CleanUp()
{
	LOG("Unloading game scene");
	App->textures->Unload(lvls);
	App->textures->Unload(background);
	App->introUI->Disable();
	return true;
}

// Update: draw background
update_status ModuleScenePreStage::Update()
{
	App->render->Blit(background, 0, 0, NULL);
	App->render->Blit(lvls, 0, 0, NULL);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN && App->fade->IsFading() == false)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene_space);
	}

	if (SDL_GetTicks() - ticks > 6000)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene_space);
	}
	return UPDATE_CONTINUE;
}