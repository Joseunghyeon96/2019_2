#include "stdafx.h"
#include "Hero.h"
#include "Enemy.h"
#include "EnemyBullet.h"
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
		score++;
	}
}

void Hero::super_fire()
{
}

void Hero::move(int i)
{
	if (autoMove)
	{
			yPos -= 10;
		if (yPos < 900)
			autoMove = false;
		return;
	}
	switch (i)
	{
	case MOVE_UP:
		if(yPos>0)
		yPos -= speed;
		break;

	case MOVE_DOWN:
		if(yPos<SCREEN_HEIGHT-250)
		yPos += speed;
		break;


	case MOVE_LEFT:
		if(xPos>0)
		xPos -= speed;
		break;


	case MOVE_RIGHT:
		if(xPos<SCREEN_WIDTH-32)
		xPos += speed;
		break;

	}
}

void Hero::init(float x, float y)
{
	enabled = true;
	autoMove = true;
	moveCheck = false;
	cheat = false;
	power = 1;
	xPos = x;
	speed = 2;
	yPos = 1200;
	imageSizeX = 24; imageSizeY = 24;
	life = 3;
	canPowerUp = true;
	shotDelayEnd = GetTickCount();
	shotDelayStart=GetTickCount();
}
void Hero::collisionCheck()
{
	if (autoMove)return;
	if (cheat) return;

	for (auto enemy : enemies) //������� �浹üũ
	{
		if (onCollision(enemy) == true) {
			destroy(enemy); // �浹�� �� ������
			power = 1;
			yPos = 2100;
			autoMove = true;
			life--;
			break;
		}
	}


	for (auto enemyBullet : enemyBullets) //����� �Ѿ� �� �浹üũ
	{
		if (onCollision(enemyBullet) == true) {
			enemyBullet->setActive(false); // �浹�� �� �Ѿ� ������
			power = 1;
			life--;
			yPos = 2100;
			autoMove = true;
			break;
		}
	}
}



void Hero::update()
{
	if (enabled == false)
	{
		if (KEY_DOWN(0x52))
		{
			enabled = true;
			power = 1;
			life = 3;
			score = 0;
			shotDelayEnd = GetTickCount();
			shotDelayStart = GetTickCount();
			canPowerUp = true;
		}
		return;
	}
	shotDelayEnd = GetTickCount();

	if (autoMove)
		move(0);

	if (KEY_DOWN(VK_UP)) {
		move(MOVE_UP);
	}

	if (KEY_DOWN(VK_DOWN))
		move(MOVE_DOWN);

	if (KEY_DOWN(VK_LEFT))
		move(MOVE_LEFT);

	if (KEY_DOWN(VK_RIGHT))
		move(MOVE_RIGHT);

	cheating();

	if (moveCheck == true) return;

	if (KEY_DOWN(VK_SPACE))
	{
		if(shotDelayEnd-shotDelayStart>200)
		fire();
	}
	powerUp();
	collisionCheck();
	if (life < 1)
		enabled = false;
}

void Hero::powerUp()
{
	if (score < 20) return;
	static DWORD temp;

	if (score % 500 < 20)
	{
		if (power < 3) {
			if (canPowerUp) {
				canPowerUp = false;
				temp = GetTickCount();
				power++;
			}
		}
	}
	else if(GetTickCount() - temp > 1499)
	{
		canPowerUp = true;
	}
}

void Hero::cheating()
{
	if (KEY_DOWN(VK_F1))
		cheat = true;
	else if (KEY_DOWN(VK_F2))
		cheat = false;
}
