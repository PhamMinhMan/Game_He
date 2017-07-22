#pragma once
#include "MovableObject.h"
#include"WhipAttackable.h"
class CandleSmall :
	public WhipAttackable
{
	static CandleSmall* instance;
public:
	static CandleSmall* getInstance();
	bool update();
	bool draw();
	CandleSmall();
	~CandleSmall();
};

