#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleSceneSpace.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneSpace::ModuleSceneSpace()
{}

ModuleSceneSpace::~ModuleSceneSpace()
{}

// Load assets
bool ModuleSceneSpace::Start()
{
	LOG("Loading space scene");
	
	background = App->textures->Load("bloodbros/level1.png");

	App->player->Enable();
	App->particles->Enable();
	App->collision->Enable();
	
	// Colliders ---
	App->collision->AddCollider({0, 224, 3930, 16}, COLLIDER_WALL);

	// TODO 1: Add colliders for the first columns of the level

	return true;
}

// UnLoad assets
bool ModuleSceneSpace::CleanUp()
{
	LOG("Unloading space scene");

 	App->textures->Unload(background);
	App->player->Disable();
	App->collision->Disable();
	App->particles->Disable();
	
	return true;
}

// Update: draw background
update_status ModuleSceneSpace::Update()
{
	// Move camera forward -----------------------------
	int scroll_speed = 0;

	App->player->position.x += 0;
	App->render->camera.x -= 0;
	

	// Draw everything --------------------------------------
	App->render->Blit(background, 0, 0, NULL);
	
	return UPDATE_CONTINUE;
}