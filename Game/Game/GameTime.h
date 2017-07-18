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
	DWORD tickPerFrame;
	DWORD deltaTime;

	bool OnTime();

	GameTime(void);
	~GameTime(void);
	GameTime(DWORD tickPerFrame);
	void init(DWORD tickPerFrame);
	virtual bool atTime();
	void update();
	void start();
};

