#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer()
{
	cowboy.x = 10;
	cowboy.y = 0;
	cowboy.w = 47;
	cowboy.h = 64;
	position.x = 120;
	position.y = 210;

	// idle animation (arcade sprite sheet)
	idle.PushBack({ 266, 4, 24, 62 });


	// walk forward animation (arcade sprite sheet)
	//forward.frames.PushBack({9, 136, 53, 83});
	forward.PushBack({ 66, 225, 35, 59 });
	forward.PushBack({ 107, 226, 35, 60 });
	forward.PushBack({ 147, 227, 41, 61 });
	forward.PushBack({ 198, 227, 32, 61 });
	forward.PushBack({ 234, 227, 31, 61 });
	forward.PushBack({ 277, 230, 41, 61 });
	forward.speed = 0.3f;

	//_________________________________________//

	backward.PushBack({ 563, 343, 41, 60 });
	backward.PushBack({ 615, 340, 33, 62 });
	backward.PushBack({ 651, 340, 33, 61 });
	backward.PushBack({ 693, 340, 41, 62 });
	backward.PushBack({ 741, 340, 34, 61 });
	backward.PushBack({ 780, 340, 35, 61 });
	backward.speed = 0.3f;

	down.PushBack({ 583, 18, 28, 47 });





	shoot.PushBack({ 264, 75, 27, 68 });
	shoot.PushBack({ 259, 149, 30, 66 });
	shoot.speed = 0.1f;
	
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("Character.png"); // arcade version
	pigs = App->textures->Load("Pigs.png");
	return ret;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	Animation* current_animation = &idle;

	int speed = 2;

	if (App->input->keyboard[SDL_SCANCODE_S] == 0){
		if (App->input->keyboard[SDL_SCANCODE_D] == 1)
		{
			current_animation = &forward;
			position.x += speed;
		}
		if (App->input->keyboard[SDL_SCANCODE_A] == 1)
		{
			current_animation = &backward;
			position.x -= speed;
		}
		if (App->input->keyboard[SDL_SCANCODE_L] == 1)
		{
			current_animation = &shoot;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_S] == 1)
	{
		current_animation = &down;
	}



	SDL_Rect r = current_animation->GetCurrentFrame();
	
	App->render->Blit(graphics, position.x, position.y - r.h, &r);
	App->render->Blit(pigs, 300, 180 - r.h, &r);

	return UPDATE_CONTINUE;
}