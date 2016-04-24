#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleFadeToBlack.h"
#include "ModulePlayer.h"

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
int const ModulePlayer::looking_at()
{
	int distance = (Aimposition.x + 70 / 2) - (position.x + 80 / 2);
	int portion = SCREEN_WIDTH / 7;
	if (distance >= portion / 2)
	{
		if (distance >= (2 * portion + portion / 2))
			return far_right;
		else if (distance >= (portion + portion / 2))
			return middle_right;
		else
			return near_right;
	}
	else if (distance <= -portion / 2)
	{
		if (distance <= -(2 * portion + portion / 2))
			return far_left;
		else if (distance <= -(portion + portion / 2))
			return Middle_left;
		else
			return near_left;
	}
	else
		return middle;
}

ModulePlayer::ModulePlayer()
{
	cowboy.x = 10;
	cowboy.y = 0;
	cowboy.w = 47;
	cowboy.h = 64;

	// idle animation //

	idle[far_left].PushBack({ 115, 3, 27, 61 });
	idle[Middle_left].PushBack({ 164, 2, 30, 60 });
	idle[near_left].PushBack({ 214, 2, 29, 60 });
	idle[middle].PushBack({ 266, 5, 23, 60 });
	idle[near_right].PushBack({ 310, 7, 23, 61 });
	idle[middle_right].PushBack({ 347, 8, 27, 61 });
	idle[far_right].PushBack({ 387, 9, 31, 61 });

	down[far_left].PushBack({ 435, 1, 32, 64 });
	down[Middle_left].PushBack({ 486, 1, 30, 64 });
	down[near_left].PushBack({ 538, 1, 28, 64 });
	down[middle].PushBack({ 583, 1, 29, 64 });
	down[near_right].PushBack({ 627, 1, 27, 64 });
	down[middle_right].PushBack({ 669, 1, 30, 64 });
	down[far_right].PushBack({ 709, 1, 32, 64 });

	//Shoot animations //
	shoot[far_left].PushBack({ 96, 78, 47, 62 });
	shoot[far_left].PushBack({ 96, 147, 47, 62 });
	shoot[Middle_left].PushBack({ 151, 73, 43, 63 });
	shoot[Middle_left].PushBack({ 151, 149, 43, 63 });
	shoot[near_left].PushBack({ 203, 68, 38, 70 });
	shoot[near_left].PushBack({ 203, 143, 38, 70 });

	shoot[middle].PushBack({ 260, 77, 31, 65 });
	shoot[middle].PushBack({ 258, 149, 31, 65 });

	shoot[near_right].PushBack({ 303, 72, 29, 66 });
	shoot[near_right].PushBack({ 299, 149, 29, 64 });
	shoot[middle_right].PushBack({ 344, 79, 40, 61 });
	shoot[middle_right].PushBack({ 338, 153, 40, 61 });
	shoot[far_right].PushBack({ 385, 80, 46, 60 });
	shoot[far_right].PushBack({ 379, 151, 46, 60 });

	//shot speed
	shoot[far_left].speed = 0.15f;
	shoot[Middle_left].speed = 0.15f;
	shoot[near_left].speed = 0.15f;
	shoot[middle].speed = 0.15f;
	shoot[near_right].speed = 0.15f;
	shoot[middle_right].speed = 0.15f;
	shoot[far_right].speed = 0.15f;

	//Shoot Seated Animation//

	shootdown[far_left].PushBack({ 429, 71, 48, 64 });
	shootdown[far_left].PushBack({ 430, 134, 48, 64 });
	shootdown[Middle_left].PushBack({ 474, 71, 43, 64 });
	shootdown[Middle_left].PushBack({ 483, 134, 43, 64 });
	shootdown[near_left].PushBack({ 528, 71, 38, 64 });
	shootdown[near_left].PushBack({ 531, 134, 38, 64 });

	shootdown[middle].PushBack({ 581, 71, 44, 64 });
	shootdown[middle].PushBack({ 585, 13, 44, 64 });

	shootdown[near_right].PushBack({ 629, 71, 29, 66 });
	shootdown[near_right].PushBack({ 629, 134, 29, 64 });
	shootdown[middle_right].PushBack({ 667, 71, 42, 64 });
	shootdown[middle_right].PushBack({ 666, 134, 35, 64 });
	shootdown[far_right].PushBack({ 712, 71, 37, 64 });
	shootdown[far_right].PushBack({ 711, 134, 39, 64 });

	//shot  seated speed
	shootdown[far_left].speed = 0.15f;
	shootdown[Middle_left].speed = 0.15f;
	shootdown[near_left].speed = 0.15f;
	shootdown[middle].speed = 0.15f;
	shootdown[near_right].speed = 0.15f;
	shootdown[middle_right].speed = 0.15f;
	shootdown[far_right].speed = 0.15f;



	// walk forward animation//	
	forward.PushBack({ 66, 225, 35, 59 });
	forward.PushBack({ 107, 226, 35, 60 });
	forward.PushBack({ 147, 227, 41, 61 });
	forward.PushBack({ 198, 227, 32, 61 });
	forward.PushBack({ 234, 227, 31, 61 });
	forward.PushBack({ 277, 230, 41, 61 });
	forward.speed = 0.1f;
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
	ftumble.speed = 0.1f;

	//down frontward tumble animation//
	downftumble.PushBack({ 592, 227, 44, 61 });
	downftumble.PushBack({ 636, 227, 33, 61 });
	downftumble.PushBack({ 675, 227, 50, 61 });
	downftumble.PushBack({ 725, 227, 50, 61 });
	downftumble.PushBack({ 773, 227, 33, 61 });
	downftumble.PushBack({ 428, 227, 33, 61 });
	downftumble.speed = 0.1f;

	//walk backward animation//
	backward.PushBack({ 563, 343, 41, 60 });
	backward.PushBack({ 615, 340, 33, 62 });
	backward.PushBack({ 651, 340, 33, 61 });
	backward.PushBack({ 693, 340, 41, 62 });
	backward.PushBack({ 741, 340, 34, 61 });
	backward.PushBack({ 780, 340, 35, 61 });
	backward.speed = 0.1f;
	//backward tumble animation//

	btumble.PushBack({ 419, 340, 34, 63 });
	btumble.PushBack({ 341, 340, 66, 61 });
	btumble.PushBack({ 297, 340, 40, 64 });
	btumble.PushBack({ 245, 340, 45, 61 });
	btumble.PushBack({ 211, 340, 34, 64 });
	btumble.PushBack({ 158, 340, 51, 61 });
	btumble.PushBack({ 110, 340, 47, 61 });
	btumble.PushBack({ 75, 340, 33, 61 });
	btumble.speed = 0.1f;

	//down backward tumble animation//

	downbtumble.PushBack({ 245, 340, 45, 61 });
	downbtumble.PushBack({ 211, 340, 34, 64 });
	downbtumble.PushBack({ 158, 340, 51, 61 });
	downbtumble.PushBack({ 110, 340, 47, 61 });
	downbtumble.PushBack({ 75, 340, 33, 61 });
	downbtumble.speed = 0.1f;
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

	player_coll = App->collision->AddCollider({ 128, 153, 22, 27 }, COLLIDER_PLAYER);//cowboy collider

	Aimposition.x = position.x;
	Aimposition.y = position.y - 150;

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
	int AimSpeed = 2;
	int xcorrection = 0;
	int ycorrection = 0;
	int Looking_at = looking_at();
	current_animation = &idle[Looking_at];

	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT && position.x > 8)
	{
		current_animation = &backward;
		position.x -= speed;
		if (Aimposition.x >= 0){
			Aimposition.x -= AimSpeed;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT && position.x < 228)
	{
		current_animation = &forward;
		position.x += speed;
		if (Aimposition.x <= 249){
			Aimposition.x += AimSpeed;
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_C] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_IDLE)
	{
		current_animation = &ftumble;

	}
	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_C] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_IDLE)
	{
		current_animation = &btumble;

	}
	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
	{
		position.x -= speed;
		current_animation = &downftumble;

	}
	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
	{
		position.x += speed;
		current_animation = &downbtumble;
	}

	if (App->input->keyboard[SDL_SCANCODE_Z] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT){

		current_animation = &shootdown[Looking_at];
	}

	if (App->input->keyboard[SDL_SCANCODE_Z] == KEY_STATE::KEY_DOWN && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_IDLE)
	{
		App->particles->AddParticle(App->particles->laser, position.x, position.y, COLLIDER_PLAYER_SHOT);
		current_animation = &shoot[Looking_at];
	}
	if (App->input->keyboard[SDL_SCANCODE_Z] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &shootdown[Looking_at];
	}

	if (App->input->keyboard[SDL_SCANCODE_Z] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &shootdown[Looking_at];
	}

	if (App->input->keyboard[SDL_SCANCODE_Z] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_IDLE)
	{
		position.x += speed;
		current_animation = &shoot[Looking_at];
	}

	if (App->input->keyboard[SDL_SCANCODE_Z] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_IDLE)
	{
		position.x -= speed;
		current_animation = &shoot[Looking_at];
	}

	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_Z] == KEY_STATE::KEY_IDLE)
	{
		current_animation = &down[Looking_at];
	}

	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_IDLE)
	{
		player_coll->SetPos(position.x + 8, position.y);
	}
	else if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_IDLE)
	{
		player_coll->SetPos(position.x + 4, position.y);
	}
	else if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
	{
		player_coll->SetPos(position.x, position.y + 20);
	}
	else
		player_coll->SetPos(position.x, position.y);

	// Draw everything --------------------------------------
	App->render->Blit(graphics, position.x + xcorrection, position.y + ycorrection, &(current_animation->GetCurrentFrame()));

	return UPDATE_CONTINUE;
}
