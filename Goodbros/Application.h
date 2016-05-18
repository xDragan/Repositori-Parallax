#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 18

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleParticles;
class ModuleSceneFirst;
class ModuleScenePreStage;
class ModuleSceneIntro;
class ModuleSceneWin;
class ModulePlayer;
class ModuleFadeToBlack;
class ModuleCollision;
class ModuleAim;
class ModuleAudio;
class Module;
class ModuleEnemies;
class ModuleStructures;
class ModuleUI;
class ModuleText;

class Application
{
public:
	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleRender* render;
	ModuleInput* input;
	ModuleTextures* textures;
	ModuleSceneFirst* scene_space;
	ModuleSceneIntro* scene_intro;
	ModuleScenePreStage* scene_prestage;
	ModuleSceneWin* scene_win;
	ModuleCollision* collision;
	ModulePlayer* player;
	ModuleFadeToBlack* fade;
	ModuleParticles* particles;
	ModuleAim* aim;
	ModuleAudio* audio;
	ModuleEnemies* enemies;
	ModuleStructures* structures;
	ModuleUI* UserUI;
	ModuleText* text;
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