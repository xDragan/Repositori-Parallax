#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "Audio0.h"
#include "Audio1.h"
#include "Audio2.h"
#include "Audio3.h"
#include "ModuleFadeToBlack.h"
#include "ModuleLevel1.h"
#include"ModuleLevel2.h"
#include "ModuleLevel3.h"
#include "ModuleTittleScreen.h"
#include "ModuleCollision.h"

Application::Application()
{
	modules[0] = window = new ModuleWindow();
	modules[1] = render = new ModuleRender();
	modules[2] = input = new ModuleInput();
	modules[3] = textures = new ModuleTextures();
	modules[4] = audio0 = new ModuleAudio0();
	modules[5] = titlescreen = new ModuleTitleScreen();
	modules[6] = collision = new ModuleCollision();
	modules[7] = Level1 = new ModuleLevel1();
	modules[8] = Level2 = new ModuleLevel2();
	modules[9] = Level3 = new ModuleLevel3();
	modules[10] = player = new ModulePlayer();
	modules[11] = fade = new ModuleFadeToBlack();
	modules[12] = audio1 = new ModuleAudio1();
	modules[13] = audio2 = new ModuleAudio2();
	modules[14] = audio3 = new ModuleAudio3();

}	

Application::~Application()
{
	for(int i = NUM_MODULES - 1; i >= 0; --i)
		delete modules[i];
}

bool Application::Init()
{
	bool ret = true;
	player->Disable();
	Level1->Disable();
	Level2->Disable();
	Level3->Disable();
	audio1->Disable();
	audio2->Disable();
	audio3->Disable();

	for(int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->Init();

	for(int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->Start();

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