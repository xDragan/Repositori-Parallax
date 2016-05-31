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
#include "ModuleUI.h"
#include "ModuleEnemies.h"
#include "ModuleSceneFirst.h"

#include "SDL/include/SDL_timer.h"

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

	die.PushBack({ 1025, 187, 52, 70 });
	die.PushBack({ 1077, 187, 52, 70 });
	die.PushBack({ 1129, 187, 52, 70 });
	die.PushBack({ 1180, 187, 52, 70 });
	die.PushBack({ 1233, 187, 52, 70 });
	die.PushBack({ 1286, 187, 53, 70 });
	die.speed = 0.07f;
	die.loop = false;

	staydied.PushBack({ 1233, 187, 52, 70 });
	staydied.PushBack({ 1286, 187, 53, 70 });
	staydied.PushBack({ 1233, 187, 52, 70 });
	staydied.PushBack({ 1233, 187, 52, 70 });
	staydied.PushBack({ 1286, 187, 53, 70 });
	staydied.PushBack({ 1233, 187, 52, 70 });
	staydied.PushBack({ 1286, 187, 53, 70 });
	staydied.PushBack({ 1233, 187, 52, 70 });
	staydied.PushBack({ 1286, 187, 53, 70 });
	staydied.PushBack({ 1233, 187, 52, 70 });
	staydied.PushBack({ 1286, 187, 53, 70 });
	staydied.PushBack({ 1233, 187, 52, 70 });
	staydied.PushBack({ 1286, 187, 53, 70 });
	staydied.PushBack({ 1233, 187, 52, 70 });
	staydied.PushBack({ 1286, 187, 53, 70 });
	staydied.PushBack({ 1233, 187, 52, 70 });
	staydied.PushBack({ 1286, 187, 53, 70 });
	staydied.PushBack({ 1233, 187, 52, 70 });
	staydied.PushBack({ 1286, 187, 53, 70 });
	staydied.PushBack({ 1233, 187, 52, 70 });
	staydied.PushBack({ 1286, 187, 53, 70 });
	staydied.PushBack({ 1233, 187, 52, 70 });
	staydied.loop = true;
	staydied.speed = 0.03;

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
	windance.speed = 0.03;
	windance.loop = false;

	//GOD MODE

	// idle animation //
	gidle[far_left].PushBack({ 86, 1057, 60, 69 });
	gidle[Middle_left].PushBack({ 146, 1057, 51, 69 });
	gidle[near_left].PushBack({ 203, 1057, 45, 69 });
	gidle[middle].PushBack({ 254, 1057, 45, 69 });
	gidle[near_right].PushBack({ 305, 1057, 45, 69 });
	gidle[middle_right].PushBack({ 357, 1057, 56, 69 });
	gidle[far_right].PushBack({ 409, 1057, 53, 69 });

	gdown[far_left].PushBack({ 501, 1057, 56, 69 });
	gdown[Middle_left].PushBack({ 561, 1057, 47, 69 });
	gdown[near_left].PushBack({ 615, 1057, 45, 69 });
	gdown[middle].PushBack({ 668, 1057, 45, 69 });
	gdown[near_right].PushBack({ 719, 1057, 45, 69 });
	gdown[middle_right].PushBack({ 774, 1057, 52, 69 });
	gdown[far_right].PushBack({ 826, 1057, 54, 69 });

	//Shoot animations //
	gshoot[far_left].PushBack({ 86, 1187, 60, 69 });
	gshoot[far_left].PushBack({ 86, 1057, 60, 69 });
	gshoot[far_left].PushBack({ 86, 1314, 60, 69 });
	gshoot[Middle_left].PushBack({ 146, 1187, 43, 73 });
	gshoot[Middle_left].PushBack({ 146, 1057, 51, 73 });
	gshoot[Middle_left].PushBack({ 146, 1314, 43, 73 });
	gshoot[near_left].PushBack({ 203, 1187, 38, 70 });
	gshoot[near_left].PushBack({ 203, 1057, 45, 69 });
	gshoot[near_left].PushBack({ 203, 1314, 45, 69 });

	gshoot[middle].PushBack({ 254, 1187, 45, 69 });
	gshoot[middle].PushBack({ 254, 1057, 45, 69 });
	gshoot[middle].PushBack({ 254, 1314, 45, 69 });

	gshoot[near_right].PushBack({ 305, 1187, 45, 69 });
	gshoot[near_right].PushBack({ 305, 1057, 45, 69 });
	gshoot[near_right].PushBack({ 305, 1314, 45, 69 });
	gshoot[middle_right].PushBack({ 357, 1187, 56, 69 });
	gshoot[middle_right].PushBack({ 357, 1057, 56, 69 });
	gshoot[middle_right].PushBack({ 357, 1314, 56, 69 });
	gshoot[far_right].PushBack({ 413, 1187, 53, 69 });
	gshoot[far_right].PushBack({ 413, 1057, 53, 69 });
	gshoot[far_right].PushBack({ 413, 1314, 53, 69 });

	//shot speed
	gshoot[far_left].speed = 0.22f;
	gshoot[Middle_left].speed = 0.22f;
	gshoot[near_left].speed = 0.22f;
	gshoot[middle].speed = 0.22f;
	gshoot[near_right].speed = 0.22f;
	gshoot[middle_right].speed = 0.22f;
	gshoot[far_right].speed = 0.22f;

	//Shoot Seated Animation//
	gshootdown[far_left].PushBack({ 501, 1187, 56, 70 });
	gshootdown[far_left].PushBack({ 501, 1057, 56, 69 });
	gshootdown[far_left].PushBack({ 501, 1314, 56, 69 });
	gshootdown[Middle_left].PushBack({ 561, 1187, 47, 69 });
	gshootdown[Middle_left].PushBack({ 561, 1057, 47, 69 });
	gshootdown[Middle_left].PushBack({ 561, 1314, 47, 69 });
	gshootdown[near_left].PushBack({ 615, 1187, 45, 69 });
	gshootdown[near_left].PushBack({ 615, 1057, 45, 69 });
	gshootdown[near_left].PushBack({ 615, 1314, 45, 69 });

	gshootdown[middle].PushBack({ 668, 1187, 45, 69 });
	gshootdown[middle].PushBack({ 668, 1057, 45, 69 });
	gshootdown[middle].PushBack({ 668, 1314, 45, 69 });

	gshootdown[near_right].PushBack({ 719, 1187, 45, 69 });
	gshootdown[near_right].PushBack({ 719, 1057, 45, 69 });
	gshootdown[near_right].PushBack({ 719, 1314, 45, 69 });
	gshootdown[middle_right].PushBack({ 774, 1187, 52, 69 });
	gshootdown[middle_right].PushBack({ 774, 1057, 52, 69 });
	gshootdown[middle_right].PushBack({ 774, 1314, 52, 69 });
	gshootdown[far_right].PushBack({ 826, 1187, 54, 69 });
	gshootdown[far_right].PushBack({ 826, 1057, 54, 69 });
	gshootdown[far_right].PushBack({ 826, 1314, 54, 69 });

	//shot  seated speed
	gshootdown[far_left].speed = 0.20f;
	gshootdown[Middle_left].speed = 0.20f;
	gshootdown[near_left].speed = 0.20f;
	gshootdown[middle].speed = 0.20f;
	gshootdown[near_right].speed = 0.20f;
	gshootdown[middle_right].speed = 0.20f;
	gshootdown[far_right].speed = 0.20f;

	// walk forward animation//	
	gforward.PushBack({ 96, 1438, 46, 60 });
	gforward.PushBack({ 152, 1438, 46, 60 });
	gforward.PushBack({ 203, 1438, 46, 60 });
	gforward.PushBack({ 255, 1438, 46, 60 });
	gforward.PushBack({ 306, 1438, 46, 60 });
	gforward.PushBack({ 357, 1438, 46, 60 });
	gforward.speed = 0.2f;

	// frontward tumble animation//
	gftumble.PushBack({ 511, 1436, 46, 62 });
	gftumble.PushBack({ 564, 1436, 97, 70 });
	gftumble.PushBack({ 668, 1436, 46, 62 });
	gftumble.PushBack({ 720, 1436, 46, 62 });
	gftumble.PushBack({ 774, 1436, 46, 62 });
	gftumble.PushBack({ 825, 1436, 46, 62 });
	gftumble.PushBack({ 875, 1436, 46, 62 });
	gftumble.PushBack({ 928, 1436, 46, 62 });
	gftumble.loop = true;
	gftumble.speed = 0.15f;

	//down frontward tumble animation//
	gdownftumble.PushBack({ 720, 1436, 46, 62 });
	gdownftumble.PushBack({ 774, 1436, 46, 62 });
	gdownftumble.PushBack({ 825, 1436, 46, 62 });
	gdownftumble.PushBack({ 875, 1436, 46, 62 });
	gdownftumble.PushBack({ 928, 1436, 46, 62 });
	gdownftumble.speed = 0.15f;

	//walk backward animation//
	gbackward.PushBack({ 96, 1508, 46, 60 });
	gbackward.PushBack({ 151, 1508, 46, 60 });
	gbackward.PushBack({ 202, 1508, 46, 60 });
	gbackward.PushBack({ 254, 1508, 46, 60 });
	gbackward.PushBack({ 306, 1508, 46, 60 });
	gbackward.PushBack({ 357, 1508, 46, 60 });
	gbackward.speed = 0.2f;

	//backward tumble animation//
	gbtumble.PushBack({ 928, 1506, 46, 62 });
	gbtumble.PushBack({ 826, 1506, 97, 62 });
	gbtumble.PushBack({ 774, 1506, 46, 62 });
	gbtumble.PushBack({ 720, 1506, 46, 62 });
	gbtumble.PushBack({ 668, 1506, 46, 62 });
	gbtumble.PushBack({ 615, 1506, 46, 62 });
	gbtumble.PushBack({ 564, 1506, 46, 62 });
	gbtumble.PushBack({ 511, 1506, 46, 62 });
	gbtumble.loop = true;
	gbtumble.speed = 0.15f;

	//down backward tumble animation//
	gdownbtumble.PushBack({ 720, 1506, 46, 62 });
	gdownbtumble.PushBack({ 668, 1506, 46, 62 });
	gdownbtumble.PushBack({ 615, 1506, 46, 62 });
	gdownbtumble.PushBack({ 564, 1506, 46, 62 });
	gdownbtumble.PushBack({ 511, 1506, 46, 62 });
	gdownbtumble.speed = 0.15f;

	//win animation// 
	gwin.PushBack({ 1032, 1054, 46, 72 });
	gwin.PushBack({ 1084, 1054, 46, 72 });
	gwin.PushBack({ 1136, 1054, 46, 72 });

	//win dance animation//
	gwindance.PushBack({ 1187, 1054, 46, 72 });
	gwindance.PushBack({ 1240, 1057, 46, 72 });
	gwindance.PushBack({ 1299, 1057, 46, 72 });
	gwindance.PushBack({ 1358, 1057, 46, 72 });
	gwindance.PushBack({ 1032, 1126, 46, 72 });
	gwindance.PushBack({ 1084, 1126, 46, 72 });
	gwindance.PushBack({ 1136, 1126, 46, 72 });
	gwindance.PushBack({ 1187, 1126, 46, 72 });
	gwindance.PushBack({ 1240, 1126, 46, 72 });
	gwindance.PushBack({ 1299, 1126, 46, 72 });
	gwindance.speed = 0.03;
	gwindance.loop = false;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	deathsound.fx = App->audio->LoadFx("bloodbros/Player_death_fx.wav");

	graphics = App->textures->Load("bloodbros/character.png");

	position.x = 120;
	position.y = 150;

	Status = IDLE;

	player_coll = App->collision->AddCollider({ 128, 153, 22, 33 }, COLLIDER_PLAYER);//cowboy collider

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
	if (c_time >= timedying)
	{
		blinkd = !blinkd;
		timedying = c_time + 500;
	}
	if (c_time > dmg_cd)
	{
		player_coll->type = COLLIDER_PLAYER;
	}
	if (win_condition >= 18) Status = WIN;
	if (godmode == true)
	{
		player_coll->type = COLLIDER_NONE;
	}
	if (App->input->keyboard[SDL_SCANCODE_L] == KEY_STATE::KEY_DOWN && Status != DIE && Status != ROLLING && App->UserUI->dynamite > 0)
	{
		App->particles->AddParticle(App->particles->dynamite, position.x, position.y, COLLIDER_DYNAMITE, 0);
		App->UserUI->dynamite--;
	}
	if (App->input->keyboard[SDL_SCANCODE_P] == KEY_STATE::KEY_DOWN && Status != DIE && Status != ROLLING)
	{
		App->particles->AddParticle(App->particles->enemyDynamite, position.x, position.y, COLLIDER_BOMB, 0);
	}
	switch (Status)
	{
	case IDLE:
		if (godmode == true)
		{
			current_animation = &gidle[Looking_at];
		}
		else{
			current_animation = &idle[Looking_at];
		}
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
		if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_IDLE)
		{
			Status = LEFT;
		}
		if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_IDLE)
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
		if (godmode == true)
		{
			current_animation = &gshoot[Looking_at];
		}
		else{
			current_animation = &shoot[Looking_at];
		}
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
		if (App->input->keyboard[SDL_SCANCODE_Z] == KEY_STATE::KEY_UP || App->input->keyboard[SDL_SCANCODE_Z] == KEY_STATE::KEY_IDLE)
		{
			Status = IDLE;
		}
		break;

	case LEFT:
		if (godmode == true)
		{
			current_animation = &gbackward;
		}
		else
		{
			current_animation = &backward;
		}
		player_coll->SetPos(position.x + 8, position.y);

		if (position.x > 0)
		{
			position.x -= speed;

		}
		if (App->input->keyboard[SDL_SCANCODE_C] == KEY_STATE::KEY_DOWN && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
		{
			gbtumble.loops = 0;
			gbtumble.Reset();
			btumble.loops = 0;
			btumble.Reset();
			if (godmode == true){
				current_animation = &gbtumble;
			}
			else{
			current_animation = &btumble;
		}
			Status = ROLLING;
		
		}
		if (App->input->keyboard[SDL_SCANCODE_G] == KEY_STATE::KEY_DOWN)
		{
			godmode = !godmode;
		}
		if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
		{
			Status = IDLE;
		}
		if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
		{
			Status = DOWN;
		}
		if (App->input->keyboard[SDL_SCANCODE_Z] == KEY_STATE::KEY_REPEAT)
		{
			Status = SHOOTING;
		}
		if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_UP || App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_IDLE)
		{
			Status = IDLE;
		}
		break;

	case RIGHT:
		if (godmode == true)
		{
			current_animation = &gforward;
		}
		else{
			current_animation = &forward;
		}
		player_coll->SetPos(position.x + 16, position.y);

		if (position.x < 220)
		{
			position.x += speed;
		}
		if (App->input->keyboard[SDL_SCANCODE_C] == KEY_STATE::KEY_DOWN)
		{

			gftumble.loops = 0;
			gftumble.Reset();
			ftumble.loops = 0;
			ftumble.Reset();
			if (godmode == true){
				current_animation = &gftumble;
			}
			else{
				current_animation = &ftumble;
			}
			Status = ROLLING;
		}
		if (App->input->keyboard[SDL_SCANCODE_G] == KEY_STATE::KEY_DOWN)
		{
			godmode = !godmode;
		}
		if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
		{
			Status = IDLE;
		}
		if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
		{
			Status = DOWN;
		}
		if (App->input->keyboard[SDL_SCANCODE_Z] == KEY_STATE::KEY_REPEAT)
		{
			Status = SHOOTING;
		}
		if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_UP || App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_IDLE)
		{
			Status = IDLE;
		}
		break;

	case DOWN:
		if (godmode == true){
			current_animation = &gdown[Looking_at];
		}
		else{
			current_animation = &down[Looking_at];
		}

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
			gdownftumble.loops = 0;
			gdownftumble.Reset();
			downftumble.loops = 0;
			downftumble.Reset();
			if (godmode == true)
			{
				current_animation = &gdownftumble;
			}
			else
			{
				current_animation = &downftumble;
			}
			Status = ROLLING;
		}
		if (App->input->keyboard[SDL_SCANCODE_C] == KEY_STATE::KEY_DOWN && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
		{
			gdownbtumble.loops = 0;
			gdownbtumble.Reset();
			downbtumble.loops = 0;
			downbtumble.Reset();
			if (godmode == true){
				current_animation = &gdownbtumble;
			}
			else
			{
				current_animation = &downbtumble;
			}
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
		if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_UP || App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_IDLE)
		{
			Status = IDLE;
		}
		break;

	case SHOOTING_DOWN:
		if (godmode == true)
		{
			current_animation = &gshootdown[Looking_at];
		}
		else
		{
			current_animation = &shootdown[Looking_at];
		}
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
		if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_UP || App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_UP)
		{
			Status = IDLE;
		}
		if (App->input->keyboard[SDL_SCANCODE_Z] == KEY_STATE::KEY_UP)
		{
			Status = DOWN;
		}
		if (SDL_GetTicks() > timeout)
		{
			App->audio->PlayFx(App->particles->shot.fx);
			timeout = SDL_GetTicks() + 150;
		}
		break;

	case ROLLING:
		player_coll->type = COLLIDER_NONE;
		
		if (current_animation == &btumble || current_animation == &gbtumble)
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
		if (current_animation == &ftumble || current_animation == &gftumble)
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
		if (current_animation == &downftumble || current_animation == &gdownftumble)
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
		if (current_animation == &downbtumble || current_animation == &gdownbtumble)
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
		break;
		
	case DIE:
		player_coll->type = COLLIDER_NONE;
		current_animation = &die;
		if (played == false)
		{
			App->audio->PlayFx(App->player->deathsound.fx);
			played = true;
		}
		if (current_animation->Finished() == true){
			if (lose == 2){
				current_animation = &staydied;
				loosing = true;
			}
			if (current_animation->Finished() == false){
				if (App->UserUI->credit >= 1 && App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN){
					App->UserUI->score = 0;
					staydied.Reset();
					dmg_cd = SDL_GetTicks() + 3000;
					lose = 0;
					App->points->AddEnemy(ENEMY_TYPES::POINTS, position.x + 50, position.y, 4, NULL);
					App->points->AddEnemy(ENEMY_TYPES::POINTS, position.x + 25, position.y, 2, NULL);
					App->UserUI->done = false;
					loosing = false;
					Status = IDLE;
				}
			}
			else if (current_animation->Finished() == true)
			{
				App->UserUI->score = 0;
				dmg_cd = SDL_GetTicks() + 3000;
				lose++;
				App->UserUI->done = false;
				loosing = false;
				if (lose == 3){
					lost = true;
				}
				Status = IDLE;
			}
		}
		break;
	case WIN:
		player_coll->type = COLLIDER_NONE;
		if (godmode == true)
		{
			current_animation = &gwindance;
		}
		else{
			current_animation = &windance;
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