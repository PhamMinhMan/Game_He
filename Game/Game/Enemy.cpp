#include "Enemy.h"

#include"Simon.h"

#include"HitEffect.h"

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
	if (other == SIMON->whip && SIMON->onAttack && SIMON->whip->curFrame==2)
	{
		this->alive = false;
		HitEffect* hitEffect = new HitEffect();

		HitEffect::getHitEffects()->_Add(hitEffect);

		hitEffect->xObject = x;
		hitEffect->yObject = y;

	}
	if (other==SIMON)
	{
		SIMON->timeFlicker.start();
		if(!SIMON->onStair)
			SIMON->setAction(AS_LUI);
		SIMON->vy = 0.05;
		if (SIMON->xCenter() < xCenter())
			SIMON->vx = -0.1;
		else
			SIMON->vx = 0.1;

	}
}

bool Enemy::draw()
{
	return GObject::draw();
}

Enemy::Enemy()
{
	objectFilter = CF_Enemy;
}


Enemy::~Enemy()
{
}
