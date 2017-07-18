#include "MovableObject.h"


bool MovableObject::update()
{
	if(!GObject::update())
		return false;
	updateVerlocity();
	return true;
}

bool MovableObject::draw()
{
	if (!GObject::draw())
		return false;
	return true;
}

void MovableObject::updateVerlocity()
{
	dx = vx*TIME;
	vy += ay*TIME;
	dy = vy*TIME;
}

MovableObject::MovableObject()
{
	dx = 0;
	dy = 0;
	ay = GRAVITY;
}


MovableObject::~MovableObject()
{
}
