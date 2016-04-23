#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleFadeToBlack.h"
#include "ModulePlayer.h"
#include "ModuleAim.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleAim::ModuleAim()
{
	idle.PushBack({ 465, 283, 33, 31 });


	shoot.PushBack({ 465, 283, 33, 31 });
	shoot.PushBack({ 501, 283, 33, 31 });
	shoot.speed = 0.2f;
	
}

ModuleAim::~ModuleAim()
{}

// Load assets
bool ModuleAim::Start()
{
	LOG("Loading Aim");

	graphics = App->textures->Load("bloodbros/Stuff.png");

	position.x = 100;
	position.y = 75;

	

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
	current_animation = &idle;

	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &idle;
		position.x -= speed;
	}

	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &idle;
		position.x += speed;
	}

	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &idle;
		position.y -= speed;
	}
	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &idle;
		position.y += speed;
	}
	if (App->input->keyboard[SDL_SCANCODE_Z] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &shoot;
	
	}
	/*if(App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
	&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE && App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE && App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE)
	current_animation = &idle;*/

	// TODO 3: Update collider position to player position

	// Draw everything --------------------------------------
	App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));

	return UPDATE_CONTINUE;
}

// TODO 4: Detect collision with a wall. If so, go back to intro screen.
