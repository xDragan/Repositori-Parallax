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
#include "ModuleText.h"

ModuleUI::ModuleUI()
{
	insert_coins.PushBack({ 137, 3, 200, 25 });
	insert_coins.PushBack({ 137, 230, 200, 25 });
	insert_coins.loop = true;
	insert_coins.speed = 0.1f;

	life_ball.PushBack({ 240, 9, 8, 8 });

	dynamite_image.PushBack({ 249, 9, 16, 16 });

	foe.PushBack({ 198, 9, 30, 8 });

	foe_bar.PushBack({ 0, 0, 4, 8 });
	foe_bar.PushBack({ 135, 9, 4, 8 });

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
	credit_counter = App->text->AddNumber(SCREEN_WIDTH / 2 + TILE / 2 + 20, SCREEN_HEIGHT - TILE, credit, 2);
	score_counter = App->text->AddNumber(0, 0, score, 8);
	dynamite_counter = App->text->AddNumber(0, SCREEN_HEIGHT - 30, dynamite, 2);

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

	int enemygauge = ((ENEMY_GAUGE - killcount) * 12) / ENEMY_GAUGE;

	if (enemygauge == 0 && killcount != ENEMY_GAUGE)
		enemygauge = 1;

	App->render->Blit(UserInterface, 35, 205, &(foe.GetCurrentFrame()), 0.5);

	Uint32 position = TILE * 2 + 80;
	Uint32 count = 0;

	while (enemygauge - 2 > -1)
	{
		App->render->Blit(UserInterface, 60, 205, &(foe_bar.GetCurrentFrame()), 0.5);
		enemygauge -= 2;
		position += 20;
		++count;
	}

	App->render->Blit(UserInterface, 0, 190, &(dynamite_image.GetCurrentFrame()), 0.6);

	if (hitpoints >= 2)
	{
		App->render->Blit(UserInterface, 0, SCREEN_HEIGHT - 20, &(life_ball.GetCurrentFrame()), 0.6);

		if (hitpoints == 3)
		{
			App->render->Blit(UserInterface, 9, SCREEN_HEIGHT - 20, &(life_ball.GetCurrentFrame()), 0.6);
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_1] == KEY_STATE::KEY_DOWN)
		++credit;

	return UPDATE_CONTINUE;
}





