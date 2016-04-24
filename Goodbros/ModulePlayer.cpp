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
int const ModulePlayer::portion_calculate()
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

	// idle animation (arcade sprite sheet)

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

	player_coll=App->collision->AddCollider({ 128, 153, 22, 27 }, COLLIDER_PLAYER);//cowboy collider
	
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
	int AimSpeed = 3;
	int xcorrection = 0;
	int ycorrection = 0;
	int screen_portion = portion_calculate();
	current_animation = &idle[screen_portion];

	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT&& position.x > 8)
	{
		current_animation = &backward;
		position.x -= speed;
		if (Aimposition.x >= 0){
			Aimposition.x -= AimSpeed;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT&& position.x < 228)
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

	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_C] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &downftumble;

	}
	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_C] == KEY_STATE::KEY_REPEAT &&App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &downbtumble;

	}
	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_C] == KEY_STATE::KEY_IDLE)
	{
		position.x += speed;
	}
	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_C] == KEY_STATE::KEY_IDLE)
	{
		position.x -= speed;
	}



	if (App->input->keyboard[SDL_SCANCODE_Z] == KEY_STATE::KEY_REPEAT){

	current_animation = &shoot;

	}
	if (App->input->keyboard[SDL_SCANCODE_Z] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
	{
		position.x -= speed;
		current_animation = &shoot;
	}

	if (App->input->keyboard[SDL_SCANCODE_Z] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
	{
		position.x += speed;
		current_animation = &shoot;
	}

	if (App->input->keyboard[SDL_SCANCODE_Z] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
	{
		position.x += speed;
		current_animation = &shoot;
	}

	if (App->input->keyboard[SDL_SCANCODE_Z] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
	{
		position.x -= speed;
		current_animation = &shoot;
	}




	if(App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
	{
		if(current_animation != &down[screen_portion])
		{
			
			current_animation = &down[screen_portion];
		}
	}
	/*if(App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
		&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE && App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE && App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE)
		current_animation = &idle;*/

	player_coll->SetPos(position.x, position.y);
	// Draw everything --------------------------------------
	App->render->Blit(graphics, position.x + xcorrection, position.y + ycorrection, &(current_animation->GetCurrentFrame()));

	return UPDATE_CONTINUE;
}

// TODO 4: Detect collision with a wall. If so, go back to intro screen.
