#include "GObject.h"

bool GObject::update()
{
	if (!alive)
		return false;
	if (sprite == 0)
		return false;
	updateAnimation();
	return true;
}

bool GObject::draw()
{
	if (!alive)
		return false;
	if (sprite == 0)
		return false;

	float xView ;
	float yView ;

	CAMERA->convertToRenderPos(x, y, xView, yView);

	int truc = xView +
		(sprite->animations[curAnimation].rects[curFrame].right - sprite->animations[curAnimation].rects[curFrame].left) / 2;
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
	sprite->draw(xView, yView, curAnimation, curFrame);

	if (direction != sprite->image->defautDirection)
	{
		D3DXMatrixIdentity(&mat);
		Graphics::getInstance()->GetSprite()->SetTransform(&mat);
	}
	return true;
}


void GObject::updateLocation()
{
	if (coVaChamCheo && !biDoiVanToc)
	{
		if (abs(dx) > abs(dy))
			dy = 0;
		else
			dx = 0;
	}
	x += dx;
	y += dy;
}

void GObject::onCollision(GObject * other, int nx, int ny)
{
	if (other->objectFilter == CF_Ground && ny!=-1)
	{
		SWEPT_AABB->preventMove(this, other);
		if (ny == 1)//fix roi nhanh xuong
		{
			vy = -0.1;
		}
	}
}

void GObject::onInterserct(GObject * other)
{
}

void GObject::updateAnimation()
{
	if (delay.atTime())
	{
		sprite->update(curAnimation, curFrame, delay);
		if (curFrame == 0)
		{
			onEndAnimation();
		}
	}
}

void GObject::setAction(int action)
{
	if (action == curAnimation)
		return;
	curAnimation = action;
	curFrame = 0;
}

void GObject::onEndAnimation()
{
}

void GObject::setHeight(int newHeight)
{
	if (height != newHeight)
	{
		y -= (height - newHeight);
		height = newHeight;
	}
}

void GObject::setOldRect()
{
	oldRect.x = x;
	oldRect.y = y;
	oldRect.width = width;
	oldRect.height = height;
}

void GObject::restore()
{
	x = oldRect.x;
	y = oldRect.y;
	alive = true;
}

GObject::GObject()
{
	curFrame = 0;
	curAnimation = 0;
	direction = Right;
	delay.deltaTime = 100;
	objectFilter = CF_Ground;
	delay.start();
	alive = true;
	pauseAnimation = false;
}


GObject::~GObject()
{
}
