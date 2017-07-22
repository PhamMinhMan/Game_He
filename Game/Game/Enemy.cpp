#include "Enemy.h"
#include "HitEffect.h"
#include"Simon.h"

//bool Enemy::update()
//{
//	return false;
//}
//
//bool Enemy::draw()
//{
//	return false;
//}

void Enemy::onInterserct(GObject * other)
{
	WhipAttackable::onInterserct(other);
	if (other==SIMON)
	{
		if (!SIMON->delayFlicker.OnTime())
		{
			//bi thuong
			SIMON->setHealth(SIMON->healthCount - 1);
			if(!SIMON->onStair)
				SIMON->setAction(AS_LUI);
			SIMON->vy = 0.05;
			if (SIMON->xCenter() < xCenter())
				SIMON->direction = Right;
			else
				SIMON->direction = Left;
			SIMON->vx = -SIMON->direction* 0.1;
			SIMON->delayFlicker.start();
		}
	}
}

Enemy::Enemy()
{
	objectFilter = CF_Enemy;
}


Enemy::~Enemy()
{
}
