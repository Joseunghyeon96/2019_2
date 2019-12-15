#include "stdafx.h"
#include "Hero.h"
#include "Enemy.h"
#include "Bullet.h"


Hero::Hero()
{
}


Hero::~Hero()
{
}

void Hero::fire()
{
	if (bullets.size() < 50) //50�������϶��� ����
	{
		if (power == 1) {
			Bullet* bullet = new Bullet;
			bullet->init(xPos + imageSizeX / 2-8, yPos, power);
		}
		else if (power == 2) {
			Bullet* bullet = new Bullet;
			bullet->init(xPos + imageSizeX / 2 - 16, yPos, power);
		}
		else if (power == 3) {
			Bullet* bullet = new Bullet;
			bullet->init(xPos , yPos-32, power);
		}
		shotDelayStart = GetTickCount();
		power = (power % 3) + 1;
	}
}

void Hero::super_fire()
{
}

void Hero::move(int i)
{
	switch (i)
	{
	case MOVE_UP:
		if(yPos>0)
		yPos -= 6;
		break;

	case MOVE_DOWN:
		if(yPos<SCREEN_HEIGHT-128)
		yPos += 6;
		break;


	case MOVE_LEFT:
		if(xPos>0)
		xPos -= 6;
		break;


	case MOVE_RIGHT:
		if(xPos<896)
		xPos += 6;
		break;

	}
}

void Hero::init(float x, float y)
{
	enabled = true;
	power = 1;
	xPos = x;
	yPos = y;
	imageSizeX = 64; imageSizeY = 64;
	life = 3;
	shotDelayEnd = GetTickCount();
	shotDelayStart=GetTickCount();
}

bool Hero::collisionCheck()
{
	for (auto enemy : enemies) //������� �浹üũ
	{
		if (onCollision(enemy) == true) {
			destroy(enemy); // �浹�� �� ������
			return true;
		}
	}

	return false;
}



void Hero::update()
{
	shotDelayEnd = GetTickCount();

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
		if(shotDelayEnd-shotDelayStart>200)
		fire();
	}
	if (collisionCheck()) //�浹�� ������ ������1����
	{
		if(life>1)
		life--;
	}
}
