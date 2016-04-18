#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 15


class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModulePlayer;
class ModuleAudio0;
class ModuleFadeToBlack;
class ModuleLevel1;
class ModuleLevel2;
class ModuleTitleScreen;
class Module;
class ModuleLevel3;
class ModuleAudio1;
class ModuleAudio2;
class ModuleAudio3;
class ModuleCollision;


class Application
{
public:

	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleRender* render;
	ModuleInput* input;
	ModuleTextures* textures;
	ModuleTitleScreen* titlescreen;
	ModuleLevel1* Level1;
	ModuleLevel2* Level2;
	ModuleLevel3* Level3;
	ModulePlayer* player;
	ModuleCollision* collision;
	ModuleAudio0* audio0;
	ModuleAudio1* audio1;
	ModuleAudio2* audio2;
	ModuleAudio3* audio3;
	ModuleFadeToBlack* fade;


public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__