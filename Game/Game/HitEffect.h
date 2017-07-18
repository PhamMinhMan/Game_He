#pragma once
#include"GObject.h"
#include"List.h"
#include"HitEffect2.h"
class HitEffect : public GObject
{
public:
	HitEffect2 obj2;
	static List<HitEffect*>* hitEffects;
	static List<HitEffect*>* getHitEffects();

	int xObject, yObject;
	HitEffect();
	~HitEffect();
	bool draw();
};

