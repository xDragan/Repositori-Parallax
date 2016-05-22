#include "SDL\include\SDL.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleFadeToBlack.h"
#include "ModulePlayer.h"
#include "ModuleAudio.h"
#include "ModuleAim.h"
#include "ModuleTextures.h"
#include "ModuleSceneFirst.h"

int ModulePlayer::looking_at() const
{
	int distance = (App->aim->position.x + 70 / 2) - (position.x + 80 / 2);
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
	idle[far_left].PushBack({ 86, 57, 60, 69 });
	idle[Middle_left].PushBack({ 146, 57, 51, 69 });
	idle[near_left].PushBack({ 203, 57, 45, 69 });
	idle[middle].PushBack({ 254, 57, 45, 69 });
	idle[near_right].PushBack({ 305, 57, 45, 69 });
	idle[middle_right].PushBack({ 357, 57, 56, 69 });
	idle[far_right].PushBack({ 409, 57, 53, 69 });

	down[far_left].PushBack({ 501, 57, 56, 69 });
	down[Middle_left].PushBack({ 561, 57, 47, 69 });
	down[near_left].PushBack({ 615, 57, 45, 69 });
	down[middle].PushBack({ 668, 57, 45, 69 });
	down[near_right].PushBack({ 719, 57, 45, 69 });
	down[middle_right].PushBack({ 774, 57, 52, 69 });
	down[far_right].PushBack({ 826, 57, 54, 69 });

	//Shoot animations //
	shoot[far_left].PushBack({ 86, 187, 60, 69 });
	shoot[far_left].PushBack({ 86, 57, 60, 69 });
	shoot[far_left].PushBack({ 86, 314, 60, 69 });
	shoot[Middle_left].PushBack({ 146, 187, 43, 73 });
	shoot[Middle_left].PushBack({ 146, 57, 51, 73 });
	shoot[Middle_left].PushBack({ 146, 314, 43, 73 });
	shoot[near_left].PushBack({ 203, 187, 38, 70 });
	shoot[near_left].PushBack({ 203, 57, 45, 69 });
	shoot[near_left].PushBack({ 203, 314, 45, 69 });

	shoot[middle].PushBack({ 254, 187, 45, 69 });
	shoot[middle].PushBack({ 254, 57, 45, 69 });
	shoot[middle].PushBack({ 254, 314, 45, 69 });

	shoot[near_right].PushBack({ 305, 187, 45, 69 });
	shoot[near_right].PushBack({ 305, 57, 45, 69 });
	shoot[near_right].PushBack({ 305, 314, 45, 69 });
	shoot[middle_right].PushBack({ 357, 187, 56, 69 });
	shoot[middle_right].PushBack({ 357, 57, 56, 69 });
	shoot[middle_right].PushBack({ 357, 314, 56, 69 });
	shoot[far_right].PushBack({ 413, 187, 53, 69 });
	shoot[far_right].PushBack({ 413, 57, 53, 69 });
	shoot[far_right].PushBack({ 413, 314, 53, 69 });

	//shot speed
	shoot[far_left].speed = 0.22f;
	shoot[Middle_left].speed = 0.22f;
	shoot[near_left].speed = 0.22f;
	shoot[middle].speed = 0.22f;
	shoot[near_right].speed = 0.22f;
	shoot[middle_right].speed = 0.22f;
	shoot[far_right].speed = 0.22f;

	//Shoot Seated Animation//
	shootdown[far_left].PushBack({ 501, 187, 56, 70 });
	shootdown[far_left].PushBack({ 501, 57, 56, 69 });
	shootdown[far_left].PushBack({ 501, 314, 56, 69 });
	shootdown[Middle_left].PushBack({ 561, 187, 47, 69 });
	shootdown[Middle_left].PushBack({ 561, 57, 47, 69 });
	shootdown[Middle_left].PushBack({ 561, 314, 47, 69 });
	shootdown[near_left].PushBack({ 615, 187, 45, 69 });
	shootdown[near_left].PushBack({ 615, 57, 45, 69 });
	shootdown[near_left].PushBack({ 615, 314, 45, 69 });

	shootdown[middle].PushBack({ 668, 187, 45, 69 });
	shootdown[middle].PushBack({ 668, 57, 45, 69 });
	shootdown[middle].PushBack({ 668, 314, 45, 69 });

	shootdown[near_right].PushBack({ 719, 187, 45, 69 });
	shootdown[near_right].PushBack({ 719, 57, 45, 69 });
	shootdown[near_right].PushBack({ 719, 314, 45, 69 });
	shootdown[middle_right].PushBack({ 774, 187, 52, 69 });
	shootdown[middle_right].PushBack({ 774, 57, 52, 69 });
	shootdown[middle_right].PushBack({ 774, 314, 52, 69 });
	shootdown[far_right].PushBack({ 826, 187, 54, 69 });
	shootdown[far_right].PushBack({ 826, 57, 54, 69 });
	shootdown[far_right].PushBack({ 826, 314, 54, 69 });

	//shot  seated speed
	shootdown[far_left].speed = 0.20f;
	shootdown[Middle_left].speed = 0.20f;
	shootdown[near_left].speed = 0.20f;
	shootdown[middle].speed = 0.20f;
	shootdown[near_right].speed = 0.20f;
	shootdown[middle_right].speed = 0.20f;
	shootdown[far_right].speed = 0.20f;

	// walk forward animation//	
	forward.PushBack({ 96, 438, 46, 60 });
	forward.PushBack({ 152, 438, 46, 60 });
	forward.PushBack({ 203, 438, 46, 60 });
	forward.PushBack({ 255, 438, 46, 60 });
	forward.PushBack({ 306, 438, 46, 60 });
	forward.PushBack({ 357, 438, 46, 60 });
	forward.speed = 0.2f;

	// frontward tumble animation//
	ftumble.PushBack({ 511, 436, 46, 62 });
	ftumble.PushBack({ 564, 436, 97, 70 });
	ftumble.PushBack({ 668, 436, 46, 62 });
	ftumble.PushBack({ 720, 436, 46, 62 });
	ftumble.PushBack({ 774, 436, 46, 62 });
	ftumble.PushBack({ 825, 436, 46, 62 });
	ftumble.PushBack({ 875, 436, 46, 62 });
	ftumble.PushBack({ 928, 436, 46, 62 });
	ftumble.loop = true;
	ftumble.speed = 0.15f;

	//down frontward tumble animation//
	downftumble.PushBack({ 720, 436, 46, 62 });
	downftumble.PushBack({ 774, 436, 46, 62 });
	downftumble.PushBack({ 825, 436, 46, 62 });
	downftumble.PushBack({ 875, 436, 46, 62 });
	downftumble.PushBack({ 928, 436, 46, 62 });
	downftumble.speed = 0.15f;

	//walk backward animation//
	backward.PushBack({ 96, 508, 46, 60 });
	backward.PushBack({ 151, 508, 46, 60 });
	backward.PushBack({ 202, 508, 46, 60 });
	backward.PushBack({ 254, 508, 46, 60 });
	backward.PushBack({ 306, 508, 46, 60 });
	backward.PushBack({ 357, 508, 46, 60 });
	backward.speed = 0.2f;

	//backward tumble animation//
	btumble.PushBack({ 928, 506, 46, 62 });
	btumble.PushBack({ 826, 506, 97, 62 });
	btumble.PushBack({ 774, 506, 46, 62 });
	btumble.PushBack({ 720, 506, 46, 62 });
	btumble.PushBack({ 668, 506, 46, 62 });
	btumble.PushBack({ 615, 506, 46, 62 });
	btumble.PushBack({ 564, 506, 46, 62 });
	btumble.PushBack({ 511, 506, 46, 62 });
	btumble.loop = true;
	btumble.speed = 0.15f;

	//down backward tumble animation//
	downbtumble.PushBack({ 720, 506, 46, 62 });
	downbtumble.PushBack({ 668, 506, 46, 62 });
	downbtumble.PushBack({ 615, 506, 46, 62 });
	downbtumble.PushBack({ 564, 506, 46, 62 });
	downbtumble.PushBack({ 511, 506, 46, 62 });
	downbtumble.speed = 0.15f;

	die.PushBack({ 1025, 187, 52, 70});
	die.PushBack({ 1077, 187, 52, 70}); 
	die.PushBack({ 1129, 187, 52, 70});
	die.PushBack({1180 , 187, 52, 70});
	die.PushBack({ 1233, 187, 52, 70});
	die.PushBack({ 1286, 187, 53, 70 });
	die.speed = 0.07f;
	die.loop = false;

	//win animation// 
	win.PushBack({ 1032, 54, 46, 72 });
	win.PushBack({ 1084, 54, 46, 72 });
	win.PushBack({ 1136, 54, 46, 72 });

	//win dance animation//
	windance.PushBack({ 1187, 54, 46, 72 });
	windance.PushBack({ 1240, 57, 46, 72 });
	windance.PushBack({ 1299, 57, 46, 72 });
	windance.PushBack({ 1358, 57, 46, 72 });
	windance.PushBack({ 1032, 126, 46, 72 });
	windance.PushBack({ 1084, 126, 46, 72 });
	windance.PushBack({ 1136, 126, 46, 72 });
	windance.PushBack({ 1187, 126, 46, 72 });
	windance.PushBack({ 1240, 126, 46, 72 });
	windance.PushBack({ 1299, 126, 46, 72 });
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

	Status = IDLE;

	player_coll = App->collision->AddCollider({ 128, 153, 22, 27 }, COLLIDER_PLAYER);//cowboy collider

	current_animation = &idle[0];

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
	speed = 1.8;
	AimSpeed = 2;
	c_time = SDL_GetTicks();
	Looking_at = looking_at();

	if (c_time >= blink_t)
	{
		blink = !blink;
		blink_t = c_time + 100;
	}
	if (c_time > dmg_cd)
	{
		player_coll->type = COLLIDER_PLAYER;
	}
	if (godmode == true)
	{
		player_coll->type = COLLIDER_NONE;
	}
	
	switch (Status)
	{
	case IDLE:
		current_animation = &idle[Looking_at];

		if (looking_at() == far_left)
		{
			player_coll->SetPos(position.x + 20, position.y + 8);
		}
		if (looking_at() == Middle_left)
		{
			player_coll->SetPos(position.x + 18, position.y + 8);
		}
		if (looking_at() == near_left)
		{
			player_coll->SetPos(position.x + 10, position.y + 8);
		}
		if (looking_at() == middle)
		{
			player_coll->SetPos(position.x + 15, position.y + 8);
		}
		if (looking_at() == near_right)
		{
			player_coll->SetPos(position.x + 15, position.y + 8);
		}
		if (looking_at() == middle_right)
		{
			player_coll->SetPos(position.x + 15, position.y + 8);
		}
		if (looking_at() == far_right)
		{
			player_coll->SetPos(position.x + 6, position.y + 8);
		}
		if (App->input->keyboard[SDL_SCANCODE_G] == KEY_STATE::KEY_DOWN)
		{
			godmode = !godmode;
		}
		if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
		{
			Status = LEFT;
		}
		if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
		{
			Status = RIGHT;
		}
		if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
		{
			Status = DOWN;
		}
		if (App->input->keyboard[SDL_SCANCODE_Z] == KEY_STATE::KEY_REPEAT)
		{
			Status = SHOOTING;
		}
		break;

	case SHOOTING:
		current_animation = &shoot[Looking_at];

		if (looking_at() == far_left)
		{
			player_coll->SetPos(position.x + 20, position.y + 8);
		}
		if (looking_at() == Middle_left)
		{
			player_coll->SetPos(position.x + 18, position.y + 8);
		}
		if (looking_at() == near_left)
		{
			player_coll->SetPos(position.x + 10, position.y + 8);
		}
		if (looking_at() == middle)
		{
			player_coll->SetPos(position.x + 15, position.y + 8);
		}
		if (looking_at() == near_right)
		{
			player_coll->SetPos(position.x + 15, position.y + 8);
		}
		if (looking_at() == middle_right)
		{
			player_coll->SetPos(position.x + 15, position.y + 8);
		}
		if (looking_at() == far_right)
		{
			player_coll->SetPos(position.x + 6, position.y + 8);
		}
		if (SDL_GetTicks() > timeout)
		{
			App->audio->PlayFx(App->particles->shot.fx);
			timeout = SDL_GetTicks() + 150;
		}
		if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
		{
			Status = SHOOTING_DOWN;
		}
		if (App->input->keyboard[SDL_SCANCODE_Z] == KEY_STATE::KEY_UP)
		{
			Status = IDLE;
		}
		break;

	case LEFT:
		current_animation = &backward;
		player_coll->SetPos(position.x + 8, position.y);

		if (position.x > 0)
		{
			position.x -= speed;

		}
		if (App->input->keyboard[SDL_SCANCODE_C] == KEY_STATE::KEY_DOWN && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
		{
			btumble.loops = 0;
			btumble.Reset();
			current_animation = &btumble;
			Status = ROLLING;
		}
		if (App->input->keyboard[SDL_SCANCODE_G] == KEY_STATE::KEY_DOWN)
		{
			godmode = !godmode;
		}
		if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
		{
			Status = DOWN;
		}
		if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_UP)
		{
			Status = IDLE;
		}
		break;

	case RIGHT:
		current_animation = &forward;
		player_coll->SetPos(position.x + 16, position.y);

		if (position.x < 220)
		{
			position.x += speed;
		}
		if (App->input->keyboard[SDL_SCANCODE_C] == KEY_STATE::KEY_DOWN)
		{
			ftumble.loops = 0;
			ftumble.Reset();
			current_animation = &ftumble;
			Status = ROLLING;
		}
		if (App->input->keyboard[SDL_SCANCODE_G] == KEY_STATE::KEY_DOWN)
		{
			godmode = !godmode;
		}
		if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
		{
			Status = DOWN;
		}
		if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_UP)
		{
			Status = IDLE;
		}
		break;

	case DOWN:
		current_animation = &down[Looking_at];

		if (looking_at() == far_left)
		{
			player_coll->SetPos(position.x + 20, position.y + 24);
		}
		if (looking_at() == Middle_left)
		{
			player_coll->SetPos(position.x + 18, position.y + 24);
		}
		if (looking_at() == near_left)
		{
			player_coll->SetPos(position.x + 10, position.y + 24);
		}
		if (looking_at() == middle)
		{
			player_coll->SetPos(position.x + 14, position.y + 24);
		}
		if (looking_at() == near_right)
		{
			player_coll->SetPos(position.x + 15, position.y + 24);
		}
		if (looking_at() == middle_right)
		{
			player_coll->SetPos(position.x + 12, position.y + 24);
		}
		if (looking_at() == far_right)
		{
			player_coll->SetPos(position.x + 12, position.y + 24);
		}
		if (App->input->keyboard[SDL_SCANCODE_C] == KEY_STATE::KEY_DOWN && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
		{
			downftumble.loops = 0;
			downftumble.Reset();
			current_animation = &downftumble;
			Status = ROLLING;
		}
		if (App->input->keyboard[SDL_SCANCODE_C] == KEY_STATE::KEY_DOWN && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
		{
			downbtumble.loops = 0;
			downbtumble.Reset();
			current_animation = &downbtumble;
			Status = ROLLING;
		}
		if (App->input->keyboard[SDL_SCANCODE_G] == KEY_STATE::KEY_DOWN)
		{
			godmode = !godmode;
		}
		if (App->input->keyboard[SDL_SCANCODE_Z] == KEY_STATE::KEY_REPEAT)
		{
			Status = SHOOTING_DOWN;
		}
		if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_UP)
		{
			Status = IDLE;
		}
		break;

	case SHOOTING_DOWN:
		current_animation = &shootdown[Looking_at];

		if (looking_at() == far_left)
		{
			player_coll->SetPos(position.x + 20, position.y + 24);
		}
		if (looking_at() == Middle_left)
		{
			player_coll->SetPos(position.x + 18, position.y + 24);
		}
		if (looking_at() == near_left)
		{
			player_coll->SetPos(position.x + 10, position.y + 24);
		}
		if (looking_at() == middle)
		{
			player_coll->SetPos(position.x + 14, position.y + 24);
		}
		if (looking_at() == near_right)
		{
			player_coll->SetPos(position.x + 15, position.y + 24);
		}
		if (looking_at() == middle_right)
		{
			player_coll->SetPos(position.x + 12, position.y + 24);
		}
		if (looking_at() == far_right)
		{
			player_coll->SetPos(position.x + 12, position.y + 24);
		}
		if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_UP)
		{
			Status = IDLE;
		}
		if (SDL_GetTicks() > timeout)
		{
			App->audio->PlayFx(App->particles->shot.fx);
			timeout = SDL_GetTicks() + 150;
		}
		break;

	case ROLLING:
		player_coll->type = COLLIDER_NONE;

		if (current_animation == &btumble)
		{
			if (position.x < 5)
			{
				speed = 0;
			}
			else
			{
				position.x -= 1.5;

			}
			if (current_animation->Finished() == true)
			{
				Status = IDLE;
				break;
			}
		}
		if (current_animation == &ftumble)
		{
			current_animation = &ftumble;

			if (current_animation == &ftumble)
			{
				if (position.x > 210)
				{
					speed = 0;
				}
				else
				{
					position.x += 1.5;
				}
				if (current_animation->Finished() == true)
				{
					Status = IDLE;
					break;
				}
			}
		}
		if (current_animation == &downftumble)
		{
			current_animation = &downftumble;

			if (current_animation == &downftumble)
			{
				if (position.x > 210)
				{
					speed = 0;
				}
				else
				{
					position.x += 1;
				}
				if (current_animation->Finished() == true)
				{
					Status = IDLE;
					break;
				}
			}
		}
		if (current_animation == &downbtumble)
		{
			current_animation = &downbtumble;

			if (current_animation == &downbtumble)
			{
				if (position.x < 5)
				{
					speed = 0;
				}
				else
				{
					position.x -= 1;
				}
				if (current_animation->Finished() == true)
				{
					Status = IDLE;
					break;
				}
			}
		}
		break;
		
	case DIE:
		player_coll->type = COLLIDER_NONE;
		current_animation = &die;

		if (current_animation->Finished() == true)
		{
			dmg_cd = SDL_GetTicks() + 3000;
			App->player->lose++;
			Status = IDLE;
		}
		break;
	}

	// Draw everything
	if (c_time >= dmg_cd || blink)
	{
		App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));
	}
	else
	{
		current_animation->GetCurrentFrame();
	}

	return UPDATE_CONTINUE;
}