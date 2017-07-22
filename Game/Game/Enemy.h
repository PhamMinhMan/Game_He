#pragma once
#include "MovableObject.h"
#include"WhipAttackable.h"
class Enemy :
	public MovableObject,public WhipAttackable
{
public:
	/*bool update();
	bool draw();*/
	virtual void onInterserct(GObject* other);
	Enemy();
	~Enemy();
};
