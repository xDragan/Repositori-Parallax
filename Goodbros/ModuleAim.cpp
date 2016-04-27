#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleAim.h"
#include "SDL/include/SDL_timer.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleAim::ModuleAim()
{
	idle.PushBack({ 542, 289, 23, 21 });

	aim.PushBack({ 542, 289, 23, 21 });
	aim.PushBack({ 579, 289, 23, 31 });
	aim.speed = 0.2f;

	Aimshoot.PushBack({ 626, 288, 23, 21 });
	Aimshoot.PushBack({ 660, 289, 23, 21 });
	Aimshoot.PushBack({ 696, 288, 23, 21 });
	Aimshoot.PushBack({ 737, 288, 23, 21 });
	Aimshoot.PushBack({ 542, 289, 23, 21 });
	Aimshoot.PushBack({ 579, 289, 23, 31 });
	Aimshoot.PushBack({ 542, 289, 23, 21 });
	Aimshoot.speed = 0.4f;
	Aimshoot.loop = true;
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
	
	current_animation = &aim;

	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT&&position.x>2)
	{
		position.x -= speed;
	}
	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT&&position.x<230)
	{
		position.x += speed;
	}
	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT&&position.y>2)
	{
		position.y -= speed;
	}
	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT&&position.y<157)
	{
		position.y += speed;
	}
	if (App->input->keyboard[SDL_SCANCODE_Z] == KEY_STATE::KEY_REPEAT)
		{
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
	if (App->input->keyboard[SDL_SCANCODE_Z] == KEY_STATE::KEY_IDLE){
		Aim->type = COLLIDER_PLAYER_NOSHOT;
	}

	Aim->rect.x = position.x + 1;
	Aim->rect.y = position.y + 1;

	// Draw everything --------------------------------------
	App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));

	return UPDATE_CONTINUE;
}
