#include "Globals.h"
#include "Application.h"
#include "ModuleLevel1.h"
#include "ModuleTittleScreen.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "Audio0.h"

// Reference at https://youtu.be/6OlenbCC4WI?t=382

ModuleTitleScreen::ModuleTitleScreen()
{
	// Background
	titlescreen.x = 0;
	titlescreen.y = 0;
	titlescreen.w = 256;
	titlescreen.h = 224;

}

ModuleTitleScreen::~ModuleTitleScreen()
{}

// Load assets
bool ModuleTitleScreen::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("Welcomepage.png");
	
	App->audio0->Enable();

	return ret;
}

// Load assets
bool ModuleTitleScreen::CleanUp()
{
	LOG("Unloading title screen");

	App->audio0->Disable();
	return true;
}

// Update: draw background
update_status ModuleTitleScreen::Update()
{
	// Draw everything --------------------------------------	

	App->render->Blit(graphics, 0, 0, &titlescreen, 0); // level 1
	App->player->Disable();
	// TODO 3: make so pressing SPACE the KEN stage is loaded
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1)
	{
		App->fade->FadeToBlack(App->titlescreen, App->Level1, 2);
	}
	return UPDATE_CONTINUE;
}