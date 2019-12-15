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
	imageSizeX = 64; imageSizeY = 64;
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
		if (bullet->getEnabled() == false) continue;
		if (onCollision(bullet) == true)
		{

			decreaseLife(bullet->getDamage());
			bullet->setActive(false);
			bullet->setExplosion(true);
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



