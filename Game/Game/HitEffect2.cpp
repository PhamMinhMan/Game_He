#include "HitEffect2.h"



HitEffect2::HitEffect2()
{
	sprite = &SpriteManager::getInstance()->sprites[SPR_HitEffect];
	curAnimation = 1;
}


HitEffect2::~HitEffect2()
{
}

