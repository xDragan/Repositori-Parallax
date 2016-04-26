 #include "Application.h"
#include "Enemy_CowBoy_Blue.h"
#include "ModuleCollision.h"

Enemy_CowBoy_Blue::Enemy_CowBoy_Blue(int x, int y) : Enemy(x, y)
{
	forward.PushBack({ 117, 396, 30, 55 });
	forward.PushBack({ 152, 396, 30, 55 });
	forward.PushBack({ 188, 396, 30, 55 });
	forward.PushBack({ 224, 396, 30, 55 });
	forward.PushBack({ 261, 396, 30, 55 });
	forward.PushBack({ 299, 396, 30, 55 });
	forward.speed = 0.09f;

	backward.PushBack({ 117, 459, 30, 55 });
	backward.PushBack({ 152, 459, 30, 55 });
	backward.PushBack({ 188, 459, 30, 55 });
	backward.PushBack({ 224, 459, 30, 55 });
	backward.PushBack({ 261, 459, 30, 55 });
	backward.PushBack({ 299, 459, 30, 55 });
	backward.speed = 0.09f;

	stop_shoot.PushBack({ 353, 396, 30, 55 });
	stop_shoot.PushBack({ 392, 396, 30, 55 });
	stop_shoot.PushBack({ 353, 396, 30, 55 });
	stop_shoot.speed = 0.04f;
	stop_shoot.loop = true;

	dieshot.PushBack({507,397,35,54});
	dieshot.PushBack({ 549, 397, 35, 54 });
	dieshot.PushBack({ 589, 397, 35, 54 });
	dieshot.PushBack({ 632, 397, 35, 54 });
	dieshot.speed = 0.09f;
	dieshot.loop = false;

	dieexplotion.PushBack({744,397,36,54});
	dieexplotion.PushBack({ 798, 397, 36, 54 });
	dieexplotion.PushBack({ 844, 397, 36, 54 });
	dieexplotion.PushBack({ 889, 397, 36, 54 }); 
	dieexplotion.speed = 0.3f;

	grenade.PushBack({1014,397,36,54});
	grenade.PushBack({ 1055, 397, 36, 54 });
	grenade.PushBack({ 1095, 397, 36, 54 });
	grenade.PushBack({ 1134, 397, 36, 54 });
	grenade.PushBack({ 1172, 397, 36, 54 });
	grenade.PushBack({ 1210, 397, 36, 54 });
	grenade.speed = 0.2f;

	bwtumble.PushBack({107,565,36,54});
	bwtumble.PushBack({ 149, 565, 41, 54 });
	bwtumble.PushBack({ 195, 565, 36, 54 });
	bwtumble.PushBack({ 237, 565, 36, 54 });
	bwtumble.PushBack({ 278, 565, 36, 54 });
	bwtumble.PushBack({ 319, 565, 36, 54 });
	bwtumble.speed = 0.2f;
	bwtumble.loop = true;
 
	bwtumbleshoot.PushBack({ 107, 619, 36, 54 });
	bwtumbleshoot.PushBack({ 149, 619, 41, 54 });
	bwtumbleshoot.PushBack({ 195, 565, 36, 54 });
	bwtumbleshoot.PushBack({ 237, 565, 36, 54 });
	bwtumbleshoot.PushBack({ 278, 565, 36, 54 });
	bwtumbleshoot.PushBack({ 319, 619, 36, 54 });
	bwtumbleshoot.PushBack({ 319, 673, 36, 54 });
	bwtumbleshoot.speed = 0.2f;
	bwtumbleshoot.loop = true;

	fwtumble.PushBack({ 107, 739, 36, 54 });
	fwtumble.PushBack({ 149, 739, 41, 54 });
	fwtumble.PushBack({ 195, 739, 36, 54 });
	fwtumble.PushBack({ 237, 739, 36, 54 });
	fwtumble.PushBack({ 278, 739, 36, 54 });
	fwtumble.PushBack({ 319, 739, 36, 54 });
	fwtumble.speed = 0.2f;
	fwtumble.loop = true;

	fwtumbleshoot.PushBack({ 107, 793 ,36, 54 });
	fwtumbleshoot.PushBack({ 149, 793, 41, 54 });  
	fwtumbleshoot.PushBack({ 195, 739, 36, 54 });
	fwtumbleshoot.PushBack({ 237, 739, 36, 54 });
	fwtumbleshoot.PushBack({ 278, 739, 36, 54 });
	fwtumbleshoot.PushBack({ 319, 793, 36, 54 });
	fwtumbleshoot.PushBack({ 319, 845 , 36, 54 });
	fwtumble.speed = 0.2f;
	fwtumbleshoot.loop = true;




	collider = App->collision->AddCollider({ 0, -20, 24, 45 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);


	original_pos.x = x;
	original_pos.y = y;
	path.PushBack({ -1.0f, 0 }, 150, &forward);
	path.PushBack({ 0, 0 }, 67, &stop_shoot);
	path.PushBack({ -1.0f, 0 }, 50, &bwtumbleshoot);
	path.PushBack({ 0, 0 }, 67, &stop_shoot);
	path.PushBack({ 1.0f, 0 }, 150, &backward);

	original_y2 = y;
}

void Enemy_CowBoy_Blue::Move()
{
	position = original_pos + path.GetCurrentSpeed(&animation);
	if (isdead == true && dieshot.Finished() == true){
		to_delete = true;
	}
}

void Enemy_CowBoy_Blue::OnCollision(Collider* c1, Collider* c2)
{
	path.Erase();
	path.PushBack({ 0.0f, 0.0f }, 40, &dieshot);
	path.loop = false;

	isdead = true;
}