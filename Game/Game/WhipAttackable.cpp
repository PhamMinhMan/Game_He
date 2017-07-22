#include "WhipAttackable.h"
#include"Simon.h"
#include"HitEffect.h"


void WhipAttackable::onInterserct(GObject * other)
{
	if (other == SIMON->whip && SIMON->onAttack && SIMON->whip->curFrame == 2)
	{
		this->alive = false;
		HitEffect* hitEffect = new HitEffect();

		HitEffect::getHitEffects()->_Add(hitEffect);

		hitEffect->xObject = x;
		hitEffect->yObject = y;
		hitEffect->delayAppear.start();
	}
}

WhipAttackable::WhipAttackable()
{
}


WhipAttackable::~WhipAttackable()
{
}
