#include "stdafx.h"
#include "EnemyBullet.h"


EnemyBullet::EnemyBullet()
{
}


EnemyBullet::~EnemyBullet()
{
}

void EnemyBullet::init(float x, float y)
{
	enabled = true;
	enemyBullets.push_back(this);
	imageSizeX = 20; imageSizeY = 20;
	xPos = x;
	yPos = y;
}

void EnemyBullet::move()
{
	yPos += 8;
	if (yPos > SCREEN_HEIGHT-200)
		enabled = false;
}

void EnemyBullet::update()
{
	if (enabled == false)
		destroy(this);
	move();
}

void EnemyBullet::destroy(GameObject * gameObject)
{

	//gameObject->setActive(false);
	int i = 0;
	if (dynamic_cast<EnemyBullet *>(gameObject) != nullptr)
	{
		for (auto obj : enemyBullets)
		{
			if (obj == gameObject)
			{
				enemyBullets.erase(enemyBullets.begin() + i);
				delete obj;
				obj = nullptr;
				return;
			}
			i++;
		}
	}
}
