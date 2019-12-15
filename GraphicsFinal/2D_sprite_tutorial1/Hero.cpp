#include "stdafx.h"
#include "Hero.h"
#include "Bullet.h"


Hero::Hero()
{
}


Hero::~Hero()
{
}

void Hero::fire()
{
}

void Hero::super_fire()
{
}

void Hero::move(int i)
{
	switch (i)
	{
	case MOVE_UP:
		yPos -= 6;
		break;

	case MOVE_DOWN:
		yPos += 6;
		break;


	case MOVE_LEFT:
		xPos -= 6;
		break;


	case MOVE_RIGHT:
		xPos += 6;
		break;

	}
}

void Hero::init(float x, float y)
{
	enabled = true;
	xPos = x;
	yPos = y;
}

void Hero::update()
{
	if (KEY_DOWN(VK_UP))
		move(MOVE_UP);

	if (KEY_DOWN(VK_DOWN))
		move(MOVE_DOWN);

	if (KEY_DOWN(VK_LEFT))
		move(MOVE_LEFT);

	if (KEY_DOWN(VK_RIGHT))
		move(MOVE_RIGHT);
	if (KEY_DOWN(VK_SPACE))
	{
		if (bullets.size() < 50) //10발이하일때만 생성
		{
			Bullet* bullet = new Bullet;
			bullet->init(xPos + 64, yPos);
		}
	}
}
