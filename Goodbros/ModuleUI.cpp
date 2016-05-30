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
#include "ModuleUIntro.h"


#include "SDL/include/SDL_timer.h"
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
	foe_barw.PushBack({ 88, 73, 4, 9 });

	Credit.PushBack({ 79, 55, 35, 7});

	characterone.PushBack({ 17, 73, 16, 8});
	
	top.PushBack({ 34, 73, 16, 8 });

	Continue.PushBack({ 16, 82, 50, 9 });

	InsertCoin.PushBack({ 17, 55, 59, 8 });

	hitpoints = 3;
	credit = 0;
	score = 0;
	topscori = 2000;
	dynamite = 10;
	continue_counter = 10;
}
ModuleUI::~ModuleUI()
{
}
bool ModuleUI::Start()
{
	LOG("Loading intro");

	UserInterface = App->textures->Load("bloodbros/HUDandFONTS2.png");
	credit_counter = App->text->AddNumber(144, SCREEN_HEIGHT - 7, credit, 2);
	score_counter = App->text->AddNumber(18, 0, topscori, 8);
	topscore = App->text->AddNumber(SCREEN_WIDTH/2 -25, 0, score, 8);
	dynamite_counter = App->text->AddNumber(1, SCREEN_HEIGHT - 23, dynamite, 2);
	
	return true;
}
bool ModuleUI::CleanUp()
{
	timecont = SDL_GetTicks();
	LOG("Unloading intro");

	App->textures->Unload(UserInterface);
	App->text->EraseText(credit_counter);
	App->text->EraseText(score_counter);
	App->text->EraseText(topscore);
	App->text->EraseText(dynamite_counter);
	App->text->EraseText(Continuee);
	return true;
}
update_status ModuleUI::Update()
{
	dynamite_counter->ChangeNumber(dynamite);
	credit_counter->ChangeNumber(credit);
	score_counter->ChangeNumber(score);
	if (score >= topscori) topscori = score;
	topscore->ChangeNumber(topscori);
	if (credit == 0){
		if (App->player->c_time >= App->player->timedying || App->player->blinkd)
		{
			App->render->Blit(UserInterface, SCREEN_WIDTH / 2 + 50, SCREEN_HEIGHT - 8, &(InsertCoin.GetCurrentFrame()), 0.5);
		}
	}


	if (App->player->win_condition < 5){
		App->render->Blit(UserInterface, 69, 207, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 73, 207, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 77, 207, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 81, 207, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 85, 207, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 89, 207, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 93, 207, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 97, 207, &(foe_bar.GetCurrentFrame()), 0.5);
	}
	else if (App->player->win_condition < 10){
		App->render->Blit(UserInterface, 69, 207, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 73, 207, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 77, 207, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 81, 207, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 85, 207, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 89, 207, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 93, 207, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 97, 208, &(foe_barw.GetCurrentFrame()), 0.5);
	}
	else if (App->player->win_condition < 15){
		App->render->Blit(UserInterface, 69, 207, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 73, 207, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 77, 207, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 81, 207, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 85, 207, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 89, 207, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 93, 208, &(foe_barw.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 97, 208, &(foe_barw.GetCurrentFrame()), 0.5);
	}
	else if (App->player->win_condition < 20){
		App->render->Blit(UserInterface, 69, 207, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 73, 207, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 77, 207, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 81, 207, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 85, 207, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 89, 208, &(foe_barw.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 93, 208, &(foe_barw.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 97, 208, &(foe_barw.GetCurrentFrame()), 0.5);
	}
	else if (App->player->win_condition < 25){
		App->render->Blit(UserInterface, 69, 207, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 73, 207, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 77, 207, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 81, 207, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 85, 208, &(foe_barw.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 89, 208, &(foe_barw.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 93, 208, &(foe_barw.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 97, 208, &(foe_barw.GetCurrentFrame()), 0.5);
	}
	else if (App->player->win_condition < 30){
		App->render->Blit(UserInterface, 69, 207, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 73, 207, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 77, 207, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 81, 208, &(foe_barw.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 85, 208, &(foe_barw.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 89, 208, &(foe_barw.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 93, 208, &(foe_barw.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 97, 208, &(foe_barw.GetCurrentFrame()), 0.5);
	}
	else if (App->player->win_condition < 35){
		App->render->Blit(UserInterface, 69, 207, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 73, 207, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 77, 208, &(foe_barw.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 81, 208, &(foe_barw.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 85, 208, &(foe_barw.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 89, 208, &(foe_barw.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 93, 208, &(foe_barw.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 97, 208, &(foe_barw.GetCurrentFrame()), 0.5);
	}
	else if (App->player->win_condition < 40){
		App->render->Blit(UserInterface, 69, 207, &(foe_bar.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 73, 208, &(foe_barw.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 77, 208, &(foe_barw.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 81, 208, &(foe_barw.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 85, 208, &(foe_barw.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 89, 208, &(foe_barw.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 93, 208, &(foe_barw.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 97, 208, &(foe_barw.GetCurrentFrame()), 0.5);
	}
	if (App->player->win_condition == 40){
		App->render->Blit(UserInterface, 69, 208, &(foe_barw.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 73, 208, &(foe_barw.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 77, 208, &(foe_barw.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 81, 208, &(foe_barw.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 85, 208, &(foe_barw.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 89, 208, &(foe_barw.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 93, 208, &(foe_barw.GetCurrentFrame()), 0.5);
		App->render->Blit(UserInterface, 97, 208, &(foe_barw.GetCurrentFrame()), 0.5);
	}


	

	App->render->Blit(UserInterface, 105, SCREEN_HEIGHT-7, &(Credit.GetCurrentFrame()), 0.5);
	App->render->Blit(UserInterface, 35, 208, &(foe.GetCurrentFrame()), 0.5);
	App->render->Blit(UserInterface, SCREEN_WIDTH/2 -43, 0, &(top.GetCurrentFrame()), 0.5);
	App->render->Blit(UserInterface, 0, 0, &(characterone.GetCurrentFrame()), 0.5);
	App->render->Blit(UserInterface, 1, SCREEN_HEIGHT- 39,  &(dynamite_image.GetCurrentFrame()), 0.6);
	if (App->player->lose == 0){
		App->render->Blit(UserInterface, 0, SCREEN_HEIGHT - 15, &(life_ball.GetCurrentFrame()), 0.6);
		App->render->Blit(UserInterface, 8, SCREEN_HEIGHT - 15, &(life_ball.GetCurrentFrame()), 0.6);
	}
	if (App->player->lose == 1)
	{
		App->render->Blit(UserInterface, 0, SCREEN_HEIGHT - 15, &(life_ball.GetCurrentFrame()), 0.6);
	}
	if (App->player->loosing == false){
		continue_counter = 10;
		App->text->EraseText(Continuee);
	}
	if (App->player->loosing == true){
		if (done == false){
		Continuee = App->text->AddNumber(85, SCREEN_HEIGHT - 7, continue_counter, 2);
		done = true;
	}
		Continuee->ChangeNumber(continue_counter);
		if (App->player->c_time >= App->player->timedying || App->player->blinkd)
		{
			App->render->Blit(UserInterface, 29, SCREEN_HEIGHT - 8, &(Continue.GetCurrentFrame()), 0.5);
		}
		if (SDL_GetTicks() > time)
		{
			continue_counter--;
			time = SDL_GetTicks() + 1100;
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_1] == KEY_STATE::KEY_DOWN)
		if (credit < 99)
		++credit;

	return UPDATE_CONTINUE;
}





