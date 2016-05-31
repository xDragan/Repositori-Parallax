#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneIntro2.h"
#include "ModuleAudio.h"
#include "ModuleSceneFirst.h"
#include "ModuleUIntro.h"
#include "ModuleEnemies.h"
#include "ModuleParticles.h"
#include "ModuleStructures.h"
ModuleSceneIntro2::ModuleSceneIntro2()
{}

ModuleSceneIntro2::~ModuleSceneIntro2()
{}

// Load assets
bool ModuleSceneIntro2::Start()
{
	LOG("Loading game intro");
	
	background = App->textures->Load("bloodbros/window inic.png");
	App->audio->Load("bloodbros/TittleScreen.ogg");
	App->introUI->Enable();
	App->barrelroll->Enable();
	App->particles->Enable();

	App->render->camera.x = App->render->camera.y = 0;

	return true;
}

// UnLoad assets
bool ModuleSceneIntro2::CleanUp()
{
	LOG("Unloading game intro");
	App->textures->Unload(background);
	App->introUI->Disable();
	return true;
}

// Update: draw background
update_status ModuleSceneIntro2::Update()
{
	App->render->Blit(background, 0, 0, NULL);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN && App->fade->IsFading() == false && App->introUI->credit >= 1)
	{
		App->introUI->credit -= 1;
		App->fade->FadeToBlack(this, (Module*)App->scene_prestage);
	}
	return UPDATE_CONTINUE;
}