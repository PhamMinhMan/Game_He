#pragma once
#include"Sprite.h"
class Number 
{
	static Number* instance;
public:

	Sprite* sprite;
	static Number* getInstance();

	void drawScore(int score, int x, int y,int maxNumCount);

	Number();
	~Number();
};

