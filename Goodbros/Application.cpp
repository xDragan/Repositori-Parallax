#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleSceneFirst.h"
#include "ModuleScenePreStage.h"
#include "ModuleSceneWin.h"
#include "ModuleSceneIntro.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleParticles.h"
#include "ModuleAim.h"
#include "ModuleAudio.h"
#include "ModuleEnemies.h"
#include "ModuleStructures.h"
#include "ModuleUI.h"
#include "ModuleText.h"

Application::Application()
{
	int i = 0;
	modules[i++] = window = new ModuleWindow();
	modules[i++] = render = new ModuleRender();
	modules[i++] = input = new ModuleInput();
	modules[i++] = textures = new ModuleTextures();
	modules[i++] = scene_intro = new ModuleSceneIntro();
	modules[i++] = scene_prestage = new ModuleScenePreStage();
	modules[i++] = scene_space = new ModuleSceneFirst();
	modules[i++] = scene_win = new ModuleSceneWin();
	modules[i++] = structuresback = new ModuleStructures();
	modules[i++] = structuresmiddle = new ModuleStructures();
	modules[i++] = smoke = new ModuleParticles();
	modules[i++] = enemies = new ModuleEnemies();
	modules[i++] = barrelroll = new ModuleEnemies();
	modules[i++] = structuresfront = new ModuleStructures();
	modules[i++] = aim = new ModuleAim();
	modules[i++] = points = new ModuleEnemies();
	modules[i++] = particles = new ModuleParticles();
	modules[i++] = player = new ModulePlayer();
	modules[i++] = UserUI = new ModuleUI();
	modules[i++] = text = new ModuleText();
	modules[i++] = collision = new ModuleCollision();
	modules[i++] = fade = new ModuleFadeToBlack();
	modules[i++] = audio = new ModuleAudio();

}	

Application::~Application()
{
	for(int i = NUM_MODULES - 1; i >= 0; --i)
		delete modules[i];
}

bool Application::Init()
{
	bool ret = true;

	// Deactivate modules here ----
	scene_space->Disable();
	scene_prestage->Disable();
	scene_win->Disable();
	player->Disable();
	collision->Disable();
	UserUI->Disable();
	// ----------------------------

	for(int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->Init();

	for(int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Start() : true;

	return ret;
}

update_status Application::Update()
{
	update_status ret = UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PreUpdate() : UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Update() : UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PostUpdate() : UPDATE_CONTINUE;

	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;

	for(int i = NUM_MODULES - 1; i >= 0 && ret == true; --i)
		ret = modules[i]->CleanUp();

	return ret;
}