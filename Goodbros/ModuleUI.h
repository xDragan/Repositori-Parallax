#ifndef __MODULEUSERI_H__
#define __MODULEUSERI_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

#define ENEMY_GAUGE 20

struct Text;

class ModuleUI : public Module
{
public:

	ModuleUI();
	~ModuleUI();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* UserInterface = nullptr;
	Animation insert_coins;
	Animation life_ball;
	Animation oneup;
	Animation dynamite_image;
	Animation foe;
	Animation foe_bar;
	Animation foe_bar_white;
	Animation Credit;
	Animation characterone;
	Animation top;
	Animation Continue;
	Uint32 hitpoints;
	Uint32 credit;
	Uint32 score;
	Uint32 dynamite = 10;
	Uint32 killcount;
	Uint32 topscori;
	Uint32 continue_counter;
	Text* credit_text;
	Text* credit_counter;
	Text* score_counter;
	Text* dynamite_counter;
	Text* topscore;
	Text* Continuee;
	uint timecont = 0;
	uint time = 0;
	bool done = false;
};


#endif //__MODULEUSERI_H__