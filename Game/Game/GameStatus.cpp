#include "GameStatus.h"
#include"Simon.h"
#include"Config.h"


GameStatus * GameStatus::instance = 0;
GameStatus * GameStatus::getInstance()
{
	if (instance == 0)
		instance = new GameStatus();
	return instance;
}

void GameStatus::update()
{
	if (deadline.atTime())
	{
		if (curTime > 0)
		{
			curTime--;
		}
		else
		{
			//chet
		}
	}
	
}

void GameStatus::draw()
{
#pragma region Draw Table

	table.Draw(0, 0, 0);

#pragma endregion

#pragma region Draw Health

	int curSimonHealth = SIMON->healthCount;
	int curX = healthPosX;
	for (int i = 0; i < maxHealth; i++)
	{
		if (i < curSimonHealth)
		{
			healthActive.Draw(curX,healthPosY,0);
		}
		else
		{
			healthInActive.Draw(curX, healthPosY,0);
		}

		curX += (healthActive.Width + 1);
	}

	Number::getInstance()->drawScore(curTime, 0, 0, 6);

#pragma endregion

}

GameStatus::GameStatus()
{
	table.Init("Data\\score\\scoretable.png",0);
	healthActive.Init("Data\\score\\health_active.png", 0);
	healthInActive.Init("Data\\score\\health_inactive.png", 0);
	maxHealth = 16;
	healthPosX = 55;
	healthPosY = 29;
	deadline.init(1000);
	curTime = 10;
}


GameStatus::~GameStatus()
{
}
