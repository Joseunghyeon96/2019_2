#include "stdafx.h"
#include "Bullet.h"
#include "Enemy.h"

Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}


void Enemy::init(float x, float y)
{
	enabled = true;
	life = 3;
	enemies.push_back(this);
	xPos = x;
	yPos = y;

}

void Enemy::fire()
{
}
void Enemy::move()
{
	if (yPos > SCREEN_HEIGHT)
		enabled = false;
	yPos += 5;
}
void Enemy::update()
{
	if (enabled == false) {
		destroy(this);
		return;
	}
	move();

	for (auto bullet : bullets) // 모든총알과 충돌체크
	{
		if (bullet->getXPos() > xPos && bullet->getXPos() < xPos + 52 &&
			bullet->getYPos() > yPos && bullet->getYPos() < yPos + 64)
		{
			life--;
			bullet->setActive(false);
			break;
		}
	}
	if (life < 1)
		destroy(this);
}
void Enemy::dead()
{
	destroy(this);
}



