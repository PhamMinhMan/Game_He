#include "HitEffect.h"

List<HitEffect*>* HitEffect::hitEffects = 0;


List<HitEffect*>* HitEffect::getHitEffects()
{
	if (hitEffects == 0)
		hitEffects = new List<HitEffect*>();
	return hitEffects;
}

HitEffect::HitEffect()
{
	sprite = &SpriteManager::getInstance()->sprites[SPR_HitEffect];
	curAnimation = 0;

}


HitEffect::~HitEffect()
{
}

bool HitEffect::draw()
{
	x = xObject;
	y = yObject;
	GObject::draw();

	obj2.x = x;
	obj2.y = yObject + 3;
	obj2.draw();
	return false;
}
