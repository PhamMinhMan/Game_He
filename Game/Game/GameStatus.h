#pragma once
#include"Texture.h"
#include"Number.h"
class GameStatus
{
	Texture table;
	Texture healthActive;
	Texture healthInActive;
	GameTime deadline;
	int healthPosX; // toa do x cua vung mau muon ve
	int healthPosY; // toa do y cua vung mau muon ve
	static GameStatus* instance;
public:
	static GameStatus* getInstance();
	int maxHealth;
	int curTime;
	void update();
	void draw();
	GameStatus();
	~GameStatus();
};

