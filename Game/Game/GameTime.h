#pragma once
#include<Windows.h>
class GameTime
{
protected:
	bool onTime;

public:
	static GameTime* instance;
	static GameTime* getInstance();
	DWORD startTime;
	DWORD deltaTime;
	//DWORD deltaTime;

	bool OnTime();

	GameTime(void);
	~GameTime(void);
	GameTime(DWORD deltaTime);
	void init(DWORD deltaTime);
	virtual bool atTime();
	void update();
	void start();
};

