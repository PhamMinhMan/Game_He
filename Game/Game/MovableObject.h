#pragma once
#include "GObject.h"
class MovableObject : 
	public virtual GObject
{
public:
	virtual bool update();
	virtual bool draw();
	
	void updateVerlocity();

	MovableObject();
	~MovableObject();
};

