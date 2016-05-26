#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneIntro.h"
#include "ModuleSceneFirst.h"
#include "ModuleAudio.h"
#include "ModuleUI.h"
#include "ModuleText.h"
#include "ModuleUIntro.h"

ModuleSceneIntro::ModuleSceneIntro()
{}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	ticks = SDL_GetTicks();
	LOG("Loading game intro");
	background = App->textures->Load("bloodbros/tribute.png");
	return true;
}

// UnLoad assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading game scene");
	App->textures->Unload(background);
	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	App->render->Blit(background, 0, 0, NULL);
	if (SDL_GetTicks() - ticks > 6000)
	{
		App->fade->FadeToBlack(this, (Module*)App->intro2);
	}
	if(App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN && App->fade->IsFading() == false)
	{
		App->fade->FadeToBlack(this, (Module*)App->intro2);
	}

	return UPDATE_CONTINUE;
}