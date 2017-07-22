#include "Number.h"



Number * Number::instance = 0;
Number * Number::getInstance()
{
	if (instance == 0)
		instance = new Number();
	return instance;
}

void Number::drawScore(int score, int x, int y, int maxNumCount)
{
	int nNum=1;
	int cal = 1;
	while (score/cal>=10)
	{
		nNum++;
		cal *= 10;
	}

	int* stackNum = new int[nNum];

	int stackIndex = 0;

	if (score == 0)
		stackNum[0] = 0;

	while (score>0)
	{
		stackNum[stackIndex++] = score % 10;
		score /= 10;
	}

	int curX = x;

	int nMax = (maxNumCount > nNum) ? maxNumCount : nNum;

	for (int i = maxNumCount; i > nNum; i--)// in list so 0
	{
		sprite->image->Draw( curX, y, &(sprite->animations[0].rects[0]));
		curX += sprite->animations[0].rects[0].right - sprite->animations[0].rects[0].left + 1;
	}
	for (int i = nNum-1; i >=0; i--)
	{
		if (stackNum[i] < 0)
			break;
		sprite->image->Draw(curX, y, &(sprite->animations[stackNum[i]].rects[0]));
		curX += sprite->animations[0].rects[0].right - sprite->animations[0].rects[0].left;


	}

	delete[] stackNum;

}

Number::Number()
{
	sprite = new Sprite();
	sprite->init("Data\\score\\number.png", "Data\\score\\number.ani");
}


Number::~Number()
{
}
