#include "Simon.h"
#include "Config.h"
#include"GameStatus.h"

Simon * Simon::instance = 0;
Simon * Simon::getInstance()
{
	if (instance == 0)
		instance = new Simon();
	return instance;
}

bool Simon::update()
{
	if (onStair)
	{
		setHeight(30);
		updateStair();
		return true;
	}

	if (!delayFlicker.OnTime())
	{
		allowRender = true;
	}
	else
	{
		if(curAnimation!=AS_LUI)
			allowRender = timeFlicker.atTime();
	}


	updateAnimation();
	if (onAttack)
	{
		if (!onGround)//nhay danh
			updateVerlocity();
		return true;
	}

	if (onGround)
	{
		if (KEYBOARD->keyLeft)
			direction = Left;

		if (KEYBOARD->keyRight)
			direction = Right;

		if (KEYBOARD->keyDown)
		{
			vx = 0;
			setAction(AS_NGOI);
			setHeight(23);
		}
		else 
		{
			setHeight(30);
			if (KEYBOARD->keyGo)
			{
				vx = direction*0.1;
				setAction(AS_DI);
			}
			else
			{
				if(curAnimation != AS_LUI)
					vx = 0;
				setAction(AS_DUNG);
			}
		}

	}
	else
	{
		if(!onAttack && curAnimation != AS_LUI)
			setAction(AS_NHAY);
	}

	if (KEYBOARD->keyAttackPress)
	{
		if(onGround)
			vx = 0;
		onAttack = true;
		setAction(AS_DANH);
	}

	updateVerlocity();

	onGround = false;


	//if (KEYBOARD->keyAttackPress && !onAttack)
	//{
	//	vx = 0;
	//	onAttack = true;
	//	setAction(AS_DUNG_DANH);
	//}

	////if (!onAttack)
	////{
	////	if (KEYBOARD->keyLeft && onGround)
	////	{
	////		vx = -0.1;
	////		setAction( AS_DI);
	////		direction = Left;
	////	}
	////	else
	////		if (KEYBOARD->keyRight && onGround)
	////		{
	////			setAction(AS_DI);
	////			direction = Right;
	////			vx = 0.1;
	////		}
	////		else
	////		{
	////			if(onGround)
	////				vx = 0;
	////			setAction(AS_DUNG);
	////			curFrame = 0;
	////		}

	////	//if (KEYBOARD->keyJump)
	////	//{
	////	//	vy = 0.05;
	////	//	curAnimation = AS_NHAY;
	////	//	curFrame = 0;
	////	//}
	////	//else
	////	//{
	////		//vy = 0;
	////		if (KEYBOARD->keyDown)
	////		{
	////			//dy = 2;
	////			curAnimation = AS_NGOI;
	////			curFrame = 0;
	////		}
	////		//else
	////		//{
	////		//	dy = 0;
	////		//}
	////	//}
	////}

	//if (!MovableObject::update())
	//	return false;

	return true;
}

bool Simon::draw()
{
	if (!allowRender)
		return false;
	if (sprite == 0)
		return false;

	int frameWidth = sprite->animations[curAnimation].rects[curFrame].right - sprite->animations[curAnimation].rects[curFrame].left;

	float xView;
	float yView;

	CAMERA->convertToRenderPos(x, y, xView, yView);
	xView = xView - (frameWidth - width) / 2;
	int truc = xView + (frameWidth) / 2;

	D3DXMATRIX mat;
	if (direction != sprite->image->defautDirection)
	{
		/*(-1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		2 * truc, 0, 0, 1)*/
		D3DXMatrixIdentity(&mat);
		mat._11 = -1;
		mat._41 = 2 * truc;
		Graphics::getInstance()->GetSprite()->SetTransform(&mat);
	}
	//add
	
	if (curAnimation == AS_LEN_DANH || curAnimation == AS_DUNG_DANH || curAnimation == AS_NHAY_DANH || curAnimation == AS_NGOI_DANH)
	{
		whip->draw();
	}

	sprite->draw(xView, yView, curAnimation, curFrame);



	if (direction != sprite->image->defautDirection)
	{
		D3DXMatrixIdentity(&mat);
		Graphics::getInstance()->GetSprite()->SetTransform(&mat);
	}
	return true;
}

void Simon::setHealth(int health)
{
	healthCount = health;
}

void Simon::setLife(int newLifeCount)
{
	lifeCount = newLifeCount;
}

void Simon::setAction(int action)
{
	if (action == curAnimation)
		return;
	if ((!onGround || vy>0)&& (action == AS_DI || action == AS_DUNG ))
		return;

	if (action == AS_DANH)
	{
		if (onStair)
			GObject::setAction(AS_LEN_DANH);
		if (onGround)
		{
			if(KEYBOARD->keyDown)
				GObject::setAction(AS_NGOI_DANH);
			else
				GObject::setAction(AS_DUNG_DANH);

		}
		else
			GObject::setAction(AS_DUNG_DANH);
		return;
	}

	GObject::setAction(action);
}



void Simon::updateStair()
{
	if (onGoing)
	{
		updateGoing();
		return;
	}
}

void Simon::updateGoing()
{

	updateAnimation();

	if ((x + dx >= xDestination && dx >= 0) ||
		(x + dx <= xDestination && dx <= 0))
	{
		x = xDestination;
		dx = 0;
	}

	if ((y + dy >= yDestination && dy >= 0) ||
		(y + dy <= yDestination && dy <= 0))
	{
		y = yDestination;
		dy = 0;
	}

	if (dx == 0 && dy == 0)
	{
		x = xDestination;
		y = yDestination;
		atDestination();
	}

}

void Simon::initGoStair(int xDestination, int yDestination, float duration, Stair * stair)
{
	if (onGoing)
		return;

	this->xDestination = xDestination;
	this->yDestination = yDestination;
	this->stair = stair;

	duration = duration*1.5;

	if (duration != 0)
	{
		dx = (xDestination - x) / duration;
		dy = (yDestination - y) / duration;
	}
	else
	{
		dx = 0;
		dy = 0;
	}

	onGoing = true;

}

void Simon::atDestination()
{
	if (!Keyboard::getInstance()->keyUp && !Keyboard::getInstance()->keyDown)
		curFrame = 0;

	onGoing = false;

	if (stair->id == ST_RightUp && bottom() <= stair->bottom())
	{
		if (curAnimation == AS_XUONG)
		{
			onStair = false;
			//dx = -8;//ap dung khi Simon di xuong qua trai
			return;
		}
		goUp(stair);
	}

	//
	if (stair->id == ST_LeftUp && bottom() == stair->bottom())
	{
		if (curAnimation == AS_XUONG)
		{
			onStair = false;
			//dx = 8;//ap dung khi Simon di xuong qua phai
			return;
		}
		goUp(stair);
	}

	if ( (stair->id == ST_LeftDownPrevent || stair->id == ST_LeftDown ) && bottom() >= stair->top() && curAnimation == AS_LEN)
	{
		onStair = false;
	//	dx = 8;
	}

	if ( (stair->id == ST_LeftDownPrevent || stair->id == ST_LeftDown ) && bottom() >= stair->top() && curAnimation != AS_LEN)
	{
		goDown(stair);

	}

	///
	if ((stair->id == ST_RightDownPrevent || stair->id == ST_RightDown) && bottom() >= stair->top() && curAnimation == AS_LEN)
	{
		onStair = false;
	//	dx = 8;
	}
	///
	if ((stair->id == ST_RightDownPrevent || stair->id == ST_RightDown) && bottom() >= stair->top() && curAnimation != AS_LEN)
	{
		goDown(stair);

	}
}

void Simon::onEndAnimation()
{
	if ( (curAnimation == AS_DUNG_DANH || curAnimation == AS_NHAY_DANH || curAnimation == AS_NGOI_DANH) && onAttack)
	{
		setAction(AS_DUNG);
		onAttack = false;

	}
}

void Simon::goUp(Stair * stair)
{
	if (onGoing)
		return;
	initGoStair(x + stairDirection* 8, y + 8, 8, stair);
	setAction(AS_LEN);
	direction = stairDirection;
}

void Simon::goDown(Stair * stair)
{
	if (onGoing)
		return;
	initGoStair(x - stairDirection* 8, y - 8, 8, stair);
	setAction(AS_XUONG);
	direction = (DIRECTION)(-stairDirection);

}


void Simon::onCollision(GObject * other, int nx, int ny)
{
	if (onStair && onGoing && dy < 0&& other->objectFilter == CF_Ground && ny == 1)
	{
		onStair = false;
		onGoing = false;
	}

	if (onStair)
		return;
	MovableObject::onCollision(other, nx, ny);

	if (other->objectFilter == CF_Ground && ny == 1)
	{
		//setHeight(30);
		onGround = true;

		

	}

	if (other->objectFilter == CF_Ground && ny == 1)
	{
		if (Keyboard::getInstance()->keyJumpPress)
		{
			setHeight(23);
			vy = 0.2;
			setAction(AS_NHAY);
			onGround = false;

		}
	}
	
	if ( (other->id == ST_LeftDownPrevent || other->id == ST_LeftDown) && ny == 1)
	{
		

		if (Keyboard::getInstance()->keyDown && !onStair)
		{
			int xDestination = other->right()  - width;
			int yDestination = other->top() + height;
			onStair = true;
			stairDirection = Right;
			initGoStair(xDestination, yDestination, xDestination - x, (Stair*)other);
		}
	}

	
	if ( (other->id == ST_RightDownPrevent || other->id == ST_RightDown) && ny == 1)
	{
		if (Keyboard::getInstance()->keyDown && !onStair)
		{
			int xDestination = other->left() ;
			int yDestination = other->top() + height;
			onStair = true;
			stairDirection = Left;
			initGoStair(xDestination, yDestination, xDestination - x, (Stair*)other);
		}
	}

	if (other->id == ST_LeftDownPrevent || other->id == ST_RightDownPrevent)
	{
		SweptAABB::getInstance()->preventMove(this, other);
		if (ny == 1)
		{
			onGround = true;
			vy = 0;
		}
	}

}

//setHealth(int newHelth)
//{ health = newHealth; }


//health -=2;

//health +=3;

Simon::Simon()
{
	sprite = &SpriteManager::getInstance()->sprites[SPR_SIMON];
	width = 16;
	height = 30;
	/*x = 42;
	y = 162;*/
	curAnimation = AS_DUNG;
	objectFilter = CF_Simon;

	stairDirection = Right;

	onStair = false;
	onGoing = false;
	whip = new Whip();
	onAttack = false;
	allowRender = true;

	timeFlicker.init(20);
	delayFlicker.init(2000);

	healthCount = GAMESTATUS->maxHealth;


}


Simon::~Simon()
{
}
