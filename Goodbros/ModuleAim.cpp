#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleAim.h"
#include "ModuleAudio.h"
#include "SDL/include/SDL_timer.h"

ModuleAim::ModuleAim()
{
	idle.PushBack({ 542, 289, 23, 21 });

	aim.PushBack({ 542, 289, 23, 21 });
	aim.PushBack({ 579, 289, 23, 31 });
	aim.speed = 0.2f;

	Aimshotgun.PushBack({466,284 ,31 ,29 });
	Aimshotgun.PushBack({ 502, 284, 31, 29 });
	Aimshotgun.speed = 0.2f;

	Aimmachine.PushBack({469, 248, 43, 32});
	Aimmachine.PushBack({517, 248, 43, 32});
	Aimmachine.speed = 0.2f;

	Aimshotgunshot.PushBack({555, 248, 43, 32});
	Aimshotgunshot.PushBack({ 603, 248, 43, 32});
	Aimshotgunshot.PushBack({ 652, 248, 43, 32});
	Aimshotgunshot.PushBack({ 700, 248, 43,32 });
	Aimshotgunshot.PushBack({ 469, 248, 43, 32 });
	Aimshotgunshot.PushBack({ 517, 248, 43, 32 });
	Aimshotgunshot.speed = 0.5f;
	Aimshotgunshot.loop = true;

	aimmachinegunshot.PushBack({414, 319, 31,29});
	aimmachinegunshot.PushBack({ 450, 319, 31, 29 });
	aimmachinegunshot.PushBack({ 414, 354, 31, 29 });
	aimmachinegunshot.PushBack({ 450, 354, 31, 29 });
	aimmachinegunshot.PushBack({ 466, 284, 31, 29 });
	aimmachinegunshot.PushBack({ 502, 284, 31, 29 });
	aimmachinegunshot.speed = 0.5f;
	aimmachinegunshot.loop = true;

	Aimshoot.PushBack({ 626, 288, 23, 21 });
	Aimshoot.PushBack({ 660, 289, 23, 21 });
	Aimshoot.PushBack({ 696, 288, 23, 21 });
	Aimshoot.PushBack({ 737, 288, 23, 21 });
	Aimshoot.PushBack({ 542, 289, 23, 21 });
	Aimshoot.PushBack({ 579, 289, 23, 31 });
	Aimshoot.PushBack({ 542, 289, 23, 21 });
	Aimshoot.speed = 0.4f;
	Aimshoot.loop = true;

	aimmode = NORMAL;

	shotgunshots = 0;
	machineshots = 0;
}

ModuleAim::~ModuleAim()
{}

// Load assets
bool ModuleAim::Start()
{
	LOG("Loading Aim");

	graphics = App->textures->Load("bloodbros/Stuff.png");

	position.x = 110;
	position.y = 75;

	Aim = App->collision->AddCollider({ position.x + 3, position.y + 3, 22, 20 }, COLLIDER_PLAYER_NOSHOT);
	return true;
}

// Unload assets
bool ModuleAim::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);

	return true;
}

// Update: draw background
update_status ModuleAim::Update()
{
	int speed = 3;
	switch (aimmode)
	{
	case NORMAL:
		current_animation = &aim;

		if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT && position.x > 2)
		{
			position.x -= speed;
		}
		if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT && position.x < 230)
		{
			position.x += speed;
		}
		if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT && position.y > 2)
		{
			position.y -= speed;
		}
		if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT && position.y < 157)
		{
			position.y += speed;
		}
		if (App->player->Status != DIE && App->player->Status != ROLLING)
		{
			if (App->input->keyboard[SDL_SCANCODE_Z] == KEY_STATE::KEY_REPEAT)
			{
				if (SDL_GetTicks() > timeshot)
				{
					App->audio->PlayFx(App->particles->shot.fx);
					timeshot = SDL_GetTicks() + 150;
				}
				if (SDL_GetTicks() > time)
				{
					
					Aim->type = COLLIDER_PLAYER_SHOT;
					time = SDL_GetTicks() + 500;
				}
				else
				{
					Aim->type = COLLIDER_PLAYER_NOSHOT;
				}
				current_animation = &Aimshoot;
			}
		}
		if (App->input->keyboard[SDL_SCANCODE_Z] == KEY_STATE::KEY_IDLE)
		{
			Aim->type = COLLIDER_PLAYER_NOSHOT;
		}
		break;
	case SHOTGUN:
		current_animation = &Aimshotgun;

		if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT && position.x > 2)
		{
			position.x -= speed;
		}
		if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT && position.x < 230)
		{
			position.x += speed;
		}
		if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT && position.y > 2)
		{
			position.y -= speed;
		}
		if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT && position.y < 157)
		{
			position.y += speed;
		}
		if (App->player->Status != DIE && App->player->Status != ROLLING && App->player->Status != WIN);
		{
			if (App->input->keyboard[SDL_SCANCODE_Z] == KEY_STATE::KEY_REPEAT)
			{
				if (SDL_GetTicks() > timeshot)
				{
					App->audio->PlayFx(App->particles->shotgunshot.fx);
					timeshot = SDL_GetTicks() + 150;
				}
				if (SDL_GetTicks() > time)
				{
				
					Aim->type = COLLIDER_PLAYER_SHOT;
					shotgunshots++;
					time = SDL_GetTicks() + 400;
				}
				else
				{
					Aim->type = COLLIDER_PLAYER_NOSHOT;
				}
				current_animation = &aimmachinegunshot;
			}
			
		}
		if (App->input->keyboard[SDL_SCANCODE_Z] == KEY_STATE::KEY_IDLE)
		{
			Aim->type = COLLIDER_PLAYER_NOSHOT;
		}
		if (shotgunshots >= 25){
			aimmode = NORMAL;
			shotgunshots = 0;
		}
		break;
	case MACHINEGUN:
		current_animation = &Aimmachine;

		if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT && position.x > 2)
		{
			position.x -= speed;
		}
		if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT && position.x < 230)
		{
			position.x += speed;
		}
		if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT && position.y > 2)
		{
			position.y -= speed;
		}
		if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT && position.y < 157)
		{
			position.y += speed;
		}
		if (App->player->Status != DIE && App->player->Status != ROLLING)
		{
			if (App->input->keyboard[SDL_SCANCODE_Z] == KEY_STATE::KEY_REPEAT)
			{
				if (SDL_GetTicks() > timeshot)
				{
					App->audio->PlayFx(App->particles->machineshot.fx);
					timeshot = SDL_GetTicks() + 150;
				}
				if (SDL_GetTicks() > time)
				{
					
					Aim->type = COLLIDER_PLAYER_SHOT;
					machineshots++;
					time = SDL_GetTicks() + 300;
				}
				else
				{
					Aim->type = COLLIDER_PLAYER_NOSHOT;
				}
				current_animation = &Aimshotgunshot;
			}
		}
		if (App->input->keyboard[SDL_SCANCODE_Z] == KEY_STATE::KEY_IDLE)
		{
			Aim->type = COLLIDER_PLAYER_NOSHOT;
		}
		if (machineshots >= 30){
			aimmode = NORMAL;
			machineshots = 0;
		}
			break;
	}
	Aim->rect.x = position.x + 1;
	Aim->rect.y = position.y + 1;

	// Draw everything --------------------------------------
	App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));

	return UPDATE_CONTINUE;
}
