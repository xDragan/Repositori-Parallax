#ifndef __MODULEUSERIntro_H__
#define __MODULEUSERIntro_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

#define ENEMY_GAUGE 20

struct Text;

class ModuleUIntro : public Module
{
public:

	ModuleUIntro();
	~ModuleUIntro();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* UserInterface = nullptr;
	Animation insert_coins;
	Animation life_ball;
	Animation oneup;
	Animation Credit;
	Animation characterone;
	Animation InsertCoin;
	Animation top;
	Uint32 hitpoints;
	Uint32 credit;
	Uint32 score;
	Uint32 dynamite = 10;
	Uint32 killcount;
	Uint32 topscori;
	Text* credit_text;
	Text* credit_counter;
	Text* score_counter;
	Text* dynamite_counter;
	Text* topscore;

};


#endif //__MODULEUSERIntro_H__