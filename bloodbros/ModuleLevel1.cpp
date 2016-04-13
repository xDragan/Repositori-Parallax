#include "Globals.h"
#include "Application.h"
#include "ModuleLevel1.h"
#include "ModuleLevel2.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "Audio1.h"

// Reference at https://youtu.be/6OlenbCC4WI?t=382

ModuleLevel1::ModuleLevel1()
{
	// Background
	background.x = 0;
	background.y = 0;
	background.w = 256;
	background.h = 224;

}

ModuleLevel1::~ModuleLevel1()
{}

// Load assets
bool ModuleLevel1::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("level1.png");

	// TODO 1: Enable (and properly disable) the player module
	App->player->Enable();
	App->audio1->Enable();
	return ret;
}

// Load assets
bool ModuleLevel1::CleanUp()
{
	LOG("Unloading level 1");
	App->player->Disable();
	App->audio1->Disable();
	return true;
}

// Update: draw background
update_status ModuleLevel1::Update()
{
	// Draw everything --------------------------------------	

	App->render->Blit(graphics, 0, 0, &background, 0); // level 1

	// TODO 3: make so pressing SPACE the KEN stage is loaded
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1)
	{
		App->fade->FadeToBlack(App->Level1, App->Level2, 2);
	}
	return UPDATE_CONTINUE;
}