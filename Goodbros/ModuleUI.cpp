#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleSceneIntro.h"
#include "ModuleSceneFirst.h"
#include "ModuleFadeToBlack.h"
#include "ModuleUI.h"
#include "ModulePlayer.h"
#include "ModuleText.h"

ModuleUI::ModuleUI()
{
	insert_coins.PushBack({ 137, 3, 200, 25 });
	insert_coins.PushBack({ 137, 230, 200, 25 });
	insert_coins.loop = true;
	insert_coins.speed = 0.1f;

	life_ball.PushBack({ 93, 73, 8, 8 });

	dynamite_image.PushBack({ 0, 55, 15, 16 });

	foe.PushBack({ 51, 73, 30, 8 });

	foe_bar.PushBack({ 83, 72, 4, 9 });
	foe_bar_white.PushBack({ 88, 73, 4, 9 });

	Credit.PushBack({ 79, 55, 35, 7});

	characterone.PushBack({ 17, 73, 16, 8});
	
	hitpoints = 3;
	credit = 0;
	score = 0;
	dynamite = 10;
}
ModuleUI::~ModuleUI()
{
}
bool ModuleUI::Start()
{
	LOG("Loading intro");

	UserInterface = App->textures->Load("bloodbros/HUDandFONTS2.png");
	credit_counter = App->text->AddNumber(SCREEN_WIDTH / 2 + 3, SCREEN_HEIGHT - 7, credit, 2);
	score_counter = App->text->AddNumber(18, 0, score, 8);
	dynamite_counter = App->text->AddNumber(1, SCREEN_HEIGHT - 28, dynamite, 2);

	return true;
}
bool ModuleUI::CleanUp()
{
	LOG("Unloading intro");

	App->textures->Unload(UserInterface);
	App->text->EraseText(credit_text);
	App->text->EraseText(credit_counter);
	App->text->EraseText(score_counter);
	App->text->EraseText(dynamite_counter);

	return true;
}
update_status ModuleUI::Update()
{
	credit_counter->ChangeNumber(credit);
	score_counter->ChangeNumber(score);
	if (true){
		App->render->Blit(UserInterface, 69, 202, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 73, 202, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 77, 202, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 81, 202, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 85, 202, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 89, 202, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 93, 202, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 97, 202, &(foe_bar.GetCurrentFrame()), 0.5);
	}

	App->render->Blit(UserInterface, 90, SCREEN_HEIGHT-7, &(Credit.GetCurrentFrame()), 0.5);
	
	App->render->Blit(UserInterface, 35, 203, &(foe.GetCurrentFrame()), 0.5);
	App->render->Blit(UserInterface, 0, 0, &(characterone.GetCurrentFrame()), 0.5);
	App->render->Blit(UserInterface, 1, SCREEN_HEIGHT- 44,  &(dynamite_image.GetCurrentFrame()), 0.6);
	if (App->player->lose == 0){
		App->render->Blit(UserInterface, 0, SCREEN_HEIGHT - 20, &(life_ball.GetCurrentFrame()), 0.6);
		App->render->Blit(UserInterface, 8, SCREEN_HEIGHT - 20, &(life_ball.GetCurrentFrame()), 0.6);
	}
	if (App->player->lose == 1)
	{
		App->render->Blit(UserInterface, 0, SCREEN_HEIGHT - 20, &(life_ball.GetCurrentFrame()), 0.6);
	}

	if (App->input->keyboard[SDL_SCANCODE_1] == KEY_STATE::KEY_DOWN)
		if (credit < 99)
		++credit;

	return UPDATE_CONTINUE;
}





