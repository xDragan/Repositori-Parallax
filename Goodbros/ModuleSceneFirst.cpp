#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleSceneFirst.h"
#include "ModuleAim.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneFirst::ModuleSceneFirst()
{}

ModuleSceneFirst::~ModuleSceneFirst()
{}

// Load assets
bool ModuleSceneFirst::Start()
{
	LOG("Loading space scene");
	
	background = App->textures->Load("bloodbros/level1.png");

	App->player->Enable();
	App->particles->Enable();
	App->collision->Enable();
	App->aim->Enable();
	
	// Colliders ---
	App->collision->AddCollider({0, 224, 3930, 16}, COLLIDER_WALL);

	// TODO 1: Add colliders for the first columns of the level

	return true;
}

// UnLoad assets
bool ModuleSceneFirst::CleanUp()
{
	LOG("Unloading space scene");

 	App->textures->Unload(background);
	App->player->Disable();
	App->collision->Disable();
	App->particles->Disable();
	App->aim->Disable();
	
	return true;
}

// Update: draw background
update_status ModuleSceneFirst::Update()
{
	// Move camera forward -----------------------------
	int scroll_speed = 0;

	App->player->position.x += 0;
	App->render->camera.x -= 0;
	

	// Draw everything --------------------------------------
	App->render->Blit(background, 0, 0, NULL);
	
	return UPDATE_CONTINUE;
}