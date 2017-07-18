#pragma once
#include "Enemy.h"
class Zombie : public Enemy
{
public:
	bool update();
	void onCollision(GObject* other, int nx, int ny);
	Zombie();
	~Zombie();
};

