#ifndef __BAR_HOUSE__
#define __BAR_HOUSE__

#include "Enemy.h"

class Bar_House : public Enemy
{
public:
	int hp = 4;
private:
	Animation destroy;
public:
	Bar_House(int x, int y);
};

#endif // __BAR_HOUSE__