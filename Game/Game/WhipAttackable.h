#pragma once
#include "GObject.h"
class WhipAttackable :
	virtual public GObject
{
public:
	void onInterserct(GObject* other);
	WhipAttackable();
	~WhipAttackable();
};

