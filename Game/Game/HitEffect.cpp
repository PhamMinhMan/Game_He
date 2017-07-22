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
	delayAppear.init(500);
	allowDelete = false;
	width = 8;

}


HitEffect::~HitEffect()
{
}

bool HitEffect::draw()
{
	int frameWidth = sprite->animations[curAnimation].rects[curFrame].right - sprite->animations[curAnimation].rects[curFrame].left;
	x = xObject - (frameWidth - width) / 2;
	y = yObject;
	GObject::draw();

	obj2.x = xObject+3;
	obj2.y = yObject + 1;
	obj2.draw();
	
	return false;
}

bool HitEffect::update()
{
	if (!delayAppear.OnTime())
	{
		allowDelete = true;
	}
	return GObject::update();
}
