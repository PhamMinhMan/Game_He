#pragma once
#include"GObject.h"
#include"List.h"
#include"HitEffect2.h"
#include "DelayTime.h"
class HitEffect : public GObject
{
public:
	HitEffect2 obj2;
	static List<HitEffect*>* hitEffects;
	static List<HitEffect*>* getHitEffects();
	DelayTime delayAppear;
	bool allowDelete;
	int xObject, yObject;
	HitEffect();
	~HitEffect();
	bool draw();
	bool update();
};

