#pragma once
#include"Sprite.h"


class SpriteManager
{
public:
	static SpriteManager* instance;
	static SpriteManager* getInstance();
	int nSprite;
	Sprite* sprites;
	SpriteManager();
	~SpriteManager();
};

