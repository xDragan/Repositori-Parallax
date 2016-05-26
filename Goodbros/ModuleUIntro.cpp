#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleSceneIntro.h"
#include "ModuleSceneFirst.h"
#include "ModuleFadeToBlack.h"
#include "ModuleUIntro.h"
#include "ModulePlayer.h"
#include "ModuleText.h"

ModuleUIntro::ModuleUIntro()
{
	insert_coins.PushBack({ 137, 3, 200, 25 });
	insert_coins.PushBack({ 137, 230, 200, 25 });
	insert_coins.loop = true;
	insert_coins.speed = 0.1f;

	life_ball.PushBack({ 93, 73, 8, 8 });


	Credit.PushBack({ 79, 55, 35, 7 });

	characterone.PushBack({ 17, 73, 16, 8 });

	top.PushBack({ 34, 73, 16, 8 });

	hitpoints = 3;
	credit = 0;
	score = 0;
	topscori = 2000;
	dynamite = 10;
}
ModuleUIntro::~ModuleUIntro()
{
}
bool ModuleUIntro::Start()
{
	LOG("Loading intro");

	UserInterface = App->textures->Load("bloodbros/HUDandFONTS2.png");
	credit_counter = App->text->AddNumber(144, SCREEN_HEIGHT - 7, credit, 2);
	score_counter = App->text->AddNumber(18, 0, topscori, 8);
	topscore = App->text->AddNumber(SCREEN_WIDTH / 2 - 25, 0, score, 8);

	return true;
}
bool ModuleUIntro::CleanUp()
{
	LOG("Unloading intro");

	App->textures->Unload(UserInterface);
	App->text->EraseText(credit_text);
	App->text->EraseText(credit_counter);
	App->text->EraseText(score_counter);


	return true;
}
update_status ModuleUIntro::Update()
{
	credit_counter->ChangeNumber(credit);
	score_counter->ChangeNumber(score);
	topscore->ChangeNumber(topscori);
	if (score >= topscori) topscori = score;

	App->render->Blit(UserInterface, 105, SCREEN_HEIGHT - 7, &(Credit.GetCurrentFrame()), 0.5);
	App->render->Blit(UserInterface, SCREEN_WIDTH / 2 - 43, 0, &(top.GetCurrentFrame()), 0.5);
	App->render->Blit(UserInterface, 0, 0, &(characterone.GetCurrentFrame()), 0.5);
	
	if (App->player->lose == 1)
	{
		App->render->Blit(UserInterface, 0, SCREEN_HEIGHT - 20, &(life_ball.GetCurrentFrame()), 0.6);
	}

	if (App->input->keyboard[SDL_SCANCODE_1] == KEY_STATE::KEY_DOWN)
		if (credit < 99)
			++credit;

	return UPDATE_CONTINUE;
}





