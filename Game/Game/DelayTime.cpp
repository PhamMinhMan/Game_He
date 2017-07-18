#include "DelayTime.h"



bool DelayTime::atTime()
{
	if(!onTime)
		return false;
	return GameTime::atTime();
}

void DelayTime::stop()
{
	onTime = false;
}


DelayTime::DelayTime()
{
}


DelayTime::~DelayTime()
{
}
