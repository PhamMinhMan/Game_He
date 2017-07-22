#include "GameTime.h"


GameTime * GameTime::instance = 0;
GameTime * GameTime::getInstance()
{
	if (instance == 0)
		instance = new GameTime();
	return instance;
}

bool GameTime::OnTime()
{
	atTime();
	return onTime;
}

GameTime::GameTime(void)
{
	onTime = false;
}

void GameTime::start()
{
	startTime = GetTickCount();
	onTime = true;
}

GameTime::GameTime(DWORD deltaTime)
{
	onTime = false;
	this->deltaTime = deltaTime;
}

void GameTime::init(DWORD deltaTime)
{
	onTime = false;
	this->deltaTime = deltaTime;
}


bool GameTime::atTime()
{
	DWORD now = GetTickCount();
	if(now - startTime >=deltaTime)
	{
		startTime = now;
		onTime = false;
		return true;
	}

	return false;
}

void GameTime::update()
{


	DWORD now = GetTickCount();
	if (now - startTime >= deltaTime)
	{
		startTime = now;
		onTime = false;
	}
}

GameTime::~GameTime(void)
{
}


