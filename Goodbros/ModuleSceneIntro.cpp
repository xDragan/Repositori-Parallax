#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneIntro.h"
#include "ModuleAudio.h"
// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneIntro::ModuleSceneIntro()
{}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading game intro");
	background = App->textures->Load("bloodbros/Welcomepage.png");
	App->audio->Load("bloodbros/TittleScreen.ogg");
	App->render->camera.x = App->render->camera.y = 0;
	
	return true;
}

// UnLoad assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading game scene");
	App->textures->Unload(background);
	//App->audio->Disable();
	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	App->render->Blit(background, 0, 0, NULL);

	if(App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN && App->fade->IsFading() == false)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene_prestage);
	}

	return UPDATE_CONTINUE;
}