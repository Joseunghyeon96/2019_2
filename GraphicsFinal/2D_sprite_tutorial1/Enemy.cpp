#include "stdafx.h"
#include "Bullet.h"
#include "Enemy.h"
#include "EnemyBullet.h"

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
	shotDelayStart = GetTickCount();

}

void Enemy::fire()
{
	if (shotDelayEnd - shotDelayStart > 2000) // 2초마다 fire
	{
		shotDelayStart = GetTickCount();
		EnemyBullet *bullet = new EnemyBullet;
		bullet->init(xPos + 16, yPos + 32);
	}
}
void Enemy::move()
{
	if (yPos > SCREEN_HEIGHT-200)
		enabled = false;
	yPos += 2.0f;
}
void Enemy::update()
{
	shotDelayEnd = GetTickCount();
	if (enabled == false) {
		destroy(this);
		return;
	}
	move();
	fire();
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



