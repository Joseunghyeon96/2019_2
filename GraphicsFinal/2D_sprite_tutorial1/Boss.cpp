#include "stdafx.h"
#include <time.h>
#include "Boss.h"
#include "Enemy.h"
#include "Bullet.h"

Boss::Boss()
{
}


Boss::~Boss()
{
}

void Boss::init(float x, float y)
{
	enabled = true;
	easyPattern1 = GetTickCount();
	imageSizeX = 512;
	imageSizeY = 256;
	ySpeed = 2.5f;
	xSpeed = 3.0f;
	life = 800;
	xPos = x;
	yPos = y;
}

void Boss::update()
{
	if (enabled == false) return;
	
	DWORD playTime = GetTickCount();
	move();
	hit();
	if (life < 780) {
		if ((playTime - easyPattern1) > 6000)
		{
			easyPattern1 = GetTickCount();
			spawnEnemy();
		}
	}
}

void Boss::move()
{
	if(yPos < 0)
	yPos += ySpeed;
	if (xPos < 0)
	{
		xSpeed *= -1;
	}
	else if (xPos > 512)
	{
		xSpeed *= -1;
	}
	xPos += xSpeed;
}
void Boss::spawnEnemy()
{
	srand(time(NULL));
	for (int i = 0; i < 15; i++)
	{
		Enemy* enemy = new Enemy;
		enemy->init((float)(rand() % 950), rand() % 200);
	}
}
void Boss::hit()
{
	for (auto bullet : bullets) // 모든총알과 충돌체크
	{
		if (bullet->getEnabled() == false) continue;

		if (onCollision(bullet) == true)
		{
			decreaseLife(bullet->getDamage());
			bullet->setActive(false);
			bullet->setExplosion(true);
			return;
		}
	}
	return;
}
