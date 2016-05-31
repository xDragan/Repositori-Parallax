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
#include "ModuleUI.h"
#include "ModuleText.h"
#include "ModuleSceneCredit.h"
#include "SDL\include\SDL.h"

#include <stdio.h>

ModuleSceneCredit::ModuleSceneCredit()
{
}

ModuleSceneCredit::~ModuleSceneCredit()
{}

// Load assets
bool ModuleSceneCredit::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	background = App->textures->Load("bloodbros/scorescreen.png");
	App->audio->Load("bloodbros/TittleScreen.ogg");
	player_name = App->text->AddText(75, 32, "RIC");
	score_counter = App->text->AddNumber(130, 32, App->UserUI->topscori, 8);

	return ret;
}

// Load assets
bool ModuleSceneCredit::CleanUp()
{
	LOG("Unloading title screen");
	App->textures->Unload(background);
	App->UserUI->Disable();
	App->UserUI->score = 0;
	App->text->EraseText(player_name);
	App->text->EraseText(score_counter);
	return true;
}

// Update: draw background
update_status ModuleSceneCredit::Update()
{
	App->render->Blit(background, 0, 0, NULL);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->intro2);
	}
	return UPDATE_CONTINUE;
}