#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleFadeToBlack.h"
#include "ModulePlayer.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer()
{
	cowboy.x = 10;
	cowboy.y = 0;
	cowboy.w = 47;
	cowboy.h = 64;

	// idle animation (arcade sprite sheet)
	idle.PushBack({ 258, 2, 31, 64 });

	shoot.PushBack({ 258, 76, 31, 66 });
	shoot.PushBack({ 258, 148, 31, 64 });
	shoot.speed = 3.0f;

	// walk forward animation//	
	forward.PushBack({ 66, 225, 35, 59 });
	forward.PushBack({ 107, 226, 35, 60 });
	forward.PushBack({ 147, 227, 41, 61 });
	forward.PushBack({ 198, 227, 32, 61 });
	forward.PushBack({ 234, 227, 31, 61 });
	forward.PushBack({ 277, 230, 41, 61 });
	forward.speed = 0.3f;
	// frontward tumble animation//
	ftumble.PushBack({ 428, 227, 33, 61 });
	ftumble.PushBack({ 475, 227, 66, 61 });
	ftumble.PushBack({ 544, 228, 39, 61 });
	ftumble.PushBack({ 592, 227, 44, 61 });
	ftumble.PushBack({ 636, 227, 33, 61 });
	ftumble.PushBack({ 675, 227, 50, 61 });
	ftumble.PushBack({ 725, 227, 50, 61 });
	ftumble.PushBack({ 773, 227, 33, 61 });
	ftumble.PushBack({ 428, 227, 33, 61 });
	ftumble.speed = 0.15f;
	
	//down frontward tumble animation//
	downftumble.PushBack({ 592, 227, 44, 61 });
	downftumble.PushBack({ 636, 227, 33, 61 });
	downftumble.PushBack({ 675, 227, 50, 61 });
	downftumble.PushBack({ 725, 227, 50, 61 });
	downftumble.PushBack({ 773, 227, 33, 61 });
	downftumble.PushBack({ 428, 227, 33, 61 });
	downftumble.speed = 0.15f;

	//walk backward animation//
	backward.PushBack({ 563, 343, 41, 60 });
	backward.PushBack({ 615, 340, 33, 62 });
	backward.PushBack({ 651, 340, 33, 61 });
	backward.PushBack({ 693, 340, 41, 62 });
	backward.PushBack({ 741, 340, 34, 61 });
	backward.PushBack({ 780, 340, 35, 61 });
	backward.speed = 0.3f;
	//backward tumble animation//

	btumble.PushBack({419,340,34,63});
	btumble.PushBack({341, 340, 66, 61 });
	btumble.PushBack({297, 340, 40, 64 });
	btumble.PushBack({245, 340, 45, 61 });
	btumble.PushBack({211, 340, 34, 64 });
	btumble.PushBack({158, 340, 51, 61 });
	btumble.PushBack({110, 340, 47, 61 });
	btumble.PushBack({75, 340, 33, 61 });
	btumble.speed = 0.15f;

	//down backward tumble animation//

	downbtumble.PushBack({ 245, 340, 45, 61 });
	downbtumble.PushBack({ 211, 340, 34, 64 });
	downbtumble.PushBack({ 158, 340, 51, 61 });
	downbtumble.PushBack({ 110, 340, 47, 61 });
	downbtumble.PushBack({ 75, 340, 33, 61 });
	downbtumble.speed = 0.15f;

	//down animation//
	
	down.PushBack({ 583, 5, 28, 61 });
	
	shoot.PushBack({ 259, 76, 27, 66 });
	shoot.PushBack({ 259, 148, 37, 64 });
	shoot.speed = 0.15f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	graphics = App->textures->Load("bloodbros/character.png");

	position.x = 120;
	position.y = 150;

	// TODO 2: Add a collider to the player

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	float speed = 1.8;
	current_animation = &idle;

	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &backward;
		position.x -= speed;
	}

	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &forward;
		position.x += speed;
	}
	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_C] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_IDLE)
	{
		current_animation = &ftumble;
		
	}
	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_C] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_IDLE)
	{
		current_animation = &btumble;
		
	}

	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_C] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &downftumble;

	}
	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_C] == KEY_STATE::KEY_REPEAT &&App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &downbtumble;

	}


	if (App->input->keyboard[SDL_SCANCODE_Z] == KEY_STATE::KEY_REPEAT)

		current_animation = &shoot;




	if(App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
	{
		if(current_animation != &down)
		{
			
			current_animation = &down;
		}
	}

	if(App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->laser, position.x + 20, position.y, COLLIDER_PLAYER_SHOT);
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
