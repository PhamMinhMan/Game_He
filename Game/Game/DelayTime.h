#pragma once
#include "GameTime.h"
class DelayTime :
	public GameTime
{
public:
	bool atTime();
	void stop();
	DelayTime();
	~DelayTime();
};

